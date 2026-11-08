---
title: Nachrichten-Referenz
description: Referenz der Nachrichten, die mit dem Main Supervisor ausgetauscht werden.
---

Nachrichten werden mit dem Gerät `emitter` gesendet und mit dem Gerät `receiver` empfangen. Beispiele findest du im [Kommunikations-Tutorial](/docs/programming/communication/).

Die Formatstrings unten sind die des Python-Moduls [struct](https://docs.python.org/3/library/struct.html).

## Vom Roboter gesendet {#sent-by-the-robot}

| Nachricht | Format | Länge | Zweck |
|---|---|---|---|
| Eine Wandmarkierung melden | `i i c`: x, z, Typ | 9 Bytes | Die Position ist in Zentimetern, und der Typ ist einer von `H`, `S`, `U`, `F`, `P`, `C`, `O`. Der Roboter muss mindestens 1 Sekunde gestanden haben. |
| Kartendaten | `2i` gefolgt von UTF-8-Text: Zeilen, Spalten, durch Kommas getrennte Zellen | Jede andere Länge | Speichert die Karte, ohne sie zu bewerten |
| `M` | `c` | 1 Byte | Bewertet die gespeicherte Karte. Das geht nur einmal. |
| `L` | `c` | 1 Byte | Meldet einen fehlenden Fortschritt (Lack of Progress) |
| `G` | `c` | 1 Byte | Fragt die Spielinformationen ab |
| `E` | `c` | 1 Byte | Beendet das Spiel. Gibt den Ausgangsbonus, wenn der Roboter auf der Startkachel steht und eine Wandmarkierung erkannt hat. |

Erebus unterscheidet diese Nachrichten an ihrer Länge, also muss eine Meldung genau 9 Bytes lang sein.

## Vom Roboter empfangen {#received-by-the-robot}

| Nachricht | Format | Länge | Zweck |
|---|---|---|---|
| `L` | `c` | 1 Byte | Ein fehlender Fortschritt ist eingetreten |
| `G` | `c f i i`: `G`, Punktzahl, verbleibende Spielzeit, verbleibende Echtzeit | 16 Bytes | Antwort auf `G`. Die Zeiten sind in Sekunden. |

Beachte, dass das Paket von `G` Füllbytes enthält, weil das `struct`-Format oben den Float ausrichtet: Die Punktzahl beginnt bei Byte 4, die Zeiten bei Byte 8 und 12.

## Häufige Webots-Funktionen {#common-webots-functions}

| Funktion | Beschreibung |
|---|---|
| `robot.getDevice(name)` | Holt ein Gerät über seinen Namen. In C++ verwendest du `robot->getMotor(name)`, `robot->getCamera(name)` und so weiter. |
| `robot.step(timeStep)` | Lässt die Simulation weiterlaufen. Gibt -1 zurück, wenn die Simulation endet. |
| `robot.getTime()` | Liefert die Simulationszeit in Sekunden |
| `device.enable(timeStep)` | Aktiviert einen Sensor |
| `motor.setPosition(float("inf"))` | Lässt den Motor sich unbegrenzt drehen |
| `motor.setVelocity(speed)` | Stellt die Geschwindigkeit eines Motors in Radiant pro Sekunde ein |
