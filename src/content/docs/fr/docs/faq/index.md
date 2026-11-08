---
title: FAQ
description: Questions fréquentes sur Erebus et la compétition.
---

## À propos d’Erebus {#about-erebus}

### Ai-je besoin d’un vrai robot ? {#do-i-need-a-real-robot}
Non. Tout se passe dans le simulateur. Le robot est un e-puck virtuel que vous concevez.

### Quels langages de programmation puis-je utiliser ? {#which-programming-languages-can-i-use}
Python et C/C++ sont traités dans cette documentation. Erebus peut aussi charger des contrôleurs Java et MATLAB, mais cette documentation ne contient pas d’exemples dans ces langages.

### Ai-je besoin d’un ordinateur puissant ? {#do-i-need-a-powerful-computer}
Non, consultez la [configuration requise](/docs/installation/). Les ordinateurs plus lents peuvent avoir besoin de [réglages graphiques plus bas](/docs/troubleshooting/#the-simulation-runs-too-slowly).

### Puis-je utiliser une version plus récente de Webots ? {#can-i-use-a-newer-version-of-webots}
Non. Erebus v26 fonctionne avec Webots **R2023b**. Vous pouvez garder d’autres versions installées à côté.

### Puis-je utiliser des bibliothèques comme OpenCV ou NumPy ? {#can-i-use-libraries-like-opencv-or-numpy}
Oui. Le code externe est autorisé, à condition de citer ses auteurs et de respecter sa licence. Les équipes doivent donner la priorité à l’apprentissage, et doivent pouvoir expliquer comment leur solution fonctionne.

## Le jeu {#the-game}

### Dans quel ordre vaut-il mieux apprendre ? {#what-is-the-best-order-to-learn-things}
Suivez [le parcours d’apprentissage](/docs/#the-learning-path) : comprenez le jeu, obtenez votre robot, faites-le tourner, apprenez les bases, puis jouez.

### Dois-je créer un robot avant de programmer ? {#do-i-need-to-make-a-robot-before-programming}
Oui. Chaque programme s’exécute sur un robot que vous chargez : commencez donc par [Obtenir votre robot](/docs/robot/). Si vous êtes pressé, vous pouvez télécharger le robot de départ déjà terminé.

### Où le robot démarre-t-il ? {#where-does-the-robot-start}
Sur la case de départ, qui se trouve dans la zone 1. Il est toujours orienté vers une direction sans mur.

### Que se passe-t-il si le robot tombe dans un trou ? {#what-happens-if-the-robot-falls-into-a-hole}
Une absence de progression (Lack of Progress) se produit : le robot retourne au dernier point de contrôle (checkpoint) visité, et vous perdez 5 points.

### Le robot doit-il revenir au départ ? {#does-the-robot-have-to-return-to-the-start}
Non, mais revenir sur la case de départ et envoyer `E` donne un bonus de sortie (exit bonus) de 10 %, à condition que le robot ait identifié au moins un marqueur mural.

### Comment mon robot peut-il savoir combien de temps il reste ? {#how-can-my-robot-tell-how-much-time-is-left}
Avec le [message `G`](/docs/programming/communication/#game-information). Il y a deux chronomètres, et le temps de jeu s’écoule plus vite dans les marécages.

### Dois-je explorer la zone 4 ? {#do-i-have-to-explore-area-4}
Non. C’est facultatif, mais ses marqueurs rapportent le plus : les points les plus élevés, multipliés par 2.

### Dois-je cartographier la zone 4 ? {#do-i-have-to-map-area-4}
Non. Toutes ses cellules valent `*` : il suffit donc de les remplir.

### Mon robot peut-il connaître la carte à l’avance ? {#can-my-robot-know-the-map-beforehand}
Non. Il est interdit de cartographier à l’avance le terrain ou l’emplacement des marqueurs muraux.

## La compétition {#the-competition}

### Comment participer ? {#how-do-i-take-part}
Par votre compétition régionale RoboCupJunior. Votre représentant régional attribue les places pour la compétition internationale. Consultez le [site de la RoboCupJunior](https://junior.robocup.org/).

### Que dois-je préparer ? {#what-should-i-prepare}
Consultez [Se préparer à une compétition](/docs/competition/).

### Où puis-je poser des questions sur les règles ? {#where-can-i-ask-about-the-rules}
Sur le [Forum RoboCupJunior](https://junior.forum.robocup.org/). Les clarifications y sont aussi publiées, consultez-le donc régulièrement.
