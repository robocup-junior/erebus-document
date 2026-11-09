---
title: macOS
description: Comment configurer le Remote Controller sous macOS.
---

# Faire tourner le serveur de jeu et le programme contrôleur sur le même ordinateur
Commencez par faire tourner le serveur de jeu et votre programme contrôleur sur le même ordinateur. Ce n’est pas la configuration utilisée en compétition, mais elle est pratique pour déboguer en local.

## Activer le mode distant {#toggle-remote-mode}
Ouvrez le monde, appuyez sur **Robot setup** dans la fenêtre de contrôle, et activez **Remote mode**. Chargez d’abord votre robot sous **Robot JSON**, si vous avez un robot personnalisé.

![Remote mode, activé dans Robot setup](../../../../../docs/competition/remote-controller/mac/toggle_remote.png)

Si la fenêtre de contrôle n’est pas affichée, faites un clic droit sur « DEF MAINSUPERVISOR Robot » dans le Scene Tree (arbre de scène) et choisissez « Show Robot Window ».

## Lancer votre programme {#execute-your-program}
Ouvrez un terminal et exécutez les commandes suivantes, en remplaçant `<Your controller path>` par le chemin de votre programme contrôleur.

```bash
export WEBOTS_HOME=/Applications/Webots.app
"$WEBOTS_HOME/Contents/MacOS/webots-controller" "<Your controller path>"
```

Si Webots est installé à un autre endroit ou sous un autre nom, modifiez `WEBOTS_HOME` en conséquence, par exemple `"/Applications/Webots R2025a.app"`.

Le contrôleur se connecte à Webots et attend le début de la partie.

## Démarrer la partie {#start-the-game}
Appuyez sur **Run match** dans la fenêtre de contrôle. Le robot apparaît, et votre programme démarre.

## Arrêter la partie {#terminate-the-game}
Pour arrêter la partie, appuyez sur Ctrl+C dans le terminal.

Quand le jeu se termine, appuyez sur **Reset** pour le relancer. La réinitialisation désactive Remote mode, sauf si **Keep on Reset** est activé.

# Faire tourner le serveur de jeu sur un autre ordinateur
C’est la configuration utilisée lors des compétitions officielles. L’ordinateur qui exécute votre contrôleur (le client) et celui qui exécute le jeu (le serveur) doivent être connectés au même réseau.

1. (Serveur) Lancez Webots sur le serveur, ouvrez le monde et activez **Remote mode** dans **Robot setup** de la fenêtre de contrôle.
1. (Serveur) Trouvez l’adresse IP du serveur, dans Réglages Système > Réseau.
1. (Client) Exécutez les commandes suivantes, en remplaçant `<Your controller path>` par le chemin de votre programme contrôleur et `<Server IP address>` par l’adresse IP trouvée à l’étape précédente.

    ```bash
    export WEBOTS_HOME=/Applications/Webots.app
    "$WEBOTS_HOME/Contents/MacOS/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. (Serveur) Lancez le jeu en appuyant sur **Run match**.

## Dépannage {#troubleshooting}
- **Le contrôleur n’arrive pas à se connecter :** vérifiez que les deux ordinateurs peuvent communiquer entre eux, par exemple avec `ping`, que le pare-feu du serveur autorise le port TCP 1234, et que la liste des adresses IP autorisées dans l’onglet Network des préférences de Webots est vide ou contient le client.
- **Le contrôleur attend, mais le robot ne bouge pas :** vérifiez que **Remote mode** est activé, et appuyez sur **Run match**.
- **Le contrôleur ne trouve pas une bibliothèque Python :** le programme s’exécute avec l’installation Python du client : installez donc la bibliothèque sur celui-ci.

# Documentation officielle
Pour en savoir plus sur cette configuration, consultez le [guide de Webots](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a).
