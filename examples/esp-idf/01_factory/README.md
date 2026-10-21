# 01_factory

[English](README.md) | [简体中文](README_ZH.md)

## What It Does

Legacy factory demo: touch drawing, settings, RTC and media.

## Hardware Required

ESP32-Touch-LCD-3.5, a USB-C data cable, and the onboard peripherals used above.

## How to Run

Use a supported ESP-IDF terminal in this directory:

```sh
idf.py set-target esp32
idf.py build flash monitor
```

## Expected Result

Press BOOT to leave the initial touch test and open the application menu.

## Troubleshooting

The legacy Wi-Fi configuration is in main/main.cpp; it is independent of the new factory project.

