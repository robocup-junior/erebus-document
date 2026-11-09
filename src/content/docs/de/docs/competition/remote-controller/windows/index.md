---
title: Windows
description: So richtest du den Remote Controller unter Windows ein.
---

# Spielserver und Controller-Programm auf demselben Computer ausführen
Führe zuerst den Spielserver und dein Controller-Programm auf demselben Computer aus. Das entspricht nicht dem Setup beim Wettbewerb, ist aber praktisch, um lokal zu debuggen.

## Remote-Modus einschalten {#toggle-remote-mode}
Öffne die Welt, drücke im Steuerfenster auf **Robot setup** und schalte **Remote mode** ein. Lade vorher deinen Roboter unter **Robot JSON**, falls du einen eigenen Roboter hast.  
![Remote mode, eingeschaltet in Robot setup](../../../../../docs/competition/remote-controller/windows/../mac/toggle_remote.png)

Wenn das Steuerfenster nicht angezeigt wird, klicke im Scene Tree mit der rechten Maustaste auf „DEF MAINSUPERVISOR Robot“ und wähle „Show Robot Window“.  
![Die Option Show Robot Window](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## Dein Programm ausführen {#execute-your-program}
Öffne PowerShell. Du findest die PowerShell normalerweise in der Liste der Apps.  
![PowerShell in der Liste der Apps](../../../../../docs/competition/remote-controller/windows/powerShell.png)

Führe den folgenden Befehl in PowerShell aus. Ersetze dabei `<Your controller path>` durch den Pfad zu deinem Controller-Programm.

`webots-controller.exe <Your controller path>`

Wenn der Befehl nicht gefunden wird, verwende seinen vollständigen Pfad, standardmäßig `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe`.

Wenn du den Pfad zu deinem Controller-Programm nicht kennst, zieh die Datei per Drag-and-drop in das PowerShell-Fenster. Ihr Pfad wird dann automatisch eingefügt.  
![Eine Datei in das PowerShell-Fenster ziehen](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

Drücke dann die Eingabetaste, um den Befehl auszuführen. Der Controller verbindet sich mit Webots und wartet, bis das Spiel beginnt.

## Das Spiel starten {#start-the-game}
Drücke im Steuerfenster auf **Run match**, um das Spiel zu starten.  
![Die Schaltfläche Run match im Steuerfenster](../../../../../docs/competition/remote-controller/windows/../../../getting-started/match-controls.png)

## Das Spiel beenden {#terminate-the-game}
Um das Spiel zu stoppen, drücke in PowerShell Strg+C, damit dein Programm beendet wird.

Wenn das Spiel endet, drücke auf **Reset**, um es noch einmal auszuführen. Beim Zurücksetzen wird Remote mode ausgeschaltet, außer **Keep on Reset** ist eingeschaltet.

# Den Spielserver auf einem anderen Computer ausführen
Dieses Setup wird bei offiziellen Wettbewerben verwendet. Der Computer, auf dem dein Controller läuft (der Client), und der Computer, auf dem das Spiel läuft (der Server), müssen mit demselben Netzwerk verbunden sein.

2. (Server) Starte Webots auf dem Server, öffne die Welt und schalte **Remote mode** in **Robot setup** des Steuerfensters ein.
2. (Server) Finde die IP-Adresse des Servers heraus. Siehe [IP-Adresse in Windows ermitteln](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9).
3. (Client) Führe den folgenden Befehl in PowerShell aus. Ersetze dabei `<Your controller path>` durch den Pfad zu deinem Controller-Programm und `<Server IP address>` durch die IP-Adresse aus dem vorherigen Schritt.  
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. (Server) Starte das Spiel mit **Run match**.

# Fehlerbehebung
Wenn sich der Controller nicht verbinden kann, prüfe, ob sich die beiden Computer gegenseitig erreichen, ob die Firewall des Servers den TCP-Port 1234 zulässt und ob die Liste der erlaubten IPs im Tab „Network“ der Webots-„Preferences“ leer ist oder den Client enthält.

# Offizielle Dokumentation
Mehr Details zu diesem Setup findest du im [Webots-Handbuch](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a).
