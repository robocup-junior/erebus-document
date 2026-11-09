---
title: Novedades de la v27
description: Los cambios de Erebus v27 y de las reglas de 2027 que afectan a tu robot.
---

Erebus v27 aplica las reglas de 2027. Si vienes de la v26, estos son los cambios que afectan a tu robot.

| Tema | Hasta 2026 | Desde 2027 |
|---|---|---|
| Batería | - | Nuevo: el robot tiene una [batería](/docs/rules/#the-battery) que se descarga según la velocidad de sus motores. Si se agota, la partida termina. |
| Baldosas de contacto | - | Nuevo: [baldosas de contacto](/docs/rules/#contact-tiles) de color cian. Quedarse quieto 5 segundos sobre una reemplaza la batería. Se mapean como `k`. |
| Pantanos | El tiempo de partida corre más rápido: x5 en la primera entrada, hasta x10 | La batería se descarga más rápido. El tiempo de partida no se ve afectado. |
| Víctimas | Símbolos Φ, Ψ, Ω | [Caras smiley](/docs/rules/#smiley-victims): triste (herida), neutral (estable) y feliz (ilesa). Se siguen informando como `H`, `S`, `U`. |
| Víctimas falsas | Símbolos tridimensionales | Caras smiley tridimensionales |
| Información de la partida | La respuesta a `G` tiene 16 bytes | La respuesta a `G` tiene 20 bytes y termina con el nivel de la batería. Consulta [Información de la partida](/docs/programming/communication/#game-information). |
| Distancia para informar | Erebus v26 aceptaba informes hasta 9 cm de la marca | Media baldosa (6 cm), como dicen las reglas |
| Áreas | Cuatro áreas, el área 4 opcional | Hasta cuatro áreas: el área 1 siempre está, y los organizadores pueden omitir las áreas 2 a 4 |
| Webots | R2023b | **R2025a** |
| Python | 3.9 o posterior | 3.10 o posterior |

[Tu primera ejecución](/docs/getting-started/) muestra cómo usar la ventana de control de Erebus v27.

## Actualizar tu programa {#updating-your-program}

1. Lee la respuesta a `G` como 20 bytes. Un programa que solo acepta 16 bytes ya no recibe la información de la partida.
1. Vigila el nivel de la batería y planifica tu ruta para que el robot llegue a una baldosa de contacto antes de que se agote. Consulta [Batería](/docs/programming/battery/).
1. Añade las baldosas de contacto a tu mapa, como `k`.
1. Actualiza tu detección de víctimas a las caras smiley. Las letras que informas no cambian.
1. Informa de las marcas desde más cerca: el centro del robot, y la posición que envías, deben estar a menos de media baldosa de la marca.
1. Los pantanos ahora cuestan batería en lugar de tiempo, así que tenlos en cuenta en tu plan de batería.
1. Instala Webots R2025a y Python 3.10 o posterior, y comprueba que tu programa sigue funcionando. Consulta [Instalación](/docs/installation/).
