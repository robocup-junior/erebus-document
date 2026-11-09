---
title: Was ist Erebus?
description: Erebus ist die Plattform von RoboCupJunior für die Rettungssimulation und basiert auf Webots. Erfahre, wie ihre Teile zusammenspielen.
---

Erebus ist eine Wettbewerbsumgebung für Robotersimulation. Du entwickelst einen Controller für einen Roboter, der selbstständig ein Labyrinth erkundet, Wandmarkierungen (Smiley-Opfer und kognitive Ziele) findet und erkennt, Hindernissen und Fallen ausweicht, seinen Akku geladen hält und eine Karte der Umgebung erstellt.

Erebus basiert auf [Webots](https://cyberbotics.com/), einer Plattform für Robotersimulation, die für den professionellen Einsatz entwickelt wurde und in Industrie, Bildung und Forschung weit verbreitet ist. Cyberbotics pflegt Webots seit 1998 ohne Unterbrechung.

Die Plattform ist in erster Linie für den Wettbewerb [RoboCupJunior Rescue Simulation](https://junior.robocup.org/rescue/) gedacht. Sie richtet sich an Programmiererinnen und Programmierer mit mittleren bis fortgeschrittenen Kenntnissen.

## Wie alles zusammenspielt {#how-it-fits-together}

| Komponente | Was sie tut | Wo du sie bekommst |
|---|---|---|
| **Webots R2025a** | Der 3D-Robotersimulator | [Webots R2025a-Release](https://github.com/cyberbotics/webots/releases/tag/R2025a) |
| **Erebus** | Die Welten und der Supervisor (Main Supervisor), die die Regeln anwendet und die Punktzahl berechnet | [Erebus-Versionen](https://github.com/robocup-junior/erebus/releases) |
| **Dein Controller** | Das Programm deines Roboters, in Python oder C/C++ | Den schreibst du! |
| **Robot Customizer** | Web-Tool, um einen eigenen Roboter zu entwerfen und als JSON-Datei zu exportieren | [robot.erebus.rcj.cloud](https://robot.erebus.rcj.cloud/) |
| **World Editor** | Web-Tool, um Übungskarten zu zeichnen und als `.wbt`-Welten zu exportieren | [world.erebus.rcj.cloud](https://world.erebus.rcj.cloud/) |

## Was kannst du damit machen? {#what-can-you-do-with-it}

1. **Einen Roboter bauen.** Wähle seine Sensoren und wo sie sitzen, im Rahmen eines Budgets.
2. **Ihn programmieren.** Dein Controller liest die Sensoren aus und entscheidet ohne menschliche Hilfe, was zu tun ist.
3. **Ihn laufen lassen.** Teste ihn auf den mitgelieferten Welten oder auf deinen eigenen und beobachte die Punktzahl.
4. **Antreten.** Nimm an lokalen, regionalen und internationalen RoboCupJunior-Wettbewerben teil.

Wenn du Erebus schon kennst, sieh dir [Neu in v27](/docs/whats-new/) an.

## Nützliche Quellen {#useful-references}
Nützliche Links, um Erebus kennenzulernen und damit zu arbeiten:
- [Webots-Benutzerhandbuch (User Guide)](https://cyberbotics.com/doc/guide/index?version=R2025a)
- [Webots-Referenzhandbuch (Reference Manual)](https://cyberbotics.com/doc/reference/nodes-and-api-functions?version=R2025a)
- [Python-Dokumentation](https://www.python.org/doc/)
- [C++-Dokumentation](https://www.cplusplus.com/doc/tutorial/)
- [OpenCV-Tutorials](https://docs.opencv.org/4.x/d9/df8/tutorial_root.html)
- [RCJ Rescue Community-Website](https://rescue.rcj.cloud/): Events, Teamdokumente und Bewertungsbögen für TDP, Poster und Video
- [RoboCupJunior-Forum](https://junior.forum.robocup.org/): Regelklarstellungen

## Weiter {#next}
[Installiere Erebus](/docs/installation/) und lies dann die [Regeln im Überblick](/docs/rules/), um das Spiel zu verstehen.
