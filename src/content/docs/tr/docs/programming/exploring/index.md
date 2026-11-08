---
title: Keşif ve haritalama
description: Labirenti sistemli bir şekilde keşfetmek ve haritayı oluşturmak için fikirler.
---

Rastgele dolaşan bir robot pek puan kazanamaz. Bu sayfa, rastgele dolaşmaktan sistemli keşfe nasıl geçeceğini gösterir. Bunlar üzerine inşa edebileceğin fikirlerdir, eksiksiz bir çözüm değil.

## Nerede olduğunu bil {#know-where-you-are}
Kareler 12 cm genişliğindedir, bu yüzden GPS konumu sana hangi karede olduğunu verir. Başlangıcın konumu her dünyada farklıdır, bu yüzden her şeyi oradan ölç:

```python
TILE = 0.12
startX, _, startZ = gps.getValues() # At the start of the game

def currentTile():
    x, _, z = gps.getValues()
    return round((x - startX) / TILE), round((z - startZ) / TILE)
```

:::note
GPS olmadan konumu tekerlek enkoderleri ve jiroskopla tahmin edebilirsin, ama hatalar birikir.
:::

## Gördüklerini hatırla {#remember-what-you-have-seen}
Her kare hakkında bildiklerini içeren bir kare sözlüğü tut: hangi yanlarında duvar var, zemin ne ve onu ziyaret ettin mi.

```python
tiles = {}
tiles[(0, 0)] = {"walls": {"N": False, "E": True, "S": False, "W": True}, "floor": "start", "visited": True}
```

Duvarların çeyrek karelerde olabildiği 2. ve 3. alanlarda kareler her şeyi anlatmaz. Haritayı çeyrek kare çözünürlüğünde saklamak ya da bir Lidar nokta bulutu kullanmak seni bu alanlara hazırlar.

## Nereye gideceğine karar ver {#decide-where-to-go}
Sadece bir duvarı izleme: bu yöntem, işaretleri daha değerli olan [yüzen karelere](/docs/rules/#linear-and-floating-tiles) asla ulaşmaz. Yaygın bir yaklaşım şudur:

1. Bulunduğun kareden, arada duvar olmayan komşuları listele.
2. Ziyaret edilmemiş bir komşu varsa ona git.
3. Yoksa, genişlik öncelikli arama (breadth-first search) ile ziyaret edilmemiş bir komşusu olan en yakın kareyi bul ve oraya git.
4. Böyle bir kare kalmadığında ya da süre azaldığında aynı yoldan başlangıca dön.

Çukurları duvar gibi düşün. Bataklıklar zaman kaybettirir ve aynı bataklığa her girişinde daha fazla kaybettirir, bu yüzden onlara yalnızca değdiğinde git.

## Beklenmedik durumlarla başa çık {#handle-the-unexpected}
- **İlerleme eksikliği:** robot son kontrol noktasına taşınır. [`L` mesajını dinle](/docs/programming/communication/#lack-of-progress) ve konumunu güncelle.
- **Süre:** kalan süreyi [`G`](/docs/programming/communication/#game-information) ile sor. Haritayı gönderip başlangıca dönmeye yetecek kadar süre bırak.
- **Gürültü:** sensörler gürültülüdür, bu yüzden bir duvara ya da işarete güvenmeden önce birkaç ölçümü karşılaştır.

## Karelerden harita matrisine {#from-tiles-to-the-map-matrix}
[Harita matrisinde](/docs/rules/mapping/) kare başına 4 hücre, artı bir tane vardır. Haritandaki `r` satırı ve `c` sütunundaki bir kare için:

| Öğe | Matristeki konum (satır, sütun) |
|---|---|
| `4` ya da `5` gibi zemin işaretleri | `4r + 1` ve `4r + 3` satırları, `4c + 1` ve `4c + 3` sütunları |
| Kuzey duvarı | `4r` satırı, `4c` ile `4c + 4` arasındaki sütunlar |
| Batı duvarı | `4c` sütunu, `4r` ile `4r + 4` arasındaki satırlar |

Haritan herhangi bir yerden başlayabilir: Erebus başlangıç karesini kullanarak [matrisi hizalar](/docs/rules/mapping/#how-correctness-is-calculated) ve dört dönüşü de dener. [Haritalama kuralları](/docs/rules/mapping/) matrisin her değerini açıklar. Sonra [haritayı gönder](/docs/programming/map-bonus/).

Doğru cevapları [Haritalama kuralları](/docs/rules/mapping/#examples) sayfasında bulunan örnek dünyalarla test et. Sonuç, kontrol penceresinin geçmişinde `Map Correctness` olarak görünür.
