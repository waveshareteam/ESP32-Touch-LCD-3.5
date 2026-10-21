#pragma once
#include "bsp/esp-bsp.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    esp_err_t i2c, expander, power, display, touch;
    esp_err_t button, audio, rtc, sdcard, wifi;
} bsp_init_status_t;

/* Call once from app_main before starting APPs. Required power/display errors
 * are returned; optional peripheral failures are logged and stored in status. */
esp_err_t bsp_init(void);
const bsp_init_status_t *bsp_get_init_status(void);
esp_err_t bsp_io_expander_init(void);
esp_err_t bsp_io_expander_read_input(bool *high);
esp_err_t bsp_power_init(void);

lv_display_t *bsp_display_get(void);
esp_lcd_touch_handle_t bsp_touch_get_handle(void);
esp_err_t bsp_user_button_init(void);
uint32_t bsp_user_button_get_press_count(void);

typedef enum {
    BSP_BUTTON_ID_BOOT,
    BSP_BUTTON_ID_PWR,
} bsp_button_id_t;
/* Normalized physical state: BOOT GPIO0 is active-low; PWR SYS_OUT on
 * GPIO36 is active-high. Does not change power-key shutdown timing. */
esp_err_t bsp_button_get_pressed(bsp_button_id_t button, bool *pressed);

typedef struct {
    bool connected, charging, vbus_present;
    uint16_t voltage_mv;
    int percentage;
} bsp_battery_info_t;
esp_err_t bsp_battery_get_info(bsp_battery_info_t *info);

typedef struct {
    uint16_t year;
    uint8_t month, day, hour, minute, second, weekday;
} bsp_sensor_datetime_t;
esp_err_t bsp_rtc_init(void);
esp_err_t bsp_rtc_get_datetime(bsp_sensor_datetime_t *datetime);
esp_err_t bsp_rtc_set_datetime(const bsp_sensor_datetime_t *datetime);

typedef struct {
    bool mounted;
    uint64_t capacity_bytes, total_bytes, free_bytes;
} bsp_sdcard_info_t;
esp_err_t bsp_sdcard_mount(void);
/* Active APPs acquire/release a lease so Settings cannot unmount an in-use card. */
esp_err_t bsp_sdcard_acquire(void);
void bsp_sdcard_release(void);
esp_err_t bsp_sdcard_unmount(void);
esp_err_t bsp_sdcard_get_info(bsp_sdcard_info_t *info);

/* Driver/netif initialization only. Credentials/scan/provisioning belong to APPs. */
esp_err_t bsp_wifi_init(void);
/* Start the initialized radio for scanning/provisioning. Does not connect. */
esp_err_t bsp_wifi_start(void);

#ifdef __cplusplus
}
#endif
