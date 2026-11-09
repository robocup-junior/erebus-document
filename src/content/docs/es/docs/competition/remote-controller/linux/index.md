---
title: Linux (Ubuntu)
description: Cómo configurar el Remote Controller en Linux (Ubuntu 22.04 LTS).
---

# Ejecutar el servidor de la partida y el programa controlador en el mismo ordenador
Primero, prueba a ejecutar el servidor de la partida y tu programa controlador en el mismo ordenador. No es la misma configuración que en una competición, pero resulta útil para depurar en local.

## Activar el modo remoto {#toggle-remote-mode}
Abre el mundo, pulsa **Robot setup** en la ventana de control y activa **Remote mode**. Si tienes un robot personalizado, carga antes tu robot en **Robot JSON**.

![Remote mode, activado en Robot setup](../../../../../docs/competition/remote-controller/linux/toggle_remote.png)

Si no se muestra la ventana de control, haz clic derecho en "DEF MAINSUPERVISOR Robot" en el Scene Tree y elige "Show Robot Window".

## Ejecutar tu programa {#execute-your-program}
Abre una terminal y ejecuta los siguientes comandos, sustituyendo `<Your controller path>` por la ruta de tu programa controlador.

```bash
export WEBOTS_HOME=/usr/local/webots
"$WEBOTS_HOME/webots-controller" "<Your controller path>"
```

Esto supone que Webots se instaló con el paquete `.deb` en `/usr/local/webots`. Si lo instalaste en otro sitio, cambia `WEBOTS_HOME` en consecuencia.

El controlador se conecta a Webots y espera hasta que empieza la partida.

## Iniciar la partida {#start-the-game}
Pulsa **Run match** en la ventana de control. El robot aparece y tu programa empieza a ejecutarse.

## Terminar la partida {#terminate-the-game}
Para detener la partida, pulsa Ctrl+C en la terminal.

Cuando termine la partida, pulsa **Reset** para ejecutarla otra vez. Al reiniciar se desactiva Remote mode, a menos que **Keep on Reset** esté activado.

# Ejecutar el servidor de la partida en otro ordenador
Esta es la configuración que se usa en las competiciones oficiales. El ordenador que ejecuta tu controlador (el cliente) y el que ejecuta la partida (el servidor) deben estar conectados a la misma red.

1. (Servidor) Inicia Webots en el servidor, abre el mundo y activa **Remote mode** en **Robot setup** de la ventana de control.
1. (Servidor) Averigua la dirección IP del servidor, por ejemplo con el comando `ip addr`.
1. (Cliente) Ejecuta los siguientes comandos, sustituyendo `<Your controller path>` por la ruta de tu programa controlador y `<Server IP address>` por la dirección IP que encontraste en el paso anterior.

    ```bash
    export WEBOTS_HOME=/usr/local/webots
    "$WEBOTS_HOME/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. (Servidor) Inicia la partida pulsando **Run match**.

## Solución de problemas {#troubleshooting}
- **El controlador no puede conectarse:** comprueba que los dos ordenadores pueden comunicarse entre sí, por ejemplo con `ping`, que el cortafuegos del servidor permite el puerto TCP 1234, y que la lista de IP permitidas de la pestaña Network de las preferencias (Preferences) de Webots está vacía o incluye al cliente.
- **El controlador espera, pero el robot no se mueve:** comprueba que **Remote mode** está activado y pulsa **Run match**.
- **El controlador no encuentra una biblioteca de Python:** el programa se ejecuta con la instalación de Python del cliente, así que instala la biblioteca ahí.

# Documentación oficial
Para más detalles sobre esta configuración, consulta la [guía de Webots](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a).
