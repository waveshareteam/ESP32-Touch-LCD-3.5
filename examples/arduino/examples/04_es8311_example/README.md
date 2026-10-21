# 04_es8311_example

[English](README.md) | [简体中文](README_ZH.md)

## What It Does

Exercise ES8311 I2S audio recording and playback.

## Hardware Required

ESP32-Touch-LCD-3.5, a USB-C data cable, and the onboard peripherals used above.

## How to Run

Install the Arduino-ESP32 version listed in the repository README and copy the bundled libraries into your sketchbook `libraries` folder. Select **ESP32 Dev Module**, 16 MB Flash, QIO, PSRAM enabled, and **Custom** partition scheme; keep the supplied `partitions.csv` (12 MB application) in the sketch folder, then open the `.ino` file and upload.

## Expected Result

Audio test status appears in the serial monitor and sound is heard through the speaker.

## Troubleshooting

Uses the onboard microphone and speaker.

