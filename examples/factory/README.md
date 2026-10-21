# Factory application suite

[English](README.md) | [简体中文](README_ZH.md)

## What It Does

Runs the portrait 320 × 480 desktop with Settings, AIChats, Touch Test, Photos, Weather, Music, Sensor (RTC only), 2048 and Mic Test. Three launcher pages are available.

## Hardware Required

ESP32-Touch-LCD-3.5 (16 MB Flash, 2 MB PSRAM), USB-C data cable and a FAT-formatted microSD card for media. This model has no camera or motion sensor.

## How to Run

Use ESP-IDF v5.5.4 in this directory:

```sh
idf.py set-target esp32
idf.py build flash monitor
```

Flash the complete project including its speech model, or use the tested merged image in [firmware](../../firmware/). Saved Wi-Fi credentials take priority; otherwise it tries `weather-wifi` / `12345678` on 2.4 GHz. Settings provides a provisioning hotspot and QR code; its English web page is at `http://192.168.4.1`.

## Expected Result

The desktop opens with nine applications. Put JPEG images in `/photo` and MP3 files in `/music` on the SD card; open AIChats while online to activate voice chat, then say “你好小智” or tap Talk.

For application controls and Wi-Fi setup, see the [user guide](USER_GUIDE.md).

## Troubleshooting

Install the complete merged image at `0x0`, including the 512 KiB model partition; a standalone application image is insufficient for first installation. Photos are decoded when Photos opens; Music, Mic Test and AIChats share the audio device exclusively. Network time updates the desktop clock (UTC+8) while Sensor reads the hardware RTC independently. Peripheral interfaces are in [components/esp32_touch_lcd_3_5](components/esp32_touch_lcd_3_5/).

