---
title: Glossaire
description: Les termes utilisés dans Erebus et dans les règles.
---

| Terme | Signification |
|---|---|
| **Zone (Area)** | L’une des quatre parties du terrain, chacune avec son propre type de murs. Le World Editor les appelle des salles (rooms). |
| **Multiplicateur de zone (Area multiplier, AM)** | 1, 1,25, 1,5 ou 2, appliqué aux points de chaque zone |
| **Point de contrôle (Checkpoint)** | Une case argentée. Le robot y retourne, au dernier visité, après une absence de progression. |
| **Cible cognitive (Cognitive target)** | Un marqueur mural composé de cinq couleurs concentriques, dont la somme donne un type de matière dangereuse. A remplacé les panneaux de matières dangereuses en 2026. |
| **Fenêtre de contrôle (Control window)** | La page web où vous chargez les programmes et lancez la partie. Aussi appelée fenêtre robot (robot window). |
| **Contrôleur (Controller)** | Votre programme |
| **Robot personnalisé (Custom robot)** | Un robot conçu avec le Robot Customizer et chargé depuis un fichier `.json` |
| **Bonus de sortie (Exit bonus, EB)** | +10 % pour être revenu sur la case de départ et avoir envoyé `E` |
| **Leurre (Fake)** | Un marqueur qui ne doit pas être signalé : les victimes lettres en trois dimensions, et les cibles cognitives dont la somme n’est pas valide |
| **Case flottante (Floating tile)** | Une case que l’on n’atteint pas en suivant les murs reliés au départ. Les marqueurs qui s’y trouvent valent davantage. |
| **Absence de progression (Lack of progress, LoP)** | Quand le robot est bloqué ou tombe dans un trou. Il retourne au dernier point de contrôle et perd 5 points. |
| **Victime lettre (Letter victim)** | Un marqueur mural portant le symbole Φ, Ψ ou Ω |
| **Case linéaire (Linear tile)** | Une case que l’on atteint en suivant les murs reliés au départ |
| **Main Supervisor** | La partie d’Erebus qui gère la partie. Aussi appelée gestionnaire de jeu. |
| **Bonus de carte (Mapping bonus, MB)** | Un multiplicateur de score égal à exactitude × 1,2 + 1 |
| **Matrice de la carte (Map matrix)** | Le tableau qui représente la carte |
| **Passage** | Une case colorée qui relie deux zones |
| **Quart de case (Quarter tile)** | Un quart de case, de 6 cm de large, utilisé dans les zones 2 et 3 |
| **Configuration serveur-client (Server-client setup)** | Le jeu tourne sur un ordinateur et votre programme sur un autre. Voir Remote Controller. |
| **Marécage (Swamp)** | Une case marron qui fait s’écouler le temps de jeu plus vite |
| **TDP** | Technical Description Paper |
| **Case (Tile)** | L’unité du terrain, de 12 cm de large |
| **TI, TT, CN, TMI** | Dans le calcul du score : identification du marqueur (token identification), type du marqueur (token type), passage d’un point de contrôle (checkpoint negotiation) et erreur d’identification d’un marqueur (token misidentification) |
| **Marqueur mural (Wall token)** | Tout ce qu’il faut identifier sur un mur : victimes lettres et cibles cognitives |
| **Monde (World)** | Une carte, sous forme de fichier `.wbt` |
