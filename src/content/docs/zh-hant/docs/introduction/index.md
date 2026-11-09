---
title: 什麼是 Erebus？
description: Erebus 是 RoboCupJunior 的救援模擬平台，以 Webots 為基礎打造。了解它的各個部分如何組合在一起。
---

Erebus 是一個機器人模擬比賽環境。你要為一台機器人開發控制器，讓它自主探索迷宮、找到並辨識牆上的標記（笑臉受害者和認知目標）、避開障礙物和陷阱、維持電池電量，並建立環境的地圖。

它以 [Webots](https://cyberbotics.com/) 為基礎。Webots 是一個專為專業用途設計的機器人模擬平台，廣泛應用於產業、教育和研究。自 1998 年以來，Cyberbotics 一直持續維護 Webots。

這個平台主要是為 [RoboCupJunior Rescue Simulation](https://junior.robocup.org/rescue/) 比賽設計的，適合具有中階到進階經驗的程式設計者。

## 各部分如何組合在一起 {#how-it-fits-together}

| 元件 | 功能 | 取得方式 |
|---|---|---|
| **Webots R2025a** | 3D 機器人模擬器 | [Webots R2025a 版本](https://github.com/cyberbotics/webots/releases/tag/R2025a) |
| **Erebus** | 各個世界和監督程式（Main Supervisor），負責套用規則並計算分數 | [Erebus 版本](https://github.com/robocup-junior/erebus/releases) |
| **你的控制器** | 你的機器人的程式，使用 Python 或 C/C++ | 由你撰寫！ |
| **Robot Customizer** | 設計自訂機器人並匯出為 JSON 檔案的網頁工具 | [robot.erebus.rcj.cloud](https://robot.erebus.rcj.cloud/) |
| **World Editor** | 繪製練習地圖並匯出為 `.wbt` 世界的網頁工具 | [world.erebus.rcj.cloud](https://world.erebus.rcj.cloud/) |

## 你可以用它做什麼？ {#what-can-you-do-with-it}

1. **組裝機器人。** 在預算內選擇它的感測器和安裝位置。
2. **撰寫程式。** 你的控制器會讀取感測器並決定要做什麼，完全不需要人類協助。
3. **執行。** 在內建的世界或你自己的世界上測試，並觀察分數。
4. **參加比賽。** 參加地區、區域和國際的 RoboCupJunior 比賽。

如果你已經認識 Erebus，請參閱 [v27 新功能](/docs/whats-new/)。

## 實用參考資料 {#useful-references}
學習和使用 Erebus 的實用連結：
- [Webots 使用者指南](https://cyberbotics.com/doc/guide/index?version=R2025a)
- [Webots 參考手冊](https://cyberbotics.com/doc/reference/nodes-and-api-functions?version=R2025a)
- [Python 文件](https://www.python.org/doc/)
- [C++ 文件](https://www.cplusplus.com/doc/tutorial/)
- [OpenCV 教學](https://docs.opencv.org/4.x/d9/df8/tutorial_root.html)
- [RCJ Rescue 社群網站](https://rescue.rcj.cloud/)：活動、隊伍文件，以及 TDP、海報和影片的評分標準
- [RoboCupJunior 論壇](https://junior.forum.robocup.org/)：規則釐清

## 下一步 {#next}
[安裝 Erebus](/docs/installation/)，然後閱讀[規則摘要](/docs/rules/)以了解比賽。
