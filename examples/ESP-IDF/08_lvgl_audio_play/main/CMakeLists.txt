# 初始化源文件和包含目录
set(SOURCES
    "./main.c" 
    "./hardeware_driver/bsp_board.c"
    "./audio_play_driver/audio_driver.c"
    "./lvgl_app_music_play/app_music_play.c"

    "./lvgl_app_music_play/asset/music_volume_32.c"
    "./lvgl_app_music_play/asset/music_last_32.c"
    "./lvgl_app_music_play/asset/music_collect_32.c"
    "./lvgl_app_music_play/asset/music_next_32.c"
    "./lvgl_app_music_play/asset/music_play_bg.c"
    "./lvgl_app_music_play/asset/music_play_32.c"
    "./lvgl_app_music_play/asset/music_stop_32.c"
    "./lvgl_app_music_play/asset/cd_ui.c"
)

set(INCLUDE_DIRS 
    "."
    "./hardeware_driver"
    "./audio_play_driver"
    "./lvgl_app_music_play"
    "./lvgl_app_music_play/asset"
)


# 注册组件
idf_component_register(
    SRCS ${SOURCES}
    INCLUDE_DIRS ${INCLUDE_DIRS}
    REQUIRES esp_timer
    REQUIRES fatfs
    REQUIRES spi_flash
    REQUIRES esp_driver_i2s
    REQUIRES esp_driver_i2c
    REQUIRES espressif__esp_codec_dev
    REQUIRES espressif__gmf_core
    REQUIRES espressif__gmf_audio
    REQUIRES espressif__gmf_io
)