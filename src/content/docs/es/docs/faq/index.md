---
title: Preguntas frecuentes
description: Preguntas frecuentes sobre Erebus y la competición.
---

## Sobre Erebus {#about-erebus}

### ¿Necesito un robot real? {#do-i-need-a-real-robot}
No. Todo ocurre en el simulador. El robot es un e-puck virtual que diseñas tú.

### ¿Qué lenguajes de programación puedo usar? {#which-programming-languages-can-i-use}
Esta documentación trata Python y C/C++. Erebus también puede cargar controladores en Java y MATLAB, pero esta documentación no tiene ejemplos para ellos.

### ¿Necesito un ordenador potente? {#do-i-need-a-powerful-computer}
No, consulta los [requisitos](/docs/installation/). Los ordenadores más lentos pueden necesitar [ajustes gráficos más bajos](/docs/troubleshooting/#the-simulation-runs-too-slowly).

### ¿Puedo usar una versión más reciente de Webots? {#can-i-use-a-newer-version-of-webots}
No. Erebus v26 funciona con Webots **R2023b**. Puedes tener otras versiones instaladas a la vez.

### ¿Puedo usar bibliotecas como OpenCV o NumPy? {#can-i-use-libraries-like-opencv-or-numpy}
Sí. Se permite código externo, siempre que reconozcas a sus autores y respetes su licencia. Los equipos deben dar prioridad al aprendizaje y tienen que poder explicar cómo funciona su solución.

## El juego {#the-game}

### ¿Cuál es el mejor orden para aprender? {#what-is-the-best-order-to-learn-things}
Sigue [el itinerario de aprendizaje](/docs/#the-learning-path): entiende el juego, consigue tu robot, ejecútalo, aprende los fundamentos y luego juega.

### ¿Tengo que hacer un robot antes de programar? {#do-i-need-to-make-a-robot-before-programming}
Sí. Cada programa funciona en un robot que cargas, así que empieza por [Consigue tu robot](/docs/robot/). Si tienes prisa, puedes descargar el robot inicial terminado.

### ¿Dónde empieza el robot? {#where-does-the-robot-start}
En la baldosa de salida, que está en el área 1. Siempre mira hacia una dirección sin pared.

### ¿Qué pasa si el robot cae en un agujero? {#what-happens-if-the-robot-falls-into-a-hole}
Se produce una falta de progreso (Lack of Progress, LoP): el robot vuelve al último punto de control (checkpoint) que visitó y pierdes 5 puntos.

### ¿Tiene que volver el robot a la salida? {#does-the-robot-have-to-return-to-the-start}
No, pero volver a la baldosa de salida y enviar `E` da una bonificación de salida (Exit bonus) del 10 %, siempre que haya identificado al menos una marca en la pared.

### ¿Cómo puede saber mi robot cuánto tiempo queda? {#how-can-my-robot-tell-how-much-time-is-left}
Con el [mensaje `G`](/docs/programming/communication/#game-information). Hay dos temporizadores, y el tiempo de partida corre más rápido en los pantanos.

### ¿Tengo que explorar el área 4? {#do-i-have-to-explore-area-4}
No. Es opcional, pero sus marcas son las que más valen: los puntos más altos, multiplicados por 2.

### ¿Tengo que mapear el área 4? {#do-i-have-to-map-area-4}
No. Todas sus celdas son `*`, así que solo tienes que rellenarlas.

### ¿Puede mi robot conocer el mapa de antemano? {#can-my-robot-know-the-map-beforehand}
No. Está prohibido mapear de antemano el campo o la ubicación de las marcas en las paredes.

## La competición {#the-competition}

### ¿Cómo participo? {#how-do-i-take-part}
A través de tu competición regional de RoboCupJunior. Tu representante regional asigna las plazas para la competición internacional. Consulta el [sitio web de RoboCupJunior](https://junior.robocup.org/).

### ¿Qué debo preparar? {#what-should-i-prepare}
Consulta [Prepararse para una competición](/docs/competition/).

### ¿Dónde puedo preguntar sobre las reglas? {#where-can-i-ask-about-the-rules}
En el [Foro de RoboCupJunior](https://junior.forum.robocup.org/). Ahí también se publican las aclaraciones, así que consúltalo con regularidad.
