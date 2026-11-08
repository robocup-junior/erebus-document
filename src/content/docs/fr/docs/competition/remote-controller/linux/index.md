---
title: Linux (Ubuntu)
description: Guide de configuration du Remote Controller pour Linux (Ubuntu 22.04 LTS).
---

# Faire tourner le serveur de jeu et le programme contrôleur sur le même ordinateur
Commençons par faire tourner le serveur de jeu et le programme contrôleur sur le même ordinateur. Ce n’est pas la même chose qu’une vraie configuration de compétition, mais cela vous aidera à déboguer en local.

## Activer le mode distant {#toggle-remote-mode}
Ouvrez le monde et appuyez sur « TOGGLE REMOTE » dans la fenêtre de contrôle. Le bouton doit devenir orange pour indiquer que le mode est activé.

![Le bouton TOGGLE REMOTE, activé](../../../../../docs/competition/remote-controller/linux/toggle_remote.png)

Si la fenêtre de contrôle n’est pas affichée, faites un clic droit sur « DEF MAINSUPERVISOR Robot » dans le Scene Tree (arbre de scène) et choisissez « Show Robot Window ».

## Lancer votre programme {#execute-your-program}
Ouvrez un terminal et exécutez les commandes suivantes, en remplaçant `<Your controller path>` par le chemin de votre programme contrôleur.

```bash
export WEBOTS_HOME=/usr/local/webots
"$WEBOTS_HOME/webots-controller" "<Your controller path>"
```

On suppose ici que Webots a été installé avec le paquet `.deb` dans `/usr/local/webots`. Si vous l’avez installé ailleurs, modifiez `WEBOTS_HOME` en conséquence.

Le contrôleur se connecte à Webots et attend le début de la partie.

## Démarrer la partie {#start-the-game}
Appuyez sur le bouton de démarrage dans la fenêtre de contrôle. Le robot apparaît, et votre programme commence à s’exécuter.

## Arrêter la partie {#terminate-the-game}
Pour interrompre la partie, appuyez sur Ctrl+C dans le terminal.

Quand la simulation s’arrête, le système de gestion de jeu d’Erebus s’arrête en même temps. Pour rejouer une partie, rechargez le monde.

# Faire tourner le serveur de jeu sur un autre ordinateur
C’est la configuration utilisée lors des compétitions officielles. L’ordinateur qui exécute votre contrôleur (le client) et le serveur de jeu (le serveur) doivent être connectés au même réseau.

1. (Serveur) Lancez Webots sur le serveur, ouvrez le monde et activez le mode distant dans la fenêtre de contrôle.
1. (Serveur) Trouvez l’adresse IP du serveur. Vous pouvez utiliser la commande `ip addr`.
1. (Client) Exécutez les commandes suivantes, en remplaçant `<Your controller path>` par le chemin de votre programme contrôleur et `<Server IP address>` par l’adresse IP trouvée à l’étape précédente.

    ```bash
    export WEBOTS_HOME=/usr/local/webots
    "$WEBOTS_HOME/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. (Serveur) Démarrez la partie en appuyant sur le bouton de démarrage.

## Dépannage {#troubleshooting}
- **Le contrôleur n’arrive pas à se connecter :** vérifiez que les deux ordinateurs peuvent communiquer, par exemple avec `ping`, que le pare-feu du serveur autorise le port TCP 1234, et que la liste des adresses IP autorisées dans l’onglet Network des préférences de Webots est vide ou contient le client.
- **Le message `No robot name provided` s’affiche :** ce message est normal pendant l’attente. S’il continue de s’afficher, le mode distant n’est pas activé : vérifiez le bouton TOGGLE REMOTE.
- **Le contrôleur ne trouve pas une bibliothèque Python :** le programme s’exécute avec le Python du client, installez-la donc sur celui-ci.

# Documentation officielle
Pour en savoir plus sur cette configuration, consultez le [guide officiel](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b).
