---
title: World Editor
description: Erebus World Editor ile kendi dünyalarını nasıl oluşturacağın.
---

## Arka plan {#background}

Robotun Erebus'la gelen haritaları ve basit labirentleri aşabildiğinde daha zorlayıcı bir şey isteyebilir ya da hazır haritaların kapsamadığı belirli senaryoları test etmek isteyebilirsin.
Bunun için çevrim içi [Erebus World Editor](https://world.erebus.rcj.cloud/) var. Haritayı tarayıcında çizersin; editör de onu Erebus'ta çalıştırabileceğin bir `.wbt` dünya dosyası olarak dışa aktarır.

![World Editor'da bitmiş bir harita](../../../../docs/tools/world-editor/overview.png)

Yalnızca test için küçük haritalar yapıyorsan sahanın kurallara uyup uymadığı muhtemelen pek önemli değildir. Ama bir yarışma sahası yapmayı planlıyorsan resmî [Simülasyon Kurallarını](https://junior.robocup.org/wp-content/uploads/2026/09/RCJRescueSimulation2027-draft.pdf) oku. Editör, sen çalışırken haritanı kurallara göre kontrol eder.

Editörün yerleşik bir rehberi var: örnek bir harita yapan uygulamalı bir ders (yaklaşık 15 dakika), ekranın tanıtımı ya da Room 4 (4. oda) hakkında bir ders için sağ alttaki **Guide** düğmesine bas. Editörün dili hemen yanından değiştirilebilir.

## Harita başlatma {#starting-a-map}
Düzenleyiciyi açtığında **hangi yılın kurallarını** izleyeceğini seç ve **New map** düğmesine bas. **Erebus v27 için 2027 kurallarını seç.** 2026 kuralları Erebus v26 içindir. Bir haritanın kurallarını daha sonra üst çubuktan değiştirebilirsin.

![World Editor'ın başlangıç ekranı](../../../../docs/tools/world-editor/start.png)

Çalışman tarayıcıda saklanır, ama başka bir tarayıcıda açıldığında ya da tarama verileri temizlendiğinde kaybolur. Önemli haritaları üst çubuktaki kaydet düğmesiyle JSON olarak kaydet ve aç düğmesiyle yeniden aç.

Çalışmak için iyi bir sıra şöyledir: boyut ve dış hat, odalar, geçitler, duvarlar, zeminler, engeller ve kazazedeler, Room 4 ve son olarak kontroller ile dışa aktarma. Araçlar soldadır ve her birinin bir klavye kısayolu vardır. Seçili aracın ayarları, araçların yanındaki panelde görünür.

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
| Floor | `F` | Kontrol noktalarını, çukurları, bataklıkları, temas karelerini ve başlangıç karesini belirle |
| Obstacle | `O` | Engel yerleştir |
| Victims | `V` | Gülen yüz kazazedeleri, bilişsel hedefleri ve sahteleri yerleştir |

Fare tekerleği yakınlaştırır, Space tuşu basılıyken sürüklemek görünümü taşır; geri alma kısayolu ise `⌘Z` ya da `Ctrl+Z`'dir.

## Boyut ve dış hat {#size-and-outline}
**Outline** aracıyla haritanın boyutunu kare cinsinden belirle. Dış duvarlar otomatik olarak eklenir. **Outline (uneven)** ile kareleri tıklayarak haritadan çıkarabilir, ayrıca tıkladığın yere satır ve sütun ekleyip kaldırabilirsin.

![Outline aracı](../../../../docs/tools/world-editor/outline.png)

## Odalar ve geçitler {#rooms-and-passages}
**Rooms** aracıyla her odanın karelerini boya. Odalar arasındaki sınırlara duvarlar otomatik olarak eklenir. Sonra **Passages** aracıyla odaları birleştir: her geçidin rengi, bağladığı odalara göre seçilir.

![Rooms aracı](../../../../docs/tools/world-editor/rooms.png)

![Passages aracı](../../../../docs/tools/world-editor/passages.png)

## Duvarlar {#walls}
Duvar çizmek için **Line** aracını kullan: 1. odada kare kenarlarına, 2. ve 3. odalarda çeyrek karelere çizilir. 3. odada **Curve** aracını kullan; kavisi seçmek için bir karenin bir çeyreğini işaret et. Aynı kavise tekrar tıklarsan kavis kaldırılır.

![Duvarlar için Line aracı](../../../../docs/tools/world-editor/walls.png)

## Zeminler ve engeller {#floors-and-obstacles}
**Floor** aracıyla bir zemin türü seç ve ayarlamak için bir kareye tıkla: kontrol noktası, çukur, bataklık, temas karesi veya başlangıç. Başlangıç karesi Oda 1'de olmalıdır ve o olmadan dünya dışa aktarılamaz. Bir kare yalnızca çukur, bataklık, kontrol noktası, temas karesi, engel, başlangıç veya geçitten biri olabilir.

![Floor aracı](../../../../docs/tools/world-editor/floors.png)

**Obstacle** aracıyla bir şekil seç ve bir kareye tıkla. 1-3 numaralı odalarda her karede bir engel olabilir ve engelin merkezi karenin üzerindedir. Bir engelin boyutunu, yüksekliğini, rengini ve dönüşünü değiştirmek için ona tıkla, sonra tutamaçlarını ve paneli kullan.

![Obstacle aracı](../../../../docs/tools/world-editor/obstacles.png)

## Kazazedeler ve bilişsel hedefler {#victims-and-cognitive-targets}
**Victims** aracıyla bir tür seç ve bir duvarın yakınına tıkla. Şunları yerleştirebilirsin:

- Gerçek gülen yüz kazazedeler: yaralı, stabil ve yarasız
- Üç boyutlu yüzleri olan sahte gülen yüz kazazedeler
- Bilişsel hedefler: tehlikeli madde türünü seç, istersen halkaların renklerini de seç. Toplam gösterilir ve türü o belirler
- Halkalarının toplamı 0 ile 3 dışında bir değer olan sahte hedefler

İlk odada (Room 1) her kare kenarında bir kazazede olabilir. 2. ve 3. odalarda kazazedeler 6 cm'lik duvarların yüzlerine yerleşir; kavislerde ise iç ve dış olmak üzere iki yer vardır. **Turn** altında sabit bir dönüş ya da her yeni işaret için rastgele bir dönüş seç. Yerleştirilmiş bir işareti değiştirmek ya da kaldırmak için ona tıkla veya duvarı boyunca sürükle.

![Victims aracı](../../../../docs/tools/world-editor/victims.png)

## Room 4 {#room-4}
Room 4 (4. oda) karelere dayanmaz, bu yüzden bir resim olarak çizilir. **Rooms** aracıyla Room 4'ü boya ve Room 4 oluşturucusunu açmak için **Draw room 4** düğmesine bas (ya da odaya çift tıkla).

![Room 4 oluşturucusu](../../../../docs/tools/world-editor/room4.png)

Siyahla çizdiğin her şey duvar olur. Oluşturucuda serbest çizim ve çizgi, kavis, yay, dikdörtgen, elips, çokgen ve simgelerden şekil çizme araçlarının yanı sıra kazazedeler ve engeller için araçlar vardır. Room 4'e istediğin kadar engel yerleştirebilirsin. Kırmızı çizgiler robotun gidemeyeceği yerleri gösterir; robotun geçebilmesi için yaklaşık bir kare genişliğinde bir yol bırakmalısın.

Bitirdiğinde **OK** düğmesine bas: resim haritada Room 4 olarak görünür ve dışa aktarılan dünyaya eklenir. Oluşturucunun sağ üstündeki düğmeler, aynı Room 4'ü başka bir haritada kullanabilmen için resmi PNG olarak kaydeder ve PNG ya da JPEG resimleri açar.

## Haritanı kontrol etme {#checking-your-map}
Her değişiklik, sağ üstteki **Checks** kartında kurallara göre kontrol edilir. Kırmızı bir ✕, dünyanın dışa aktarılmasını engelleyen bir sorundur; sarı bir ! ise göz atmaya değer bir uyarıdır. Bir öğeye gitmek için ona tıkla. **Fix** bir öğeyi düzeltir, **Fix all that can be fixed** ise düzeltilebilen her şeyi düzeltir.

![Checks kartıyla World Editor'da yeni bir harita](../../../../docs/tools/world-editor/new_map.png)

Üst çubuktaki **Linear** düğmesi her kareyi doğrusal ya da yüzen olarak renklendirir; bu da işaretlerin değerini belirler.

![Haritada gösterilen doğrusal ve yüzen kareler](../../../../docs/tools/world-editor/linear.png)

Üst çubuktaki kupa; puanlama kurallarıyla hesaplanan **maksimum puanı**, her odanın bu puandaki payını ve çıkış ile haritalama bonuslarıyla birlikte elde edilecek puanı gösterir.

![Haritanın maksimum puanı](../../../../docs/tools/world-editor/max_score.png)

## Dünyanı dışa aktarma ve çalıştırma {#exporting-and-running-your-world}
Üst çubukta haritanın adını belirle ve sağ üstteki **.wbt** düğmesine bas. Sonra:

1. `.wbt` dosyasını Erebus'un `game/worlds` klasörüne kopyala. Dünya Erebus'taki dosyaları kullandığı için dosya o klasörde olmalıdır.
1. Onu Webots'ta aç ya da [kontrol penceresinin](/docs/getting-started/) **Worlds** düğmesiyle seç.

![Editör rehberindeki örnek harita, Erebus v27'de çalışırken.](../../../../docs/tools/world-editor/exported_world.png)

*Editör rehberindeki örnek harita, Erebus v27'de çalışırken.*

Bir `.wbt` dosyası düzenlenebilir bir haritaya geri dönüştürülemez, bu yüzden JSON dosyasını da sakla.
