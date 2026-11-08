---
title: คอนโทรลเลอร์ C++
description: บิลด์คอนโทรลเลอร์ที่เขียนด้วย C หรือ C++ แล้วรันใน Erebus
---

คอนโทรลเลอร์ C และ C++ ต่างจาก Python ตรงที่ต้องคอมไพล์ก่อนรัน ตัวอย่างทุกอันในเอกสารนี้มีแท็บ C/C++ ซึ่งเป็นโปรแกรมเดียวกับเวอร์ชัน Python และทั้งหมดได้รับการคอมไพล์และรันบนหุ่นยนต์เริ่มต้นแล้ว

:::tip
ใน C++ ให้รับอุปกรณ์ด้วยฟังก์ชันที่ระบุชนิด เช่น `robot->getMotor("left wheel motor")` หรือ `robot->getCamera("camera")` แทน `getDevice()` และ include เฮดเดอร์ที่ตรงกัน เช่น `<webots/Motor.hpp>`
:::

## โปรแกรมแรก {#a-first-program}

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

## การคอมไพล์ {#compiling}
วิธีที่ง่ายที่สุดในทุกระบบคือใช้ตัวแก้ไขของ Webots: ใช้ **Wizards > New Robot Controller** เพื่อสร้างคอนโทรลเลอร์ C++ พร้อม `Makefile` แล้วกดปุ่ม **Build** ดู[คู่มือของ Webots](https://cyberbotics.com/doc/guide/using-cpp?version=R2023b)

คุณยังคอมไพล์จากเทอร์มินัลได้ด้วย คำสั่งนี้ทดสอบบน macOS แล้ว:

```bash
WEBOTS=/Applications/Webots.app/Contents
clang++ -std=c++17 -I$WEBOTS/include/controller/cpp -L$WEBOTS/lib/controller \
  -lController -lCppController -Wl,-rpath,$WEBOTS/lib/controller \
  my_controller.cpp -o my_controller
```

บน Linux ตัวเลือกเดียวกันใช้ได้กับ `WEBOTS=/usr/local/webots` หากคุณใช้ OpenCV ให้เพิ่มตัวเลือกของ OpenCV ด้วย เมื่อติดตั้ง OpenCV 4 แล้ว เช่น ผ่าน Homebrew บน macOS คำสั่ง `$(pkg-config --cflags --libs opencv4)` จะให้ตัวเลือกเหล่านั้น ตัวอย่างทดสอบกับ OpenCV 4.13

## การรัน {#running}

- **บน Windows** โหลดไฟล์ `.exe` ด้วยปุ่ม LOAD ด้านซ้ายของหน้าต่างควบคุม
- **บน macOS และ Linux** โปรแกรมที่คอมไพล์แล้วไม่มีนามสกุลไฟล์ และปุ่ม LOAD เลือกไฟล์เหล่านี้ไม่ได้ ให้รันด้วย [Remote Controller](/docs/competition/remote-controller/) แทน เหมือนที่คุณทำในการแข่งขัน
