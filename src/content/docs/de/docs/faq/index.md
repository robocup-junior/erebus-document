---
title: FAQ
description: Häufig gestellte Fragen zu Erebus und zum Wettbewerb.
---

## Über Erebus {#custom-md-id}

### Brauche ich einen echten Roboter? {#do-i-need-a-real-robot}
Nein. Alles passiert im Simulator. Der Roboter ist ein virtueller e-puck, den du entwirfst.

### Welche Programmiersprachen kann ich verwenden? {#which-programming-languages-can-i-use}
Diese Dokumentation behandelt Python und C/C++. Erebus kann auch Controller in Java und MATLAB laden, aber diese Dokumentation hat dafür keine Beispiele.

### Brauche ich einen leistungsstarken Computer? {#is-a-powerful-computer-needed}
Nein, siehe die [Voraussetzungen](/docs/installation/). Langsamere Computer brauchen eventuell [niedrigere Grafikeinstellungen](/docs/troubleshooting/#the-simulation-runs-too-slowly).

### Kann ich eine neuere Version von Webots verwenden? {#can-i-use-a-newer-version-of-webots}
Nein. Erebus v26 läuft mit Webots **R2023b**. Du kannst andere Versionen daneben installiert lassen.

### Kann ich Bibliotheken wie OpenCV oder NumPy verwenden? {#can-i-use-libraries-like-opencv-or-numpy}
Ja. Fremder Code ist erlaubt, solange du seine Urheber nennst und seine Lizenz beachtest. Teams sollten das Lernen in den Vordergrund stellen und müssen erklären können, wie ihre Lösung funktioniert.

## Das Spiel {#the-game}

### In welcher Reihenfolge lerne ich am besten? {#what-is-the-best-order-to-learn-things}
Folge [dem Lernpfad](/docs/#the-learning-path): Das Spiel verstehen, den Roboter besorgen, ihn laufen lassen, die Grundlagen lernen und dann das Spiel spielen.

### Muss ich vor dem Programmieren einen Roboter bauen? {#do-i-need-to-make-a-robot-before-programming}
Ja. Jedes Programm läuft auf einem Roboter, den du lädst, also beginne mit [Roboter besorgen](/docs/robot/). Wenn es schnell gehen muss, kannst du den fertigen Starter-Roboter herunterladen.

### Wo startet der Roboter? {#where-does-the-robot-start}
Auf der Startkachel, die in Bereich 1 liegt. Er schaut immer in eine Richtung ohne Wand.

### Was passiert, wenn der Roboter in ein Loch fällt? {#what-happens-if-the-robot-falls-into-a-hole}
Es tritt ein fehlender Fortschritt (Lack of Progress) ein: Der Roboter kehrt zum zuletzt besuchten Checkpoint zurück, und du verlierst 5 Punkte.

### Muss der Roboter zum Start zurückkehren? {#does-the-robot-have-to-return-to-the-start}
Nein, aber wenn er zur Startkachel zurückkehrt und `E` sendet, bekommt er einen Ausgangsbonus (Exit bonus) von 10 %, sofern er mindestens eine Wandmarkierung erkannt hat.

### Wie erfährt mein Roboter, wie viel Zeit noch übrig ist? {#how-can-my-robot-tell-how-much-time-is-left}
Mit der [Nachricht `G`](/docs/programming/communication/#game-information). Es gibt zwei Timer, und die Spielzeit läuft in Sümpfen schneller ab.

### Muss ich Bereich 4 erkunden? {#do-i-have-to-explore-area-4}
Nein. Er ist optional, aber seine Markierungen sind am meisten wert: die höchsten Punkte, multipliziert mit 2.

### Muss ich Bereich 4 kartieren? {#do-i-have-to-map-area-4}
Nein. Alle seine Zellen sind `*`, du musst sie also nur ausfüllen.

### Darf mein Roboter die Karte vorher kennen? {#can-my-robot-know-the-map-beforehand}
Nein. Das Spielfeld oder die Position der Wandmarkierungen vorab zu kartieren ist verboten.

## Der Wettbewerb {#the-competition}

### Wie kann ich teilnehmen? {#how-do-i-take-part}
Über deinen regionalen RoboCupJunior-Wettbewerb. Deine regionale Vertretung (Regional Representative) vergibt die Plätze für den internationalen Wettbewerb. Siehe die [RoboCupJunior-Website](https://junior.robocup.org/).

### Was sollte ich vorbereiten? {#what-should-i-prepare}
Siehe [Vorbereitung auf einen Wettbewerb](/docs/competition/).

### Wo kann ich Fragen zu den Regeln stellen? {#where-can-i-ask-about-the-rules}
Im [RoboCupJunior-Forum](https://junior.forum.robocup.org/). Dort werden auch Klarstellungen veröffentlicht, also schau regelmäßig vorbei.
