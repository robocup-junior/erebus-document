---
title: macOS
description: 如何在 macOS 上设置 Remote Controller。
---

# 在同一台电脑上运行比赛服务器和控制器程序
首先，试着在同一台电脑上运行比赛服务器和你的控制器程序。这和比赛时的设置不同，但很适合在本地调试。

## 开启远程模式 {#toggle-remote-mode}
打开世界，在控制窗口中按 **Robot setup**，然后打开 **Remote mode**。如果你有自定义机器人，请先在 **Robot JSON** 下加载它。

![在 Robot setup 中打开的 Remote mode](../../../../../docs/competition/remote-controller/mac/toggle_remote.png)

如果控制窗口没有显示，请在 Scene Tree（场景树）中右键点击“DEF MAINSUPERVISOR Robot”，然后选择“Show Robot Window”。

## 运行你的程序 {#execute-your-program}
打开终端，运行下面的命令，把 `<Your controller path>` 替换为你的控制器程序的路径。

```bash
export WEBOTS_HOME=/Applications/Webots.app
"$WEBOTS_HOME/Contents/MacOS/webots-controller" "<Your controller path>"
```

如果 Webots 安装在其他位置或使用了其他名称，请相应地修改 `WEBOTS_HOME`，例如 `"/Applications/Webots R2025a.app"`。

控制器会连接到 Webots，并等待比赛开始。

## 开始比赛 {#start-the-game}
在控制窗口中按 **Run match**。机器人出现，你的程序开始运行。

## 结束比赛 {#terminate-the-game}
要停止比赛，请在终端中按 Ctrl+C。

比赛结束后，按 **Reset** 可以再运行一次。除非打开了 **Keep on Reset**，否则重置会关闭 Remote mode。

# 在另一台电脑上运行比赛服务器
这是正式比赛中使用的设置。运行你的控制器的电脑（客户端）和运行比赛的电脑（服务器）必须连接到同一个网络。

1. （服务器）在服务器上启动 Webots，打开世界，并在控制窗口的 **Robot setup** 中打开 **Remote mode**。
1. （服务器）查出服务器的 IP 地址，可以在 System Settings（系统设置）> Network（网络）中找到。
1. （客户端）运行下面的命令，把 `<Your controller path>` 替换为你的控制器程序的路径，把 `<Server IP address>` 替换为上一步查到的 IP 地址。

    ```bash
    export WEBOTS_HOME=/Applications/Webots.app
    "$WEBOTS_HOME/Contents/MacOS/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. （服务器）按 **Run match** 开始比赛。

## 故障排除 {#troubleshooting}
- **控制器无法连接**：检查两台电脑能否互相访问（例如用 `ping`），服务器的防火墙是否允许 TCP 端口 1234，以及 Webots 首选项（Preferences）的 Network 标签页中的允许 IP 列表是否为空或包含客户端。
- **控制器在等待，但机器人不动：** 检查 **Remote mode** 是否已打开，然后按 **Run match**。
- **控制器找不到某个 Python 库**：程序使用的是客户端上安装的 Python，所以请在客户端上安装这个库。

# 官方文档
有关这套设置的更多细节，请参阅 [Webots 指南](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a)。
