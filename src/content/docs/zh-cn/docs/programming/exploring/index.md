---
title: 探索与建图
description: 有条理地探索迷宫并绘制地图的一些思路。
---

随机乱逛的机器人得不了多少分。本页介绍如何从随机乱逛变成有条理地探索。这些是供你在此基础上发展的思路，而不是完整的解决方案。

## 知道自己在哪里 {#know-where-you-are}
地块宽 12 cm，所以根据 GPS 位置就能知道机器人在哪个地块上。每个世界中起点的位置都不同，所以一切都要从起点开始计算：

```python
TILE = 0.12
startX, _, startZ = gps.getValues() # At the start of the game

def currentTile():
    x, _, z = gps.getValues()
    return round((x - startX) / TILE), round((z - startZ) / TILE)
```

:::note
没有 GPS 时，你可以用车轮编码器和陀螺仪来估算位置，但误差会不断累积。
:::

## 记住你看到的东西 {#remember-what-you-have-seen}
用一个字典记录各个地块，以及你对每个地块所了解的信息：哪几侧有墙、地面是什么，以及你是否去过那里。

```python
tiles = {}
tiles[(0, 0)] = {"walls": {"N": False, "E": True, "S": False, "W": True}, "floor": "start", "visited": True}
```

在区域 2 和 3 中，只看地块并不能说明全部情况，因为那里的墙可能位于四分之一地块上。以四分之一地块的精度保存地图，或者使用激光雷达的点云，可以帮你应对这种情况。

## 决定去哪里 {#decide-where-to-go}
不要只是沿着墙走：那样永远到不了[浮动地块](/docs/rules/#linear-and-floating-tiles)，而那里的标识分值更高。一种常见的方法是：

1. 从当前地块出发，列出中间没有墙隔开的相邻地块。
2. 如果其中有没去过的地块，就去那里。
3. 如果没有，用广度优先搜索找到最近的、有未访问相邻地块的地块，然后前往那里。
4. 当不再有这样的地块，或者时间不多时，用同样的方法返回起点。

把坑洞当作墙来处理。沼泽会消耗时间，而且每次进入同一片沼泽消耗得更多，所以只有在值得时才进入。

## 应对意外情况 {#handle-the-unexpected}
- **缺乏进展**：机器人会被移到最后一个检查点。[监听 `L` 消息](/docs/programming/communication/#lack-of-progress)，并更新你的位置。
- **时间**：用 [`G`](/docs/programming/communication/#game-information) 查询剩余时间。留出足够的时间来发送地图并返回起点。
- **噪声**：传感器有噪声，所以在相信某处有墙或标识之前，先比较多个读数。

## 从地块到地图矩阵 {#from-tiles-to-the-map-matrix}
[地图矩阵](/docs/rules/mapping/)中每个地块对应 4 个单元格，再加上一个。对于你的地图中第 `r` 行、第 `c` 列的地块：

| 元素 | 在矩阵中的位置（行，列） |
|---|---|
| 地面标记，例如 `4` 或 `5` | 第 `4r + 1` 和 `4r + 3` 行，第 `4c + 1` 和 `4c + 3` 列 |
| 北侧的墙 | 第 `4r` 行，第 `4c` 至 `4c + 4` 列 |
| 西侧的墙 | 第 `4c` 列，第 `4r` 至 `4r + 4` 行 |

![第 r 行、第 c 列地块在地图矩阵中对应的单元格：北侧的墙在第 4r 行，西侧的墙在第 4c 列，地面标记在四分之一地块的中心](../../../../docs/programming/exploring/tile-to-matrix.svg)

你的地图可以从任何位置开始：Erebus 会利用起始地块来[对齐矩阵](/docs/rules/mapping/#how-correctness-is-calculated)，并尝试四种旋转方向。[地图规则](/docs/rules/mapping/)解释了矩阵中的每一个值。然后[提交地图](/docs/programming/map-bonus/)。

用示例世界来测试，它们的正确答案在[地图规则](/docs/rules/mapping/#examples)中。结果会以 `Map Correctness` 的形式显示在控制窗口的历史记录中。
