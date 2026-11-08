---
title: C++ denetleyicileri
description: C ya da C++ ile yazılmış denetleyicileri derle ve Erebus'ta çalıştır.
---

Python'dan farklı olarak C ve C++ denetleyicileri çalıştırılmadan önce derlenmelidir. Bu belgelerdeki her örneğin, Python sürümüyle aynı programı içeren bir C/C++ sekmesi vardır ve hepsi başlangıç robotunda derlenip çalıştırıldı.

:::tip
C++'ta cihazları `getDevice()` yerine `robot->getMotor("left wheel motor")` ya da `robot->getCamera("camera")` gibi türe özgü fonksiyonlarla al. `<webots/Motor.hpp>` gibi uygun başlık dosyasını dahil et.
:::

## İlk program {#a-first-program}

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

## Derleme {#compiling}
Her sistemde en kolay yol Webots düzenleyicisidir: `Makefile` dosyasıyla birlikte bir C++ denetleyicisi oluşturmak için **Wizards > New Robot Controller** seçeneğini kullan ve **Build** düğmesine bas. [Webots kılavuzuna](https://cyberbotics.com/doc/guide/using-cpp?version=R2023b) bak.

Terminalden de derleyebilirsin. Bu komut macOS'ta test edildi:

```bash
WEBOTS=/Applications/Webots.app/Contents
clang++ -std=c++17 -I$WEBOTS/include/controller/cpp -L$WEBOTS/lib/controller \
  -lController -lCppController -Wl,-rpath,$WEBOTS/lib/controller \
  my_controller.cpp -o my_controller
```

Linux'ta aynı seçenekler `WEBOTS=/usr/local/webots` ile çalışır. OpenCV kullanıyorsan onun seçeneklerini de ekle. OpenCV 4 kuruluysa (örneğin macOS'ta Homebrew ile) `$(pkg-config --cflags --libs opencv4)` bunları verir. Örnekler OpenCV 4.13 ile test edildi.

## Çalıştırma {#running}

- **Windows'ta,** `.exe` dosyasını kontrol penceresinin soldaki LOAD düğmesiyle yükle.
- **macOS ve Linux'ta,** derlenmiş programların dosya uzantısı yoktur ve LOAD düğmesi onları seçemez. Bunun yerine, bir yarışmada yapacağın gibi, onları [Remote Controller](/docs/competition/remote-controller/) ile çalıştır.
