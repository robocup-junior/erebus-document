---
title: Mesaj başvurusu
description: Main Supervisor ile alınıp verilen mesajların başvurusu.
---

Mesajlar `emitter` cihazıyla gönderilir ve `receiver` cihazıyla alınır. Örnekler için [İletişim eğitimine](/docs/programming/communication/) bak.

Aşağıdaki biçim dizeleri Python'un [struct](https://docs.python.org/3/library/struct.html) modülüne aittir.

## Robotun gönderdikleri {#sent-by-the-robot}

| Mesaj | Biçim | Uzunluk | Amaç |
|---|---|---|---|
| Duvar işareti bildirme | `i i c`: x, z, tür | 9 bayt | Konum santimetre cinsindendir ve tür `H`, `S`, `U`, `F`, `P`, `C`, `O` değerlerinden biridir. Robot en az 1 saniye durmuş olmalıdır. |
| Harita verisi | `2i` ardından UTF-8 metin: satırlar, sütunlar, virgülle ayrılmış hücreler | Diğer herhangi bir uzunluk | Haritayı değerlendirmeden saklar |
| `M` | `c` | 1 bayt | Saklanan haritayı değerlendirir. Bu yalnızca bir kez yapılabilir. |
| `L` | `c` | 1 bayt | İlerleme eksikliği çağırır |
| `G` | `c` | 1 bayt | Oyun bilgilerini ister |
| `E` | `c` | 1 bayt | Oyunu bitirir. Robot başlangıç karesindeyse ve bir duvar işaretini tanımladıysa çıkış bonusu verir. |

Erebus bu mesajları uzunluklarına göre ayırt eder, bu yüzden bir bildirim tam olarak 9 bayt olmalıdır.

## Robotun aldıkları {#received-by-the-robot}

| Mesaj | Biçim | Uzunluk | Amaç |
|---|---|---|---|
| `L` | `c` | 1 bayt | Bir ilerleme eksikliği oldu |
| `G` | `c f i i f`: `G`, puan, kalan oyun süresi, kalan gerçek zaman, batarya seviyesi | 20 bayt | `G` yanıtı. Süreler saniye cinsindendir, batarya seviyesi 0 ile 100 arasında bir yüzdedir. |

`G` paketinin dolgu baytları içerdiğine dikkat et, çünkü yukarıdaki `struct` biçimi ondalıklı sayıyı hizalar: puan 4. bayttan, süreler 8. ve 12. baytlardan, batarya seviyesi ise 16. bayttan başlar.

## Sık kullanılan Webots fonksiyonları {#common-webots-functions}

| Fonksiyon | Açıklama |
|---|---|
| `robot.getDevice(name)` | Bir cihazı adıyla alır. C++'ta `robot->getMotor(name)`, `robot->getCamera(name)` vb. kullan. |
| `robot.step(timeStep)` | Simülasyonu ilerletir. Simülasyon bittiğinde -1 döndürür. |
| `robot.getTime()` | Simülasyon zamanını saniye cinsinden alır |
| `device.enable(timeStep)` | Bir sensörü etkinleştirir |
| `motor.setPosition(float("inf"))` | Motorun sınırsız dönmesini sağlar |
| `motor.setVelocity(speed)` | Bir motorun hızını radyan/saniye cinsinden ayarlar |
