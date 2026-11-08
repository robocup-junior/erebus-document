---
title: Windows
description: Cómo configurar el Remote Controller en Windows.
---

# Ejecutar el servidor de la partida y el programa controlador en el mismo ordenador
Primero, prueba a ejecutar el servidor de la partida y tu programa controlador en el mismo ordenador. No es la misma configuración que en una competición, pero resulta útil para depurar en local.

## Activar el modo remoto {#toggle-remote-mode}
Abre el mundo y pulsa "TOGGLE REMOTE" en la ventana de control. El botón se vuelve naranja para indicar que el modo remoto está activado.  
![El botón TOGGLE REMOTE](../../../../../docs/competition/remote-controller/windows/toggleRemote.png)

Si no se muestra la ventana de control, haz clic derecho en "DEF MAINSUPERVISOR Robot" en el Scene Tree y elige "Show Robot Window".  
![La opción Show Robot Window](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## Ejecutar tu programa {#execute-your-program}
Abre PowerShell. Normalmente lo encontrarás en la lista de aplicaciones.  
![PowerShell en la lista de aplicaciones](../../../../../docs/competition/remote-controller/windows/powerShell.png)

Ejecuta el siguiente comando en PowerShell, sustituyendo `<Your controller path>` por la ruta de tu programa controlador.

`webots-controller.exe <Your controller path>`

Si no se encuentra el comando, usa su ruta completa, que por defecto es `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe`.

Si no conoces la ruta de tu programa controlador, arrastra el archivo y suéltalo en la ventana de PowerShell: su ruta se escribe automáticamente.  
![Arrastrar un archivo a la ventana de PowerShell](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

Después, pulsa Intro para ejecutar el comando. El controlador se conecta a Webots y espera hasta que empieza la partida.

## Iniciar la partida {#start-the-game}
Pulsa el botón de inicio en la ventana de control para iniciar la simulación.  
![El botón de inicio de la ventana de control](../../../../../docs/competition/remote-controller/windows/run.png)

## Terminar la partida {#terminate-the-game}
Para detener la partida, pulsa Ctrl+C en PowerShell y así detendrás tu programa.

Cuando la simulación termina, el gestor de la partida de Erebus también se detiene. Para volver a ejecutar la partida, recarga el mundo.  
![El botón de recarga de Webots](../../../../../docs/competition/remote-controller/windows/reload.png)

# Ejecutar el servidor de la partida en otro ordenador
Esta es la configuración que se usa en las competiciones oficiales. El ordenador que ejecuta tu controlador (el cliente) y el que ejecuta la partida (el servidor) deben estar conectados a la misma red.

1. (Servidor) Inicia Webots en el servidor, abre el mundo y activa el modo remoto en la ventana de control.
2. (Servidor) Averigua la dirección IP del servidor. Consulta [Buscar la dirección IP en Windows](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9).
3. (Cliente) Ejecuta el siguiente comando en PowerShell, sustituyendo `<Your controller path>` por la ruta de tu programa controlador y `<Server IP address>` por la dirección IP que encontraste en el paso anterior.  
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. (Servidor) Inicia la partida pulsando el botón de inicio.

# Solución de problemas
Si el controlador no puede conectarse, comprueba que los dos ordenadores pueden comunicarse entre sí, que el cortafuegos del servidor permite el puerto TCP 1234, y que la lista de IP permitidas de la pestaña Network de las preferencias (Preferences) de Webots está vacía o incluye al cliente.

# Documentación oficial
Para más detalles sobre esta configuración, consulta la [guía de Webots](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b).
