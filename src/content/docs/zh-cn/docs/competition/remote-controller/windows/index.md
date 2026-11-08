---
title: Windows
description: Windows 的 Remote Controller 设置指南。
---

# 在同一台电脑上运行比赛服务器和控制器程序
首先，我们来试试在同一台电脑上运行比赛服务器和控制器程序。这和真实比赛的设置不同，但在本地调试时会很有帮助。

## 开启远程模式 {#toggle-remote-mode}
在机器人窗口（Robot Window）中按下 "TOGGLE REMOTE"，启用远程控制器设置。按钮会变成橙色，表示已经启用。  
![TOGGLE REMOTE 按钮](../../../../../docs/competition/remote-controller/windows/toggleRemote.png)

如果机器人窗口没有显示，请在 Scene Tree（场景树）中右键点击 "DEF MAINSUPERVISOR Robot"，然后选择 "Show Robot Window"。  
![Show Robot Window 选项](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## 运行你的程序 {#execute-your-program}
打开 PowerShell。通常可以在应用程序列表中找到它。  
![应用程序列表中的 PowerShell](../../../../../docs/competition/remote-controller/windows/powerShell.png)

在 PowerShell 中执行下面的命令，把 `<Your controller path>` 替换为你的控制器程序的路径。

`webots-controller.exe <Your controller path>`

如果找不到这个命令，请使用完整路径，默认是 `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe`。

如果你不知道控制器程序的路径，可以把这个文件拖放到 PowerShell 窗口中，路径会自动填入。  
![把文件拖入 PowerShell 窗口](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

输入命令后，按回车键执行。

## 开始比赛 {#start-the-game}
在机器人窗口中按下开始按钮，开始仿真。  
![控制窗口的开始按钮](../../../../../docs/competition/remote-controller/windows/run.png)

## 结束比赛 {#terminate-the-game}
要中断比赛，请在 PowerShell 中按 Ctrl+C，中断正在运行的程序。

仿真结束时，Erebus 的比赛管理系统也会同时结束。如果你想再运行一次比赛，请重新加载世界。  
![Webots 的重新加载按钮](../../../../../docs/competition/remote-controller/windows/reload.png)

# 在另一台电脑上运行比赛服务器
这是正式比赛使用的设置。
运行你的控制器的电脑（客户端）和比赛服务器（服务器）必须连接到同一个网络。

1. （服务器）在服务器电脑上启动 Webots，打开世界，并在机器人窗口中开启远程模式。
2. （服务器）查出这台电脑的 IP 地址。你可以参考[这篇文章](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9)。
3. （客户端）在 PowerShell 中执行下面的命令，把 `<Your controller path>` 替换为你的控制器程序的路径，把 `<Server IP address>` 替换为上一步查到的 IP 地址。   
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. （服务器）按下开始按钮开始比赛。

# 故障排除
如果控制器无法连接，请检查两台电脑能否互相访问，服务器的防火墙是否允许 TCP 端口 1234，以及 Webots 首选项（Preferences）的 Network 标签页中的允许 IP 列表是否为空或包含客户端。

# 官方文档
如果你想更详细地了解这套设置，可以查看[官方指南](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b)。
