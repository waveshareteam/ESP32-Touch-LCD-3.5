# 11_bt_music_receiver_arduino_i2s

[English](README.md) | [简体中文](README_ZH.md)

## What It Does

Receive Bluetooth Classic A2DP audio and show track metadata.

## Hardware Required

ESP32-Touch-LCD-3.5, a USB-C data cable, and the onboard peripherals used above.

## How to Run

Install the Arduino-ESP32 version listed in the repository README and copy the bundled libraries into your sketchbook `libraries` folder. Select **ESP32 Dev Module**, 16 MB Flash, QIO, PSRAM enabled, and **Custom** partition scheme; keep the supplied `partitions.csv` (12 MB application) in the sketch folder, then open the `.ino` file and upload.

## Expected Result

Pair a phone with ESP32-Touch-LCD-3.5 to play sound through the speaker.

## Troubleshooting

This is a classic ESP32 example; the sketch waits for a Bluetooth connection.

