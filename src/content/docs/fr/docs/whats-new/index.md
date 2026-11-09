---
title: Nouveautés de la v27
description: Les changements d’Erebus v27 et des règles 2027 qui concernent votre robot.
---

Erebus v27 applique les règles 2027. Si vous venez de la v26, voici les changements qui concernent votre robot.

| Sujet | Jusqu’en 2026 | À partir de 2027 |
|---|---|---|
| Batterie | - | Nouveau : le robot a une [batterie](/docs/rules/#the-battery) qui se vide selon la vitesse de ses moteurs. Si elle est vide, le jeu se termine. |
| Cases de contact | - | Nouveau : des [cases de contact](/docs/rules/#contact-tiles) cyan. Rester immobile 5 secondes dessus remplace la batterie. Elles sont cartographiées avec `k`. |
| Marécages | Le temps de jeu s’écoule plus vite : x5 à la première entrée, jusqu’à x10 | La batterie se vide plus vite. Le temps de jeu n’est pas affecté. |
| Victimes | Symboles Φ, Ψ, Ω | [Visages smiley](/docs/rules/#smiley-victims) : triste (blessée), neutre (stable) et content (indemne). Ils sont toujours signalés avec `H`, `S`, `U`. |
| Victimes leurres | Symboles en relief | Visages smiley en relief |
| Informations de jeu | La réponse à `G` fait 16 octets | La réponse à `G` fait 20 octets, et se termine par le niveau de la batterie. Voir [Informations de jeu](/docs/programming/communication/#game-information). |
| Distance de signalement | Erebus v26 acceptait les signalements jusqu’à 9 cm du marqueur | Une demi-case (6 cm), comme le disent les règles |
| Zones | Quatre zones, la zone 4 facultative | Jusqu’à quatre zones : la zone 1 est toujours présente, et les organisateurs peuvent omettre les zones 2 à 4 |
| Webots | R2023b | **R2025a** |
| Python | 3.9 ou plus récent | 3.10 ou plus récent |

[Votre première exécution](/docs/getting-started/) explique comment utiliser la fenêtre de contrôle d’Erebus v27.

## Mettre à jour votre programme {#updating-your-program}

1. Lisez la réponse à `G` sur 20 octets. Un programme qui n’accepte que 16 octets ne reçoit plus les informations de jeu.
1. Surveillez le niveau de la batterie, et prévoyez votre trajet pour que le robot atteigne une case de contact avant qu’elle soit vide. Voir [Batterie](/docs/programming/battery/).
1. Ajoutez les cases de contact à votre carte, avec `k`.
1. Adaptez votre détection des victimes aux visages smiley. Les lettres que vous signalez ne changent pas.
1. Signalez les marqueurs de plus près : le centre du robot, et la position envoyée, doivent être à moins d’une demi-case du marqueur.
1. Les marécages coûtent maintenant de la batterie au lieu du temps : tenez-en compte dans votre plan de batterie.
1. Installez Webots R2025a et Python 3.10 ou plus récent, et vérifiez que votre programme fonctionne toujours. Voir [Installation](/docs/installation/).
