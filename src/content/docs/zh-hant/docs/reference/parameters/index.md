---
title: 參數參考
description: 場地尺寸、比賽時間、計分倍數、機器人限制，以及入門機器人的裝置名稱。
---

## 場地 {#field}

| 參數 | 數值 |
|---|---|
| 地塊 | 12 cm × 12 cm |
| 四分之一地塊（區域 2 和 3） | 6 cm × 6 cm |
| 牆壁 | 厚 1 cm，高 6 cm |
| 字母受害者 | 2 cm × 2 cm |
| 認知目標 | 直徑 5 cm |

## 比賽 {#game}

| 參數 | 數值 |
|---|---|
| 比賽時間 | 8 分鐘模擬時間 |
| 實際時間 | 10 分鐘 |
| 自動缺乏進展 | 停在固定位置 20 秒後 |
| 回報牆上的標記所需的停止時間 | 至少 1 秒 |
| 沼澤中的時間倍數 | 第一次進入為 x5，每次重新進入同一個沼澤 +1，最高 x10 |
| 區域倍數 | 區域 1、2、3、4 分別為 1、1.25、1.5 和 2 |
| 出口加成 | +10% |
| 地圖加成倍數 | 正確率 × 1.2 + 1 |

## 機器人 {#robot}

| 參數 | 數值 |
|---|---|
| 預算 | 3000 |
| 攝影機數量上限 | 3 |
| 距離感測器數量上限 | 8 |
| 距離感測器範圍 | 0 到 0.8 m |
| GPS 精確度 | 0.0025 m |
| 輪子最大速度 | 6.28 rad/s |
| 光達 | 每層 512 個點，4 層，0.01 到 1 m |

`timeStep` 設定感測器每次更新之間的毫秒數。`int(robot.getBasicTimeStep())` 會取得世界的基本時間步長，在 Erebus v26.1 的世界中是 16 ms。

## 入門機器人的裝置名稱 {#device-names-of-the-starter-robot}

使用[入門機器人](/docs/robot/)時，這些就是要傳給 `robot.getDevice()` 的名稱。在你自己的機器人中，名稱是在 [Robot Customizer](/docs/robot/customizer/#components) 中選擇的。發射器和接收器一定可以使用。

| 裝置 | 名稱 |
|---|---|
| 輪子馬達 | `left wheel motor`、`right wheel motor` |
| 輪子編碼器 | `left wheel sensor`、`right wheel sensor` |
| 距離感測器 | `leftDist`、`frontDist`、`rightDist` |
| 攝影機 | `camera` |
| 顏色感測器 | `color` |
| GPS | `gps` |
| 陀螺儀 | `gyro` |
| 加速度計 | `accelerometer` |
| 光達 | `lidar` |
| 發射器 | `emitter` |
| 接收器 | `receiver` |
