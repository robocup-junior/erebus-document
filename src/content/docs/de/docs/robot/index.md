---
title: Roboter besorgen
description: Jedes Programm läuft auf einem Roboter, den du entwirfst. Lade den Starter-Roboter herunter oder bau ihn selbst.
---

In Erebus **entwirfst du deinen Roboter selbst**: Du wählst seine Sensoren und wo sie sitzen, im Rahmen eines Budgets. Jedes Programm braucht einen Roboter, also besteht der erste Schritt darin, einen zu besorgen und in Erebus zu laden.

![Ein echter e-puck-Roboter](../../../docs/robot/real_robot.thumbnail.jpg)

Der Roboter basiert auf dem [e-puck](https://cyberbotics.com/doc/guide/epuck?version=R2023b), einem kleinen, runden Lernroboter mit zwei Rädern. Mit dem [Robot Customizer](https://robot.erebus.rcj.cloud/) fügst du ihm Sensoren hinzu und speicherst den Entwurf als `.json`-Datei, die Erebus lädt.

## Der Starter-Roboter {#the-starter-robot}
Diese Dokumentation verwendet überall denselben Roboter, den **Starter-Roboter**, damit jedes Beispiel ohne Änderungen funktioniert. Er hat alle Sensoren, die die Tutorials brauchen:

| Komponente | Name in deinem Programm | Wofür sie da ist |
|---|---|---|
| Zwei Räder | `left wheel motor`, `right wheel motor` | Fahren |
| Rad-Encoder | `left wheel sensor`, `right wheel sensor` | Messen, wie weit sich die Räder gedreht haben |
| Drei Abstandssensoren | `leftDist`, `frontDist`, `rightDist` | Wände links, vorne und rechts finden |
| Kamera, 64 × 40 Pixel | `camera` | Wandmarkierungen finden |
| Farbsensor | `color` | Den Boden sehen: Löcher, Sümpfe und Durchgänge |
| GPS | `gps` | Die eigene Position kennen, um Markierungen zu melden |
| Gyroskop | `gyro` | Messen, wie weit er sich gedreht hat |
| Beschleunigungssensor | `accelerometer` | Beschleunigung messen |
| LIDAR | `lidar` | Entfernungen rundherum messen |
| Sender und Empfänger | `emitter`, `receiver` | Mit dem Spiel kommunizieren. Jeder Roboter hat sie. |

Er kostet 2400 des Budgets von 3000.

## Wähle deinen Weg {#choose-your-path}

**Empfohlen: Bau ihn selbst.** Das dauert etwa 15 Minuten, und du verstehst danach jeden Teil deines Roboters. Folge der Anleitung [Roboter bauen](/docs/robot/build/).

**Wenn es schnell gehen muss:** Lade den fertigen Roboter herunter und mach mit den Tutorials weiter. Du kannst jederzeit zurückkommen und ihn später bauen.

<a href="/downloads/starter-robot.json" download>starter-robot.json herunterladen</a>

## In Erebus laden {#load-it-in-erebus}
1. Öffne eine Welt, zum Beispiel `game/worlds/world1.wbt`.
2. Drücke im Steuerfenster den **rechten LOAD-Button** mit dem Robotersymbol und wähle deine `.json`-Datei.
3. Sieh in der Webots-Konsole nach. Erebus listet jede Komponente mit ihren Kosten auf und endet mit `Your custom robot has been successfully generated!`.

:::note
Erebus v26.1 gibt außerdem in Rot `PROTO parameter 'camera_width' has no matching IS field` aus. Das kannst du ignorieren: Deine Kamera hat trotzdem die Auflösung, die du gewählt hast.
:::

Der Roboter bleibt geladen, bis du einen anderen lädst oder das Spiel zurücksetzt. Als Nächstes [führst du dein erstes Programm aus](/docs/getting-started/).

## Deinen eigenen entwerfen {#designing-your-own}
Sobald du die Grundlagen kennst, kannst du den Starter-Roboter ändern oder einen neuen entwerfen: mehr Kameras mit höherer Auflösung, mehr Abstandssensoren, Sensoren an anderen Stellen. Die [Referenz: Robot Customizer](/docs/robot/customizer/) listet alle Komponenten mit ihren Kosten und Grenzen auf.

Wenn du den Namen einer Komponente änderst, ändere ihn auch in deinem Programm.
