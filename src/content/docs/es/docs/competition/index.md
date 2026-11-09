---
title: Prepararse para una competición
description: Una lista de comprobación para prepararte para una competición de RoboCupJunior Rescue Simulation.
---

Esta página es una guía para la competición internacional con las reglas de 2027. Las competiciones locales y regionales pueden ser diferentes, así que consúltalo con tu organizador. Las [reglas](/docs/rules/) oficiales se aplican siempre.

## Calendario {#timeline}

| Cuándo | Qué |
|---|---|
| Durante todo el año | Sigue la [página del evento](/docs/events/upcoming-events/) y el [foro](https://junior.forum.robocup.org/), donde se publican las aclaraciones |
| Al menos 4 semanas antes | Los organizadores dan instrucciones sobre el formulario web para preparar las entrevistas |
| 3 semanas antes del primer día | Fecha límite de los documentos |
| Día de montaje | Llega pronto a la sede para el registro, las entrevistas y las reuniones de equipos |
| Cada ronda | Los mundos se revelan justo antes de las partidas. Los programas no pueden cambiar después de la fecha límite de cada ronda. |
| Después de las rondas puntuables | Technical Challenge (desafío técnico) |

## Documentos que hay que enviar {#documents-to-submit}
Las plantillas y las rúbricas están en el [sitio web de la comunidad RCJ Rescue](https://rescue.rcj.cloud/).

- [ ] **Technical Description Paper (TDP).** Sigue la plantilla al pie de la letra: si no, la puntuación del documento es 0.
- [ ] **Póster,** como archivo y como póster físico en la sede, no más grande que A1.
- [ ] **Vídeo** que muestre tu proyecto.
- [ ] **Vídeo servidor-cliente:** un vídeo corto que muestre cómo ejecutas tu controlador en un mapa de ejemplo con la configuración servidor-cliente.
- [ ] **Código fuente** y el **formulario web** para las entrevistas.

## Configuración de la competición {#competition-setup}
Las partidas se juegan con una configuración servidor-cliente: los organizadores ejecutan el servidor de la partida y ofrecen una toma RJ-45, y tu programa se ejecuta en tu ordenador. Consulta [Remote Controller](/docs/competition/remote-controller/).

Trae:

- [ ] Un ordenador con tu programa y todas sus bibliotecas instaladas, y Webots R2025a
- [ ] Un cable Ethernet, y un adaptador si tu ordenador lo necesita
- [ ] El archivo `.json` de tu robot, si tienes un robot personalizado
- [ ] El póster físico

## Ajustes de OpenGL {#opengl-settings}
Salvo que los organizadores anuncien lo contrario, se usan los siguientes ajustes. Afectan a lo que ven las cámaras, así que haz pruebas con ellos. Los encontrarás en la pestaña OpenGL de las preferencias de Webots.

| Ajuste | Valor |
|---|---|
| Ambient Occlusion | Low |
| Texture Quality | Low |
| Max Texture Filtering | 4 |
| Shadows | Disabled |
| Anti-aliasing | Disabled |

## Probar tu robot {#testing-your-robot}
- [ ] Probar en todos los mundos incluidos, sobre todo en los cuatro mundos `2027_`, que incluyen baldosas de contacto y marcas falsas.
- [ ] Crea tus propios mapas con el [World Editor](/docs/tools/world-editor/), con las cuatro áreas.
- [ ] Comprobar la partida completa: ¿llega hasta el final, reemplaza la batería a tiempo, envía el mapa y vuelve al inicio?
- [ ] Prueba qué pasa después de una falta de progreso (Lack of Progress).
- [ ] Haz pruebas en el ordenador que vas a llevar y con los ajustes de OpenGL de arriba.

## Durante la competición {#during-the-competition}
- Solo el capitán y el cocapitán pueden acceder a la zona de competición, salvo que un árbitro diga lo contrario.
- El árbitro maneja la simulación. No puedes tocar el equipo de la partida una vez que empieza.
- Los mentores no pueden ayudar durante la competición.
- Prepárate para explicar tu trabajo: cada miembro del equipo debe tener un papel técnico y saber cómo funciona.

## Puntuación final {#final-score}
La puntuación final en las competiciones internacionales combina:

| Parte | Peso | Contenido |
|---|---|---|
| Puntuación en el campo | 0,6 | Media de las puntuaciones normalizadas en el campo. Se descartan la peor ronda o las peores rondas. |
| Rúbricas | 0,2 | TDP (0,6), vídeo (0,2), póster (0,2) |
| Technical Challenge | 0,2 | Minitareas anunciadas en la competición, que se resuelven reprogramando tu robot en un tiempo limitado |

Los empates se resuelven según la media de las puntuaciones normalizadas en el campo. El SuperTeam Challenge es un evento aparte con su propio premio.
