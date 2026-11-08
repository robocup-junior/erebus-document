---
title: 訊息參考
description: 與 Main Supervisor 交換的訊息參考。
---

訊息是用 `emitter` 裝置傳送，並用 `receiver` 裝置接收。範例請參閱[通訊教學](/docs/programming/communication/)。

以下的格式字串是 Python [struct](https://docs.python.org/3/library/struct.html) 模組所使用的格式。

## 機器人傳送的訊息 {#sent-by-the-robot}

| 訊息 | 格式 | 長度 | 用途 |
|---|---|---|---|
| 回報牆上的標記 | `i i c`：x、z、類型 | 9 位元組 | 位置以公分為單位，類型是 `H`、`S`、`U`、`F`、`P`、`C`、`O` 其中之一。機器人必須已停止至少 1 秒。 |
| 地圖資料 | `2i` 後面接著 UTF-8 文字：列數、行數、以逗號分隔的格子 | 其他任何長度 | 儲存地圖，但不進行評估 |
| `M` | `c` | 1 位元組 | 評估已儲存的地圖。只能執行一次。 |
| `L` | `c` | 1 位元組 | 宣告缺乏進展 |
| `G` | `c` | 1 位元組 | 要求取得比賽資訊 |
| `E` | `c` | 1 位元組 | 結束比賽。如果機器人在起始地塊上，且已辨識出至少一個牆上的標記，就會獲得出口加成。 |

Erebus 是依長度來區分這些訊息，所以回報訊息必須剛好是 9 位元組。

## 機器人接收的訊息 {#received-by-the-robot}

| 訊息 | 格式 | 長度 | 用途 |
|---|---|---|---|
| `L` | `c` | 1 位元組 | 發生了缺乏進展 |
| `G` | `c f i i`：`G`、分數、剩餘比賽時間、剩餘實際時間 | 16 位元組 | 對 `G` 的回覆。時間以秒為單位。 |

請注意，`G` 的封包包含填充位元組，因為上面的 `struct` 格式會對齊浮點數：分數從第 4 個位元組開始，時間則從第 8 和第 12 個位元組開始。

## 常用的 Webots 函式 {#common-webots-functions}

| 函式 | 說明 |
|---|---|
| `robot.getDevice(name)` | 依名稱取得裝置。在 C++ 中，請使用 `robot->getMotor(name)`、`robot->getCamera(name)` 等等。 |
| `robot.step(timeStep)` | 讓模擬前進。模擬結束時會回傳 -1。 |
| `robot.getTime()` | 取得模擬時間，單位是秒 |
| `device.enable(timeStep)` | 啟用感測器 |
| `motor.setPosition(float("inf"))` | 讓馬達無限制地轉動 |
| `motor.setVelocity(speed)` | 設定馬達的速度，單位是弧度每秒 |
