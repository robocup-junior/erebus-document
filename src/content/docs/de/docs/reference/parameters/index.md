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
| Buchstabenopfer | 2 cm × 2 cm |
| Kognitives Ziel | 5 cm Durchmesser |

## Spiel {#game}

| Parameter | Wert |
|---|---|
| Spielzeit | 8 Minuten simulierte Zeit |
| Echtzeit | 10 Minuten |
| Automatischer fehlender Fortschritt (Lack of Progress) | Nach 20 Sekunden an derselben Stelle |
| Stoppzeit zum Melden einer Wandmarkierung | Mindestens 1 Sekunde |
| Zeitmultiplikator im Sumpf | x5 beim ersten Betreten, +1 bei jedem erneuten Betreten desselben Sumpfs, bis zu x10 |
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
| LIDAR | 512 Punkte pro Schicht, 4 Schichten, 0,01 bis 1 m |

`timeStep` legt die Anzahl der Millisekunden zwischen Sensor-Aktualisierungen fest. `int(robot.getBasicTimeStep())` liefert den Basis-Zeitschritt der Welt, der in den Welten von Erebus v26.1 16 ms beträgt.

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
| LIDAR | `lidar` |
| Sender | `emitter` |
| Empfänger | `receiver` |
