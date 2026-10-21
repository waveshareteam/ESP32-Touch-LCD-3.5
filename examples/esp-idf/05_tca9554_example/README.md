# 05_tca9554_example

[English](README.md) | [简体中文](README_ZH.md)

## What It Does

Exercise the TCA9554 I/O-expander driver through Unity tests.

## Hardware Required

ESP32-Touch-LCD-3.5, a USB-C data cable, and the onboard peripherals used above.

## How to Run

Use a supported ESP-IDF terminal in this directory:

```sh
idf.py set-target esp32
idf.py build flash monitor
```

## Expected Result

Select a test in the serial menu to view the test result.

## Troubleshooting

The expander also controls onboard reset and amplifier signals.

