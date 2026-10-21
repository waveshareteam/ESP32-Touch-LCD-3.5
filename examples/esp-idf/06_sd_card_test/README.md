# 06_sd_card_test

[English](README.md) | [简体中文](README_ZH.md)

## What It Does

Mount a microSD card over SPI and read/write a test file.

## Hardware Required

ESP32-Touch-LCD-3.5, a USB-C data cable, and the onboard peripherals used above.

## How to Run

Use a supported ESP-IDF terminal in this directory:

```sh
idf.py set-target esp32
idf.py build flash monitor
```

## Expected Result

The serial monitor reports card information and file contents.

## Troubleshooting

Insert a FAT-formatted card before startup; formatting on mount failure is disabled by default.

