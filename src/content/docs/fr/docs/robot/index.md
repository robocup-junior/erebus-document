---
title: Obtenir votre robot
description: Chaque programme s’exécute sur un robot que vous concevez. Téléchargez le robot de départ, ou construisez-le vous-même.
---

Dans Erebus, **c’est vous qui concevez votre robot** : vous choisissez ses capteurs et leur emplacement, dans les limites d’un budget. Chaque programme en a besoin d’un : la première étape est donc d’obtenir un robot et de le charger dans Erebus.

![Un vrai robot e-puck](../../../docs/robot/real_robot.thumbnail.jpg)

Le robot est basé sur l’[e-puck](https://cyberbotics.com/doc/guide/epuck?version=R2023b), un petit robot éducatif rond à deux roues. Vous lui ajoutez des capteurs avec le [Robot Customizer](https://robot.erebus.rcj.cloud/), et vous enregistrez le modèle dans un fichier `.json` qu’Erebus charge.

## Le robot de départ {#the-starter-robot}
Cette documentation utilise partout le même robot, le **robot de départ**, pour que chaque exemple fonctionne tel quel. Il possède tous les capteurs dont les tutoriels ont besoin :

| Composant | Nom dans votre programme | À quoi il sert |
|---|---|---|
| Deux roues | `left wheel motor`, `right wheel motor` | Se déplacer |
| Encodeurs de roues | `left wheel sensor`, `right wheel sensor` | Mesurer de combien les roues ont tourné |
| Trois capteurs de distance | `leftDist`, `frontDist`, `rightDist` | Détecter les murs à gauche, devant et à droite |
| Caméra, 64 × 40 pixels | `camera` | Trouver les marqueurs muraux |
| Capteur de couleur | `color` | Voir le sol : trous, marécages et passages |
| GPS | `gps` | Connaître sa position, pour signaler les marqueurs |
| Gyroscope | `gyro` | Mesurer de combien il a tourné |
| Accéléromètre | `accelerometer` | Mesurer l’accélération |
| LIDAR | `lidar` | Mesurer les distances tout autour |
| Émetteur et récepteur | `emitter`, `receiver` | Communiquer avec le jeu. Tous les robots en ont. |

Il coûte 2400 sur un budget de 3000.

## Choisissez votre chemin {#choose-your-path}

**Recommandé : construisez-le vous-même.** Cela prend environ 15 minutes, et vous comprendrez chaque élément de votre robot. Suivez [Construire votre robot](/docs/robot/build/).

**Si vous êtes pressé :** téléchargez le robot terminé et continuez avec les tutoriels. Vous pourrez toujours revenir le construire plus tard.

<a href="/downloads/starter-robot.json" download>Télécharger starter-robot.json</a>

## Le charger dans Erebus {#load-it-in-erebus}
1. Ouvrez un monde, par exemple `game/worlds/world1.wbt`.
2. Dans la fenêtre de contrôle, appuyez sur le **bouton LOAD de droite**, avec l’icône de robot, et choisissez votre fichier `.json`.
3. Vérifiez la console de Webots. Erebus liste chaque composant avec son coût, et termine par `Your custom robot has been successfully generated!`.

:::note
Erebus v26.1 affiche aussi `PROTO parameter 'camera_width' has no matching IS field` en rouge. Vous pouvez l’ignorer : votre caméra a bien la résolution que vous avez choisie.
:::

Le robot reste chargé jusqu’à ce que vous en chargiez un autre ou que vous réinitialisiez la partie. Ensuite, [lancez votre premier programme](/docs/getting-started/).

## Concevoir le vôtre {#designing-your-own}
Une fois les bases acquises, modifiez le robot de départ ou concevez-en un nouveau : plus de caméras avec une meilleure résolution, plus de capteurs de distance, des capteurs à d’autres endroits. La [Référence du Robot Customizer](/docs/robot/customizer/) liste tous les composants, leurs coûts et leurs limites.

Si vous changez le nom d’un composant, changez-le aussi dans votre programme.
