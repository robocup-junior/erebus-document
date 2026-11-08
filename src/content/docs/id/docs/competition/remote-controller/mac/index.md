---
title: macOS
description: Panduan pengaturan Remote Controller untuk macOS.
---

# Menjalankan server permainan dan program controller di komputer yang sama
Pertama, mari coba jalankan server permainan dan program controller di komputer yang sama. Ini tidak sama dengan pengaturan kompetisi sungguhan, tetapi akan membantumu saat melakukan debugging secara lokal.

## Mengaktifkan mode remote {#toggle-remote-mode}
Buka world dan tekan "TOGGLE REMOTE" di jendela kontrol. Warna tombol akan berubah menjadi oranye untuk menunjukkan bahwa mode ini aktif.

![Tombol TOGGLE REMOTE, dalam keadaan aktif](../../../../../docs/competition/remote-controller/mac/toggle_remote.png)

Jika jendela kontrol tidak muncul, klik kanan "DEF MAINSUPERVISOR Robot" di Scene Tree lalu tekan "Show Robot Window".

## Menjalankan programmu {#execute-your-program}
Buka terminal dan jalankan perintah berikut, dengan mengganti `<Your controller path>` dengan path ke program controller-mu.

```bash
export WEBOTS_HOME=/Applications/Webots.app
"$WEBOTS_HOME/Contents/MacOS/webots-controller" "<Your controller path>"
```

Jika Webots diinstal di lokasi lain atau dengan nama lain, sesuaikan `WEBOTS_HOME`, misalnya `"/Applications/Webots R2023b.app"`.

Controller akan terhubung ke Webots dan menunggu sampai permainan dimulai.

## Memulai permainan {#start-the-game}
Tekan tombol start di jendela kontrol. Robot akan muncul, dan programmu mulai berjalan.

## Menghentikan permainan {#terminate-the-game}
Untuk menghentikan permainan, tekan Ctrl+C di terminal.

Begitu simulasi dihentikan, sistem pengelola permainan Erebus juga ikut berhenti. Jika kamu ingin menjalankan permainan lagi, muat ulang world-nya.

# Menjalankan server permainan di komputer yang berbeda
Ini adalah pengaturan yang digunakan di kompetisi resmi. Komputer yang menjalankan controller-mu (klien) dan server permainan (server) harus terhubung ke jaringan yang sama.

1. (Server) Jalankan Webots di server, buka world, lalu aktifkan mode remote di jendela kontrol.
1. (Server) Cari tahu alamat IP server. Kamu bisa menemukannya di System Settings --> Network.
1. (Klien) Jalankan perintah berikut, dengan mengganti `<Your controller path>` dengan path ke program controller-mu dan `<Server IP address>` dengan alamat IP yang kamu temukan di langkah sebelumnya.

    ```bash
    export WEBOTS_HOME=/Applications/Webots.app
    "$WEBOTS_HOME/Contents/MacOS/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. (Server) Mulai permainan dengan menekan tombol start.

## Pemecahan masalah {#troubleshooting}
- **Controller tidak bisa terhubung:** pastikan kedua komputer bisa saling menjangkau, misalnya dengan `ping`, firewall server mengizinkan port TCP 1234, dan daftar IP yang diizinkan di tab Network pada Preferences Webots kosong atau mencakup klien.
- **Muncul `No robot name provided`:** pesan ini normal selama controller menunggu. Jika terus muncul, mode remote belum aktif, jadi periksa tombol TOGGLE REMOTE.
- **Controller tidak menemukan library Python:** program berjalan dengan Python milik klien, jadi instal library-nya di sana.

# Dokumen resmi
Jika kamu ingin mengetahui pengaturannya lebih detail, kamu bisa menemukannya di [Panduan Resmi](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b).
