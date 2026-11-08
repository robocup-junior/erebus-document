---
title: Neu in v26
description: Die Änderungen in Erebus v26 und in den Regeln von 2026, die deinen Roboter betreffen.
---

Erebus v26 setzt die Regeln von 2026 um. Wenn du von einer früheren Version kommst, sind das die Änderungen, die deinen Roboter betreffen.

| Thema | Bis 2025 | Ab 2026 |
|---|---|---|
| Buchstabenopfer (Letter victims) | Buchstaben H, S, U | Symbole Φ (verletzt), Ψ (stabil), Ω (unverletzt). Sie werden weiterhin als `H`, `S`, `U` gemeldet. |
| Gefahrgutschilder (Hazmat signs) | Vier Gefahrgutetiketten | Ersetzt durch [kognitive Ziele](/docs/rules/#cognitive-targets) (Cognitive targets): konzentrische farbige Ringe, deren Werte zusammen den Typ ergeben. Sie werden weiterhin als `F`, `P`, `C`, `O` gemeldet. |
| Gefälschte Markierungen | - | Neu: [gefälschte Opfer](/docs/rules/#fake-victims) (Fake victims) mit dreidimensionalen Buchstaben und kognitive Ziele, deren Summe nicht 0 bis 3 ist. Melde sie nicht und trage sie nicht in die Karte ein. |
| Sümpfe | Zeit läuft 5-mal schneller ab | Das erste Betreten eines Sumpfs zählt x5, jedes erneute Betreten desselben Sumpfs addiert 1, bis zu x10. |
| Hindernisse auf der Karte | Nicht kartiert | Kacheln mit einem Hindernis werden als `x` kartiert. |
| Kartenbonus | Bis zu x2 | Der Multiplikator ist jetzt Korrektheit × 1,2 + 1. |
| Sensorrauschen | - | Das GPS hat Rauschen. Die Organisatoren ändern die Rauschpegel für den Wettbewerb nicht. |
| Ablauf der Spiele | Pro Event angekündigt | Server-Client-Setup: Dein Controller läuft auf deinem eigenen Computer, per Ethernet mit dem Spielserver verbunden. Siehe [Remote Controller](/docs/competition/remote-controller/). |
| Dokumente | TDP, Poster, Video | Zusätzlich ein kurzes Video, das zeigt, wie du deinen Controller im Server-Client-Setup ausführst. |
| Verpasste Spiele | -50 Punkte | 0 Punkte. |

Die Webots-Version hat sich nicht geändert: Erebus v26 läuft weiterhin mit Webots **R2023b**.

Die beiden nach v26.0.0 veröffentlichten Versionen ändern die Regeln nicht. v26.0.1 fügt Beispielwelten mit gefälschten Opfern hinzu sowie ein Skript, das Opfer einer bestehenden Welt in Fälschungen umwandelt, und v26.1 korrigiert, wie Hindernisse in Bereich 4 markiert werden.

## Dein Programm aktualisieren {#updating-your-program}

1. Passe deine Opfererkennung an die neuen Symbole an. Die Buchstaben, die du meldest, ändern sich nicht.
2. Ersetze die Gefahrguterkennung durch das [Lesen kognitiver Ziele](/docs/programming/wall-tokens/#reading-a-cognitive-target).
3. Stelle sicher, dass dein Programm keine Fälschungen meldet und sie nicht in die Karte einträgt.
4. Trage Hindernisse als `x` in deine Karte ein.
5. Plane deine Route mit Blick auf die neuen Sümpfe: Jedes Mal, wenn der Roboter denselben Sumpf betritt, kostet das mehr Zeit.
6. Übe das [Server-Client-Setup](/docs/competition/remote-controller/).
