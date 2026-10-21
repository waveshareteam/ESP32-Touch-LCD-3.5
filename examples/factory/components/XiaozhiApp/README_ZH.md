# AIChats 组件

[English](README.md) | [简体中文](README_ZH.md)

## 功能

将小智激活、唤醒词、语音对话接入 Brookesia 应用生命周期。[出厂工程](../../README.md)将本组件安装为 AIChats。

## 硬件需求

使用本板 ES8311 与单麦克风，没有硬件回声参考通道。本产品不包含摄像头驱动、拍照工具或预览界面。

## 怎么运行

完整编译、烧录出厂工程，包含语音模型分区。在 Settings 配置网络，打开 AIChats 完成激活，说“你好小智”或点击 Talk 开始对话，点击 Stop 取消。

## 预期现象

识别文本和回复通过字幕、音频输出，界面显示表情。

## 常见问题

音频缓冲使用 PSRAM，MCP 工作任务栈保留在内部 RAM，以支持可能关闭外部存储缓存的 NVS 操作。经典 ESP32 使用其 SDK 支持的 SR 类型 AFE，激活走普通验证码流程，不使用该芯片没有的硬件 HMAC。上游 OGG 适配代码的来源及 MIT 许可证保留在 [third_party/xiaozhi_esp32](third_party/xiaozhi_esp32/)。
