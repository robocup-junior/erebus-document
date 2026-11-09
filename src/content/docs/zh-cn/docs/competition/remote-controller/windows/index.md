---
title: Windows
description: 如何在 Windows 上设置 Remote Controller。
---

# 在同一台电脑上运行比赛服务器和控制器程序
首先，试着在同一台电脑上运行比赛服务器和你的控制器程序。这和比赛时的设置不同，但很适合在本地调试。

## 开启远程模式 {#toggle-remote-mode}
打开世界，在控制窗口中按 **Robot setup**，然后打开 **Remote mode**。如果你有自定义机器人，请先在 **Robot JSON** 下加载它。  
![在 Robot setup 中打开的 Remote mode](../../../../../docs/competition/remote-controller/windows/../mac/toggle_remote.png)

如果控制窗口没有显示，请在 Scene Tree（场景树）中右键点击“DEF MAINSUPERVISOR Robot”，然后选择“Show Robot Window”。  
![Show Robot Window 选项](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## 运行你的程序 {#execute-your-program}
打开 PowerShell。通常可以在应用程序列表中找到它。  
![应用程序列表中的 PowerShell](../../../../../docs/competition/remote-controller/windows/powerShell.png)

在 PowerShell 中运行下面的命令，把 `<Your controller path>` 替换为你的控制器程序的路径。

`webots-controller.exe <Your controller path>`

如果找不到这个命令，请使用它的完整路径，默认是 `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe`。

如果你不知道控制器程序的路径，可以把这个文件拖放到 PowerShell 窗口中，它的路径会自动填入。  
![把文件拖入 PowerShell 窗口](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

然后按 Enter 键运行命令。控制器会连接到 Webots，并等待比赛开始。

## 开始比赛 {#start-the-game}
在控制窗口中按 **Run match** 开始比赛。  
![控制窗口的 Run match 按钮](../../../../../docs/competition/remote-controller/windows/../../../getting-started/match-controls.png)

## 结束比赛 {#terminate-the-game}
要停止比赛，请在 PowerShell 中按 Ctrl+C，停止你的程序。

比赛结束后，按 **Reset** 可以再运行一次。除非打开了 **Keep on Reset**，否则重置会关闭 Remote mode。

# 在另一台电脑上运行比赛服务器
这是正式比赛中使用的设置。运行你的控制器的电脑（客户端）和运行比赛的电脑（服务器）必须连接到同一个网络。

2. （服务器）在服务器上启动 Webots，打开世界，并在控制窗口的 **Robot setup** 中打开 **Remote mode**。
2. （服务器）查出服务器的 IP 地址。请参阅[在 Windows 中查找 IP 地址](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9)。
3. （客户端）在 PowerShell 中运行下面的命令，把 `<Your controller path>` 替换为你的控制器程序的路径，把 `<Server IP address>` 替换为上一步查到的 IP 地址。   
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. （服务器）按 **Run match** 开始比赛。

# 故障排除
如果控制器无法连接，请检查两台电脑能否互相访问，服务器的防火墙是否允许 TCP 端口 1234，以及 Webots 首选项（Preferences）的 Network 标签页中的允许 IP 列表是否为空或包含客户端。

# 官方文档
有关这套设置的更多细节，请参阅 [Webots 指南](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a)。
