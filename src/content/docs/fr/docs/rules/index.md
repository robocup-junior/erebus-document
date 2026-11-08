---
title: Résumé des règles
description: "Un résumé des règles 2026 de la RoboCupJunior Rescue Simulation : le terrain, les marqueurs muraux, le score et la compétition."
---

:::note
Cette page est un résumé pour vous aider à démarrer. Les seules règles officielles sont les [RoboCupJunior Rescue Simulation Rules 2026](https://junior.robocup.org/wp-content/uploads/2026/02/RCJRescueSimulation2026-final.pdf) (dernière mise à jour le 11/02/2026). En cas de différence entre cette page et les règles officielles, ce sont les règles officielles qui s’appliquent.

Les corrections et clarifications sont publiées sur le [Forum officiel de la RoboCupJunior](https://junior.forum.robocup.org/). Il appartient à chaque équipe de les consulter.
:::

## Le jeu en une minute {#the-game-in-one-minute}
Votre robot est lâché seul dans un labyrinthe inconnu. En 8 minutes, sans aucune aide de votre part, il doit :

1. **Explorer** le labyrinthe sans rester bloqué ni tomber dans les trous.
2. **Trouver les marqueurs muraux** (wall tokens), victimes et panneaux de danger (hazard signs) sur les murs, et signaler ce qu’est chacun d’eux.
3. **Cartographier** le labyrinthe, et envoyer la carte à la fin.
4. **Revenir** à son point de départ.

Tout ce qui suit explique ces quatre tâches en détail. Inutile de tout retenir maintenant : revenez-y au fur et à mesure que vous programmez chaque partie.

## Mission et objectif {#mission-and-objective}
![Vue de dessus d’un terrain Erebus avec quatre zones](../../../docs/rules/rules_environment.png)

Le robot doit explorer en autonomie un environnement inconnu tout en évitant les ennuis. Il y a trois missions principales :

- Parcourir un labyrinthe complexe sans rester bloqué
- Cartographier l’environnement avec précision
- Trouver et identifier les marqueurs muraux : victimes lettres (letter victims) et cibles cognitives (cognitive targets)

## Le terrain {#the-field}
Le terrain peut être divisé en quatre zones (areas), et chaque passage entre deux zones fait la largeur d’une case standard. Les cases (tiles) sont un concept utilisé pour générer le terrain, pas des structures physiques.

- Une case mesure **12 cm × 12 cm**. Dans les zones 2 et 3, chaque case est subdivisée en quatre **quarts de case** (quarter tiles) de 6 cm × 6 cm.
- Les murs font **1 cm d’épaisseur et 6 cm de hauteur**.
- Les couloirs sont au moins aussi larges que le robot, et peuvent s’ouvrir sur des espaces plus larges.

![Exemples de dispositions des murs des zones 1, 2 et 3](../../../docs/rules/rules_tiles.png)

| Zone | Murs | Remarques |
|---|---|---|
| Zone 1 | Peuvent être placés sur les bords de chaque case | La case de départ se trouve dans cette zone |
| Zone 2 | Peuvent être placés sur les bords de chaque quart de case | |
| Zone 3 | Peuvent être placés sur les bords de chaque quart de case | Les angles à 90° peuvent être arrondis en quart de cercle |
| Zone 4 (facultative) | Pas de cases ; murs et obstacles placés librement | Peut contenir des objets comme des boîtes, et peut exiger des déplacements en diagonale |

### Passages entre les zones {#passages-between-areas}
Les passages sont des cases uniques avec des murs sur deux côtés, pour que leur entrée et leur sortie soient sans ambiguïté. La couleur de leur sol indique quelles zones ils relient :

![Tableau des couleurs des passages entre chaque paire de zones](../../../docs/rules/rules_passages.png)

Aucune victime lettre n’est placée dans les passages.

### Cases linéaires et flottantes {#linear-and-floating-tiles}
Les cases qui mènent à la case de départ en suivant toujours le mur le plus à gauche ou le plus à droite sont des **cases linéaires** (linear tiles). Toutes les autres sont des **cases flottantes** (floating tiles). Les marqueurs situés sur des cases flottantes rapportent plus de points. Les quarts de case ne sont pas pris en compte, et les trous noirs comptent ici comme des murs virtuels.

![Un terrain montrant les cases linéaires en gris et les cases flottantes en rose](../../../docs/rules/rules_linear_floating.png)

### Points de contrôle {#checkpoints}
Les cases argentées sont des points de contrôle (checkpoints), et elles peuvent être placées n’importe où sur le terrain. La zone 4 contient des points de contrôle juste après ses passages. Après une absence de progression, le robot repart du dernier point de contrôle visité.

## Marécages, obstacles et trous {#swamps-obstacles-and-holes}
![Un terrain avec un marécage, un trou et un obstacle](../../../docs/rules/rules_obstacles.png)

* Les **marécages** (swamps, cases marron) font s’écouler le temps de jeu plus vite tant que le robot s’y trouve. La première fois que le robot entre dans un marécage, le temps s’écoule 5 fois plus vite. Chaque nouvelle entrée dans le même marécage ajoute un de plus, jusqu’à la limite de x10.
* Les **obstacles** peuvent être fixés au sol, avoir n’importe quelle forme et couleur, et réduisent la largeur du couloir. Dans les zones 1 à 3, le centre d’un obstacle est toujours sur une case, jamais sur le bord entre deux cases, et il y a au plus un obstacle par case.
* Les **trous** ont des bords noirs. Si le robot tombe dans l’un d’eux, une absence de progression se produit.

Aucune case n’est à la fois plus d’un des éléments suivants : marécage, trou, point de contrôle, case de départ, case avec un obstacle, ou passage entre zones.

## Marqueurs muraux {#wall-tokens}
Il existe deux sortes de marqueurs muraux : les victimes lettres et les cibles cognitives. Les deux peuvent apparaître sur n’importe quel mur, y compris sur les surfaces courbes. Les victimes lettres peuvent aussi être tournées selon n’importe quel angle.

![Cibles cognitives et victimes lettres sur les murs d’un terrain](../../../docs/rules/rules_wall_tokens.png)

### Victimes lettres {#letter-victims}
Les victimes lettres (letter victims) sont des images de 2 cm × 2 cm. Le symbole représente l’état de santé de la victime, et la lettre entre parenthèses est le code que vous signalez et inscrivez sur la carte.

| État | Symbole | Code |
|---|---|---|
| Blessée (Harmed) | Φ | `H` |
| Stable (Stable) | Ψ | `S` |
| Indemne (Unharmed) | Ω | `U` |

![Les symboles phi, psi et oméga](../../../docs/rules/rules_victims.png)

### Fausses victimes {#fake-victims}
Certains marqueurs muraux affichent les mêmes symboles, mais avec des lettres **en trois dimensions**. Ce sont des fausses victimes (fake victims) : vous ne devez ni les signaler au superviseur, ni les inclure dans la carte. Les règles précisent que ce relief peut être détecté avec l’un des capteurs disponibles dans le Robot Customizer.

![Fausses victimes aux symboles en trois dimensions sur un mur](../../../docs/rules/rules_fake_victims.png)

### Cibles cognitives {#cognitive-targets}
Les cibles cognitives (cognitive targets) représentent des matières dangereuses (hazmats). Ce sont des cercles de 5 cm de diamètre composés de cinq parties concentriques, de diamètres 1, 2, 3, 4 et 5 cm. Chaque couleur a une valeur :

| Noir | Rouge | Jaune | Vert | Bleu |
|---|---|---|---|---|
| -2 | -1 | 0 | 1 | 2 |

Additionnez les valeurs des cinq parties pour obtenir le type. Si la somme ne figure pas ci-dessous, la cible est un leurre et ne doit être ni signalée ni cartographiée.

| Somme | Matière dangereuse | Code |
|---|---|---|
| 0 | Gaz inflammable (Flammable Gas) | `F` |
| 1 | Toxique (Poison) | `P` |
| 2 | Corrosif (Corrosive) | `C` |
| 3 | Peroxyde organique (Organic Peroxide) | `O` |

Les anneaux adjacents de même couleur ne sont **pas** fusionnés : comptez toujours les cinq, même quand les couleurs se répètent.

![Deux exemples de cibles cognitives, l’une valide et l’autre fausse](../../../docs/rules/rules_cognitive_example.png)

La cible de gauche est jaune, bleu, rouge, noir, vert du centre vers l’extérieur : 0 + 2 - 1 - 2 + 1 = 0, c’est donc un gaz inflammable (`F`). La cible de droite est bleu, jaune, noir, noir, noir : 2 + 0 - 2 - 2 - 2 = -4, c’est donc un leurre.

Le [tutoriel Marqueurs muraux](/docs/programming/wall-tokens/) montre comment lire une cible avec une caméra.

## Le robot {#the-robot}
- Les équipes utilisent le modèle de robot fourni par les organisateurs, et peuvent le personnaliser avec le [Robot Customizer](https://robot.erebus.rcj.cloud/) dans la limite d’un budget de **3000**. Consultez [Le robot](/docs/robot/).
- Le robot peut utiliser un GPS, un capteur de couleur, des capteurs de distance, des caméras RVB (RGB), un LIDAR, un gyroscope et un accéléromètre.
- Les capteurs simulés ont un bruit réaliste. Votre programme doit y être robuste, et les organisateurs ne modifieront pas les niveaux de bruit pour la compétition.
- Les robots doivent être autonomes. Chaque équipe a un robot sur le terrain.
- La cartographie préalable est interdite : cela concerne à la fois le terrain et l’emplacement des marqueurs muraux, y compris les mouvements prédéfinis à partir de positions connues. Elle entraîne la disqualification immédiate pour la manche.

## Déroulement d’une partie {#playing-a-game}
- Une partie dure **8 minutes de temps simulé**. Un second chronomètre tourne en temps réel, avec une limite de **10 minutes**. La partie se termine dès que l’un des deux chronomètres expire.
- Une case compte comme visitée quand le centre du robot s’y trouve. Erebus en juge automatiquement.
- La partie se termine aussi quand le robot envoie la commande de sortie, ou quand le capitaine de l’équipe demande la fin de la partie (selon la façon dont la partie est exécutée).
- Les mondes de compétition sont dévoilés juste avant les parties, et les programmes ne peuvent plus être modifiés après la date limite de chaque manche.

### Absence de progression {#lack-of-progress}
Une absence de progression (Lack of Progress, LoP) se produit quand :

- Le robot est tombé dans un trou.
- Le robot reste au même endroit pendant 20 secondes ou plus (déclenchée automatiquement).
- L’arbitre estime que le robot n’est pas immobile, mais coincé dans une séquence de mouvements.
- Le robot la déclenche de lui-même.
- Dans d’autres cas, le capitaine de l’équipe peut la demander, et l’arbitre prend la décision finale. Cela peut ne pas s’appliquer, selon la façon dont la partie est exécutée.

Le robot est alors replacé sur le dernier point de contrôle visité, ou sur la case de départ s’il n’en a jamais atteint. Son orientation ne peut pas être choisie. Erebus envoie aussi la lettre `L` au robot, pour que votre programme puisse [y réagir](/docs/programming/communication/#lack-of-progress).

## Score {#scoring}
Le calcul du score est automatisé par Erebus. Les récompenses ne se cumulent pas : par exemple, chaque point de contrôle ne rapporte des points que la première fois.

Pour identifier un marqueur mural, le robot doit s’arrêter **au moins 1 seconde**, puis [envoyer le type et la position](/docs/programming/communication/#scoring-wall-tokens) au gestionnaire de jeu. Le centre du robot doit être à au plus une demi-case du marqueur.

| Élément | Points |
|---|---|
| Identification d’un marqueur mural (TI) sur une case linéaire des zones 1 à 3 | Victime lettre : 5, cible cognitive : 10 |
| Identification d’un marqueur mural (TI) sur une case flottante des zones 1 à 3, et tous les marqueurs de la zone 4 | Victime lettre : 15, cible cognitive : 30 |
| Type correct (TT), en plus de TI | Victime lettre : 10, cible cognitive : 20 |
| Point de contrôle visité (CN) | 10 |
| Erreur d’identification d’un marqueur mural (TMI) | -5 |
| Absence de progression (LoP) | -5 |

Le score total ne peut pas descendre en dessous de zéro. Une erreur d’identification consiste à signaler une position à plus d’une demi-case du marqueur, à signaler un marqueur là où il n’y en a pas, ou à signaler une victime comme un danger et inversement. Signaler un leurre entre dans la deuxième catégorie.

**Multiplicateurs de zone (Area multipliers, AM)** : TI, TT et CN sont multipliés par 1, 1,25, 1,5 et 2 respectivement dans les zones 1, 2, 3 et 4. TMI et LoP ne sont pas multipliés.

**Bonus de sortie (Exit bonus, EB)** : si le robot a identifié au moins un marqueur mural, revient sur la case de départ et envoie la commande de sortie, le score augmente de 10 %.

**Bonus de carte (Mapping bonus, MB)** : le robot peut soumettre une carte du labyrinthe. Le multiplicateur vaut exactitude × 1,2 + 1 : une carte parfaite multiplie donc le score par 2,2. Consultez [Cartographie](/docs/rules/mapping/).

Le score sur le terrain d’une partie se calcule ainsi :

![Le score sur le terrain est égal à la somme sur les quatre zones de (TI plus TT plus CN) multipliée par AM, moins TMI et LoP, le tout multiplié par EB et MB](../../../docs/rules/rules_field_score.png)

Par exemple, une partie avec ces résultats obtient 2680,15 points :

![Exemple détaillé de calcul du score](../../../docs/rules/rules_scoring_example.png)

## La compétition {#the-competition}
La préparation, les documents à soumettre, la configuration de la compétition et le score final sont décrits dans [Se préparer à une compétition](/docs/competition/).

## Et ensuite {#next}
Maintenant que vous savez ce que votre robot doit faire, [obtenez votre robot](/docs/robot/).
