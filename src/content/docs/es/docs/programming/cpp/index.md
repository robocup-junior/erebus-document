---
title: Controladores en C++
description: Compila controladores escritos en C o C++ y ejecútalos en Erebus.
---

A diferencia de Python, los controladores en C y C++ deben compilarse antes de ejecutarlos. Cada ejemplo de esta documentación tiene una pestaña C/C++ con el mismo programa que el de Python, y todos se compilaron y ejecutaron en el robot inicial.

:::tip
En C++, obtén los dispositivos con funciones tipadas, como `robot->getMotor("left wheel motor")` o `robot->getCamera("camera")`, en lugar de `getDevice()`. Incluye la cabecera correspondiente, como `<webots/Motor.hpp>`.
:::

## Un primer programa {#a-first-program}

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

## Compilar {#compiling}
La forma más sencilla en cualquier sistema es el editor de Webots: usa **Wizards > New Robot Controller** para crear un controlador en C++ con su `Makefile`, y pulsa el botón **Build**. Consulta la [guía de Webots](https://cyberbotics.com/doc/guide/using-cpp?version=R2025a).

También puedes compilar desde una terminal. Este comando se probó en macOS:

```bash
WEBOTS=/Applications/Webots.app/Contents
clang++ -std=c++17 -I$WEBOTS/include/controller/cpp -L$WEBOTS/lib/controller \
  -lController -lCppController -Wl,-rpath,$WEBOTS/lib/controller \
  my_controller.cpp -o my_controller
```

En Linux, las mismas opciones funcionan con `WEBOTS=/usr/local/webots`. Si usas OpenCV, añade también sus opciones. Con OpenCV 4 instalado, por ejemplo con Homebrew en macOS, `$(pkg-config --cflags --libs opencv4)` te las da. Los ejemplos se probaron con OpenCV 4.13.

## Ejecutar {#running}

- **En Windows,** carga el archivo `.exe` en **Controller**, dentro de **Robot setup** de la ventana de control.
- **En macOS y Linux,** los programas compilados no tienen extensión de archivo, y **Load file** no puede seleccionarlos. Ejecútalos en su lugar con el [Remote Controller](/docs/competition/remote-controller/), como harías en una competición.
