---
title: Linux (Ubuntu)
description: Einrichtungsanleitung für den Remote Controller unter Linux (Ubuntu 22.04 LTS).
---

# Spielserver und Controller-Programm auf demselben Computer ausführen
Probieren wir zuerst, den Spielserver und das Controller-Programm auf demselben Computer auszuführen. Das entspricht nicht dem echten Wettbewerbs-Setup, hilft dir aber beim lokalen Debuggen.

## Remote-Modus einschalten {#toggle-remote-mode}
Öffne die Welt und drücke im Steuerfenster auf „TOGGLE REMOTE“. Der Button sollte orange werden, um anzuzeigen, dass der Modus aktiviert ist.

![Der Button TOGGLE REMOTE, eingeschaltet](../../../../../docs/competition/remote-controller/linux/toggle_remote.png)

Wenn das Steuerfenster nicht angezeigt wird, klicke im Scene Tree mit der rechten Maustaste auf „DEF MAINSUPERVISOR Robot“ und wähle „Show Robot Window“.

## Dein Programm ausführen {#execute-your-program}
Öffne ein Terminal und führe die folgenden Befehle aus. Ersetze dabei `<Your controller path>` durch den Pfad zu deinem Controller-Programm.

```bash
export WEBOTS_HOME=/usr/local/webots
"$WEBOTS_HOME/webots-controller" "<Your controller path>"
```

Das setzt voraus, dass Webots mit dem `.deb`-Paket in `/usr/local/webots` installiert wurde. Wenn du es woanders installiert hast, passe `WEBOTS_HOME` entsprechend an.

Der Controller verbindet sich mit Webots und wartet, bis das Spiel beginnt.

## Das Spiel starten {#start-the-game}
Drücke den Start-Button im Steuerfenster. Der Roboter erscheint, und dein Programm beginnt zu laufen.

## Das Spiel beenden {#terminate-the-game}
Um das Spiel abzubrechen, drücke Ctrl+C im Terminal.

Sobald die Simulation beendet ist, wird gleichzeitig auch die Spielverwaltung von Erebus beendet. Wenn du das Spiel noch einmal ausführen möchtest, lade die Welt neu.

# Den Spielserver auf einem anderen Computer ausführen
Dieses Setup wird bei offiziellen Wettbewerben verwendet. Der Computer, auf dem dein Controller läuft (Client), und der Spielserver (Server) müssen mit demselben Netzwerk verbunden sein.

1. (Server) Starte Webots auf dem Server, öffne die Welt und schalte im Steuerfenster den Remote-Modus ein.
1. (Server) Finde die IP-Adresse des Servers heraus. Dafür kannst du den Befehl `ip addr` verwenden.
1. (Client) Führe die folgenden Befehle aus. Ersetze dabei `<Your controller path>` durch den Pfad zu deinem Controller-Programm und `<Server IP address>` durch die IP-Adresse aus dem vorherigen Schritt.

    ```bash
    export WEBOTS_HOME=/usr/local/webots
    "$WEBOTS_HOME/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. (Server) Starte das Spiel mit dem Start-Button.

## Fehlerbehebung {#troubleshooting}
- **Der Controller kann sich nicht verbinden:** Prüfe, ob sich beide Computer gegenseitig erreichen, zum Beispiel mit `ping`, ob die Firewall des Servers den TCP-Port 1234 zulässt und ob die Liste der erlaubten IPs im Tab „Network“ der Webots-„Preferences“ leer ist oder den Client enthält.
- **`No robot name provided` wird angezeigt:** Diese Meldung ist während des Wartens normal. Wird sie dauerhaft angezeigt, ist der Remote-Modus nicht eingeschaltet. Prüfe also den Button TOGGLE REMOTE.
- **Der Controller findet eine Python-Bibliothek nicht:** Das Programm läuft mit dem Python des Clients, also installiere sie dort.

# Offizielle Dokumentation
Wenn du mehr Details über das Setup wissen möchtest, findest du sie in der [offiziellen Anleitung](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b).
