---
title: Solución de problemas
description: Soluciones a los problemas habituales al instalar y ejecutar Erebus.
---

Antes de nada, revisa la consola de Webots. La mayoría de los problemas muestran ahí un mensaje de error.

## Instalación {#installation}

### `No module named 'cv2'` {#no-module-named-cv2}
OpenCV no está instalado en el Python que usa Webots. Instala las [bibliotecas necesarias](/docs/installation/#python-libraries) en ese Python. Si tienes varias instalaciones, el ajuste **Python command** que se explica abajo te dice cuál usa Webots.

### `WARNING: Python was not found` {#warning-python-was-not-found}
Webots no sabe dónde está Python.

1. Encuéntralo. En macOS y Linux, ejecuta `which python3` en una terminal. En Windows, comprueba que al escribir `python` en un nuevo símbolo del sistema se abre Python. Si no, vuelve a instalar Python marcando la opción para añadirlo a tu PATH.
2. Abre las preferencias de Webots: **Webots > Preferences** en macOS, **Tools > Preferences** en Windows y Linux.

   ![El elemento Preferences del menú de Webots](../../../docs/troubleshooting/preferences_open.png)

3. Pon la ruta en el campo **Python command**. En Windows, normalmente basta con `python`.

   ![El campo Python command de las preferencias de Webots](../../../docs/troubleshooting/preferences.png)

### `ERROR: Skipped PROTO 'custom_robot'` {#error-skipped-proto-custom_robot}
Aparece la primera vez que abres un mundo, antes de que Erebus haya preparado el modelo del robot. Erebus lo prepara y vuelve a cargar el mundo por sí solo, así que puedes ignorarlo.

### No aparece el temporizador de la partida {#the-game-timer-does-not-appear}
El primer inicio puede tardar unos minutos mientras Erebus instala bibliotecas. Si nunca termina, busca errores en la consola. Si la instalación automática no funciona, instala tú las [bibliotecas necesarias](/docs/installation/#python-libraries).

## Ejecutar Erebus {#running-erebus}

### No aparece la ventana de control {#the-control-window-does-not-appear}
La ventana de control es una página web que abre Webots.

1. Si la cerraste, o tu navegador la bloqueó, vuelve a cargar el mundo con el botón de recarga de Webots. Erebus abre de nuevo la ventana de control.
2. Si no, asegúrate de que se muestra el Scene Tree, con **Tools > Scene Tree**.
3. Busca **DEF MAINSUPERVISOR Robot** en el Scene Tree, haz clic derecho y elige **Show Robot Window**.

La ventana de control tiene una dirección privada, que cambia cada vez que se carga el mundo. Si abres tú la ventana en `localhost:1234`, muestra **Read-only** y sus botones no funcionan.

### La ventana de control dice "Access log incomplete" {#the-control-window-says-access-log-incomplete}
Este aviso aparece cuando [Wireshark](/docs/installation/#optional-wireshark) no está instalado. Está pensado para los organizadores en las competiciones: pulsa **Acknowledge** y practica como siempre.

![La opción Show Robot Window en el Scene Tree](../../../docs/troubleshooting/showrobot.png)

### La pantalla de Webots está en blanco o en negro {#the-webots-screen-is-blank-or-black}
Copia la descarga y descomprímela en una carpeta aparte antes de abrir el mundo.

### La simulación va demasiado lenta {#the-simulation-runs-too-slowly}
Probablemente se deba al rendimiento de tu ordenador. Bajar la calidad de los gráficos puede ayudar:

1. Abre las preferencias de Webots.
2. Abre la pestaña **OpenGL**.
3. Cambia los ajustes.

![La pestaña OpenGL de las preferencias de Webots](../../../docs/troubleshooting/opengl.png)

Estos ajustes cambian lo que ven las cámaras, y la competición usa [sus propios ajustes](/docs/competition/#opengl-settings), así que prueba también tu programa con ellos.

## Tu robot {#your-robot}

### Mi programa dice que no se encontró un dispositivo {#my-program-says-a-device-was-not-found}
Consulta más abajo. Comprueba también que cargaste tu robot en **Robot JSON**, dentro de **Robot setup**, antes de empezar la partida.

## Tu programa {#your-program}

### `Device "..." was not found` {#device--was-not-found}
El nombre del dispositivo en tu programa no coincide con tu robot. Los nombres del robot inicial están en la [Referencia](/docs/reference/parameters/#device-names-of-the-starter-robot). En tu propio robot, son los nombres que pusiste en el [Robot Customizer](/docs/robot/customizer/). Comprueba que tu robot se ha cargado.

### No pasa nada cuando informo de una marca en la pared {#nothing-happens-when-i-report-a-wall-token}
Activa **Enable debugging** en **Advanced setup** de la ventana de control, y revisa la consola. Las causas más comunes son que el robot no llevaba al menos 1 segundo parado, que las coordenadas no se convirtieron a centímetros, y que el robot o la posición estaban a más de media baldosa (6 cm) de la marca. Consulta [Comunicación](/docs/programming/communication/#scoring-wall-tokens).

### Mis informes cuentan como identificaciones erróneas {#my-reports-are-misidentifications}
El robot debe estar como máximo a media baldosa de la marca y en el mismo lado de la pared, y cada marca solo se puede puntuar una vez. Informar de una marca falsa también cuenta como identificación errónea.

### La partida termina con "Battery depleted" {#the-game-ends-with-battery-depleted}
Se agotó la batería. Detente 5 segundos sobre una baldosa de contacto para reemplazarla antes de que ocurra. Consulta [Batería](/docs/programming/battery/).

### Mi programa ya no recibe la información de la partida {#my-program-no-longer-receives-the-game-information}
Desde Erebus v27, la respuesta a `G` tiene 20 bytes, con el nivel de batería al final. Actualiza la comprobación de la longitud en tu programa. Consulta [Información de la partida](/docs/programming/communication/#game-information).

### El mapa obtiene un 0 % o un error de puntuación {#the-map-gets-0-or-a-scoring-error}
Tu mapa debe contener la baldosa de salida (`5`), y solo se puede evaluar una vez. Consulta [Enviar el mapa](/docs/programming/map-bonus/).

### El controlador no puede conectarse en modo remoto {#the-controller-cannot-connect-in-remote-mode}
Consulta la guía del [Remote Controller](/docs/competition/remote-controller/) para tu sistema operativo.

## ¿Sigues atascado? {#still-stuck}
Pregunta en el [servidor de Discord](https://discord.com/invite/6FJxZxk) o [abre un issue](https://github.com/robocup-junior/erebus/issues). Incluye tu sistema operativo, tus versiones de Erebus y Webots, y el mensaje de la consola.
