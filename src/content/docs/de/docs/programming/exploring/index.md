---
title: Erkunden und Kartieren
description: Ideen, wie du das Labyrinth systematisch erkundest und die Karte erstellst.
---

Ein Roboter, der zufällig umherfährt, holt nicht viele Punkte. Diese Seite zeigt, wie du vom Umherfahren zum systematischen Erkunden kommst. Es sind Ideen zum Weiterentwickeln, keine vollständige Lösung.

## Finde heraus, wo du bist {#know-where-you-are}
Kacheln sind 12 cm breit, also verrät dir die GPS-Position die Kachel. Die Startposition ist in jeder Welt anders, also miss alles von dort aus:

```python
TILE = 0.12
startX, _, startZ = gps.getValues() # At the start of the game

def currentTile():
    x, _, z = gps.getValues()
    return round((x - startX) / TILE), round((z - startZ) / TILE)
```

:::note
Ohne GPS kannst du die Position mit den Rad-Encodern und dem Gyroskop schätzen, aber die Fehler summieren sich.
:::

## Merk dir, was du gesehen hast {#remember-what-you-have-seen}
Führe ein Dictionary der Kacheln mit allem, was du über jede weißt: auf welchen Seiten Wände sind, wie der Boden ist und ob du sie schon besucht hast.

```python
tiles = {}
tiles[(0, 0)] = {"walls": {"N": False, "E": True, "S": False, "W": True}, "floor": "start", "visited": True}
```

In den Bereichen 2 und 3 erzählen die Kacheln nicht die ganze Geschichte, denn dort können Wände auf Viertelkacheln stehen. Wenn du die Karte in der Auflösung von Viertelkacheln speicherst oder eine Lidar-Punktwolke verwendest, bist du darauf vorbereitet.

## Entscheide, wohin du fährst {#decide-where-to-go}
Folge nicht einfach einer Wand: So erreichst du nie die [schwebenden Kacheln](/docs/rules/#linear-and-floating-tiles) (Floating tiles), deren Markierungen mehr wert sind. Ein üblicher Ansatz:

1. Liste von der aktuellen Kachel aus die Nachbarn auf, zu denen keine Wand dazwischen ist.
2. Fahr zu einem unbesuchten Nachbarn, falls es einen gibt.
3. Falls nicht, finde mit einer Breitensuche die nächste Kachel mit einem unbesuchten Nachbarn und fahr dorthin.
4. Wenn keine solche Kachel mehr übrig ist oder die Zeit knapp wird, kehr auf demselben Weg zum Start zurück.

Behandle Löcher wie Wände. Sümpfe kosten Zeit, und zwar jedes Mal mehr, wenn du denselben betrittst. Besuche sie also nur, wenn es sich lohnt.

## Mit dem Unerwarteten umgehen {#handle-the-unexpected}
- **Fehlender Fortschritt (Lack of Progress):** Der Roboter wird zum letzten Checkpoint versetzt. [Achte auf die Nachricht `L`](/docs/programming/communication/#lack-of-progress) und aktualisiere deine Position.
- **Zeit:** Frag mit [`G`](/docs/programming/communication/#game-information) die verbleibende Zeit ab. Lass genug übrig, um die Karte zu senden und zum Start zurückzukehren.
- **Rauschen:** Sensoren rauschen, also vergleiche mehrere Messwerte, bevor du einer Wand oder einer Markierung vertraust.

## Von den Kacheln zur Kartenmatrix {#from-tiles-to-the-map-matrix}
Die [Kartenmatrix](/docs/rules/mapping/) hat 4 Zellen pro Kachel, plus eine. Für eine Kachel in Zeile `r` und Spalte `c` deiner Karte gilt:

| Element | Position in der Matrix (Zeile, Spalte) |
|---|---|
| Bodenmarkierungen wie `4` oder `5` | Zeilen `4r + 1` und `4r + 3`, Spalten `4c + 1` und `4c + 3` |
| Nordwand | Zeile `4r`, Spalten `4c` bis `4c + 4` |
| Westwand | Spalte `4c`, Zeilen `4r` bis `4r + 4` |

Deine Karte kann überall beginnen: Erebus [richtet die Matrix](/docs/rules/mapping/#how-correctness-is-calculated) anhand der Startkachel aus und probiert die vier Drehungen. Die [Regeln für die Karte](/docs/rules/mapping/) erklären jeden Wert der Matrix. Danach [gibst du sie ab](/docs/programming/map-bonus/).

Teste sie mit den Beispielwelten, deren richtige Lösungen in den [Regeln für die Karte](/docs/rules/mapping/#examples) stehen. Das Ergebnis erscheint als `Map Correctness` im Verlauf des Steuerfensters.
