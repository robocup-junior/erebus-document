---
title: Yang baru di v27
description: Perubahan di Erebus v27 dan aturan 2027 yang memengaruhi robotmu.
---

Erebus v27 menerapkan aturan 2027. Jika kamu beralih dari v26, berikut perubahan yang memengaruhi robotmu.

| Topik | Sampai 2026 | Mulai 2027 |
|---|---|---|
| Baterai | - | Baru: robot memiliki [baterai](/docs/rules/#the-battery) yang berkurang sesuai kecepatan motornya. Jika habis, permainan berakhir. |
| Ubin kontak | - | Baru: [ubin kontak](/docs/rules/#contact-tiles) berwarna sian. Diam 5 detik di atasnya akan mengganti baterai. Ubin ini dipetakan sebagai `k`. |
| Rawa | Waktu permainan berjalan lebih cepat: x5 saat pertama masuk, hingga x10 | Baterai berkurang lebih cepat. Waktu permainan tidak terpengaruh. |
| Korban | Simbol Φ, Ψ, Ω | [Wajah smiley](/docs/rules/#smiley-victims): sedih (terluka), datar (stabil), dan senang (tidak terluka). Tetap dilaporkan sebagai `H`, `S`, `U`. |
| Korban palsu | Simbol tiga dimensi | Wajah smiley tiga dimensi |
| Informasi permainan | Balasan `G` berukuran 16 byte | Balasan `G` berukuran 20 byte, dan diakhiri dengan level baterai. Lihat [Informasi permainan](/docs/programming/communication/#game-information). |
| Jarak pelaporan | Erebus v26 menerima laporan hingga 9 cm dari penanda | Setengah ubin (6 cm), sesuai aturan |
| Area | Empat area, Area 4 opsional | Hingga empat area: Area 1 selalu ada, dan panitia boleh tidak menyertakan Area 2 sampai 4 |
| Webots | R2023b | **R2025a** |
| Python | 3.9 atau lebih baru | 3.10 atau lebih baru |

[Menjalankan pertama kali](/docs/getting-started/) menjelaskan cara memakai jendela kontrol Erebus v27.

## Memperbarui programmu {#updating-your-program}

1. Baca balasan `G` sebagai 20 byte. Program yang hanya menerima 16 byte tidak lagi menerima informasi permainan.
1. Pantau level baterai, dan rencanakan rutemu agar robot mencapai ubin kontak sebelum baterai habis. Lihat [Baterai](/docs/programming/battery/).
1. Tambahkan ubin kontak ke petamu, sebagai `k`.
1. Perbarui deteksi korbanmu untuk wajah smiley. Huruf yang kamu laporkan tidak berubah.
1. Laporkan penanda dari jarak lebih dekat: titik tengah robot dan posisi yang kamu kirim harus berada dalam setengah ubin dari penanda.
1. Rawa sekarang menghabiskan baterai, bukan waktu, jadi perhitungkan dalam rencana baterai.
1. Instal Webots R2025a dan Python 3.10 atau lebih baru, dan periksa apakah programmu masih berjalan. Lihat [Instalasi](/docs/installation/).
