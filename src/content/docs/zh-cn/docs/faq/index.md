---
title: 常见问题
description: 关于 Erebus 和比赛的常见问题。
---

## 关于 Erebus {#about-erebus}

### 我需要一台真实的机器人吗？ {#do-i-need-a-real-robot}
不需要。一切都在仿真器中进行。机器人是一台由你设计的虚拟 e-puck。

### 我可以使用哪些编程语言？ {#which-programming-languages-can-i-use}
本文档介绍的是 Python 和 C/C++。Erebus 也可以加载 Java 和 MATLAB 控制器，但本文档没有这两种语言的示例。

### 我需要高性能的电脑吗？ {#do-i-need-a-powerful-computer}
不需要，请参阅[系统要求](/docs/installation/)。较慢的电脑可能需要[降低图形设置](/docs/troubleshooting/#the-simulation-runs-too-slowly)。

### 我可以使用更新版本的 Webots 吗？ {#can-i-use-a-newer-version-of-webots}
不可以。Erebus v27 在 Webots **R2025a** 上运行。你可以同时保留已安装的其他版本，例如用于 Erebus v26 的 R2023b。

### 我可以使用 OpenCV 或 NumPy 之类的库吗？ {#can-i-use-libraries-like-opencv-or-numpy}
可以。允许使用外部代码，前提是你注明代码的作者并遵守它的许可证。各队应把学习放在首位，并且必须能够解释自己的方案是如何工作的。

## 比赛 {#the-game}

### 按什么顺序学习最好？ {#what-is-the-best-order-to-learn-things}
按照[学习路线](/docs/#the-learning-path)进行：了解比赛，获取机器人，运行它，学习基础知识，然后进行比赛。

### 编程之前需要先做一个机器人吗？ {#do-i-need-to-make-a-robot-before-programming}
需要。每个程序都运行在你加载的机器人上，所以请从[获取机器人](/docs/robot/)开始。如果赶时间，可以直接下载搭建好的入门机器人。

### 机器人从哪里出发？ {#where-does-the-robot-start}
从起始地块出发，它位于区域 1。机器人总是朝向一个没有墙的方向。

### 机器人掉进坑洞会怎样？ {#what-happens-if-the-robot-falls-into-a-hole}
会发生缺乏进展（Lack of progress）：机器人回到它最后经过的检查点，并扣 5 分。

### 机器人必须返回起点吗？ {#does-the-robot-have-to-return-to-the-start}
不需要。但只要机器人已经识别出至少一个墙面标识，回到起始地块并发送 `E` 就能获得 10% 的离场奖励（Exit bonus）。

### 我的机器人怎样知道还剩多少时间？ {#how-can-my-robot-tell-how-much-time-is-left}
通过 [`G` 消息](/docs/programming/communication/#game-information)。共有两个计时器，任意一个耗尽，比赛就会结束。

### 电池耗尽会怎样？ {#what-happens-when-the-battery-runs-out}
比赛结束。为了避免这种情况，请在青色的接触地块上停留 5 秒来更换电池。你的程序可以通过 [`G` 消息](/docs/programming/communication/#game-information)读取电池电量。参见[电池](/docs/programming/battery/)。

### 开得慢能省电吗？ {#does-driving-slowly-save-the-battery}
电池按电机的速度消耗，所以慢速机器人每秒耗电更少，但同样时间内走过的距离也更短。请通过测试为你的机器人找到最佳平衡。

### 我必须探索区域 4 吗？ {#do-i-have-to-explore-area-4}
不需要。这是可选的，但那里的标识价值最高：分值最高，而且还要乘以 2。

### 我必须绘制区域 4 的地图吗？ {#do-i-have-to-map-area-4}
不需要。区域 4 的所有单元格都是 `*`，只要把它们填上即可。

### 我的机器人可以事先知道地图吗？ {#can-my-robot-know-the-map-beforehand}
不可以。禁止事先绘制场地地图或记录墙面标识的位置。

## 参加比赛 {#the-competition}

### 怎样参加比赛？ {#how-do-i-take-part}
通过你所在地区的 RoboCupJunior 比赛参加。国际赛的名额由你所在地区的代表（Regional Representative）分配。请参阅 [RoboCupJunior 网站](https://junior.robocup.org/)。

### 我应该准备什么？ {#what-should-i-prepare}
请参阅[赛前准备](/docs/competition/)。

### 我可以在哪里询问规则问题？ {#where-can-i-ask-about-the-rules}
在 [RoboCupJunior 论坛](https://junior.forum.robocup.org/)上。规则澄清也会发布在那里，所以请经常查看。
