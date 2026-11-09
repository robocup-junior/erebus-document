---
title: Referencia de parámetros
description: Tamaños del campo, tiempos de partida, multiplicadores de puntuación, límites del robot y nombres de los dispositivos del robot inicial.
---

## Campo {#field}

| Parámetro | Valor |
|---|---|
| Baldosa | 12 cm × 12 cm |
| Cuarto de baldosa (áreas 2 y 3) | 6 cm × 6 cm |
| Pared | 1 cm de grosor, 6 cm de alto |
| Víctima smiley | 2 cm × 2 cm |
| Objetivo cognitivo | 5 cm de diámetro |

## Partida {#game}

| Parámetro | Valor |
|---|---|
| Tiempo de partida | 8 minutos de tiempo simulado |
| Tiempo real | 10 minutos |
| Falta de progreso (Lack of Progress) automática | Tras 20 segundos en un mismo lugar |
| Tiempo parado para informar de una marca | Al menos 1 segundo |
| Distancia para informar de una marca | Media baldosa (6 cm), tanto para el centro del robot como para la posición enviada |
| Batería | 100 % al inicio. Se descarga según la velocidad de las ruedas, alrededor del 1,25 % por segundo con dos ruedas a toda velocidad. |
| Batería en un pantano | Se descarga 5 veces más rápido |
| Reemplazo de la batería | Permanecer quieto 5 segundos sobre una baldosa de contacto |
| Multiplicadores de área | 1, 1,25, 1,5 y 2 para las áreas 1, 2, 3 y 4 |
| Bonificación de salida | +10 % |
| Multiplicador de la bonificación por mapa | exactitud × 1,2 + 1 |

## Robot {#robot}

| Parámetro | Valor |
|---|---|
| Presupuesto | 3000 |
| Número máximo de cámaras | 3 |
| Número máximo de sensores de distancia | 8 |
| Alcance del sensor de distancia | 0 a 0,8 m |
| Precisión del GPS | 0,0025 m |
| Velocidad máxima de las ruedas | 6,28 rad/s |
| Lidar | 512 puntos por capa, 4 capas, de 0,01 a 1 m |

`timeStep` fija el número de milisegundos entre actualizaciones de los sensores. `int(robot.getBasicTimeStep())` obtiene el paso de tiempo básico del mundo, que es de 16 ms en los mundos de Erebus v27.

## Nombres de los dispositivos del robot inicial {#device-names-of-the-starter-robot}

Estos son los nombres que debes pasar a `robot.getDevice()` con el [robot inicial](/docs/robot/). En tus propios robots, eliges los nombres en el [Robot Customizer](/docs/robot/customizer/#components). El emisor y el receptor están siempre disponibles.

| Dispositivo | Nombre |
|---|---|
| Motores de las ruedas | `left wheel motor`, `right wheel motor` |
| Encoders de las ruedas | `left wheel sensor`, `right wheel sensor` |
| Sensores de distancia | `leftDist`, `frontDist`, `rightDist` |
| Cámara | `camera` |
| Sensor de color | `color` |
| GPS | `gps` |
| Giroscopio | `gyro` |
| Acelerómetro | `accelerometer` |
| Lidar | `lidar` |
| Emisor | `emitter` |
| Receptor | `receiver` |
