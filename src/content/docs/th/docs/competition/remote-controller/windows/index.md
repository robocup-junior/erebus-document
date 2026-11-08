---
title: Windows
description: คู่มือการตั้งค่า Remote Controller สำหรับ Windows
---

# การรันเซิร์ฟเวอร์เกมและโปรแกรมคอนโทรลเลอร์บน PC เครื่องเดียวกัน
ก่อนอื่น ลองรันเซิร์ฟเวอร์เกมและโปรแกรมคอนโทรลเลอร์บน PC เครื่องเดียวกัน วิธีนี้ไม่เหมือนกับการตั้งค่าในการแข่งขันจริง แต่จะช่วยคุณเมื่อดีบักบนเครื่องของตัวเอง

## เปิดโหมด Remote {#toggle-remote-mode}
กด "TOGGLE REMOTE" ใน Robot Window (หน้าต่างควบคุม) เพื่อเปิดใช้การตั้งค่า Remote Controller ปุ่มจะเปลี่ยนเป็นสีส้มเพื่อแสดงว่าเปิดใช้งานแล้ว  
![ปุ่ม TOGGLE REMOTE](../../../../../docs/competition/remote-controller/windows/toggleRemote.png)

หาก Robot Window ไม่แสดง ให้คลิกขวาที่ "DEF MAINSUPERVISOR Robot" ใน Scene Tree แล้วกด "Show Robot Window"  
![ตัวเลือก Show Robot Window](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## รันโปรแกรมของคุณ {#execute-your-program}
เปิด PowerShell โดยปกติคุณจะหาได้ในรายการแอปพลิเคชัน  
![PowerShell ในรายการแอปพลิเคชัน](../../../../../docs/competition/remote-controller/windows/powerShell.png)

รันคำสั่งต่อไปนี้ใน PowerShell โดยแทนที่ `<Your controller path>` ด้วยพาธของโปรแกรมคอนโทรลเลอร์ของคุณ

`webots-controller.exe <Your controller path>`

หากไม่พบคำสั่ง ให้ใช้พาธเต็ม ซึ่งค่าเริ่มต้นคือ `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe`

หากคุณไม่รู้พาธของโปรแกรมคอนโทรลเลอร์ คุณลากไฟล์นั้นมาวางในหน้าต่าง PowerShell ได้ แล้วพาธจะถูกใส่ให้อัตโนมัติ  
![การลากไฟล์มาวางในหน้าต่าง PowerShell](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

หลังจากพิมพ์คำสั่งแล้ว กด Enter เพื่อรัน

## เริ่มเกม {#start-the-game}
กดปุ่มเริ่มใน Robot Window เพื่อเริ่มการจำลอง  
![ปุ่มเริ่มของหน้าต่างควบคุม](../../../../../docs/competition/remote-controller/windows/run.png)

## หยุดเกม {#terminate-the-game}
หากต้องการขัดจังหวะการทำงานของเกม ให้ขัดจังหวะโปรแกรมที่รันอยู่ใน PowerShell โดยกด Ctrl+C

เมื่อการจำลองสิ้นสุดลง ระบบจัดการเกมของ Erebus จะสิ้นสุดลงพร้อมกัน หากต้องการรันเกมอีกครั้ง ให้โหลดโลกใหม่  
![ปุ่มโหลดใหม่ของ Webots](../../../../../docs/competition/remote-controller/windows/reload.png)

# การรันเซิร์ฟเวอร์เกมบน PC อีกเครื่องหนึ่ง
นี่คือการตั้งค่าที่ใช้ในการแข่งขันอย่างเป็นทางการ
PC ที่รันคอนโทรลเลอร์ของคุณ (ไคลเอนต์) และเซิร์ฟเวอร์เกม (เซิร์ฟเวอร์) ต้องเชื่อมต่อกับเครือข่ายเดียวกัน

1. (เซิร์ฟเวอร์) เริ่ม Webots บน PC เซิร์ฟเวอร์ เปิดโลก แล้วเปิดโหมด Remote จาก Robot Window
2. (เซิร์ฟเวอร์) หาที่อยู่ IP ของ PC นั้น ดูวิธีได้จาก[บทความนี้](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9)
3. (ไคลเอนต์) รันคำสั่งต่อไปนี้ใน PowerShell โดยแทนที่ `<Your controller path>` ด้วยพาธของโปรแกรมคอนโทรลเลอร์ของคุณ และ `<Server IP address>` ด้วยที่อยู่ IP ที่หาได้ในขั้นตอนก่อนหน้า  
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. (เซิร์ฟเวอร์) เริ่มเกมโดยกดปุ่มเริ่ม

# การแก้ไขปัญหา
หากคอนโทรลเลอร์เชื่อมต่อไม่ได้ ให้ตรวจสอบว่า PC ทั้งสองเครื่องติดต่อกันได้ ไฟร์วอลล์ของเซิร์ฟเวอร์อนุญาตพอร์ต TCP 1234 และรายการ IP ที่อนุญาตในแท็บ Network ของ Preferences ใน Webots ว่างอยู่หรือมีไคลเอนต์อยู่ด้วย

# เอกสารทางการ
หากต้องการทราบรายละเอียดเพิ่มเติมเกี่ยวกับการตั้งค่า ดูได้ใน[คู่มือทางการ](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b)
