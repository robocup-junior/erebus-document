---
title: Regeln im Überblick
description: "Eine Zusammenfassung der Regeln der RoboCupJunior Rescue Simulation 2027: das Spielfeld, die Wandmarkierungen, der Akku, die Wertung und der Wettbewerb."
---

:::note
Diese Seite ist eine Zusammenfassung für den Einstieg. Die einzigen offiziellen Regeln sind die [RoboCupJunior Rescue Simulation Rules 2027](https://junior.robocup.org/wp-content/uploads/2026/09/RCJRescueSimulation2027-draft.pdf). Diese Zusammenfassung folgt der Fassung vom 2026-10-24. Wenn sich diese Seite und die offiziellen Regeln unterscheiden, gelten die offiziellen Regeln.

Korrekturen und Klarstellungen werden im [offiziellen RoboCupJunior-Forum](https://junior.forum.robocup.org/) veröffentlicht. Jedes Team ist selbst dafür verantwortlich, sie zu prüfen.
:::

## Das Spiel in einer Minute {#the-game-in-one-minute}
Dein Roboter wird allein in ein unbekanntes Labyrinth gesetzt. In 8 Minuten muss er ohne deine Hilfe:

1. Das Labyrinth **erkunden**, ohne steckenzubleiben oder in Löcher zu fallen.
2. **Die Wandmarkierungen finden**, also die Opfer und kognitiven Ziele an den Wänden, und melden, was jede davon ist.
3. **Seinen Akku geladen halten**, indem er auf einer Kontaktkachel anhält, bevor der Akku leer ist.
4. Das Labyrinth **kartieren** und die Karte am Ende senden.
5. Dorthin **zurückkehren**, wo er gestartet ist.

Alles Weitere erklärt diese fünf Aufgaben im Detail. Du musst dir jetzt nicht alles merken: Komm hierher zurück, wenn du den jeweiligen Teil programmierst.

## Mission und Ziel {#mission-and-objective}
![Draufsicht auf ein Erebus-Spielfeld mit vier Bereichen](../../../docs/rules/rules_environment.png)

Der Roboter muss selbstständig eine unbekannte Umgebung erkunden und dabei Schwierigkeiten vermeiden. Es gibt drei Hauptaufgaben:

- Durch ein komplexes Labyrinth navigieren, ohne steckenzubleiben
- Die Umgebung genau kartieren
- Wandmarkierungen (Wall tokens) finden und erkennen: Smiley-Opfer (Letter victims) und kognitive Ziele (Cognitive targets)

## Das Spielfeld {#the-field}
Das Spielfeld besteht aus bis zu vier Bereichen. Bereich 1 ist immer Teil des Spielfelds, und die Veranstalter können die Bereiche 2 bis 4 weglassen. Jeder Durchgang zwischen den Bereichen ist eine Standardkachel breit. Kacheln sind ein Konzept, mit dem das Spielfeld erzeugt wird, keine physischen Strukturen.

- Eine Kachel ist **12 cm × 12 cm** groß. In den Bereichen 2 und 3 ist jede Kachel in vier **Viertelkacheln** von 6 cm × 6 cm unterteilt.
- Wände sind **1 cm dick und 6 cm hoch**.
- Wege sind mindestens so breit wie der Roboter und können sich zu breiteren Vorräumen öffnen.

![Beispiele für die Wandanordnung in den Bereichen 1, 2 und 3](../../../docs/rules/rules_tiles.png)

| Bereich | Wände | Hinweise |
|---|---|---|
| Bereich 1 | Können an den Kanten jeder Kachel stehen | Die Startkachel liegt in diesem Bereich |
| Bereich 2 | Können an den Kanten jeder Viertelkachel stehen | |
| Bereich 3 | Können an den Kanten jeder Viertelkachel stehen | 90°-Ecken können zu einem Viertelkreis abgerundet sein |
| Bereich 4 (optional) | Nicht kachelbasiert; Wände und Hindernisse sind beliebig platziert | Kann Objekte wie Kisten enthalten und diagonale Bewegungen erfordern |

### Durchgänge zwischen Bereichen {#passages-between-areas}
Durchgänge sind einzelne Kacheln mit Wänden an zwei Seiten, damit sie einen eindeutigen Ein- und Ausgang haben. Ihre Bodenfarbe zeigt dir, welche Bereiche sie verbinden:

![Tabelle der Farben der Durchgänge zwischen jedem Paar von Bereichen](../../../docs/rules/rules_passages.png)

An den Wänden der Durchgänge gibt es keine Wandmarkierungen.

### Lineare und schwebende Kacheln {#linear-and-floating-tiles}
Kacheln, von denen man zur Startkachel gelangt, wenn man konsequent der linken oder der rechten Wand folgt, sind **lineare Kacheln** (Linear tiles). Alle anderen sind **schwebende Kacheln** (Floating tiles). Markierungen auf schwebenden Kacheln bringen mehr Punkte. Viertelkacheln werden dabei nicht berücksichtigt, und Löcher zählen hier als virtuelle Wände.

![Ein Spielfeld mit linearen Kacheln in Grau und schwebenden Kacheln in Rosa](../../../docs/rules/rules_linear_floating.png)

### Checkpoints {#checkpoints}
Silberne Kacheln sind Checkpoints, und sie können überall auf dem Spielfeld liegen. Bereich 4 enthält direkt hinter seinen Durchgängen Checkpoints. Nach einem fehlenden Fortschritt startet der Roboter vom zuletzt besuchten Checkpoint neu.

## Sümpfe, Hindernisse und Löcher {#swamps-obstacles-and-holes}
![Ein Spielfeld mit einem Sumpf, einem Loch und einem Hindernis](../../../docs/rules/rules_obstacles.png)

* **Sümpfe** (braune Kacheln) lassen den Akku schneller leer werden, solange der Roboter auf ihnen ist, weil die Motoren stärker arbeiten müssen. Die Spielzeit ist davon nicht betroffen.
* **Hindernisse** können am Boden befestigt sein, jede Form und Farbe haben und beeinflussen die Breite des Wegs. In den Bereichen 1 bis 3 liegt der Mittelpunkt eines Hindernisses immer auf einer Kachel, nie auf der Kante zwischen Kacheln, und es gibt höchstens ein Hindernis pro Kachel.
* **Löcher** sind Kacheln mit einer Öffnung im Boden. Ihre Ränder sind schwarz, 1,5 cm von den Nachbarkacheln entfernt. Fällt der Roboter hinein, tritt ein fehlender Fortschritt ein.

Keine Kachel ist gleichzeitig mehr als eines der folgenden Dinge: Sumpf, Loch, Checkpoint, Kontaktkachel, Startkachel, Kachel mit Hindernis oder Durchgang zwischen Bereichen.

## Kontaktkacheln {#contact-tiles}
Kontaktkacheln sind **cyanfarbene** Kacheln, auf denen der Akku des Roboters während des Spiels ausgetauscht werden kann. Der Roboter muss auf der Kachel stillstehen, während sein Akku ausgetauscht wird. Siehe [Der Akku](#the-battery).

![Ein Spielfeld mit cyanfarbenen Kontaktkacheln](../../../docs/rules/rules_contact_tiles.png)

## Wandmarkierungen {#wall-tokens}
Es gibt zwei Arten von Wandmarkierungen: Smiley-Opfer und kognitive Ziele. Beide können an jeder Wand vorkommen, auch an gebogenen Flächen, außer an den Wänden der Durchgänge zwischen den Bereichen. Smiley-Opfer können außerdem um jeden Winkel von 0 bis 360 Grad gedreht sein.

![Kognitive Ziele und Smiley-Opfer an den Wänden eines Spielfelds](../../../docs/rules/rules_wall_tokens.png)

### Smiley-Opfer {#smiley-victims}
Smiley-Opfer sind 2 cm × 2 cm große Bilder eines schwarz gedruckten Smiley-Emojis. Der Gesichtsausdruck zeigt den Gesundheitszustand des Opfers, und der Code ist der Buchstabe, den du meldest und in die Karte schreibst.

| Zustand | Gesicht | Code |
|---|---|---|
| Verletzt | Traurig | `H` |
| Stabil | Neutral | `S` |
| Unverletzt | Fröhlich | `U` |

![Ein trauriges, ein neutrales und ein fröhliches Gesicht](../../../docs/rules/rules_victims.png)

### Gefälschte Opfer {#fake-victims}
Manche Wandmarkierungen zeigen dieselben Gesichter, aber die Emojis sind **dreidimensional**. Sie sind Fälschungen: Du darfst sie weder dem Supervisor melden noch in die Karte aufnehmen. Laut den Regeln lässt sich diese Tiefe mit einem der Sensoren erkennen, die im Robot Customizer verfügbar sind.

![Gefälschte Opfer mit dreidimensionalen Gesichtern an einer Wand](../../../docs/rules/rules_fake_victims.png)

### Kognitive Ziele {#cognitive-targets}
Kognitive Ziele (Cognitive targets) stehen für Gefahrgüter (Hazmats). Es sind Kreise mit 5 cm Durchmesser aus fünf konzentrischen Teilen mit Durchmessern von 1, 2, 3, 4 und 5 cm. Jede Farbe hat einen Wert:

| Schwarz | Rot | Gelb | Grün | Blau |
|---|---|---|---|---|
| -2 | -1 | 0 | 1 | 2 |

Addiere die Werte aller fünf Teile, um den Typ zu erhalten. Steht die Summe nicht in der Liste unten, ist das Ziel eine gefälschte Wandmarkierung und darf weder gemeldet noch kartiert werden.

| Summe | Gefahrgut | Code |
|---|---|---|
| 0 | Entzündbares Gas (Flammable Gas) | `F` |
| 1 | Gift (Poison) | `P` |
| 2 | Ätzend (Corrosive) | `C` |
| 3 | Organisches Peroxid (Organic Peroxide) | `O` |

Benachbarte Ringe derselben Farbe werden **nicht** zusammengefasst: Zähle immer alle fünf, auch wenn sich Farben wiederholen.

![Zwei Beispiele für kognitive Ziele, eines gültig und eines gefälscht](../../../docs/rules/rules_cognitive_example.png)

Das linke Ziel ist von innen nach außen Gelb, Blau, Rot, Schwarz, Grün: 0 + 2 - 1 - 2 + 1 = 0, also ist es entzündbares Gas (`F`). Das rechte Ziel ist Blau, Gelb, Schwarz, Schwarz, Schwarz: 2 + 0 - 2 - 2 - 2 = -4, also ist es eine Fälschung.

Das [Tutorial zu Wandmarkierungen](/docs/programming/wall-tokens/) zeigt, wie du ein Ziel mit einer Kamera liest.

## Der Roboter {#the-robot}
- Die Teams verwenden das von den Organisatoren bereitgestellte Robotermodell und können es mit dem [Robot Customizer](https://robot.erebus.rcj.cloud/) im Rahmen eines Budgets von **3000** anpassen. Siehe [Roboter besorgen](/docs/robot/).
- Der Roboter kann ein GPS, einen Farbsensor, Abstandssensoren, RGB-Kameras, ein Lidar, ein Gyroskop und einen Beschleunigungssensor verwenden.
- Die simulierten Sensoren haben realistisches Rauschen. Dein Programm muss damit zurechtkommen, und die Organisatoren ändern die Rauschpegel für den Wettbewerb nicht.

### Der Akku {#the-battery}
Der Roboter hat einen Akku, der sich je nach Geschwindigkeit seiner Motoren entlädt. Der Akkustand wird im Steuerfenster über den Timern angezeigt. Die Regeln nennen die genaue Rate nicht: Von den Teams wird erwartet, dass sie sein Verhalten durch Tests herausfinden.

- Um den Akku auszutauschen, muss der Roboter **5 Sekunden simulierte Zeit lang auf einer Kontaktkachel stillstehen**. Danach ist der Akku wieder voll.
- In Sümpfen entlädt sich der Akku schneller.
- Ist der Akku leer, endet das Spiel.

Das Tutorial [Akku](/docs/programming/battery/) zeigt, wie dein Programm den Akkustand lesen und den Akku austauschen kann.
- Roboter müssen autonom sein. Jedes Team hat einen Roboter auf dem Spielfeld.
- Vorab-Kartierung ist verboten: Das gilt sowohl für das Spielfeld als auch für die Position der Wandmarkierungen, einschließlich vordefinierter Bewegungen von bekannten Positionen aus. Sie führt zur sofortigen Disqualifikation für die Runde.

## Ein Spiel spielen {#playing-a-game}
- Ein Spiel dauert **8 Minuten simulierte Zeit**. Ein zweiter Timer läuft in Echtzeit mit einem Limit von **10 Minuten**. Das Spiel endet, wenn einer der beiden Timer abläuft.
- Eine Kachel gilt als besucht, wenn der Mittelpunkt des Roboters in ihr liegt, wie vom Supervisor festgestellt.
- Das Spiel endet auch, wenn der Akku leer ist, wenn der Roboter den Exit-Befehl sendet oder wenn der Teamkapitän das Ende des Spiels erklärt (je nachdem, wie das Spiel durchgeführt wird).
- Die Wettbewerbswelten werden erst kurz vor den Spielen bekannt gegeben, und nach der offiziellen, von den Veranstaltern angekündigten Frist jeder Runde dürfen Programme nicht mehr geändert werden.

### Fehlender Fortschritt {#lack-of-progress}
Ein fehlender Fortschritt (Lack of Progress, LoP) tritt ein, wenn:

- der Roboter in ein Loch gefallen ist.
- der Roboter 20 Sekunden oder länger an derselben Stelle bleibt (wird automatisch ausgelöst).
- der Schiedsrichter feststellt, dass der Roboter nicht stillsteht, aber in einer Bewegungsabfolge feststeckt.
- der Roboter ihn selbstständig auslöst.
- In anderen Fällen kann der Teamkapitän ihn beantragen, und der Schiedsrichter entscheidet endgültig. Das gilt je nach Ablauf des Spiels eventuell nicht.

Der Roboter wird dann auf den zuletzt besuchten Checkpoint zurückgesetzt oder auf die Startkachel, falls er nie einen erreicht hat. Seine Richtung kann nicht gewählt werden. Erebus sendet außerdem den Buchstaben `L` an den Roboter, damit dein Programm [darauf reagieren](/docs/programming/communication/#lack-of-progress) kann.

## Wertung {#scoring}
Die Wertung übernimmt Erebus automatisch. Punkte werden nicht doppelt vergeben: Jeder Checkpoint bringt zum Beispiel nur beim ersten Mal Punkte.

Um eine Wandmarkierung zu erkennen, muss der Roboter **mindestens 1 Sekunde** anhalten und dann [Typ und Position](/docs/programming/communication/#scoring-wall-tokens) an den Supervisor senden. Der Mittelpunkt des Roboters darf höchstens eine halbe Kachel von der Markierung entfernt sein.

| Posten | Punkte |
|---|---|
| Erkennung einer Wandmarkierung (TI) auf einer linearen Kachel in den Bereichen 1 bis 3 | Smiley-Opfer: 5, kognitives Ziel: 10 |
| Erkennung einer Wandmarkierung (TI) auf einer schwebenden Kachel in den Bereichen 1 bis 3 und alle Markierungen in Bereich 4 | Smiley-Opfer: 15, kognitives Ziel: 30 |
| Richtiger Typ (TT), zusätzlich zu TI | Smiley-Opfer: 10, kognitives Ziel: 20 |
| Besuchter Checkpoint (CN) | 10 |
| Fehlerkennung einer Wandmarkierung (TMI) | -5 |
| Fehlender Fortschritt (LoP) | -5 |

Die Gesamtpunktzahl kann nicht unter null fallen. Eine Fehlerkennung bedeutet, eine Position zu melden, die mehr als eine halbe Kachel von der Markierung entfernt ist, eine Markierung zu melden, wo keine ist, oder ein Smiley-Opfer als kognitives Ziel zu melden oder umgekehrt. Das Melden einer gefälschten Markierung fällt in die zweite Kategorie.

**Bereichsmultiplikatoren (AM)**: TI, TT und CN werden in den Bereichen 1, 2, 3 und 4 mit 1, 1,25, 1,5 bzw. 2 multipliziert. TMI und LoP werden nicht multipliziert.

**Ausgangsbonus (Exit bonus, EB)**: Wenn der Roboter mindestens eine Wandmarkierung erkannt hat, zur Startkachel zurückkehrt und den Exit-Befehl sendet, erhöht sich die Punktzahl um 10 %.

**Kartenbonus (Mapping bonus, MB)**: Der Roboter kann eine Karte des Labyrinths abgeben. Der Multiplikator ist Korrektheit × 1,2 + 1, eine perfekte Karte multipliziert die Punktzahl also mit 2,2. Siehe [Regeln für die Karte](/docs/rules/mapping/).

Die Spielfeld-Punktzahl eines Spiels wird so berechnet:

![Die Spielfeld-Punktzahl ist die Summe über die vier Bereiche von TI plus TT plus CN mal AM, abzüglich TMI und LoP, alles multipliziert mit EB und MB](../../../docs/rules/rules_field_score.png)

Ein Lauf mit diesen Ergebnissen erzielt zum Beispiel 2825,35 Punkte:

![Durchgerechnetes Beispiel einer Punkteberechnung](../../../docs/rules/rules_scoring_example.png)

## Der Wettbewerb {#the-competition}
Wie du dich vorbereitest, welche Dokumente du einreichen musst, wie das Setup beim Wettbewerb aussieht und wie sich die Endpunktzahl zusammensetzt, steht unter [Vorbereitung auf einen Wettbewerb](/docs/competition/).

## Weiter {#next}
Jetzt, wo du weißt, was dein Roboter tun muss, [besorg dir deinen Roboter](/docs/robot/).
