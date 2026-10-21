# 01_i2s_audio

[English](README.md) | [简体中文](README_ZH.md)

## What It Does

Play /music/1.mp3 from microSD using the ES8311 codec.

## Hardware Required

ESP32-Touch-LCD-3.5, a USB-C data cable, and the onboard peripherals used above.

## How to Run

Install the Arduino-ESP32 version listed in the repository README and copy the bundled libraries into your sketchbook `libraries` folder. Select **ESP32 Dev Module**, 16 MB Flash, QIO, PSRAM enabled, and **Custom** partition scheme; keep the supplied `partitions.csv` (12 MB application) in the sketch folder, then open the `.ino` file and upload.

## Expected Result

The speaker plays the MP3 and serial output reports decoder status.

## Troubleshooting

A FAT-formatted card and /music/1.mp3 are required.

