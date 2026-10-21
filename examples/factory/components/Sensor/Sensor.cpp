#include "Sensor.hpp"
#include <cstdio>
#include <new>
#include "esp_timer.h"
LV_IMAGE_DECLARE(img_app_sensor);
using namespace app_ui;
namespace esp_brookesia::apps {
Sensor *Sensor::instance_;
Sensor *Sensor::requestInstance() { if(!instance_) instance_=new(std::nothrow) Sensor; return instance_; }
Sensor::Sensor():App("Sensor",&img_app_sensor,true,false,false) {}
Sensor::~Sensor() { close(); instance_=nullptr; }
bool Sensor::run() {
    root_=screen("Sensors",event,this);
    auto *rtc=box(root_,12,76,296,120);
    label(rtc,"PCF85063  /  RTC",16,12,264,&lv_font_montserrat_14,MUTED);
    clock_=label(rtc,"--:--:--",16,38,264,&lv_font_montserrat_32);
    date_=label(rtc,"--",16,86,264,&lv_font_montserrat_14,MUTED);
    status_=label(root_,"Reading RTC...",14,218,292,&lv_font_montserrat_12,MUTED);
    timer_=lv_timer_create(poll,1000,this);
    if(!timer_ || !start("sensor",4096)) { close(); return false; }
    return true;
}
void Sensor::work() {
    int64_t next_rtc=0;
    while(!stopping()) {
        auto now=esp_timer_get_time();
        if(now>=next_rtc) {
            bsp_sensor_datetime_t t={}; auto err=bsp_rtc_get_datetime(&t);
            portENTER_CRITICAL(&lock_); rtc_error_=err; if(err==ESP_OK) time_=t; portEXIT_CRITICAL(&lock_);
            next_rtc=now+1000000;
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
void Sensor::refresh() {
    bsp_sensor_datetime_t t; esp_err_t rtc;
    portENTER_CRITICAL(&lock_); t=time_; rtc=rtc_error_; portEXIT_CRITICAL(&lock_);
    char s[80];
    if(rtc==ESP_OK) {
        snprintf(s,sizeof(s),"%02u:%02u:%02u",t.hour,t.minute,t.second); text(clock_,s);
        snprintf(s,sizeof(s),"%04u-%02u-%02u",t.year,t.month,t.day); text(date_,s);
    } else { text(clock_,"--:--:--"); text(date_,"RTC unavailable"); }
    snprintf(s,sizeof(s),"RTC: %s",rtc==ESP_OK?"OK":"unavailable"); text(status_,s);
}
void Sensor::poll(lv_timer_t *t) { static_cast<Sensor *>(lv_timer_get_user_data(t))->refresh(); }
void Sensor::event(lv_event_t *e) { static_cast<Sensor *>(lv_event_get_user_data(e))->back(); }
bool Sensor::pause() { if(timer_) lv_timer_pause(timer_); stop(); return true; }
bool Sensor::resume() { if(timer_) lv_timer_resume(timer_); return start("sensor",4096); }
bool Sensor::close() { stop(); if(timer_) { lv_timer_delete(timer_); timer_=nullptr; } if(root_) lv_obj_delete(root_); root_=nullptr; return true; }
}
