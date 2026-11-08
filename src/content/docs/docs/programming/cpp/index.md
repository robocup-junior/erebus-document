---
title: C++ controllers
description: Build controllers written in C or C++ and run them in Erebus.
---

Unlike Python, C and C++ controllers must be compiled before running them. Every example in this documentation has a C/C++ tab with the same program as the Python one, and all of them were compiled and run on the starter robot.

:::tip
In C++, get devices with typed functions, like `robot->getMotor("left wheel motor")` or `robot->getCamera("camera")`, instead of `getDevice()`. Include the matching header, like `<webots/Motor.hpp>`.
:::

## A first program

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

## Compiling
The easiest way on any system is the Webots editor: use **Wizards > New Robot Controller** to create a C++ controller with its `Makefile`, and press the **Build** button. See the [Webots guide](https://cyberbotics.com/doc/guide/using-cpp?version=R2023b).

You can also compile from a terminal. This command was tested on macOS:

```bash
WEBOTS=/Applications/Webots.app/Contents
clang++ -std=c++17 -I$WEBOTS/include/controller/cpp -L$WEBOTS/lib/controller \
  -lController -lCppController -Wl,-rpath,$WEBOTS/lib/controller \
  my_controller.cpp -o my_controller
```

On Linux, the same options work with `WEBOTS=/usr/local/webots`. If you use OpenCV, add its options too. With OpenCV 4 installed, for example with Homebrew on macOS, `$(pkg-config --cflags --libs opencv4)` gives them. The examples were tested with OpenCV 4.13.

## Running

- **On Windows,** load the `.exe` file with the left LOAD button of the control window.
- **On macOS and Linux,** compiled programs have no file extension, and the LOAD button cannot select them. Run them with the [Remote Controller](/docs/competition/remote-controller/) instead, as you would at a competition.
