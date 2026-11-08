---
title: macOS
description: Remote Controller'ın macOS'ta nasıl kurulacağı.
---

# Oyun sunucusunu ve denetleyici programını aynı bilgisayarda çalıştırma
Önce oyun sunucusunu ve denetleyici programını aynı bilgisayarda çalıştırmayı dene. Bu, yarışmadaki kurulumla aynı değildir, ama kendi bilgisayarında hata ayıklarken işine yarar.

## Uzaktan modu aç {#toggle-remote-mode}
Dünyayı aç ve kontrol penceresinde "TOGGLE REMOTE" düğmesine bas. Düğme turuncuya döner; bu, uzaktan modun açık olduğunu gösterir.

![Açık durumdaki TOGGLE REMOTE düğmesi](../../../../../docs/competition/remote-controller/mac/toggle_remote.png)

Kontrol penceresi görünmüyorsa Scene Tree'de "DEF MAINSUPERVISOR Robot" öğesine sağ tıkla ve "Show Robot Window" seçeneğini seç.

## Programını çalıştır {#execute-your-program}
Bir terminal aç ve `<Your controller path>` yerine denetleyici programının yolunu yazarak aşağıdaki komutları çalıştır.

```bash
export WEBOTS_HOME=/Applications/Webots.app
"$WEBOTS_HOME/Contents/MacOS/webots-controller" "<Your controller path>"
```

Webots başka bir konuma ya da başka bir adla kuruluysa `WEBOTS_HOME` değerini buna göre değiştir, örneğin `"/Applications/Webots R2023b.app"`.

Denetleyici Webots'a bağlanır ve oyun başlayana kadar bekler.

## Oyunu başlat {#start-the-game}
Kontrol penceresinde başlat düğmesine bas. Robot görünür ve programın çalışmaya başlar.

## Oyunu sonlandır {#terminate-the-game}
Oyunu durdurmak için terminalde Ctrl+C tuşlarına bas.

Simülasyon sona erdiğinde Erebus oyun yöneticisi de durur. Oyunu yeniden çalıştırmak için dünyayı yeniden yükle.

# Oyun sunucusunu farklı bir bilgisayarda çalıştırma
Resmî yarışmalarda kullanılan kurulum budur. Denetleyicini çalıştıran bilgisayar (istemci) ile oyunu çalıştıran bilgisayar (sunucu) aynı ağa bağlı olmalıdır.

1. (Sunucu) Sunucuda Webots'u başlat, dünyayı aç ve kontrol penceresinde uzaktan modu aç.
1. (Sunucu) Sunucunun IP adresini System Settings > Network (Sistem Ayarları > Ağ) bölümünden öğren.
1. (İstemci) `<Your controller path>` yerine denetleyici programının yolunu, `<Server IP address>` yerine önceki adımda bulduğun IP adresini yazarak aşağıdaki komutları çalıştır.

    ```bash
    export WEBOTS_HOME=/Applications/Webots.app
    "$WEBOTS_HOME/Contents/MacOS/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. (Sunucu) Başlat düğmesine basarak oyunu başlat.

## Sorun giderme {#troubleshooting}
- **Denetleyici bağlanamıyor:** iki bilgisayarın birbirine ulaşabildiğini (örneğin `ping` ile), sunucunun güvenlik duvarının 1234 numaralı TCP portuna izin verdiğini ve Webots tercihlerinin Network sekmesindeki izin verilen IP'ler listesinin boş olduğunu ya da istemciyi içerdiğini kontrol et.
- **`No robot name provided` mesajı görüntüleniyor:** denetleyici beklerken bu mesaj normaldir. Mesaj kaybolmuyorsa uzaktan mod açık değildir: TOGGLE REMOTE düğmesini kontrol et.
- **Denetleyici bir Python kütüphanesini bulamıyor:** program istemcideki Python kurulumuyla çalışır, bu yüzden kütüphaneyi istemciye kur.

# Resmî belgeler
Bu kurulum hakkında daha fazla ayrıntı için [Webots kılavuzuna](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b) bak.
