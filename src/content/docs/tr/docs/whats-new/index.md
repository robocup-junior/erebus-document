---
title: v26'daki yenilikler
description: Erebus v26'daki ve 2026 kurallarındaki, robotunu etkileyen değişiklikler.
---

Erebus v26, 2026 kurallarını uygular. Daha eski bir sürümden geliyorsan robotunu etkileyen değişiklikler şunlardır.

| Konu | 2025'e kadar | 2026'dan itibaren |
|---|---|---|
| Harf kazazedeler | H, S, U harfleri | Φ (yaralı), Ψ (stabil), Ω (yarasız) sembolleri. Hâlâ `H`, `S`, `U` olarak bildirilirler. |
| Tehlikeli madde işaretleri (hazmat signs) | Dört tehlikeli madde etiketi | Yerlerini [bilişsel hedefler](/docs/rules/#cognitive-targets) aldı: değerlerinin toplamı türü veren, eş merkezli renkli halkalar. Hâlâ `F`, `P`, `C`, `O` olarak bildirilirler. |
| Sahte işaretler | - | Yeni: üç boyutlu harfli [sahte kazazedeler](/docs/rules/#fake-victims) ve toplamı 0 ile 3 arasında olmayan bilişsel hedefler. Bunları bildirme ve haritaya ekleme. |
| Bataklıklar | Süre 5 kat hızlı akar | Bir bataklığa ilk girişte çarpan x5'tir; aynı bataklığa her yeni girişte 1 artar, en fazla x10 olur. |
| Haritadaki engeller | Haritaya eklenmez | Engel bulunan kareler haritada `x` olarak işaretlenir. |
| Haritalama bonusu | En fazla x2 | Çarpan artık doğruluk × 1,2 + 1. |
| Sensör gürültüsü | - | GPS'te gürültü var. Organizatörler yarışma için gürültü seviyelerini değiştirmez. |
| Oyunların yürütülmesi | Her etkinlik için duyurulur | Sunucu-istemci kurulumu: denetleyicin kendi bilgisayarında çalışır ve oyun sunucusuna Ethernet ile bağlanır. [Remote Controller](/docs/competition/remote-controller/) sayfasına bak. |
| Belgeler | TDP, poster, video | Bunlara ek olarak, denetleyicini sunucu-istemci kurulumunda nasıl çalıştırdığını gösteren kısa bir video. |
| Kaçırılan oyunlar | -50 puan | 0 puan. |

Webots sürümü değişmedi: Erebus v26 hâlâ Webots **R2023b** üzerinde çalışır.

v26.0.0'dan sonra yayımlanan iki sürüm kuralları değiştirmez. v26.0.1, sahte kazazedeler içeren örnek dünyalar ve mevcut bir dünyadaki kazazedeleri sahteye dönüştüren bir betik ekler. v26.1 ise 4. alandaki engellerin işaretlenme şeklini düzeltir.

## Programını güncelleme {#updating-your-program}

1. Kazazede tespitini yeni sembollere göre güncelle. Bildirdiğin harfler değişmez.
2. Tehlikeli madde tespitini [bilişsel hedef okuma](/docs/programming/wall-tokens/#reading-a-cognitive-target) ile değiştir.
3. Programının sahteleri bildirmediğinden ve onları haritaya eklemediğinden emin ol.
4. Engelleri haritana `x` olarak ekle.
5. Rotanı yeni bataklıkları göz önünde bulundurarak planla: robot aynı bataklığa her girdiğinde daha fazla zaman kaybeder.
6. [Sunucu-istemci kurulumu](/docs/competition/remote-controller/) ile pratik yap.
