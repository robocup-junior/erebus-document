---
title: macOS
description: 如何在 macOS 上設定 Remote Controller。
---

# 在同一台電腦上執行比賽伺服器和控制器程式
首先，試著在同一台電腦上執行比賽伺服器和你的控制器程式。這和比賽時的架構不同，但對於在本機除錯很有用。

## 開啟遠端模式 {#toggle-remote-mode}
開啟世界，在控制視窗中按 **Robot setup**，然後開啟 **Remote mode**。如果你有自訂機器人，請先在 **Robot JSON** 下載入它。

![在 Robot setup 中開啟的 Remote mode](../../../../../docs/competition/remote-controller/mac/toggle_remote.png)

如果沒有顯示控制視窗，請在 Scene Tree（場景樹）中的「DEF MAINSUPERVISOR Robot」上按右鍵，然後選擇「Show Robot Window」。

## 執行你的程式 {#execute-your-program}
開啟終端機並執行以下指令，把 `<Your controller path>` 換成你的控制器程式的路徑。

```bash
export WEBOTS_HOME=/Applications/Webots.app
"$WEBOTS_HOME/Contents/MacOS/webots-controller" "<Your controller path>"
```

如果 Webots 安裝在其他位置或使用其他名稱，請相應地更改 `WEBOTS_HOME`，例如 `"/Applications/Webots R2025a.app"`。

控制器會連接到 Webots，並等待比賽開始。

## 開始比賽 {#start-the-game}
在控制視窗中按 **Run match**。機器人出現，你的程式開始執行。

## 終止比賽 {#terminate-the-game}
要停止比賽，請在終端機中按下 Ctrl+C。

比賽結束後，按 **Reset** 可以再執行一次。除非開啟了 **Keep on Reset**，否則重設會關閉 Remote mode。

# 在另一台電腦上執行比賽伺服器
這是正式比賽使用的架構。執行你的控制器的電腦（用戶端）和執行比賽的電腦（伺服器）必須連接到同一個網路。

1. （伺服器）在伺服器上啟動 Webots，開啟世界，並在控制視窗的 **Robot setup** 中開啟 **Remote mode**。
1. （伺服器）在「系統設定」>「網路」中查出伺服器的 IP 位址。
1. （用戶端）執行以下指令，把 `<Your controller path>` 換成你的控制器程式的路徑，並把 `<Server IP address>` 換成上一步查到的 IP 位址。

    ```bash
    export WEBOTS_HOME=/Applications/Webots.app
    "$WEBOTS_HOME/Contents/MacOS/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. （伺服器）按 **Run match** 開始比賽。

## 疑難排解 {#troubleshooting}
- **控制器無法連線：** 請確認兩台電腦可以互相連通（例如用 `ping`）、伺服器的防火牆允許 TCP 連接埠 1234，以及 Webots 偏好設定（Preferences）的 Network 分頁中允許的 IP 清單是空的或包含用戶端。
- **控制器在等待，但機器人不動：** 檢查 **Remote mode** 是否已開啟，然後按 **Run match**。
- **控制器找不到 Python 函式庫：** 程式是用用戶端上安裝的 Python 執行的，所以請在用戶端安裝該函式庫。

# 官方說明文件
如需這個架構的更多詳細資訊，請參閱 [Webots 指南](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a)。
