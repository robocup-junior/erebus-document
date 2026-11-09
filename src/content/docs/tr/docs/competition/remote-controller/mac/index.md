---
title: macOS
description: Remote Controller'ın macOS'ta nasıl kurulacağı.
---

# Oyun sunucusunu ve denetleyici programını aynı bilgisayarda çalıştırma
Önce oyun sunucusunu ve denetleyici programını aynı bilgisayarda çalıştırmayı dene. Bu, yarışmadaki kurulumla aynı değildir, ama kendi bilgisayarında hata ayıklarken işine yarar.

## Uzaktan modu aç {#toggle-remote-mode}
Dünyayı aç, kontrol penceresinde **Robot setup** düğmesine bas ve **Remote mode** seçeneğini aç. Özel bir robotun varsa önce onu **Robot JSON** altından yükle.

![Robot setup içinde açılmış Remote mode](../../../../../docs/competition/remote-controller/mac/toggle_remote.png)

Kontrol penceresi görünmüyorsa Scene Tree'de "DEF MAINSUPERVISOR Robot" öğesine sağ tıkla ve "Show Robot Window" seçeneğini seç.

## Programını çalıştır {#execute-your-program}
Bir terminal aç ve `<Your controller path>` yerine denetleyici programının yolunu yazarak aşağıdaki komutları çalıştır.

```bash
export WEBOTS_HOME=/Applications/Webots.app
"$WEBOTS_HOME/Contents/MacOS/webots-controller" "<Your controller path>"
```

Webots başka bir konuma ya da başka bir adla kuruluysa `WEBOTS_HOME` değerini buna göre değiştir, örneğin `"/Applications/Webots R2025a.app"`.

Denetleyici Webots'a bağlanır ve oyun başlayana kadar bekler.

## Oyunu başlat {#start-the-game}
Kontrol penceresinde **Run match** düğmesine bas. Robot belirir ve programın çalışmaya başlar.

## Oyunu sonlandır {#terminate-the-game}
Oyunu durdurmak için terminalde Ctrl+C tuşlarına bas.

Oyun bitince yeniden çalıştırmak için **Reset** düğmesine bas. **Keep on Reset** açık değilse sıfırlama Remote mode'u kapatır.

# Oyun sunucusunu farklı bir bilgisayarda çalıştırma
Resmî yarışmalarda kullanılan kurulum budur. Denetleyicini çalıştıran bilgisayar (istemci) ile oyunu çalıştıran bilgisayar (sunucu) aynı ağa bağlı olmalıdır.

1. (Sunucu) Sunucuda Webots'u başlat, dünyayı aç ve kontrol penceresinin **Robot setup** bölümünde **Remote mode** seçeneğini aç.
1. (Sunucu) Sunucunun IP adresini System Settings > Network (Sistem Ayarları > Ağ) bölümünden öğren.
1. (İstemci) `<Your controller path>` yerine denetleyici programının yolunu, `<Server IP address>` yerine önceki adımda bulduğun IP adresini yazarak aşağıdaki komutları çalıştır.

    ```bash
    export WEBOTS_HOME=/Applications/Webots.app
    "$WEBOTS_HOME/Contents/MacOS/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. (Sunucu) **Run match** düğmesine basarak oyunu başlat.

## Sorun giderme {#troubleshooting}
- **Denetleyici bağlanamıyor:** iki bilgisayarın birbirine ulaşabildiğini (örneğin `ping` ile), sunucunun güvenlik duvarının 1234 numaralı TCP portuna izin verdiğini ve Webots tercihlerinin Network sekmesindeki izin verilen IP'ler listesinin boş olduğunu ya da istemciyi içerdiğini kontrol et.
- **Denetleyici bekliyor ama robot hareket etmiyor:** **Remote mode** seçeneğinin açık olduğunu kontrol et ve **Run match** düğmesine bas.
- **Denetleyici bir Python kütüphanesini bulamıyor:** program istemcideki Python kurulumuyla çalışır, bu yüzden kütüphaneyi istemciye kur.

# Resmî belgeler
Bu kurulum hakkında daha fazla ayrıntı için [Webots kılavuzuna](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a) bak.
