---
title: Menjelajah dan memetakan
description: Ide-ide untuk menjelajahi labirin secara sistematis dan membuat petanya.
---

Robot yang berkeliaran secara acak tidak akan mencetak banyak poin. Halaman ini menunjukkan cara beralih dari berkeliaran ke menjelajah secara sistematis. Ini adalah ide untuk dikembangkan, bukan solusi lengkap.

## Ketahui posisimu {#know-where-you-are}
Lebar ubin adalah 12 cm, jadi dari posisi GPS kamu bisa mengetahui ubin tempat robot berada. Posisi titik awal berbeda di setiap world, jadi ukur semuanya dari sana:

```python
TILE = 0.12
startX, _, startZ = gps.getValues() # At the start of the game

def currentTile():
    x, _, z = gps.getValues()
    return round((x - startX) / TILE), round((z - startZ) / TILE)
```

:::note
Tanpa GPS, kamu bisa memperkirakan posisi dengan encoder roda dan giroskop, tetapi kesalahannya akan menumpuk.
:::

## Ingat apa yang sudah kamu lihat {#remember-what-you-have-seen}
Simpan dictionary berisi ubin-ubin, beserta apa yang kamu ketahui tentang setiap ubin: sisi mana yang punya dinding, lantainya seperti apa, dan apakah kamu sudah mengunjunginya.

```python
tiles = {}
tiles[(0, 0)] = {"walls": {"N": False, "E": True, "S": False, "W": True}, "floor": "start", "visited": True}
```

Data per ubin saja tidak cukup di Area 2 dan 3, tempat dinding bisa berada di seperempat ubin. Menyimpan peta dengan resolusi seperempat ubin, atau menggunakan awan titik Lidar, akan membuatmu siap menghadapinya.

## Tentukan ke mana harus pergi {#decide-where-to-go}
Jangan hanya menyusuri dinding: cara itu tidak akan pernah mencapai [ubin mengambang](/docs/rules/#linear-and-floating-tiles), yang penandanya bernilai lebih tinggi. Pendekatan yang umum adalah:

1. Dari ubin saat ini, buat daftar ubin tetangga yang tidak dipisahkan oleh dinding.
2. Pergi ke tetangga yang belum dikunjungi, jika ada.
3. Jika tidak ada, cari ubin terdekat yang punya tetangga belum dikunjungi dengan breadth-first search, lalu pergi ke sana.
4. Jika tidak ada lagi ubin seperti itu, atau waktunya hampir habis, kembali ke titik awal dengan cara yang sama.

Perlakukan lubang seperti dinding. Rawa menguras baterai lebih cepat, jadi masuklah hanya jika sepadan. Ingat di mana ubin kontak berada, untuk [mengganti baterai](/docs/programming/battery/) di jalan.

## Tangani hal yang tak terduga {#handle-the-unexpected}
- **Kurangnya kemajuan (lack of progress):** robot dipindahkan ke checkpoint terakhir. [Dengarkan pesan `L`](/docs/programming/communication/#lack-of-progress), dan perbarui posisimu.
- **Waktu:** minta sisa waktu dengan [`G`](/docs/programming/communication/#game-information). Sisakan cukup waktu untuk mengirim peta dan kembali ke titik awal.
- **Derau:** sensor punya derau, jadi bandingkan beberapa pembacaan sebelum memercayai adanya dinding atau penanda.

## Dari ubin ke matriks peta {#from-tiles-to-the-map-matrix}
[Matriks peta](/docs/rules/mapping/) punya 4 sel per ubin, ditambah satu. Untuk ubin di baris `r` dan kolom `c` pada petamu:

| Elemen | Posisi di matriks (baris, kolom) |
|---|---|
| Tanda lantai, seperti `4` atau `5` | Baris `4r + 1` dan `4r + 3`, kolom `4c + 1` dan `4c + 3` |
| Dinding utara | Baris `4r`, kolom `4c` hingga `4c + 4` |
| Dinding barat | Kolom `4c`, baris `4r` hingga `4r + 4` |

![Sel-sel matriks peta untuk ubin di baris r dan kolom c: dinding utara di baris 4r, dinding barat di kolom 4c, dan tanda lantai di tengah seperempat ubin](../../../../docs/programming/exploring/tile-to-matrix.svg)

Petamu bisa dimulai dari mana saja: Erebus [menyejajarkan matriks](/docs/rules/mapping/#how-correctness-is-calculated) menggunakan ubin awal, dan mencoba keempat rotasinya. [Aturan pemetaan](/docs/rules/mapping/) menjelaskan setiap nilai dalam matriks. Lalu [kirimkan petanya](/docs/programming/map-bonus/).

Uji dengan world contoh, yang jawaban benarnya ada di [Aturan pemetaan](/docs/rules/mapping/#examples). Hasilnya muncul sebagai `Map Correctness` di event pertandingan jendela kontrol.
