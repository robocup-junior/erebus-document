---
title: Referencia del Robot Customizer
description: La pantalla, los componentes, los costes y los límites del Robot Customizer.
---

El [Robot Customizer](https://robot.erebus.rcj.cloud/) te permite elegir los sensores de tu robot y dónde colocarlos. Funciona en tu navegador y exporta un archivo `.json` que Erebus carga.

¿Es la primera vez que lo usas? Empieza por [Construye tu robot](/docs/robot/build/), que construye el robot inicial paso a paso. Esta página describe todo lo demás.

![El Robot Customizer](../../../../docs/robot/customizer/customizer.png)

La vista previa en 3D está a la izquierda, y los componentes y el presupuesto, a la derecha.

## La pantalla {#the-screen}

1. **Añade componentes.** Activa el interruptor de cada sensor o cámara que quieras, y ajusta el número de sensores de distancia con `−` y `+`. El coste de cada componente aparece a su lado.
2. **No te salgas del presupuesto.** Arriba a la derecha se muestra cuánto queda del presupuesto de 3000 y cómo se reparte entre ruedas, sensores de distancia, sensores y cámaras. Si te pasas, te dice cuánto tienes que quitar: el robot no se puede exportar hasta que quepa.
3. **Colócalos.** Haz clic en un componente de la lista o de la vista 3D para abrir sus ajustes. Arrastra las flechas de la vista 3D, con **Move** (`W`) o **Rotate** (`R`), o escribe los valores. Las posiciones están en décimas de milímetro, aunque las casillas digan mm. La posición Y va de -100 a 370. Los botones de rotación orientan un sensor hacia delante, atrás, la izquierda, la derecha, arriba o abajo con un clic. La flecha verde marca la parte delantera del robot.
4. **Ponles nombre.** El nombre es lo que usa tu programa con `getDevice()`, como se muestra en **In your controller**. Las ruedas tienen dos dispositivos: `<name> motor` y `<name> sensor`. La rueda 1 (Wheel 1) está en el lado derecho del robot, y la rueda 2 (Wheel 2), en el izquierdo.
5. **Ajusta la resolución de la cámara.** Cada cámara tiene un ancho y un alto, que cambian su coste.
6. **Expórtalo.** Escribe un nombre de archivo arriba y pulsa **Export**. Guarda el archivo: **Import**, o soltar el archivo sobre la página, lo recupera para seguir trabajando en él.

![Los ajustes de una cámara](../../../../docs/robot/customizer/component.png)

### Vistas útiles {#useful-views}
- **3D**, **Top**, **Front** y **Side** muestran el robot desde distintos ángulos. La vista Top es práctica para colocar sensores de forma simétrica.
- **Labels** muestra el nombre de cada componente.
- **Camera view** muestra una estimación de lo que ven las cámaras en Webots.
- Deshacer, rehacer y restablecer están arriba.

## Usarlo en Erebus {#using-it-in-erebus}

En la [ventana de control](/docs/getting-started/#robot-setup), pulsa **Robot setup**, luego **Load file** en **Robot JSON**, y elige tu archivo `.json`. Consulta [Cárgalo en Erebus](/docs/robot/#load-it-in-erebus). Erebus comprueba el presupuesto y genera el robot, y la consola de Webots enumera cada componente con su coste.

Carga primero tu robot y después tu programa.

## Componentes {#components}

| Componente | Coste | Nombre por defecto |
|---|---|---|
| Rueda (2, obligatorias) | 300 cada una | `wheel1`, `wheel2` |
| Sensor de distancia (hasta 8) | 50 cada uno | `distance sensor1`, `distance sensor2`… |
| Giroscopio | 100 | `gyro` |
| Unidad inercial | 100 | `inertial_unit` |
| Acelerómetro | 100 | `accelerometer` |
| Sensor de color | 100 | `colour_sensor` |
| GPS | 250 | `gps` |
| Lidar | 500 | `lidar` |
| Cámara (hasta 3) | 500, más el coste de la resolución | `camera1`, `camera2`, `camera3` |

El coste de resolución de una cámara se suma por su ancho y por su alto: 32 o 40 píxeles cuestan 0, 64 píxeles cuestan 100, 128 píxeles cuestan 200 y 256 píxeles cuestan 300. Por ejemplo, una cámara de 256 × 128 cuesta 500 + 300 + 200 = 1000.

Las cámaras nuevas son de 40 × 32 píxeles. El robot inicial usa 64 × 40.

Las dos ruedas cuestan 600 en total, así que quedan 2400 del presupuesto para todo lo demás.

## Consejos de diseño {#design-tips}

- **GPS:** necesitas una posición para informar de las marcas, y esta es la forma sencilla de obtenerla.
- **Cámaras:** las resoluciones más altas leen las marcas desde más lejos, pero cuestan más y son más lentas de procesar.
- **Lidar:** ve alrededor de todo el robot, lo que ayuda mucho a mapear. Colócalo encima y déjalo plano con la rotación X `90`, como en el [robot inicial](/docs/robot/build/), o el robot lo tapará.
- **Sensor de color:** colócalo delante de las ruedas, para que el robot vea un agujero antes de caer en él.

[Construye tu robot](/docs/robot/build/) muestra un ejemplo completo.
