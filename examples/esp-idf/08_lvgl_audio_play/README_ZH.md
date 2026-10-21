# 08_lvgl_audio_play

[English](README.md) | [简体中文](README_ZH.md)

## 功能

通过 LVGL 音乐界面操作 ES8311，播放 microSD 音频。

## 硬件需求

ESP32-Touch-LCD-3.5、USB-C 数据线，以及上述功能所用板载外设。

## 怎么运行

在本目录打开受支持的 ESP-IDF 终端：

```sh
idf.py set-target esp32
idf.py build flash monitor
```

## 预期现象

屏幕显示播放控件，扬声器播放所选文件。

## 常见问题

请插入存有支持音频文件的 FAT 格式 microSD 卡。[data/music](data/music/) 提供一首示例音频。

