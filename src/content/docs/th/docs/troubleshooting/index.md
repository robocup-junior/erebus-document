---
title: การแก้ไขปัญหา
description: วิธีแก้ปัญหาที่พบบ่อยเมื่อติดตั้งและรัน Erebus
---

ก่อนอื่น ให้ตรวจสอบคอนโซลของ Webots ปัญหาส่วนใหญ่จะแสดงข้อความแจ้งข้อผิดพลาดไว้ที่นั่น

## การติดตั้ง {#installation}

### `No module named 'cv2'` {#no-module-named-cv2}
ยังไม่ได้ติดตั้ง OpenCV ใน Python ที่ Webots ใช้ ให้ติดตั้ง[ไลบรารีที่จำเป็น](/docs/installation/#python-libraries) ใน Python นั้น หากคุณติดตั้ง Python ไว้หลายชุด การตั้งค่า **Python command** ด้านล่างจะบอกว่า Webots ใช้ชุดใด

### `WARNING: Python was not found` {#warning-python-was-not-found}
Webots ไม่รู้ว่า Python อยู่ที่ใด

1. หาตำแหน่งของ Python บน macOS และ Linux ให้รัน `which python3` ในเทอร์มินัล บน Windows ให้ตรวจสอบว่าการพิมพ์ `python` ใน Command Prompt ใหม่จะเปิด Python ได้ หากไม่ได้ ให้ติดตั้ง Python ใหม่ โดยเลือกตัวเลือกเพิ่ม Python ลงใน PATH
2. เปิด Preferences ของ Webots: **Webots > Preferences** บน macOS และ **Tools > Preferences** บน Windows และ Linux

   ![เมนู Preferences ใน Webots](../../../docs/troubleshooting/preferences_open.png)

3. ตั้งพาธในช่อง **Python command** บน Windows โดยทั่วไปใช้ `python` ก็พอ

   ![ช่อง Python command ใน Preferences ของ Webots](../../../docs/troubleshooting/preferences.png)

### ตัวจับเวลาเกมไม่ปรากฏ {#the-game-timer-does-not-appear}
การเริ่มครั้งแรกอาจใช้เวลาหลายนาทีขณะที่ Erebus ติดตั้งไลบรารี หากไม่เสร็จเสียที ให้ตรวจสอบข้อผิดพลาดในคอนโซล หากการติดตั้งอัตโนมัติไม่ทำงาน ให้ติดตั้ง[ไลบรารีที่จำเป็น](/docs/installation/#python-libraries) ด้วยตัวเอง

## การรัน Erebus {#running-erebus}

### หน้าต่างควบคุมไม่ปรากฏ {#the-control-window-does-not-appear}
หน้าต่างควบคุมเป็นหน้าเว็บที่ Webots เปิดขึ้น

1. หากเบราว์เซอร์ของคุณบล็อกไว้ ให้เปิด[หน้าต่างควบคุม](http://localhost:1234/robot_windows/MainSupervisorWindow/MainSupervisorWindow.html?name=robot) ขณะที่โลกเปิดอยู่
2. มิฉะนั้น ตรวจสอบให้แน่ใจว่า Scene Tree แสดงอยู่ ด้วย **Tools > Scene Tree**
3. หา **DEF MAINSUPERVISOR Robot** ใน Scene Tree คลิกขวาแล้วเลือก **Show Robot Window**

![ตัวเลือก Show Robot Window ใน Scene Tree](../../../docs/troubleshooting/showrobot.png)

### หน้าจอ Webots ว่างเปล่าหรือเป็นสีดำ {#the-webots-screen-is-blank-or-black}
คัดลอกไฟล์ที่ดาวน์โหลดมาและแตกไฟล์ไว้ในโฟลเดอร์แยกต่างหากก่อนเปิดโลก

### การจำลองทำงานช้าเกินไป {#the-simulation-runs-too-slowly}
สาเหตุน่าจะมาจากประสิทธิภาพของคอมพิวเตอร์ของคุณ การลดคุณภาพของกราฟิกอาจช่วยได้:

1. เปิด Preferences ของ Webots
2. เปิดแท็บ **OpenGL**
3. เปลี่ยนการตั้งค่า

![แท็บ OpenGL ใน Preferences ของ Webots](../../../docs/troubleshooting/opengl.png)

การตั้งค่าเหล่านี้เปลี่ยนสิ่งที่กล้องเห็น และการแข่งขันใช้[การตั้งค่าของตัวเอง](/docs/competition/#opengl-settings) ดังนั้นให้ตรวจสอบโปรแกรมของคุณด้วยการตั้งค่านั้นด้วย

## หุ่นยนต์ของคุณ {#your-robot}

### `PROTO parameter 'camera_width' has no matching IS field` {#proto-parameter-camera_width-has-no-matching-is-field}
Erebus v26.1 แสดงข้อผิดพลาดนี้เป็นสีแดงเมื่อโหลดหุ่นยนต์ที่สร้างด้วย Robot Customizer เวอร์ชันปัจจุบัน คุณละเลยได้: หุ่นยนต์ทำงานได้ และกล้องมีความละเอียดตามที่คุณเลือก

### โปรแกรมแจ้งว่าไม่พบอุปกรณ์ {#my-program-says-a-device-was-not-found}
ดูด้านล่าง และตรวจสอบด้วยว่าคุณโหลดหุ่นยนต์ด้วยปุ่ม LOAD **ด้านขวา** ก่อนเริ่มเกมแล้ว

## โปรแกรมของคุณ {#your-program}

### `Device "..." was not found` {#device--was-not-found}
ชื่ออุปกรณ์ในโปรแกรมของคุณไม่ตรงกับหุ่นยนต์ ชื่อของหุ่นยนต์เริ่มต้นอยู่ใน[ข้อมูลอ้างอิง](/docs/reference/parameters/#device-names-of-the-starter-robot) สำหรับหุ่นยนต์ของคุณเอง ชื่อคือชื่อที่คุณตั้งไว้ใน [Robot Customizer](/docs/robot/customizer/) ตรวจสอบว่าโหลดหุ่นยนต์แล้ว

### ไม่มีอะไรเกิดขึ้นเมื่อรายงานสัญลักษณ์บนผนัง {#nothing-happens-when-i-report-a-wall-token}
เปิด **Enable debugging** ในแท็บ Settings ของหน้าต่างควบคุม แล้วตรวจสอบคอนโซล สาเหตุที่พบบ่อยที่สุดคือหุ่นยนต์ไม่ได้หยุดนิ่งอย่างน้อย 1 วินาที และพิกัดไม่ได้แปลงเป็นเซนติเมตร ดู[การสื่อสาร](/docs/programming/communication/#scoring-wall-tokens)

### การรายงานของฉันกลายเป็นการระบุผิด {#my-reports-are-misidentifications}
หุ่นยนต์ต้องอยู่ห่างจากสัญลักษณ์ไม่เกินครึ่งช่องและอยู่ฝั่งเดียวกันของผนัง และสัญลักษณ์แต่ละอันทำคะแนนได้เพียงครั้งเดียว การรายงานของปลอมก็นับเป็นการระบุผิดเช่นกัน

### แผนที่ได้ 0% หรือเกิดข้อผิดพลาดในการให้คะแนน {#the-map-gets-0-or-a-scoring-error}
แผนที่ของคุณต้องมีช่องเริ่มต้น (`5`) และประเมินได้เพียงครั้งเดียว ดู[การส่งแผนที่](/docs/programming/map-bonus/)

### คอนโทรลเลอร์เชื่อมต่อไม่ได้ในโหมด remote {#the-controller-cannot-connect-in-remote-mode}
ดูคู่มือ [Remote Controller](/docs/competition/remote-controller/) สำหรับระบบปฏิบัติการของคุณ

## ยังแก้ไม่ได้? {#still-stuck}
ถามได้ที่[เซิร์ฟเวอร์ Discord](https://discord.com/invite/6FJxZxk) หรือ[เปิด issue](https://github.com/robocup-junior/erebus/issues) โดยระบุระบบปฏิบัติการ เวอร์ชันของ Erebus และ Webots และข้อความในคอนโซล
