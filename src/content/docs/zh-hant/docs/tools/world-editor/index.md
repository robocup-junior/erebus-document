---
title: World Editor
description: 如何用 Erebus World Editor 建立你自己的世界。
---

## 背景 {#background}

當你征服了測試地圖，而且你的機器人能夠跑完簡單的迷宮之後，也許你會想挑戰更困難的內容，或想測試我們的地圖沒有提供的特定情境。
為此，你可以使用線上的 [Erebus World Editor](https://world.erebus.rcj.cloud/)。你在瀏覽器中繪製地圖，它會匯出一個可以在 Erebus 中執行的 `.wbt` 世界檔。

![World Editor 中完成的地圖](../../../../docs/tools/world-editor/overview.png)

如果你只是製作小型地圖來測試，場地是否完全正確對你來說可能不太重要。但如果你打算製作比賽用的場地，就應該仔細閱讀官方的[模擬規則](https://junior.robocup.org/wp-content/uploads/2026/02/RCJRescueSimulation2026-final.pdf)。編輯器會在你工作時依照規則檢查你的地圖。

編輯器內建了指南：按下右下角的 **Guide**，可以選擇製作範例地圖的實作課程（約 15 分鐘）、畫面導覽，或 Room 4 的課程。編輯器的語言可以在它旁邊切換。

## 開始製作地圖 {#starting-a-map}
開啟編輯器時，請選擇要依照**哪一年的規則**，然後按下 **New map**。**Erebus v26 請選擇 2026 年規則。** 2027 年規則是下一版 Erebus 的草案。

![World Editor 的開始畫面](../../../../docs/tools/world-editor/start.png)

你的作品會保存在瀏覽器中，但換到其他瀏覽器或清除瀏覽資料時就會消失。重要的地圖請用頂端列的儲存按鈕存成 JSON，之後再用開啟按鈕重新開啟。

建議的製作順序是：大小和外框、房間、通道、牆壁、地板、障礙物和受害者、Room 4，最後是檢查和匯出。工具位於左側，每個工具都有鍵盤快速鍵。所選工具的設定會顯示在旁邊的面板中。

| 工具 | 按鍵 | 用途 |
|---|---|---|
| Select | `S` | 選取、移動、複製和貼上地圖的部分 |
| Move | `H` | 移動視角 |
| Outline | `X` | 設定地圖的大小和形狀 |
| Rooms | `M` | 繪製 Room 1 到 4（即規則中的區域） |
| Passages | `P` | 用通道連接房間 |
| Line | `L` | 繪製牆壁 |
| Curve | `A` | 在 Room 3 中繪製弧形牆 |
| Eraser | `E` | 移除牆壁、地板、障礙物和受害者 |
| Floor | `F` | 設定檢查點、坑洞、沼澤和起始地塊 |
| Obstacle | `O` | 放置障礙物 |
| Victims | `V` | 放置字母受害者、認知目標和假目標 |

滑鼠滾輪可以縮放，按住空白鍵拖曳可以移動視角，復原則是 `⌘Z` 或 `Ctrl+Z`。

## 大小和外框 {#size-and-outline}
用 **Outline** 工具以地塊為單位設定地圖的大小。外牆會自動產生。**Outline (uneven)** 讓你點選地塊，把它們從地圖中移除；你也可以在點選的位置插入或移除列和行。

![Outline 工具](../../../../docs/tools/world-editor/outline.png)

## 房間和通道 {#rooms-and-passages}
用 **Rooms** 工具繪製每個房間（Room）的地塊。房間之間的邊界會自動立起牆壁。接著，用 **Passages** 工具連接房間：每條通道的顏色會依照它所連接的房間來決定。

![Rooms 工具](../../../../docs/tools/world-editor/rooms.png)

![Passages 工具](../../../../docs/tools/world-editor/passages.png)

## 牆壁 {#walls}
用 **Line** 工具繪製牆壁：在 Room 1 中畫在地塊邊緣上，在 Room 2 和 3 中則畫在四分之一地塊上。在 Room 3 中使用 **Curve** 工具，指向地塊的四分之一來選擇弧線。再點一次同一條弧線就會移除它。

![繪製牆壁的 Line 工具](../../../../docs/tools/world-editor/walls.png)

## 地板和障礙物 {#floors-and-obstacles}
用 **Floor** 工具選擇地板類型，然後點選地塊進行設定。起始地塊必須是 Room 1 中的地塊，沒有起始地塊就無法匯出世界。一個地塊只能是坑洞、沼澤、檢查點、障礙物、起點或通道其中之一。

![Floor 工具](../../../../docs/tools/world-editor/floors.png)

用 **Obstacle** 工具選擇形狀，然後點選地塊。在 Room 1 到 3 中，每個地塊只能有一個障礙物，而且它的中心要在該地塊上。點選障礙物後，可以用它的控制點和面板改變它的大小、高度、顏色和旋轉。

![Obstacle 工具](../../../../docs/tools/world-editor/obstacles.png)

## 受害者和認知目標 {#victims-and-cognitive-targets}
用 **Victims** 工具選擇種類，然後在牆壁附近點選。你可以放置：

- 真的字母受害者：受傷（harmed）、穩定（stable）和未受傷（unharmed）
- 帶有立體符號的假字母受害者
- 認知目標：選擇危險物品類型，如果想要也可以自己選擇圓環的顏色。畫面會顯示總和，而總和決定了類型
- 假目標，它們的圓環總和不在 0 到 3 之間

在 Room 1 中，每個地塊的每一邊可以有一個受害者。在 Room 2 和 3 中，受害者放在 6 cm 牆面上，而弧形牆有內側和外側兩個位置。在 **Turn** 下方，可以選擇固定的旋轉角度，或讓每個新標記隨機旋轉。點選已放置的標記可以修改或移除它，也可以沿著牆拖曳它。

![Victims 工具](../../../../docs/tools/world-editor/victims.png)

## Room 4 {#room-4}
Room 4 不是以地塊為基礎，所以要用畫圖的方式繪製。用 **Rooms** 工具繪製 Room 4，然後按下 **Draw room 4**（或雙擊該房間）開啟 Room 4 建立工具。

![Room 4 建立工具](../../../../docs/tools/world-editor/room4.png)

你用黑色畫的部分會變成牆壁。建立工具提供了徒手繪圖，以及繪製直線、曲線、圓弧、矩形、橢圓、多邊形和圖示形狀的工具，還有放置受害者和障礙物的工具。Room 4 中可以放置任意數量的障礙物。紅色條紋表示機器人無法到達的地方，而你必須留下大約一個地塊寬的空間讓機器人通過。

完成後，按下 **OK**：這張圖會以 Room 4 的形式出現在地圖上，並包含在匯出的世界中。建立工具右上角的按鈕可以把圖存成 PNG，讓你在其他地圖中使用同一個 Room 4，也可以開啟 PNG 或 JPEG 圖片。

## 檢查你的地圖 {#checking-your-map}
每次修改都會依照規則進行檢查，結果顯示在右上角的 **Checks** 卡片中。紅色的 ✕ 是會阻止世界匯出的問題，黃色的 ! 則是值得留意的警告。點選項目就會跳到該處。**Fix** 會修正一個項目，**Fix all that can be fixed** 則會修正所有可以修正的項目。

![World Editor 中的新地圖，以及 Checks 卡片](../../../../docs/tools/world-editor/new_map.png)

頂端列的 **Linear** 按鈕會把每個地塊標示為線性地塊或浮動地塊，這決定了標記的分數。

![地圖上顯示的線性地塊和浮動地塊](../../../../docs/tools/world-editor/linear.png)

頂端列的獎盃會顯示地圖的**最高分數**，這是依照計分規則計算的，並列出各房間所佔的分數，以及加上出口加成和地圖加成後的分數。

![地圖的最高分數](../../../../docs/tools/world-editor/max_score.png)

## 匯出並執行你的世界 {#exporting-and-running-your-world}
在頂端列設定地圖的名稱，然後按下右上角的 **.wbt** 按鈕。接著：

1. 把 `.wbt` 檔案複製到 Erebus 的 `game/worlds` 資料夾中。它必須放在這個資料夾裡，因為世界會使用 Erebus 中的檔案。
1. 在 Webots 中開啟它，或用[控制視窗](/docs/getting-started/)的 **Worlds** 按鈕選擇它。

![編輯器指南中的範例地圖，在 Erebus v26.1 中執行。](../../../../docs/tools/world-editor/exported_world.png)

*編輯器指南中的範例地圖，在 Erebus v26.1 中執行。*

`.wbt` 檔案無法轉回可以編輯的地圖，所以請一併保留 JSON 檔案。
