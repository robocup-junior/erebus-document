---
title: Linux (Ubuntu)
description: Linux（Ubuntu 22.04 LTS）的 Remote Controller 設定指南。
---

# 在同一台電腦上執行比賽伺服器和控制器程式
首先，我們來試著在同一台電腦上執行比賽伺服器和控制器程式。這和真正的比賽架構不同，但在本機除錯時會很有幫助。

## 開啟遠端模式 {#toggle-remote-mode}
開啟世界，然後按下控制視窗中的「TOGGLE REMOTE」。按鈕會變成橘色，表示已經啟用。

![已開啟的 TOGGLE REMOTE 按鈕](../../../../../docs/competition/remote-controller/linux/toggle_remote.png)

如果沒有顯示控制視窗，請在 Scene Tree（場景樹）中的「DEF MAINSUPERVISOR Robot」上按右鍵，然後按下「Show Robot Window」。

## 執行你的程式 {#execute-your-program}
開啟終端機並執行以下指令，把 `<Your controller path>` 換成你的控制器程式的路徑。

```bash
export WEBOTS_HOME=/usr/local/webots
"$WEBOTS_HOME/webots-controller" "<Your controller path>"
```

這是假設 Webots 是用 `.deb` 套件安裝在 `/usr/local/webots`。如果你安裝在其他地方，請相應地更改 `WEBOTS_HOME`。

控制器會連接到 Webots，並等待比賽開始。

## 開始比賽 {#start-the-game}
按下控制視窗中的開始按鈕。機器人會出現，你的程式也會開始執行。

## 終止比賽 {#terminate-the-game}
要中斷比賽，請在終端機中按下 Ctrl+C。

模擬終止時，Erebus 的比賽管理系統也會同時終止。如果你想再次執行比賽，請重新載入世界。

# 在另一台電腦上執行比賽伺服器
這是正式比賽使用的架構。執行你的控制器的電腦（用戶端）和比賽伺服器（伺服器）必須連接到同一個網路。

1. （伺服器）在伺服器上啟動 Webots，開啟世界，並在控制視窗中開啟遠端模式。
1. （伺服器）查出伺服器的 IP 位址。你可以使用 `ip addr` 指令。
1. （用戶端）執行以下指令，把 `<Your controller path>` 換成你的控制器程式的路徑，並把 `<Server IP address>` 換成上一步查到的 IP 位址。

    ```bash
    export WEBOTS_HOME=/usr/local/webots
    "$WEBOTS_HOME/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. （伺服器）按下開始按鈕開始比賽。

## 疑難排解 {#troubleshooting}
- **控制器無法連線：** 請確認兩台電腦可以互相連通（例如用 `ping`）、伺服器的防火牆允許 TCP 連接埠 1234，以及 Webots 偏好設定（Preferences）的 Network 分頁中允許的 IP 清單是空的或包含用戶端。
- **顯示 `No robot name provided`：** 在等待期間出現這則訊息是正常的。如果它一直顯示，表示遠端模式沒有開啟，請檢查 TOGGLE REMOTE 按鈕。
- **控制器找不到 Python 函式庫：** 程式是用用戶端的 Python 執行的，所以請在用戶端安裝該函式庫。

# 官方文件
如果你想更詳細地了解這個架構，可以參閱[官方指南](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b)。
