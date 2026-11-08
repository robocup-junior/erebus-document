---
title: Ringkasan aturan
description: "Ringkasan aturan RoboCupJunior Rescue Simulation 2026: arena, penanda dinding, penilaian, dan kompetisi."
---

:::note
Halaman ini adalah ringkasan untuk membantumu memulai. Satu-satunya aturan resmi adalah [RoboCupJunior Rescue Simulation Rules 2026](https://junior.robocup.org/wp-content/uploads/2026/02/RCJRescueSimulation2026-final.pdf) (terakhir diperbarui 2026-02-11). Jika halaman ini berbeda dengan aturan resmi, aturan resmi yang berlaku.

Koreksi dan klarifikasi diumumkan di [Forum resmi RoboCupJunior](https://junior.forum.robocup.org/). Setiap tim bertanggung jawab untuk memeriksanya.
:::

## Permainan dalam satu menit {#the-game-in-one-minute}
Robotmu dijatuhkan ke dalam labirin yang tidak dikenal, sendirian. Dalam 8 menit, tanpa bantuan darimu, robot harus:

1. **Menjelajahi** labirin tanpa terjebak atau jatuh ke lubang.
2. **Menemukan penanda dinding** (wall tokens), yaitu korban dan tanda bahaya (hazard signs) di dinding, lalu melaporkan apa masing-masing penanda itu.
3. **Memetakan** labirin, dan mengirim petanya di akhir.
4. **Kembali** ke tempat awalnya.

Semua bagian di bawah ini menjelaskan keempat tugas tersebut secara detail. Kamu tidak perlu mengingat semuanya sekarang: kembalilah ke sini saat kamu memprogram setiap bagian.

## Misi dan tujuan {#mission-and-objective}
![Tampilan atas arena Erebus dengan empat area](../../../docs/rules/rules_environment.png)

Robot harus menjelajahi lingkungan yang tidak dikenal secara mandiri sambil menjaga dirinya agar tidak bermasalah. Ada tiga misi utama:

- Menavigasi labirin yang rumit tanpa terjebak
- Memetakan lingkungan dengan akurat
- Menemukan dan mengidentifikasi penanda dinding: korban huruf (letter victims) dan target kognitif (cognitive targets)

## Arena {#the-field}
Arena bisa dibagi menjadi empat area, dan setiap lorong penghubung antar-area selebar satu ubin standar. Ubin adalah konsep yang dipakai untuk membuat arena, bukan struktur fisik.

- Satu ubin berukuran **12 cm × 12 cm**. Di Area 2 dan 3, setiap ubin dibagi menjadi empat **seperempat ubin** (quarter tiles) berukuran 6 cm × 6 cm.
- Dinding memiliki **tebal 1 cm dan tinggi 6 cm**.
- Jalur setidaknya selebar robot, dan bisa terbuka menjadi ruang yang lebih lebar.

![Contoh tata letak dinding di area 1, 2, dan 3](../../../docs/rules/rules_tiles.png)

| Area | Dinding | Catatan |
|---|---|---|
| Area 1 | Bisa ditempatkan di tepi setiap ubin | Ubin awal berada di area ini |
| Area 2 | Bisa ditempatkan di tepi setiap seperempat ubin | |
| Area 3 | Bisa ditempatkan di tepi setiap seperempat ubin | Sudut 90° bisa dibulatkan menjadi seperempat lingkaran |
| Area 4 (opsional) | Tidak berbasis ubin; dinding dan rintangan ditempatkan secara bebas | Bisa berisi benda seperti kotak, dan mungkin membutuhkan gerakan diagonal |

### Lorong penghubung antar-area {#passages-between-areas}
Lorong penghubung (passages) adalah satu ubin dengan dinding di dua sisinya, sehingga punya pintu masuk dan keluar yang jelas. Warna lantainya memberitahumu area mana yang dihubungkannya:

![Tabel warna lorong penghubung antara setiap pasangan area](../../../docs/rules/rules_passages.png)

Korban huruf tidak ditempatkan di lorong penghubung.

### Ubin linear dan ubin mengambang {#linear-and-floating-tiles}
Ubin yang mengarah ke ubin awal dengan terus menyusuri dinding paling kiri atau paling kanan adalah **ubin linear** (linear tiles). Semua ubin lainnya adalah **ubin mengambang** (floating tiles). Penanda di ubin mengambang bernilai lebih tinggi. Seperempat ubin tidak diperhitungkan, dan lubang hitam dihitung sebagai dinding virtual di sini.

![Arena yang menunjukkan ubin linear berwarna abu-abu dan ubin mengambang berwarna merah muda](../../../docs/rules/rules_linear_floating.png)

### Checkpoint {#checkpoints}
Ubin berwarna perak adalah checkpoint (titik pemeriksaan), dan bisa ditempatkan di mana saja di arena. Area 4 berisi checkpoint tepat setelah lorong penghubungnya. Setelah kurangnya kemajuan, robot mulai lagi dari checkpoint terakhir yang dikunjunginya.

## Rawa, rintangan, dan lubang {#swamps-obstacles-and-holes}
![Arena dengan rawa, lubang, dan rintangan](../../../docs/rules/rules_obstacles.png)

* **Rawa** (swamps, ubin cokelat) membuat waktu permainan berjalan lebih cepat selama robot berada di atasnya. Saat pertama kali robot masuk ke rawa, waktu berjalan 5 kali lebih cepat. Setiap kali masuk lagi ke rawa yang sama, pengalinya bertambah satu, hingga batas x10.
* **Rintangan** (obstacles) bisa terpasang di lantai, bisa berbentuk dan berwarna apa saja, dan memengaruhi lebar jalur. Di Area 1 sampai 3, titik tengah rintangan selalu berada di ubin, tidak pernah di tepi antar-ubin, dan paling banyak ada satu rintangan per ubin.
* **Lubang** (holes) punya tepi hitam. Jika robot jatuh ke dalamnya, terjadi kurangnya kemajuan.

Tidak ada ubin yang sekaligus menjadi lebih dari satu dari berikut ini: rawa, lubang, checkpoint, ubin awal, ubin dengan rintangan, atau lorong penghubung antar-area.

## Penanda dinding {#wall-tokens}
Ada dua jenis penanda dinding: korban huruf dan target kognitif. Keduanya bisa muncul di dinding mana pun, termasuk permukaan melengkung. Korban huruf juga bisa diputar ke sudut mana pun.

![Target kognitif dan korban huruf di dinding arena](../../../docs/rules/rules_wall_tokens.png)

### Korban huruf {#letter-victims}
Korban huruf (letter victims) adalah gambar berukuran 2 cm × 2 cm. Simbolnya menunjukkan kondisi kesehatan korban, dan huruf dalam kurung adalah kode yang kamu laporkan dan tulis di peta.

| Kondisi | Simbol | Kode |
|---|---|---|
| Terluka (Harmed) | Φ | `H` |
| Stabil (Stable) | Ψ | `S` |
| Tidak terluka (Unharmed) | Ω | `U` |

![Simbol phi, psi, dan omega](../../../docs/rules/rules_victims.png)

### Korban palsu {#fake-victims}
Beberapa penanda dinding menampilkan simbol yang sama, tetapi dengan huruf **tiga dimensi**. Penanda itu palsu: kamu tidak boleh melaporkannya ke supervisor atau memasukkannya ke peta. Aturan menyatakan bahwa kedalaman ini bisa dideteksi dengan salah satu sensor yang tersedia di Robot Customizer.

![Korban palsu dengan simbol tiga dimensi di dinding](../../../docs/rules/rules_fake_victims.png)

### Target kognitif {#cognitive-targets}
Target kognitif (cognitive targets) mewakili bahan berbahaya (hazmat). Bentuknya lingkaran berdiameter 5 cm yang terdiri dari lima bagian konsentris, dengan diameter 1, 2, 3, 4, dan 5 cm. Setiap warna punya nilai:

| Hitam | Merah | Kuning | Hijau | Biru |
|---|---|---|---|---|
| -2 | -1 | 0 | 1 | 2 |

Jumlahkan nilai kelima bagian untuk mendapatkan jenisnya. Jika jumlahnya tidak tercantum di bawah ini, target itu palsu dan tidak boleh dilaporkan atau dipetakan.

| Jumlah | Hazmat | Kode |
|---|---|---|
| 0 | Gas Mudah Terbakar (Flammable Gas) | `F` |
| 1 | Racun (Poison) | `P` |
| 2 | Korosif (Corrosive) | `C` |
| 3 | Peroksida Organik (Organic Peroxide) | `O` |

Cincin bersebelahan dengan warna yang sama **tidak** digabung: selalu hitung kelimanya, bahkan saat warnanya berulang.

![Dua contoh target kognitif, satu valid dan satu palsu](../../../docs/rules/rules_cognitive_example.png)

Target kiri berwarna Kuning, Biru, Merah, Hitam, Hijau dari tengah ke luar: 0 + 2 - 1 - 2 + 1 = 0, jadi jenisnya Gas Mudah Terbakar (`F`). Target kanan berwarna Biru, Kuning, Hitam, Hitam, Hitam: 2 + 0 - 2 - 2 - 2 = -4, jadi target itu palsu.

[Tutorial Penanda dinding](/docs/programming/wall-tokens/) menunjukkan cara membaca target dengan kamera.

## Robot {#the-robot}
- Tim menggunakan model robot yang disediakan panitia, dan boleh menyesuaikannya dengan [Robot Customizer](https://robot.erebus.rcj.cloud/) dalam anggaran **3000**. Lihat [Robot](/docs/robot/).
- Robot bisa menggunakan GPS, sensor warna, sensor jarak, kamera RGB, LiDAR, giroskop, dan akselerometer.
- Sensor simulasi punya derau yang realistis. Programmu harus tahan terhadapnya, dan panitia tidak akan mengubah tingkat derau untuk kompetisi.
- Robot harus otonom. Setiap tim punya satu robot di arena.
- Pemetaan sebelumnya (pre-mapping) dilarang: ini mencakup arena maupun lokasi penanda dinding, termasuk gerakan yang ditentukan sebelumnya dari posisi yang sudah diketahui. Pelanggarannya berakibat diskualifikasi langsung dari ronde tersebut.

## Memainkan permainan {#playing-a-game}
- Satu permainan berlangsung **8 menit waktu simulasi**. Pewaktu kedua berjalan dalam waktu nyata dengan batas **10 menit**. Permainan berakhir saat salah satu pewaktu habis.
- Sebuah ubin dihitung sudah dikunjungi saat titik tengah robot berada di dalamnya. Erebus menilainya secara otomatis.
- Permainan juga berakhir saat robot mengirim perintah keluar, atau saat kapten tim menyatakan permainan berakhir (tergantung cara permainan dijalankan).
- World kompetisi diungkapkan tepat sebelum permainan, dan program tidak bisa diubah setelah batas waktu setiap ronde.

### Kurangnya kemajuan {#lack-of-progress}
Kurangnya kemajuan (Lack of Progress, LoP) terjadi saat:

- Robot jatuh ke lubang.
- Robot berada di lokasi yang sama selama 20 detik atau lebih (dipanggil otomatis).
- Wasit menentukan bahwa robot tidak diam, tetapi terjebak dalam urutan gerakan.
- Robot memanggilnya secara mandiri.
- Dalam kasus lain, kapten tim boleh memintanya, dan wasit yang membuat keputusan akhir. Ini mungkin tidak berlaku, tergantung cara permainan dijalankan.

Robot lalu ditempatkan kembali di checkpoint terakhir yang dikunjungi, atau di ubin awal jika belum pernah mencapai checkpoint. Arahnya tidak bisa dipilih. Erebus juga mengirim huruf `L` ke robot, agar programmu bisa [menanggapinya](/docs/programming/communication/#lack-of-progress).

## Penilaian {#scoring}
Penilaian dilakukan otomatis oleh Erebus. Poin tidak diberikan dua kali: misalnya, setiap checkpoint hanya dihitung pada kunjungan pertama.

Untuk mengidentifikasi penanda dinding, robot harus berhenti **minimal 1 detik**, lalu [mengirim jenis dan posisinya](/docs/programming/communication/#scoring-wall-tokens) ke pengelola permainan. Titik tengah robot harus berada paling jauh setengah ubin dari penanda.

| Item | Poin |
|---|---|
| Identifikasi penanda dinding (TI) di ubin linear di Area 1 sampai 3 | Korban huruf: 5, target kognitif: 10 |
| Identifikasi penanda dinding (TI) di ubin mengambang di Area 1 sampai 3, dan semua penanda di Area 4 | Korban huruf: 15, target kognitif: 30 |
| Jenis yang benar (TT), sebagai tambahan TI | Korban huruf: 10, target kognitif: 20 |
| Checkpoint dikunjungi (CN) | 10 |
| Salah identifikasi penanda dinding (TMI) | -5 |
| Kurangnya kemajuan (LoP) | -5 |

Skor total tidak bisa kurang dari nol. Salah identifikasi berarti melaporkan posisi yang lebih dari setengah ubin dari penanda, melaporkan penanda di tempat yang tidak ada penandanya, atau melaporkan korban sebagai bahaya atau sebaliknya. Melaporkan penanda palsu termasuk kategori kedua.

**Pengali area (Area multipliers, AM)**: TI, TT, dan CN dikalikan 1, 1,25, 1,5, dan 2 masing-masing di Area 1, 2, 3, dan 4. TMI dan LoP tidak dikalikan.

**Bonus keluar (Exit bonus, EB)**: jika robot sudah mengidentifikasi minimal satu penanda dinding, kembali ke ubin awal, dan mengirim perintah keluar, skornya bertambah 10%.

**Bonus peta (Mapping bonus, MB)**: robot bisa mengirimkan peta labirin. Pengalinya adalah ketepatan × 1,2 + 1, jadi peta yang sempurna mengalikan skor dengan 2,2. Lihat [Aturan pemetaan](/docs/rules/mapping/).

Skor lapangan sebuah permainan dihitung sebagai berikut:

![Skor lapangan sama dengan jumlah dari keempat area atas TI ditambah TT ditambah CN dikali AM, dikurangi TMI dan LoP, semuanya dikalikan EB dan MB](../../../docs/rules/rules_field_score.png)

Misalnya, permainan dengan hasil berikut mendapat skor 2680,15 poin:

![Contoh perhitungan skor](../../../docs/rules/rules_scoring_example.png)

## Kompetisi {#the-competition}
Cara bersiap, dokumen yang harus dikirim, pengaturan kompetisi, dan skor akhir ada di [Persiapan kompetisi](/docs/competition/).

## Selanjutnya {#next}
Sekarang setelah kamu tahu apa yang harus dilakukan robotmu, [dapatkan robotmu](/docs/robot/).
