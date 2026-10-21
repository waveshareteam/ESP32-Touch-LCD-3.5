file(GLOB_RECURSE SRC_FILES "*.c" "*.cpp")

idf_component_register(SRCS ${SRC_FILES}
                    INCLUDE_DIRS "."
                    REQUIRES "freertos" "sensorlib" "XPowersLib"
                             "esp_driver_gpio" "esp_driver_i2c" "esp_driver_i2s"
                             "esp_driver_ledc" "esp_driver_spi" "esp_driver_sdmmc"
                             "espressif__esp_codec_dev" "fatfs" "nvs_flash" "lwip"
                             "esp_wifi" "esp_lcd_st7796" "esp_lcd_touch_ft6336")
