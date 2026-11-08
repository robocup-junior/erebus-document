---
title: 什么是 Erebus？
description: Erebus 是 RoboCupJunior 的救援仿真平台，基于 Webots 构建。了解它的各个部分如何协同工作。
---

Erebus 是一个机器人仿真比赛环境。你需要为一个机器人开发控制器，让它自主探索迷宫，找到并识别墙面标识（字母受害者和认知目标），避开障碍物和陷阱，并绘制出环境的地图。

它基于 [Webots](https://cyberbotics.com/) 构建。Webots 是一个为专业用途设计的机器人仿真平台，广泛应用于工业、教育和研究领域。自 1998 年以来，Cyberbotics 一直在持续维护 Webots。

这个平台主要是为 [RoboCupJunior Rescue Simulation](https://junior.robocup.org/rescue/)（救援仿真）比赛设计的，面向具有中级到高级经验的程序员。

## 各部分如何协同工作 {#how-it-fits-together}

| 组成部分 | 作用 | 获取方式 |
|---|---|---|
| **Webots R2023b** | 3D 机器人仿真器 | [Webots R2023b 发布页](https://github.com/cyberbotics/webots/releases/tag/R2023b) |
| **Erebus** | 各个世界和比赛管理器（Main Supervisor），负责执行规则并计算得分 | [Erebus 发布页](https://github.com/robocup-junior/erebus/releases) |
| **你的控制器** | 机器人的程序，用 Python 或 C/C++ 编写 | 由你来编写！ |
| **Robot Customizer** | 用来设计自定义机器人并导出为 JSON 文件的网页工具 | [robot.erebus.rcj.cloud](https://robot.erebus.rcj.cloud/) |
| **World Editor** | 用来绘制练习地图并导出为 `.wbt` 世界的网页工具 | [world.erebus.rcj.cloud](https://world.erebus.rcj.cloud/) |

## 你可以用它做什么？ {#what-can-you-do-with-it}

1. **搭建机器人。** 在预算范围内选择它的传感器和安装位置。
2. **为它编程。** 你的控制器读取传感器并决定要做什么，不需要任何人的帮助。
3. **运行它。** 在自带的世界或你自己的世界中测试，并查看得分。
4. **参加比赛。** 参加地方、地区和国际级别的 RoboCupJunior 比赛。

如果你已经了解 Erebus，请查看 [v26 新功能](/docs/whats-new/)。

## 有用的参考资料 {#useful-references}
学习和使用 Erebus 时有用的链接：
- [Webots 用户指南](https://cyberbotics.com/doc/guide/index?version=R2023b)
- [Webots 参考手册](https://cyberbotics.com/doc/reference/nodes-and-api-functions?version=R2023b)
- [Python 文档](https://www.python.org/doc/)
- [C++ 文档](https://www.cplusplus.com/doc/tutorial/)
- [OpenCV 教程](https://docs.opencv.org/4.x/d9/df8/tutorial_root.html)
- [RCJ Rescue 社区网站](https://rescue.rcj.cloud/)：活动、队伍文档，以及 TDP、海报和视频的评分标准
- [RoboCupJunior 论坛](https://junior.forum.robocup.org/)：规则澄清

## 下一步 {#next}
[安装 Erebus](/docs/installation/)，然后阅读[规则概要](/docs/rules/)来了解比赛。
