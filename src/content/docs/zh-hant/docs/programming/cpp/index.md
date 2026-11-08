---
title: C++ 控制器
description: 建置用 C 或 C++ 撰寫的控制器，並在 Erebus 中執行它們。
---

和 Python 不同，C 和 C++ 控制器必須先編譯才能執行。本文件中的每個範例都有一個 C/C++ 分頁，裡面的程式與 Python 版本相同，而且全部都已在入門機器人上編譯並執行過。

:::tip
在 C++ 中，請使用有型別的函式取得裝置，例如 `robot->getMotor("left wheel motor")` 或 `robot->getCamera("camera")`，而不是 `getDevice()`。並引入對應的標頭檔，例如 `<webots/Motor.hpp>`。
:::

## 第一個程式 {#a-first-program}

```cpp
#include <cmath>
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

using namespace webots;

int main() {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();

  Motor *left = robot->getMotor("left wheel motor");
  Motor *right = robot->getMotor("right wheel motor");
  left->setPosition(INFINITY);
  right->setPosition(INFINITY);
  left->setVelocity(3.0);
  right->setVelocity(3.0);

  while (robot->step(timeStep) != -1) {
  }

  delete robot;
  return 0;
}
```

## 編譯 {#compiling}
在任何系統上最簡單的方式是使用 Webots 編輯器：用 **Wizards > New Robot Controller** 建立一個附有 `Makefile` 的 C++ 控制器，然後按下 **Build** 按鈕。請參閱 [Webots 指南](https://cyberbotics.com/doc/guide/using-cpp?version=R2023b)。

你也可以從終端機編譯。這個指令已在 macOS 上測試過：

```bash
WEBOTS=/Applications/Webots.app/Contents
clang++ -std=c++17 -I$WEBOTS/include/controller/cpp -L$WEBOTS/lib/controller \
  -lController -lCppController -Wl,-rpath,$WEBOTS/lib/controller \
  my_controller.cpp -o my_controller
```

在 Linux 上，同樣的選項搭配 `WEBOTS=/usr/local/webots` 即可使用。如果你使用 OpenCV，也要加上它的選項。安裝 OpenCV 4 之後（例如在 macOS 上用 Homebrew 安裝），可以用 `$(pkg-config --cflags --libs opencv4)` 取得這些選項。範例已用 OpenCV 4.13 測試過。

## 執行 {#running}

- **在 Windows 上，** 用控制視窗左邊的 LOAD 按鈕載入 `.exe` 檔案。
- **在 macOS 和 Linux 上，** 編譯後的程式沒有副檔名，無法用 LOAD 按鈕選取。請改用 [Remote Controller](/docs/competition/remote-controller/) 執行它們，就像在比賽中一樣。
