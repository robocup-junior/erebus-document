---
title: Windows
description: Windows için Remote Controller kurulum kılavuzu.
---

# Oyun sunucusunu ve denetleyici programlarını aynı bilgisayarda çalıştırma
Önce oyun sunucusunu ve denetleyici programlarını aynı bilgisayarda çalıştırmayı deneyelim. Bu, gerçek bir yarışma kurulumuyla aynı değildir, ama yerelde hata ayıklarken sana yardımcı olur.

## Uzaktan modu aç {#toggle-remote-mode}
Uzaktan denetleyici kurulumunu etkinleştirmek için Robot Window (robot penceresi) üzerinde "TOGGLE REMOTE" düğmesine bas. Etkinleştirildiğini göstermek için düğmenin rengi turuncuya dönmelidir.  
![TOGGLE REMOTE düğmesi](../../../../../docs/competition/remote-controller/windows/toggleRemote.png)

Robot Window görünmüyorsa Scene Tree içinde "DEF MAINSUPERVISOR Robot" öğesine sağ tıkla ve "Show Robot Window" seçeneğine bas.  
![Show Robot Window seçeneği](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## Programını çalıştır {#execute-your-program}
PowerShell'i aç. Genellikle uygulamalar listesinde bulabilirsin.  
![Uygulamalar listesinde PowerShell](../../../../../docs/competition/remote-controller/windows/powerShell.png)

`<Your controller path>` yerine denetleyici programının yolunu yazarak PowerShell içinde aşağıdaki komutu çalıştır.

`webots-controller.exe <Your controller path>`

Komut bulunamazsa tam yolu kullan; varsayılan olarak bu `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe` yoludur.

Denetleyici programının yolunu bilmiyorsan dosyayı PowerShell penceresine sürükleyip bırakabilirsin; yol otomatik olarak doldurulur.  
![Bir dosyayı PowerShell penceresine sürükleme](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

Komutu yazdıktan sonra çalıştırmak için Enter'a bas.

## Oyunu başlat {#start-the-game}
Simülasyonu başlatmak için Robot Window'daki başlat düğmesine bas.  
![Kontrol penceresinin başlat düğmesi](../../../../../docs/competition/remote-controller/windows/run.png)

## Oyunu sonlandır {#terminate-the-game}
Oyunun yürütülmesini yarıda kesmek için PowerShell'de çalışan programı Ctrl+C tuşlarına basarak durdur.

Simülasyon sonlandırıldığında Erebus oyun yönetim sistemi de aynı anda sonlandırılır. Oyunu yeniden çalıştırmak istersen dünyayı yeniden yükle.  
![Webots'un yeniden yükleme düğmesi](../../../../../docs/competition/remote-controller/windows/reload.png)

# Oyun sunucusunu farklı bir bilgisayarda çalıştırma
Resmî yarışmalarda kullanılan kurulum budur.
Denetleyicini çalıştıran bilgisayar (istemci) ile oyun sunucusu (sunucu) aynı ağa bağlı olmalıdır.

1. (Sunucu) Sunucu bilgisayarda Webots'u başlat, dünyayı aç ve Robot Window'dan uzaktan modu aç.
2. (Sunucu) O bilgisayarın IP adresini öğren. Bunun için [bu makaleye](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9) başvurabilirsin.
3. (İstemci) `<Your controller path>` yerine denetleyici programının yolunu, `<Server IP address>` yerine önceki adımda bulduğumuz IP adresini yazarak PowerShell içinde aşağıdaki komutu çalıştır.   
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. (Sunucu) Başlat düğmesine basarak oyunu başlat.

# Sorun giderme
Denetleyici bağlanamazsa iki bilgisayarın birbirine ulaşabildiğini, sunucunun güvenlik duvarının 1234 numaralı TCP portuna izin verdiğini ve Webots tercihlerinin (Preferences) Network sekmesindeki izin verilen IP listesinin boş olduğunu ya da istemciyi içerdiğini kontrol et.

# Resmî belge
Kurulum hakkında daha ayrıntılı bilgi istersen [Resmî Kılavuz](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b) sayfasında bulabilirsin.
