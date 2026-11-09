---
title: 探索與建圖
description: 有系統地探索迷宮並建立地圖的思路。
---

隨機亂走的機器人得不了多少分。本頁說明如何從隨機亂走進步到有系統地探索。這些是可以延伸發展的思路，而不是完整的解答。

## 知道自己在哪裡 {#know-where-you-are}
地塊寬 12 cm，所以從 GPS 位置就能得知所在的地塊。每個世界的起點位置都不同，所以請以起點為基準測量一切：

```python
TILE = 0.12
startX, _, startZ = gps.getValues() # At the start of the game

def currentTile():
    x, _, z = gps.getValues()
    return round((x - startX) / TILE), round((z - startZ) / TILE)
```

:::note
沒有 GPS 的話，你可以用輪子編碼器和陀螺儀估計位置，但誤差會不斷累積。
:::

## 記住你看過的東西 {#remember-what-you-have-seen}
用一個字典記錄地塊，以及你對每個地塊所知道的資訊：哪幾側有牆、地板是什麼，以及是否已經造訪過。

```python
tiles = {}
tiles[(0, 0)] = {"walls": {"N": False, "E": True, "S": False, "W": True}, "floor": "start", "visited": True}
```

在區域 2 和 3 中，牆壁可能位於四分之一地塊上，所以只看地塊無法掌握全貌。以四分之一地塊的解析度儲存地圖，或使用光達點雲，能讓你為這些區域做好準備。

## 決定要去哪裡 {#decide-where-to-go}
不要只是沿著牆走：這樣永遠到不了[浮動地塊](/docs/rules/#linear-and-floating-tiles)，而那裡的標記分數更高。常見的做法是：

1. 從目前的地塊，列出中間沒有牆隔開的相鄰地塊。
2. 如果有尚未造訪的相鄰地塊，就前往其中一個。
3. 如果沒有，就用廣度優先搜尋找出最近一個有未造訪相鄰地塊的地塊，然後前往那裡。
4. 當這樣的地塊都沒有了，或時間快用完時，就用同樣的方式返回起點。

把坑洞當成牆壁。沼澤會花費時間，而且每次進入同一個沼澤都會花費更多，所以只有在值得時才進入。

## 應付意外狀況 {#handle-the-unexpected}
- **缺乏進展：** 機器人會被移到最後一個檢查點。[接收 `L` 訊息](/docs/programming/communication/#lack-of-progress)，並更新你的位置。
- **時間：** 用 [`G`](/docs/programming/communication/#game-information) 查詢剩餘時間。留下足夠的時間傳送地圖並返回起點。
- **雜訊：** 感測器有雜訊，所以在相信偵測到牆壁或標記之前，請先比較多次讀數。

## 從地塊到地圖矩陣 {#from-tiles-to-the-map-matrix}
[地圖矩陣](/docs/rules/mapping/)中每個地塊有 4 個格子，再加上一個。對於你的地圖中第 `r` 列、第 `c` 行的地塊：

| 元素 | 矩陣位置（列，行） |
|---|---|
| 地板標示，例如 `4` 或 `5` | 第 `4r + 1` 和 `4r + 3` 列，第 `4c + 1` 和 `4c + 3` 行 |
| 北側牆壁 | 第 `4r` 列，第 `4c` 到 `4c + 4` 行 |
| 西側牆壁 | 第 `4c` 行，第 `4r` 到 `4r + 4` 列 |

![第 r 列、第 c 行地塊在地圖矩陣中對應的格子：北側牆壁在第 4r 列，西側牆壁在第 4c 行，地板標示在四分之一地塊的中央](../../../../docs/programming/exploring/tile-to-matrix.svg)

你的地圖可以從任何位置開始：Erebus 會利用起始地塊[對齊矩陣](/docs/rules/mapping/#how-correctness-is-calculated)，並嘗試四種旋轉方向。[地圖規則](/docs/rules/mapping/)說明了矩陣中的每一個值。然後再[提交地圖](/docs/programming/map-bonus/)。

用範例世界來測試，它們的正確答案在[地圖規則](/docs/rules/mapping/#examples)中。結果會以 `Map Correctness` 顯示在控制視窗的歷史紀錄中。
