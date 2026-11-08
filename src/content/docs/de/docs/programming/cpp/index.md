---
title: C++-Controller
description: Kompiliere Controller, die in C oder C++ geschrieben sind, und führe sie in Erebus aus.
---

Anders als bei Python müssen Controller in C und C++ kompiliert werden, bevor du sie ausführen kannst. Jedes Beispiel in dieser Dokumentation hat einen C/C++-Tab mit demselben Programm wie in Python, und alle wurden auf dem Starter-Roboter kompiliert und ausgeführt.

:::tip
Hol Geräte in C++ mit typisierten Funktionen wie `robot->getMotor("left wheel motor")` oder `robot->getCamera("camera")` statt mit `getDevice()`. Binde den passenden Header ein, zum Beispiel `<webots/Motor.hpp>`.
:::

## Ein erstes Programm {#a-first-program}

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

## Kompilieren {#compiling}
Am einfachsten geht es auf jedem System mit dem Webots-Editor: Erstelle über **Wizards > New Robot Controller** einen C++-Controller mit seinem `Makefile` und drücke den Button **Build**. Siehe die [Webots-Anleitung](https://cyberbotics.com/doc/guide/using-cpp?version=R2023b).

Du kannst auch im Terminal kompilieren. Dieser Befehl wurde unter macOS getestet:

```bash
WEBOTS=/Applications/Webots.app/Contents
clang++ -std=c++17 -I$WEBOTS/include/controller/cpp -L$WEBOTS/lib/controller \
  -lController -lCppController -Wl,-rpath,$WEBOTS/lib/controller \
  my_controller.cpp -o my_controller
```

Unter Linux funktionieren dieselben Optionen mit `WEBOTS=/usr/local/webots`. Wenn du OpenCV verwendest, füge auch dessen Optionen hinzu. Ist OpenCV 4 installiert, zum Beispiel mit Homebrew unter macOS, liefert `$(pkg-config --cflags --libs opencv4)` sie. Die Beispiele wurden mit OpenCV 4.13 getestet.

## Ausführen {#running}

- **Unter Windows** lädst du die `.exe`-Datei mit dem linken LOAD-Button des Steuerfensters.
- **Unter macOS und Linux** haben kompilierte Programme keine Dateiendung, und der LOAD-Button kann sie nicht auswählen. Führe sie stattdessen mit dem [Remote Controller](/docs/competition/remote-controller/) aus, so wie bei einem Wettbewerb.
