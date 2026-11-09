---
title: Windows
description: Comment configurer le Remote Controller sous Windows.
---

# Faire tourner le serveur de jeu et le programme contrôleur sur le même ordinateur
Commencez par faire tourner le serveur de jeu et votre programme contrôleur sur le même ordinateur. Ce n’est pas la configuration utilisée en compétition, mais elle est pratique pour déboguer en local.

## Activer le mode distant {#toggle-remote-mode}
Ouvrez le monde, appuyez sur **Robot setup** dans la fenêtre de contrôle, et activez **Remote mode**. Chargez d’abord votre robot sous **Robot JSON**, si vous avez un robot personnalisé.  
![Remote mode, activé dans Robot setup](../../../../../docs/competition/remote-controller/windows/../mac/toggle_remote.png)

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
Appuyez sur **Run match** dans la fenêtre de contrôle pour lancer le jeu.  
![Le bouton Run match de la fenêtre de contrôle](../../../../../docs/competition/remote-controller/windows/../../../getting-started/match-controls.png)

## Arrêter la partie {#terminate-the-game}
Pour arrêter la partie, appuyez sur Ctrl+C dans PowerShell afin d’arrêter votre programme.

Quand le jeu se termine, appuyez sur **Reset** pour le relancer. La réinitialisation désactive Remote mode, sauf si **Keep on Reset** est activé.

# Faire tourner le serveur de jeu sur un autre ordinateur
C’est la configuration utilisée lors des compétitions officielles. L’ordinateur qui exécute votre contrôleur (le client) et celui qui exécute le jeu (le serveur) doivent être connectés au même réseau.

2. (Serveur) Lancez Webots sur le serveur, ouvrez le monde et activez **Remote mode** dans **Robot setup** de la fenêtre de contrôle.
2. (Serveur) Trouvez l’adresse IP du serveur. Consultez [Rechercher votre adresse IP dans Windows](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9).
3. (Client) Exécutez la commande suivante dans PowerShell, en remplaçant `<Your controller path>` par le chemin de votre programme contrôleur et `<Server IP address>` par l’adresse IP trouvée à l’étape précédente.  
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. (Serveur) Lancez le jeu en appuyant sur **Run match**.

# Dépannage
Si le contrôleur n’arrive pas à se connecter, vérifiez que les deux ordinateurs peuvent communiquer entre eux, que le pare-feu du serveur autorise le port TCP 1234, et que la liste des adresses IP autorisées dans l’onglet Network des préférences de Webots est vide ou contient le client.

# Documentation officielle
Pour en savoir plus sur cette configuration, consultez le [guide de Webots](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a).
