# 04_pcf85063_example

[English](README.md) | [简体中文](README_ZH.md)

## What It Does

Set and read the PCF85063 hardware RTC.

## Hardware Required

ESP32-Touch-LCD-3.5, a USB-C data cable, and the onboard peripherals used above.

## How to Run

Use a supported ESP-IDF terminal in this directory:

```sh
idf.py set-target esp32
idf.py build flash monitor
```

## Expected Result

The serial monitor prints the running calendar.

## Troubleshooting

This example initializes a demonstration calendar; edit it before using it as a clock.

