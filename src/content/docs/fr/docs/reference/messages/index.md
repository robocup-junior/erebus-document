---
title: Référence des messages
description: Référence des messages échangés avec le Main Supervisor.
---

Les messages sont envoyés avec le composant `emitter` et reçus avec le composant `receiver`. Consultez le [tutoriel Communication](/docs/programming/communication/) pour des exemples.

Les chaînes de format ci-dessous sont celles du module Python [struct](https://docs.python.org/3/library/struct.html).

## Envoyés par le robot {#sent-by-the-robot}

| Message | Format | Longueur | Rôle |
|---|---|---|---|
| Signaler un marqueur mural | `i i c` : x, z, type | 9 octets | La position est en centimètres, et le type est l’un de `H`, `S`, `U`, `F`, `P`, `C`, `O`. Le robot doit être resté arrêté au moins 1 seconde. |
| Données de la carte | `2i` suivi d’un texte UTF-8 : lignes, colonnes, cellules séparées par des virgules | Toute autre longueur | Enregistre la carte, sans l’évaluer |
| `M` | `c` | 1 octet | Évalue la carte enregistrée. Possible une seule fois. |
| `L` | `c` | 1 octet | Déclenche une absence de progression |
| `G` | `c` | 1 octet | Demande les informations de jeu |
| `E` | `c` | 1 octet | Termine la partie. Donne le bonus de sortie si le robot est sur la case de départ et a identifié un marqueur mural. |

Erebus distingue ces messages par leur longueur : un signalement doit donc faire exactement 9 octets.

## Reçus par le robot {#received-by-the-robot}

| Message | Format | Longueur | Rôle |
|---|---|---|---|
| `L` | `c` | 1 octet | Une absence de progression s’est produite |
| `G` | `c f i i` : `G`, score, temps de jeu restant, temps réel restant | 16 octets | Réponse à `G`. Les temps sont en secondes. |

Notez que le paquet de `G` contient des octets de remplissage, car le format `struct` ci-dessus aligne le nombre flottant : le score commence à l’octet 4, et les temps aux octets 8 et 12.

## Fonctions Webots courantes {#common-webots-functions}

| Fonction | Description |
|---|---|
| `robot.getDevice(name)` | Obtient un composant par son nom. En C++, utilisez `robot->getMotor(name)`, `robot->getCamera(name)`, etc. |
| `robot.step(timeStep)` | Fait avancer la simulation. Renvoie -1 quand la simulation se termine. |
| `robot.getTime()` | Obtient le temps de simulation, en secondes |
| `device.enable(timeStep)` | Active un capteur |
| `motor.setPosition(float("inf"))` | Laisse le moteur tourner indéfiniment |
| `motor.setVelocity(speed)` | Règle la vitesse d’un moteur, en radians par seconde |
