---
title: Windows
description: วิธีตั้งค่า Remote Controller บน Windows
---

# การรันเซิร์ฟเวอร์เกมและโปรแกรมคอนโทรลเลอร์บนคอมพิวเตอร์เครื่องเดียวกัน
ก่อนอื่น ให้ลองรันเซิร์ฟเวอร์เกมและโปรแกรมคอนโทรลเลอร์ของคุณบนคอมพิวเตอร์เครื่องเดียวกัน วิธีนี้ไม่เหมือนกับการตั้งค่าที่ใช้ในการแข่งขัน แต่สะดวกสำหรับการดีบักบนเครื่องของตัวเอง

## เปิดโหมดรีโมต {#toggle-remote-mode}
เปิดโลกแล้วกด "TOGGLE REMOTE" ในหน้าต่างควบคุม ปุ่มจะเปลี่ยนเป็นสีส้มเพื่อแสดงว่าโหมดรีโมตเปิดอยู่  
![ปุ่ม TOGGLE REMOTE](../../../../../docs/competition/remote-controller/windows/toggleRemote.png)

หากหน้าต่างควบคุมไม่แสดง ให้คลิกขวาที่ "DEF MAINSUPERVISOR Robot" ใน Scene Tree แล้วเลือก "Show Robot Window"  
![ตัวเลือก Show Robot Window](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## รันโปรแกรมของคุณ {#execute-your-program}
เปิด PowerShell ซึ่งปกติจะอยู่ในรายการแอปพลิเคชัน  
![PowerShell ในรายการแอปพลิเคชัน](../../../../../docs/competition/remote-controller/windows/powerShell.png)

รันคำสั่งต่อไปนี้ใน PowerShell โดยแทนที่ `<Your controller path>` ด้วยพาธของโปรแกรมคอนโทรลเลอร์ของคุณ

`webots-controller.exe <Your controller path>`

หากไม่พบคำสั่งนี้ ให้ใช้พาธเต็มของคำสั่ง ซึ่งโดยค่าเริ่มต้นคือ `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe`

หากไม่รู้พาธของโปรแกรมคอนโทรลเลอร์ ให้ลากไฟล์นั้นมาวางในหน้าต่าง PowerShell แล้วพาธของไฟล์จะถูกใส่ให้โดยอัตโนมัติ  
![การลากไฟล์มาวางในหน้าต่าง PowerShell](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

จากนั้นกด Enter เพื่อรันคำสั่ง คอนโทรลเลอร์จะเชื่อมต่อกับ Webots และรอจนกว่าเกมจะเริ่ม

## เริ่มเกม {#start-the-game}
กดปุ่มเริ่มในหน้าต่างควบคุมเพื่อเริ่มการจำลอง  
![ปุ่มเริ่มของหน้าต่างควบคุม](../../../../../docs/competition/remote-controller/windows/run.png)

## หยุดเกม {#terminate-the-game}
หากต้องการหยุดเกม ให้กด Ctrl+C ใน PowerShell เพื่อหยุดโปรแกรมของคุณ

เมื่อการจำลองสิ้นสุดลง ตัวจัดการเกมของ Erebus ก็จะหยุดทำงานด้วย หากต้องการรันเกมอีกครั้ง ให้โหลดโลกใหม่  
![ปุ่มโหลดใหม่ของ Webots](../../../../../docs/competition/remote-controller/windows/reload.png)

# การรันเซิร์ฟเวอร์เกมบนคอมพิวเตอร์อีกเครื่องหนึ่ง
นี่คือการตั้งค่าที่ใช้ในการแข่งขันอย่างเป็นทางการ คอมพิวเตอร์ที่รันคอนโทรลเลอร์ของคุณ (ไคลเอนต์) และคอมพิวเตอร์ที่รันเกม (เซิร์ฟเวอร์) ต้องเชื่อมต่อกับเครือข่ายเดียวกัน

1. (เซิร์ฟเวอร์) เริ่ม Webots บนเซิร์ฟเวอร์ เปิดโลก แล้วเปิดโหมดรีโมตในหน้าต่างควบคุม
2. (เซิร์ฟเวอร์) หาที่อยู่ IP ของเซิร์ฟเวอร์ ดูวิธีได้ที่[ค้นหาที่อยู่ IP ของคุณใน Windows](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9)
3. (ไคลเอนต์) รันคำสั่งต่อไปนี้ใน PowerShell โดยแทนที่ `<Your controller path>` ด้วยพาธของโปรแกรมคอนโทรลเลอร์ของคุณ และ `<Server IP address>` ด้วยที่อยู่ IP ที่หาได้ในขั้นตอนก่อนหน้า  
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. (เซิร์ฟเวอร์) เริ่มเกมโดยกดปุ่มเริ่ม

# การแก้ไขปัญหา
หากคอนโทรลเลอร์เชื่อมต่อไม่ได้ ให้ตรวจสอบว่าคอมพิวเตอร์ทั้งสองเครื่องติดต่อกันได้ ไฟร์วอลล์ของเซิร์ฟเวอร์อนุญาตพอร์ต TCP 1234 และรายการ IP ที่อนุญาตในแท็บ Network ของ Preferences ใน Webots ว่างอยู่หรือมี IP ของไคลเอนต์อยู่ด้วย

# เอกสารทางการ
ดูรายละเอียดเพิ่มเติมเกี่ยวกับการตั้งค่านี้ได้ใน[คู่มือของ Webots](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b)
