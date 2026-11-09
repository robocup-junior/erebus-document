---
title: Dapatkan robotmu
description: Setiap program berjalan di robot yang kamu rancang. Unduh robot pemula, atau rakit sendiri.
---

Di Erebus, **kamu yang merancang robotmu**: kamu memilih sensornya dan tempat pemasangannya, sesuai anggaran. Setiap program membutuhkan robot, jadi langkah pertama adalah mendapatkan robot dan memuatnya di Erebus.

![Robot e-puck sungguhan](../../../docs/robot/real_robot.thumbnail.jpg)

Robot ini didasarkan pada [e-puck](https://cyberbotics.com/doc/guide/epuck?version=R2023b), robot edukasi kecil berbentuk bulat dengan dua roda. Kamu menambahkan sensor ke robot itu dengan [Robot Customizer](https://robot.erebus.rcj.cloud/), lalu menyimpan rancangannya sebagai berkas `.json` yang dimuat oleh Erebus.

## Robot pemula {#the-starter-robot}
Dokumentasi ini menggunakan satu robot di semua tempat, yaitu **robot pemula**, agar setiap contoh bisa langsung berjalan tanpa diubah. Robot ini punya semua sensor yang dibutuhkan tutorial:

| Komponen | Nama di programmu | Kegunaannya |
|---|---|---|
| Dua roda | `left wheel motor`, `right wheel motor` | Bergerak |
| Encoder roda | `left wheel sensor`, `right wheel sensor` | Mengukur seberapa jauh roda berputar |
| Tiga sensor jarak | `leftDist`, `frontDist`, `rightDist` | Menemukan dinding di kiri, depan, dan kanan |
| Kamera, 64 × 40 piksel | `camera` | Menemukan penanda dinding |
| Sensor warna | `color` | Melihat lantai: lubang, rawa, dan lorong penghubung |
| GPS | `gps` | Mengetahui posisinya, untuk melaporkan penanda |
| Giroskop | `gyro` | Mengukur seberapa besar robot sudah berputar |
| Akselerometer | `accelerometer` | Mengukur percepatan |
| Lidar | `lidar` | Mengukur jarak di sekelilingnya |
| Emitter dan receiver | `emitter`, `receiver` | Berkomunikasi dengan permainan. Setiap robot memilikinya. |

Robot ini memakai 2400 dari anggaran 3000.

![Robot yang sudah jadi, dengan label dan tampilan kameranya](../../../docs/robot/build/finished.png)

## Pilih jalurmu {#choose-your-path}

**Disarankan: rakit sendiri.** Butuh sekitar 15 menit, dan kamu akan memahami setiap bagian robotmu. Ikuti [Rakit robotmu](/docs/robot/build/).

**Jika sedang buru-buru:** unduh robot yang sudah jadi dan lanjutkan ke tutorial. Kamu selalu bisa kembali dan merakitnya nanti.

<a href="/downloads/starter-robot.json" download>Unduh starter-robot.json</a>

## Muat di Erebus {#load-it-in-erebus}
1. Buka sebuah world, misalnya `game/worlds/world1.wbt`.
2. Di jendela kontrol, tekan **tombol LOAD sebelah kanan**, yang berikon robot, lalu pilih berkas `.json`-mu.
3. Periksa konsol Webots. Erebus menampilkan daftar setiap komponen beserta biayanya, dan diakhiri dengan `Your custom robot has been successfully generated!`.

:::note
Erebus v26.1 juga mencetak `PROTO parameter 'camera_width' has no matching IS field` dengan warna merah. Kamu bisa mengabaikannya: kameramu tetap punya resolusi yang kamu pilih.
:::

Robot tetap termuat sampai kamu memuat robot lain atau me-reset permainan. Selanjutnya, [jalankan program pertamamu](/docs/getting-started/).

## Merancang robotmu sendiri {#designing-your-own}
Setelah kamu memahami dasarnya, ubah robot pemula atau rancang robot baru: lebih banyak kamera dengan resolusi lebih tinggi, lebih banyak sensor jarak, sensor di tempat lain. [Referensi Robot Customizer](/docs/robot/customizer/) mencantumkan semua komponen, biaya, dan batasannya.

Jika kamu mengubah nama sebuah komponen, ubah juga di programmu.
