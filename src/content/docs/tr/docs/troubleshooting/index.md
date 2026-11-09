---
title: Sorun giderme
description: Erebus'u kurarken ve çalıştırırken sık karşılaşılan sorunlara çözümler.
---

Her şeyden önce Webots konsolunu kontrol et. Çoğu sorunda orada bir hata mesajı görünür.

## Kurulum {#installation}

### `No module named 'cv2'` {#no-module-named-cv2}
OpenCV, Webots'un kullandığı Python'da kurulu değil. [Gerekli kütüphaneleri](/docs/installation/#python-libraries) o Python'a kur. Birden fazla Python kurulumun varsa aşağıdaki **Python command** ayarı, Webots'un hangisini kullandığını gösterir.

### `WARNING: Python was not found` {#warning-python-was-not-found}
Webots, Python'un nerede olduğunu bilmiyor.

1. Python'u bul. macOS ve Linux'ta bir terminalde `which python3` çalıştır. Windows'ta yeni bir Komut İstemi'nde `python` yazınca Python'un açıldığını kontrol et. Açılmıyorsa Python'u PATH'e ekleme seçeneğini işaretleyerek yeniden kur.
2. Webots tercihlerini aç: macOS'ta **Webots > Preferences**, Windows ve Linux'ta **Tools > Preferences**.

   ![Webots menüsündeki Preferences öğesi](../../../docs/troubleshooting/preferences_open.png)

3. Yolu **Python command** alanına yaz. Windows'ta genellikle `python` yeterlidir.

   ![Webots tercihlerindeki Python command alanı](../../../docs/troubleshooting/preferences.png)

### `ERROR: Skipped PROTO 'custom_robot'` {#error-skipped-proto-custom_robot}
Bu mesaj, bir dünyayı ilk açtığında, Erebus robot modelini hazırlamadan önce görünür. Erebus modeli hazırlar ve dünyayı kendiliğinden yeniden yükler, bu yüzden görmezden gelebilirsin.

### Oyun süresi görünmüyor {#the-game-timer-does-not-appear}
İlk başlatma, Erebus kütüphaneleri kurarken birkaç dakika sürebilir. İşlem hiç bitmiyorsa konsolda hata olup olmadığına bak. Otomatik kurulum çalışmazsa [gerekli kütüphaneleri](/docs/installation/#python-libraries) kendin kur.

## Erebus'u çalıştırma {#running-erebus}

### Kontrol penceresi görünmüyor {#the-control-window-does-not-appear}
Kontrol penceresi, Webots'un açtığı bir web sayfasıdır.

1. Pencereyi kapattıysan ya da tarayıcın engellediyse, dünyayı Webots'un yeniden yükleme düğmesiyle yeniden yükle. Erebus kontrol penceresini yeniden açar.
2. Aksi halde **Tools > Scene Tree** ile Scene Tree'nin görüntülendiğinden emin ol.
3. Scene Tree'de **DEF MAINSUPERVISOR Robot** öğesini bul, sağ tıkla ve **Show Robot Window** seçeneğini seç.

Kontrol penceresinin, dünya her yüklendiğinde değişen özel bir adresi vardır. Pencereyi `localhost:1234` adresinde kendin açarsan **Read-only** gösterir ve düğmeleri çalışmaz.

### Kontrol penceresi "Access log incomplete" diyor {#the-control-window-says-access-log-incomplete}
Bu uyarı, [Wireshark](/docs/installation/#optional-wireshark) kurulu olmadığında görünür. Yarışmalardaki organizatörler içindir: **Acknowledge** düğmesine bas ve her zamanki gibi çalış.

![Scene Tree'deki Show Robot Window seçeneği](../../../docs/troubleshooting/showrobot.png)

### Webots ekranı boş ya da siyah {#the-webots-screen-is-blank-or-black}
İndirdiğin dosyayı, dünyayı açmadan önce ayrı bir klasöre kopyalayıp zip'ten çıkar.

### Simülasyon çok yavaş çalışıyor {#the-simulation-runs-too-slowly}
Bu muhtemelen bilgisayarının performansından kaynaklanıyor. Grafik kalitesini düşürmek yardımcı olabilir:

1. Webots tercihlerini aç.
2. **OpenGL** sekmesini aç.
3. Ayarları değiştir.

![Webots tercihlerinin OpenGL sekmesi](../../../docs/troubleshooting/opengl.png)

Bu ayarlar kameraların gördüklerini değiştirir ve yarışma [kendi ayarlarını](/docs/competition/#opengl-settings) kullanır, bu yüzden programını o ayarlarla da kontrol et.

## Robotun {#your-robot}

### Programım bir cihazın bulunamadığını söylüyor {#my-program-says-a-device-was-not-found}
Aşağıya bak. Ayrıca oyunu başlatmadan önce robotunu **Robot setup** içindeki **Robot JSON** altından yüklediğini kontrol et.

## Programın {#your-program}

### `Device "..." was not found` {#device--was-not-found}
Programındaki cihaz adı robotunla eşleşmiyor. Başlangıç robotunun adları [Başvuru](/docs/reference/parameters/#device-names-of-the-starter-robot) sayfasındadır. Kendi robotun için bunlar [Robot Customizer](/docs/robot/customizer/) içinde belirlediğin adlardır. Robotunun yüklendiğini kontrol et.

### Bir duvar işaretini bildirdiğimde hiçbir şey olmuyor {#nothing-happens-when-i-report-a-wall-token}
Kontrol penceresinin **Advanced setup** bölümünde **Enable debugging** seçeneğini aç ve konsolu kontrol et. En yaygın nedenler; robotun en az 1 saniye durmamış olması, koordinatların santimetreye çevrilmemiş olması ve robotun ya da konumun işarete yarım kareden (6 cm) uzak olmasıdır. Bkz. [İletişim](/docs/programming/communication/#scoring-wall-tokens).

### Bildirimlerim yanlış tanımlama sayılıyor {#my-reports-are-misidentifications}
Robot işarete en fazla yarım kare uzaklıkta ve duvarın aynı tarafında olmalıdır; ayrıca her işaretten yalnızca bir kez puan alınabilir. Sahte bir işareti bildirmek de yanlış tanımlama sayılır.

### Oyun "Battery depleted" ile bitiyor {#the-game-ends-with-battery-depleted}
Batarya bitti. Bu olmadan önce bataryayı değiştirmek için bir temas karesinin üzerinde 5 saniye dur. Bkz. [Batarya](/docs/programming/battery/).

### Programım artık oyun bilgisini almıyor {#my-program-no-longer-receives-the-game-information}
Erebus v27'den itibaren `G` yanıtı 20 bayttır ve sonunda batarya seviyesi bulunur. Programındaki uzunluk kontrolünü güncelle. Bkz. [Oyun bilgisi](/docs/programming/communication/#game-information).

### Harita %0 alıyor ya da puanlama hatası veriyor {#the-map-gets-0-or-a-scoring-error}
Haritan başlangıç karesini (`5`) içermelidir ve yalnızca bir kez değerlendirilebilir. [Haritayı gönderme](/docs/programming/map-bonus/) sayfasına bak.

### Denetleyici uzaktan modda bağlanamıyor {#the-controller-cannot-connect-in-remote-mode}
İşletim sistemin için [Remote Controller](/docs/competition/remote-controller/) kılavuzuna bak.

## Hâlâ takıldın mı? {#still-stuck}
[Discord sunucusunda](https://discord.com/invite/6FJxZxk) sor ya da [bir issue aç](https://github.com/robocup-junior/erebus/issues). İşletim sistemini, Erebus ve Webots sürümlerini ve konsoldaki mesajı ekle.
