# 出厂 APP 工程

[English](README.md) | [简体中文](README_ZH.md)

## 功能

运行 320 × 480 竖屏桌面，包含 Settings、AIChats、Touch Test、Photos、Weather、Music、Sensor（仅 RTC）、2048 和 Mic Test，共预留三页桌面。

## 硬件需求

ESP32-Touch-LCD-3.5（16 MB Flash、2 MB PSRAM）、USB-C 数据线；媒体功能需要 FAT 格式 microSD 卡。本型号没有摄像头及陀螺仪。

## 怎么运行

在本目录使用 ESP-IDF v5.5.4：

```sh
idf.py set-target esp32
idf.py build flash monitor
```

烧录完整工程及语音模型，或使用 [firmware](../../firmware/README_ZH.md) 中实测合并固件。优先使用已保存的 Wi-Fi，否则连接 2.4 GHz 的 `weather-wifi`，密码 `12345678`；Settings 提供热点和二维码配网，英文网页地址为 `http://192.168.4.1`。

## 预期现象

桌面显示九个应用。SD 卡的 `/photo` 放 JPEG，`/music` 放 MP3；联网后打开 AIChats 完成激活，再说“你好小智”或点击 Talk 开始对话。

## 常见问题

首次安装需在 `0x0` 烧录完整合并镜像，其中包含 512 KiB 语音模型分区，仅烧录 APP 不足以启用语音。相册在打开时才解析图片；Music、Mic Test 和 AIChats 独占共享音频设备。联网同步桌面时间（UTC+8），Sensor 独立读取硬件 RTC。外设接口位于 [components/esp32_touch_lcd_3_5](components/esp32_touch_lcd_3_5/)。

