# 08_lvgl_audio_play

[English](README.md) | [简体中文](README_ZH.md)

## What It Does

Play microSD audio through ES8311 using the LVGL music interface.

## Hardware Required

ESP32-Touch-LCD-3.5, a USB-C data cable, and the onboard peripherals used above.

## How to Run

Use a supported ESP-IDF terminal in this directory:

```sh
idf.py set-target esp32
idf.py build flash monitor
```

## Expected Result

The display shows playback controls and the speaker plays the selected file.

## Troubleshooting

Insert a FAT-formatted microSD card containing supported audio files. A sample track is provided in [data/music](data/music/).

