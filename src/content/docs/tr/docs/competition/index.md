---
title: Yarışmaya hazırlanma
description: Bir RoboCupJunior Rescue Simulation yarışmasına hazırlanmak için bir kontrol listesi.
---

Bu sayfa, 2026 kurallarına göre uluslararası yarışma için bir kılavuzdur. Yerel ve bölgesel yarışmalar farklı olabilir, bu yüzden organizatörüne danış. Resmî [kurallar](/docs/rules/) her zaman geçerlidir.

## Zaman çizelgesi {#timeline}

| Ne zaman | Ne |
|---|---|
| Yıl boyunca | [Etkinlik sayfasını](/docs/events/upcoming-events/) ve kural açıklamalarının yayımlandığı [forumu](https://junior.forum.robocup.org/) takip et |
| En az 4 hafta önce | Organizatörler, mülakatlara hazırlık için doldurulacak web formuyla ilgili talimatları verir |
| İlk günden 3 hafta önce | Belgeler için son tarih |
| Kurulum günü | Kayıt, mülakatlar ve takım toplantıları için mekâna erken git |
| Her tur | Dünyalar oyunlardan hemen önce açıklanır. Her turun son tarihinden sonra programlar değiştirilemez. |
| Puanlama turlarından sonra | Technical Challenge (Teknik Görev) |

## Gönderilecek belgeler {#documents-to-submit}
Şablonlar ve değerlendirme ölçütleri [RCJ Rescue Topluluk Web Sitesinde](https://rescue.rcj.cloud/) bulunur.

- [ ] **Technical Description Paper (TDP).** Şablona harfiyen uy: aksi halde belgenin puanı 0 olur.
- [ ] **Poster:** hem dosya olarak hem de mekânda en fazla A1 boyutunda basılı poster olarak.
- [ ] Projeni tanıtan bir **video**.
- [ ] **Sunucu-istemci videosu** (2026'da yeni): denetleyicini sunucu-istemci kurulumunda örnek bir harita üzerinde nasıl çalıştırdığını gösteren kısa bir video.
- [ ] Mülakatlar için **kaynak kod** ve **web formu**.

## Yarışma kurulumu {#competition-setup}
Oyunlar sunucu-istemci kurulumuyla yürütülür: organizatörler oyun sunucusunu çalıştırır ve bir RJ-45 soketi sağlar; programın ise kendi bilgisayarında çalışır. [Remote Controller](/docs/competition/remote-controller/) sayfasına bak.

Yanında getirmen gerekenler:

- [ ] Programının, programının ihtiyaç duyduğu tüm kütüphanelerin ve Webots R2023b'nin kurulu olduğu bir bilgisayar
- [ ] Bir Ethernet kablosu ve bilgisayarın gerektiriyorsa bir adaptör
- [ ] Özel bir robotun varsa robotunun `.json` dosyası
- [ ] Basılı poster

## OpenGL ayarları {#opengl-settings}
Organizatörler aksini duyurmadıkça aşağıdaki ayarlar kullanılır. Kameraların gördüklerini etkiledikleri için bu ayarlarla test et. Bunları Webots tercihlerinin (Preferences) OpenGL sekmesinde bulabilirsin.

| Ayar | Değer |
|---|---|
| Ambient Occlusion | Low |
| Texture Quality | Low |
| Max Texture Filtering | 4 |
| Shadows | Disabled |
| Anti-aliasing | Disabled |

## Robotunu test etme {#testing-your-robot}
- [ ] Programını Erebus'la gelen her dünyada, özellikle sahte işaretler içeren `world3.wbt` ve `world4.wbt` üzerinde çalıştır.
- [ ] [World Editor](/docs/tools/world-editor/) ile dört alanın tamamını içeren kendi haritalarını yap.
- [ ] Oyunun tamamını kontrol et: sonuna kadar çalışıyor, haritayı gönderiyor ve zamanında başlangıca dönüyor mu?
- [ ] Bir ilerleme eksikliğinden sonra ne olduğunu test et.
- [ ] Yanında getireceğin bilgisayarda ve yukarıdaki OpenGL ayarlarıyla test et.

## Yarışma sırasında {#during-the-competition}
- Bir hakem aksini söylemedikçe yarışma alanına yalnızca kaptan ve yardımcı kaptan girebilir.
- Simülasyonu hakem çalıştırır. Oyun başladıktan sonra oyun ekipmanına dokunamazsın.
- Mentorlar yarışma sırasında yardım edemez.
- Çalışmanı açıklamaya hazır ol: her takım üyesinin teknik bir rolü olmalı ve üstlendiği kısmın nasıl çalıştığını bilmelidir.

## Final puanı {#final-score}
Uluslararası yarışmalarda final puanı şunları birleştirir:

| Bölüm | Ağırlık | İçerik |
|---|---|---|
| Saha puanı | 0,6 | Normalleştirilmiş saha puanlarının ortalaması. En kötü tur ya da turlar hesaba katılmaz. |
| Değerlendirme ölçütleri | 0,2 | TDP (0,6), video (0,2), poster (0,2) |
| Technical Challenge | 0,2 | Yarışmada duyurulan ve robotunu sınırlı sürede yeniden programlayarak çözdüğün mini görevler |

Eşitlikler normalleştirilmiş saha puanlarının ortalamasına göre çözülür. SuperTeam Challenge, kendi ödülü olan ayrı bir etkinliktir.
