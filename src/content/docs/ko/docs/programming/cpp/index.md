---
title: C++ 컨트롤러
description: C 또는 C++로 작성한 컨트롤러를 빌드하고 Erebus에서 실행해요.
---

Python과 달리 C와 C++ 컨트롤러는 실행하기 전에 컴파일해야 해요. 이 문서의 모든 예제에는 Python과 같은 프로그램이 담긴 C/C++ 탭이 있고, 모두 스타터 로봇에서 컴파일하고 실행해 봤어요.

:::tip
C++에서는 `getDevice()` 대신 `robot->getMotor("left wheel motor")`나 `robot->getCamera("camera")`처럼 타입이 정해진 함수로 장치를 가져오세요. `<webots/Motor.hpp>`처럼 맞는 헤더도 포함하세요.
:::

## 첫 번째 프로그램 {#a-first-program}

```cpp
#include <cmath>
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

using namespace webots;

int main() {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();

  Motor *left = robot->getMotor("left wheel motor");
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

## 컴파일하기 {#compiling}
어떤 시스템에서든 가장 쉬운 방법은 Webots 에디터예요. **Wizards > New Robot Controller**로 `Makefile`이 포함된 C++ 컨트롤러를 만들고, **Build** 버튼을 누르세요. [Webots 가이드](https://cyberbotics.com/doc/guide/using-cpp?version=R2023b)를 참고하세요.

터미널에서 컴파일할 수도 있어요. 이 명령은 macOS에서 테스트했어요.

```bash
WEBOTS=/Applications/Webots.app/Contents
clang++ -std=c++17 -I$WEBOTS/include/controller/cpp -L$WEBOTS/lib/controller \
  -lController -lCppController -Wl,-rpath,$WEBOTS/lib/controller \
  my_controller.cpp -o my_controller
```

Linux에서는 `WEBOTS=/usr/local/webots`로 같은 옵션을 사용할 수 있어요. OpenCV를 사용한다면 OpenCV의 옵션도 추가하세요. 예를 들어 macOS에서 Homebrew로 OpenCV 4를 설치했다면 `$(pkg-config --cflags --libs opencv4)`로 옵션을 얻을 수 있어요. 예제는 OpenCV 4.13으로 테스트했어요.

## 실행하기 {#running}

- **Windows에서는** 제어 창의 왼쪽 LOAD 버튼으로 `.exe` 파일을 불러오세요.
- **macOS와 Linux에서는** 컴파일된 프로그램에 파일 확장자가 없어서 LOAD 버튼으로 선택할 수 없어요. 대신 대회에서처럼 [Remote Controller](/docs/competition/remote-controller/)로 실행하세요.
