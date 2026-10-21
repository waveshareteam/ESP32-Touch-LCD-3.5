# Factory application suite

[English](README.md) | [简体中文](README_ZH.md)

## What It Does

Provides a portrait 320 × 480 desktop with 11 applications: Settings, AIChats, Touch Test, Photos, Weather, Music, Sensor (RTC only), 2048, Mic Test, Button Test and Display Test.

## Hardware Required

ESP32-Touch-LCD-3.5 (16 MB Flash, 2 MB PSRAM), USB-C data cable and a FAT32-formatted microSD card for media. This model has no camera or motion sensor.

## How to Run

To restore the factory software, follow the [firmware instructions](../../firmware/README.md). To build from source, configure ESP-IDF v5.5.4 as described in [Development Environment](../../README.md#development-environment), then run `idf.py set-target esp32`, `idf.py build` and `idf.py -p PORT flash monitor` in this directory, replacing `PORT` with the device's serial port.

## Expected Result

The desktop opens with 11 applications, with Settings first and AIChats second; tap an icon to open an application. The screen lights up when the desktop is ready. Settings offers brightness, volume, Wi-Fi scanning and setup, and SD-card information; put JPEG images in `/photo` and MP3 files in `/music` at the SD-card root.

Short press PWR once to power on; press and hold PWR for 5 seconds to power off. Use short presses when checking PWR in Button Test.

For application controls and Wi-Fi setup, see the [user guide](USER_GUIDE.md).

## Troubleshooting

Weather and AIChats require Internet access; follow the on-screen instructions to activate AIChats. If a speech model is missing, flash the complete factory firmware or use a full `idf.py flash` rather than flashing only the application; see the [user guide](USER_GUIDE.md#common-questions) for other questions.

