---
title: macOS
description: Cara menyiapkan Remote Controller di macOS.
---

# Menjalankan server permainan dan program controller di komputer yang sama
Pertama, coba jalankan server permainan dan program controller-mu di komputer yang sama. Pengaturan ini berbeda dengan pengaturan di kompetisi, tetapi berguna untuk debugging secara lokal.

## Mengaktifkan mode remote {#toggle-remote-mode}
Buka world, tekan **Robot setup** di jendela kontrol, dan aktifkan **Remote mode**. Jika kamu punya robot kustom, muat dulu robotmu di bawah **Robot JSON**.

![Remote mode, diaktifkan di Robot setup](../../../../../docs/competition/remote-controller/mac/toggle_remote.png)

Jika jendela kontrol tidak muncul, klik kanan "DEF MAINSUPERVISOR Robot" di Scene Tree, lalu pilih "Show Robot Window".

## Menjalankan programmu {#execute-your-program}
Buka terminal, lalu jalankan perintah berikut. Ganti `<Your controller path>` dengan path ke program controller-mu.

```bash
export WEBOTS_HOME=/Applications/Webots.app
"$WEBOTS_HOME/Contents/MacOS/webots-controller" "<Your controller path>"
```

Jika Webots diinstal di lokasi lain atau dengan nama lain, sesuaikan `WEBOTS_HOME`, misalnya `"/Applications/Webots R2025a.app"`.

Controller akan terhubung ke Webots dan menunggu sampai permainan dimulai.

## Memulai permainan {#start-the-game}
Tekan **Run match** di jendela kontrol. Robot muncul, dan programmu mulai berjalan.

## Menghentikan permainan {#terminate-the-game}
Untuk menghentikan permainan, tekan Ctrl+C di terminal.

Saat permainan berakhir, tekan **Reset** untuk menjalankannya lagi. Reset akan mematikan Remote mode, kecuali **Keep on Reset** aktif.

# Menjalankan server permainan di komputer yang berbeda
Inilah pengaturan yang digunakan di kompetisi resmi. Komputer yang menjalankan controller-mu (klien) dan komputer yang menjalankan permainan (server) harus terhubung ke jaringan yang sama.

1. (Server) Jalankan Webots di server, buka world, dan aktifkan **Remote mode** di **Robot setup** pada jendela kontrol.
1. (Server) Cari tahu alamat IP server di System Settings > Network.
1. (Klien) Jalankan perintah berikut. Ganti `<Your controller path>` dengan path ke program controller-mu, dan `<Server IP address>` dengan alamat IP yang kamu temukan di langkah sebelumnya.

    ```bash
    export WEBOTS_HOME=/Applications/Webots.app
    "$WEBOTS_HOME/Contents/MacOS/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. (Server) Mulai permainan dengan menekan **Run match**.

## Pemecahan masalah {#troubleshooting}
- **Controller tidak bisa terhubung:** pastikan kedua komputer bisa saling terhubung (periksa misalnya dengan `ping`), firewall server mengizinkan port TCP 1234, dan daftar IP yang diizinkan di tab Network pada Preferences Webots kosong atau mencakup klien.
- **Controller menunggu, tetapi robot tidak bergerak:** periksa bahwa **Remote mode** aktif, dan tekan **Run match**.
- **Controller tidak menemukan library Python:** program berjalan dengan instalasi Python di komputer klien, jadi instal library tersebut di sana.

# Dokumentasi resmi
Untuk detail lebih lanjut tentang pengaturan ini, lihat [panduan Webots](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a).
