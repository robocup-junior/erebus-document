---
title: 疑難排解
description: 安裝和執行 Erebus 時常見問題的解決方法。
---

首先，請查看 Webots 主控台。大部分的問題都會在那裡顯示錯誤訊息。

## 安裝 {#installation}

### `No module named 'cv2'` {#no-module-named-cv2}
Webots 使用的 Python 中沒有安裝 OpenCV。請在那個 Python 中安裝[所需的函式庫](/docs/installation/#python-libraries)。如果你安裝了好幾個 Python，下方的 **Python command** 設定會告訴你 Webots 使用的是哪一個。

### `WARNING: Python was not found` {#warning-python-was-not-found}
Webots 不知道 Python 在哪裡。

1. 找出 Python 的位置。在 macOS 和 Linux 上，請在終端機中執行 `which python3`。在 Windows 上，請確認在新的命令提示字元中輸入 `python` 能開啟 Python。如果不行，請重新安裝 Python，並勾選將它加入 PATH 的選項。
2. 開啟 Webots 偏好設定：在 macOS 上是 **Webots > Preferences**，在 Windows 和 Linux 上是 **Tools > Preferences**。

   ![Webots 選單中的 Preferences 項目](../../../docs/troubleshooting/preferences_open.png)

3. 在 **Python command** 欄位中設定路徑。在 Windows 上，通常輸入 `python` 就夠了。

   ![Webots 偏好設定中的 Python command 欄位](../../../docs/troubleshooting/preferences.png)

### 比賽計時器沒有出現 {#the-game-timer-does-not-appear}
第一次啟動時，Erebus 會安裝函式庫，可能需要幾分鐘。如果一直沒有完成，請查看主控台是否有錯誤。如果自動安裝無法運作，請自行安裝[所需的函式庫](/docs/installation/#python-libraries)。

## 執行 Erebus {#running-erebus}

### 控制視窗沒有出現 {#the-control-window-does-not-appear}
控制視窗是由 Webots 開啟的網頁。

1. 如果被你的瀏覽器封鎖了，請在世界開啟時開啟[控制視窗](http://localhost:1234/robot_windows/MainSupervisorWindow/MainSupervisorWindow.html?name=robot)。
2. 否則，請用 **Tools > Scene Tree** 確認已顯示 Scene Tree（場景樹）。
3. 在 Scene Tree 中找到 **DEF MAINSUPERVISOR Robot**，按右鍵並選擇 **Show Robot Window**。

![Scene Tree 中的 Show Robot Window 選項](../../../docs/troubleshooting/showrobot.png)

### Webots 畫面一片空白或全黑 {#the-webots-screen-is-blank-or-black}
請在開啟世界之前，把下載的檔案複製並解壓縮到另一個資料夾。

### 模擬執行得太慢 {#the-simulation-runs-too-slowly}
這可能是因為你的電腦效能不足。降低圖形品質可能會有幫助：

1. 開啟 Webots 偏好設定。
2. 開啟 **OpenGL** 分頁。
3. 更改設定。

![Webots 偏好設定的 OpenGL 分頁](../../../docs/troubleshooting/opengl.png)

這些設定會改變攝影機看到的畫面，而比賽會使用[它自己的設定](/docs/competition/#opengl-settings)，所以也請用那些設定檢查你的程式。

## 你的機器人 {#your-robot}

### `PROTO parameter 'camera_width' has no matching IS field` {#proto-parameter-camera_width-has-no-matching-is-field}
Erebus v26.1 在載入用目前的 Robot Customizer 製作的機器人時，會以紅色顯示這則錯誤。你可以忽略它：機器人可以正常運作，攝影機也是你選擇的解析度。

### 我的程式說找不到某個裝置 {#my-program-says-a-device-was-not-found}
請參閱下方說明。另外，請確認你在開始比賽之前，已經用**右邊的** LOAD 按鈕載入了你的機器人。

## 你的程式 {#your-program}

### `Device "..." was not found` {#device--was-not-found}
你的程式中的裝置名稱與你的機器人不符。入門機器人的名稱請參閱[參考](/docs/reference/parameters/#device-names-of-the-starter-robot)。如果是你自己的機器人，名稱就是你在 [Robot Customizer](/docs/robot/customizer/) 中設定的名稱。請確認你的機器人已經載入。

### 回報牆上的標記時沒有任何反應 {#nothing-happens-when-i-report-a-wall-token}
在控制視窗的 Settings 分頁中開啟 **Enable debugging**，然後查看主控台。最常見的原因是機器人沒有停止至少 1 秒，以及座標沒有換算成公分。請參閱[通訊](/docs/programming/communication/#scoring-wall-tokens)。

### 我的回報都被判定為誤判 {#my-reports-are-misidentifications}
機器人必須距離標記最多半個地塊，並且和標記在牆的同一側，而且每個標記只能得分一次。回報假目標也會被視為誤判。

### 地圖得到 0% 或出現計分錯誤 {#the-map-gets-0-or-a-scoring-error}
你的地圖必須包含起始地塊（`5`），而且只能被評估一次。請參閱[提交地圖](/docs/programming/map-bonus/)。

### 在遠端模式下控制器無法連線 {#the-controller-cannot-connect-in-remote-mode}
請參閱適用於你的作業系統的 [Remote Controller](/docs/competition/remote-controller/) 指南。

## 還是無法解決？ {#still-stuck}
請在 [Discord 伺服器](https://discord.com/invite/6FJxZxk)上提問，或[提出 issue](https://github.com/robocup-junior/erebus/issues)。請附上你的作業系統、Erebus 和 Webots 的版本，以及主控台中的訊息。
