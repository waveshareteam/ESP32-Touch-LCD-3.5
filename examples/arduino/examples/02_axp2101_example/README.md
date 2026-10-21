# 02_axp2101_example

[English](README.md) | [简体中文](README_ZH.md)

## What It Does

Inspect AXP2101 power and battery status.

## Hardware Required

ESP32-Touch-LCD-3.5, a USB-C data cable, and the onboard peripherals used above.

## How to Run

Install the Arduino-ESP32 version listed in the repository README and copy the bundled libraries into your sketchbook `libraries` folder. Select **ESP32 Dev Module**, 16 MB Flash, QIO, PSRAM enabled, and **Custom** partition scheme; keep the supplied `partitions.csv` (12 MB application) in the sketch folder, then open the `.ino` file and upload.

## Expected Result

The serial monitor reports PMU information.

## Troubleshooting

A battery is required to observe battery-specific readings.

