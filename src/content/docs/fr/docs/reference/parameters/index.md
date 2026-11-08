---
title: Référence des paramètres
description: Dimensions du terrain, durées de jeu, multiplicateurs de score, limites du robot et noms des composants du robot de départ.
---

## Terrain {#field}

| Paramètre | Valeur |
|---|---|
| Case | 12 cm × 12 cm |
| Quart de case (zones 2 et 3) | 6 cm × 6 cm |
| Mur | 1 cm d’épaisseur, 6 cm de hauteur |
| Victime lettre | 2 cm × 2 cm |
| Cible cognitive | 5 cm de diamètre |

## Jeu {#game}

| Paramètre | Valeur |
|---|---|
| Temps de jeu | 8 minutes de temps simulé |
| Temps réel | 10 minutes |
| Absence de progression automatique | Après 20 secondes au même endroit |
| Temps d’arrêt pour signaler un marqueur mural | Au moins 1 seconde |
| Multiplicateur de temps dans un marécage | x5 à la première entrée, +1 à chaque nouvelle entrée dans le même marécage, jusqu’à x10 |
| Multiplicateurs de zone | 1, 1,25, 1,5 et 2 pour les zones 1, 2, 3 et 4 |
| Bonus de sortie | +10 % |
| Multiplicateur du bonus de cartographie | exactitude × 1,2 + 1 |

## Robot {#robot}

| Paramètre | Valeur |
|---|---|
| Budget | 3000 |
| Nombre maximal de caméras | 3 |
| Nombre maximal de capteurs de distance | 8 |
| Portée des capteurs de distance | 0 à 0,8 m |
| Précision du GPS | 0,0025 m |
| Vitesse maximale des roues | 6,28 rad/s |
| LIDAR | 512 points par couche, 4 couches, 0,01 à 1 m |

`timeStep` définit le nombre de millisecondes entre deux mises à jour des capteurs. `int(robot.getBasicTimeStep())` obtient le pas de temps de base du monde, qui est de 16 ms dans les mondes d’Erebus v26.1.

## Noms des composants du robot de départ {#device-names-of-the-starter-robot}

Voici les noms à passer à `robot.getDevice()` avec le [robot de départ](/docs/robot/). Pour vos propres robots, vous choisissez les noms dans le [Robot Customizer](/docs/robot/customizer/#components). L’émetteur et le récepteur sont toujours disponibles.

| Composant | Nom |
|---|---|
| Moteurs des roues | `left wheel motor`, `right wheel motor` |
| Encodeurs des roues | `left wheel sensor`, `right wheel sensor` |
| Capteurs de distance | `leftDist`, `frontDist`, `rightDist` |
| Caméra | `camera` |
| Capteur de couleur | `color` |
| GPS | `gps` |
| Gyroscope | `gyro` |
| Accéléromètre | `accelerometer` |
| LIDAR | `lidar` |
| Émetteur | `emitter` |
| Récepteur | `receiver` |
