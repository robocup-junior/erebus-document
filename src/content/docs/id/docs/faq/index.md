---
title: FAQ
description: Pertanyaan yang sering diajukan tentang Erebus dan kompetisinya.
---

## Tentang Erebus {#about-erebus}

### Apakah aku butuh robot sungguhan? {#do-i-need-a-real-robot}
Tidak. Semuanya terjadi di simulator. Robotnya adalah e-puck virtual yang kamu rancang.

### Bahasa pemrograman apa saja yang bisa kupakai? {#which-programming-languages-can-i-use}
Python dan C/C++ dibahas di dokumentasi ini. Erebus juga bisa memuat controller Java dan MATLAB, tetapi dokumentasi ini tidak punya contoh untuk keduanya.

### Apakah aku butuh komputer yang kuat? {#do-i-need-a-powerful-computer}
Tidak, lihat [persyaratan](/docs/installation/). Komputer yang lebih lambat mungkin perlu [pengaturan grafis yang lebih rendah](/docs/troubleshooting/#the-simulation-runs-too-slowly).

### Bisakah aku memakai versi Webots yang lebih baru? {#can-i-use-a-newer-version-of-webots}
Tidak. Erebus v27 berjalan di Webots **R2025a**. Kamu tetap bisa menginstal versi lain di sampingnya, misalnya R2023b untuk Erebus v26.

### Bisakah aku memakai library seperti OpenCV atau NumPy? {#can-i-use-libraries-like-opencv-or-numpy}
Bisa. Kode eksternal diperbolehkan, asalkan kamu mencantumkan pembuatnya dan menghormati lisensinya. Tim sebaiknya mengutamakan belajar, dan harus bisa menjelaskan cara kerja solusi mereka.

## Permainannya {#the-game}

### Apa urutan terbaik untuk mempelajari semuanya? {#what-is-the-best-order-to-learn-things}
Ikuti [jalur belajar](/docs/#the-learning-path): pahami permainannya, dapatkan robotmu, jalankan, pelajari dasarnya, lalu mainkan permainannya.

### Apakah aku harus membuat robot sebelum memprogram? {#do-i-need-to-make-a-robot-before-programming}
Ya. Setiap program berjalan di robot yang kamu muat, jadi mulailah dengan [Dapatkan robotmu](/docs/robot/). Kamu bisa mengunduh robot pemula yang sudah jadi jika sedang buru-buru.

### Di mana robot mulai? {#where-does-the-robot-start}
Di ubin awal, yang berada di Area 1. Robot selalu menghadap ke arah yang tidak ada dindingnya.

### Apa yang terjadi jika robot jatuh ke lubang? {#what-happens-if-the-robot-falls-into-a-hole}
Terjadi kurangnya kemajuan (lack of progress): robot kembali ke checkpoint terakhir yang dikunjunginya, dan kamu kehilangan 5 poin.

### Apakah robot harus kembali ke titik awal? {#does-the-robot-have-to-return-to-the-start}
Tidak, tetapi kembali ke ubin awal dan mengirim `E` memberikan bonus keluar 10%, asalkan robot sudah mengidentifikasi minimal satu penanda dinding.

### Bagaimana robotku tahu berapa sisa waktunya? {#how-can-my-robot-tell-how-much-time-is-left}
Dengan [pesan `G`](/docs/programming/communication/#game-information). Ada dua pewaktu, dan permainan berakhir saat salah satunya habis.

### Apa yang terjadi kalau baterai habis? {#what-happens-when-the-battery-runs-out}
Permainan berakhir. Untuk menghindarinya, berhentilah 5 detik di ubin kontak berwarna sian, yang akan mengganti baterai. Programmu bisa membaca level baterai dengan [pesan `G`](/docs/programming/communication/#game-information). Lihat [Baterai](/docs/programming/battery/).

### Apakah melaju pelan menghemat baterai? {#does-driving-slowly-save-the-battery}
Baterai berkurang sesuai kecepatan motor, jadi robot yang pelan memakai lebih sedikit baterai per detik, tetapi juga menempuh jarak lebih pendek dalam waktu itu. Temukan keseimbangan terbaik untuk robotmu dengan pengujian.

### Apakah aku harus menjelajahi Area 4? {#do-i-have-to-explore-area-4}
Tidak. Area ini opsional, tetapi penandanya bernilai paling tinggi: poin tertinggi, dikalikan 2.

### Apakah aku harus memetakan Area 4? {#do-i-have-to-map-area-4}
Tidak. Semua selnya bernilai `*`, jadi kamu cukup mengisinya.

### Bolehkah robotku mengetahui peta sebelumnya? {#can-my-robot-know-the-map-beforehand}
Tidak. Memetakan arena atau lokasi penanda dinding terlebih dahulu dilarang.

## Kompetisi {#the-competition}

### Bagaimana cara ikut serta? {#how-do-i-take-part}
Melalui kompetisi RoboCupJunior di wilayahmu. Perwakilan Regional (Regional Representative) di wilayahmu membagikan jatah tempat untuk kompetisi internasional. Lihat [situs web RoboCupJunior](https://junior.robocup.org/).

### Apa yang harus kusiapkan? {#what-should-i-prepare}
Lihat [Persiapan kompetisi](/docs/competition/).

### Di mana aku bisa bertanya tentang aturan? {#where-can-i-ask-about-the-rules}
Di [Forum RoboCupJunior](https://junior.forum.robocup.org/). Klarifikasi juga diumumkan di sana, jadi periksa forum itu secara rutin.
