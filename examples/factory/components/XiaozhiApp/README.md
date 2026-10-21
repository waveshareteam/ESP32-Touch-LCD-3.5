# AIChats component

[English](README.md) | [简体中文](README_ZH.md)

## What It Does

Integrates Xiaozhi activation, wake-word detection and speech conversation with the Brookesia application lifecycle. The [factory project](../../README.md) installs this component as AIChats.

## Hardware Required

Uses the ESP32 board's ES8311 codec and one microphone, without a hardware echo-reference channel. No camera driver, photo tool or preview is included.

## How to Run

Build and flash the complete factory project, including the speech-model partition. Connect Wi-Fi in Settings, open AIChats, complete activation and say “你好小智” or tap Talk; tap Stop to cancel.

## Expected Result

Recognition and replies appear as subtitles and audio with the animated face.

## Troubleshooting

Audio buffers use PSRAM, while the MCP worker stack stays in internal RAM because NVS access can disable the external-memory cache. The ESP32 uses the speech-recognition AFE supported by its SDK and ordinary code-based activation (it has no hardware HMAC peripheral). Upstream OGG adaptation attribution and its MIT license are retained in [third_party/xiaozhi_esp32](third_party/xiaozhi_esp32/).
