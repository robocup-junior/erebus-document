---
title: SSS
description: Erebus ve yarışma hakkında sıkça sorulan sorular.
---

## Erebus hakkında {#about-erebus}

### Gerçek bir robota ihtiyacım var mı? {#do-i-need-a-real-robot}
Hayır. Her şey simülatörde olur. Robot, senin tasarladığın sanal bir e-puck'tır.

### Hangi programlama dillerini kullanabilirim? {#which-programming-languages-can-i-use}
Bu belgelerde Python ve C/C++ ele alınıyor. Erebus Java ve MATLAB denetleyicilerini de yükleyebilir, ama bu belgelerde onlar için örnek yok.

### Güçlü bir bilgisayara ihtiyacım var mı? {#do-i-need-a-powerful-computer}
Hayır, [gereksinimlere](/docs/installation/) bak. Daha yavaş bilgisayarlarda [grafik ayarlarını düşürmek](/docs/troubleshooting/#the-simulation-runs-too-slowly) gerekebilir.

### Webots'un daha yeni bir sürümünü kullanabilir miyim? {#can-i-use-a-newer-version-of-webots}
Hayır. Erebus v26, Webots **R2023b** üzerinde çalışır. Diğer sürümleri onun yanında kurulu tutabilirsin.

### OpenCV ya da NumPy gibi kütüphaneleri kullanabilir miyim? {#can-i-use-libraries-like-opencv-or-numpy}
Evet. Kodun yazarlarını belirttiğin ve lisansına uyduğun sürece harici kod kullanabilirsin. Takımlar öğrenmeye öncelik vermeli ve çözümlerinin nasıl çalıştığını açıklayabilmelidir.

## Oyun {#the-game}

### Konuları öğrenmenin en iyi sırası nedir? {#what-is-the-best-order-to-learn-things}
[Öğrenme yolunu](/docs/#the-learning-path) izle: oyunu anla, robotunu edin, çalıştır, temelleri öğren, sonra oyunu oyna.

### Programlamadan önce bir robot yapmam gerekiyor mu? {#do-i-need-to-make-a-robot-before-programming}
Evet. Her program yüklediğin bir robot üzerinde çalışır, bu yüzden [Robotunu edin](/docs/robot/) sayfasıyla başla. Acelen varsa hazır başlangıç robotunu indirebilirsin.

### Robot nereden başlar? {#where-does-the-robot-start}
1. alandaki başlangıç karesinden. Her zaman duvar olmayan bir yöne bakar.

### Robot bir çukura düşerse ne olur? {#what-happens-if-the-robot-falls-into-a-hole}
Bir ilerleme eksikliği (lack of progress, LoP) olur: robot ziyaret ettiği son kontrol noktasına döner ve 5 puan kaybedersin.

### Robotun başlangıca dönmesi gerekiyor mu? {#does-the-robot-have-to-return-to-the-start}
Hayır, ama robot en az bir duvar işaretini tanımladıysa başlangıç karesine dönüp `E` göndermek %10'luk çıkış bonusu kazandırır.

### Robotum ne kadar süre kaldığını nasıl öğrenebilir? {#how-can-my-robot-tell-how-much-time-is-left}
[`G` mesajıyla](/docs/programming/communication/#game-information). İki sayaç vardır ve oyun süresi bataklıklarda daha hızlı akar.

### 4. alanı keşfetmem gerekiyor mu? {#do-i-have-to-explore-area-4}
Hayır. İsteğe bağlıdır, ama oradaki işaretler en değerli olanlardır: en yüksek puanı verirler ve bu puan 2 ile çarpılır.

### 4. alanın haritasını çıkarmam gerekiyor mu? {#do-i-have-to-map-area-4}
Hayır. Tüm hücreleri `*` olduğu için onları yalnızca `*` ile doldurman yeterli.

### Robotum haritayı önceden bilebilir mi? {#can-my-robot-know-the-map-beforehand}
Hayır. Sahanın ya da duvar işaretlerinin konumunun önceden haritalanması yasaktır.

## Yarışma {#the-competition}

### Nasıl katılırım? {#how-do-i-take-part}
Bölgendeki RoboCupJunior yarışması aracılığıyla. Uluslararası yarışmadaki kontenjanları Bölge Temsilcin (Regional Representative) belirler. [RoboCupJunior web sitesine](https://junior.robocup.org/) bak.

### Neler hazırlamalıyım? {#what-should-i-prepare}
[Yarışmaya hazırlanma](/docs/competition/) sayfasına bak.

### Kurallar hakkında nereden soru sorabilirim? {#where-can-i-ask-about-the-rules}
[RoboCupJunior Forumu](https://junior.forum.robocup.org/) üzerinden. Açıklamalar da orada yayımlanır, bu yüzden düzenli olarak kontrol et.
