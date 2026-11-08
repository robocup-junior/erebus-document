---
title: Windows
description: So richtest du den Remote Controller unter Windows ein.
---

# Spielserver und Controller-Programm auf demselben Computer ausführen
Führe zuerst den Spielserver und dein Controller-Programm auf demselben Computer aus. Das entspricht nicht dem Setup beim Wettbewerb, ist aber praktisch, um lokal zu debuggen.

## Remote-Modus einschalten {#toggle-remote-mode}
Öffne die Welt und drücke im Steuerfenster auf „TOGGLE REMOTE“. Der Button wird orange, sobald der Remote-Modus eingeschaltet ist.  
![Der Button TOGGLE REMOTE](../../../../../docs/competition/remote-controller/windows/toggleRemote.png)

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
Drücke den Start-Button im Steuerfenster, um die Simulation zu starten.  
![Der Start-Button des Steuerfensters](../../../../../docs/competition/remote-controller/windows/run.png)

## Das Spiel beenden {#terminate-the-game}
Um das Spiel zu stoppen, drücke in PowerShell Strg+C, damit dein Programm beendet wird.

Wenn die Simulation endet, wird auch die Spielverwaltung von Erebus beendet. Um das Spiel noch einmal zu starten, lade die Welt neu.  
![Der Reload-Button von Webots](../../../../../docs/competition/remote-controller/windows/reload.png)

# Den Spielserver auf einem anderen Computer ausführen
Dieses Setup wird bei offiziellen Wettbewerben verwendet. Der Computer, auf dem dein Controller läuft (der Client), und der Computer, auf dem das Spiel läuft (der Server), müssen mit demselben Netzwerk verbunden sein.

1. (Server) Starte Webots auf dem Server, öffne die Welt und schalte im Steuerfenster den Remote-Modus ein.
2. (Server) Finde die IP-Adresse des Servers heraus. Siehe [IP-Adresse in Windows ermitteln](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9).
3. (Client) Führe den folgenden Befehl in PowerShell aus. Ersetze dabei `<Your controller path>` durch den Pfad zu deinem Controller-Programm und `<Server IP address>` durch die IP-Adresse aus dem vorherigen Schritt.  
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. (Server) Starte das Spiel mit dem Start-Button.

# Fehlerbehebung
Wenn sich der Controller nicht verbinden kann, prüfe, ob sich die beiden Computer gegenseitig erreichen, ob die Firewall des Servers den TCP-Port 1234 zulässt und ob die Liste der erlaubten IPs im Tab „Network“ der Webots-„Preferences“ leer ist oder den Client enthält.

# Offizielle Dokumentation
Mehr Details zu diesem Setup findest du im [Webots-Handbuch](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b).
