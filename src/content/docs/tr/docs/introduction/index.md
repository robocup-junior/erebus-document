---
title: Erebus nedir?
description: Erebus, RoboCupJunior'ın Webots üzerine kurulu kurtarma simülasyonu platformudur. Parçalarının nasıl bir araya geldiğini öğren.
---

Erebus bir robot simülasyonu yarışma ortamıdır. Bir labirenti kendi başına keşfeden, duvar işaretlerini (harf kazazedeler ve bilişsel hedefler) bulup tanıyan, engellerden ve tuzaklardan kaçınan ve ortamın haritasını çıkaran bir robot için denetleyici geliştirirsin.

Erebus, profesyonel kullanım için tasarlanmış ve endüstride, eğitimde ve araştırmada yaygın olarak kullanılan bir robot simülasyonu platformu olan [Webots](https://cyberbotics.com/) üzerine kuruludur. Cyberbotics, Webots'u 1998'den beri kesintisiz olarak geliştiriyor.

Platform öncelikle [RoboCupJunior Rescue Simulation](https://junior.robocup.org/rescue/) yarışması için tasarlandı. Orta seviyeden çok deneyimliye kadar programcılara yöneliktir.

## Parçalar nasıl bir araya gelir {#how-it-fits-together}

| Bileşen | Ne yapar | Nereden edinilir |
|---|---|---|
| **Webots R2023b** | 3B robot simülatörü | [Webots R2023b sürümü](https://github.com/cyberbotics/webots/releases/tag/R2023b) |
| **Erebus** | Dünyalar ve kuralları uygulayıp puanı hesaplayan oyun yöneticisi (Main Supervisor) | [Erebus sürümleri](https://github.com/robocup-junior/erebus/releases) |
| **Denetleyicin** | Robotunun Python ya da C/C++ ile yazılmış programı | Bunu sen yazarsın! |
| **Robot Customizer** | Özel bir robot tasarlayıp JSON dosyası olarak dışa aktarmak için web aracı | [robot.erebus.rcj.cloud](https://robot.erebus.rcj.cloud/) |
| **World Editor** | Alıştırma haritaları çizip `.wbt` dünyaları olarak dışa aktarmak için web aracı | [world.erebus.rcj.cloud](https://world.erebus.rcj.cloud/) |

## Onunla neler yapabilirsin? {#what-can-you-do-with-it}

1. **Bir robot yap.** Bir bütçe dahilinde sensörlerini ve nereye yerleşeceklerini seç.
2. **Onu programla.** Denetleyicin sensörleri okur ve hiçbir insan yardımı olmadan ne yapacağına karar verir.
3. **Onu çalıştır.** Hazır dünyalarda ya da kendi dünyalarında test et ve puanı izle.
4. **Yarış.** Yerel, bölgesel ve uluslararası RoboCupJunior yarışmalarına katıl.

Erebus'u zaten tanıyorsan [v26'daki yenilikler](/docs/whats-new/) sayfasına bak.

## Faydalı kaynaklar {#useful-references}
Erebus simülatörünü öğrenmek ve onunla çalışmak için faydalı bağlantılar:
- [Webots Kullanıcı Kılavuzu](https://cyberbotics.com/doc/guide/index?version=R2023b)
- [Webots Başvuru Kılavuzu](https://cyberbotics.com/doc/reference/nodes-and-api-functions?version=R2023b)
- [Python Belgeleri](https://www.python.org/doc/)
- [C++ Belgeleri](https://www.cplusplus.com/doc/tutorial/)
- [OpenCV Eğitimleri](https://docs.opencv.org/4.x/d9/df8/tutorial_root.html)
- [RCJ Rescue Topluluk Web Sitesi](https://rescue.rcj.cloud/): etkinlikler, takım belgeleri ve TDP, poster ve video değerlendirme ölçütleri
- [RoboCupJunior Forumu](https://junior.forum.robocup.org/): kural açıklamaları

## Sırada {#next}
[Erebus'u kur](/docs/installation/), sonra oyunu anlamak için [Kural özeti](/docs/rules/) sayfasını oku.
