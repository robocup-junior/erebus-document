---
title: Referência de parâmetros
description: Tamanhos do campo, tempos da partida, multiplicadores de pontuação, limites do robô e os nomes dos dispositivos do robô inicial.
---

## Campo {#field}

| Parâmetro | Valor |
|---|---|
| Ladrilho | 12 cm × 12 cm |
| Quarto de ladrilho (áreas 2 e 3) | 6 cm × 6 cm |
| Parede | 1 cm de espessura, 6 cm de altura |
| Vítima de letra | 2 cm × 2 cm |
| Alvo cognitivo | 5 cm de diâmetro |

## Partida {#game}

| Parâmetro | Valor |
|---|---|
| Tempo de partida | 8 minutos de tempo simulado |
| Tempo real | 10 minutos |
| Falta de progresso automática | Após 20 segundos em um mesmo lugar |
| Tempo parado para informar um marcador | Pelo menos 1 segundo |
| Multiplicador de tempo em um pântano | x5 na primeira entrada, +1 a cada nova entrada no mesmo pântano, até x10 |
| Multiplicadores de área | 1, 1,25, 1,5 e 2 para as áreas 1, 2, 3 e 4 |
| Bônus de saída | +10% |
| Multiplicador do bônus de mapa | acerto × 1,2 + 1 |

## Robô {#robot}

| Parâmetro | Valor |
|---|---|
| Orçamento | 3000 |
| Número máximo de câmeras | 3 |
| Número máximo de sensores de distância | 8 |
| Alcance do sensor de distância | 0 a 0,8 m |
| Precisão do GPS | 0,0025 m |
| Velocidade máxima da roda | 6,28 rad/s |
| Lidar | 512 pontos por camada, 4 camadas, de 0,01 a 1 m |

`timeStep` define o número de milissegundos entre as atualizações dos sensores. `int(robot.getBasicTimeStep())` obtém o passo de tempo básico do mundo, que é de 16 ms nos mundos do Erebus v26.1.

## Nomes dos dispositivos do robô inicial {#device-names-of-the-starter-robot}

Estes são os nomes que você passa para `robot.getDevice()` com o [robô inicial](/docs/robot/). Nos seus próprios robôs, você escolhe os nomes no [Robot Customizer](/docs/robot/customizer/#components). O emissor e o receptor estão sempre disponíveis.

| Dispositivo | Nome |
|---|---|
| Motores das rodas | `left wheel motor`, `right wheel motor` |
| Encoders das rodas | `left wheel sensor`, `right wheel sensor` |
| Sensores de distância | `leftDist`, `frontDist`, `rightDist` |
| Câmera | `camera` |
| Sensor de cor | `color` |
| GPS | `gps` |
| Giroscópio | `gyro` |
| Acelerômetro | `accelerometer` |
| Lidar | `lidar` |
| Emissor | `emitter` |
| Receptor | `receiver` |
