---
title: Windows
description: Remote Controller'ın Windows'ta nasıl kurulacağı.
---

# Oyun sunucusunu ve denetleyici programını aynı bilgisayarda çalıştırma
Önce oyun sunucusunu ve denetleyici programını aynı bilgisayarda çalıştırmayı dene. Bu, yarışmadaki kurulumla aynı değildir, ama kendi bilgisayarında hata ayıklarken işine yarar.

## Uzaktan modu aç {#toggle-remote-mode}
Dünyayı aç, kontrol penceresinde **Robot setup** düğmesine bas ve **Remote mode** seçeneğini aç. Özel bir robotun varsa önce onu **Robot JSON** altından yükle.  
![Robot setup içinde açılmış Remote mode](../../../../../docs/competition/remote-controller/windows/../mac/toggle_remote.png)

Kontrol penceresi görünmüyorsa Scene Tree'de "DEF MAINSUPERVISOR Robot" öğesine sağ tıkla ve "Show Robot Window" seçeneğini seç.  
![Show Robot Window seçeneği](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## Programını çalıştır {#execute-your-program}
PowerShell'i aç. Genellikle uygulamalar listesinde bulabilirsin.  
![Uygulamalar listesinde PowerShell](../../../../../docs/competition/remote-controller/windows/powerShell.png)

PowerShell'de, `<Your controller path>` yerine denetleyici programının yolunu yazarak aşağıdaki komutu çalıştır.

`webots-controller.exe <Your controller path>`

Komut bulunamazsa komutun tam yolunu kullan; varsayılan yol `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe` şeklindedir.

Denetleyici programının yolunu bilmiyorsan dosyayı PowerShell penceresine sürükleyip bırak; yolu otomatik olarak doldurulur.  
![Bir dosyayı PowerShell penceresine sürükleme](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

Ardından komutu çalıştırmak için Enter'a bas. Denetleyici Webots'a bağlanır ve oyun başlayana kadar bekler.

## Oyunu başlat {#start-the-game}
Oyunu başlatmak için kontrol penceresindeki **Run match** düğmesine bas.  
![Kontrol penceresindeki Run match düğmesi](../../../../../docs/competition/remote-controller/windows/../../../getting-started/match-controls.png)

## Oyunu sonlandır {#terminate-the-game}
Oyunu durdurmak için PowerShell'de Ctrl+C tuşlarına basarak programını durdur.

Oyun bitince yeniden çalıştırmak için **Reset** düğmesine bas. **Keep on Reset** açık değilse sıfırlama Remote mode'u kapatır.

# Oyun sunucusunu farklı bir bilgisayarda çalıştırma
Resmî yarışmalarda kullanılan kurulum budur. Denetleyicini çalıştıran bilgisayar (istemci) ile oyunu çalıştıran bilgisayar (sunucu) aynı ağa bağlı olmalıdır.

2. (Sunucu) Sunucuda Webots'u başlat, dünyayı aç ve kontrol penceresinin **Robot setup** bölümünde **Remote mode** seçeneğini aç.
2. (Sunucu) Sunucunun IP adresini öğren. [Windows'ta IP adresini bulma](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9) makalesine bak.
3. (İstemci) `<Your controller path>` yerine denetleyici programının yolunu, `<Server IP address>` yerine de önceki adımda bulduğun IP adresini yazarak PowerShell'de aşağıdaki komutu çalıştır.  
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. (Sunucu) **Run match** düğmesine basarak oyunu başlat.

# Sorun giderme
Denetleyici bağlanamazsa iki bilgisayarın birbirine ulaşabildiğini, sunucunun güvenlik duvarının 1234 numaralı TCP portuna izin verdiğini ve Webots tercihlerinin Network sekmesindeki izin verilen IP'ler listesinin boş olduğunu ya da istemciyi içerdiğini kontrol et.

# Resmî belgeler
Bu kurulum hakkında daha fazla ayrıntı için [Webots kılavuzuna](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a) bak.
