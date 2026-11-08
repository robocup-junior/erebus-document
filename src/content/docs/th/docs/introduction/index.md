---
title: Erebus คืออะไร?
description: Erebus คือแพลตฟอร์มการจำลองการกู้ภัยของ RoboCupJunior ที่สร้างบน Webots มาเรียนรู้ว่าส่วนต่าง ๆ ทำงานร่วมกันอย่างไร
---

Erebus เป็นสภาพแวดล้อมสำหรับการแข่งขันหุ่นยนต์จำลอง คุณพัฒนาคอนโทรลเลอร์ให้หุ่นยนต์ที่สำรวจเขาวงกตได้เอง ค้นหาและระบุสัญลักษณ์บนผนัง (ผู้ประสบภัยแบบตัวอักษรและเป้าหมายเชิงรับรู้) หลบสิ่งกีดขวางและกับดัก และสร้างแผนที่ของสภาพแวดล้อม

Erebus สร้างบน [Webots](https://cyberbotics.com/) ซึ่งเป็นแพลตฟอร์มจำลองหุ่นยนต์ที่ออกแบบมาสำหรับการใช้งานระดับมืออาชีพ และใช้กันอย่างแพร่หลายในอุตสาหกรรม การศึกษา และการวิจัย Cyberbotics ดูแล Webots อย่างต่อเนื่องมาตั้งแต่ปี 1998

แพลตฟอร์มนี้ออกแบบมาสำหรับการแข่งขัน [RoboCupJunior Rescue Simulation](https://junior.robocup.org/rescue/) เป็นหลัก และเหมาะสำหรับผู้เขียนโปรแกรมระดับกลางไปจนถึงผู้มีประสบการณ์สูง

## ส่วนต่าง ๆ ทำงานร่วมกันอย่างไร {#how-it-fits-together}

| องค์ประกอบ | หน้าที่ | หาได้จากที่ใด |
|---|---|---|
| **Webots R2023b** | ซิมูเลเตอร์หุ่นยนต์แบบ 3 มิติ | [Webots R2023b release](https://github.com/cyberbotics/webots/releases/tag/R2023b) |
| **Erebus** | โลกต่าง ๆ และตัวจัดการเกม (Main Supervisor) ซึ่งใช้กติกาและคำนวณคะแนน | [Erebus releases](https://github.com/robocup-junior/erebus/releases) |
| **คอนโทรลเลอร์ของคุณ** | โปรแกรมของหุ่นยนต์ของคุณ เขียนด้วย Python หรือ C/C++ | คุณเขียนเอง! |
| **Robot Customizer** | เครื่องมือบนเว็บสำหรับออกแบบหุ่นยนต์แบบกำหนดเอง และส่งออกเป็นไฟล์ JSON | [robot.erebus.rcj.cloud](https://robot.erebus.rcj.cloud/) |
| **World Editor** | เครื่องมือบนเว็บสำหรับวาดแผนที่ฝึกซ้อม และส่งออกเป็นโลก `.wbt` | [world.erebus.rcj.cloud](https://world.erebus.rcj.cloud/) |

## คุณทำอะไรกับมันได้บ้าง? {#what-can-you-do-with-it}

1. **สร้างหุ่นยนต์** เลือกเซนเซอร์และตำแหน่งที่ติดตั้ง ภายในงบประมาณ
2. **เขียนโปรแกรม** คอนโทรลเลอร์ของคุณอ่านเซนเซอร์และตัดสินใจว่าจะทำอะไร โดยไม่มีมนุษย์ช่วย
3. **รัน** ทดสอบบนโลกที่มีมาให้หรือโลกของคุณเอง แล้วดูคะแนน
4. **แข่งขัน** เข้าร่วมการแข่งขัน RoboCupJunior ระดับท้องถิ่น ระดับภูมิภาค และระดับนานาชาติ

หากคุณรู้จัก Erebus อยู่แล้ว ดู[มีอะไรใหม่ใน v26](/docs/whats-new/)

## แหล่งอ้างอิงที่มีประโยชน์ {#useful-references}
รายการลิงก์ที่มีประโยชน์สำหรับการเรียนรู้และการทำงานกับ Erebus Simulator:
- [คู่มือผู้ใช้ Webots](https://cyberbotics.com/doc/guide/index?version=R2023b)
- [คู่มืออ้างอิง Webots](https://cyberbotics.com/doc/reference/nodes-and-api-functions?version=R2023b)
- [เอกสาร Python](https://www.python.org/doc/)
- [เอกสาร C++](https://www.cplusplus.com/doc/tutorial/)
- [บทเรียน OpenCV](https://docs.opencv.org/4.x/d9/df8/tutorial_root.html)
- [เว็บไซต์ชุมชน RCJ Rescue](https://rescue.rcj.cloud/): กิจกรรม เอกสารของทีม และเกณฑ์การให้คะแนน TDP โปสเตอร์ และวิดีโอ
- [RoboCupJunior Forum](https://junior.forum.robocup.org/): คำชี้แจงกติกา

## ขั้นต่อไป {#next}
[ติดตั้ง Erebus](/docs/installation/) แล้วอ่าน[สรุปกติกา](/docs/rules/) เพื่อทำความเข้าใจเกม
