---
title: Windows
description: Cara menyiapkan Remote Controller di Windows.
---

# Menjalankan server permainan dan program controller di komputer yang sama
Pertama, coba jalankan server permainan dan program controller-mu di komputer yang sama. Pengaturan ini berbeda dengan pengaturan di kompetisi, tetapi berguna untuk debugging secara lokal.

## Mengaktifkan mode remote {#toggle-remote-mode}
Buka world, tekan **Robot setup** di jendela kontrol, dan aktifkan **Remote mode**. Jika kamu punya robot kustom, muat dulu robotmu di bawah **Robot JSON**.  
![Remote mode, diaktifkan di Robot setup](../../../../../docs/competition/remote-controller/windows/../mac/toggle_remote.png)

Jika jendela kontrol tidak muncul, klik kanan "DEF MAINSUPERVISOR Robot" di Scene Tree, lalu pilih "Show Robot Window".  
![Opsi Show Robot Window](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## Menjalankan programmu {#execute-your-program}
Buka PowerShell. Biasanya kamu bisa menemukannya di daftar aplikasi.  
![PowerShell di daftar aplikasi](../../../../../docs/competition/remote-controller/windows/powerShell.png)

Jalankan perintah berikut di PowerShell. Ganti `<Your controller path>` dengan path ke program controller-mu.

`webots-controller.exe <Your controller path>`

Jika perintahnya tidak ditemukan, gunakan path lengkapnya, yang secara bawaan adalah `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe`.

Jika kamu tidak tahu path ke program controller-mu, seret dan lepas (drag and drop) berkasnya ke jendela PowerShell, dan path-nya akan terisi otomatis.  
![Menyeret berkas ke jendela PowerShell](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

Lalu tekan Enter untuk menjalankan perintahnya. Controller akan terhubung ke Webots dan menunggu sampai permainan dimulai.

## Memulai permainan {#start-the-game}
Tekan **Run match** di jendela kontrol untuk memulai permainan.  
![Tombol Run match di jendela kontrol](../../../../../docs/competition/remote-controller/windows/../../../getting-started/match-controls.png)

## Menghentikan permainan {#terminate-the-game}
Untuk menghentikan permainan, tekan Ctrl+C di PowerShell untuk menghentikan programmu.

Saat permainan berakhir, tekan **Reset** untuk menjalankannya lagi. Reset akan mematikan Remote mode, kecuali **Keep on Reset** aktif.

# Menjalankan server permainan di komputer yang berbeda
Inilah pengaturan yang digunakan di kompetisi resmi. Komputer yang menjalankan controller-mu (klien) dan komputer yang menjalankan permainan (server) harus terhubung ke jaringan yang sama.

2. (Server) Jalankan Webots di server, buka world, dan aktifkan **Remote mode** di **Robot setup** pada jendela kontrol.
2. (Server) Cari tahu alamat IP server. Lihat [Menemukan alamat IP di Windows](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9).
3. (Klien) Jalankan perintah berikut di PowerShell. Ganti `<Your controller path>` dengan path ke program controller-mu, dan `<Server IP address>` dengan alamat IP yang kamu temukan di langkah sebelumnya.  
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. (Server) Mulai permainan dengan menekan **Run match**.

# Pemecahan masalah
Jika controller tidak bisa terhubung, pastikan kedua komputer bisa saling terhubung, firewall server mengizinkan port TCP 1234, dan daftar IP yang diizinkan di tab Network pada Preferences Webots kosong atau mencakup klien.

# Dokumentasi resmi
Untuk detail lebih lanjut tentang pengaturan ini, lihat [panduan Webots](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a).
