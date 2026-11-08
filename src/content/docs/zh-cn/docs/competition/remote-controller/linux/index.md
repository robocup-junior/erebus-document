---
title: Linux (Ubuntu)
description: 如何在 Linux（Ubuntu 22.04 LTS）上设置 Remote Controller。
---

# 在同一台电脑上运行比赛服务器和控制器程序
首先，试着在同一台电脑上运行比赛服务器和你的控制器程序。这和比赛时的设置不同，但很适合在本地调试。

## 开启远程模式 {#toggle-remote-mode}
打开世界，在控制窗口中按下“TOGGLE REMOTE”。按钮变成橙色，表示远程模式已开启。

![已开启的 TOGGLE REMOTE 按钮](../../../../../docs/competition/remote-controller/linux/toggle_remote.png)

如果控制窗口没有显示，请在 Scene Tree（场景树）中右键点击“DEF MAINSUPERVISOR Robot”，然后选择“Show Robot Window”。

## 运行你的程序 {#execute-your-program}
打开终端，运行下面的命令，把 `<Your controller path>` 替换为你的控制器程序的路径。

```bash
export WEBOTS_HOME=/usr/local/webots
"$WEBOTS_HOME/webots-controller" "<Your controller path>"
```

这里假设 Webots 是用 `.deb` 安装包安装在 `/usr/local/webots` 中的。如果你把它安装在其他位置，请相应地修改 `WEBOTS_HOME`。

控制器会连接到 Webots，并等待比赛开始。

## 开始比赛 {#start-the-game}
在控制窗口中按下开始按钮。机器人会出现，你的程序开始运行。

## 结束比赛 {#terminate-the-game}
要停止比赛，请在终端中按 Ctrl+C。

仿真结束时，Erebus 的比赛管理器也会随之停止。要再运行一次比赛，请重新加载世界。

# 在另一台电脑上运行比赛服务器
这是正式比赛中使用的设置。运行你的控制器的电脑（客户端）和运行比赛的电脑（服务器）必须连接到同一个网络。

1. （服务器）在服务器上启动 Webots，打开世界，并在控制窗口中开启远程模式。
1. （服务器）查出服务器的 IP 地址，例如使用 `ip addr` 命令。
1. （客户端）运行下面的命令，把 `<Your controller path>` 替换为你的控制器程序的路径，把 `<Server IP address>` 替换为上一步查到的 IP 地址。

    ```bash
    export WEBOTS_HOME=/usr/local/webots
    "$WEBOTS_HOME/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. （服务器）按下开始按钮，开始比赛。

## 故障排除 {#troubleshooting}
- **控制器无法连接**：检查两台电脑能否互相访问（例如用 `ping`），服务器的防火墙是否允许 TCP 端口 1234，以及 Webots 首选项（Preferences）的 Network 标签页中的允许 IP 列表是否为空或包含客户端。
- **显示 `No robot name provided`**：控制器等待期间出现这条消息是正常的。如果它一直不消失，说明远程模式没有开启：请检查 TOGGLE REMOTE 按钮。
- **控制器找不到某个 Python 库**：程序使用的是客户端上安装的 Python，所以请在客户端上安装这个库。

# 官方文档
有关这套设置的更多细节，请参阅 [Webots 指南](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b)。
