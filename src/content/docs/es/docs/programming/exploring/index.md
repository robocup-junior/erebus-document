---
title: Explorar y mapear
description: Ideas para explorar el laberinto de forma sistemática y construir el mapa.
---

Un robot que deambula al azar no sumará muchos puntos. Esta página muestra cómo pasar de deambular a explorar de forma sistemática. Son ideas sobre las que construir, no una solución completa.

## Averigua dónde estás {#know-where-you-are}
Las baldosas miden 12 cm de ancho, así que la posición del GPS te da la baldosa. La posición de la salida es distinta en cada mundo, así que mídelo todo desde ahí:

```python
TILE = 0.12
startX, _, startZ = gps.getValues() # At the start of the game

def currentTile():
    x, _, z = gps.getValues()
    return round((x - startX) / TILE), round((z - startZ) / TILE)
```

:::note
Sin GPS puedes estimar la posición con los encoders de las ruedas y el giroscopio, pero los errores se acumulan.
:::

## Recuerda lo que has visto {#remember-what-you-have-seen}
Guarda un diccionario de baldosas, con lo que sabes de cada una: qué lados tienen paredes, cómo es el suelo y si la has visitado.

```python
tiles = {}
tiles[(0, 0)] = {"walls": {"N": False, "E": True, "S": False, "W": True}, "floor": "start", "visited": True}
```

Las baldosas no lo cuentan todo en las áreas 2 y 3, donde las paredes pueden estar en cuartos de baldosa. Guardar el mapa con la resolución de cuartos de baldosa, o usar una nube de puntos del lidar, te preparará para ellas.

## Decide adónde ir {#decide-where-to-go}
No te limites a seguir una pared: así nunca llegarás a las [baldosas flotantes](/docs/rules/#linear-and-floating-tiles), cuyas marcas valen más. Un enfoque habitual es:

1. Desde la baldosa actual, enumera las vecinas que no tienen una pared en medio.
2. Ve a una que no hayas visitado, si la hay.
3. Si no, encuentra la baldosa más cercana con una vecina sin visitar mediante una búsqueda en anchura y ve allí.
4. Cuando no quede ninguna baldosa así, o quede poco tiempo, vuelve a la salida de la misma forma.

Trata los agujeros como paredes. Los pantanos descargan la batería más rápido, así que entra en ellos solo cuando valga la pena. Recuerda dónde están las baldosas de contacto, para [reemplazar la batería](/docs/programming/battery/) por el camino.

## Gestiona lo inesperado {#handle-the-unexpected}
- **Falta de progreso (Lack of Progress):** el robot se traslada al último punto de control. [Escucha el mensaje `L`](/docs/programming/communication/#lack-of-progress) y actualiza tu posición.
- **Tiempo:** pide el tiempo restante con [`G`](/docs/programming/communication/#game-information). Deja suficiente para enviar el mapa y volver a la salida.
- **Ruido:** los sensores tienen ruido, así que compara varias lecturas antes de fiarte de una pared o de una marca.

## De las baldosas a la matriz del mapa {#from-tiles-to-the-map-matrix}
La [matriz del mapa](/docs/rules/mapping/) tiene 4 celdas por baldosa, más una. Para una baldosa en la fila `r` y la columna `c` de tu mapa:

| Elemento | Posición en la matriz (fila, columna) |
|---|---|
| Marcas del suelo, como `4` o `5` | Filas `4r + 1` y `4r + 3`, columnas `4c + 1` y `4c + 3` |
| Pared norte | Fila `4r`, columnas `4c` a `4c + 4` |
| Pared oeste | Columna `4c`, filas `4r` a `4r + 4` |

![Las celdas de la matriz del mapa para la baldosa de la fila r y la columna c: la pared norte en la fila 4r, la pared oeste en la columna 4c y las marcas del suelo en el centro de los cuartos de baldosa](../../../../docs/programming/exploring/tile-to-matrix.svg)

Tu mapa puede empezar en cualquier sitio: Erebus [alinea la matriz](/docs/rules/mapping/#how-correctness-is-calculated) usando la baldosa de salida y prueba las cuatro rotaciones. Las [Reglas del mapa](/docs/rules/mapping/) explican cada valor de la matriz. Después, [envíalo](/docs/programming/map-bonus/).

Pruébalo con los mundos de ejemplo, cuyas respuestas correctas están en [Reglas del mapa](/docs/rules/mapping/#examples). El resultado aparece como `Map Correctness` en los eventos de la partida de la ventana de control.
