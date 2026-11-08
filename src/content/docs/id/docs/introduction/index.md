---
title: Apa itu Erebus?
description: Erebus adalah platform simulasi penyelamatan RoboCupJunior, yang dibangun di atas Webots. Pelajari bagaimana bagian-bagiannya saling berkaitan.
---

Erebus adalah lingkungan kompetisi simulasi robot. Kamu mengembangkan controller untuk robot yang secara mandiri menjelajahi labirin, menemukan dan mengidentifikasi penanda dinding (korban huruf dan target kognitif), menghindari rintangan dan jebakan, serta membuat peta lingkungannya.

Erebus dibangun di atas [Webots](https://cyberbotics.com/), platform simulasi robotik yang dirancang untuk penggunaan profesional dan banyak dipakai di industri, pendidikan, dan penelitian. Cyberbotics terus mengembangkan dan memelihara Webots sejak 1998.

Platform ini terutama dirancang untuk kompetisi [RoboCupJunior Rescue Simulation](https://junior.robocup.org/rescue/). Platform ini ditujukan untuk programmer dengan pengalaman tingkat menengah hingga mahir.

## Bagaimana semuanya saling berkaitan {#how-it-fits-together}

| Komponen | Fungsinya | Tempat mendapatkannya |
|---|---|---|
| **Webots R2023b** | Simulator robot 3D | [Rilis Webots R2023b](https://github.com/cyberbotics/webots/releases/tag/R2023b) |
| **Erebus** | World dan pengelola permainan (Main Supervisor), yang menerapkan aturan dan menghitung skor | [Rilis Erebus](https://github.com/robocup-junior/erebus/releases) |
| **Controller-mu** | Program robotmu, dalam Python atau C/C++ | Kamu yang menulisnya! |
| **Robot Customizer** | Alat web untuk merancang robot kustom dan mengekspornya sebagai berkas JSON | [robot.erebus.rcj.cloud](https://robot.erebus.rcj.cloud/) |
| **World Editor** | Alat web untuk menggambar peta latihan dan mengekspornya sebagai world `.wbt` | [world.erebus.rcj.cloud](https://world.erebus.rcj.cloud/) |

## Apa yang bisa kamu lakukan dengannya? {#what-can-you-do-with-it}

1. **Rakit robot.** Pilih sensornya dan tempat pemasangannya, sesuai anggaran.
2. **Program robotnya.** Controller-mu membaca sensor dan memutuskan apa yang harus dilakukan, tanpa bantuan manusia.
3. **Jalankan.** Uji di world yang sudah disertakan atau di world buatanmu sendiri, dan lihat skornya.
4. **Bertanding.** Ikuti kompetisi RoboCupJunior tingkat lokal, regional, dan internasional.

Jika kamu sudah mengenal Erebus, lihat [Yang baru di v26](/docs/whats-new/).

## Referensi yang berguna {#useful-references}
Tautan yang berguna untuk mempelajari dan menggunakan Erebus:
- [Panduan Pengguna Webots](https://cyberbotics.com/doc/guide/index?version=R2023b)
- [Manual Referensi Webots](https://cyberbotics.com/doc/reference/nodes-and-api-functions?version=R2023b)
- [Dokumentasi Python](https://www.python.org/doc/)
- [Dokumentasi C++](https://www.cplusplus.com/doc/tutorial/)
- [Tutorial OpenCV](https://docs.opencv.org/4.x/d9/df8/tutorial_root.html)
- [Situs Web Komunitas RCJ Rescue](https://rescue.rcj.cloud/): acara, dokumen tim, serta rubrik TDP, Poster, dan Video
- [Forum RoboCupJunior](https://junior.forum.robocup.org/): klarifikasi aturan

## Selanjutnya {#next}
[Instal Erebus](/docs/installation/), lalu baca [Ringkasan aturan](/docs/rules/) untuk memahami permainannya.
