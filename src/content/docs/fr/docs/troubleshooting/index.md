---
title: Dépannage
description: Solutions aux problèmes courants lors de l’installation et de l’utilisation d’Erebus.
---

Avant tout, consultez la console de Webots. La plupart des problèmes y affichent un message d’erreur.

## Installation {#installation}

### `No module named 'cv2'` {#no-module-named-cv2}
OpenCV n’est pas installé dans le Python utilisé par Webots. Installez les [bibliothèques nécessaires](/docs/installation/#python-libraries) dans ce Python. Si vous avez plusieurs installations, le réglage **Python command** ci-dessous vous indique laquelle Webots utilise.

### `WARNING: Python was not found` {#warning-python-was-not-found}
Webots ne sait pas où se trouve Python.

1. Trouvez-le. Sous macOS et Linux, exécutez `which python3` dans un terminal. Sous Windows, vérifiez que taper `python` dans une nouvelle invite de commandes ouvre Python. Si ce n’est pas le cas, réinstallez Python en cochant l’option qui l’ajoute à votre PATH.
2. Ouvrez les préférences de Webots : **Webots > Preferences** sous macOS, **Tools > Preferences** sous Windows et Linux.

   ![L’élément Preferences dans le menu de Webots](../../../docs/troubleshooting/preferences_open.png)

3. Indiquez le chemin dans le champ **Python command**. Sous Windows, `python` suffit généralement.

   ![Le champ Python command dans les préférences de Webots](../../../docs/troubleshooting/preferences.png)

### `ERROR: Skipped PROTO 'custom_robot'` {#error-skipped-proto-custom_robot}
Ce message apparaît la première fois que vous ouvrez un monde, avant qu’Erebus ait préparé le modèle du robot. Erebus le prépare et recharge le monde de lui-même : vous pouvez l’ignorer.

### Le chronomètre de jeu n’apparaît pas {#the-game-timer-does-not-appear}
Le premier démarrage peut prendre quelques minutes, le temps qu’Erebus installe les bibliothèques. S’il ne se termine jamais, cherchez des erreurs dans la console. Si l’installation automatique ne fonctionne pas, installez vous-même les [bibliothèques nécessaires](/docs/installation/#python-libraries).

## Faire tourner Erebus {#running-erebus}

### La fenêtre de contrôle n’apparaît pas {#the-control-window-does-not-appear}
La fenêtre de contrôle est une page web ouverte par Webots.

1. Si vous l’avez fermée, ou si votre navigateur l’a bloquée, rechargez le monde avec le bouton de rechargement de Webots. Erebus rouvre la fenêtre de contrôle.
2. Sinon, assurez-vous que le Scene Tree (arbre de scène) est affiché, avec **Tools > Scene Tree**.
3. Trouvez **DEF MAINSUPERVISOR Robot** dans le Scene Tree, faites un clic droit dessus et choisissez **Show Robot Window**.

La fenêtre de contrôle a une adresse privée, qui change à chaque chargement du monde. Si vous ouvrez vous-même la fenêtre à `localhost:1234`, elle affiche **Read-only**, et ses boutons ne fonctionnent pas.

### La fenêtre de contrôle affiche « Access log incomplete » {#the-control-window-says-access-log-incomplete}
Cet avertissement apparaît quand [Wireshark](/docs/installation/#optional-wireshark) n’est pas installé. Il sert aux organisateurs en compétition : appuyez sur **Acknowledge** et entraînez-vous normalement.

![L’option Show Robot Window dans le Scene Tree](../../../docs/troubleshooting/showrobot.png)

### L’écran de Webots est vide ou noir {#the-webots-screen-is-blank-or-black}
Copiez le téléchargement et décompressez-le dans un dossier séparé avant d’ouvrir le monde.

### La simulation est trop lente {#the-simulation-runs-too-slowly}
C’est probablement dû aux performances de votre ordinateur. Baisser la qualité graphique peut aider :

1. Ouvrez les préférences de Webots.
2. Ouvrez l’onglet **OpenGL**.
3. Modifiez les réglages.

![L’onglet OpenGL des préférences de Webots](../../../docs/troubleshooting/opengl.png)

Ces réglages modifient ce que voient les caméras, et la compétition utilise [ses propres réglages](/docs/competition/#opengl-settings) : vérifiez donc aussi votre programme avec ceux-ci.

## Votre robot {#your-robot}

### Mon programme indique qu’un composant est introuvable {#my-program-says-a-device-was-not-found}
Voir ci-dessous. Vérifiez aussi que vous avez chargé votre robot sous **Robot JSON** dans **Robot setup** avant de lancer le jeu.

## Votre programme {#your-program}

### `Device "..." was not found` {#device--was-not-found}
Le nom du composant dans votre programme ne correspond pas à votre robot. Les noms du robot de départ se trouvent dans la [Référence](/docs/reference/parameters/#device-names-of-the-starter-robot). Pour votre propre robot, ce sont les noms que vous avez définis dans le [Robot Customizer](/docs/robot/customizer/). Vérifiez que votre robot a bien été chargé.

### Rien ne se passe quand je signale un marqueur mural {#nothing-happens-when-i-report-a-wall-token}
Activez **Enable debugging** dans **Advanced setup** de la fenêtre de contrôle, et regardez la console. Les causes les plus courantes sont que le robot n’était pas arrêté depuis au moins 1 seconde, que les coordonnées n’étaient pas converties en centimètres, et que le robot ou la position était à plus d’une demi-case (6 cm) du marqueur. Voir [Communication](/docs/programming/communication/#scoring-wall-tokens).

### Mes signalements sont des erreurs d’identification {#my-reports-are-misidentifications}
Le robot doit être à au plus une demi-case du marqueur et du même côté du mur, et chaque marqueur ne rapporte des points qu’une seule fois. Signaler un leurre compte aussi comme une erreur d’identification.

### Le jeu se termine avec « Battery depleted » {#the-game-ends-with-battery-depleted}
La batterie était vide. Arrêtez-vous 5 secondes sur une case de contact pour la remplacer avant que cela n’arrive. Voir [Batterie](/docs/programming/battery/).

### Mon programme ne reçoit plus les informations de jeu {#my-program-no-longer-receives-the-game-information}
Depuis Erebus v27, la réponse à `G` fait 20 octets, avec le niveau de la batterie à la fin. Mettez à jour la vérification de la longueur dans votre programme. Voir [Informations de jeu](/docs/programming/communication/#game-information).

### La carte obtient 0 % ou une erreur de score {#the-map-gets-0-or-a-scoring-error}
Votre carte doit contenir la case de départ (`5`), et elle ne peut être évaluée qu’une seule fois. Consultez [Soumettre la carte](/docs/programming/map-bonus/).

### Le contrôleur n’arrive pas à se connecter en mode distant {#the-controller-cannot-connect-in-remote-mode}
Consultez le guide [Remote Controller](/docs/competition/remote-controller/) correspondant à votre système d’exploitation.

## Toujours bloqué ? {#still-stuck}
Posez votre question sur le [serveur Discord](https://discord.com/invite/6FJxZxk), ou [ouvrez une issue](https://github.com/robocup-junior/erebus/issues). Indiquez votre système d’exploitation, vos versions d’Erebus et de Webots, et le message affiché dans la console.
