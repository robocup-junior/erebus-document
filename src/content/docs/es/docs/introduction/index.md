---
title: ¿Qué es Erebus?
description: Erebus es la plataforma de simulación de rescate de RoboCupJunior, basada en Webots. Descubre cómo encajan sus partes.
---

Erebus es un entorno de competición de simulación de robots. Desarrollas un controlador para un robot que explora un laberinto de forma autónoma, encuentra e identifica marcas en las paredes (víctimas de letra y objetivos cognitivos), evita obstáculos y trampas, y construye un mapa del entorno.

Está basado en [Webots](https://cyberbotics.com/), una plataforma de simulación robótica diseñada para uso profesional y muy utilizada en la industria, la educación y la investigación. Cyberbotics mantiene Webots de forma continua desde 1998.

La plataforma está diseñada principalmente para la competición [RoboCupJunior Rescue Simulation](https://junior.robocup.org/rescue/). Está pensada para programadores de nivel intermedio a muy experimentado.

## Cómo encaja todo {#how-it-fits-together}

| Componente | Qué hace | Dónde conseguirlo |
|---|---|---|
| **Webots R2023b** | El simulador de robots en 3D | [Versión R2023b de Webots](https://github.com/cyberbotics/webots/releases/tag/R2023b) |
| **Erebus** | Los mundos y el gestor de la partida (Main Supervisor), que aplica las reglas y calcula la puntuación | [Versiones de Erebus](https://github.com/robocup-junior/erebus/releases) |
| **Tu controlador** | El programa de tu robot, en Python o C/C++ | ¡Lo escribes tú! |
| **Robot Customizer** | Herramienta web para diseñar un robot personalizado y exportarlo como archivo JSON | [robot.erebus.rcj.cloud](https://robot.erebus.rcj.cloud/) |
| **World Editor** | Herramienta web para dibujar mapas de práctica y exportarlos como mundos `.wbt` | [world.erebus.rcj.cloud](https://world.erebus.rcj.cloud/) |

## ¿Qué puedes hacer con él? {#what-can-you-do-with-it}

1. **Construye un robot.** Elige sus sensores y dónde van, sin salirte del presupuesto.
2. **Prográmalo.** Tu controlador lee los sensores y decide qué hacer, sin ayuda humana.
3. **Ejecútalo.** Pruébalo en los mundos incluidos o en los tuyos, y observa la puntuación.
4. **Compite.** Participa en competiciones de RoboCupJunior locales, regionales e internacionales.

Si ya conoces Erebus, consulta [Novedades de la v26](/docs/whats-new/).

## Referencias útiles {#useful-references}
Lista de enlaces útiles para aprender y trabajar con el simulador Erebus:
- [Guía del usuario de Webots](https://cyberbotics.com/doc/guide/index?version=R2023b)
- [Manual de referencia de Webots](https://cyberbotics.com/doc/reference/nodes-and-api-functions?version=R2023b)
- [Documentación de Python](https://www.python.org/doc/)
- [Documentación de C++](https://www.cplusplus.com/doc/tutorial/)
- [Tutoriales de OpenCV](https://docs.opencv.org/4.x/d9/df8/tutorial_root.html)
- [Sitio web de la comunidad RCJ Rescue](https://rescue.rcj.cloud/): eventos, documentos de equipos y rúbricas del TDP, el póster y el vídeo
- [Foro de RoboCupJunior](https://junior.forum.robocup.org/): aclaraciones de las reglas

## Siguiente paso {#next}
[Instala Erebus](/docs/installation/) y luego lee el [Resumen de las reglas](/docs/rules/) para entender el juego.
