---
title: World Editor
description: Cara membuat world-mu sendiri dengan Erebus World Editor.
---

## Latar belakang {#background}

Setelah robotmu bisa menaklukkan peta bawaan dan labirin sederhana, mungkin kamu menginginkan sesuatu yang lebih menantang, atau ingin menguji skenario tertentu yang tidak tercakup oleh peta bawaan.
Untuk itu, tersedia [Erebus World Editor](https://world.erebus.rcj.cloud/) daring. Kamu menggambar peta di browser-mu, dan alat ini mengekspor berkas world `.wbt` yang bisa kamu jalankan di Erebus.

![Peta yang sudah jadi di World Editor](../../../../docs/tools/world-editor/overview.png)

Jika kamu hanya membuat peta kecil untuk pengujian, apakah arenanya sesuai aturan atau tidak mungkin tidak terlalu penting. Namun, jika kamu berencana membuat arena kompetisi, bacalah [Aturan Simulasi](https://junior.robocup.org/wp-content/uploads/2026/02/RCJRescueSimulation2026-final.pdf) resmi. Editor memeriksa petamu berdasarkan aturan selama kamu bekerja.

Editor ini punya panduan bawaan: tekan **Guide** di kanan bawah untuk pelajaran praktik yang membuat peta contoh (sekitar 15 menit), tur pengenalan layar, atau pelajaran tentang Room 4. Bahasa editor bisa diganti di sebelahnya.

## Memulai peta {#starting-a-map}
Saat membuka editor, pilih **aturan tahun berapa** yang ingin kamu ikuti, lalu tekan **New map**. **Pilih aturan 2026 untuk Erebus v26.** Aturan 2027 adalah draf untuk versi Erebus berikutnya.

![Layar awal World Editor](../../../../docs/tools/world-editor/start.png)

Pekerjaanmu disimpan di browser, tetapi akan hilang di browser lain atau saat data browsing dihapus. Simpan peta yang penting sebagai JSON dengan tombol simpan di bilah atas, dan buka lagi dengan tombol buka.

Urutan kerja yang baik adalah ukuran dan garis luar, ruangan (room), lorong penghubung, dinding, lantai, rintangan dan korban, Room 4, dan terakhir pemeriksaan dan ekspor. Alat-alatnya ada di sebelah kiri, masing-masing dengan pintasan keyboard. Pengaturan alat yang dipilih muncul di panel di sebelahnya.

| Alat | Tombol | Kegunaan |
|---|---|---|
| Select | `S` | Memilih, memindahkan, menyalin, dan menempel bagian peta |
| Move | `H` | Menggeser tampilan |
| Outline | `X` | Mengatur ukuran dan bentuk peta |
| Rooms | `M` | Mewarnai Room 1 sampai 4 (area dalam aturan) |
| Passages | `P` | Menghubungkan ruangan dengan lorong penghubung |
| Line | `L` | Menggambar dinding |
| Curve | `A` | Menggambar dinding melengkung di Room 3 |
| Eraser | `E` | Menghapus dinding, lantai, rintangan, dan korban |
| Floor | `F` | Mengatur checkpoint, lubang, rawa, dan ubin awal |
| Obstacle | `O` | Menempatkan rintangan |
| Victims | `V` | Menempatkan korban huruf, target kognitif, dan penanda palsu |

Gunakan roda mouse untuk zoom, seret sambil menahan Spasi untuk menggeser tampilan, dan tekan `⌘Z` atau `Ctrl+Z` untuk undo.

## Ukuran dan garis luar {#size-and-outline}
Dengan alat **Outline**, atur ukuran peta dalam ubin. Dinding luar ditambahkan secara otomatis. **Outline (uneven)** memungkinkanmu mengklik ubin untuk mengeluarkannya dari peta, dan kamu juga bisa menyisipkan dan menghapus baris dan kolom di tempat yang kamu klik.

![Alat Outline](../../../../docs/tools/world-editor/outline.png)

## Ruangan dan lorong penghubung {#rooms-and-passages}
Dengan alat **Rooms**, warnai ubin-ubin setiap ruangan. Dinding ditambahkan secara otomatis di perbatasan antar-ruangan. Lalu, dengan alat **Passages**, hubungkan ruangan-ruangannya: warna setiap lorong penghubung dipilih sesuai ruangan yang dihubungkannya.

![Alat Rooms](../../../../docs/tools/world-editor/rooms.png)

![Alat Passages](../../../../docs/tools/world-editor/passages.png)

## Dinding {#walls}
Gunakan alat **Line** untuk menggambar dinding: di tepi ubin pada Room 1, dan di seperempat ubin pada Room 2 dan 3. Gunakan alat **Curve** di Room 3, dengan menunjuk seperempat ubin untuk memilih lengkungannya. Mengklik lengkungan yang sama sekali lagi akan menghapusnya.

![Alat Line untuk dinding](../../../../docs/tools/world-editor/walls.png)

## Lantai dan rintangan {#floors-and-obstacles}
Dengan alat **Floor**, pilih jenis lantai dan klik ubin untuk mengaturnya. Ubin awal harus berada di Room 1, dan world tidak bisa diekspor tanpanya. Satu ubin hanya bisa menjadi salah satu dari lubang, rawa, checkpoint, rintangan, ubin awal, atau lorong penghubung.

![Alat Floor](../../../../docs/tools/world-editor/floors.png)

Dengan alat **Obstacle**, pilih bentuk dan klik ubin. Di Room 1 sampai 3 ada satu rintangan per ubin, dengan titik tengahnya di ubin itu. Klik rintangan untuk mengubah ukuran, tinggi, warna, dan rotasinya dengan pegangan dan panelnya.

![Alat Obstacle](../../../../docs/tools/world-editor/obstacles.png)

## Korban dan target kognitif {#victims-and-cognitive-targets}
Dengan alat **Victims**, pilih jenisnya dan klik di dekat dinding. Kamu bisa menempatkan:

- Korban huruf asli: terluka (harmed), stabil (stable), dan tidak terluka (unharmed)
- Korban huruf palsu dengan simbol tiga dimensi
- Target kognitif: pilih hazmat-nya, dan pilih warna cincinnya jika kamu mau. Jumlahnya ditampilkan, dan jumlah itulah yang menentukan jenisnya
- Target palsu, yang cincinnya berjumlah selain 0 sampai 3

Di Room 1 bisa ada satu korban di setiap sisi ubin. Di Room 2 dan 3, korban ditempatkan di permukaan dinding 6 cm, dan lengkungan punya dua tempat, di dalam dan di luar. Di bawah **Turn**, pilih rotasi tetap, atau rotasi acak untuk setiap penanda baru. Klik penanda yang sudah ditempatkan untuk mengubah atau menghapusnya, atau seret di sepanjang dindingnya.

![Alat Victims](../../../../docs/tools/world-editor/victims.png)

## Room 4 {#room-4}
Room 4 tidak berbasis ubin, jadi ruangan ini dibuat sebagai gambar. Dengan alat **Rooms**, warnai Room 4, lalu tekan **Draw room 4** (atau klik dua kali ruangannya) untuk membuka pembuat Room 4.

![Pembuat Room 4](../../../../docs/tools/world-editor/room4.png)

Apa yang kamu gambar dengan warna hitam akan menjadi dinding. Pembuat ini punya alat untuk menggambar bebas dan menggambar garis, lengkungan, busur, persegi panjang, elips, poligon, dan bentuk dari ikon, serta alat untuk korban dan rintangan. Kamu bisa menempatkan rintangan sebanyak yang kamu mau di Room 4. Garis-garis merah menunjukkan tempat yang tidak bisa dilalui robot, dan kamu harus menyisakan jalur selebar sekitar satu ubin agar robot bisa lewat.

Setelah selesai, tekan **OK**: gambarnya muncul sebagai Room 4 di peta dan masuk ke world yang diekspor. Tombol-tombol di kanan atas pembuat ini menyimpan gambar sebagai PNG, agar kamu bisa memakai Room 4 yang sama di peta lain, dan membuka gambar PNG atau JPEG.

## Memeriksa petamu {#checking-your-map}
Setiap perubahan diperiksa berdasarkan aturan, di kartu **Checks** di kanan atas. Tanda ✕ merah adalah masalah yang mencegah world diekspor, dan tanda ! kuning adalah peringatan yang patut diperhatikan. Klik sebuah item untuk menuju ke sana. **Fix** memperbaiki satu item, dan **Fix all that can be fixed** memperbaiki semuanya.

![Peta baru di World Editor, dengan kartu Checks](../../../../docs/tools/world-editor/new_map.png)

Tombol **Linear** di bilah atas mewarnai setiap ubin sebagai linear atau mengambang, yang menentukan nilai penanda di sana.

![Ubin linear dan mengambang ditampilkan di peta](../../../../docs/tools/world-editor/linear.png)

Trofi di bilah atas menampilkan **skor maksimum** peta, yang dihitung dengan aturan penilaian, beserta porsi setiap ruangan dan skor dengan bonus keluar dan bonus pemetaan.

![Skor maksimum peta](../../../../docs/tools/world-editor/max_score.png)

## Mengekspor dan menjalankan world-mu {#exporting-and-running-your-world}
Atur nama peta di bilah atas, lalu tekan tombol **.wbt** di kanan atas. Lalu:

1. Salin berkas `.wbt` ke folder `game/worlds` milik Erebus. Berkas itu harus berada di folder tersebut, karena world-nya memakai berkas-berkas dari Erebus.
1. Buka di Webots, atau pilih dengan tombol **Worlds** di [jendela kontrol](/docs/getting-started/).

![Peta contoh dari panduan editor, berjalan di Erebus v26.1.](../../../../docs/tools/world-editor/exported_world.png)

*Peta contoh dari panduan editor, berjalan di Erebus v26.1.*

Berkas `.wbt` tidak bisa diubah kembali menjadi peta yang bisa kamu edit, jadi simpan juga berkas JSON-nya.
