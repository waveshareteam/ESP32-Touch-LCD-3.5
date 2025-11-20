#include "app_music_play.h"
#include "bsp_board.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_lvgl_port.h"
#include "audio_driver.h"

static char *TAG = "app_music_play";

#define MAX_MP3_FILE    10
static char SD_Name[MAX_MP3_FILE][100]; 
static uint16_t Search_mp3_file_count = 0;
static char music_buf[120] = {0};

static int32_t spectrum_i = 0;
static uint32_t music_time_count = 0;

static lv_obj_t *label_music_name;
static lv_obj_t *image_ctrl_play;
static lv_obj_t *image_ctrl_stop;
static lv_obj_t *image_ctrl_volume;
static lv_obj_t *image_ctrl_last;
static lv_obj_t *image_ctrl_next;
static lv_obj_t *image_ctrl_collect;
static lv_obj_t *slider_time;
static lv_obj_t *slider_volume;
static lv_obj_t *label_music_play_time_now;
static lv_obj_t *label_music_play_time;
static lv_timer_t  *timer_1s = NULL;

LV_IMAGE_DECLARE(music_play_bg);
LV_IMAGE_DECLARE(music_volume_32);
LV_IMAGE_DECLARE(music_last_32);
LV_IMAGE_DECLARE(music_collect_32);
LV_IMAGE_DECLARE(music_next_32);
LV_IMAGE_DECLARE(music_play_32);
LV_IMAGE_DECLARE(music_stop_32);
LV_IMAGE_DECLARE(cd_ui);

void Search_mp3_Music(void)     
{        
    Search_mp3_file_count = Folder_retrieval("/sdcard",".mp3",SD_Name,MAX_MP3_FILE);
    printf("file_count=%d\r\n",Search_mp3_file_count);
    if(Search_mp3_file_count) 
    {  
        for (int i = 0; i < Search_mp3_file_count; i++) 
        {
            ESP_LOGI("SAFASF","%s",SD_Name[i]);
        }                
        
    }                                                             
}

static const char * lvgl_music_get_title(uint32_t track_id)
{
    if(track_id >= Search_mp3_file_count) return NULL;
    return SD_Name[track_id];
}


void lv_demo_music_play(int32_t id)
{
    lv_label_set_text_fmt(label_music_name, "%s",lvgl_music_get_title(id));

    memset(music_buf,0,sizeof(music_buf));
    sprintf(music_buf,"file://sdcard/%s",lvgl_music_get_title(id));
    printf("play:%s\r\n",music_buf);
    Audio_Play_Music(music_buf);
    music_time_count = 0;
    lv_slider_set_value(slider_time, 0, LV_ANIM_ON);
    lv_label_set_text_fmt(label_music_play_time_now, "00:00");
    lv_timer_resume(timer_1s);
}

static void play_event_click_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    if(lv_obj_has_state(obj, LV_STATE_CHECKED)) 
    {
        esp_asp_state_t state = Audio_Get_Current_State();
        if(state == ESP_ASP_STATE_NONE)
        {
            lv_demo_music_play(spectrum_i);
        }
        else if(state == ESP_ASP_STATE_PAUSED)
        {
            Audio_Resume_Play();
            lv_timer_resume(timer_1s);
        }
    }
    else 
    {
        Audio_Pause_Play();
        lv_timer_pause(timer_1s);
    }
}




static void timer_cb(lv_timer_t * t)
{
    if(music_time_count<240)
    {
        music_time_count++;
        lv_slider_set_value(slider_time, music_time_count, LV_ANIM_ON);

        // 计算分钟和秒（总秒数转换为 MM:SS）
        uint8_t minutes = music_time_count / 60;  // 分钟 = 总秒数 ÷ 60
        uint8_t seconds = music_time_count % 60;  // 秒 = 总秒数 % 60

        lv_label_set_text_fmt(label_music_play_time_now, "%02d:%02d", minutes, seconds);
    }
    
}



static void volume_adjustment_event_cb(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);

    Volume_Adjustment((uint8_t)lv_slider_get_value(slider));

}

static void  volume_click_event_cb(lv_event_t * e) 
{

    lv_obj_t * obj = lv_event_get_target(e);
    if(lv_obj_has_state(obj, LV_STATE_CHECKED)) {
        lv_obj_remove_flag(slider_volume, LV_OBJ_FLAG_HIDDEN);
    }
    else {
        lv_obj_add_flag(slider_volume, LV_OBJ_FLAG_HIDDEN);
    }
}

void lv_app_music_init(void)
{



    /* 获取屏幕对象 */
    lv_obj_t *scr = lv_scr_act();
    
    /* 1. 创建背景图片对象 */
    lv_obj_t *bg_img = lv_img_create(scr);
    lv_img_set_src(bg_img, &music_play_bg); // 设置图片源
    lv_obj_align(bg_img,LV_ALIGN_CENTER,0,0);


    /* 2. 创建透明覆盖层 */
    lv_obj_t *overlay = lv_obj_create(scr);
    
    /* 设置覆盖层大小与屏幕一致 */
    lv_obj_set_size(overlay, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_pos(overlay, 0, 0); // 与背景图片位置相同
    
    /* 设置覆盖层背景颜色和透明度 */
    lv_obj_set_style_bg_color(overlay, lv_color_hex(0xfffff0), 0); 
    lv_obj_set_style_bg_opa(overlay, LV_OPA_50, 0); // 30% 不透明度 (70% 透明)
    
    /* 移除覆盖层的边框和阴影 */
    lv_obj_set_style_border_width(overlay, 0, 0);
    lv_obj_set_style_shadow_width(overlay, 0, 0);
    
    /* 确保覆盖层在背景图片上方 */
    lv_obj_move_foreground(overlay);


    lv_obj_t *bg_img_cd = lv_image_create(lv_screen_active());
    lv_image_set_src(bg_img_cd, &cd_ui); 
    lv_obj_align(bg_img_cd,LV_ALIGN_CENTER,-150,-80);

    image_ctrl_play = lv_imagebutton_create(lv_screen_active());
    lv_imagebutton_set_src(image_ctrl_play, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &music_play_32, NULL);
    lv_imagebutton_set_src(image_ctrl_play, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, NULL, &music_stop_32, NULL);
    lv_obj_align(image_ctrl_play,LV_ALIGN_CENTER,0,100);
    lv_obj_add_flag(image_ctrl_play, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_add_flag(image_ctrl_play, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_grid_cell(image_ctrl_play, LV_GRID_ALIGN_CENTER, 3, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_add_event_cb(image_ctrl_play, play_event_click_cb, LV_EVENT_CLICKED, NULL);

    image_ctrl_last = lv_image_create(lv_screen_active());
    lv_image_set_src(image_ctrl_last, &music_last_32); 
    lv_obj_align(image_ctrl_last,LV_ALIGN_CENTER,-70,100);


    image_ctrl_next = lv_image_create(lv_screen_active());
    lv_image_set_src(image_ctrl_next, &music_next_32); 
    lv_obj_align(image_ctrl_next,LV_ALIGN_CENTER,70,100);
    
    image_ctrl_collect = lv_image_create(lv_screen_active());
    lv_image_set_src(image_ctrl_collect, &music_collect_32); 
    lv_obj_align(image_ctrl_collect,LV_ALIGN_CENTER,-140,100);
    
    image_ctrl_volume = lv_image_create(lv_screen_active());
    lv_image_set_src(image_ctrl_volume, &music_volume_32); 
    lv_obj_align(image_ctrl_volume,LV_ALIGN_CENTER,140,100);
    lv_obj_add_flag(image_ctrl_volume, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(image_ctrl_volume, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_add_event_cb(image_ctrl_volume, volume_click_event_cb, LV_EVENT_CLICKED, NULL);

    slider_time = lv_slider_create(lv_screen_active());
    lv_obj_center(slider_time);
    lv_slider_set_range(slider_time, 0, 240);
    lv_obj_set_style_anim_duration(slider_time, 2000, 0);
    lv_obj_set_style_bg_opa(slider_time, LV_OPA_0, LV_PART_KNOB);
    lv_obj_set_style_bg_opa(slider_time, LV_OPA_30, LV_PART_MAIN);
    lv_obj_set_style_bg_color(slider_time, lv_color_hex(0xC0C0C0), LV_PART_MAIN);
    lv_obj_set_style_bg_color(slider_time, lv_color_hex(0x8B4513), LV_PART_INDICATOR);
    lv_obj_set_style_bg_opa(slider_time, LV_OPA_60, LV_PART_INDICATOR);
    lv_obj_set_size(slider_time, 450,5);

    /*Create a label below the slider*/
    label_music_play_time_now = lv_label_create(lv_screen_active());
    lv_label_set_text_fmt(label_music_play_time_now, "00:00");
    lv_obj_align_to(label_music_play_time_now, slider_time, LV_ALIGN_OUT_BOTTOM_MID, -200, 10);

    label_music_play_time = lv_label_create(lv_screen_active());
    lv_label_set_text_fmt(label_music_play_time, "03:58");
    lv_obj_align_to(label_music_play_time, slider_time, LV_ALIGN_OUT_BOTTOM_MID, 200, 10);

    label_music_name = lv_label_create(lv_screen_active());
    lv_label_set_text_fmt(label_music_name," ");
    lv_obj_align_to(label_music_name, bg_img_cd,LV_ALIGN_OUT_RIGHT_MID, 20, -10);
    lv_obj_set_style_text_font(label_music_name, &lv_font_montserrat_36, 0);



    slider_volume = lv_slider_create(lv_screen_active());                                 
    lv_obj_add_flag(slider_volume, LV_OBJ_FLAG_CLICKABLE);    
    lv_obj_set_size(slider_volume, 25, 130);                                                          
    lv_obj_set_style_bg_opa(slider_volume, LV_OPA_TRANSP, LV_PART_KNOB);                               
    lv_obj_set_style_pad_all(slider_volume, 20, LV_PART_KNOB);                                            
    lv_obj_set_style_bg_color(slider_volume, lv_color_hex(0xADD8F6), LV_PART_INDICATOR);              
    lv_obj_set_style_outline_width(slider_volume, 0, 0);  
    lv_slider_set_range(slider_volume, 0, Volume_MAX);              
    lv_slider_set_value(slider_volume, PLAYER_VOLUME, LV_ANIM_ON);  
    lv_obj_align(slider_volume, LV_ALIGN_RIGHT_MID, -20, 0); 
    lv_obj_add_flag(slider_volume, LV_OBJ_FLAG_HIDDEN);                                     
    lv_obj_add_event_cb(slider_volume, volume_adjustment_event_cb, LV_EVENT_VALUE_CHANGED, NULL); 

    timer_1s = lv_timer_create(timer_cb, 1000, NULL);
    lv_timer_pause(timer_1s);
}