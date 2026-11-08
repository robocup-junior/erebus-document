---
title: 常見問題
description: 關於 Erebus 和比賽的常見問題。
---

## 關於 Erebus {#about-erebus}

### 我需要一台真正的機器人嗎？ {#do-i-need-a-real-robot}
不需要。一切都在模擬器中進行。機器人是由你設計的虛擬 e-puck。

### 我可以使用哪些程式語言？ {#which-programming-languages-can-i-use}
本文件涵蓋 Python 和 C/C++。Erebus 也可以載入 Java 和 MATLAB 控制器，但本文件沒有這些語言的範例。

### 我需要效能強大的電腦嗎？ {#do-i-need-a-powerful-computer}
不需要，請參閱[系統需求](/docs/installation/)。速度較慢的電腦可能需要[降低圖形設定](/docs/troubleshooting/#the-simulation-runs-too-slowly)。

### 我可以使用較新版本的 Webots 嗎？ {#can-i-use-a-newer-version-of-webots}
不行。Erebus v26 在 Webots **R2023b** 上執行。你可以同時保留其他已安裝的版本。

### 我可以使用 OpenCV 或 NumPy 之類的函式庫嗎？ {#can-i-use-libraries-like-opencv-or-numpy}
可以。只要註明原作者並遵守授權條款，就可以使用外部程式碼。隊伍應以學習為優先，而且必須能夠說明自己的解法是如何運作的。

## 比賽 {#the-game}

### 學習的最佳順序是什麼？ {#what-is-the-best-order-to-learn-things}
依照[學習路線](/docs/#the-learning-path)：了解比賽、取得機器人、執行它、學習基礎，然後進行比賽。

### 撰寫程式之前需要先做出機器人嗎？ {#do-i-need-to-make-a-robot-before-programming}
需要。每個程式都在你載入的機器人上執行，所以請從[取得機器人](/docs/robot/)開始。如果趕時間，可以直接下載完成的入門機器人。

### 機器人從哪裡出發？ {#where-does-the-robot-start}
從位於區域 1 的起始地塊出發。它一定會朝向沒有牆壁的方向。

### 如果機器人掉進坑洞會怎樣？ {#what-happens-if-the-robot-falls-into-a-hole}
會發生缺乏進展（lack of progress）：機器人會回到最後造訪的檢查點，而且你會被扣 5 分。

### 機器人一定要回到起點嗎？ {#does-the-robot-have-to-return-to-the-start}
不一定，但只要已辨識出至少一個牆上的標記，回到起始地塊並傳送 `E` 就能獲得 10% 的出口加成（exit bonus）。

### 我的機器人要怎麼知道還剩多少時間？ {#how-can-my-robot-tell-how-much-time-is-left}
用 [`G` 訊息](/docs/programming/communication/#game-information)。比賽有兩個計時器，而比賽時間在沼澤中會流逝得更快。

### 我一定要探索區域 4 嗎？ {#do-i-have-to-explore-area-4}
不一定。區域 4 是選擇性的，但那裡的標記價值最高：分數最高，而且還要乘以 2。

### 我一定要為區域 4 建圖嗎？ {#do-i-have-to-map-area-4}
不需要。區域 4 的所有格子都是 `*`，所以你只需要把它們填上即可。

### 我的機器人可以事先知道地圖嗎？ {#can-my-robot-know-the-map-beforehand}
不可以。禁止預先建立場地地圖或預先記錄牆上標記的位置。

## 參加比賽 {#the-competition}

### 我要怎麼參加？ {#how-do-i-take-part}
透過你所在地區的 RoboCupJunior 比賽。國際賽的名額由你的地區代表（Regional Representative）分配。請參閱 [RoboCupJunior 網站](https://junior.robocup.org/)。

### 我應該準備什麼？ {#what-should-i-prepare}
請參閱[賽前準備](/docs/competition/)。

### 我可以在哪裡詢問規則？ {#where-can-i-ask-about-the-rules}
在 [RoboCupJunior 論壇](https://junior.forum.robocup.org/)上。規則釐清也會公布在那裡，所以請定期查看。
