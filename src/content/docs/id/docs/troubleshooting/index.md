---
title: Pemecahan masalah
description: Solusi untuk masalah umum saat menginstal dan menjalankan Erebus.
---

Pertama-tama, periksa konsol Webots. Sebagian besar masalah menampilkan pesan error di sana.

## Instalasi {#installation}

### `No module named 'cv2'` {#no-module-named-cv2}
OpenCV belum terinstal di Python yang dipakai Webots. Instal [library yang dibutuhkan](/docs/installation/#python-libraries) di Python tersebut. Jika kamu punya beberapa instalasi, pengaturan **Python command** di bawah ini menunjukkan instalasi mana yang dipakai Webots.

### `WARNING: Python was not found` {#warning-python-was-not-found}
Webots tidak tahu di mana Python berada.

1. Temukan Python. Di macOS dan Linux, jalankan `which python3` di terminal. Di Windows, pastikan bahwa mengetik `python` di Command Prompt yang baru dibuka akan menjalankan Python. Jika tidak, instal ulang Python, dan centang opsi untuk menambahkannya ke PATH.
2. Buka Preferences Webots: **Webots > Preferences** di macOS, **Tools > Preferences** di Windows dan Linux.

   ![Item Preferences di menu Webots](../../../docs/troubleshooting/preferences_open.png)

3. Atur path di kolom **Python command**. Di Windows, `python` biasanya sudah cukup.

   ![Kolom Python command di Preferences Webots](../../../docs/troubleshooting/preferences.png)

### `ERROR: Skipped PROTO 'custom_robot'` {#error-skipped-proto-custom_robot}
Pesan ini muncul saat pertama kali kamu membuka world, sebelum Erebus menyiapkan model robot. Erebus menyiapkannya dan memuat ulang world dengan sendirinya, jadi kamu bisa mengabaikannya.

### Pewaktu permainan tidak muncul {#the-game-timer-does-not-appear}
Saat pertama kali dijalankan, prosesnya bisa memakan beberapa menit karena Erebus menginstal library. Jika prosesnya tidak kunjung selesai, periksa konsol untuk melihat error. Jika instalasi otomatis tidak berhasil, instal sendiri [library yang dibutuhkan](/docs/installation/#python-libraries).

## Menjalankan Erebus {#running-erebus}

### Jendela kontrol tidak muncul {#the-control-window-does-not-appear}
Jendela kontrol adalah halaman web yang dibuka oleh Webots.

1. Jika kamu menutupnya, atau browser-mu memblokirnya, muat ulang world dengan tombol muat ulang Webots. Erebus akan membuka jendela kontrol lagi.
2. Jika tidak, pastikan Scene Tree ditampilkan, dengan **Tools > Scene Tree**.
3. Cari **DEF MAINSUPERVISOR Robot** di Scene Tree, klik kanan, lalu pilih **Show Robot Window**.

Jendela kontrol memiliki alamat pribadi, yang berubah setiap kali world dimuat. Jika kamu membuka jendela di `localhost:1234` sendiri, jendela itu menampilkan **Read-only**, dan tombolnya tidak berfungsi.

### Jendela kontrol menampilkan "Access log incomplete" {#the-control-window-says-access-log-incomplete}
Peringatan ini muncul saat [Wireshark](/docs/installation/#optional-wireshark) tidak terinstal. Peringatan ini untuk panitia di kompetisi: tekan **Acknowledge**, dan berlatihlah seperti biasa.

![Opsi Show Robot Window di Scene Tree](../../../docs/troubleshooting/showrobot.png)

### Layar Webots kosong atau hitam {#the-webots-screen-is-blank-or-black}
Salin berkas unduhan dan ekstrak ke folder terpisah sebelum membuka world.

### Simulasi berjalan terlalu lambat {#the-simulation-runs-too-slowly}
Ini kemungkinan karena performa komputermu. Menurunkan kualitas grafis mungkin membantu:

1. Buka Preferences Webots.
2. Buka tab **OpenGL**.
3. Ubah pengaturannya.

![Tab OpenGL di Preferences Webots](../../../docs/troubleshooting/opengl.png)

Pengaturan ini mengubah apa yang dilihat kamera, dan kompetisi menggunakan [pengaturannya sendiri](/docs/competition/#opengl-settings), jadi periksa juga programmu dengan pengaturan tersebut.

## Robotmu {#your-robot}

### Programku menyatakan perangkat (device) tidak ditemukan {#my-program-says-a-device-was-not-found}
Lihat di bawah. Periksa juga bahwa kamu sudah memuat robotmu di bawah **Robot JSON** pada **Robot setup** sebelum memulai permainan.

## Programmu {#your-program}

### `Device "..." was not found` {#device--was-not-found}
Nama perangkat di programmu tidak cocok dengan robotmu. Nama-nama perangkat robot pemula ada di [Referensi](/docs/reference/parameters/#device-names-of-the-starter-robot). Untuk robotmu sendiri, namanya adalah nama yang kamu atur di [Robot Customizer](/docs/robot/customizer/). Pastikan robotmu sudah dimuat.

### Tidak terjadi apa-apa saat aku melaporkan penanda dinding {#nothing-happens-when-i-report-a-wall-token}
Aktifkan **Enable debugging** di **Advanced setup** pada jendela kontrol, lalu periksa konsol. Penyebab paling umum adalah robot belum berhenti setidaknya 1 detik, koordinat tidak dikonversi ke sentimeter, dan robot atau posisinya lebih dari setengah ubin (6 cm) dari penanda. Lihat [Komunikasi](/docs/programming/communication/#scoring-wall-tokens).

### Laporanku dianggap salah identifikasi {#my-reports-are-misidentifications}
Robot harus berada paling jauh setengah ubin dari penanda dan di sisi dinding yang sama, dan setiap penanda hanya bisa dihitung sekali. Melaporkan penanda palsu juga dihitung sebagai salah identifikasi.

### Permainan berakhir dengan "Battery depleted" {#the-game-ends-with-battery-depleted}
Baterai habis. Sebelum itu terjadi, berhentilah 5 detik di ubin kontak untuk menggantinya. Lihat [Baterai](/docs/programming/battery/).

### Programku tidak lagi menerima informasi permainan {#my-program-no-longer-receives-the-game-information}
Sejak Erebus v27, balasan `G` berukuran 20 byte, dengan level baterai di akhir. Perbarui pemeriksaan panjang di programmu. Lihat [Informasi permainan](/docs/programming/communication/#game-information).

### Peta mendapat 0% atau error penilaian {#the-map-gets-0-or-a-scoring-error}
Petamu harus memuat ubin awal (`5`), dan hanya bisa dievaluasi sekali. Lihat [Mengirim peta](/docs/programming/map-bonus/).

### Controller tidak bisa terhubung dalam mode remote {#the-controller-cannot-connect-in-remote-mode}
Lihat panduan [Remote Controller](/docs/competition/remote-controller/) untuk sistem operasimu.

## Masih buntu? {#still-stuck}
Tanyakan di [server Discord](https://discord.com/invite/6FJxZxk), atau [buat issue](https://github.com/robocup-junior/erebus/issues). Sertakan sistem operasimu, versi Erebus dan Webots-mu, serta pesan di konsol.
