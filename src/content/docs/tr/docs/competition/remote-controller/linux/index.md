---
title: Linux (Ubuntu)
description: Linux (Ubuntu 22.04 LTS) için Remote Controller kurulum kılavuzu.
---

# Oyun sunucusunu ve denetleyici programlarını aynı bilgisayarda çalıştırma
Önce oyun sunucusunu ve denetleyici programlarını aynı bilgisayarda çalıştırmayı deneyelim. Bu, gerçek bir yarışma kurulumuyla aynı değildir, ama yerelde hata ayıklarken sana yardımcı olur.

## Uzaktan modu aç {#toggle-remote-mode}
Dünyayı aç ve kontrol penceresinde "TOGGLE REMOTE" düğmesine bas. Etkinleştirildiğini göstermek için düğmenin rengi turuncuya dönmelidir.

![Açık durumdaki TOGGLE REMOTE düğmesi](../../../../../docs/competition/remote-controller/linux/toggle_remote.png)

Kontrol penceresi görünmüyorsa Scene Tree içinde "DEF MAINSUPERVISOR Robot" öğesine sağ tıkla ve "Show Robot Window" seçeneğine bas.

## Programını çalıştır {#execute-your-program}
Bir terminal aç ve `<Your controller path>` yerine denetleyici programının yolunu yazarak aşağıdaki komutları çalıştır.

```bash
export WEBOTS_HOME=/usr/local/webots
"$WEBOTS_HOME/webots-controller" "<Your controller path>"
```

Bu, Webots'un `.deb` paketiyle `/usr/local/webots` içine kurulduğunu varsayar. Başka bir yere kurduysan `WEBOTS_HOME` değerini buna göre değiştir.

Denetleyici Webots'a bağlanır ve oyun başlayana kadar bekler.

## Oyunu başlat {#start-the-game}
Kontrol penceresinde başlat düğmesine bas. Robot görünür ve programın çalışmaya başlar.

## Oyunu sonlandır {#terminate-the-game}
Oyunu yarıda kesmek için terminalde Ctrl+C tuşlarına bas.

Simülasyon sonlandırıldığında Erebus oyun yönetim sistemi de aynı anda sonlandırılır. Oyunu yeniden çalıştırmak istersen dünyayı yeniden yükle.

# Oyun sunucusunu farklı bir bilgisayarda çalıştırma
Resmî yarışmalarda kullanılan kurulum budur. Denetleyicini çalıştıran bilgisayar (istemci) ile oyun sunucusu (sunucu) aynı ağa bağlı olmalıdır.

1. (Sunucu) Sunucuda Webots'u başlat, dünyayı aç ve kontrol penceresinde uzaktan modu aç.
1. (Sunucu) Sunucunun IP adresini öğren. `ip addr` komutunu kullanabilirsin.
1. (İstemci) `<Your controller path>` yerine denetleyici programının yolunu, `<Server IP address>` yerine önceki adımda bulduğun IP adresini yazarak aşağıdaki komutları çalıştır.

    ```bash
    export WEBOTS_HOME=/usr/local/webots
    "$WEBOTS_HOME/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. (Sunucu) Başlat düğmesine basarak oyunu başlat.

## Sorun giderme {#troubleshooting}
- **Denetleyici bağlanamıyor:** iki bilgisayarın birbirine ulaşabildiğini (örneğin `ping` ile), sunucunun güvenlik duvarının 1234 numaralı TCP portuna izin verdiğini ve Webots tercihlerinin (Preferences) Network sekmesindeki izin verilen IP listesinin boş olduğunu ya da istemciyi içerdiğini kontrol et.
- **`No robot name provided` görüntüleniyor:** bu mesaj beklerken normaldir. Görüntülenmeye devam ederse uzaktan mod açık değildir, TOGGLE REMOTE düğmesini kontrol et.
- **Denetleyici bir Python kütüphanesini bulamıyor:** program istemcinin Python'uyla çalışır, bu yüzden kütüphaneyi orada kur.

# Resmî belge
Kurulum hakkında daha ayrıntılı bilgi istersen [Resmî Kılavuz](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b) sayfasında bulabilirsin.
