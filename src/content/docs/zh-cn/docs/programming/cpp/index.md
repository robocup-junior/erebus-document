---
title: C++ 控制器
description: 编译用 C 或 C++ 编写的控制器，并在 Erebus 中运行它们。
---

与 Python 不同，C 和 C++ 控制器在运行之前必须先编译。本文档中的每个示例都有一个 C/C++ 标签页，其中的程序与 Python 版本相同，而且所有示例都已在入门机器人上编译并运行过。

:::tip
在 C++ 中，请使用带类型的函数来获取设备，例如 `robot->getMotor("left wheel motor")` 或 `robot->getCamera("camera")`，而不是 `getDevice()`。还要包含对应的头文件，例如 `<webots/Motor.hpp>`。
:::

## 第一个程序 {#a-first-program}

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

## 编译 {#compiling}
在任何系统上，最简单的方法都是使用 Webots 编辑器：用 **Wizards > New Robot Controller** 创建一个带有 `Makefile` 的 C++ 控制器，然后按下 **Build** 按钮。请参阅 [Webots 指南](https://cyberbotics.com/doc/guide/using-cpp?version=R2023b)。

你也可以在终端中编译。下面的命令已在 macOS 上测试过：

```bash
WEBOTS=/Applications/Webots.app/Contents
clang++ -std=c++17 -I$WEBOTS/include/controller/cpp -L$WEBOTS/lib/controller \
  -lController -lCppController -Wl,-rpath,$WEBOTS/lib/controller \
  my_controller.cpp -o my_controller
```

在 Linux 上，使用 `WEBOTS=/usr/local/webots` 时同样的选项也能用。如果你使用 OpenCV，还要加上它的选项。安装了 OpenCV 4 之后（例如在 macOS 上用 Homebrew 安装），`$(pkg-config --cflags --libs opencv4)` 会给出这些选项。示例已在 OpenCV 4.13 上测试过。

## 运行 {#running}

- **在 Windows 上**，用控制窗口左侧的 LOAD 按钮加载 `.exe` 文件。
- **在 macOS 和 Linux 上**，编译后的程序没有文件扩展名，LOAD 按钮无法选择它们。请改用 [Remote Controller](/docs/competition/remote-controller/) 来运行，就像在比赛中一样。
