---
title: World Editor
description: 如何用 Erebus World Editor 创建你自己的世界。
---

## 背景 {#background}

当你的机器人能够应对自带的地图和简单的迷宫之后，也许你会想要更有挑战性的地图，或者想测试一些自带地图没有涵盖的特定场景。
为此，可以使用在线的 [Erebus World Editor](https://world.erebus.rcj.cloud/)。你在浏览器中绘制地图，它会导出一个可以在 Erebus 中运行的 `.wbt` 世界文件。

![World Editor 中一张完成的地图](../../../../docs/tools/world-editor/overview.png)

如果你只是制作用于测试的小地图，场地是否符合规则可能并不重要。但如果你打算制作比赛用的场地，请阅读官方的[仿真规则](https://junior.robocup.org/wp-content/uploads/2026/02/RCJRescueSimulation2026-final.pdf)。编辑器会在你工作时根据规则检查你的地图。

编辑器内置了指南：按右下角的 **Guide**，可以选择一堂制作示例地图的实践课（约 15 分钟）、一次界面导览，或者一堂关于房间 4 的课。编辑器的语言可以在它旁边切换。

## 开始制作地图 {#starting-a-map}
打开编辑器时，选择你想遵循**哪一年的规则**，然后按 **New map**。**Erebus v26 请选择 2026 年规则。** 2027 年规则是为下一个 Erebus 版本准备的草案。

![World Editor 的开始界面](../../../../docs/tools/world-editor/start.png)

你的工作会保存在浏览器中，但换一个浏览器或者清除浏览数据后就会丢失。对于重要的地图，请用顶部栏中的保存按钮把它们保存为 JSON，之后可以用打开按钮重新打开。

推荐的工作顺序是：尺寸和轮廓、房间、通道、墙壁、地面、障碍物和受害者、房间 4，最后是检查和导出。工具位于左侧，每个工具都有键盘快捷键。所选工具的设置会显示在旁边的面板中。

| 工具 | 快捷键 | 用途 |
|---|---|---|
| Select | `S` | 选择、移动、复制和粘贴地图的一部分 |
| Move | `H` | 移动视图 |
| Outline | `X` | 设置地图的尺寸和形状 |
| Rooms | `M` | 绘制房间 1 到 4（即规则中的区域） |
| Passages | `P` | 用通道连接房间 |
| Line | `L` | 绘制墙壁 |
| Curve | `A` | 在房间 3 中绘制弧形墙 |
| Eraser | `E` | 删除墙壁、地面、障碍物和受害者 |
| Floor | `F` | 设置检查点、坑洞、沼泽和起始地块 |
| Obstacle | `O` | 放置障碍物 |
| Victims | `V` | 放置字母受害者、认知目标和假标识 |

鼠标滚轮可以缩放，按住空格键拖动可以移动视图，撤销是 `⌘Z` 或 `Ctrl+Z`。

## 尺寸和轮廓 {#size-and-outline}
用 **Outline** 工具以地块为单位设置地图的尺寸。外墙会自动生成。**Outline (uneven)** 让你可以点击地块，把它们从地图中去掉；你还可以在点击的位置插入或删除行和列。

![Outline 工具](../../../../docs/tools/world-editor/outline.png)

## 房间和通道 {#rooms-and-passages}
用 **Rooms** 工具绘制每个房间的地块。房间之间的边界上会自动添加墙壁。然后用 **Passages** 工具连接各个房间：每个通道的颜色会根据它所连接的房间自动选择。

![Rooms 工具](../../../../docs/tools/world-editor/rooms.png)

![Passages 工具](../../../../docs/tools/world-editor/passages.png)

## 墙壁 {#walls}
用 **Line** 工具绘制墙壁：在房间 1 中沿地块边缘绘制，在房间 2 和 3 中沿四分之一地块绘制。在房间 3 中使用 **Curve** 工具，指向地块的某个四分之一来选择弧线。再次点击同一条弧线就会删除它。

![用于绘制墙壁的 Line 工具](../../../../docs/tools/world-editor/walls.png)

## 地面和障碍物 {#floors-and-obstacles}
用 **Floor** 工具选择一种地面类型，然后点击地块来设置。起始地块必须是房间 1 中的地块，没有起始地块的世界无法导出。一个地块只能是坑洞、沼泽、检查点、障碍物、起点或通道中的一种。

![Floor 工具](../../../../docs/tools/world-editor/floors.png)

用 **Obstacle** 工具选择一种形状，然后点击地块。在房间 1 到 3 中，每个地块上最多放一个障碍物，其中心位于该地块上。点击一个障碍物，就可以用它的控制柄和面板修改它的尺寸、高度、颜色和旋转角度。

![Obstacle 工具](../../../../docs/tools/world-editor/obstacles.png)

## 受害者和认知目标 {#victims-and-cognitive-targets}
用 **Victims** 工具选择一种类型，然后在墙附近点击。你可以放置：

- 真实的字母受害者：受伤、稳定和未受伤
- 带有立体符号的假字母受害者
- 认知目标：选择危险品类型，如果需要，还可以选择各个圆环的颜色。编辑器会显示数值之和，它决定了类型
- 假认知目标，其圆环数值之和不在 0 到 3 之间

在房间 1 中，每条地块边上可以放置一个受害者。在房间 2 和 3 中，受害者放在 6 cm 墙的各个面上，而弧形墙有内侧和外侧两个位置。在 **Turn** 下，可以选择固定的旋转角度，或者让每个新标识随机旋转。点击已放置的标识可以修改或删除它，也可以沿着它所在的墙拖动它。

![Victims 工具](../../../../docs/tools/world-editor/victims.png)

## 房间 4 {#room-4}
房间 4 不是基于地块的，所以要以图片的形式绘制。用 **Rooms** 工具绘制房间 4，然后按 **Draw room 4**（或者双击这个房间）打开房间 4 创建器。

![房间 4 创建器](../../../../docs/tools/world-editor/room4.png)

你用黑色绘制的部分会变成墙壁。创建器提供了自由绘制的工具，以及绘制直线、曲线、圆弧、矩形、椭圆、多边形和图标形状的工具，还有放置受害者和障碍物的工具。房间 4 中可以放置任意数量的障碍物。红色条纹表示机器人无法到达的地方，而且你必须留出一条大约一个地块宽的路径，让机器人能够通过。

完成后按 **OK**：图片会作为房间 4 出现在地图上，并包含在导出的世界中。创建器右上角的按钮可以把图片保存为 PNG，这样你就可以在另一张地图中使用同一个房间 4；也可以打开 PNG 或 JPEG 图片。

## 检查你的地图 {#checking-your-map}
每次修改都会根据规则进行检查，结果显示在右上角的 **Checks** 卡片中。红色的 ✕ 是会阻止世界导出的问题，黄色的 ! 是值得留意的警告。点击某一项可以跳转到它。**Fix** 修复单个项目，**Fix all that can be fixed** 修复所有可以修复的项目。

![World Editor 中的一张新地图，带有 Checks 卡片](../../../../docs/tools/world-editor/new_map.png)

顶部栏中的 **Linear** 按钮会把每个地块标记为线性地块或浮动地块，这决定了标识的分值。

![在地图上显示的线性地块和浮动地块](../../../../docs/tools/world-editor/linear.png)

顶部栏中的奖杯图标显示根据计分规则计算出的地图**最高得分**，包括每个房间所占的分数，以及加上离场奖励和地图奖励后的得分。

![地图的最高得分](../../../../docs/tools/world-editor/max_score.png)

## 导出并运行你的世界 {#exporting-and-running-your-world}
在顶部栏中设置地图的名称，然后按右上角的 **.wbt** 按钮。然后：

1. 把 `.wbt` 文件复制到 Erebus 的 `game/worlds` 文件夹中。它必须放在这个文件夹里，因为世界会用到 Erebus 中的文件。
1. 在 Webots 中打开它，或者用[控制窗口](/docs/getting-started/)的 **Worlds** 按钮选择它。

![编辑器指南中的示例地图，在 Erebus v26.1 中运行](../../../../docs/tools/world-editor/exported_world.png)

*编辑器指南中的示例地图，在 Erebus v26.1 中运行。*

`.wbt` 文件无法转换回可以编辑的地图，所以也请保留 JSON 文件。
