---
title: Parametre başvurusu
description: Saha ölçüleri, oyun süreleri, puan çarpanları, robot sınırları ve başlangıç robotunun cihaz adları.
---

## Saha {#field}

| Parametre | Değer |
|---|---|
| Kare | 12 cm × 12 cm |
| Çeyrek kare (2. ve 3. alanlar) | 6 cm × 6 cm |
| Duvar | 1 cm kalınlığında, 6 cm yüksekliğinde |
| Harf kazazede | 2 cm × 2 cm |
| Bilişsel hedef | 5 cm çapında |

## Oyun {#game}

| Parametre | Değer |
|---|---|
| Oyun süresi | 8 dakika simülasyon zamanı |
| Gerçek zaman | 10 dakika |
| Otomatik ilerleme eksikliği | Sabit bir konumda 20 saniye kaldıktan sonra |
| Duvar işareti bildirmek için durma süresi | En az 1 saniye |
| Bataklıkta zaman çarpanı | İlk girişte x5, aynı bataklığa her yeni girişte +1, en fazla x10 |
| Alan çarpanları | 1., 2., 3. ve 4. alanlar için sırasıyla 1, 1,25, 1,5 ve 2 |
| Çıkış bonusu | +%10 |
| Haritalama bonusu çarpanı | doğruluk × 1,2 + 1 |

## Robot {#robot}

| Parametre | Değer |
|---|---|
| Bütçe | 3000 |
| En fazla kamera sayısı | 3 |
| En fazla mesafe sensörü sayısı | 8 |
| Mesafe sensörü menzili | 0-0,8 m |
| GPS doğruluğu | 0,0025 m |
| En yüksek tekerlek hızı | 6,28 rad/s |
| Lidar | Katman başına 512 nokta, 4 katman, 0,01-1 m |

`timeStep`, sensör güncellemeleri arasındaki milisaniye sayısını belirler. `int(robot.getBasicTimeStep())` dünyanın temel zaman adımını verir; bu, Erebus v26.1 dünyalarında 16 ms'dir.

## Başlangıç robotunun cihaz adları {#device-names-of-the-starter-robot}

Bunlar, [başlangıç robotunda](/docs/robot/) `robot.getDevice()` fonksiyonuna verilecek adlardır. Kendi robotlarında adları [Robot Customizer](/docs/robot/customizer/#components) içinde sen seçersin. Verici (emitter) ve alıcı (receiver) her zaman vardır.

| Cihaz | Ad |
|---|---|
| Tekerlek motorları | `left wheel motor`, `right wheel motor` |
| Tekerlek enkoderleri | `left wheel sensor`, `right wheel sensor` |
| Mesafe sensörleri | `leftDist`, `frontDist`, `rightDist` |
| Kamera | `camera` |
| Renk sensörü | `color` |
| GPS | `gps` |
| Jiroskop | `gyro` |
| İvmeölçer | `accelerometer` |
| Lidar | `lidar` |
| Verici | `emitter` |
| Alıcı | `receiver` |
