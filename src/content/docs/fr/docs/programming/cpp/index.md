---
title: Contrôleurs C++
description: Compilez des contrôleurs écrits en C ou C++ et exécutez-les dans Erebus.
---

Contrairement à Python, les contrôleurs C et C++ doivent être compilés avant d’être exécutés. Chaque exemple de cette documentation possède un onglet C/C++ avec le même programme que la version Python, et tous ont été compilés et exécutés sur le robot de départ.

:::tip
En C++, obtenez les composants avec des fonctions typées, comme `robot->getMotor("left wheel motor")` ou `robot->getCamera("camera")`, plutôt qu’avec `getDevice()`. Incluez l’en-tête correspondant, comme `<webots/Motor.hpp>`.
:::

## Un premier programme {#a-first-program}

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

## Compiler {#compiling}
Sur tous les systèmes, le plus simple est d’utiliser l’éditeur de Webots : utilisez **Wizards > New Robot Controller** pour créer un contrôleur C++ avec son `Makefile`, puis appuyez sur le bouton **Build**. Consultez le [guide Webots](https://cyberbotics.com/doc/guide/using-cpp?version=R2025a).

Vous pouvez aussi compiler depuis un terminal. Cette commande a été testée sur macOS :

```bash
WEBOTS=/Applications/Webots.app/Contents
clang++ -std=c++17 -I$WEBOTS/include/controller/cpp -L$WEBOTS/lib/controller \
  -lController -lCppController -Wl,-rpath,$WEBOTS/lib/controller \
  my_controller.cpp -o my_controller
```

Sous Linux, les mêmes options fonctionnent avec `WEBOTS=/usr/local/webots`. Si vous utilisez OpenCV, ajoutez aussi ses options. Avec OpenCV 4 installé, par exemple via Homebrew sur macOS, `$(pkg-config --cflags --libs opencv4)` les fournit. Les exemples ont été testés avec OpenCV 4.13.

## Exécuter {#running}

- **Sous Windows,** chargez le fichier `.exe` sous **Controller** dans **Robot setup** de la fenêtre de contrôle.
- **Sous macOS et Linux,** les programmes compilés n’ont pas d’extension de fichier, et **Load file** ne peut pas les sélectionner. Exécutez-les plutôt avec le [Remote Controller](/docs/competition/remote-controller/), comme vous le feriez en compétition.
