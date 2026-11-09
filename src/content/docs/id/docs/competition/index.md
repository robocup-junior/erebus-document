---
title: Persiapan kompetisi
description: Daftar periksa untuk bersiap menghadapi kompetisi RoboCupJunior Rescue Simulation.
---

Halaman ini adalah panduan untuk kompetisi internasional dengan aturan 2027. Kompetisi lokal dan regional mungkin berbeda, jadi tanyakan kepada panitiamu. [Aturan](/docs/rules/) resmi selalu berlaku.

## Jadwal {#timeline}

| Kapan | Apa |
|---|---|
| Sepanjang tahun | Ikuti [halaman acara](/docs/events/upcoming-events/) dan [forum](https://junior.forum.robocup.org/), tempat klarifikasi diumumkan |
| Minimal 4 minggu sebelumnya | Panitia memberikan petunjuk untuk formulir web persiapan wawancara |
| 3 minggu sebelum hari pertama | Batas waktu pengiriman dokumen |
| Hari persiapan | Datang lebih awal ke lokasi untuk registrasi, wawancara, dan pertemuan tim |
| Setiap ronde | World diungkapkan tepat sebelum permainan. Program tidak bisa diubah setelah batas waktu setiap ronde. |
| Setelah ronde penilaian | Technical Challenge (tantangan teknis) |

## Dokumen yang harus dikirim {#documents-to-submit}
Templat dan rubrik ada di [Situs Web Komunitas RCJ Rescue](https://rescue.rcj.cloud/).

- [ ] **Technical Description Paper (TDP).** Ikuti templatnya dengan ketat: jika tidak, skor untuk dokumen ini 0.
- [ ] **Poster,** sebagai berkas digital dan sebagai poster fisik di lokasi, tidak lebih besar dari A1.
- [ ] **Video** yang menampilkan proyekmu.
- [ ] **Video server-klien:** video singkat yang menunjukkan cara kamu menjalankan controller pada peta contoh dalam pengaturan server-klien.
- [ ] **Kode sumber** dan **formulir web** untuk wawancara.

## Pengaturan kompetisi {#competition-setup}
Permainan berjalan dengan pengaturan server-klien: panitia menjalankan server permainan dan menyediakan satu soket RJ-45, dan programmu berjalan di komputermu. Lihat [Remote Controller](/docs/competition/remote-controller/).

Bawalah:

- [ ] Komputer dengan programmu dan semua library-nya terinstal, serta Webots R2025a
- [ ] Kabel Ethernet, dan adaptor jika komputermu membutuhkannya
- [ ] Berkas `.json` robotmu, jika kamu punya robot kustom
- [ ] Poster fisik

## Pengaturan OpenGL {#opengl-settings}
Kecuali panitia mengumumkan hal lain, pengaturan berikut yang digunakan. Pengaturan ini memengaruhi apa yang dilihat kamera, jadi lakukan pengujian dengannya. Kamu bisa menemukannya di tab OpenGL pada Preferences Webots.

| Pengaturan | Nilai |
|---|---|
| Ambient Occlusion | Low |
| Texture Quality | Low |
| Max Texture Filtering | 4 |
| Shadows | Disabled |
| Anti-aliasing | Disabled |

## Menguji robotmu {#testing-your-robot}
- [ ] Jalankan di setiap world yang disertakan, terutama keempat world `2027_`, yang berisi ubin kontak dan penanda palsu.
- [ ] Buat petamu sendiri dengan [World Editor](/docs/tools/world-editor/), mencakup keempat area.
- [ ] Periksa seluruh permainan: apakah berjalan sampai akhir, mengganti baterai tepat waktu, mengirim peta, dan kembali ke start?
- [ ] Uji apa yang terjadi setelah kurangnya kemajuan (lack of progress).
- [ ] Uji di komputer yang akan kamu bawa, dan dengan pengaturan OpenGL di atas.

## Selama kompetisi {#during-the-competition}
- Hanya kapten dan wakil kapten yang boleh memasuki area kompetisi, kecuali wasit mengatakan lain.
- Wasit yang mengoperasikan simulasi. Kamu tidak boleh menyentuh peralatan permainan setelah permainan dimulai.
- Mentor tidak boleh membantu selama kompetisi.
- Bersiaplah menjelaskan pekerjaanmu: setiap anggota tim harus punya peran teknis dan memahami cara kerjanya.

## Skor akhir {#final-score}
Skor akhir di kompetisi internasional menggabungkan:

| Bagian | Bobot | Isi |
|---|---|---|
| Skor lapangan | 0,6 | Rata-rata skor lapangan yang dinormalisasi. Ronde atau ronde-ronde terburuk tidak dihitung. |
| Rubrik | 0,2 | TDP (0,6), Video (0,2), Poster (0,2) |
| Technical Challenge | 0,2 | Tugas-tugas kecil yang diumumkan di kompetisi, diselesaikan dengan memprogram ulang robotmu dalam waktu terbatas |

Skor seri ditentukan berdasarkan rata-rata skor lapangan yang dinormalisasi. SuperTeam Challenge adalah acara terpisah dengan penghargaannya sendiri.
