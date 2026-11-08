---
title: Windows
description: Comment configurer le Remote Controller sous Windows.
---

# Faire tourner le serveur de jeu et le programme contrôleur sur le même ordinateur
Commencez par faire tourner le serveur de jeu et votre programme contrôleur sur le même ordinateur. Ce n’est pas la configuration utilisée en compétition, mais elle est pratique pour déboguer en local.

## Activer le mode distant {#toggle-remote-mode}
Ouvrez le monde et appuyez sur « TOGGLE REMOTE » dans la fenêtre de contrôle. Le bouton devient orange pour indiquer que le mode distant est activé.  
![Le bouton TOGGLE REMOTE](../../../../../docs/competition/remote-controller/windows/toggleRemote.png)

Si la fenêtre de contrôle n’est pas affichée, faites un clic droit sur « DEF MAINSUPERVISOR Robot » dans le Scene Tree (arbre de scène) et choisissez « Show Robot Window ».  
![L’option Show Robot Window](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## Lancer votre programme {#execute-your-program}
Ouvrez PowerShell. Vous le trouverez généralement dans la liste des applications.  
![PowerShell dans la liste des applications](../../../../../docs/competition/remote-controller/windows/powerShell.png)

Exécutez la commande suivante dans PowerShell, en remplaçant `<Your controller path>` par le chemin de votre programme contrôleur.

`webots-controller.exe <Your controller path>`

Si la commande est introuvable, utilisez son chemin complet, qui est par défaut `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe`.

Si vous ne connaissez pas le chemin de votre programme contrôleur, faites glisser le fichier dans la fenêtre PowerShell : son chemin est inséré automatiquement.  
![Glisser un fichier dans la fenêtre PowerShell](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

Appuyez ensuite sur Entrée pour exécuter la commande. Le contrôleur se connecte à Webots et attend le début de la partie.

## Démarrer la partie {#start-the-game}
Appuyez sur le bouton de démarrage dans la fenêtre de contrôle pour lancer la simulation.  
![Le bouton de démarrage de la fenêtre de contrôle](../../../../../docs/competition/remote-controller/windows/run.png)

## Arrêter la partie {#terminate-the-game}
Pour arrêter la partie, appuyez sur Ctrl+C dans PowerShell afin d’arrêter votre programme.

Quand la simulation se termine, le gestionnaire de jeu d’Erebus s’arrête aussi. Pour rejouer une partie, rechargez le monde.  
![Le bouton de rechargement de Webots](../../../../../docs/competition/remote-controller/windows/reload.png)

# Faire tourner le serveur de jeu sur un autre ordinateur
C’est la configuration utilisée lors des compétitions officielles. L’ordinateur qui exécute votre contrôleur (le client) et celui qui exécute le jeu (le serveur) doivent être connectés au même réseau.

1. (Serveur) Lancez Webots sur le serveur, ouvrez le monde et activez le mode distant dans la fenêtre de contrôle.
2. (Serveur) Trouvez l’adresse IP du serveur. Consultez [Rechercher votre adresse IP dans Windows](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9).
3. (Client) Exécutez la commande suivante dans PowerShell, en remplaçant `<Your controller path>` par le chemin de votre programme contrôleur et `<Server IP address>` par l’adresse IP trouvée à l’étape précédente.  
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. (Serveur) Démarrez la partie en appuyant sur le bouton de démarrage.

# Dépannage
Si le contrôleur n’arrive pas à se connecter, vérifiez que les deux ordinateurs peuvent communiquer entre eux, que le pare-feu du serveur autorise le port TCP 1234, et que la liste des adresses IP autorisées dans l’onglet Network des préférences de Webots est vide ou contient le client.

# Documentation officielle
Pour en savoir plus sur cette configuration, consultez le [guide de Webots](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b).
