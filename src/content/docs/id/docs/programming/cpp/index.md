---
title: Controller C++
description: Kompilasi controller yang ditulis dalam C atau C++ dan jalankan di Erebus.
---

Berbeda dengan Python, controller C dan C++ harus dikompilasi sebelum dijalankan. Setiap contoh di dokumentasi ini punya tab C/C++ dengan program yang sama seperti versi Python-nya, dan semuanya sudah dikompilasi dan dijalankan di robot pemula.

:::tip
Di C++, ambil perangkat dengan fungsi khusus untuk tiap jenis perangkat, seperti `robot->getMotor("left wheel motor")` atau `robot->getCamera("camera")`, alih-alih `getDevice()`. Sertakan header yang sesuai, seperti `<webots/Motor.hpp>`.
:::

## Program pertama {#a-first-program}

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

## Mengompilasi {#compiling}
Cara termudah di sistem apa pun adalah editor Webots: gunakan **Wizards > New Robot Controller** untuk membuat controller C++ beserta `Makefile`-nya, lalu tekan tombol **Build**. Lihat [panduan Webots](https://cyberbotics.com/doc/guide/using-cpp?version=R2025a).

Kamu juga bisa mengompilasi dari terminal. Perintah ini sudah diuji di macOS:

```bash
WEBOTS=/Applications/Webots.app/Contents
clang++ -std=c++17 -I$WEBOTS/include/controller/cpp -L$WEBOTS/lib/controller \
  -lController -lCppController -Wl,-rpath,$WEBOTS/lib/controller \
  my_controller.cpp -o my_controller
```

Di Linux, opsi yang sama bisa dipakai dengan `WEBOTS=/usr/local/webots`. Jika kamu menggunakan OpenCV, tambahkan juga opsinya. Dengan OpenCV 4 terinstal, misalnya dengan Homebrew di macOS, `$(pkg-config --cflags --libs opencv4)` memberikan opsi tersebut. Contoh-contohnya sudah diuji dengan OpenCV 4.13.

## Menjalankan {#running}

- **Di Windows,** muat berkas `.exe` di bawah **Controller** pada **Robot setup** di jendela kontrol.
- **Di macOS dan Linux,** program hasil kompilasi tidak punya ekstensi berkas, dan **Load file** tidak bisa memilihnya. Sebagai gantinya, jalankan dengan [Remote Controller](/docs/competition/remote-controller/), seperti yang akan kamu lakukan di kompetisi.
