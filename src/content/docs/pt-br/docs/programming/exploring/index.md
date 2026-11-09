---
title: Explorar e mapear
description: Ideias para explorar o labirinto de forma sistemática e construir o mapa.
---

Um robô que vagueia ao acaso não vai pontuar muito. Esta página mostra como passar de vaguear para explorar de forma sistemática. São ideias para você desenvolver, não uma solução completa.

## Saiba onde você está {#know-where-you-are}
Os ladrilhos têm 12 cm de largura, então a posição do GPS indica o ladrilho. A posição de início é diferente em cada mundo, então meça tudo a partir dela:

```python
TILE = 0.12
startX, _, startZ = gps.getValues() # At the start of the game

def currentTile():
    x, _, z = gps.getValues()
    return round((x - startX) / TILE), round((z - startZ) / TILE)
```

:::note
Sem um GPS, você pode estimar a posição com os encoders das rodas e o giroscópio, mas os erros se acumulam.
:::

## Lembre-se do que você viu {#remember-what-you-have-seen}
Mantenha um dicionário de ladrilhos com o que você sabe sobre cada um: quais lados têm paredes, como é o piso e se você já o visitou.

```python
tiles = {}
tiles[(0, 0)] = {"walls": {"N": False, "E": True, "S": False, "W": True}, "floor": "start", "visited": True}
```

Os ladrilhos não contam toda a história nas áreas 2 e 3, onde as paredes podem ficar em quartos de ladrilho. Guardar o mapa na resolução de quartos de ladrilho, ou usar uma nuvem de pontos do lidar, vai preparar você para elas.

## Decida para onde ir {#decide-where-to-go}
Não se limite a seguir uma parede: assim você nunca chega aos [ladrilhos flutuantes](/docs/rules/#linear-and-floating-tiles) (floating tiles), cujos marcadores valem mais. Uma abordagem comum é:

1. A partir do ladrilho atual, liste os vizinhos sem parede entre vocês.
2. Vá para um que ainda não foi visitado, se houver.
3. Se não houver, encontre o ladrilho mais próximo com um vizinho não visitado usando uma busca em largura (breadth-first search) e vá até ele.
4. Quando não restar nenhum ladrilho assim, ou o tempo estiver acabando, volte ao início do mesmo jeito.

Trate os buracos como paredes. Os pântanos custam tempo, e mais a cada vez que você entra no mesmo, então visite-os só quando valer a pena.

## Lide com o inesperado {#handle-the-unexpected}
- **Falta de progresso:** o robô é levado ao último ponto de controle. [Fique atento à mensagem `L`](/docs/programming/communication/#lack-of-progress) e atualize a sua posição.
- **Tempo:** pergunte o tempo restante com [`G`](/docs/programming/communication/#game-information). Deixe tempo suficiente para enviar o mapa e voltar ao início.
- **Ruído:** os sensores têm ruído, então compare várias leituras antes de confiar em uma parede ou em um marcador.

## Dos ladrilhos à matriz do mapa {#from-tiles-to-the-map-matrix}
A [matriz do mapa](/docs/rules/mapping/) tem 4 células por ladrilho, mais uma. Para um ladrilho na linha `r` e na coluna `c` do seu mapa:

| Elemento | Posição na matriz (linha, coluna) |
|---|---|
| Marcas do piso, como `4` ou `5` | Linhas `4r + 1` e `4r + 3`, colunas `4c + 1` e `4c + 3` |
| Parede norte | Linha `4r`, colunas `4c` a `4c + 4` |
| Parede oeste | Coluna `4c`, linhas `4r` a `4r + 4` |

![As células da matriz do mapa para o ladrilho na linha r e na coluna c: a parede norte na linha 4r, a parede oeste na coluna 4c e as marcas do piso no centro dos quartos de ladrilho](../../../../docs/programming/exploring/tile-to-matrix.svg)

O seu mapa pode começar em qualquer lugar: o Erebus [alinha a matriz](/docs/rules/mapping/#how-correctness-is-calculated) usando o ladrilho inicial e testa as quatro rotações. As [Regras do mapa](/docs/rules/mapping/) explicam cada valor da matriz. Depois, [envie-o](/docs/programming/map-bonus/).

Teste com os mundos de exemplo, cujas respostas corretas estão nas [Regras do mapa](/docs/rules/mapping/#examples). O resultado aparece como `Map Correctness` no histórico da janela de controle.
