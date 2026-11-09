---
title: Referensi Robot Customizer
description: Tampilan, komponen, biaya, dan batasan Robot Customizer.
---

[Robot Customizer](https://robot.erebus.rcj.cloud/) memungkinkanmu memilih sensor robot dan tempat pemasangannya. Alat ini berjalan di browser-mu, dan mengekspor berkas `.json` yang dimuat oleh Erebus.

Baru pertama kali memakainya? Mulailah dengan [Rakit robotmu](/docs/robot/build/), yang merakit robot pemula langkah demi langkah. Halaman ini menjelaskan semua hal lainnya.

![Robot Customizer](../../../../docs/robot/customizer/customizer.png)

Pratinjau 3D ada di sebelah kiri, sedangkan komponen dan anggaran ada di sebelah kanan.

## Tampilan layar {#the-screen}

1. **Tambahkan komponen.** Nyalakan sakelar setiap sensor atau kamera yang kamu inginkan, dan atur jumlah sensor jarak dengan `−` dan `+`. Biaya setiap komponen ditampilkan di sebelahnya.
2. **Tetap dalam anggaran.** Bagian kanan atas menunjukkan sisa anggaran dari 3000, dan pembagiannya antara roda, sensor jarak, sensor, dan kamera. Jika kamu melebihi anggaran, alat ini memberi tahu berapa yang harus dikurangi: robot tidak bisa diekspor sampai sesuai anggaran.
3. **Tempatkan komponen.** Klik komponen di daftar atau di tampilan 3D untuk membuka pengaturannya. Seret panah di tampilan 3D, dengan **Move** (`W`) atau **Rotate** (`R`), atau ketik nilainya. Posisinya dalam satuan sepersepuluh milimeter, meskipun kotaknya bertuliskan mm. Posisi Y berkisar dari -100 hingga 370. Tombol rotasi mengarahkan sensor ke depan, belakang, kiri, kanan, atas, atau bawah dengan satu klik. Panah hijau menandai bagian depan robot.
4. **Beri nama.** Nama inilah yang dipakai programmu dengan `getDevice()`, seperti yang ditunjukkan di bawah **In your controller**. Roda mendapat dua perangkat: `<name> motor` dan `<name> sensor`. Wheel 1 berada di sisi kanan robot, dan Wheel 2 di sisi kiri.
5. **Atur resolusi kamera.** Setiap kamera punya lebar dan tinggi, yang mengubah biayanya.
6. **Ekspor.** Masukkan nama berkas di bagian atas, lalu tekan **Export**. Simpan berkasnya: dengan **Import**, atau dengan menyeret berkas itu ke halaman, kamu bisa memuatnya kembali dan melanjutkan pekerjaanmu.

![Pengaturan sebuah kamera](../../../../docs/robot/customizer/component.png)

### Tampilan yang berguna {#useful-views}
- **3D**, **Top**, **Front**, dan **Side** menampilkan robot dari sudut yang berbeda. Top berguna untuk menempatkan sensor secara simetris.
- **Labels** menampilkan nama setiap komponen.
- **Camera view** menampilkan perkiraan apa yang dilihat kamera di Webots.
- Undo, redo, dan reset ada di bagian atas.

## Menggunakannya di Erebus {#using-it-in-erebus}

Di [jendela kontrol](/docs/getting-started/#robot-setup), tekan **Robot setup**, lalu **Load file** di bawah **Robot JSON**, dan pilih berkas `.json`-mu. Lihat [Muat di Erebus](/docs/robot/#load-it-in-erebus). Erebus memeriksa anggaran dan membuat robot, dan konsol Webots menampilkan setiap komponen beserta biayanya.

Muat robotmu terlebih dahulu, baru programmu.

## Komponen {#components}

| Komponen | Biaya | Nama bawaan |
|---|---|---|
| Roda (2, wajib) | 300 per buah | `wheel1`, `wheel2` |
| Sensor jarak (hingga 8) | 50 per buah | `distance sensor1`, `distance sensor2`… |
| Giroskop | 100 | `gyro` |
| Unit inersia | 100 | `inertial_unit` |
| Akselerometer | 100 | `accelerometer` |
| Sensor warna | 100 | `colour_sensor` |
| GPS | 250 | `gps` |
| Lidar | 500 | `lidar` |
| Kamera (hingga 3) | 500, ditambah biaya resolusi | `camera1`, `camera2`, `camera3` |

Biaya resolusi kamera dihitung untuk lebar dan tingginya masing-masing: 32 atau 40 piksel berbiaya 0, 64 piksel berbiaya 100, 128 piksel berbiaya 200, dan 256 piksel berbiaya 300. Misalnya, kamera 256 × 128 berbiaya 500 + 300 + 200 = 1000.

Kamera yang baru ditambahkan beresolusi 40 × 32 piksel. Robot pemula menggunakan 64 × 40.

Kedua roda berbiaya total 600, jadi tersisa 2400 dari anggaran untuk semua komponen lainnya.

## Tips merancang {#design-tips}

- **GPS:** kamu butuh posisi untuk melaporkan penanda, dan inilah cara termudah untuk mendapatkannya.
- **Kamera:** resolusi yang lebih tinggi bisa membaca penanda dari jarak lebih jauh, tetapi biayanya lebih besar dan pengolahannya lebih lambat.
- **Lidar:** lidar melihat ke sekeliling robot, yang sangat membantu untuk pemetaan. Tempatkan di atas, dan buat datar dengan rotasi X `90`, seperti di [robot pemula](/docs/robot/build/), kalau tidak badan robot akan menghalanginya.
- **Sensor warna:** tempatkan di depan roda, agar robot bisa melihat lubang sebelum jatuh ke dalamnya.

[Rakit robotmu](/docs/robot/build/) menunjukkan contoh lengkapnya.
