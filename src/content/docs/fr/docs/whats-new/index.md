---
title: Nouveautés de la v26
description: Les changements d’Erebus v26 et des règles 2026 qui concernent votre robot.
---

Erebus v26 met en œuvre les règles 2026. Si vous venez d’une version précédente, voici les changements qui concernent votre robot.

| Sujet | Jusqu’en 2025 | À partir de 2026 |
|---|---|---|
| Victimes lettres | Lettres H, S, U | Symboles Φ (blessée, harmed), Ψ (stable), Ω (indemne, unharmed). Elles sont toujours signalées par `H`, `S`, `U`. |
| Panneaux de matières dangereuses (hazmat signs) | Quatre étiquettes de matières dangereuses | Remplacés par les [cibles cognitives](/docs/rules/#cognitive-targets) (cognitive targets) : des anneaux colorés concentriques dont les valeurs s’additionnent pour donner le type. Elles sont toujours signalées par `F`, `P`, `C`, `O`. |
| Leurres | - | Nouveauté : des [fausses victimes](/docs/rules/#fake-victims) (fake victims) aux lettres en trois dimensions, et des cibles cognitives dont la somme n’est pas comprise entre 0 et 3. Ne les signalez pas et ne les mettez pas sur la carte. |
| Marécages | Temps consommé 5 fois plus vite | La première entrée dans un marécage vaut x5, et chaque nouvelle entrée dans le même marécage ajoute 1, jusqu’à x10. |
| Obstacles sur la carte | Non cartographiés | Les cases avec un obstacle sont cartographiées par `x`. |
| Bonus de cartographie | Jusqu’à x2 | Le multiplicateur vaut désormais exactitude × 1,2 + 1. |
| Bruit des capteurs | - | Le GPS a du bruit. Les organisateurs ne modifieront pas les niveaux de bruit pour la compétition. |
| Déroulement des parties | Annoncé pour chaque événement | Configuration serveur-client : votre contrôleur tourne sur votre propre ordinateur, relié au serveur de jeu par Ethernet. Consultez [Remote Controller](/docs/competition/remote-controller/). |
| Documents | TDP, poster, vidéo | En plus, une courte vidéo montrant comment vous lancez votre contrôleur dans la configuration serveur-client. |
| Parties manquées | -50 points | 0 point. |

La version de Webots n’a pas changé : Erebus v26 fonctionne toujours avec Webots **R2023b**.

Les deux versions publiées après la v26.0.0 ne modifient pas les règles. La v26.0.1 ajoute des mondes d’exemple avec des fausses victimes et un script qui transforme les victimes d’un monde existant en leurres, et la v26.1 corrige le marquage des obstacles dans la zone 4.

## Mettre à jour votre programme {#updating-your-program}

1. Adaptez votre détection des victimes aux nouveaux symboles. Les lettres que vous signalez ne changent pas.
2. Remplacez la détection des matières dangereuses par la [lecture des cibles cognitives](/docs/programming/wall-tokens/#reading-a-cognitive-target).
3. Assurez-vous que votre programme ne signale pas les leurres, et les laisse hors de la carte.
4. Ajoutez les obstacles à votre carte, sous la forme `x`.
5. Planifiez votre itinéraire en tenant compte des nouveaux marécages : chaque fois que le robot entre dans le même marécage, cela coûte plus de temps.
6. Entraînez-vous avec la [configuration serveur-client](/docs/competition/remote-controller/).
