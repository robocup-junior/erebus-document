---
title: 消息参考
description: 与 Main Supervisor 交换的消息的参考说明。
---

消息用 `emitter` 设备发送，用 `receiver` 设备接收。示例请参阅[通信教程](/docs/programming/communication/)。

下面的格式字符串是 Python [struct](https://docs.python.org/3/library/struct.html) 模块使用的格式字符串。

## 机器人发送的消息 {#sent-by-the-robot}

| 消息 | 格式 | 长度 | 用途 |
|---|---|---|---|
| 报告墙上的标识 | `i i c`：x、z、类型 | 9 字节 | 位置以厘米为单位，类型是 `H`、`S`、`U`、`F`、`P`、`C`、`O` 之一。机器人必须已经停止至少 1 秒。 |
| 地图数据 | `2i` 后接 UTF-8 文本：行数、列数、用逗号分隔的单元格 | 其他任意长度 | 保存地图，但不进行评估 |
| `M` | `c` | 1 字节 | 评估已保存的地图。只能评估一次。 |
| `L` | `c` | 1 字节 | 请求缺乏进展 |
| `G` | `c` | 1 字节 | 请求比赛信息 |
| `E` | `c` | 1 字节 | 结束比赛。如果机器人位于起始地块上，并且已经识别出至少一个墙上的标识，就会获得离场奖励。 |

Erebus 根据长度来区分这些消息，所以报告的长度必须正好是 9 字节。

## 机器人接收的消息 {#received-by-the-robot}

| 消息 | 格式 | 长度 | 用途 |
|---|---|---|---|
| `L` | `c` | 1 字节 | 发生了缺乏进展 |
| `G` | `c f i i`：`G`、得分、剩余比赛时间、剩余真实时间 | 16 字节 | 对 `G` 的回复。时间以秒为单位。 |

注意，`G` 的数据包中包含填充字节，因为上面的 `struct` 格式会对齐浮点数：得分从第 4 字节开始，两个时间分别从第 8 和第 12 字节开始。

## 常用的 Webots 函数 {#common-webots-functions}

| 函数 | 说明 |
|---|---|
| `robot.getDevice(name)` | 按名字获取设备。在 C++ 中，请使用 `robot->getMotor(name)`、`robot->getCamera(name)` 等。 |
| `robot.step(timeStep)` | 让仿真向前推进。仿真结束时返回 -1。 |
| `robot.getTime()` | 获取仿真时间，单位为秒 |
| `device.enable(timeStep)` | 启用传感器 |
| `motor.setPosition(float("inf"))` | 让电机无限制地转动 |
| `motor.setVelocity(speed)` | 设置电机的速度，单位为弧度每秒 |
