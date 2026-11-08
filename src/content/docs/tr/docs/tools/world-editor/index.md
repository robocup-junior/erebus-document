---
title: World Editor
description: Erebus World Editor ile kendi dünyalarını nasıl oluşturursun.
---

## Arka plan {#background}

Test haritalarını fethettikten ve robotun basit labirentlerde çalışabildikten sonra belki daha zorlayıcı bir şey istersin ya da haritalarımızın sunmadığı belirli senaryoları test etmek istersin.
Bunun için çevrim içi [Erebus World Editor](https://world.erebus.rcj.cloud/) aracı var. Tarayıcında bir harita çizersin ve araç, Erebus'ta çalıştırabileceğin bir `.wbt` dünya dosyası dışa aktarır.

![World Editor'da bitmiş bir harita](../../../../docs/tools/world-editor/overview.png)

Yalnızca test için küçük haritalar yapıyorsan sahanın kurallara uygunluğu muhtemelen senin için çok önemli değildir. Ama bir yarışma sahası yapmayı planlıyorsan resmî [Simülasyon Kurallarını](https://junior.robocup.org/wp-content/uploads/2026/02/RCJRescueSimulation2026-final.pdf) baştan sona okumalısın. Düzenleyici, sen çalışırken haritanı kurallara göre kontrol eder.

Düzenleyicinin yerleşik bir rehberi var: örnek bir harita yapan uygulamalı bir ders (yaklaşık 15 dakika), ekranın tanıtımı ya da Room 4 (4. oda) hakkında bir ders için sağ alttaki **Guide** düğmesine bas. Düzenleyicinin dili hemen yanından değiştirilebilir.

## Harita başlatma {#starting-a-map}
Düzenleyiciyi açtığında **hangi yılın kurallarını** izlemek istediğini seç ve **New map** düğmesine bas. **Erebus v26 için 2026 kurallarını seç.** 2027 kuralları, Erebus'un bir sonraki sürümü için bir taslaktır.

![World Editor'ın başlangıç ekranı](../../../../docs/tools/world-editor/start.png)

Çalışman tarayıcıda saklanır, ama başka bir tarayıcıda ya da tarama verileri temizlendiğinde kaybolur. Önemli haritaları üst çubuktaki kaydet düğmesiyle JSON olarak kaydet ve aç düğmesiyle yeniden aç.

Çalışmak için iyi bir sıra şudur: boyut ve dış hat, odalar, geçitler, duvarlar, zeminler, engeller ve kazazedeler, Room 4 ve son olarak kontroller ve dışa aktarma. Araçlar solda bulunur ve her birinin bir klavye kısayolu vardır. Seçili aracın ayarları yanlarındaki panelde görünür.

| Araç | Tuş | Kullanım |
|---|---|---|
| Select | `S` | Haritanın parçalarını seç, taşı, kopyala ve yapıştır |
| Move | `H` | Görünümü taşı |
| Outline | `X` | Haritanın boyutunu ve şeklini belirle |
| Rooms | `M` | 1-4 numaralı odaları (kurallardaki alanlar) boya |
| Passages | `P` | Odaları bir geçitle birleştir |
| Line | `L` | Duvar çiz |
| Curve | `A` | 3. odada kavisli duvarlar çiz |
| Eraser | `E` | Duvarları, zeminleri, engelleri ve kazazedeleri kaldır |
| Floor | `F` | Kontrol noktalarını, çukurları, bataklıkları ve başlangıç karesini belirle |
| Obstacle | `O` | Engel yerleştir |
| Victims | `V` | Harf kazazedeleri, bilişsel hedefleri ve sahteleri yerleştir |

Fare tekerleği yakınlaştırır, Space basılıyken sürüklemek görünümü taşır, geri alma ise `⌘Z` ya da `Ctrl+Z`'dir.

## Boyut ve dış hat {#size-and-outline}
**Outline** aracıyla haritanın boyutunu kare cinsinden belirle. Dış duvarlar kendiliğinden gelir. **Outline (uneven)**, kareleri haritadan çıkarmak için onlara tıklamanı sağlar; tıkladığın yere satır ve sütun ekleyip kaldırabilirsin de.

![Outline aracı](../../../../docs/tools/world-editor/outline.png)

## Odalar ve geçitler {#rooms-and-passages}
**Rooms** aracıyla her odanın karelerini boya. Odalar arasındaki sınırlara duvarlar kendiliğinden yerleşir. Sonra **Passages** aracıyla odaları birleştir: her geçidin rengi, bağladığı odalara göre seçilir.

![Rooms aracı](../../../../docs/tools/world-editor/rooms.png)

![Passages aracı](../../../../docs/tools/world-editor/passages.png)

## Duvarlar {#walls}
Duvar çizmek için **Line** aracını kullan: 1. odada kare kenarlarına, 2. ve 3. odalarda çeyrek karelere. 3. odada **Curve** aracını kullan; kavisi seçmek için bir karenin çeyreğini işaret et. Aynı kavise tekrar tıklamak onu kaldırır.

![Duvarlar için Line aracı](../../../../docs/tools/world-editor/walls.png)

## Zeminler ve engeller {#floors-and-obstacles}
**Floor** aracıyla bir zemin türü seç ve ayarlamak için bir kareye tıkla. Başlangıç karesi 1. odadaki bir kare olmalıdır ve o olmadan dünya dışa aktarılamaz. Bir kare yalnızca çukur, bataklık, kontrol noktası, engel, başlangıç ya da geçitten biri olabilir.

![Floor aracı](../../../../docs/tools/world-editor/floors.png)

**Obstacle** aracıyla bir şekil seç ve bir kareye tıkla. 1-3 numaralı odalarda her karede, merkezi kare üzerinde olan bir engel bulunur. Bir engelin boyutunu, yüksekliğini, rengini ve dönüşünü tutamaçları ve panel ile değiştirmek için ona tıkla.

![Obstacle aracı](../../../../docs/tools/world-editor/obstacles.png)

## Kazazedeler ve bilişsel hedefler {#victims-and-cognitive-targets}
**Victims** aracıyla bir tür seç ve bir duvarın yakınına tıkla. Şunları yerleştirebilirsin:

- Gerçek harf kazazedeler: yaralı, stabil ve yarasız
- Üç boyutlu sembollü sahte harf kazazedeler
- Bilişsel hedefler: tehlikeli madde türünü seç, istersen halkaların renklerini de seç. Toplam gösterilir ve türü o belirler
- Halkalarının toplamı 0 ile 3 dışında bir değer olan sahte hedefler

1. odada her kare kenarında bir kazazede olabilir. 2. ve 3. odalarda kazazedeler 6 cm'lik duvarların yüzlerine yerleşir; kavislerde ise iç ve dış olmak üzere iki yer vardır. **Turn** altında sabit bir dönüş ya da her yeni işaret için rastgele bir dönüş seç. Yerleştirilmiş bir işareti değiştirmek ya da kaldırmak için ona tıkla veya duvarı boyunca sürükle.

![Victims aracı](../../../../docs/tools/world-editor/victims.png)

## Room 4 {#room-4}
Room 4 (4. oda) karelere dayanmaz, bu yüzden bir resim olarak çizilir. **Rooms** aracıyla Room 4'ü boya ve Room 4 oluşturucusunu açmak için **Draw room 4** düğmesine bas (ya da odaya çift tıkla).

![Room 4 oluşturucusu](../../../../docs/tools/world-editor/room4.png)

Siyahla çizdiğin her şey duvar olur. Oluşturucuda serbest çizim ve çizgi, kavis, yay, dikdörtgen, elips, çokgen ve simgelerden şekil çizme araçları ile kazazedeler ve engeller için araçlar vardır. Room 4'e istediğin kadar engel yerleştirilebilir. Kırmızı çizgiler robotun ulaşamayacağı yerleri gösterir; robotun geçebilmesi için yaklaşık bir kare genişliğinde yer bırakmalısın.

Bitirdiğinde **OK** düğmesine bas: resim haritada Room 4 olarak görünür ve dışa aktarılan dünyaya eklenir. Oluşturucunun sağ üstündeki düğmeler, aynı Room 4'ü başka bir haritada kullanabilmen için resmi PNG olarak kaydeder ve PNG ya da JPEG resimleri açar.

## Haritanı kontrol etme {#checking-your-map}
Her değişiklik, sağ üstteki **Checks** kartında kurallara göre kontrol edilir. Kırmızı bir ✕, dünyanın dışa aktarılmasını engelleyen bir sorundur; sarı bir ! ise göz atmaya değer bir uyarıdır. Bir öğeye gitmek için ona tıkla. **Fix** bir öğeyi düzeltir, **Fix all that can be fixed** ise düzeltilebilen her şeyi düzeltir.

![Checks kartıyla World Editor'da yeni bir harita](../../../../docs/tools/world-editor/new_map.png)

Üst çubuktaki **Linear** düğmesi her kareyi doğrusal ya da yüzen olarak renklendirir; bu da işaretlerin değerini belirler.

![Haritada gösterilen doğrusal ve yüzen kareler](../../../../docs/tools/world-editor/linear.png)

Üst çubuktaki kupa, haritanın puanlama kurallarıyla hesaplanan **maksimum puanını**, her odanın payını ve çıkış ile harita bonuslarıyla birlikte puanı gösterir.

![Haritanın maksimum puanı](../../../../docs/tools/world-editor/max_score.png)

## Dünyanı dışa aktarma ve çalıştırma {#exporting-and-running-your-world}
Üst çubukta haritanın adını belirle ve sağ üstteki **.wbt** düğmesine bas. Sonra:

1. `.wbt` dosyasını Erebus'un `game/worlds` klasörüne kopyala. Dünya Erebus'taki dosyaları kullandığı için dosya o klasörde olmalıdır.
1. Onu Webots'ta aç ya da [kontrol penceresinin](/docs/getting-started/) **Worlds** düğmesiyle seç.

![Düzenleyici rehberindeki örnek harita, Erebus v26.1'de çalışırken.](../../../../docs/tools/world-editor/exported_world.png)

*Düzenleyici rehberindeki örnek harita, Erebus v26.1'de çalışırken.*

Bir `.wbt` dosyası düzenlenebilir bir haritaya geri dönüştürülemez, bu yüzden JSON dosyasını da sakla.
