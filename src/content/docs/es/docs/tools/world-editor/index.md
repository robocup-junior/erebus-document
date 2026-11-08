---
title: World Editor
description: Cómo crear tus propios mundos con el World Editor de Erebus.
---

## Contexto {#background}

Cuando tu robot ya se desenvuelva bien en los mapas incluidos y en laberintos sencillos, puede que quieras algo más difícil, o probar situaciones concretas que los mapas incluidos no cubren.
Para eso existe el [World Editor de Erebus](https://world.erebus.rcj.cloud/), en línea. Dibujas un mapa en tu navegador y exporta un archivo de mundo `.wbt` que puedes ejecutar en Erebus.

![Un mapa terminado en el World Editor](../../../../docs/tools/world-editor/overview.png)

Si solo construyes mapas pequeños para hacer pruebas, probablemente no te importe mucho que el campo cumpla las reglas. Pero si piensas construir un campo de competición, lee las [reglas oficiales de Simulation](https://junior.robocup.org/wp-content/uploads/2026/02/RCJRescueSimulation2026-final.pdf). El editor comprueba tu mapa frente a las reglas mientras trabajas.

El editor tiene una guía integrada: pulsa **Guide** abajo a la derecha para una lección práctica que crea un mapa de ejemplo (unos 15 minutos), un recorrido por la pantalla o una lección sobre la habitación 4 (Room 4). El idioma del editor se puede cambiar justo al lado.

## Empezar un mapa {#starting-a-map}
Cuando abras el editor, elige **las reglas de qué año** quieres seguir y pulsa **New map**. **Elige las reglas de 2026 para Erebus v26.** Las reglas de 2027 son un borrador para la próxima versión de Erebus.

![La pantalla de inicio del World Editor](../../../../docs/tools/world-editor/start.png)

Tu trabajo se guarda en el navegador, pero se pierde en otro navegador o cuando se borran los datos de navegación. Conserva los mapas importantes guardándolos como JSON con el botón de guardar de la barra superior, y vuelve a abrirlos con el botón de abrir.

Un buen orden de trabajo es tamaño y contorno, habitaciones, pasos, paredes, suelos, obstáculos y víctimas, habitación 4 y, por último, las comprobaciones y la exportación. Las herramientas están a la izquierda, cada una con un atajo de teclado. Los ajustes de la herramienta seleccionada aparecen en el panel de al lado.

| Herramienta | Tecla | Uso |
|---|---|---|
| Select | `S` | Seleccionar, mover, copiar y pegar partes del mapa |
| Move | `H` | Mover la vista |
| Outline | `X` | Fijar el tamaño y la forma del mapa |
| Rooms | `M` | Pintar las habitaciones 1 a 4 (las áreas de las reglas) |
| Passages | `P` | Unir habitaciones con un paso |
| Line | `L` | Dibujar paredes |
| Curve | `A` | Dibujar paredes curvas en la habitación 3 |
| Eraser | `E` | Quitar paredes, suelos, obstáculos y víctimas |
| Floor | `F` | Poner puntos de control, agujeros, pantanos y la baldosa de salida |
| Obstacle | `O` | Colocar obstáculos |
| Victims | `V` | Colocar víctimas de letra, objetivos cognitivos y falsos |

La rueda del ratón hace zoom, arrastrar manteniendo pulsado Espacio mueve la vista, y deshacer es `⌘Z` o `Ctrl+Z`.

## Tamaño y contorno {#size-and-outline}
Con la herramienta **Outline**, fija el tamaño del mapa en baldosas. Las paredes exteriores se añaden automáticamente. **Outline (uneven)** te permite hacer clic en baldosas para quitarlas del mapa, y también puedes insertar y eliminar filas y columnas donde hagas clic.

![La herramienta Outline](../../../../docs/tools/world-editor/outline.png)

## Habitaciones y pasos {#rooms-and-passages}
Con la herramienta **Rooms**, pinta las baldosas de cada habitación. Las paredes se añaden automáticamente en los bordes entre habitaciones. Después, con la herramienta **Passages**, une las habitaciones: el color de cada paso se elige según las habitaciones que conecta.

![La herramienta Rooms](../../../../docs/tools/world-editor/rooms.png)

![La herramienta Passages](../../../../docs/tools/world-editor/passages.png)

## Paredes {#walls}
Usa la herramienta **Line** para dibujar paredes: en los bordes de las baldosas en la habitación 1, y en cuartos de baldosa en las habitaciones 2 y 3. Usa la herramienta **Curve** en la habitación 3, apuntando a un cuarto de baldosa para elegir la curva. Si vuelves a hacer clic en la misma, se elimina.

![La herramienta Line para las paredes](../../../../docs/tools/world-editor/walls.png)

## Suelos y obstáculos {#floors-and-obstacles}
Con la herramienta **Floor**, elige un tipo de suelo y haz clic en una baldosa para ponerlo. La baldosa de salida debe ser una baldosa de la habitación 1, y el mundo no se puede exportar sin ella. Una baldosa solo puede ser una de estas cosas: agujero, pantano, punto de control, obstáculo, salida o paso.

![La herramienta Floor](../../../../docs/tools/world-editor/floors.png)

Con la herramienta **Obstacle**, elige una forma y haz clic en una baldosa. En las habitaciones 1 a 3 hay un obstáculo por baldosa, con su centro en la baldosa. Haz clic en un obstáculo para cambiar su tamaño, altura, color y rotación con sus controles y el panel.

![La herramienta Obstacle](../../../../docs/tools/world-editor/obstacles.png)

## Víctimas y objetivos cognitivos {#victims-and-cognitive-targets}
Con la herramienta **Victims**, elige un tipo y haz clic cerca de una pared. Puedes colocar:

- Víctimas de letra reales: herida, estable e ilesa
- Víctimas de letra falsas con símbolos tridimensionales
- Objetivos cognitivos: elige el material peligroso (hazmat) y, si quieres, los colores de los anillos. Se muestra la suma, que decide el tipo
- Objetivos falsos, cuyos anillos suman algo distinto de 0 a 3

En la habitación 1 puede haber una víctima en cada lado de una baldosa. En las habitaciones 2 y 3, van en las caras de las paredes de 6 cm, y las curvas tienen dos sitios, dentro y fuera. En **Turn**, elige una rotación fija, o una aleatoria para cada marca nueva. Haz clic en una marca colocada para cambiarla o quitarla, o arrástrala a lo largo de su pared.

![La herramienta Victims](../../../../docs/tools/world-editor/victims.png)

## Habitación 4 {#room-4}
La habitación 4 no está basada en baldosas, así que se dibuja como una imagen. Con la herramienta **Rooms**, pinta la habitación 4 y pulsa **Draw room 4** (o haz doble clic en la habitación) para abrir el creador de la habitación 4.

![El creador de la habitación 4](../../../../docs/tools/world-editor/room4.png)

Lo que dibujes en negro se convierte en paredes. El creador tiene herramientas para dibujar a mano alzada y para dibujar líneas, curvas, arcos, rectángulos, elipses, polígonos y formas a partir de iconos, y herramientas para víctimas y obstáculos. En la habitación 4 se pueden colocar tantos obstáculos como quieras. Las franjas rojas muestran adónde no puede ir el robot, y debes dejarle un camino de aproximadamente una baldosa de ancho para que pueda pasar.

Cuando termines, pulsa **OK**: la imagen aparece como habitación 4 en el mapa y pasa al mundo exportado. Los botones de arriba a la derecha del creador guardan la imagen como PNG, para que puedas usar la misma habitación 4 en otro mapa, y abren imágenes PNG o JPEG.

## Comprobar tu mapa {#checking-your-map}
Cada cambio se comprueba frente a las reglas, en la tarjeta **Checks** de arriba a la derecha. Una ✕ roja es un problema que impide exportar el mundo, y un ! amarillo es un aviso que merece la pena revisar. Haz clic en un elemento para ir a él. **Fix** corrige un elemento, y **Fix all that can be fixed** los corrige todos.

![Un mapa nuevo en el World Editor, con la tarjeta Checks](../../../../docs/tools/world-editor/new_map.png)

El botón **Linear** de la barra superior colorea cada baldosa como lineal o flotante, lo que determina cuánto valen las marcas.

![Baldosas lineales y flotantes mostradas en el mapa](../../../../docs/tools/world-editor/linear.png)

El trofeo de la barra superior muestra la **puntuación máxima** del mapa, calculada con las reglas de puntuación, con la parte de cada habitación y la puntuación con las bonificaciones de salida y por mapa.

![La puntuación máxima del mapa](../../../../docs/tools/world-editor/max_score.png)

## Exportar y ejecutar tu mundo {#exporting-and-running-your-world}
Pon el nombre del mapa en la barra superior y pulsa el botón **.wbt** de arriba a la derecha. Después:

1. Copia el archivo `.wbt` en la carpeta `game/worlds` de Erebus. Tiene que estar en esa carpeta, porque el mundo usa archivos de Erebus.
1. Ábrelo en Webots, o elígelo con el botón **Worlds** de la [ventana de control](/docs/getting-started/).

![El mapa de ejemplo de la guía del editor, ejecutándose en Erebus v26.1.](../../../../docs/tools/world-editor/exported_world.png)

*El mapa de ejemplo de la guía del editor, ejecutándose en Erebus v26.1.*

Un archivo `.wbt` no se puede volver a convertir en un mapa editable, así que guarda también el JSON.
