---
title: Fehlerbehebung
description: Lösungen für häufige Probleme beim Installieren und Ausführen von Erebus.
---

Sieh zuerst in der Webots-Konsole nach. Bei den meisten Problemen steht dort eine Fehlermeldung.

## Installation {#installation}

### `No module named 'cv2'` {#no-module-named-cv2}
OpenCV ist nicht in dem Python installiert, das Webots verwendet. Installiere die [benötigten Bibliotheken](/docs/installation/#python-libraries) in diesem Python. Wenn du mehrere Installationen hast, verrät dir die Einstellung **Python command** weiter unten, welche Webots verwendet.

### `WARNING: Python was not found` {#warning-python-was-not-found}
Webots weiß nicht, wo Python ist.

1. Finde es. Führe unter macOS und Linux `which python3` in einem Terminal aus. Prüfe unter Windows, ob die Eingabe von `python` in einer neuen Eingabeaufforderung Python öffnet. Falls nicht, installiere Python erneut und setze dabei das Häkchen bei der Option, es zu deinem PATH hinzuzufügen.
2. Öffne die Webots-Einstellungen: **Webots > Preferences** unter macOS, **Tools > Preferences** unter Windows und Linux.

   ![Der Eintrag Preferences im Webots-Menü](../../../docs/troubleshooting/preferences_open.png)

3. Trage den Pfad in das Feld **Python command** ein. Unter Windows reicht meist `python`.

   ![Das Feld Python command in den Webots-Einstellungen](../../../docs/troubleshooting/preferences.png)

### `ERROR: Skipped PROTO 'custom_robot'` {#error-skipped-proto-custom_robot}
Das erscheint beim ersten Öffnen einer Welt, bevor Erebus das Robotermodell vorbereitet hat. Erebus bereitet es vor und lädt die Welt von selbst neu, du kannst es also ignorieren.

### Der Spieltimer erscheint nicht {#the-game-timer-does-not-appear}
Der erste Start kann einige Minuten dauern, während Erebus Bibliotheken installiert. Wenn er nie fertig wird, sieh in der Konsole nach Fehlern. Wenn die automatische Installation nicht funktioniert, installiere die [benötigten Bibliotheken](/docs/installation/#python-libraries) selbst.

## Erebus ausführen {#running-erebus}

### Das Steuerfenster erscheint nicht {#the-control-window-does-not-appear}
Das Steuerfenster ist eine Webseite, die Webots öffnet.

1. Wenn du es geschlossen hast oder dein Browser es blockiert hat, lade die Welt mit dem Neuladen-Button von Webots neu. Erebus öffnet das Steuerfenster dann erneut.
2. Andernfalls stelle mit **Tools > Scene Tree** sicher, dass der Scene Tree angezeigt wird.
3. Suche **DEF MAINSUPERVISOR Robot** im Scene Tree, klicke mit der rechten Maustaste darauf und wähle **Show Robot Window**.

Das Steuerfenster hat eine private Adresse, die sich bei jedem Laden der Welt ändert. Wenn du das Fenster selbst unter `localhost:1234` öffnest, zeigt es **Read-only**, und seine Schaltflächen funktionieren nicht.

### Das Steuerfenster meldet „Access log incomplete“ {#the-control-window-says-access-log-incomplete}
Diese Warnung erscheint, wenn [Wireshark](/docs/installation/#optional-wireshark) nicht installiert ist. Sie ist für Veranstalter bei Wettbewerben gedacht: Drücke auf **Acknowledge** und übe wie gewohnt.

![Die Option Show Robot Window im Scene Tree](../../../docs/troubleshooting/showrobot.png)

### Der Webots-Bildschirm ist leer oder schwarz {#the-webots-screen-is-blank-or-black}
Kopiere den Download und entpacke ihn in einen separaten Ordner, bevor du die Welt öffnest.

### Die Simulation läuft zu langsam {#the-simulation-runs-too-slowly}
Das liegt wahrscheinlich an der Leistung deines Computers. Eine niedrigere Grafikqualität kann helfen:

1. Öffne die Webots-Einstellungen (Preferences).
2. Öffne den Tab **OpenGL**.
3. Ändere die Einstellungen.

![Der Tab OpenGL in den Webots-Einstellungen](../../../docs/troubleshooting/opengl.png)

Diese Einstellungen verändern, was die Kameras sehen, und der Wettbewerb verwendet [eigene Einstellungen](/docs/competition/#opengl-settings). Prüfe dein Programm also auch mit diesen.

## Dein Roboter {#your-robot}

### Mein Programm meldet, dass ein Gerät nicht gefunden wurde {#my-program-says-a-device-was-not-found}
Siehe unten. Prüfe außerdem, ob du deinen Roboter vor dem Spielstart unter **Robot JSON** in **Robot setup** geladen hast.

## Dein Programm {#your-program}

### `Device "..." was not found` {#device--was-not-found}
Der Gerätename in deinem Programm passt nicht zu deinem Roboter. Die Namen des Starter-Roboters stehen in der [Referenz](/docs/reference/parameters/#device-names-of-the-starter-robot). Bei deinem eigenen Roboter sind es die Namen, die du im [Robot Customizer](/docs/robot/customizer/) festgelegt hast. Prüfe, ob dein Roboter geladen wurde.

### Nichts passiert, wenn ich eine Wandmarkierung melde {#nothing-happens-when-i-report-a-wall-token}
Schalte im Steuerfenster unter **Advanced setup** die Option **Enable debugging** ein und sieh in der Konsole nach. Die häufigsten Ursachen sind, dass der Roboter nicht mindestens 1 Sekunde stand, dass die Koordinaten nicht in Zentimeter umgerechnet wurden und dass der Roboter oder die Position mehr als eine halbe Kachel (6 cm) von der Markierung entfernt war. Siehe [Kommunikation](/docs/programming/communication/#scoring-wall-tokens).

### Meine Meldungen sind Fehlerkennungen {#my-reports-are-misidentifications}
Der Roboter darf höchstens eine halbe Kachel von der Markierung entfernt sein und muss auf derselben Seite der Wand stehen, und jede Markierung bringt nur einmal Punkte. Auch das Melden einer Fälschung zählt als Fehlerkennung.

### Das Spiel endet mit „Battery depleted“ {#the-game-ends-with-battery-depleted}
Der Akku war leer. Halte vorher 5 Sekunden lang auf einer Kontaktkachel an, um ihn auszutauschen. Siehe [Akku](/docs/programming/battery/).

### Mein Programm erhält keine Spielinformationen mehr {#my-program-no-longer-receives-the-game-information}
Seit Erebus v27 ist die Antwort auf `G` 20 Byte lang, mit dem Akkustand am Ende. Passe die Längenprüfung in deinem Programm an. Siehe [Spielinformationen](/docs/programming/communication/#game-information).

### Die Karte bekommt 0 % oder einen Bewertungsfehler {#the-map-gets-0-or-a-scoring-error}
Deine Karte muss die Startkachel (`5`) enthalten, und sie kann nur einmal bewertet werden. Siehe [Die Karte abgeben](/docs/programming/map-bonus/).

### Der Controller kann sich im Remote-Modus nicht verbinden {#the-controller-cannot-connect-in-remote-mode}
Sieh dir die Anleitung zum [Remote Controller](/docs/competition/remote-controller/) für dein Betriebssystem an.

## Kommst du immer noch nicht weiter? {#still-stuck}
Frag auf dem [Discord-Server](https://discord.com/invite/6FJxZxk) oder [erstelle ein Issue](https://github.com/robocup-junior/erebus/issues). Gib dein Betriebssystem, deine Erebus- und Webots-Versionen und die Meldung in der Konsole an.
