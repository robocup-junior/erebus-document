---
title: Controladores em C++
description: Compile controladores escritos em C ou C++ e execute-os no Erebus.
---

Ao contrário do Python, os controladores em C e C++ precisam ser compilados antes de serem executados. Todo exemplo desta documentação tem uma aba C/C++ com o mesmo programa da versão em Python, e todos eles foram compilados e executados no robô inicial.

:::tip
Em C++, obtenha os dispositivos com funções tipadas, como `robot->getMotor("left wheel motor")` ou `robot->getCamera("camera")`, em vez de `getDevice()`. Inclua o cabeçalho correspondente, como `<webots/Motor.hpp>`.
:::

## Um primeiro programa {#a-first-program}

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

## Compilando {#compiling}
O jeito mais fácil, em qualquer sistema, é o editor do Webots: use **Wizards > New Robot Controller** para criar um controlador em C++ com o seu `Makefile` e pressione o botão **Build**. Veja o [guia do Webots](https://cyberbotics.com/doc/guide/using-cpp?version=R2023b).

Você também pode compilar pelo terminal. Este comando foi testado no macOS:

```bash
WEBOTS=/Applications/Webots.app/Contents
clang++ -std=c++17 -I$WEBOTS/include/controller/cpp -L$WEBOTS/lib/controller \
  -lController -lCppController -Wl,-rpath,$WEBOTS/lib/controller \
  my_controller.cpp -o my_controller
```

No Linux, as mesmas opções funcionam com `WEBOTS=/usr/local/webots`. Se você usa o OpenCV, adicione também as opções dele. Com o OpenCV 4 instalado, por exemplo pelo Homebrew no macOS, `$(pkg-config --cflags --libs opencv4)` fornece essas opções. Os exemplos foram testados com o OpenCV 4.13.

## Executando {#running}

- **No Windows,** carregue o arquivo `.exe` com o botão LOAD da esquerda na janela de controle.
- **No macOS e no Linux,** os programas compilados não têm extensão de arquivo, e o botão LOAD não consegue selecioná-los. Execute-os com o [Remote Controller](/docs/competition/remote-controller/), como você faria em uma competição.
