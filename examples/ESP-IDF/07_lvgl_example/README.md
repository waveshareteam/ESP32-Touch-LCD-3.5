# 07_lvgl_example

[English](README.md) | [简体中文](README_ZH.md)

## What It Does

Display LVGL widgets with capacitive touch input.

## Hardware Required

ESP32-Touch-LCD-3.5, a USB-C data cable, and the onboard peripherals used above.

## How to Run

Use a supported ESP-IDF terminal in this directory:

```sh
idf.py set-target esp32
idf.py build flash monitor
```

## Expected Result

The screen shows the LVGL widgets demo.

## Troubleshooting

Keep the project configuration and its declared LVGL dependency together.

