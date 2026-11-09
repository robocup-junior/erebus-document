---
title: C++ コントローラー
description: C や C++ で書いたコントローラーをビルドし、Erebus で実行します。
---

Python と違い、C や C++ のコントローラーは実行する前にコンパイルする必要があります。このドキュメントのすべての例には、Python 版と同じプログラムの C/C++ タブがあり、どれもスターターロボットでコンパイルして実行を確認しています。

:::tip
C++ では、`getDevice()` の代わりに、`robot->getMotor("left wheel motor")` や `robot->getCamera("camera")` のような型ごとの関数でデバイスを取得します。`<webots/Motor.hpp>` のように、対応するヘッダーをインクルードしてください。
:::

## 最初のプログラム {#a-first-program}

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

## コンパイル {#compiling}
どのシステムでもいちばん簡単なのは、Webots のエディターを使う方法です。**Wizards > New Robot Controller** で `Makefile` 付きの C++ コントローラーを作成し、**Build** ボタンを押します。[Webots のガイド](https://cyberbotics.com/doc/guide/using-cpp?version=R2025a)を参照してください。

ターミナルからコンパイルすることもできます。次のコマンドは macOS でテストしました。

```bash
WEBOTS=/Applications/Webots.app/Contents
clang++ -std=c++17 -I$WEBOTS/include/controller/cpp -L$WEBOTS/lib/controller \
  -lController -lCppController -Wl,-rpath,$WEBOTS/lib/controller \
  my_controller.cpp -o my_controller
```

Linux では、`WEBOTS=/usr/local/webots` にすれば同じオプションが使えます。OpenCV を使う場合は、そのオプションも追加してください。たとえば macOS の Homebrew などで OpenCV 4 をインストールしていれば、`$(pkg-config --cflags --libs opencv4)` でオプションが得られます。例は OpenCV 4.13 でテストしています。

## 実行 {#running}

- **Windows では、** コントロールウィンドウの **Robot setup** にある **Controller** で `.exe` ファイルを読み込みます。
- **macOS と Linux では、** コンパイルしたプログラムにファイル拡張子がないため、**Load file** では選択できません。代わりに、競技のときと同じように [Remote Controller](/docs/competition/remote-controller/) で実行してください。
