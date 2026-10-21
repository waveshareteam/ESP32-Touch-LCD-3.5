# 01_i2s_audio

[English](README.md) | [简体中文](README_ZH.md)

## 功能

使用 ES8311 播放 microSD 中的 /music/1.mp3。

## 硬件需求

ESP32-Touch-LCD-3.5、USB-C 数据线，以及上述功能所用板载外设。

## 怎么运行

安装仓库首页所列 Arduino-ESP32 版本，将随附库复制到草图本的 `libraries` 目录。选择 **ESP32 Dev Module**、16 MB Flash、QIO、启用 PSRAM，以及 **16M Flash (3MB APP/9.9MB FATFS)**，打开 `.ino` 文件并上传。

## 预期现象

扬声器播放 MP3，串口输出解码状态。

## 常见问题

需要 FAT 格式卡及 /music/1.mp3 文件。

