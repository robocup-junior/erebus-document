---
title: Vorbereitung auf einen Wettbewerb
description: Eine Checkliste, um dich auf einen Wettbewerb in RoboCupJunior Rescue Simulation vorzubereiten.
---

Diese Seite ist ein Leitfaden für den internationalen Wettbewerb nach den Regeln von 2027. Lokale und regionale Wettbewerbe können abweichen, also frag bei deinen Organisatoren nach. Die offiziellen [Regeln](/docs/rules/) gelten immer.

## Zeitplan {#timeline}

| Wann | Was |
|---|---|
| Das ganze Jahr über | Verfolge die [Event-Seite](/docs/events/upcoming-events/) und das [Forum](https://junior.forum.robocup.org/), wo Klarstellungen veröffentlicht werden |
| Mindestens 4 Wochen vorher | Die Organisatoren geben Anweisungen für das Webformular zur Vorbereitung der Interviews |
| 3 Wochen vor dem ersten Tag | Abgabefrist für die Dokumente |
| Aufbautag | Sei früh vor Ort für Registrierung, Interviews und Teambesprechungen |
| Jede Runde | Die Welten werden kurz vor den Spielen bekannt gegeben. Nach der Frist jeder Runde können Programme nicht mehr geändert werden. |
| Nach den Wertungsläufen | Technical Challenge |

## Einzureichende Dokumente {#documents-to-submit}
Vorlagen und Bewertungsbögen findest du auf der [RCJ Rescue Community-Website](https://rescue.rcj.cloud/).

- [ ] **Technical Description Paper (TDP).** Halte dich genau an die Vorlage, sonst bekommt das Dokument 0 Punkte.
- [ ] **Poster**, als Datei und als gedrucktes Poster vor Ort, höchstens A1.
- [ ] **Video**, das dein Projekt vorstellt.
- [ ] **Server-Client-Video:** ein kurzes Video, das zeigt, wie du deinen Controller auf einer Beispielkarte im Server-Client-Setup ausführst.
- [ ] **Quellcode** und das **Webformular** für die Interviews.

## Setup beim Wettbewerb {#competition-setup}
Die Spiele laufen in einem Server-Client-Setup: Die Organisatoren betreiben den Spielserver und stellen eine RJ-45-Buchse bereit, und dein Programm läuft auf deinem Computer. Siehe [Remote Controller](/docs/competition/remote-controller/).

Bring mit:

- [ ] Einen Computer mit deinem Programm und allen installierten Bibliotheken sowie Webots R2025a
- [ ] Ein Ethernet-Kabel und einen Adapter, falls dein Computer einen braucht
- [ ] Die `.json`-Datei deines Roboters, falls du einen eigenen Roboter hast
- [ ] Das gedruckte Poster

## OpenGL-Einstellungen {#opengl-settings}
Sofern die Organisatoren nichts anderes ankündigen, werden die folgenden Einstellungen verwendet. Sie beeinflussen, was die Kameras sehen, also teste mit ihnen. Du findest sie im Tab „OpenGL“ der Webots-„Preferences“.

| Einstellung | Wert |
|---|---|
| Ambient Occlusion | Low |
| Texture Quality | Low |
| Max Texture Filtering | 4 |
| Shadows | Disabled |
| Anti-aliasing | Disabled |

## Deinen Roboter testen {#testing-your-robot}
- [ ] Auf jeder enthaltenen Welt fahren, besonders auf den vier `2027_`-Welten, die Kontaktkacheln und Fälschungen enthalten.
- [ ] Erstelle mit dem [World Editor](/docs/tools/world-editor/) eigene Karten mit allen vier Bereichen.
- [ ] Das ganze Spiel prüfen: Läuft es bis zum Ende, tauscht der Roboter rechtzeitig seinen Akku aus, gibt er die Karte ab und kehrt er zum Start zurück?
- [ ] Teste, was nach einem fehlenden Fortschritt (Lack of Progress) passiert.
- [ ] Teste auf dem Computer, den du mitbringst, und mit den OpenGL-Einstellungen oben.

## Während des Wettbewerbs {#during-the-competition}
- Nur Kapitän und Co-Kapitän dürfen den Wettbewerbsbereich betreten, sofern ein Schiedsrichter nichts anderes sagt.
- Der Schiedsrichter bedient die Simulation. Nach Spielbeginn darfst du die Spielgeräte nicht berühren.
- Mentoren dürfen während des Wettbewerbs nicht helfen.
- Sei bereit, deine Arbeit zu erklären: Jedes Teammitglied sollte eine technische Rolle haben und wissen, wie sie funktioniert.

## Endpunktzahl {#final-score}
Die Endpunktzahl bei internationalen Wettbewerben setzt sich zusammen aus:

| Teil | Gewichtung | Inhalt |
|---|---|---|
| Punktzahl auf dem Spielfeld | 0,6 | Mittelwert der normierten Spielfeld-Punktzahlen. Die schlechteste Runde bzw. die schlechtesten Runden werden gestrichen. |
| Bewertungsbögen | 0,2 | TDP (0,6), Video (0,2), Poster (0,2) |
| Technical Challenge | 0,2 | Kleine Aufgaben, die beim Wettbewerb bekannt gegeben werden und die du löst, indem du deinen Roboter in begrenzter Zeit umprogrammierst |

Bei Gleichstand entscheidet der Mittelwert der normierten Spielfeld-Punktzahlen. Die SuperTeam Challenge ist ein separates Event mit eigener Auszeichnung.
