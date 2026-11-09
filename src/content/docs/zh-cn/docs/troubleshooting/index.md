---
title: 故障排除
description: 安装和运行 Erebus 时常见问题的解决方法。
---

首先，请查看 Webots 控制台。大多数问题都会在那里显示错误信息。

## 安装 {#installation}

### `No module named 'cv2'` {#no-module-named-cv2}
Webots 使用的 Python 中没有安装 OpenCV。请在这个 Python 中安装[所需的库](/docs/installation/#python-libraries)。如果你安装了多个 Python，下面提到的 **Python command** 设置会告诉你 Webots 使用的是哪一个。

### `WARNING: Python was not found` {#warning-python-was-not-found}
Webots 不知道 Python 在哪里。

1. 找到 Python。在 macOS 和 Linux 上，在终端中运行 `which python3`。在 Windows 上，检查在新打开的命令提示符中输入 `python` 能否启动 Python。如果不能，请重新安装 Python，并勾选把它添加到 PATH 的选项。
2. 打开 Webots 首选项：在 macOS 上是 **Webots > Preferences**，在 Windows 和 Linux 上是 **Tools > Preferences**。

   ![Webots 菜单中的 Preferences 菜单项](../../../docs/troubleshooting/preferences_open.png)

3. 在 **Python command** 字段中设置路径。在 Windows 上，通常填 `python` 就够了。

   ![Webots 首选项中的 Python command 字段](../../../docs/troubleshooting/preferences.png)

### `ERROR: Skipped PROTO 'custom_robot'` {#error-skipped-proto-custom_robot}
第一次打开世界时，在 Erebus 准备好机器人模型之前会显示这条信息。Erebus 会准备好模型并自动重新加载世界，所以可以忽略它。

### 比赛计时器没有出现 {#the-game-timer-does-not-appear}
第一次启动时，Erebus 需要安装一些库，可能要花几分钟。如果一直没有完成，请查看控制台中的错误。如果自动安装不起作用，请自己安装[所需的库](/docs/installation/#python-libraries)。

## 运行 Erebus {#running-erebus}

### 控制窗口没有出现 {#the-control-window-does-not-appear}
控制窗口是 Webots 打开的一个网页。

1. 如果你关掉了窗口，或者浏览器拦截了它，请用 Webots 的重新加载按钮重新加载世界。Erebus 会再次打开控制窗口。
2. 否则，请通过 **Tools > Scene Tree** 确保 Scene Tree（场景树）处于显示状态。
3. 在 Scene Tree 中找到 **DEF MAINSUPERVISOR Robot**，右键点击它，选择 **Show Robot Window**。

控制窗口有一个专用地址，每次加载世界都会改变。如果你自己在 `localhost:1234` 打开窗口，它会显示 **Read-only**，按钮也不起作用。

### 控制窗口显示“Access log incomplete” {#the-control-window-says-access-log-incomplete}
没有安装 [Wireshark](/docs/installation/#optional-wireshark) 时会出现这个警告。它是给比赛组织者用的：按 **Acknowledge**，然后照常练习。

![Scene Tree 中的 Show Robot Window 选项](../../../docs/troubleshooting/showrobot.png)

### Webots 画面空白或全黑 {#the-webots-screen-is-blank-or-black}
在打开世界之前，先把下载的文件复制并解压到一个单独的文件夹中。

### 仿真运行得太慢 {#the-simulation-runs-too-slowly}
这很可能是由于你的电脑性能不足。降低图形质量可能会有帮助：

1. 打开 Webots 首选项。
2. 打开 **OpenGL** 标签页。
3. 修改设置。

![Webots 首选项中的 OpenGL 标签页](../../../docs/troubleshooting/opengl.png)

这些设置会改变摄像头看到的画面，而比赛使用的是[比赛自己的设置](/docs/competition/#opengl-settings)，所以也请用那些设置检查你的程序。

## 你的机器人 {#your-robot}

### 我的程序说找不到某个设备 {#my-program-says-a-device-was-not-found}
见下文。另外，请检查开始比赛前是否已经在 **Robot setup** 的 **Robot JSON** 下加载了机器人。

## 你的程序 {#your-program}

### `Device "..." was not found` {#device--was-not-found}
程序中的设备名称与你的机器人不一致。入门机器人的设备名称在[参考](/docs/reference/parameters/#device-names-of-the-starter-robot)中。对于你自己的机器人，名称就是你在 [Robot Customizer](/docs/robot/customizer/) 中设置的名字。请检查机器人是否已经加载。

### 报告墙面标识时什么都没有发生 {#nothing-happens-when-i-report-a-wall-token}
在控制窗口的 **Advanced setup** 中打开 **Enable debugging**，然后查看控制台。最常见的原因是：机器人没有停止至少 1 秒、坐标没有换算成厘米，以及机器人或位置离标识超过半个地块（6 cm）。参见[通信](/docs/programming/communication/#scoring-wall-tokens)。

### 我的报告都被判为误判 {#my-reports-are-misidentifications}
机器人必须在距离标识半个地块以内，并且与标识位于墙的同一侧，而且每个标识只能得分一次。报告假标识也算作误判。

### 比赛以“Battery depleted”结束 {#the-game-ends-with-battery-depleted}
电池耗尽了。在那之前，在接触地块上停留 5 秒来更换电池。参见[电池](/docs/programming/battery/)。

### 我的程序收不到比赛信息了 {#my-program-no-longer-receives-the-game-information}
从 Erebus v27 开始，`G` 的回复为 20 字节，最后是电池电量。请更新程序中对长度的检查。参见[比赛信息](/docs/programming/communication/#game-information)。

### 地图得到 0% 或出现计分错误 {#the-map-gets-0-or-a-scoring-error}
你的地图必须包含起始地块（`5`），而且只能被评估一次。请参阅[提交地图](/docs/programming/map-bonus/)。

### 在远程模式下控制器无法连接 {#the-controller-cannot-connect-in-remote-mode}
请参阅你所用操作系统的 [Remote Controller](/docs/competition/remote-controller/) 指南。

## 还是解决不了？ {#still-stuck}
请在 [Discord 服务器](https://discord.com/invite/6FJxZxk)上提问，或者[提交 issue](https://github.com/robocup-junior/erebus/issues)。请附上你的操作系统、Erebus 和 Webots 的版本，以及控制台中的消息。
