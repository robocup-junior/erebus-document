---
title: Parameter-Referenz
description: Maße des Spielfelds, Spielzeiten, Multiplikatoren für die Wertung, Grenzen für den Roboter und die Gerätenamen des Starter-Roboters.
---

## Spielfeld {#field}

| Parameter | Wert |
|---|---|
| Kachel | 12 cm × 12 cm |
| Viertelkachel (Bereiche 2 und 3) | 6 cm × 6 cm |
| Wand | 1 cm dick, 6 cm hoch |
| Smiley-Opfer | 2 cm × 2 cm |
| Kognitives Ziel | 5 cm Durchmesser |

## Spiel {#game}

| Parameter | Wert |
|---|---|
| Spielzeit | 8 Minuten simulierte Zeit |
| Echtzeit | 10 Minuten |
| Automatischer fehlender Fortschritt (Lack of Progress) | Nach 20 Sekunden an derselben Stelle |
| Stoppzeit zum Melden einer Wandmarkierung | Mindestens 1 Sekunde |
| Abstand zum Melden einer Wandmarkierung | Eine halbe Kachel (6 cm), für den Mittelpunkt des Roboters und die gesendete Position |
| Akku | 100 % zu Beginn. Er entlädt sich mit der Geschwindigkeit der Räder, etwa 1,25 % pro Sekunde mit zwei Rädern bei voller Geschwindigkeit. |
| Akku in einem Sumpf | Entlädt sich 5-mal schneller |
| Akkuwechsel | 5 Sekunden lang auf einer Kontaktkachel stillstehen |
| Bereichsmultiplikatoren | 1, 1,25, 1,5 und 2 für die Bereiche 1, 2, 3 und 4 |
| Ausgangsbonus | +10 % |
| Multiplikator des Kartenbonus | Korrektheit × 1,2 + 1 |

## Roboter {#robot}

| Parameter | Wert |
|---|---|
| Budget | 3000 |
| Maximale Anzahl Kameras | 3 |
| Maximale Anzahl Abstandssensoren | 8 |
| Reichweite des Abstandssensors | 0 bis 0,8 m |
| Genauigkeit des GPS | 0,0025 m |
| Maximale Radgeschwindigkeit | 6,28 rad/s |
| Lidar | 512 Punkte pro Schicht, 4 Schichten, 0,01 bis 1 m |

`timeStep` legt die Anzahl der Millisekunden zwischen Sensor-Aktualisierungen fest. `int(robot.getBasicTimeStep())` liefert den Basis-Zeitschritt der Welt, der in den Welten von Erebus v27 16 ms beträgt.

## Gerätenamen des Starter-Roboters {#device-names-of-the-starter-robot}

Das sind die Namen, die du beim [Starter-Roboter](/docs/robot/) an `robot.getDevice()` übergibst. Bei deinen eigenen Robotern wählst du die Namen im [Robot Customizer](/docs/robot/customizer/#components). Sender (Emitter) und Empfänger (Receiver) sind immer vorhanden.

| Gerät | Name |
|---|---|
| Radmotoren | `left wheel motor`, `right wheel motor` |
| Rad-Encoder | `left wheel sensor`, `right wheel sensor` |
| Abstandssensoren | `leftDist`, `frontDist`, `rightDist` |
| Kamera | `camera` |
| Farbsensor | `color` |
| GPS | `gps` |
| Gyroskop | `gyro` |
| Beschleunigungssensor | `accelerometer` |
| Lidar | `lidar` |
| Sender | `emitter` |
| Empfänger | `receiver` |
