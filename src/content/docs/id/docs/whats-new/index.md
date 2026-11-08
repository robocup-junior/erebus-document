---
title: Yang baru di v26
description: Perubahan di Erebus v26 dan aturan 2026 yang memengaruhi robotmu.
---

Erebus v26 menerapkan aturan 2026. Jika kamu berasal dari versi sebelumnya, inilah perubahan yang memengaruhi robotmu.

| Topik | Hingga 2025 | Mulai 2026 |
|---|---|---|
| Korban huruf (Letter victims) | Huruf H, S, U | Simbol Φ (terluka), Ψ (stabil), Ω (tidak terluka). Tetap dilaporkan sebagai `H`, `S`, `U`. |
| Tanda hazmat (Hazmat signs) | Empat label hazmat | Digantikan oleh [target kognitif](/docs/rules/#cognitive-targets) (cognitive targets): cincin berwarna konsentris yang nilainya dijumlahkan menjadi jenisnya. Tetap dilaporkan sebagai `F`, `P`, `C`, `O`. |
| Penanda palsu | - | Baru: [korban palsu](/docs/rules/#fake-victims) (fake victims) dengan huruf tiga dimensi, dan target kognitif yang jumlahnya bukan 0 sampai 3. Jangan laporkan atau petakan. |
| Rawa (Swamps) | Waktu terpakai 5x lebih cepat | Masuk pertama ke rawa bernilai x5, dan setiap kali masuk lagi ke rawa yang sama menambah 1, hingga x10. |
| Rintangan di peta | Tidak dipetakan | Ubin dengan rintangan dipetakan sebagai `x`. |
| Bonus peta | Hingga x2 | Pengalinya sekarang ketepatan × 1,2 + 1. |
| Derau sensor | - | GPS memiliki derau. Panitia tidak akan mengubah tingkat derau untuk kompetisi. |
| Pelaksanaan permainan | Diumumkan per acara | Pengaturan server-klien: controller-mu berjalan di komputermu sendiri, terhubung ke server permainan melalui Ethernet. Lihat [Remote Controller](/docs/competition/remote-controller/). |
| Dokumen | TDP, Poster, Video | Ditambah video singkat yang menunjukkan cara kamu menjalankan controller dengan pengaturan server-klien. |
| Permainan yang terlewat | -50 poin | 0 poin. |

Versi Webots tidak berubah: Erebus v26 tetap berjalan di Webots **R2023b**.

Dua versi yang dirilis setelah v26.0.0 tidak mengubah aturan. v26.0.1 menambahkan world contoh dengan korban palsu dan skrip yang mengubah korban di world yang sudah ada menjadi palsu, dan v26.1 memperbaiki cara rintangan ditandai di Area 4.

## Memperbarui programmu {#updating-your-program}

1. Perbarui deteksi korbanmu ke simbol-simbol baru. Huruf yang kamu laporkan tidak berubah.
2. Ganti deteksi hazmat dengan [pembacaan target kognitif](/docs/programming/wall-tokens/#reading-a-cognitive-target).
3. Pastikan programmu tidak melaporkan penanda palsu, dan tidak memasukkannya ke peta.
4. Tambahkan rintangan ke petamu, sebagai `x`.
5. Rencanakan rutemu dengan memperhatikan rawa yang baru: setiap kali robot masuk ke rawa yang sama, waktu yang terbuang makin banyak.
6. Latih [pengaturan server-klien](/docs/competition/remote-controller/).
