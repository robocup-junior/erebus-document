---
title: World Editor
description: Wie du mit dem Erebus World Editor deine eigenen Welten erstellst.
---

## Hintergrund {#background}

Wenn dein Roboter die mitgelieferten Karten und einfache Labyrinthe schafft, möchtest du vielleicht etwas Anspruchsvolleres ausprobieren oder bestimmte Situationen testen, die in den mitgelieferten Karten nicht vorkommen.
Dafür gibt es den Online-[Erebus World Editor](https://world.erebus.rcj.cloud/). Du zeichnest eine Karte in deinem Browser, und er exportiert eine `.wbt`-Weltdatei, die du in Erebus ausführen kannst.

![Eine fertige Karte im World Editor](../../../../docs/tools/world-editor/overview.png)

Wenn du nur kleine Karten zum Testen baust, spielt es wahrscheinlich keine große Rolle, ob das Spielfeld den Regeln entspricht. Wenn du aber ein Wettbewerbsfeld bauen möchtest, lies die offiziellen [Simulationsregeln](https://junior.robocup.org/wp-content/uploads/2026/02/RCJRescueSimulation2026-final.pdf). Der Editor prüft deine Karte während der Arbeit anhand der Regeln.

Der Editor hat eine eingebaute Anleitung: Drücke unten rechts auf **Guide**, um eine praktische Lektion zu starten, in der du eine Beispielkarte erstellst (etwa 15 Minuten), eine Tour durch die Oberfläche oder eine Lektion zu Raum 4. Daneben kannst du die Sprache des Editors ändern.

## Eine Karte beginnen {#starting-a-map}
Wenn du den Editor öffnest, wähle, **nach den Regeln welchen Jahres** du dich richten möchtest, und drücke **New map**. **Wähle für Erebus v26 die Regeln von 2026.** Die Regeln von 2027 sind ein Entwurf für die nächste Version von Erebus.

![Der Startbildschirm des World Editor](../../../../docs/tools/world-editor/start.png)

Deine Arbeit wird im Browser gespeichert, geht aber in einem anderen Browser oder beim Löschen der Browserdaten verloren. Sichere wichtige Karten als JSON mit dem Speichern-Button in der oberen Leiste und öffne sie wieder mit dem Öffnen-Button.

Eine gute Arbeitsreihenfolge ist Größe und Umriss, Räume, Durchgänge, Wände, Böden, Hindernisse und Opfer, Raum 4 und zum Schluss die Prüfungen und der Export. Die Werkzeuge sind links, jedes mit einem Tastenkürzel. Die Einstellungen des ausgewählten Werkzeugs erscheinen im Bereich daneben.

| Werkzeug | Taste | Verwendung |
|---|---|---|
| Select | `S` | Teile der Karte auswählen, verschieben, kopieren und einfügen |
| Move | `H` | Die Ansicht verschieben |
| Outline | `X` | Größe und Form der Karte festlegen |
| Rooms | `M` | Die Räume 1 bis 4 malen (die Bereiche der Regeln) |
| Passages | `P` | Räume mit einem Durchgang verbinden |
| Line | `L` | Wände zeichnen |
| Curve | `A` | Gekrümmte Wände in Raum 3 zeichnen |
| Eraser | `E` | Wände, Böden, Hindernisse und Opfer entfernen |
| Floor | `F` | Checkpoints, Löcher, Sümpfe und die Startkachel setzen |
| Obstacle | `O` | Hindernisse platzieren |
| Victims | `V` | Buchstabenopfer, kognitive Ziele und Fälschungen platzieren |

Mit dem Mausrad zoomst du, Ziehen bei gedrückter Leertaste verschiebt die Ansicht, und Rückgängig ist `⌘Z` oder `Ctrl+Z`.

## Größe und Umriss {#size-and-outline}
Lege mit dem Werkzeug **Outline** die Größe der Karte in Kacheln fest. Die Außenwände werden automatisch hinzugefügt. Mit **Outline (uneven)** kannst du Kacheln anklicken, um sie aus der Karte zu entfernen, und du kannst dort, wo du klickst, auch Zeilen und Spalten einfügen und entfernen.

![Das Werkzeug Outline](../../../../docs/tools/world-editor/outline.png)

## Räume und Durchgänge {#rooms-and-passages}
Male mit dem Werkzeug **Rooms** die Kacheln jedes Raums. An den Grenzen zwischen den Räumen werden automatisch Wände hinzugefügt. Verbinde die Räume dann mit dem Werkzeug **Passages**: Die Farbe jedes Durchgangs wird danach gewählt, welche Räume er verbindet.

![Das Werkzeug Rooms](../../../../docs/tools/world-editor/rooms.png)

![Das Werkzeug Passages](../../../../docs/tools/world-editor/passages.png)

## Wände {#walls}
Zeichne Wände mit dem Werkzeug **Line**: in Raum 1 auf den Kachelkanten, in den Räumen 2 und 3 auf Viertelkacheln. Verwende in Raum 3 das Werkzeug **Curve** und zeige auf ein Viertel einer Kachel, um die Kurve zu wählen. Ein erneuter Klick auf dieselbe Kurve entfernt sie.

![Das Werkzeug Line für Wände](../../../../docs/tools/world-editor/walls.png)

## Böden und Hindernisse {#floors-and-obstacles}
Wähle mit dem Werkzeug **Floor** einen Bodentyp und klicke auf eine Kachel, um ihn zu setzen. Die Startkachel muss eine Kachel in Raum 1 sein, und ohne sie kann die Welt nicht exportiert werden. Eine Kachel kann nur genau eines davon sein: Loch, Sumpf, Checkpoint, Hindernis, Start oder Durchgang.

![Das Werkzeug Floor](../../../../docs/tools/world-editor/floors.png)

Wähle mit dem Werkzeug **Obstacle** eine Form und klicke auf eine Kachel. In den Räumen 1 bis 3 gibt es ein Hindernis pro Kachel, mit seinem Mittelpunkt auf der Kachel. Klicke ein Hindernis an, um Größe, Höhe, Farbe und Drehung mit seinen Anfassern und im Einstellungsbereich zu ändern.

![Das Werkzeug Obstacle](../../../../docs/tools/world-editor/obstacles.png)

## Opfer und kognitive Ziele {#victims-and-cognitive-targets}
Wähle mit dem Werkzeug **Victims** eine Art und klicke in die Nähe einer Wand. Du kannst platzieren:

- Echte Buchstabenopfer: verletzt (harmed), stabil (stable) und unverletzt (unharmed)
- Gefälschte Buchstabenopfer (Fake victims) mit dreidimensionalen Symbolen
- Kognitive Ziele (Cognitive targets): Wähle das Gefahrgut und, wenn du möchtest, die Farben der Ringe. Die Summe wird angezeigt und bestimmt den Typ
- Gefälschte Ziele, deren Ringe zusammen etwas anderes als 0 bis 3 ergeben

In Raum 1 kann auf jeder Kachelseite ein Opfer sein. In den Räumen 2 und 3 kommen sie auf die Flächen der 6-cm-Wände, und Kurven haben zwei Plätze, innen und außen. Wähle unter **Turn** eine feste Drehung oder eine zufällige für jede neue Markierung. Klicke eine platzierte Markierung an, um sie zu ändern oder zu entfernen, oder zieh sie an ihrer Wand entlang.

![Das Werkzeug Victims](../../../../docs/tools/world-editor/victims.png)

## Raum 4 {#room-4}
Raum 4 basiert nicht auf Kacheln und wird deshalb als Bild gezeichnet. Male mit dem Werkzeug **Rooms** den Raum 4 und drücke **Draw room 4** (oder doppelklicke auf den Raum), um den Raum-4-Editor zu öffnen.

![Der Raum-4-Editor](../../../../docs/tools/world-editor/room4.png)

Was du schwarz zeichnest, wird zu Wänden. Der Editor hat Werkzeuge zum Freihandzeichnen und zum Zeichnen von Linien, Kurven, Bögen, Rechtecken, Ellipsen, Polygonen und Formen aus Symbolen sowie Werkzeuge für Opfer und Hindernisse. In Raum 4 kannst du beliebig viele Hindernisse platzieren. Rote Streifen zeigen, wohin der Roboter nicht gelangen kann, und du musst einen etwa eine Kachel breiten Weg frei lassen, damit der Roboter durchkommt.

Wenn du fertig bist, drücke **OK**: Das Bild erscheint als Raum 4 auf der Karte und kommt in die exportierte Welt. Mit den Buttons oben rechts im Editor speicherst du das Bild als PNG, damit du denselben Raum 4 in einer anderen Karte verwenden kannst, und öffnest PNG- oder JPEG-Bilder.

## Deine Karte prüfen {#checking-your-map}
Jede Änderung wird im Bereich **Checks** oben rechts anhand der Regeln geprüft. Ein rotes ✕ ist ein Problem, das den Export der Welt verhindert, und ein gelbes ! ist eine Warnung, die du dir ansehen solltest. Klicke auf einen Eintrag, um dorthin zu springen. **Fix** behebt einen Eintrag, und **Fix all that can be fixed** behebt alle.

![Eine neue Karte im World Editor mit dem Bereich Checks](../../../../docs/tools/world-editor/new_map.png)

Der Button **Linear** in der oberen Leiste färbt jede Kachel als lineare oder schwebende Kachel ein. Das bestimmt, wie viel die Markierungen wert sind.

![Lineare und schwebende Kacheln auf der Karte](../../../../docs/tools/world-editor/linear.png)

Der Pokal in der oberen Leiste zeigt die **maximale Punktzahl** der Karte, berechnet nach den Wertungsregeln, mit dem Anteil jedes Raums und der Punktzahl mit Ausgangsbonus und Kartenbonus.

![Die maximale Punktzahl der Karte](../../../../docs/tools/world-editor/max_score.png)

## Deine Welt exportieren und ausführen {#exporting-and-running-your-world}
Lege den Namen der Karte in der oberen Leiste fest und drücke oben rechts den Button **.wbt**. Dann:

1. Kopiere die `.wbt`-Datei in den Ordner `game/worlds` von Erebus. Sie muss in diesem Ordner liegen, weil die Welt Dateien von Erebus verwendet.
1. Öffne sie in Webots oder wähle sie mit dem Button **Worlds** des [Steuerfensters](/docs/getting-started/).

![Die Beispielkarte aus der Anleitung des Editors, ausgeführt in Erebus v26.1.](../../../../docs/tools/world-editor/exported_world.png)

*Die Beispielkarte aus der Anleitung des Editors, ausgeführt in Erebus v26.1.*

Eine `.wbt`-Datei lässt sich nicht wieder in eine bearbeitbare Karte umwandeln, also bewahre auch die JSON-Datei auf.
