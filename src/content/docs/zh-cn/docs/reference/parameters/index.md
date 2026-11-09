---
title: 参数参考
description: 场地尺寸、比赛时间、计分乘数、机器人限制，以及入门机器人的设备名称。
---

## 场地 {#field}

| 参数 | 数值 |
|---|---|
| 地块 | 12 cm × 12 cm |
| 四分之一地块（区域 2 和 3） | 6 cm × 6 cm |
| 墙壁 | 厚 1 cm，高 6 cm |
| 笑脸受害者 | 2 cm × 2 cm |
| 认知目标 | 直径 5 cm |

## 比赛 {#game}

| 参数 | 数值 |
|---|---|
| 比赛时间 | 8 分钟仿真时间 |
| 真实时间 | 10 分钟 |
| 自动判定缺乏进展 | 在同一位置停留 20 秒后 |
| 报告墙面标识所需的停止时间 | 至少 1 秒 |
| 报告墙面标识的距离 | 半个地块（6 cm），对机器人中心和发送的位置都适用 |
| 电池 | 开始时为 100%。按车轮的速度消耗，两个车轮全速时每秒约 1.25%。 |
| 沼泽中的电池 | 消耗速度为 5 倍 |
| 更换电池 | 在接触地块上静止 5 秒 |
| 区域乘数 | 区域 1、2、3、4 分别为 1、1.25、1.5 和 2 |
| 离场奖励 | +10% |
| 地图奖励乘数 | 正确率 × 1.2 + 1 |

## 机器人 {#robot}

| 参数 | 数值 |
|---|---|
| 预算 | 3000 |
| 摄像头最多数量 | 3 |
| 距离传感器最多数量 | 8 |
| 距离传感器量程 | 0 至 0.8 m |
| GPS 精度 | 0.0025 m |
| 最大车轮速度 | 6.28 rad/s |
| 激光雷达 | 每层 512 个点，4 层，0.01 至 1 m |

`timeStep` 设置两次传感器更新之间的毫秒数。`int(robot.getBasicTimeStep())` 获取世界的基本时间步长，在 Erebus v27 的世界中为 16 ms。

## 入门机器人的设备名称 {#device-names-of-the-starter-robot}

使用[入门机器人](/docs/robot/)时，把下面这些名字传给 `robot.getDevice()`。在你自己的机器人中，名字是在 [Robot Customizer](/docs/robot/customizer/#components) 中选择的。发射器和接收器始终可用。

| 设备 | 名称 |
|---|---|
| 车轮电机 | `left wheel motor`、`right wheel motor` |
| 车轮编码器 | `left wheel sensor`、`right wheel sensor` |
| 距离传感器 | `leftDist`、`frontDist`、`rightDist` |
| 摄像头 | `camera` |
| 颜色传感器 | `color` |
| GPS | `gps` |
| 陀螺仪 | `gyro` |
| 加速度计 | `accelerometer` |
| 激光雷达 | `lidar` |
| 发射器 | `emitter` |
| 接收器 | `receiver` |
