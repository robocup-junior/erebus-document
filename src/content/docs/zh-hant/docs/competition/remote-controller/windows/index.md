---
title: Windows
description: 如何在 Windows 上設定 Remote Controller。
---

# 在同一台電腦上執行比賽伺服器和控制器程式
首先，試著在同一台電腦上執行比賽伺服器和你的控制器程式。這和比賽時的架構不同，但對於在本機除錯很有用。

## 開啟遠端模式 {#toggle-remote-mode}
開啟世界，在控制視窗中按 **Robot setup**，然後開啟 **Remote mode**。如果你有自訂機器人，請先在 **Robot JSON** 下載入它。  
![在 Robot setup 中開啟的 Remote mode](../../../../../docs/competition/remote-controller/windows/../mac/toggle_remote.png)

如果沒有顯示控制視窗，請在 Scene Tree（場景樹）中的「DEF MAINSUPERVISOR Robot」上按右鍵，然後選擇「Show Robot Window」。  
![Show Robot Window 選項](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## 執行你的程式 {#execute-your-program}
開啟 PowerShell。通常可以在應用程式清單中找到它。  
![應用程式清單中的 PowerShell](../../../../../docs/competition/remote-controller/windows/powerShell.png)

在 PowerShell 中執行以下指令，把 `<Your controller path>` 換成你的控制器程式的路徑。

`webots-controller.exe <Your controller path>`

如果找不到這個指令，請使用它的完整路徑，預設為 `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe`。

如果你不知道控制器程式的路徑，請把檔案拖放到 PowerShell 視窗中，它的路徑就會自動填入。  
![把檔案拖進 PowerShell 視窗](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

然後按下 Enter 執行指令。控制器會連接到 Webots，並等待比賽開始。

## 開始比賽 {#start-the-game}
在控制視窗中按 **Run match** 開始比賽。  
![控制視窗的 Run match 按鈕](../../../../../docs/competition/remote-controller/windows/../../../getting-started/match-controls.png)

## 終止比賽 {#terminate-the-game}
要停止比賽，請在 PowerShell 中按下 Ctrl+C，停止你的程式。

比賽結束後，按 **Reset** 可以再執行一次。除非開啟了 **Keep on Reset**，否則重設會關閉 Remote mode。

# 在另一台電腦上執行比賽伺服器
這是正式比賽使用的架構。執行你的控制器的電腦（用戶端）和執行比賽的電腦（伺服器）必須連接到同一個網路。

2. （伺服器）在伺服器上啟動 Webots，開啟世界，並在控制視窗的 **Robot setup** 中開啟 **Remote mode**。
2. （伺服器）查出伺服器的 IP 位址。請參閱[在 Windows 中尋找您的 IP 位址](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9)。
3. （用戶端）在 PowerShell 中執行以下指令，把 `<Your controller path>` 換成你的控制器程式的路徑，並把 `<Server IP address>` 換成上一步查到的 IP 位址。  
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. （伺服器）按 **Run match** 開始比賽。

# 疑難排解
如果控制器無法連線，請確認兩台電腦可以互相連通、伺服器的防火牆允許 TCP 連接埠 1234，以及 Webots 偏好設定（Preferences）的 Network 分頁中允許的 IP 清單是空的或包含用戶端。

# 官方說明文件
如需這個架構的更多詳細資訊，請參閱 [Webots 指南](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a)。
