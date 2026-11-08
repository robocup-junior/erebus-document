---
title: Windows
description: Guía de configuración del Remote Controller para Windows.
---

# Ejecutar el servidor de la partida y el programa controlador en el mismo PC
Primero, vamos a ejecutar el servidor de la partida y el programa controlador en el mismo PC. No es lo mismo que la configuración de una competición real, pero te ayudará a depurar en local.

## Activar el modo remoto {#toggle-remote-mode}
Pulsa "TOGGLE REMOTE" en la Robot Window (ventana del robot) para activar la configuración del controlador remoto. El botón debería volverse naranja para indicar que está activado.  
![El botón TOGGLE REMOTE](../../../../../docs/competition/remote-controller/windows/toggleRemote.png)

Si no se muestra la Robot Window, haz clic derecho en "DEF MAINSUPERVISOR Robot" en el Scene Tree y pulsa "Show Robot Window".  
![La opción Show Robot Window](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## Ejecutar tu programa {#execute-your-program}
Abre PowerShell. Normalmente lo encontrarás en la lista de aplicaciones.  
![PowerShell en la lista de aplicaciones](../../../../../docs/competition/remote-controller/windows/powerShell.png)

Ejecuta el siguiente comando en PowerShell, sustituyendo `<Your controller path>` por la ruta de tu programa controlador.

`webots-controller.exe <Your controller path>`

Si no se encuentra el comando, usa la ruta completa, que por defecto es `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe`.

Si no conoces la ruta de tu programa controlador, puedes arrastrar y soltar ese archivo en la ventana de PowerShell y se rellenará automáticamente.  
![Arrastrar un archivo a la ventana de PowerShell](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

Después de escribir el comando, pulsa Intro para ejecutarlo.

## Iniciar la partida {#start-the-game}
Pulsa el botón de inicio en la Robot Window para iniciar la simulación.  
![El botón de inicio de la ventana de control](../../../../../docs/competition/remote-controller/windows/run.png)

## Terminar la partida {#terminate-the-game}
Para interrumpir la partida, interrumpe el programa que se está ejecutando en PowerShell pulsando Ctrl+C.

Cuando la simulación termina, el sistema de gestión de partidas de Erebus termina al mismo tiempo. Si quieres volver a jugar la partida, recarga el mundo.  
![El botón de recarga de Webots](../../../../../docs/competition/remote-controller/windows/reload.png)

# Ejecutar el servidor de la partida en otro PC
Esta es la configuración que se usa en las competiciones oficiales.
El PC que ejecuta tu controlador (cliente) y el servidor de la partida (servidor) deben estar conectados a la misma red.

1. (Servidor) Inicia Webots en el PC servidor, abre el mundo y activa el modo remoto desde la Robot Window.
2. (Servidor) Averigua la dirección IP de ese PC. Puedes consultar [este artículo como referencia](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9).
3. (Cliente) Ejecuta el siguiente comando en PowerShell, sustituyendo `<Your controller path>` por la ruta de tu programa controlador y `<Server IP address>` por la dirección IP que averiguamos en el paso anterior.   
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. (Servidor) Inicia la partida pulsando el botón de inicio.

# Solución de problemas
Si el controlador no puede conectarse, comprueba que ambos PC se ven entre sí, que el cortafuegos del servidor permite el puerto TCP 1234, y que la lista de IP permitidas de la pestaña Network de las preferencias (Preferences) de Webots está vacía o incluye al cliente.

# Documentación oficial
Si quieres conocer la configuración con más detalle, la encontrarás en la [guía oficial](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b).
