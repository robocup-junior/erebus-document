---
title: Windows
description: Einrichtungsanleitung für den Remote Controller unter Windows.
---

# Spielserver und Controller-Programm auf demselben PC ausführen
Probieren wir zuerst, den Spielserver und das Controller-Programm auf demselben PC auszuführen. Das entspricht nicht dem echten Wettbewerbs-Setup, hilft dir aber beim lokalen Debuggen.

## Remote-Modus einschalten {#toggle-remote-mode}
Drücke im Robot Window (Steuerfenster) auf „TOGGLE REMOTE“, um das Remote-Controller-Setup zu aktivieren. Der Button sollte orange werden, um anzuzeigen, dass der Modus aktiviert ist.  
![Der Button TOGGLE REMOTE](../../../../../docs/competition/remote-controller/windows/toggleRemote.png)

Wenn das Robot Window nicht angezeigt wird, klicke im Scene Tree mit der rechten Maustaste auf „DEF MAINSUPERVISOR Robot“ und wähle „Show Robot Window“.  
![Die Option Show Robot Window](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## Dein Programm ausführen {#execute-your-program}
Öffne PowerShell. Du findest es normalerweise in der Liste der Anwendungen.  
![PowerShell in der Liste der Anwendungen](../../../../../docs/competition/remote-controller/windows/powerShell.png)

Führe den folgenden Befehl in PowerShell aus. Ersetze dabei `<Your controller path>` durch den Pfad zu deinem Controller-Programm.

`webots-controller.exe <Your controller path>`

Wenn der Befehl nicht gefunden wird, verwende den vollständigen Pfad, standardmäßig `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe`.

Wenn du den Pfad zu deinem Controller-Programm nicht kennst, kannst du die Datei per Drag-and-drop in das PowerShell-Fenster ziehen, dann wird er automatisch eingefügt.  
![Eine Datei in das PowerShell-Fenster ziehen](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

Drücke nach der Eingabe des Befehls die Eingabetaste, um ihn auszuführen.

## Das Spiel starten {#start-the-game}
Drücke den Start-Button im Robot Window, um die Simulation zu starten.  
![Der Start-Button des Steuerfensters](../../../../../docs/competition/remote-controller/windows/run.png)

## Das Spiel beenden {#terminate-the-game}
Um das Spiel abzubrechen, unterbrich das in PowerShell laufende Programm mit Ctrl+C.

Sobald die Simulation beendet ist, wird gleichzeitig auch die Spielverwaltung von Erebus beendet. Wenn du das Spiel noch einmal ausführen möchtest, lade die Welt neu.  
![Der Reload-Button von Webots](../../../../../docs/competition/remote-controller/windows/reload.png)

# Den Spielserver auf einem anderen PC ausführen
Dieses Setup wird bei offiziellen Wettbewerben verwendet.
Der PC, auf dem dein Controller läuft (Client), und der Spielserver (Server) müssen mit demselben Netzwerk verbunden sein.

1. (Server) Starte Webots auf dem Server-PC, öffne die Welt und schalte im Robot Window den Remote-Modus ein.
2. (Server) Finde die IP-Adresse dieses PCs heraus. Dazu kannst du [diesen Artikel](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9) lesen.
3. (Client) Führe den folgenden Befehl in PowerShell aus. Ersetze dabei `<Your controller path>` durch den Pfad zu deinem Controller-Programm und `<Server IP address>` durch die IP-Adresse aus dem vorherigen Schritt.   
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. (Server) Starte das Spiel mit dem Start-Button.

# Fehlerbehebung
Wenn sich der Controller nicht verbinden kann, prüfe, ob sich beide PCs gegenseitig erreichen, ob die Firewall des Servers den TCP-Port 1234 zulässt und ob die Liste der erlaubten IPs im Tab „Network“ der Webots-„Preferences“ leer ist oder den Client enthält.

# Offizielle Dokumentation
Wenn du mehr Details über das Setup wissen möchtest, findest du sie in der [offiziellen Anleitung](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b).
