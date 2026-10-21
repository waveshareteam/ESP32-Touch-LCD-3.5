# 02_axp2101_example

[English](README.md) | [简体中文](README_ZH.md)

## 功能

查看 AXP2101 电源与电池状态。

## 硬件需求

ESP32-Touch-LCD-3.5、USB-C 数据线，以及上述功能所用板载外设。

## 怎么运行

安装仓库首页所列 Arduino-ESP32 版本，将随附库复制到草图本的 `libraries` 目录。选择 **ESP32 Dev Module**、16 MB Flash、QIO、启用 PSRAM，以及 **16M Flash (3MB APP/9.9MB FATFS)**，打开 `.ino` 文件并上传。

## 预期现象

串口监视器输出 PMU 信息。

## 常见问题

查看电池相关读数时需要连接电池。

