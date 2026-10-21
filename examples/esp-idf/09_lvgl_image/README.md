# 09_lvgl_image

[English](README.md) | [简体中文](README_ZH.md)

## What It Does

Display the embedded image with LVGL and touch support.

## Hardware Required

ESP32-Touch-LCD-3.5, a USB-C data cable, and the onboard peripherals used above.

## How to Run

Use a supported ESP-IDF terminal in this directory:

```sh
idf.py set-target esp32
idf.py build flash monitor
```

## Expected Result

The embedded image appears on the LCD.

## Troubleshooting

Image assets are compiled into this example; no SD card is required.

