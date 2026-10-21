# 02_axp2101_example

[English](README.md) | [简体中文](README_ZH.md)

## What It Does

Read AXP2101 power status and handle its interrupt events.

## Hardware Required

ESP32-Touch-LCD-3.5, a USB-C data cable, and the onboard peripherals used above.

## How to Run

Use a supported ESP-IDF terminal in this directory:

```sh
idf.py set-target esp32
idf.py build flash monitor
```

## Expected Result

Power and battery information appears in the serial monitor.

## Troubleshooting

The configured PMU outputs must match the board supply rails.

