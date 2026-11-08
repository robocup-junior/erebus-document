---
title: 取得機器人
description: 每個程式都在你設計的機器人上執行。下載入門機器人，或自己組裝。
---

在 Erebus 中，**機器人由你設計**：你要在預算內選擇它的感測器和安裝位置。每個程式都需要一台機器人，所以第一步就是取得一台機器人，並在 Erebus 中載入它。

![一台真實的 e-puck 機器人](../../../docs/robot/real_robot.thumbnail.jpg)

這台機器人以 [e-puck](https://cyberbotics.com/doc/guide/epuck?version=R2023b) 為基礎，e-puck 是一台有兩個輪子的小型圓形教育機器人。你可以用 [Robot Customizer](https://robot.erebus.rcj.cloud/) 為它加上感測器，並把設計儲存為 Erebus 可以載入的 `.json` 檔案。

## 入門機器人 {#the-starter-robot}
本文件在所有地方都使用同一台機器人，也就是**入門機器人**（starter robot），讓每個範例都能直接運作。它具備教學所需的所有感測器：

| 元件 | 程式中的名稱 | 用途 |
|---|---|---|
| 兩個輪子 | `left wheel motor`、`right wheel motor` | 移動 |
| 輪子編碼器 | `left wheel sensor`、`right wheel sensor` | 測量輪子轉了多少 |
| 三個距離感測器 | `leftDist`、`frontDist`、`rightDist` | 找出左方、前方和右方的牆壁 |
| 攝影機，64 × 40 像素 | `camera` | 找出牆上的標記 |
| 顏色感測器 | `color` | 查看地板：坑洞、沼澤和通道 |
| GPS | `gps` | 知道自己的位置，以便回報標記 |
| 陀螺儀 | `gyro` | 測量轉了多少 |
| 加速度計 | `accelerometer` | 測量加速度 |
| 光達 | `lidar` | 測量周圍一整圈的距離 |
| 發射器和接收器 | `emitter`、`receiver` | 與比賽溝通。每台機器人都有。 |

它花費 3000 預算中的 2400。

## 選擇你的方式 {#choose-your-path}

**建議：自己組裝。** 大約需要 15 分鐘，而且你會了解機器人的每一個部分。請參閱[組裝機器人](/docs/robot/build/)。

**趕時間的話：** 下載完成的機器人，直接繼續教學。之後隨時都可以回來自己組裝。

<a href="/downloads/starter-robot.json" download>下載 starter-robot.json</a>

## 在 Erebus 中載入 {#load-it-in-erebus}
1. 開啟一個世界，例如 `game/worlds/world1.wbt`。
2. 在控制視窗中，按下有機器人圖示的**右邊 LOAD 按鈕**，然後選擇你的 `.json` 檔案。
3. 查看 Webots 主控台。Erebus 會列出每個元件和它的成本，最後顯示 `Your custom robot has been successfully generated!`。

:::note
Erebus v26.1 還會以紅色印出 `PROTO parameter 'camera_width' has no matching IS field`。你可以忽略它：你的攝影機仍然是你選擇的解析度。
:::

機器人會一直保持載入，直到你載入另一台機器人或重設比賽。接下來，[執行你的第一個程式](/docs/getting-started/)。

## 設計你自己的機器人 {#designing-your-own}
熟悉基礎之後，就可以修改入門機器人或設計一台新的：更多更高解析度的攝影機、更多距離感測器、把感測器放在其他位置。[Robot Customizer 參考](/docs/robot/customizer/)列出了所有元件、它們的成本和限制。

如果你更改了元件的名稱，也要在程式中一併更改。
