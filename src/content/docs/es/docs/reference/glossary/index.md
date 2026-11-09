---
title: Glosario
description: Los términos que se usan en Erebus y en las reglas.
---

| Término | Significado |
|---|---|
| **Área (Area)** | Una de las cuatro partes del campo, cada una con su propio tipo de paredes. El World Editor las llama habitaciones (rooms). |
| **Multiplicador de área (Area multiplier, AM)** | 1, 1,25, 1,5 o 2, aplicado a los puntos de cada área |
| **Batería (Battery)** | Se descarga según la velocidad de los motores. La partida termina cuando se agota. |
| **Punto de control (Checkpoint)** | Una baldosa plateada. El robot vuelve al último que visitó tras una falta de progreso. |
| **Objetivo cognitivo (Cognitive target)** | Una marca en la pared de cinco colores concéntricos, cuya suma da un tipo de material peligroso (hazmat). Sustituyó a las señales de materiales peligrosos (hazmat signs) en 2026. |
| **Baldosa de contacto (Contact tile)** | Una baldosa cian donde se reemplaza la batería, si el robot se queda quieto 5 segundos sobre ella |
| **Ventana de control (Control window)** | La página web donde cargas los programas y ejecutas la partida. También se llama ventana del robot (robot window). |
| **Controlador (Controller)** | Tu programa |
| **Robot personalizado (Custom robot)** | Un robot diseñado con el Robot Customizer y cargado desde un archivo `.json` |
| **Bonificación de salida (Exit bonus, EB)** | +10 % por volver a la baldosa de salida y enviar `E` |
| **Falso (Fake)** | Una marca de la que no se debe informar: víctimas smiley tridimensionales y objetivos cognitivos con una suma no válida |
| **Baldosa flotante (Floating tile)** | Una baldosa a la que no se llega siguiendo las paredes unidas a la salida. Las marcas que hay en ellas valen más. |
| **Falta de progreso (Lack of progress, LoP)** | Cuando el robot se queda atascado o cae en un agujero. Vuelve al último punto de control y pierde 5 puntos. |
| **Baldosa lineal (Linear tile)** | Una baldosa a la que se llega siguiendo las paredes unidas a la salida |
| **Main Supervisor** | La parte de Erebus que gestiona la partida. También se llama supervisor o gestor de la partida (game manager). |
| **Bonificación por mapa (Mapping bonus, MB)** | Un multiplicador de puntuación de exactitud × 1,2 + 1 |
| **Matriz del mapa (Map matrix)** | La matriz que representa el mapa |
| **Paso (Passage)** | Una baldosa de color que conecta dos áreas |
| **Cuarto de baldosa (Quarter tile)** | Un cuarto de baldosa, de 6 cm de ancho, que se usa en las áreas 2 y 3 |
| **Configuración servidor-cliente (Server-client setup)** | La partida se ejecuta en un ordenador y tu programa en otro. Consulta Remote Controller. |
| **Víctima smiley (Smiley victim)** | Una marca en la pared con una cara triste, neutral o feliz. Sustituyó a las víctimas de letra en 2027. |
| **Pantano (Swamp)** | Una baldosa marrón donde la batería se descarga más rápido |
| **TDP** | Technical Description Paper (documento de descripción técnica) |
| **Baldosa (Tile)** | La unidad del campo, de 12 cm de ancho |
| **TI, TT, CN, TMI** | En la puntuación: identificación de la marca (token identification), tipo de marca (token type), superación de punto de control (checkpoint negotiation) y marca mal identificada (token misidentification) |
| **Marca en la pared (Wall token)** | Todo lo que hay que identificar en una pared: víctimas smiley y objetivos cognitivos |
| **Mundo (World)** | Un mapa, como archivo `.wbt` |
