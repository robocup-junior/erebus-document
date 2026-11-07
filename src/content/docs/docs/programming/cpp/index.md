---
title: C++ controllers
description: Build controllers written in C or C++ and run them in Erebus.
---

Unlike Python, C and C++ controllers must be compiled before running them. The examples in this documentation have a C/C++ tab with the same code as the Python one.

:::tip
In C++, get devices with typed functions, like `robot->getMotor("wheel1 motor")` or `robot->getCamera("camera_centre")`, instead of `getDevice()`. Include the matching header, like `<webots/Motor.hpp>`.
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

  Motor *left = robot->getMotor("wheel1 motor");
  Motor *right = robot->getMotor("wheel2 motor");
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

On Linux, the same options work with `WEBOTS=/usr/local/webots`. If you use OpenCV, add its compiler options too.

## Running

- **On Windows,** load the `.exe` file with the left LOAD button of the control window.
- **On macOS and Linux,** compiled programs have no file extension, and the LOAD button cannot select them. Run them with the [Remote Controller](/docs/competition/remote-controller/) instead, as you would at a competition.
