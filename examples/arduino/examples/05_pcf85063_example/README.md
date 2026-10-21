# 05_pcf85063_example

[English](README.md) | [简体中文](README_ZH.md)

## What It Does

Set and read the PCF85063 calendar and demonstrate Unix-time conversion.

## Hardware Required

ESP32-Touch-LCD-3.5, a USB-C data cable, and the onboard peripherals used above.

## How to Run

Install the Arduino-ESP32 version listed in the repository README and copy the bundled libraries into your sketchbook `libraries` folder. Select **ESP32 Dev Module**, 16 MB Flash, QIO, PSRAM enabled, and **16M Flash (3MB APP/9.9MB FATFS)**, then open the `.ino` file and upload.

## Expected Result

The serial monitor prints RTC and converted time.

## Troubleshooting

The sketch sets an initial demonstration date on startup.

