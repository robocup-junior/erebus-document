---
title: Novedades de la v26
description: Los cambios de Erebus v26 y de las reglas de 2026 que afectan a tu robot.
---

Erebus v26 aplica las reglas de 2026. Si vienes de una versión anterior, estos son los cambios que afectan a tu robot.

| Tema | Hasta 2025 | Desde 2026 |
|---|---|---|
| Víctimas de letra (Letter victims) | Letras H, S, U | Símbolos Φ (herida), Ψ (estable), Ω (ilesa). Se siguen informando como `H`, `S`, `U`. |
| Señales de materiales peligrosos (Hazmat signs) | Cuatro etiquetas de materiales peligrosos | Sustituidas por [objetivos cognitivos](/docs/rules/#cognitive-targets) (Cognitive targets): anillos de colores concéntricos cuyos valores suman el tipo. Se siguen informando como `F`, `P`, `C`, `O`. |
| Marcas falsas | - | Novedad: [víctimas falsas](/docs/rules/#fake-victims) (Fake victims) con letras tridimensionales, y objetivos cognitivos cuya suma no está entre 0 y 3. No informes de ellas ni las pongas en el mapa. |
| Pantanos (Swamps) | El tiempo se consume 5 veces más rápido | La primera entrada en un pantano es x5, y cada nueva entrada en el mismo pantano suma 1, hasta x10. |
| Obstáculos en el mapa | No se mapean | Las baldosas con un obstáculo se mapean como `x`. |
| Bonificación por mapa (Map bonus) | Hasta x2 | El multiplicador es ahora exactitud × 1,2 + 1. |
| Ruido de los sensores | - | El GPS tiene ruido. Los organizadores no cambiarán los niveles de ruido para la competición. |
| Ejecución de las partidas | Se anuncia en cada evento | Configuración servidor-cliente: tu controlador se ejecuta en tu propio ordenador, conectado al servidor de la partida por Ethernet. Consulta [Remote Controller](/docs/competition/remote-controller/). |
| Documentos | TDP, póster, vídeo | Además, un vídeo corto que muestre cómo ejecutas tu controlador en la configuración servidor-cliente. |
| Partidas no jugadas | -50 puntos | 0 puntos. |

La versión de Webots no ha cambiado: Erebus v26 sigue funcionando con Webots **R2023b**.

Las dos versiones publicadas después de la v26.0.0 no cambian las reglas. La v26.0.1 añade mundos de ejemplo con víctimas falsas y un script que convierte en falsas las víctimas de un mundo existente, y la v26.1 corrige cómo se marcan los obstáculos en el área 4.

## Actualizar tu programa {#updating-your-program}

1. Actualiza tu detección de víctimas a los nuevos símbolos. Las letras que informas no cambian.
2. Sustituye la detección de materiales peligrosos por la [lectura de objetivos cognitivos](/docs/programming/wall-tokens/#reading-a-cognitive-target).
3. Asegúrate de que tu programa no informa de las falsas y las deja fuera del mapa.
4. Añade los obstáculos a tu mapa, como `x`.
5. Planifica tu ruta teniendo en cuenta los nuevos pantanos: cada vez que el robot entra en el mismo pantano, le cuesta más tiempo.
6. Practica la [configuración servidor-cliente](/docs/competition/remote-controller/).
