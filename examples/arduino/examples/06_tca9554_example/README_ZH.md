# 06_tca9554_example

[English](README.md) | [简体中文](README_ZH.md)

## 功能

测试 TCA9554 I/O 扩展器输出。

## 硬件需求

ESP32-Touch-LCD-3.5、USB-C 数据线，以及上述功能所用板载外设。

## 怎么运行

安装仓库首页所列 Arduino-ESP32 版本，将随附库复制到草图本的 `libraries` 目录。选择 **ESP32 Dev Module**、16 MB Flash、QIO、启用 PSRAM，分区方案选 **Custom**；保留草图目录内随附的 `partitions.csv`（12 MB 应用分区），打开 `.ino` 文件并上传。

## 预期现象

串口输出引脚操作信息。

## 常见问题

扩展器同时用于板载复位及功放控制。

