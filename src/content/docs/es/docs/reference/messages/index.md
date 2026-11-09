---
title: Referencia de mensajes
description: Referencia de los mensajes que se intercambian con el Main Supervisor.
---

Los mensajes se envían con el dispositivo `emitter` y se reciben con el dispositivo `receiver`. Consulta el [tutorial de comunicación](/docs/programming/communication/) para ver ejemplos.

Las cadenas de formato siguientes son las del módulo [struct](https://docs.python.org/3/library/struct.html) de Python.

## Enviados por el robot {#sent-by-the-robot}

| Mensaje | Formato | Longitud | Función |
|---|---|---|---|
| Informar de una marca en la pared | `i i c`: x, z, tipo | 9 bytes | La posición está en centímetros, y el tipo es uno de `H`, `S`, `U`, `F`, `P`, `C`, `O`. El robot debe haber estado parado al menos 1 segundo. |
| Datos del mapa | `2i` seguido de texto UTF-8: filas, columnas, celdas separadas por comas | Cualquier otra longitud | Guarda el mapa, sin evaluarlo |
| `M` | `c` | 1 byte | Evalúa el mapa guardado. Solo se puede hacer una vez. |
| `L` | `c` | 1 byte | Declara una falta de progreso |
| `G` | `c` | 1 byte | Pide la información de la partida |
| `E` | `c` | 1 byte | Termina la partida. Da la bonificación de salida si el robot está en la baldosa de salida y ha identificado una marca en la pared. |

Erebus distingue estos mensajes por su longitud, así que un informe debe tener exactamente 9 bytes.

## Recibidos por el robot {#received-by-the-robot}

| Mensaje | Formato | Longitud | Función |
|---|---|---|---|
| `L` | `c` | 1 byte | Se ha producido una falta de progreso |
| `G` | `c f i i f`: `G`, puntuación, tiempo de partida restante, tiempo real restante, nivel de batería | 20 bytes | Respuesta a `G`. Los tiempos están en segundos, y el nivel de batería es un porcentaje de 0 a 100. |

Ten en cuenta que el paquete de `G` incluye relleno, porque el formato `struct` de arriba alinea el número de coma flotante: la puntuación empieza en el byte 4, los tiempos en los bytes 8 y 12, y el nivel de batería en el byte 16.

## Funciones habituales de Webots {#common-webots-functions}

| Función | Descripción |
|---|---|
| `robot.getDevice(name)` | Obtiene un dispositivo por su nombre. En C++, usa `robot->getMotor(name)`, `robot->getCamera(name)`, etc. |
| `robot.step(timeStep)` | Hace avanzar la simulación. Devuelve -1 cuando la simulación termina. |
| `robot.getTime()` | Obtiene el tiempo de simulación, en segundos |
| `device.enable(timeStep)` | Activa un sensor |
| `motor.setPosition(float("inf"))` | Permite que el motor gire indefinidamente |
| `motor.setVelocity(speed)` | Ajusta la velocidad de un motor, en radianes por segundo |
