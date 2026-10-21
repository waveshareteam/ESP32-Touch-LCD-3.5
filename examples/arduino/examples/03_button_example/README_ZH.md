# 03_button_example

[English](README.md) | [简体中文](README_ZH.md)

## 功能

输出 BOOT 与 PWR 按键的单击、双击和长按事件。

## 硬件需求

ESP32-Touch-LCD-3.5、USB-C 数据线，以及上述功能所用板载外设。

## 怎么运行

安装仓库首页所列 Arduino-ESP32 版本，将随附库复制到草图本的 `libraries` 目录。选择 **ESP32 Dev Module**、16 MB Flash、QIO、启用 PSRAM，分区方案选 **Custom**；保留草图目录内随附的 `partitions.csv`（12 MB 应用分区），打开 `.ino` 文件并上传。

## 预期现象

115200 波特率串口输出按键事件。

## 常见问题

持续按住 PWR 达到硬件关机时长会关闭电源。

