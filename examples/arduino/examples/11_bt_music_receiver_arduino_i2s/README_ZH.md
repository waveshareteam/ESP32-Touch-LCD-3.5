# 11_bt_music_receiver_arduino_i2s

[English](README.md) | [简体中文](README_ZH.md)

## 功能

接收经典蓝牙 A2DP 音频并显示曲目信息。

## 硬件需求

ESP32-Touch-LCD-3.5、USB-C 数据线，以及上述功能所用板载外设。

## 怎么运行

安装仓库首页所列 Arduino-ESP32 版本，将随附库复制到草图本的 `libraries` 目录。选择 **ESP32 Dev Module**、16 MB Flash、QIO、启用 PSRAM，分区方案选 **Custom**；保留草图目录内随附的 `partitions.csv`（12 MB 应用分区），打开 `.ino` 文件并上传。

## 预期现象

手机配对 ESP32-Touch-LCD-3.5 后，通过扬声器播放音乐。

## 常见问题

此示例用于经典 ESP32；草图会等待蓝牙连接。

