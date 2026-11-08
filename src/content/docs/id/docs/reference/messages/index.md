---
title: Referensi pesan
description: Referensi untuk pesan-pesan yang dipertukarkan dengan Main Supervisor.
---

Pesan dikirim dengan perangkat `emitter` dan diterima dengan perangkat `receiver`. Lihat [tutorial Komunikasi](/docs/programming/communication/) untuk contoh-contohnya.

String format di bawah ini mengikuti format modul Python [struct](https://docs.python.org/3/library/struct.html).

## Dikirim oleh robot {#sent-by-the-robot}

| Pesan | Format | Panjang | Kegunaan |
|---|---|---|---|
| Melaporkan penanda dinding | `i i c`: x, z, jenis | 9 byte | Posisinya dalam sentimeter, dan jenisnya salah satu dari `H`, `S`, `U`, `F`, `P`, `C`, `O`. Robot harus sudah berhenti minimal 1 detik. |
| Data peta | `2i` diikuti teks UTF-8: baris, kolom, sel yang dipisahkan koma | Panjang lainnya | Menyimpan peta, tanpa mengevaluasinya |
| `M` | `c` | 1 byte | Mengevaluasi peta yang tersimpan. Ini hanya bisa dilakukan sekali. |
| `L` | `c` | 1 byte | Memicu kurangnya kemajuan (lack of progress) |
| `G` | `c` | 1 byte | Meminta informasi permainan |
| `E` | `c` | 1 byte | Mengakhiri permainan. Memberikan bonus keluar jika robot berada di ubin awal dan sudah mengidentifikasi penanda dinding. |

Erebus membedakan pesan-pesan ini berdasarkan panjangnya, jadi laporan harus tepat 9 byte.

## Diterima oleh robot {#received-by-the-robot}

| Pesan | Format | Panjang | Kegunaan |
|---|---|---|---|
| `L` | `c` | 1 byte | Kurangnya kemajuan telah terjadi |
| `G` | `c f i i`: `G`, skor, sisa waktu permainan, sisa waktu dunia nyata | 16 byte | Balasan untuk `G`. Waktunya dalam detik. |

Perhatikan bahwa paket `G` berisi padding, karena format `struct` di atas menyejajarkan float: skor dimulai di byte 4, dan waktunya di byte 8 dan 12.

## Fungsi Webots yang umum {#common-webots-functions}

| Fungsi | Deskripsi |
|---|---|
| `robot.getDevice(name)` | Mengambil perangkat berdasarkan nama. Di C++, gunakan `robot->getMotor(name)`, `robot->getCamera(name)`, dan seterusnya. |
| `robot.step(timeStep)` | Memajukan simulasi. Mengembalikan -1 saat simulasi berakhir. |
| `robot.getTime()` | Mengambil waktu simulasi, dalam detik |
| `device.enable(timeStep)` | Mengaktifkan sensor |
| `motor.setPosition(float("inf"))` | Membiarkan motor berputar tanpa batas |
| `motor.setVelocity(speed)` | Mengatur kecepatan motor, dalam radian per detik |
