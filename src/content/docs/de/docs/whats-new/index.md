---
title: Neu in v27
description: Die Änderungen in Erebus v27 und den Regeln 2027, die deinen Roboter betreffen.
---

Erebus v27 setzt die Regeln 2027 um. Wenn du von v26 kommst, sind das die Änderungen, die deinen Roboter betreffen.

| Thema | Bis 2026 | Ab 2027 |
|---|---|---|
| Akku | - | Neu: Der Roboter hat einen [Akku](/docs/rules/#the-battery), der sich mit der Geschwindigkeit seiner Motoren entlädt. Ist er leer, endet das Spiel. |
| Kontaktkacheln | - | Neu: cyanfarbene [Kontaktkacheln](/docs/rules/#contact-tiles). Wer 5 Sekunden lang darauf stillsteht, bekommt einen neuen Akku. Sie werden als `k` kartiert. |
| Sümpfe | Die Spielzeit läuft schneller: x5 beim ersten Betreten, bis zu x10 | Der Akku entlädt sich schneller. Die Spielzeit ist nicht betroffen. |
| Opfer | Symbole Φ, Ψ, Ω | [Smiley-Gesichter](/docs/rules/#smiley-victims): traurig (verletzt), neutral (stabil) und fröhlich (unverletzt). Sie werden weiterhin als `H`, `S`, `U` gemeldet. |
| Gefälschte Opfer | Dreidimensionale Symbole | Dreidimensionale Smiley-Gesichter |
| Spielinformationen | Die Antwort auf `G` ist 16 Byte lang | Die Antwort auf `G` ist 20 Byte lang und endet mit dem Akkustand. Siehe [Spielinformationen](/docs/programming/communication/#game-information). |
| Meldeabstand | Erebus v26 akzeptierte Meldungen bis 9 cm von der Markierung | Eine halbe Kachel (6 cm), wie in den Regeln |
| Bereiche | Vier Bereiche, Bereich 4 optional | Bis zu vier Bereiche: Bereich 1 gibt es immer, die Veranstalter können die Bereiche 2 bis 4 weglassen |
| Webots | R2023b | **R2025a** |
| Python | 3.9 oder neuer | 3.10 oder neuer |

[Dein erster Lauf](/docs/getting-started/) zeigt, wie du das Steuerfenster von Erebus v27 benutzt.

## Dein Programm aktualisieren {#updating-your-program}

1. Lies die Antwort auf `G` als 20 Byte. Ein Programm, das nur 16 Byte akzeptiert, erhält keine Spielinformationen mehr.
1. Behalte den Akkustand im Blick und plane deine Route so, dass der Roboter eine Kontaktkachel erreicht, bevor der Akku leer ist. Siehe [Akku](/docs/programming/battery/).
1. Nimm Kontaktkacheln als `k` in deine Karte auf.
1. Passe deine Opfererkennung an die Smiley-Gesichter an. Die Buchstaben, die du meldest, ändern sich nicht.
1. Melde Markierungen aus geringerem Abstand: Der Mittelpunkt des Roboters und die gesendete Position müssen innerhalb einer halben Kachel von der Markierung liegen.
1. Sümpfe kosten jetzt Akku statt Zeit. Berücksichtige sie in deiner Akkuplanung.
1. Installiere Webots R2025a und Python 3.10 oder neuer, und prüfe, ob dein Programm noch funktioniert. Siehe [Installation](/docs/installation/).
