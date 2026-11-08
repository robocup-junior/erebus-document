---
title: Windows
description: Windows 的 Remote Controller 設定指南。
---

# 在同一台電腦上執行比賽伺服器和控制器程式
首先，我們來試著在同一台電腦上執行比賽伺服器和控制器程式。這和真正的比賽架構不同，但在本機除錯時會很有幫助。

## 開啟遠端模式 {#toggle-remote-mode}
在 Robot Window（機器人視窗）中按下「TOGGLE REMOTE」，啟用遠端控制器架構。按鈕會變成橘色，表示已經啟用。  
![TOGGLE REMOTE 按鈕](../../../../../docs/competition/remote-controller/windows/toggleRemote.png)

如果沒有顯示 Robot Window，請在 Scene Tree（場景樹）中的「DEF MAINSUPERVISOR Robot」上按右鍵，然後按下「Show Robot Window」。  
![Show Robot Window 選項](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## 執行你的程式 {#execute-your-program}
開啟 PowerShell。通常可以在應用程式清單中找到它。  
![應用程式清單中的 PowerShell](../../../../../docs/competition/remote-controller/windows/powerShell.png)

在 PowerShell 中執行以下指令，把 `<Your controller path>` 換成你的控制器程式的路徑。

`webots-controller.exe <Your controller path>`

如果找不到這個指令，請使用完整路徑，預設為 `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe`。

如果你不知道控制器程式的路徑，可以把檔案拖放到 PowerShell 視窗中，路徑就會自動填入。  
![把檔案拖進 PowerShell 視窗](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

輸入指令後，按下 Enter 執行。

## 開始比賽 {#start-the-game}
按下 Robot Window 中的開始按鈕，開始模擬。  
![控制視窗的開始按鈕](../../../../../docs/competition/remote-controller/windows/run.png)

## 終止比賽 {#terminate-the-game}
要中斷比賽的執行，請按下 Ctrl+C，中斷在 PowerShell 中執行的程式。

模擬終止時，Erebus 的比賽管理系統也會同時終止。如果你想再次執行比賽，請重新載入世界。  
![Webots 的重新載入按鈕](../../../../../docs/competition/remote-controller/windows/reload.png)

# 在另一台電腦上執行比賽伺服器
這是正式比賽使用的架構。
執行你的控制器的電腦（用戶端）和比賽伺服器（伺服器）必須連接到同一個網路。

1. （伺服器）在伺服器電腦上啟動 Webots，開啟世界，並從 Robot Window 開啟遠端模式。
2. （伺服器）查出那台電腦的 IP 位址。你可以參考[這篇文章](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9)。
3. （用戶端）在 PowerShell 中執行以下指令，把 `<Your controller path>` 換成你的控制器程式的路徑，並把 `<Server IP address>` 換成上一步查到的 IP 位址。   
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. （伺服器）按下開始按鈕開始比賽。

# 疑難排解
如果控制器無法連線，請確認兩台電腦可以互相連通、伺服器的防火牆允許 TCP 連接埠 1234，以及 Webots 偏好設定（Preferences）的 Network 分頁中允許的 IP 清單是空的或包含用戶端。

# 官方文件
如果你想更詳細地了解這個架構，可以參閱[官方指南](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b)。
