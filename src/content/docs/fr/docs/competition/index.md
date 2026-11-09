---
title: Se préparer à une compétition
description: Une liste de vérification pour être prêt pour une compétition RoboCupJunior Rescue Simulation.
---

Cette page est un guide pour la compétition internationale selon les règles 2027. Les compétitions locales et régionales peuvent être différentes : renseignez-vous auprès de vos organisateurs. Les [règles](/docs/rules/) officielles s’appliquent toujours.

## Calendrier {#timeline}

| Quand | Quoi |
|---|---|
| Tout au long de l’année | Suivez la [page de l’événement](/docs/events/upcoming-events/) et le [forum](https://junior.forum.robocup.org/), où les clarifications sont publiées |
| Au moins 4 semaines avant | Les organisateurs donnent les instructions du formulaire web pour préparer les entretiens |
| 3 semaines avant le premier jour | Date limite d’envoi des documents |
| Jour d’installation | Arrivez tôt sur place pour l’inscription, les entretiens et les réunions d’équipes |
| Chaque manche | Les mondes sont dévoilés juste avant les parties. Les programmes ne peuvent plus être modifiés après la date limite de chaque manche. |
| Après les manches notées | Technical Challenge (défi technique) |

## Documents à soumettre {#documents-to-submit}
Les modèles et les grilles d’évaluation se trouvent sur le [site de la communauté RCJ Rescue](https://rescue.rcj.cloud/).

- [ ] **Technical Description Paper (TDP).** Suivez strictement le modèle : sinon, le document obtient 0 point.
- [ ] **Poster,** sous forme de fichier et en version imprimée sur place, au format A1 maximum.
- [ ] **Vidéo** présentant votre projet.
- [ ] **Vidéo serveur-client :** une courte vidéo montrant comment vous lancez votre contrôleur sur une carte d’exemple dans la configuration serveur-client.
- [ ] **Code source** et **formulaire web** pour les entretiens.

## Configuration de la compétition {#competition-setup}
Les parties se déroulent en configuration serveur-client : les organisateurs font tourner le serveur de jeu et fournissent une prise RJ-45, et votre programme s’exécute sur votre ordinateur. Consultez [Remote Controller](/docs/competition/remote-controller/).

Apportez :

- [ ] Un ordinateur avec votre programme et toutes ses bibliothèques installées, ainsi que Webots R2025a
- [ ] Un câble Ethernet, et un adaptateur si votre ordinateur en a besoin
- [ ] Le fichier `.json` de votre robot, si vous avez un robot personnalisé
- [ ] Le poster imprimé

## Réglages OpenGL {#opengl-settings}
Sauf annonce contraire des organisateurs, les réglages suivants sont utilisés. Ils influent sur ce que voient les caméras : faites vos tests avec eux. Vous les trouverez dans l’onglet OpenGL des préférences de Webots.

| Réglage | Valeur |
|---|---|
| Ambient Occlusion | Low |
| Texture Quality | Low |
| Max Texture Filtering | 4 |
| Shadows | Disabled |
| Anti-aliasing | Disabled |

## Tester votre robot {#testing-your-robot}
- [ ] Faire tourner sur chaque monde inclus, en particulier les quatre mondes `2027_`, qui comprennent des cases de contact et des leurres.
- [ ] Créez vos propres cartes avec le [World Editor](/docs/tools/world-editor/), avec les quatre zones.
- [ ] Vérifier le jeu entier : va-t-il jusqu’au bout, remplace-t-il sa batterie à temps, soumet-il la carte et revient-il au départ ?
- [ ] Testez ce qui se passe après une absence de progression (Lack of Progress).
- [ ] Testez sur l’ordinateur que vous apporterez, et avec les réglages OpenGL ci-dessus.

## Pendant la compétition {#during-the-competition}
- Seuls le capitaine et le vice-capitaine peuvent accéder à la zone de compétition, sauf indication contraire d’un arbitre.
- L’arbitre pilote la simulation. Vous ne pouvez plus toucher au matériel de jeu une fois la partie commencée.
- Les encadrants (mentors) ne peuvent pas aider pendant la compétition.
- Soyez prêts à expliquer votre travail : chaque membre de l’équipe doit avoir un rôle technique et savoir comment cela fonctionne.

## Score final {#final-score}
Aux compétitions internationales, le score final combine :

| Partie | Poids | Contenu |
|---|---|---|
| Score sur le terrain | 0,6 | Moyenne des scores normalisés sur le terrain. La ou les plus mauvaises manches sont écartées. |
| Grilles d’évaluation | 0,2 | TDP (0,6), Vidéo (0,2), Poster (0,2) |
| Technical Challenge | 0,2 | Mini-tâches annoncées pendant la compétition, à résoudre en reprogrammant votre robot en un temps limité |

Les égalités sont départagées par la moyenne des scores normalisés sur le terrain. Le SuperTeam Challenge est une épreuve séparée, avec son propre prix.
