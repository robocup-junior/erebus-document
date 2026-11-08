---
title: Referência de mensagens
description: Referência das mensagens trocadas com o Main Supervisor.
---

As mensagens são enviadas com o dispositivo `emitter` e recebidas com o dispositivo `receiver`. Veja o [tutorial de Comunicação](/docs/programming/communication/) para exemplos.

As strings de formato abaixo são as do módulo [struct](https://docs.python.org/3/library/struct.html) do Python.

## Enviadas pelo robô {#sent-by-the-robot}

| Mensagem | Formato | Tamanho | Finalidade |
|---|---|---|---|
| Informar um marcador de parede | `i i c`: x, z, tipo | 9 bytes | A posição é em centímetros, e o tipo é um destes: `H`, `S`, `U`, `F`, `P`, `C`, `O`. O robô precisa ter ficado parado por pelo menos 1 segundo. |
| Dados do mapa | `2i` seguido de texto UTF-8: linhas, colunas, células separadas por vírgulas | Qualquer outro tamanho | Guarda o mapa, sem avaliá-lo |
| `M` | `c` | 1 byte | Avalia o mapa guardado. Isso só pode ser feito uma vez. |
| `L` | `c` | 1 byte | Declara uma falta de progresso |
| `G` | `c` | 1 byte | Pede as informações da partida |
| `E` | `c` | 1 byte | Termina a partida. Dá o bônus de saída se o robô estiver no ladrilho inicial e tiver identificado um marcador. |

O Erebus diferencia essas mensagens pelo tamanho, então um informe precisa ter exatamente 9 bytes.

## Recebidas pelo robô {#received-by-the-robot}

| Mensagem | Formato | Tamanho | Finalidade |
|---|---|---|---|
| `L` | `c` | 1 byte | Aconteceu uma falta de progresso |
| `G` | `c f i i`: `G`, pontuação, tempo de partida restante, tempo real restante | 16 bytes | Resposta a `G`. Os tempos são em segundos. |

Observe que o pacote de `G` inclui preenchimento (padding), já que o formato `struct` acima alinha o float: a pontuação começa no byte 4, e os tempos nos bytes 8 e 12.

## Funções comuns do Webots {#common-webots-functions}

| Função | Descrição |
|---|---|
| `robot.getDevice(name)` | Obtém um dispositivo pelo nome. Em C++, use `robot->getMotor(name)`, `robot->getCamera(name)` e assim por diante. |
| `robot.step(timeStep)` | Avança a simulação. Retorna -1 quando a simulação termina. |
| `robot.getTime()` | Obtém o tempo da simulação, em segundos |
| `device.enable(timeStep)` | Ativa um sensor |
| `motor.setPosition(float("inf"))` | Deixa o motor girar indefinidamente |
| `motor.setVelocity(speed)` | Define a velocidade de um motor, em radianos por segundo |
