---
title: Windows
description: Guide de configuration du Remote Controller pour Windows.
---

# Faire tourner le serveur de jeu et le programme contrôleur sur le même PC
Commençons par faire tourner le serveur de jeu et le programme contrôleur sur le même PC. Ce n’est pas la même chose qu’une vraie configuration de compétition, mais cela vous aidera à déboguer en local.

## Activer le mode distant {#toggle-remote-mode}
Appuyez sur « TOGGLE REMOTE » dans la Robot Window (fenêtre de contrôle) pour activer la configuration du contrôleur à distance. Le bouton doit devenir orange pour indiquer que le mode est activé.  
![Le bouton TOGGLE REMOTE](../../../../../docs/competition/remote-controller/windows/toggleRemote.png)

Si la Robot Window n’est pas affichée, faites un clic droit sur « DEF MAINSUPERVISOR Robot » dans le Scene Tree (arbre de scène) et choisissez « Show Robot Window ».  
![L’option Show Robot Window](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## Lancer votre programme {#execute-your-program}
Ouvrez PowerShell. Vous le trouverez généralement dans la liste des applications.  
![PowerShell dans la liste des applications](../../../../../docs/competition/remote-controller/windows/powerShell.png)

Exécutez la commande suivante dans PowerShell, en remplaçant `<Your controller path>` par le chemin de votre programme contrôleur.

`webots-controller.exe <Your controller path>`

Si la commande est introuvable, utilisez le chemin complet, qui est par défaut `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe`.

Si vous ne connaissez pas le chemin de votre programme contrôleur, vous pouvez faire glisser ce fichier dans la fenêtre PowerShell : le chemin sera rempli automatiquement.  
![Glisser un fichier dans la fenêtre PowerShell](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

Après avoir saisi la commande, appuyez sur Entrée pour l’exécuter.

## Démarrer la partie {#start-the-game}
Appuyez sur le bouton de démarrage dans la Robot Window pour lancer la simulation.  
![Le bouton de démarrage de la fenêtre de contrôle](../../../../../docs/competition/remote-controller/windows/run.png)

## Arrêter la partie {#terminate-the-game}
Pour interrompre la partie, interrompez le programme qui tourne dans PowerShell en appuyant sur Ctrl+C.

Quand la simulation s’arrête, le système de gestion de jeu d’Erebus s’arrête en même temps. Pour rejouer une partie, rechargez le monde.  
![Le bouton de rechargement de Webots](../../../../../docs/competition/remote-controller/windows/reload.png)

# Faire tourner le serveur de jeu sur un autre PC
C’est la configuration utilisée lors des compétitions officielles.
Le PC qui exécute votre contrôleur (le client) et le serveur de jeu (le serveur) doivent être connectés au même réseau.

1. (Serveur) Lancez Webots sur le PC serveur, ouvrez le monde et activez le mode distant depuis la Robot Window.
2. (Serveur) Trouvez l’adresse IP de ce PC. Vous pouvez consulter [cet article](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9).
3. (Client) Exécutez la commande suivante dans PowerShell, en remplaçant `<Your controller path>` par le chemin de votre programme contrôleur et `<Server IP address>` par l’adresse IP trouvée à l’étape précédente.   
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. (Serveur) Démarrez la partie en appuyant sur le bouton de démarrage.

# Dépannage
Si le contrôleur n’arrive pas à se connecter, vérifiez que les deux PC peuvent communiquer, que le pare-feu du serveur autorise le port TCP 1234, et que la liste des adresses IP autorisées dans l’onglet Network des préférences de Webots est vide ou contient le client.

# Documentation officielle
Pour en savoir plus sur cette configuration, consultez le [guide officiel](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b).
