---
title: macOS
description: วิธีตั้งค่า Remote Controller บน macOS
---

# การรันเซิร์ฟเวอร์เกมและโปรแกรมคอนโทรลเลอร์บนคอมพิวเตอร์เครื่องเดียวกัน
ก่อนอื่น ให้ลองรันเซิร์ฟเวอร์เกมและโปรแกรมคอนโทรลเลอร์ของคุณบนคอมพิวเตอร์เครื่องเดียวกัน วิธีนี้ไม่เหมือนกับการตั้งค่าที่ใช้ในการแข่งขัน แต่สะดวกสำหรับการดีบักบนเครื่องของตัวเอง

## เปิดโหมดรีโมต {#toggle-remote-mode}
เปิดโลก กด **Robot setup** ในหน้าต่างควบคุม แล้วเปิด **Remote mode** ถ้ามีหุ่นยนต์แบบกำหนดเอง ให้โหลดหุ่นยนต์ใต้ **Robot JSON** ก่อน

![Remote mode ที่เปิดใน Robot setup](../../../../../docs/competition/remote-controller/mac/toggle_remote.png)

หากหน้าต่างควบคุมไม่แสดง ให้คลิกขวาที่ "DEF MAINSUPERVISOR Robot" ใน Scene Tree แล้วเลือก "Show Robot Window"

## รันโปรแกรมของคุณ {#execute-your-program}
เปิดเทอร์มินัลแล้วรันคำสั่งต่อไปนี้ โดยแทนที่ `<Your controller path>` ด้วยพาธของโปรแกรมคอนโทรลเลอร์ของคุณ

```bash
export WEBOTS_HOME=/Applications/Webots.app
"$WEBOTS_HOME/Contents/MacOS/webots-controller" "<Your controller path>"
```

หากติดตั้ง Webots ไว้ที่อื่นหรือใช้ชื่ออื่น ให้เปลี่ยน `WEBOTS_HOME` ให้ตรงกัน เช่น `"/Applications/Webots R2025a.app"`

คอนโทรลเลอร์จะเชื่อมต่อกับ Webots และรอจนกว่าเกมจะเริ่ม

## เริ่มเกม {#start-the-game}
กด **Run match** ในหน้าต่างควบคุม หุ่นยนต์จะปรากฏ และโปรแกรมของคุณจะเริ่มทำงาน

## หยุดเกม {#terminate-the-game}
หากต้องการหยุดเกม ให้กด Ctrl+C ในเทอร์มินัล

เมื่อเกมจบ ให้กด **Reset** เพื่อรันอีกครั้ง การรีเซ็ตจะปิด Remote mode เว้นแต่จะเปิด **Keep on Reset** ไว้

# การรันเซิร์ฟเวอร์เกมบนคอมพิวเตอร์อีกเครื่องหนึ่ง
นี่คือการตั้งค่าที่ใช้ในการแข่งขันอย่างเป็นทางการ คอมพิวเตอร์ที่รันคอนโทรลเลอร์ของคุณ (ไคลเอนต์) และคอมพิวเตอร์ที่รันเกม (เซิร์ฟเวอร์) ต้องเชื่อมต่อกับเครือข่ายเดียวกัน

1. (เซิร์ฟเวอร์) เปิด Webots บนเซิร์ฟเวอร์ เปิดโลก และเปิด **Remote mode** ใน **Robot setup** ของหน้าต่างควบคุม
1. (เซิร์ฟเวอร์) หาที่อยู่ IP ของเซิร์ฟเวอร์ ดูได้ใน System Settings > Network
1. (ไคลเอนต์) รันคำสั่งต่อไปนี้ โดยแทนที่ `<Your controller path>` ด้วยพาธของโปรแกรมคอนโทรลเลอร์ของคุณ และ `<Server IP address>` ด้วยที่อยู่ IP ที่หาได้ในขั้นตอนก่อนหน้า

    ```bash
    export WEBOTS_HOME=/Applications/Webots.app
    "$WEBOTS_HOME/Contents/MacOS/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. (เซิร์ฟเวอร์) เริ่มเกมโดยกด **Run match**

## การแก้ไขปัญหา {#troubleshooting}
- **คอนโทรลเลอร์เชื่อมต่อไม่ได้:** ตรวจสอบว่าคอมพิวเตอร์ทั้งสองเครื่องติดต่อกันได้ (เช่น ด้วย `ping`) ไฟร์วอลล์ของเซิร์ฟเวอร์อนุญาตพอร์ต TCP 1234 และรายการ IP ที่อนุญาตในแท็บ Network ของ Preferences ใน Webots ว่างอยู่หรือมี IP ของไคลเอนต์อยู่ด้วย
- **คอนโทรลเลอร์รออยู่ แต่หุ่นยนต์ไม่ขยับ:** ตรวจสอบว่าเปิด **Remote mode** แล้ว และกด **Run match**
- **คอนโทรลเลอร์หาไลบรารี Python ไม่พบ:** โปรแกรมรันด้วย Python ที่ติดตั้งอยู่บนไคลเอนต์ จึงต้องติดตั้งไลบรารีไว้ที่เครื่องนั้น

# เอกสารทางการ
ดูรายละเอียดเพิ่มเติมเกี่ยวกับการตั้งค่านี้ได้ใน[คู่มือของ Webots](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a)
