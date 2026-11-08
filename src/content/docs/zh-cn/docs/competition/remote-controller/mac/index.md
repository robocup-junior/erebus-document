---
title: macOS
description: macOS 的 Remote Controller 设置指南。
---

# 在同一台电脑上运行比赛服务器和控制器程序
首先，我们来试试在同一台电脑上运行比赛服务器和控制器程序。这和真实比赛的设置不同，但在本地调试时会很有帮助。

## 开启远程模式 {#toggle-remote-mode}
打开世界，在控制窗口中按下 "TOGGLE REMOTE"。按钮会变成橙色，表示已经启用。

![已开启的 TOGGLE REMOTE 按钮](../../../../../docs/competition/remote-controller/mac/toggle_remote.png)

如果控制窗口没有显示，请在 Scene Tree（场景树）中右键点击 "DEF MAINSUPERVISOR Robot"，然后选择 "Show Robot Window"。

## 运行你的程序 {#execute-your-program}
打开终端，运行下面的命令，把 `<Your controller path>` 替换为你的控制器程序的路径。

```bash
export WEBOTS_HOME=/Applications/Webots.app
"$WEBOTS_HOME/Contents/MacOS/webots-controller" "<Your controller path>"
```

如果 Webots 安装在其他位置或使用了其他名称，请相应地修改 `WEBOTS_HOME`，例如 `"/Applications/Webots R2023b.app"`。

控制器会连接到 Webots，并等待比赛开始。

## 开始比赛 {#start-the-game}
在控制窗口中按下开始按钮。机器人会出现，你的程序开始运行。

## 结束比赛 {#terminate-the-game}
要中断比赛，请在终端中按 Ctrl+C。

仿真结束时，Erebus 的比赛管理系统也会同时结束。如果你想再运行一次比赛，请重新加载世界。

# 在另一台电脑上运行比赛服务器
这是正式比赛使用的设置。运行你的控制器的电脑（客户端）和比赛服务器（服务器）必须连接到同一个网络。

1. （服务器）在服务器上启动 Webots，打开世界，并在控制窗口中开启远程模式。
1. （服务器）查出服务器的 IP 地址。你可以在 System Settings（系统设置）--> Network（网络）中找到它。
1. （客户端）运行下面的命令，把 `<Your controller path>` 替换为你的控制器程序的路径，把 `<Server IP address>` 替换为上一步查到的 IP 地址。

    ```bash
    export WEBOTS_HOME=/Applications/Webots.app
    "$WEBOTS_HOME/Contents/MacOS/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. （服务器）按下开始按钮开始比赛。

## 故障排除 {#troubleshooting}
- **控制器无法连接：** 检查两台电脑能否互相访问（例如用 `ping`），服务器的防火墙是否允许 TCP 端口 1234，以及 Webots 首选项（Preferences）的 Network 标签页中的允许 IP 列表是否为空或包含客户端。
- **显示 `No robot name provided`：** 等待期间出现这条消息是正常的。如果它一直显示，说明远程模式没有开启，请检查 TOGGLE REMOTE 按钮。
- **控制器找不到某个 Python 库：** 程序使用的是客户端上的 Python，所以请在客户端上安装这个库。

# 官方文档
如果你想更详细地了解这套设置，可以查看[官方指南](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b)。
