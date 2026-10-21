# 03_button_power_save

[English](README.md) | [简体中文](README_ZH.md)

## What It Does

Use the GPIO0 BOOT button to exercise the button and power-saving example.

## Hardware Required

ESP32-Touch-LCD-3.5, a USB-C data cable, and the onboard peripherals used above.

## How to Run

Use a supported ESP-IDF terminal in this directory:

```sh
idf.py set-target esp32
idf.py build flash monitor
```

## Expected Result

Button actions are reported by the serial monitor.

## Troubleshooting

Use the board BOOT button; do not hold it while resetting unless entering download mode.

