---
title: 術語表
description: Erebus 和規則中使用的術語。
---

| 術語 | 意思 |
|---|---|
| **區域（Area）** | 場地的四個部分之一，每個區域都有自己的牆壁類型。World Editor 稱它們為房間（rooms）。 |
| **區域倍數（Area multiplier，AM）** | 1、1.25、1.5 或 2，套用在各區域的得分上 |
| **檢查點（Checkpoint）** | 銀色的地塊。發生缺乏進展後，機器人會回到最後造訪的檢查點。 |
| **認知目標（Cognitive target）** | 由五個同心圓顏色組成的牆上標記，顏色的總和代表一種危險物品類型。2026 年取代了危險物品標誌（hazmat signs）。 |
| **控制視窗（Control window）** | 載入程式並執行比賽的網頁。也稱為機器人視窗（robot window）。 |
| **控制器（Controller）** | 你的程式 |
| **自訂機器人（Custom robot）** | 用 Robot Customizer 設計，並從 `.json` 檔案載入的機器人 |
| **出口加成（Exit bonus，EB）** | 回到起始地塊並傳送 `E` 時獲得 +10% |
| **假目標（Fake）** | 不可以回報的標記：立體的字母受害者，以及總和無效的認知目標 |
| **浮動地塊（Floating tile）** | 沿著與起點相連的牆壁走無法到達的地塊。這裡的標記分數較高。 |
| **缺乏進展（Lack of progress，LoP）** | 機器人卡住或掉進坑洞時。機器人會回到最後一個檢查點，並扣 5 分。 |
| **字母受害者（Letter victim）** | 帶有 Φ、Ψ 或 Ω 符號的牆上標記 |
| **線性地塊（Linear tile）** | 沿著與起點相連的牆壁走可以到達的地塊 |
| **Main Supervisor（主監督程式）** | Erebus 中管理比賽的部分。也稱為比賽管理程式（game manager）。 |
| **地圖加成（Mapping bonus，MB）** | 分數倍數，等於正確率 × 1.2 + 1 |
| **地圖矩陣（Map matrix）** | 表示地圖的陣列 |
| **通道（Passage）** | 連接兩個區域的彩色地塊 |
| **四分之一地塊（Quarter tile）** | 地塊的四分之一，寬 6 cm，用於區域 2 和 3 |
| **伺服器－用戶端架構（Server-client setup）** | 比賽在一台電腦上執行，你的程式在另一台電腦上執行。請參閱 Remote Controller。 |
| **沼澤（Swamp）** | 會讓比賽時間流逝得更快的棕色地塊 |
| **TDP** | 技術說明文件（Technical Description Paper） |
| **地塊（Tile）** | 場地的單位，寬 12 cm |
| **TI、TT、CN、TMI** | 計分中的標記辨識（token identification）、標記類型（token type）、通過檢查點（checkpoint negotiation）和標記誤判（token misidentification） |
| **牆上的標記（Wall token）** | 牆上任何需要辨識的東西：字母受害者和認知目標 |
| **世界（World）** | 一張地圖，以 `.wbt` 檔案表示 |
