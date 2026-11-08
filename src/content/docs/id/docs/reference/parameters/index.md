---
title: Referensi parameter
description: Ukuran arena, waktu permainan, pengali skor, batasan robot, dan nama perangkat pada robot pemula.
---

## Arena {#field}

| Parameter | Nilai |
|---|---|
| Ubin | 12 cm × 12 cm |
| Seperempat ubin (Area 2 dan 3) | 6 cm × 6 cm |
| Dinding | Tebal 1 cm, tinggi 6 cm |
| Korban huruf | 2 cm × 2 cm |
| Target kognitif | Diameter 5 cm |

## Permainan {#game}

| Parameter | Nilai |
|---|---|
| Waktu permainan | 8 menit waktu simulasi |
| Waktu dunia nyata | 10 menit |
| Kurangnya kemajuan otomatis | Setelah 20 detik di lokasi yang sama |
| Waktu berhenti untuk melaporkan penanda dinding | Minimal 1 detik |
| Pengali waktu di rawa | x5 pada masuk pertama, +1 setiap kali masuk lagi ke rawa yang sama, hingga x10 |
| Pengali area | 1; 1,25; 1,5; dan 2 untuk Area 1, 2, 3, dan 4 |
| Bonus keluar | +10% |
| Pengali bonus pemetaan | ketepatan × 1,2 + 1 |

## Robot {#robot}

| Parameter | Nilai |
|---|---|
| Anggaran | 3000 |
| Jumlah kamera maksimum | 3 |
| Jumlah sensor jarak maksimum | 8 |
| Jangkauan sensor jarak | 0 hingga 0,8 m |
| Akurasi GPS | 0,0025 m |
| Kecepatan roda maksimum | 6,28 rad/s |
| Lidar | 512 titik per lapisan, 4 lapisan, 0,01 hingga 1 m |

`timeStep` menentukan jumlah milidetik di antara pembaruan sensor. `int(robot.getBasicTimeStep())` mengambil time step dasar dari world, yaitu 16 ms di world Erebus v26.1.

## Nama perangkat pada robot pemula {#device-names-of-the-starter-robot}

Berikut adalah nama-nama yang diberikan ke `robot.getDevice()` untuk [robot pemula](/docs/robot/). Pada robot buatanmu sendiri, kamu memilih namanya di [Robot Customizer](/docs/robot/customizer/#components). Emitter dan receiver selalu tersedia.

| Perangkat | Nama |
|---|---|
| Motor roda | `left wheel motor`, `right wheel motor` |
| Encoder roda | `left wheel sensor`, `right wheel sensor` |
| Sensor jarak | `leftDist`, `frontDist`, `rightDist` |
| Kamera | `camera` |
| Sensor warna | `color` |
| GPS | `gps` |
| Giroskop | `gyro` |
| Akselerometer | `accelerometer` |
| Lidar | `lidar` |
| Emitter | `emitter` |
| Receiver | `receiver` |
