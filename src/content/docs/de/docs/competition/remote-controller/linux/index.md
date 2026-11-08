---
title: Linux (Ubuntu)
description: So richtest du den Remote Controller unter Linux (Ubuntu 22.04 LTS) ein.
---

# Spielserver und Controller-Programm auf demselben Computer ausführen
Führe zuerst den Spielserver und dein Controller-Programm auf demselben Computer aus. Das entspricht nicht dem Setup beim Wettbewerb, ist aber praktisch, um lokal zu debuggen.

## Remote-Modus einschalten {#toggle-remote-mode}
Öffne die Welt und drücke im Steuerfenster auf „TOGGLE REMOTE“. Der Button wird orange, sobald der Remote-Modus eingeschaltet ist.

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
Um das Spiel zu stoppen, drücke Strg+C im Terminal.

Wenn die Simulation endet, wird auch die Spielverwaltung von Erebus beendet. Um das Spiel noch einmal zu starten, lade die Welt neu.

# Den Spielserver auf einem anderen Computer ausführen
Dieses Setup wird bei offiziellen Wettbewerben verwendet. Der Computer, auf dem dein Controller läuft (der Client), und der Computer, auf dem das Spiel läuft (der Server), müssen mit demselben Netzwerk verbunden sein.

1. (Server) Starte Webots auf dem Server, öffne die Welt und schalte im Steuerfenster den Remote-Modus ein.
1. (Server) Finde die IP-Adresse des Servers heraus, zum Beispiel mit dem Befehl `ip addr`.
1. (Client) Führe die folgenden Befehle aus. Ersetze dabei `<Your controller path>` durch den Pfad zu deinem Controller-Programm und `<Server IP address>` durch die IP-Adresse aus dem vorherigen Schritt.

    ```bash
    export WEBOTS_HOME=/usr/local/webots
    "$WEBOTS_HOME/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. (Server) Starte das Spiel mit dem Start-Button.

## Fehlerbehebung {#troubleshooting}
- **Der Controller kann sich nicht verbinden:** Prüfe, ob sich die beiden Computer gegenseitig erreichen, zum Beispiel mit `ping`, ob die Firewall des Servers den TCP-Port 1234 zulässt und ob die Liste der erlaubten IPs im Tab „Network“ der Webots-„Preferences“ leer ist oder den Client enthält.
- **`No robot name provided` wird angezeigt:** Diese Meldung ist normal, solange der Controller wartet. Verschwindet sie nicht, ist der Remote-Modus nicht eingeschaltet: Prüfe den Button TOGGLE REMOTE.
- **Der Controller findet eine Python-Bibliothek nicht:** Das Programm läuft mit der Python-Installation des Clients, also installiere die Bibliothek dort.

# Offizielle Dokumentation
Mehr Details zu diesem Setup findest du im [Webots-Handbuch](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b).
