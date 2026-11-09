---
title: Robotunu edin
description: Her program, senin tasarladığın bir robot üzerinde çalışır. Başlangıç robotunu indir ya da kendin yap.
---

Erebus'ta **robotunu sen tasarlarsın**: bir bütçe dahilinde sensörlerini ve nereye yerleşeceklerini seçersin. Her programın bir robota ihtiyacı vardır, bu yüzden ilk adım bir robot edinip onu Erebus'a yüklemektir.

![Gerçek bir e-puck robotu](../../../docs/robot/real_robot.thumbnail.jpg)

Robot, iki tekerlekli, küçük ve yuvarlak bir eğitim robotu olan [e-puck](https://cyberbotics.com/doc/guide/epuck?version=R2025a) temel alınarak yapılmıştır. [Robot Customizer](https://robot.erebus.rcj.cloud/) ile ona sensörler ekler ve tasarımı Erebus'un yüklediği bir `.json` dosyası olarak kaydedersin.

## Başlangıç robotu {#the-starter-robot}
Bu belgeler, her örnek olduğu gibi çalışsın diye her yerde tek bir robot kullanır: **başlangıç robotu** (starter robot). Bu robotta eğitimlerin ihtiyaç duyduğu tüm sensörler vardır:

| Bileşen | Programındaki adı | Ne işe yarar |
|---|---|---|
| İki tekerlek | `left wheel motor`, `right wheel motor` | Hareket etmek |
| Tekerlek enkoderleri | `left wheel sensor`, `right wheel sensor` | Tekerleklerin ne kadar döndüğünü ölçmek |
| Üç mesafe sensörü | `leftDist`, `frontDist`, `rightDist` | Solda, önde ve sağda duvarları bulmak |
| Kamera, 64 × 40 piksel | `camera` | Duvar işaretlerini bulmak |
| Renk sensörü | `color` | Zemini görmek: çukurlar, bataklıklar, temas kareleri ve geçitler |
| GPS | `gps` | İşaretleri bildirmek için konumunu bilmek |
| Jiroskop | `gyro` | Ne kadar döndüğünü ölçmek |
| İvmeölçer | `accelerometer` | İvmeyi ölçmek |
| Lidar | `lidar` | Çevresindeki mesafeleri ölçmek |
| Verici ve alıcı | `emitter`, `receiver` | Oyunla konuşmak. Her robotta bulunur. |

Robotun maliyeti, 3000'lik bütçenin 2400'üdür.

![Etiketleri ve kamera görünümüyle bitmiş robot](../../../docs/robot/build/finished.png)

## Yolunu seç {#choose-your-path}

**Önerilen: kendin yap.** Yaklaşık 15 dakika sürer ve robotunun her parçasını anlarsın. [Robotunu yap](/docs/robot/build/) sayfasını izle.

**Acelen varsa:** hazır robotu indir ve eğitimlere devam et. Daha sonra her zaman geri dönüp onu yapabilirsin.

<a href="/downloads/starter-robot.json" download>starter-robot.json dosyasını indir</a>

## Erebus'a yükle {#load-it-in-erebus}
1. `game/worlds/world1.wbt` gibi bir dünya aç.
2. Kontrol penceresinde **Robot setup** düğmesine, ardından **Robot JSON** altındaki **Load file** düğmesine bas ve `.json` dosyanı seç.
3. Webots konsolunu kontrol et. Erebus her bileşeni maliyetiyle listeler ve `Your custom robot has been successfully generated!` mesajı ile kullandığın bütçeyle bitirir.

Robot, başka bir robot yükleyene kadar yüklü kalır. Varsayılan olarak açık olan **Keep files after Reset** sayesinde oyunu sıfırladığında da yüklü kalır. Sırada [ilk programını çalıştırmak](/docs/getting-started/) var.

## Kendi robotunu tasarlama {#designing-your-own}
Temelleri öğrendikten sonra başlangıç robotunu değiştir ya da yeni bir robot tasarla: daha yüksek çözünürlüklü daha fazla kamera, daha fazla mesafe sensörü, başka yerlerde sensörler. [Robot Customizer başvurusu](/docs/robot/customizer/) tüm bileşenleri, maliyetlerini ve sınırlarını listeler.

Bir bileşenin adını değiştirirsen programında da değiştir.
