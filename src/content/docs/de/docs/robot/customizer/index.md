---
title: "Referenz: Robot Customizer"
description: Die Oberfläche, Komponenten, Kosten und Grenzen des Robot Customizer.
---

Mit dem [Robot Customizer](https://robot.erebus.rcj.cloud/) wählst du die Sensoren deines Roboters und wo sie sitzen. Er läuft in deinem Browser und exportiert eine `.json`-Datei, die Erebus lädt.

Neu dabei? Beginne mit [Roboter bauen](/docs/robot/build/), wo der Starter-Roboter Schritt für Schritt gebaut wird. Diese Seite beschreibt alles Weitere.

![Der Robot Customizer](../../../../docs/robot/customizer/customizer.png)

Links ist die 3D-Vorschau, rechts sind die Komponenten und das Budget.

## Die Oberfläche {#the-screen}

1. **Komponenten hinzufügen.** Schalte den Schalter jedes Sensors oder jeder Kamera ein, die du möchtest, und stelle die Anzahl der Abstandssensoren mit `−` und `+` ein. Die Kosten jeder Komponente stehen daneben.
2. **Im Budget bleiben.** Oben rechts siehst du, wie viel vom Budget von 3000 noch übrig ist und wie es sich auf Räder, Abstandssensoren, Sensoren und Kameras verteilt. Wenn du darüber liegst, wird angezeigt, wie viel du entfernen musst: Der Roboter kann erst exportiert werden, wenn er ins Budget passt.
3. **Platzieren.** Klicke eine Komponente in der Liste oder in der 3D-Ansicht an, um ihre Einstellungen zu öffnen. Zieh die Pfeile in der 3D-Ansicht mit **Move** (`W`) oder **Rotate** (`R`), oder tippe die Werte ein. Die Positionen sind in Zehntelmillimetern angegeben, obwohl in den Feldern mm steht. Die Y-Position reicht von -100 bis 370. Mit den Drehungs-Buttons richtest du einen Sensor mit einem Klick nach vorne, hinten, links, rechts, oben oder unten aus. Der grüne Pfeil markiert die Vorderseite des Roboters.
4. **Benennen.** Den Namen verwendet dein Programm mit `getDevice()`, wie unter **In your controller** angezeigt. Räder bekommen zwei Geräte: `<name> motor` und `<name> sensor`. Wheel 1 ist auf der rechten Seite des Roboters, Wheel 2 auf der linken.
5. **Die Kameraauflösung einstellen.** Jede Kamera hat eine Breite und eine Höhe, die ihre Kosten verändern.
6. **Exportieren.** Gib oben einen Dateinamen ein und drücke **Export**. Bewahre die Datei auf: Mit **Import** oder indem du die Datei auf die Seite ziehst, holst du sie zurück, um weiterzuarbeiten.

![Die Einstellungen einer Kamera](../../../../docs/robot/customizer/component.png)

### Nützliche Ansichten {#useful-views}
- **3D**, **Top**, **Front** und **Side** zeigen den Roboter aus verschiedenen Blickwinkeln. Top ist praktisch, um Sensoren symmetrisch zu platzieren.
- **Labels** zeigt den Namen jeder Komponente.
- **Camera view** zeigt eine Schätzung dessen, was die Kameras in Webots sehen.
- Rückgängig, Wiederholen und Zurücksetzen findest du oben.

## In Erebus verwenden {#using-it-in-erebus}

Drücke den rechten LOAD-Button des [Steuerfensters](/docs/getting-started/#the-control-window) und wähle deine `.json`-Datei. Siehe [In Erebus laden](/docs/robot/#load-it-in-erebus). Erebus prüft das Budget und erzeugt den Roboter, und die Webots-Konsole listet jede Komponente mit ihren Kosten auf.

Lade zuerst deinen Roboter und dann dein Programm.

## Komponenten {#components}

| Komponente | Kosten | Standardname |
|---|---|---|
| Rad (2, Pflicht) | je 300 | `wheel1`, `wheel2` |
| Abstandssensor (bis zu 8) | je 50 | `distance sensor1`, `distance sensor2`… |
| Gyroskop | 100 | `gyro` |
| Inertialsensor | 100 | `inertial_unit` |
| Beschleunigungssensor | 100 | `accelerometer` |
| Farbsensor | 100 | `colour_sensor` |
| GPS | 250 | `gps` |
| LIDAR | 500 | `lidar` |
| Kamera (bis zu 3) | 500, plus die Kosten der Auflösung | `camera1`, `camera2`, `camera3` |

Die Kosten der Auflösung einer Kamera werden für Breite und Höhe addiert: 32 oder 40 Pixel kosten 0, 64 Pixel kosten 100, 128 Pixel kosten 200 und 256 Pixel kosten 300. Eine Kamera mit 256 × 128 kostet zum Beispiel 500 + 300 + 200 = 1000.

Neue Kameras haben 40 × 32 Pixel. Der Starter-Roboter verwendet 64 × 40.

Die beiden Räder kosten zusammen 600, also bleiben 2400 des Budgets für alles andere.

## Tipps zum Entwurf {#design-tips}

- **GPS:** Du brauchst eine Position, um Markierungen zu melden, und so bekommst du sie am einfachsten.
- **Kameras:** Höhere Auflösungen lesen Markierungen aus größerer Entfernung, kosten aber mehr und sind langsamer zu verarbeiten.
- **LIDAR:** Es sieht rund um den Roboter, was beim Kartieren sehr hilft. Platziere es oben und leg es mit der Drehung X `90` flach, wie beim [Starter-Roboter](/docs/robot/build/), sonst verdeckt es der Roboter.
- **Farbsensor:** Platziere ihn vor den Rädern, damit der Roboter ein Loch sieht, bevor er hineinfällt.

[Roboter bauen](/docs/robot/build/) zeigt ein vollständiges Beispiel.
