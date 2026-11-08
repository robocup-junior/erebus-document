---
title: macOS
description: Guía de configuración del Remote Controller para macOS.
---

# Ejecutar el servidor de la partida y el programa controlador en el mismo ordenador
Primero, vamos a ejecutar el servidor de la partida y el programa controlador en el mismo ordenador. No es lo mismo que la configuración de una competición real, pero te ayudará a depurar en local.

## Activar el modo remoto {#toggle-remote-mode}
Abre el mundo y pulsa "TOGGLE REMOTE" en la ventana de control. El botón debería volverse naranja para indicar que está activado.

![El botón TOGGLE REMOTE, activado](../../../../../docs/competition/remote-controller/mac/toggle_remote.png)

Si no se muestra la ventana de control, haz clic derecho en "DEF MAINSUPERVISOR Robot" en el Scene Tree y pulsa "Show Robot Window".

## Ejecutar tu programa {#execute-your-program}
Abre una terminal y ejecuta los siguientes comandos, sustituyendo `<Your controller path>` por la ruta de tu programa controlador.

```bash
export WEBOTS_HOME=/Applications/Webots.app
"$WEBOTS_HOME/Contents/MacOS/webots-controller" "<Your controller path>"
```

Si Webots está instalado en otro lugar o con otro nombre, cambia `WEBOTS_HOME` en consecuencia, por ejemplo `"/Applications/Webots R2023b.app"`.

El controlador se conecta a Webots y espera hasta que empieza la partida.

## Iniciar la partida {#start-the-game}
Pulsa el botón de inicio en la ventana de control. El robot aparece y tu programa empieza a ejecutarse.

## Terminar la partida {#terminate-the-game}
Para interrumpir la partida, pulsa Ctrl+C en la terminal.

Cuando la simulación termina, el sistema de gestión de partidas de Erebus termina al mismo tiempo. Si quieres volver a jugar la partida, recarga el mundo.

# Ejecutar el servidor de la partida en otro ordenador
Esta es la configuración que se usa en las competiciones oficiales. El ordenador que ejecuta tu controlador (cliente) y el servidor de la partida (servidor) deben estar conectados a la misma red.

1. (Servidor) Inicia Webots en el servidor, abre el mundo y activa el modo remoto en la ventana de control.
1. (Servidor) Averigua la dirección IP del servidor. La encontrarás en System Settings --> Network (Ajustes del Sistema > Red).
1. (Cliente) Ejecuta los siguientes comandos, sustituyendo `<Your controller path>` por la ruta de tu programa controlador y `<Server IP address>` por la dirección IP que encontraste en el paso anterior.

    ```bash
    export WEBOTS_HOME=/Applications/Webots.app
    "$WEBOTS_HOME/Contents/MacOS/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. (Servidor) Inicia la partida pulsando el botón de inicio.

## Solución de problemas {#troubleshooting}
- **El controlador no puede conectarse:** comprueba que ambos ordenadores se ven entre sí, por ejemplo con `ping`, que el cortafuegos del servidor permite el puerto TCP 1234, y que la lista de IP permitidas de la pestaña Network de las preferencias (Preferences) de Webots está vacía o incluye al cliente.
- **Aparece `No robot name provided`:** este mensaje es normal mientras espera. Si sigue apareciendo, el modo remoto no está activado, así que comprueba el botón TOGGLE REMOTE.
- **El controlador no encuentra una biblioteca de Python:** el programa se ejecuta con el Python del cliente, así que instálala ahí.

# Documentación oficial
Si quieres conocer la configuración con más detalle, la encontrarás en la [guía oficial](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b).
