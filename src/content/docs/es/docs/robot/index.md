---
title: Consigue tu robot
description: Cada programa funciona en un robot que diseñas tú. Descarga el robot inicial o constrúyelo tú mismo.
---

En Erebus, **tú diseñas tu robot**: eliges sus sensores y dónde van, sin salirte del presupuesto. Todo programa necesita uno, así que el primer paso es conseguir un robot y cargarlo en Erebus.

![Un robot e-puck real](../../../docs/robot/real_robot.thumbnail.jpg)

El robot está basado en el [e-puck](https://cyberbotics.com/doc/guide/epuck?version=R2025a), un pequeño robot educativo redondo con dos ruedas. Le añades sensores con el [Robot Customizer](https://robot.erebus.rcj.cloud/) y guardas el diseño como un archivo `.json` que Erebus carga.

## El robot inicial {#the-starter-robot}
Esta documentación usa un único robot en todas partes, el **robot inicial**, para que todos los ejemplos funcionen tal cual. Tiene todos los sensores que necesitan los tutoriales:

| Componente | Nombre en tu programa | Para qué sirve |
|---|---|---|
| Dos ruedas | `left wheel motor`, `right wheel motor` | Moverse |
| Encoders de las ruedas | `left wheel sensor`, `right wheel sensor` | Medir cuánto han girado las ruedas |
| Tres sensores de distancia | `leftDist`, `frontDist`, `rightDist` | Encontrar paredes a la izquierda, delante y a la derecha |
| Cámara, 64 × 40 píxeles | `camera` | Encontrar marcas en las paredes |
| Sensor de color | `color` | Ver el suelo: agujeros, pantanos, baldosas de contacto y pasos |
| GPS | `gps` | Conocer su posición, para informar de las marcas |
| Giroscopio | `gyro` | Medir cuánto ha girado |
| Acelerómetro | `accelerometer` | Medir la aceleración |
| Lidar | `lidar` | Medir distancias a su alrededor |
| Emisor y receptor | `emitter`, `receiver` | Hablar con la partida. Todos los robots los tienen. |

Cuesta 2400 del presupuesto de 3000.

![El robot terminado, con sus etiquetas y la vista de la cámara](../../../docs/robot/build/finished.png)

## Elige tu camino {#choose-your-path}

**Recomendado: constrúyelo tú mismo.** Se tarda unos 15 minutos y entenderás cada parte de tu robot. Sigue [Construye tu robot](/docs/robot/build/).

**Si tienes prisa:** descarga el robot terminado y continúa con los tutoriales. Siempre puedes volver y construirlo más tarde.

<a href="/downloads/starter-robot.json" download>Descargar starter-robot.json</a>

## Cárgalo en Erebus {#load-it-in-erebus}
1. Abre un mundo, como `game/worlds/world1.wbt`.
2. En la ventana de control, pulsa **Robot setup**, luego **Load file** en **Robot JSON**, y elige tu archivo `.json`.
3. Revisa la consola de Webots. Erebus enumera cada componente con su coste y termina con `Your custom robot has been successfully generated!` y el presupuesto que usaste.

El robot sigue cargado hasta que cargues otro. Con **Keep files after Reset**, que está activado por defecto, también sigue cargado cuando reinicias la partida. Después, [ejecuta tu primer programa](/docs/getting-started/).

## Diseñar el tuyo {#designing-your-own}
Cuando domines lo básico, modifica el robot inicial o diseña uno nuevo: más cámaras con más resolución, más sensores de distancia, sensores en otros lugares. La [Referencia del Robot Customizer](/docs/robot/customizer/) enumera todos los componentes, sus costes y sus límites.

Si cambias el nombre de un componente, cámbialo también en tu programa.
