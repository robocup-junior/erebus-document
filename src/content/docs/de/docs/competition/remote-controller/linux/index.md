---
title: Linux (Ubuntu)
description: So richtest du den Remote Controller unter Linux (Ubuntu 22.04 LTS) ein.
---

# Spielserver und Controller-Programm auf demselben Computer ausführen
Führe zuerst den Spielserver und dein Controller-Programm auf demselben Computer aus. Das entspricht nicht dem Setup beim Wettbewerb, ist aber praktisch, um lokal zu debuggen.

## Remote-Modus einschalten {#toggle-remote-mode}
Öffne die Welt, drücke im Steuerfenster auf **Robot setup** und schalte **Remote mode** ein. Lade vorher deinen Roboter unter **Robot JSON**, falls du einen eigenen Roboter hast.

![Remote mode, eingeschaltet in Robot setup](../../../../../docs/competition/remote-controller/linux/toggle_remote.png)

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
Drücke im Steuerfenster auf **Run match**. Der Roboter erscheint, und dein Programm startet.

## Das Spiel beenden {#terminate-the-game}
Um das Spiel zu stoppen, drücke Strg+C im Terminal.

Wenn das Spiel endet, drücke auf **Reset**, um es noch einmal auszuführen. Beim Zurücksetzen wird Remote mode ausgeschaltet, außer **Keep on Reset** ist eingeschaltet.

# Den Spielserver auf einem anderen Computer ausführen
Dieses Setup wird bei offiziellen Wettbewerben verwendet. Der Computer, auf dem dein Controller läuft (der Client), und der Computer, auf dem das Spiel läuft (der Server), müssen mit demselben Netzwerk verbunden sein.

1. (Server) Starte Webots auf dem Server, öffne die Welt und schalte **Remote mode** in **Robot setup** des Steuerfensters ein.
1. (Server) Finde die IP-Adresse des Servers heraus, zum Beispiel mit dem Befehl `ip addr`.
1. (Client) Führe die folgenden Befehle aus. Ersetze dabei `<Your controller path>` durch den Pfad zu deinem Controller-Programm und `<Server IP address>` durch die IP-Adresse aus dem vorherigen Schritt.

    ```bash
    export WEBOTS_HOME=/usr/local/webots
    "$WEBOTS_HOME/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. (Server) Starte das Spiel mit **Run match**.

## Fehlerbehebung {#troubleshooting}
- **Der Controller kann sich nicht verbinden:** Prüfe, ob sich die beiden Computer gegenseitig erreichen, zum Beispiel mit `ping`, ob die Firewall des Servers den TCP-Port 1234 zulässt und ob die Liste der erlaubten IPs im Tab „Network“ der Webots-„Preferences“ leer ist oder den Client enthält.
- **Der Controller wartet, aber der Roboter bewegt sich nicht:** Prüfe, ob **Remote mode** eingeschaltet ist, und drücke auf **Run match**.
- **Der Controller findet eine Python-Bibliothek nicht:** Das Programm läuft mit der Python-Installation des Clients, also installiere die Bibliothek dort.

# Offizielle Dokumentation
Mehr Details zu diesem Setup findest du im [Webots-Handbuch](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a).
