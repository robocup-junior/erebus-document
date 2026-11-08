---
title: Kural özeti
description: "RoboCupJunior Rescue Simulation 2026 kurallarının özeti: saha, duvar işaretleri, puanlama ve yarışma."
---

:::note
Bu sayfa, başlamana yardımcı olacak bir özettir. Tek resmî kurallar [RoboCupJunior Rescue Simulation Rules 2026](https://junior.robocup.org/wp-content/uploads/2026/02/RCJRescueSimulation2026-final.pdf) belgesidir (son güncelleme 2026-02-11). Bu sayfa ile resmî kurallar farklıysa resmî kurallar geçerlidir.

Düzeltmeler ve açıklamalar [resmî RoboCupJunior Forumu](https://junior.forum.robocup.org/) üzerinde yayımlanır. Bunları kontrol etmek her takımın sorumluluğundadır.
:::

## Bir dakikada oyun {#the-game-in-one-minute}
Robotun, bilinmeyen bir labirente tek başına bırakılır. 8 dakika içinde, senden hiçbir yardım almadan şunları yapmalıdır:

1. Sıkışmadan ya da çukurlara düşmeden labirenti **keşfetmek**.
2. Duvarlardaki **duvar işaretlerini** (wall tokens), yani kazazedeleri ve tehlike işaretlerini (hazard signs) **bulmak** ve her birinin ne olduğunu bildirmek.
3. Labirentin **haritasını çıkarmak** ve sonunda haritayı göndermek.
4. Başladığı yere **geri dönmek**.

Aşağıdaki her şey bu dört işi ayrıntılı olarak açıklar. Şimdi hepsini hatırlaman gerekmiyor: her bölümü programlarken buraya geri dön.

## Görev ve amaç {#mission-and-objective}
![Dört alanlı bir Erebus sahasının üstten görünümü](../../../docs/rules/rules_environment.png)

Robot, başını belaya sokmadan bilinmeyen bir ortamı kendi başına keşfetmelidir. Üç ana görev vardır:

- Sıkışmadan karmaşık bir labirentte yol bulmak
- Ortamın haritasını doğru şekilde çıkarmak
- Duvar işaretlerini bulmak ve tanımlamak: harf kazazedeler (Letter victims) ve bilişsel hedefler (Cognitive targets)

## Saha {#the-field}
Saha dört alana (area) bölünebilir ve alanlar arasındaki her geçit bir standart kare genişliğindedir. Kareler (tiles) sahayı oluşturmak için kullanılan bir kavramdır, fiziksel yapılar değildir.

- Bir kare **12 cm × 12 cm**'dir. 2. ve 3. alanlarda her kare 6 cm × 6 cm'lik dört **çeyrek kareye** (quarter tiles) bölünür.
- Duvarlar **1 cm kalınlığında ve 6 cm yüksekliğindedir**.
- Yollar en az robot kadar geniştir ve daha geniş salonlara açılabilir.

![1., 2. ve 3. alanların duvar düzenlerine örnekler](../../../docs/rules/rules_tiles.png)

| Alan | Duvarlar | Notlar |
|---|---|---|
| 1. alan | Her karenin kenarlarına yerleştirilebilir | Başlangıç karesi bu alandadır |
| 2. alan | Her çeyrek karenin kenarlarına yerleştirilebilir | |
| 3. alan | Her çeyrek karenin kenarlarına yerleştirilebilir | 90°'lik köşeler çeyrek daire şeklinde yuvarlatılabilir |
| 4. alan (isteğe bağlı) | Karelere dayanmaz; duvarlar ve engeller rastgele yerleştirilir | Kutu gibi nesneler içerebilir ve çapraz hareket gerektirebilir |

### Alanlar arasındaki geçitler {#passages-between-areas}
Geçitler, belirgin bir girişleri ve çıkışları olması için iki yanında duvar bulunan tek karelerdir. Zemin renkleri hangi alanları bağladıklarını gösterir:

![Her alan çifti arasındaki geçit renklerinin tablosu](../../../docs/rules/rules_passages.png)

Geçitlere harf kazazede yerleştirilmez.

### Doğrusal ve yüzen kareler {#linear-and-floating-tiles}
En soldaki ya da en sağdaki duvar sürekli izlenerek başlangıç karesine götüren kareler **doğrusal karelerdir** (linear tiles). Diğerlerinin hepsi **yüzen karelerdir** (floating tiles). Yüzen karelerdeki işaretler daha fazla puan değerindedir. Burada çeyrek kareler hesaba katılmaz ve siyah çukurlar sanal duvar sayılır.

![Doğrusal karelerin gri, yüzen karelerin pembe gösterildiği bir saha](../../../docs/rules/rules_linear_floating.png)

### Kontrol noktaları {#checkpoints}
Gümüş renkli kareler kontrol noktalarıdır (Checkpoint) ve sahanın herhangi bir yerine yerleştirilebilirler. 4. alanda geçitlerin hemen ardından kontrol noktaları bulunur. Bir ilerleme eksikliğinden sonra robot ziyaret ettiği son kontrol noktasından yeniden başlar.

## Bataklıklar, engeller ve çukurlar {#swamps-obstacles-and-holes}
![Bataklık, çukur ve engel içeren bir saha](../../../docs/rules/rules_obstacles.png)

* **Bataklıklar** (Swamp, kahverengi kareler), robot üzerlerindeyken oyun süresinin daha hızlı akmasını sağlar. Robot bir bataklığa ilk kez girdiğinde süre 5 kat hızlı akar. Aynı bataklığa her yeni giriş bir kat daha ekler, x10 sınırına kadar.
* **Engeller** zemine sabitlenmiş olabilir, herhangi bir şekil ve renkte olabilir ve yolun genişliğini etkiler. 1-3. alanlarda bir engelin merkezi her zaman bir karenin üzerindedir, asla kareler arasındaki kenarda değildir ve her karede en fazla bir engel bulunur.
* **Çukurların** siyah kenarları vardır. Robot birine düşerse bir ilerleme eksikliği olur.

Hiçbir kare aynı anda şunlardan birden fazlası olamaz: bataklık, çukur, kontrol noktası, başlangıç karesi, engelli kare ya da alan geçidi.

## Duvar işaretleri {#wall-tokens}
İki tür duvar işareti vardır: harf kazazedeler ve bilişsel hedefler. İkisi de kavisli yüzeyler dahil herhangi bir duvarda görünebilir. Harf kazazedeler ayrıca herhangi bir açıyla döndürülmüş olabilir.

![Bir sahanın duvarlarındaki bilişsel hedefler ve harf kazazedeler](../../../docs/rules/rules_wall_tokens.png)

### Harf kazazedeler {#letter-victims}
Harf kazazedeler (Letter victims) 2 cm × 2 cm'lik resimlerdir. Sembol kazazedenin sağlık durumunu temsil eder; parantez içindeki harf ise bildirdiğin ve haritaya yazdığın koddur.

| Durum | Sembol | Kod |
|---|---|---|
| Yaralı (Harmed) | Φ | `H` |
| Stabil (Stable) | Ψ | `S` |
| Yarasız (Unharmed) | Ω | `U` |

![Fi, psi ve omega sembolleri](../../../docs/rules/rules_victims.png)

### Sahte kazazedeler {#fake-victims}
Bazı duvar işaretleri aynı sembolleri gösterir, ama harfleri **üç boyutludur**. Bunlar sahtedir (Fake victims): onları denetçiye (supervisor) bildirmemeli ve haritaya eklememelisin. Kurallar, bu derinliğin Robot Customizer'daki sensörlerden biriyle tespit edilebileceğini belirtir.

![Bir duvarda üç boyutlu sembollü sahte kazazedeler](../../../docs/rules/rules_fake_victims.png)

### Bilişsel hedefler {#cognitive-targets}
Bilişsel hedefler (Cognitive targets) tehlikeli maddeleri (hazmat) temsil eder. 5 cm çapında, çapları 1, 2, 3, 4 ve 5 cm olan beş eş merkezli parçadan oluşan dairelerdir. Her rengin bir değeri vardır:

| Siyah | Kırmızı | Sarı | Yeşil | Mavi |
|---|---|---|---|---|
| -2 | -1 | 0 | 1 | 2 |

Türü bulmak için beş parçanın değerlerini topla. Toplam aşağıda listelenmemişse hedef sahtedir; bildirilmemeli ve haritaya eklenmemelidir.

| Toplam | Tehlikeli madde | Kod |
|---|---|---|
| 0 | Yanıcı Gaz (Flammable Gas) | `F` |
| 1 | Zehir (Poison) | `P` |
| 2 | Aşındırıcı (Corrosive) | `C` |
| 3 | Organik Peroksit (Organic Peroxide) | `O` |

Aynı renkteki bitişik halkalar birleştirilmez: renkler tekrar etse bile her zaman beşini de say.

![Biri geçerli, biri sahte iki örnek bilişsel hedef](../../../docs/rules/rules_cognitive_example.png)

Soldaki hedef merkezden dışa doğru Sarı, Mavi, Kırmızı, Siyah, Yeşil'dir: 0 + 2 - 1 - 2 + 1 = 0, yani Yanıcı Gaz'dır (`F`). Sağdaki hedef Mavi, Sarı, Siyah, Siyah, Siyah'tır: 2 + 0 - 2 - 2 - 2 = -4, yani sahtedir.

[Duvar işaretleri eğitimi](/docs/programming/wall-tokens/), bir hedefin kamerayla nasıl okunacağını gösterir.

## Robot {#the-robot}
- Takımlar organizatörlerin sağladığı robot modelini kullanır ve onu **3000**'lik bir bütçe dahilinde [Robot Customizer](https://robot.erebus.rcj.cloud/) ile özelleştirebilir. [Robot](/docs/robot/) sayfasına bak.
- Robot bir GPS, bir renk sensörü, mesafe sensörleri, RGB kameralar, bir LiDAR, bir jiroskop ve bir ivmeölçer kullanabilir.
- Simüle edilen sensörlerde gerçekçi gürültü vardır. Programın buna karşı dayanıklı olmalıdır ve organizatörler yarışma için gürültü seviyelerini değiştirmeyecek.
- Robotlar otonom olmalıdır. Her takımın sahada bir robotu vardır.
- Önceden haritalama yasaktır: bu hem sahayı hem de duvar işaretlerinin konumunu kapsar; bilinen konumlardan önceden tanımlanmış hareketler de buna dahildir. Önceden haritalama, turdan derhal diskalifiyeyle sonuçlanır.

## Bir oyun oynama {#playing-a-game}
- Bir oyun **8 dakika simülasyon zamanı** sürer. İkinci bir sayaç gerçek zamanda, **10 dakika** sınırıyla çalışır. Sayaçlardan herhangi biri dolduğunda oyun biter.
- Robotun merkezi bir karenin içindeyse o kare ziyaret edilmiş sayılır. Erebus bu kararı otomatik olarak verir.
- Oyun ayrıca robot çıkış komutunu gönderdiğinde ya da takım kaptanı oyunun bitişini çağırdığında da biter (oyunun nasıl yürütüldüğüne bağlı olarak).
- Yarışma dünyaları oyunlardan hemen önce açıklanır ve her turun son tarihinden sonra programlar değiştirilemez.

### İlerleme eksikliği {#lack-of-progress}
İlerleme eksikliği (Lack of Progress, LoP) şu durumlarda olur:

- Robot bir çukura düştüğünde.
- Robot 20 saniye ya da daha uzun süre sabit bir konumda kaldığında (otomatik olarak çağrılır).
- Hakem, robotun hareketsiz olmadığına ama bir hareket döngüsünde sıkıştığına karar verdiğinde.
- Robot onu kendi başına çağırdığında.
- Diğer durumlarda takım kaptanı bunu isteyebilir ve son kararı hakem verir. Oyunun nasıl yürütüldüğüne bağlı olarak bu geçerli olmayabilir.

Robot daha sonra ziyaret ettiği son kontrol noktasına ya da hiçbirine ulaşmadıysa başlangıç karesine geri yerleştirilir. Yönü seçilemez. Erebus ayrıca robota `L` harfini gönderir, böylece programın [buna tepki verebilir](/docs/programming/communication/#lack-of-progress).

## Puanlama {#scoring}
Puanlama Erebus tarafından otomatik olarak yapılır. Ödüller tekrarlanmaz: örneğin her kontrol noktası yalnızca ilk seferde puan kazandırır.

Bir duvar işaretini tanımlamak için robot **en az 1 saniye** durmalı, sonra türü ve konumu oyun yöneticisine [göndermelidir](/docs/programming/communication/#scoring-wall-tokens). Robotun merkezi işarete en fazla yarım kare uzaklıkta olmalıdır.

| Öğe | Puan |
|---|---|
| 1-3. alanlarda doğrusal bir karede duvar işareti tanımlama (TI) | Harf kazazede: 5, bilişsel hedef: 10 |
| 1-3. alanlarda yüzen bir karede duvar işareti tanımlama (TI) ve 4. alandaki tüm işaretler | Harf kazazede: 15, bilişsel hedef: 30 |
| TI'ya ek olarak doğru tür (TT) | Harf kazazede: 10, bilişsel hedef: 20 |
| Ziyaret edilen kontrol noktası (CN) | 10 |
| Yanlış duvar işareti tanımlama (TMI) | -5 |
| İlerleme eksikliği (LoP) | -5 |

Toplam puan sıfırın altına düşemez. Yanlış tanımlama; işarete yarım kareden daha uzak bir konum bildirmek, işaret olmayan bir yerde işaret bildirmek ya da bir kazazedeyi tehlike işareti olarak bildirmek (veya tersi) anlamına gelir. Sahte bir işareti bildirmek ikinci kategoriye girer.

**Alan çarpanları (AM)**: TI, TT ve CN; 1., 2., 3. ve 4. alanlarda sırasıyla 1, 1,25, 1,5 ve 2 ile çarpılır. TMI ve LoP çarpılmaz.

**Çıkış bonusu (Exit bonus, EB)**: robot en az bir duvar işaretini tanımladıysa, başlangıç karesine döner ve çıkış komutunu gönderirse puan %10 artar.

**Harita bonusu (Map bonus, MB)**: robot labirentin haritasını gönderebilir. Çarpan doğruluk × 1,2 + 1'dir, yani kusursuz bir harita puanı 2,2 ile çarpar. [Haritalama](/docs/rules/mapping/) sayfasına bak.

Bir oyunun saha puanı şöyle hesaplanır:

![Saha puanı, dört alan üzerinden (TI + TT + CN) × AM toplamından TMI ve LoP çıkarılıp tümünün EB ve MB ile çarpılmasına eşittir](../../../docs/rules/rules_field_score.png)

Örneğin bu sonuçları alan bir oyun 2680,15 puan alır:

![Bir puan hesaplamasının adım adım örneği](../../../docs/rules/rules_scoring_example.png)

## Yarışma {#the-competition}
Nasıl hazırlanacağın, göndermen gereken belgeler, yarışma kurulumu ve final puanı [Yarışmaya hazırlanma](/docs/competition/) sayfasındadır.

## Sırada {#next}
Robotunun ne yapması gerektiğini artık bildiğine göre [robotunu edin](/docs/robot/).
