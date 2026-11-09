---
title: v27'deki yenilikler
description: Erebus v27'deki ve 2027 kurallarındaki, robotunu etkileyen değişiklikler.
---

Erebus v27, 2027 kurallarını uygular. v26'dan geliyorsan robotunu etkileyen değişiklikler şunlardır.

| Konu | 2026'ya kadar | 2027'den itibaren |
|---|---|---|
| Batarya | - | Yeni: robotun, motorlarının hızına göre azalan bir [bataryası](/docs/rules/#the-battery) var. Biterse oyun sona erer. |
| Temas kareleri | - | Yeni: camgöbeği [temas kareleri](/docs/rules/#contact-tiles). Birinin üzerinde 5 saniye hareketsiz durmak bataryayı değiştirir. Haritada `k` ile gösterilir. |
| Bataklıklar | Oyun süresi daha hızlı akar: ilk girişte x5, en fazla x10 | Batarya daha hızlı azalır. Oyun süresi etkilenmez. |
| Kazazedeler | Φ, Ψ, Ω sembolleri | [Gülen yüzler](/docs/rules/#smiley-victims): üzgün (yaralı), nötr (stabil) ve mutlu (yarasız). Hâlâ `H`, `S`, `U` olarak bildirilir. |
| Sahte kazazedeler | Üç boyutlu semboller | Üç boyutlu gülen yüzler |
| Oyun bilgisi | `G` yanıtı 16 bayttır | `G` yanıtı 20 bayttır ve batarya seviyesiyle biter. Bkz. [Oyun bilgisi](/docs/programming/communication/#game-information). |
| Bildirim mesafesi | Erebus v26 işarete 9 cm'ye kadar olan bildirimleri kabul ediyordu | Kurallardaki gibi yarım kare (6 cm) |
| Alanlar | Dört alan, Alan 4 isteğe bağlı | En fazla dört alan: Alan 1 her zaman vardır, organizatörler Alan 2-4'ü koymayabilir |
| Webots | R2023b | **R2025a** |
| Python | 3.9 veya üstü | 3.10 veya üstü |

[İlk çalıştırman](/docs/getting-started/), Erebus v27 kontrol penceresinin nasıl kullanılacağını gösterir.

## Programını güncelleme {#updating-your-program}

1. `G` yanıtını 20 bayt olarak oku. Yalnızca 16 baytı kabul eden bir program artık oyun bilgisini alamaz.
1. Batarya seviyesini izle ve rotanı, robot batarya bitmeden bir temas karesine ulaşacak şekilde planla. Bkz. [Batarya](/docs/programming/battery/).
1. Temas karelerini haritana `k` olarak ekle.
1. Kazazede algılamanı gülen yüzlere göre güncelle. Bildirdiğin harfler değişmez.
1. İşaretleri daha yakından bildir: robotun merkezi ve gönderdiğin konum, işarete yarım kare mesafede olmalıdır.
1. Bataklıklar artık zaman yerine batarya harcatır; batarya planında bunları hesaba kat.
1. Webots R2025a ile Python 3.10 veya üstünü kur, ve programının hâlâ çalıştığını kontrol et. Bkz. [Kurulum](/docs/installation/).
