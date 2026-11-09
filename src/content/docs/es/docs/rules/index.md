---
title: Resumen de las reglas
description: "Un resumen de las reglas de RoboCupJunior Rescue Simulation 2027: el campo, las marcas en las paredes, la batería, la puntuación y la competición."
---

:::note
Esta página es un resumen para ayudarte a empezar. Las únicas reglas oficiales son las [RoboCupJunior Rescue Simulation Rules 2027](https://junior.robocup.org/wp-content/uploads/2026/09/RCJRescueSimulation2027-draft.pdf). Este resumen sigue la versión actualizada el 2026-10-24. Si esta página y las reglas oficiales difieren, se aplican las reglas oficiales.

Las correcciones y aclaraciones se publican en el [foro oficial de RoboCupJunior](https://junior.forum.robocup.org/). Es responsabilidad de cada equipo consultarlas.
:::

## El juego en un minuto {#the-game-in-one-minute}
Tu robot aparece solo en un laberinto desconocido. En 8 minutos, sin tu ayuda, debe:

1. **Explorar** el laberinto sin quedarse atascado ni caer en agujeros.
2. **Encontrar las marcas en las paredes** (wall tokens), es decir, las víctimas y los objetivos cognitivos de las paredes, e informar de qué es cada una.
3. **Mantener su batería cargada**, deteniéndose en una baldosa de contacto antes de que se agote.
4. **Mapear** el laberinto y enviar el mapa al final.
5. **Volver** al lugar donde empezó.

Todo lo que sigue explica estas cinco tareas en detalle. No necesitas recordarlo todo ahora: vuelve aquí cuando programes cada parte.

## Misión y objetivo {#mission-and-objective}
![Vista superior de un campo de Erebus con cuatro áreas](../../../docs/rules/rules_environment.png)

El robot debe explorar de forma autónoma un entorno desconocido sin meterse en problemas. Hay tres misiones principales:

- Recorrer un laberinto complejo sin quedarse atascado
- Mapear el entorno con precisión
- Encontrar e identificar las marcas en las paredes: víctimas smiley y objetivos cognitivos

## El campo {#the-field}
El campo tiene hasta cuatro áreas. El área 1 siempre forma parte del campo, y los organizadores pueden omitir las áreas 2 a 4. Cada paso entre áreas tiene el ancho de una baldosa estándar. Las baldosas son un concepto para generar el campo, no estructuras físicas.

- Una baldosa mide **12 cm × 12 cm**. En las áreas 2 y 3, cada baldosa se subdivide en cuatro **cuartos de baldosa** (quarter tiles) de 6 cm × 6 cm.
- Las paredes tienen **1 cm de grosor y 6 cm de alto**.
- Los pasillos son al menos tan anchos como el robot, y pueden abrirse a espacios más amplios.

![Ejemplos de la disposición de las paredes en las áreas 1, 2 y 3](../../../docs/rules/rules_tiles.png)

| Área | Paredes | Notas |
|---|---|---|
| Área 1 | Pueden colocarse en los bordes de cada baldosa | La baldosa de salida está en esta área |
| Área 2 | Pueden colocarse en los bordes de cada cuarto de baldosa | |
| Área 3 | Pueden colocarse en los bordes de cada cuarto de baldosa | Las esquinas de 90° pueden redondearse en un cuarto de círculo |
| Área 4 (opcional) | No se basa en baldosas; las paredes y los obstáculos se colocan libremente | Puede contener objetos como cajas, y puede requerir movimientos en diagonal |

### Pasos entre áreas {#passages-between-areas}
Los pasos (passages) son baldosas individuales con paredes en dos lados, para que tengan una entrada y una salida inequívocas. El color de su suelo te dice qué áreas conectan:

![Tabla de los colores de los pasos entre cada par de áreas](../../../docs/rules/rules_passages.png)

En las paredes de los pasos no se colocan marcas.

### Baldosas lineales y flotantes {#linear-and-floating-tiles}
Las baldosas que llevan a la baldosa de salida siguiendo siempre la pared de más a la izquierda o de más a la derecha son **baldosas lineales** (linear tiles). Todas las demás son **baldosas flotantes** (floating tiles). Las marcas en baldosas flotantes valen más puntos. Aquí no se tienen en cuenta los cuartos de baldosa, y los agujeros cuentan como paredes virtuales.

![Un campo con las baldosas lineales en gris y las flotantes en rosa](../../../docs/rules/rules_linear_floating.png)

### Puntos de control {#checkpoints}
Las baldosas plateadas son puntos de control (checkpoints), y pueden estar en cualquier lugar del campo. El área 4 tiene puntos de control justo después de sus pasos. Tras una falta de progreso, el robot vuelve a empezar desde el último punto de control que visitó.

## Pantanos, obstáculos y agujeros {#swamps-obstacles-and-holes}
![Un campo con un pantano, un agujero y un obstáculo](../../../docs/rules/rules_obstacles.png)

* Los **pantanos** (baldosas marrones) hacen que la batería se descargue más rápido mientras el robot está sobre ellos, porque los motores tienen que esforzarse más. El tiempo de partida no se ve afectado.
* Los **obstáculos** pueden estar fijados al suelo, pueden tener cualquier forma y color, y afectan al ancho del pasillo. En las áreas 1 a 3, el centro de un obstáculo está siempre sobre una baldosa, nunca en el borde entre baldosas, y hay como máximo un obstáculo por baldosa.
* Los **agujeros** son baldosas con una abertura en el suelo. Sus bordes son negros, a 1,5 cm de las baldosas vecinas. Si el robot cae en uno, se produce una falta de progreso.

Ninguna baldosa es a la vez más de una de estas cosas: pantano, agujero, punto de control, baldosa de contacto, baldosa de inicio, baldosa con obstáculo o paso entre áreas.

## Baldosas de contacto {#contact-tiles}
Las baldosas de contacto son baldosas de color **cian** donde se puede reemplazar la batería del robot durante la partida. El robot debe permanecer quieto sobre la baldosa mientras se reemplaza su batería. Consulta [La batería](#the-battery).

![Un campo con baldosas de contacto cian](../../../docs/rules/rules_contact_tiles.png)

## Marcas en las paredes {#wall-tokens}
Hay dos tipos de marcas en las paredes: víctimas smiley y objetivos cognitivos. Ambas pueden aparecer en cualquier pared, incluidas las superficies curvas, excepto en las paredes de los pasos entre áreas. Las víctimas smiley además pueden estar giradas cualquier ángulo, de 0 a 360 grados.

![Objetivos cognitivos y víctimas smiley en las paredes de un campo](../../../docs/rules/rules_wall_tokens.png)

### Víctimas smiley {#smiley-victims}
Las víctimas smiley son imágenes de 2 cm × 2 cm de un emoji de cara sonriente impreso en negro. La expresión de la cara representa el estado de salud de la víctima, y el código es la letra que informas y escribes en el mapa.

| Estado | Cara | Código |
|---|---|---|
| Herida | Triste | `H` |
| Estable | Neutral | `S` |
| Ilesa | Feliz | `U` |

![Una cara triste, una neutral y una feliz](../../../docs/rules/rules_victims.png)

### Víctimas falsas {#fake-victims}
Algunas marcas muestran las mismas caras, pero los emojis son **tridimensionales**. Son falsas: no debes informarlas al supervisor ni incluirlas en el mapa. Las reglas indican que esta profundidad se puede detectar con uno de los sensores disponibles en el Robot Customizer.

![Víctimas falsas con caras tridimensionales en una pared](../../../docs/rules/rules_fake_victims.png)

### Objetivos cognitivos {#cognitive-targets}
Los objetivos cognitivos (Cognitive targets) representan materiales peligrosos (hazmats). Son círculos de 5 cm de diámetro formados por cinco partes concéntricas, con diámetros de 1, 2, 3, 4 y 5 cm. Cada color tiene un valor:

| Negro | Rojo | Amarillo | Verde | Azul |
|---|---|---|---|---|
| -2 | -1 | 0 | 1 | 2 |

Suma los valores de las cinco partes para obtener el tipo. Si la suma no está en la lista de abajo, el objetivo es una marca falsa y no se debe informar ni poner en el mapa.

| Suma | Material peligroso | Código |
|---|---|---|
| 0 | Gas inflamable (Flammable Gas) | `F` |
| 1 | Veneno (Poison) | `P` |
| 2 | Corrosivo (Corrosive) | `C` |
| 3 | Peróxido orgánico (Organic Peroxide) | `O` |

Los anillos contiguos del mismo color **no** se fusionan: cuenta siempre las cinco partes, aunque se repitan colores.

![Dos objetivos cognitivos de ejemplo, uno válido y uno falso](../../../docs/rules/rules_cognitive_example.png)

El objetivo de la izquierda es amarillo, azul, rojo, negro y verde del centro hacia fuera: 0 + 2 - 1 - 2 + 1 = 0, así que es gas inflamable (`F`). El de la derecha es azul, amarillo, negro, negro y negro: 2 + 0 - 2 - 2 - 2 = -4, así que es falso.

El [tutorial de marcas en las paredes](/docs/programming/wall-tokens/) muestra cómo leer un objetivo con una cámara.

## El robot {#the-robot}
- Los equipos usan el modelo de robot que proporcionan los organizadores, y pueden personalizarlo con el [Robot Customizer](https://robot.erebus.rcj.cloud/) dentro de un presupuesto de **3000**. Consulta [El robot](/docs/robot/).
- El robot puede usar un GPS, un sensor de color, sensores de distancia, cámaras RGB, un LiDAR, un giroscopio y un acelerómetro.
- Los sensores simulados tienen un ruido realista. Tu programa debe tolerarlo, y los organizadores no cambiarán los niveles de ruido para la competición.

### La batería {#the-battery}
El robot tiene una batería que se descarga según la velocidad de sus motores. El nivel de la batería se muestra en la ventana de control, encima de los temporizadores. Las reglas no indican el ritmo exacto: se espera que los equipos descubran su comportamiento con pruebas.

- Para reemplazar la batería, el robot debe **permanecer quieto sobre una baldosa de contacto durante 5 segundos** de tiempo simulado. Entonces la batería vuelve a estar llena.
- En los pantanos, la batería se descarga más rápido.
- Si la batería se agota, la partida termina.

El tutorial [Batería](/docs/programming/battery/) muestra cómo tu programa puede leer el nivel de la batería y reemplazarla.
- Los robots deben ser autónomos. Cada equipo tiene un robot en el campo.
- Está prohibido mapear de antemano: esto incluye tanto el campo como la ubicación de las marcas en las paredes, así como los movimientos predefinidos a partir de posiciones conocidas. Supone la descalificación inmediata de la ronda.

## Jugar una partida {#playing-a-game}
- Una partida dura **8 minutos de tiempo simulado**. Un segundo temporizador corre en tiempo real con un límite de **10 minutos**. La partida termina cuando se acaba cualquiera de los dos.
- Una baldosa cuenta como visitada cuando el centro del robot está dentro de ella, según determine el supervisor.
- La partida también termina cuando se agota la batería, cuando el robot envía el comando de salida o cuando el capitán del equipo pide terminarla (según cómo se lleve a cabo la partida).
- Los mundos de competición se revelan justo antes de las partidas, y los programas no se pueden cambiar después del plazo oficial de cada ronda, anunciado por los organizadores.

### Falta de progreso {#lack-of-progress}
Se produce una falta de progreso (Lack of Progress, LoP) cuando:

- El robot ha caído en un agujero.
- El robot se queda en un mismo lugar durante 20 segundos o más (se declara automáticamente).
- El árbitro determina que el robot no está quieto, pero sí atascado en una secuencia de movimientos.
- El robot la declara de forma autónoma.
- En otros casos, el capitán del equipo puede pedirla, y el árbitro toma la decisión final. Puede que esto no se aplique, según cómo se ejecute la partida.

El robot se coloca entonces de nuevo en el último punto de control visitado, o en la baldosa de salida si nunca llegó a ninguno. No se puede elegir su orientación. Erebus también envía la letra `L` al robot, para que tu programa pueda [reaccionar](/docs/programming/communication/#lack-of-progress).

## Puntuación {#scoring}
Erebus calcula la puntuación automáticamente. Las recompensas no se duplican: por ejemplo, cada punto de control solo puntúa la primera vez.

Para identificar una marca en la pared, el robot debe detenerse **al menos 1 segundo** y después [enviar el tipo y la posición](/docs/programming/communication/#scoring-wall-tokens) al supervisor. El centro del robot debe estar como máximo a media baldosa de la marca.

| Elemento | Puntos |
|---|---|
| Identificación de una marca (TI) en una baldosa lineal en las áreas 1 a 3 | Víctima smiley: 5, objetivo cognitivo: 10 |
| Identificación de una marca (TI) en una baldosa flotante en las áreas 1 a 3, y todas las marcas del área 4 | Víctima smiley: 15, objetivo cognitivo: 30 |
| Tipo correcto (TT), además de TI | Víctima smiley: 10, objetivo cognitivo: 20 |
| Punto de control visitado (CN) | 10 |
| Marca mal identificada (TMI) | -5 |
| Falta de progreso (LoP) | -5 |

La puntuación total no puede bajar de cero. Una identificación errónea consiste en informar de una posición a más de media baldosa de la marca, informar de una marca donde no la hay, o informar de una víctima smiley como objetivo cognitivo o viceversa. Informar de una marca falsa entra en la segunda categoría.

**Multiplicadores de área (Area multipliers, AM)**: TI, TT y CN se multiplican por 1, 1,25, 1,5 y 2 en las áreas 1, 2, 3 y 4 respectivamente. TMI y LoP no se multiplican.

**Bonificación de salida (Exit bonus, EB)**: si el robot ha identificado al menos una marca en la pared, vuelve a la baldosa de salida y envía la orden de salida, la puntuación aumenta un 10 %.

**Bonificación por mapa (Mapping bonus, MB)**: el robot puede enviar un mapa del laberinto. El multiplicador es exactitud × 1,2 + 1, así que un mapa perfecto multiplica la puntuación por 2,2. Consulta [Reglas del mapa](/docs/rules/mapping/).

La puntuación en el campo de una partida se calcula así:

![La puntuación en el campo es la suma, en las cuatro áreas, de TI más TT más CN por AM, menos TMI y LoP, todo multiplicado por EB y MB](../../../docs/rules/rules_field_score.png)

Por ejemplo, una ejecución con estos resultados obtiene 2825,35 puntos:

![Ejemplo resuelto de un cálculo de puntuación](../../../docs/rules/rules_scoring_example.png)

## La competición {#the-competition}
Cómo prepararte, los documentos que debes enviar, la configuración de la competición y la puntuación final están en [Prepararse para una competición](/docs/competition/).

## Siguiente paso {#next}
Ahora que sabes lo que tiene que hacer tu robot, [consigue tu robot](/docs/robot/).
