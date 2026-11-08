---
title: Qu’est-ce qu’Erebus ?
description: Erebus est la plateforme de simulation de sauvetage de la RoboCupJunior, basée sur Webots. Découvrez comment ses éléments s’articulent.
---

Erebus est un environnement de compétition de simulation robotique. Vous développez un contrôleur pour un robot qui explore un labyrinthe en toute autonomie, trouve et identifie les marqueurs muraux (victimes lettres et cibles cognitives), évite les obstacles et les pièges, et dresse une carte de l’environnement.

Il est basé sur [Webots](https://cyberbotics.com/), une plateforme de simulation robotique conçue pour un usage professionnel et largement utilisée dans l’industrie, l’enseignement et la recherche. Cyberbotics maintient Webots sans interruption depuis 1998.

La plateforme est avant tout conçue pour la compétition [RoboCupJunior Rescue Simulation](https://junior.robocup.org/rescue/). Elle s’adresse à des programmeurs de niveau intermédiaire à très expérimenté.

## Comment tout s’articule {#how-it-fits-together}

| Composant | Rôle | Où l’obtenir |
|---|---|---|
| **Webots R2023b** | Le simulateur de robots en 3D | [Version Webots R2023b](https://github.com/cyberbotics/webots/releases/tag/R2023b) |
| **Erebus** | Les mondes et le gestionnaire de jeu (Main Supervisor), qui applique les règles et calcule le score | [Versions d’Erebus](https://github.com/robocup-junior/erebus/releases) |
| **Votre contrôleur** | Le programme de votre robot, en Python ou en C/C++ | C’est vous qui l’écrivez ! |
| **Robot Customizer** | Outil web pour concevoir un robot personnalisé et l’exporter en fichier JSON | [robot.erebus.rcj.cloud](https://robot.erebus.rcj.cloud/) |
| **World Editor** | Outil web pour dessiner des cartes d’entraînement et les exporter en mondes `.wbt` | [world.erebus.rcj.cloud](https://world.erebus.rcj.cloud/) |

## Que pouvez-vous en faire ? {#what-can-you-do-with-it}

1. **Construire un robot.** Choisissez ses capteurs et leur emplacement, dans les limites d’un budget.
2. **Le programmer.** Votre contrôleur lit les capteurs et décide quoi faire, sans aucune aide humaine.
3. **Le faire tourner.** Testez-le sur les mondes fournis ou sur les vôtres, et suivez le score.
4. **Concourir.** Participez à des compétitions RoboCupJunior locales, régionales et internationales.

Si vous connaissez déjà Erebus, consultez [Nouveautés de la v26](/docs/whats-new/).

## Références utiles {#useful-references}
Liste de liens utiles pour apprendre et travailler avec le simulateur Erebus :
- [Guide de l’utilisateur Webots](https://cyberbotics.com/doc/guide/index?version=R2023b)
- [Manuel de référence Webots](https://cyberbotics.com/doc/reference/nodes-and-api-functions?version=R2023b)
- [Documentation Python](https://www.python.org/doc/)
- [Documentation C++](https://www.cplusplus.com/doc/tutorial/)
- [Tutoriels OpenCV](https://docs.opencv.org/4.x/d9/df8/tutorial_root.html)
- [Site de la communauté RCJ Rescue](https://rescue.rcj.cloud/) : événements, documents d’équipe, et grilles d’évaluation du TDP, du poster et de la vidéo
- [Forum RoboCupJunior](https://junior.forum.robocup.org/) : clarifications des règles

## Et ensuite {#next}
[Installez Erebus](/docs/installation/), puis lisez le [Résumé des règles](/docs/rules/) pour comprendre le jeu.
