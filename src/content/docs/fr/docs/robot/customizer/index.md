---
title: Référence du Robot Customizer
description: L’écran, les composants, les coûts et les limites du Robot Customizer.
---

Le [Robot Customizer](https://robot.erebus.rcj.cloud/) vous permet de choisir les capteurs de votre robot et leur emplacement. Il fonctionne dans votre navigateur, et exporte un fichier `.json` qu’Erebus charge.

Vous débutez ? Commencez par [Construire votre robot](/docs/robot/build/), qui construit le robot de départ étape par étape. Cette page décrit tout le reste.

![Le Robot Customizer](../../../../docs/robot/customizer/customizer.png)

L’aperçu 3D est à gauche, et les composants et le budget sont à droite.

## L’écran {#the-screen}

1. **Ajoutez des composants.** Activez l’interrupteur de chaque capteur ou caméra souhaité, et réglez le nombre de capteurs de distance avec `−` et `+`. Le coût de chaque composant est affiché à côté.
2. **Respectez le budget.** En haut à droite s’affiche ce qu’il reste du budget de 3000, et sa répartition entre roues, capteurs de distance, capteurs et caméras. Si vous le dépassez, il vous indique combien retirer : le robot ne peut pas être exporté tant qu’il ne rentre pas dans le budget.
3. **Placez-les.** Cliquez sur un composant dans la liste ou dans la vue 3D pour ouvrir ses réglages. Faites glisser les flèches dans la vue 3D, avec **Move** (`W`) ou **Rotate** (`R`), ou saisissez les valeurs. Les positions sont en dixièmes de millimètre, même si les champs indiquent mm. La position Y va de -100 à 370. Les boutons de rotation orientent un capteur vers l’avant, l’arrière, la gauche, la droite, le haut ou le bas en un clic. La flèche verte indique l’avant du robot.
4. **Nommez-les.** Le nom est celui que votre programme utilise avec `getDevice()`, comme indiqué sous **In your controller**. Les roues donnent deux composants : `<name> motor` et `<name> sensor`. Wheel 1 est du côté droit du robot, et Wheel 2 du côté gauche.
5. **Réglez la résolution de la caméra.** Chaque caméra a une largeur et une hauteur, qui modifient son coût.
6. **Exportez-le.** Saisissez un nom de fichier en haut et appuyez sur **Export**. Conservez le fichier : **Import**, ou un glisser-déposer du fichier sur la page, le recharge pour continuer à travailler dessus.

![Les réglages d’une caméra](../../../../docs/robot/customizer/component.png)

### Vues utiles {#useful-views}
- **3D**, **Top**, **Front** et **Side** montrent le robot sous différents angles. Top est pratique pour placer les capteurs de façon symétrique.
- **Labels** affiche le nom de chaque composant.
- **Camera view** affiche une estimation de ce que voient les caméras dans Webots.
- Annuler, rétablir et réinitialiser se trouvent en haut.

## L’utiliser dans Erebus {#using-it-in-erebus}

Dans la [fenêtre de contrôle](/docs/getting-started/#robot-setup), appuyez sur **Robot setup**, puis sur **Load file** sous **Robot JSON**, et choisissez votre fichier `.json`. Voir [Le charger dans Erebus](/docs/robot/#load-it-in-erebus). Erebus vérifie le budget et génère le robot, et la console de Webots liste chaque composant avec son coût.

Chargez d’abord votre robot, puis votre programme.

## Composants {#components}

| Composant | Coût | Nom par défaut |
|---|---|---|
| Roue (2, obligatoires) | 300 chacune | `wheel1`, `wheel2` |
| Capteur de distance (jusqu’à 8) | 50 chacun | `distance sensor1`, `distance sensor2`… |
| Gyroscope | 100 | `gyro` |
| Centrale inertielle | 100 | `inertial_unit` |
| Accéléromètre | 100 | `accelerometer` |
| Capteur de couleur | 100 | `colour_sensor` |
| GPS | 250 | `gps` |
| LIDAR | 500 | `lidar` |
| Caméra (jusqu’à 3) | 500, plus le coût de la résolution | `camera1`, `camera2`, `camera3` |

Le coût de résolution d’une caméra s’ajoute pour sa largeur et pour sa hauteur : 32 ou 40 pixels coûtent 0, 64 pixels coûtent 100, 128 pixels coûtent 200 et 256 pixels coûtent 300. Par exemple, une caméra de 256 × 128 coûte 500 + 300 + 200 = 1000.

Les nouvelles caméras font 40 × 32 pixels. Le robot de départ utilise 64 × 40.

Les deux roues coûtent 600 à elles deux : il reste donc 2400 du budget pour tout le reste.

## Conseils de conception {#design-tips}

- **GPS :** il vous faut une position pour signaler les marqueurs, et c’est le moyen le plus simple de l’obtenir.
- **Caméras :** une résolution plus élevée permet de lire les marqueurs de plus loin, mais coûte plus cher et demande plus de temps de traitement.
- **LIDAR :** il voit tout autour du robot, ce qui aide beaucoup pour la cartographie. Placez-le sur le dessus, et mettez-le à plat avec une rotation X `90`, comme sur le [robot de départ](/docs/robot/build/), sinon le robot le masque.
- **Capteur de couleur :** placez-le devant les roues, pour que le robot voie un trou avant d’y tomber.

[Construire votre robot](/docs/robot/build/) montre un exemple complet.
