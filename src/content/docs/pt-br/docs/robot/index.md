---
title: Obtenha seu robô
description: Todo programa roda em um robô projetado por você. Baixe o robô inicial ou monte-o você mesmo.
---

No Erebus, **você projeta o seu robô**: escolhe os sensores dele e onde ficam, dentro de um orçamento. Todo programa precisa de um, então o primeiro passo é obter um robô e carregá-lo no Erebus.

![Um robô e-puck real](../../../docs/robot/real_robot.thumbnail.jpg)

O robô é baseado no [e-puck](https://cyberbotics.com/doc/guide/epuck?version=R2025a), um pequeno robô educacional redondo com duas rodas. Você adiciona sensores a ele com o [Robot Customizer](https://robot.erebus.rcj.cloud/) e salva o projeto como um arquivo `.json`, que o Erebus carrega.

## O robô inicial {#the-starter-robot}
Esta documentação usa o mesmo robô em todo lugar, o **robô inicial**, para que todos os exemplos funcionem do jeito que estão. Ele tem todos os sensores de que os tutoriais precisam:

| Componente | Nome no seu programa | Para que serve |
|---|---|---|
| Duas rodas | `left wheel motor`, `right wheel motor` | Mover-se |
| Encoders das rodas | `left wheel sensor`, `right wheel sensor` | Medir quanto as rodas giraram |
| Três sensores de distância | `leftDist`, `frontDist`, `rightDist` | Encontrar paredes à esquerda, à frente e à direita |
| Câmera, 64 × 40 pixels | `camera` | Encontrar marcadores nas paredes |
| Sensor de cor | `color` | Ver o piso: buracos, pântanos, ladrilhos de contato e passagens |
| GPS | `gps` | Saber a sua posição, para informar marcadores |
| Giroscópio | `gyro` | Medir quanto o robô girou |
| Acelerômetro | `accelerometer` | Medir a aceleração |
| Lidar | `lidar` | Medir distâncias ao redor |
| Emissor e receptor | `emitter`, `receiver` | Conversar com a partida. Todo robô tem os dois. |

Ele custa 2400 do orçamento de 3000.

![O robô pronto, com os rótulos e a visão da câmera](../../../docs/robot/build/finished.png)

## Escolha o seu caminho {#choose-your-path}

**Recomendado: monte-o você mesmo.** Leva cerca de 15 minutos, e você vai entender cada parte do seu robô. Siga [Monte seu robô](/docs/robot/build/).

**Com pressa:** baixe o robô pronto e continue com os tutoriais. Você sempre pode voltar e montá-lo depois.

<a href="/downloads/starter-robot.json" download>Baixar starter-robot.json</a>

## Carregue-o no Erebus {#load-it-in-erebus}
1. Abra um mundo, como `game/worlds/world1.wbt`.
2. Na janela de controle, clique em **Robot setup**, depois em **Load file** em **Robot JSON**, e escolha seu arquivo `.json`.
3. Confira o console do Webots. O Erebus lista cada componente com seu custo e termina com `Your custom robot has been successfully generated!` e o orçamento usado.

O robô continua carregado até você carregar outro. Com **Keep files after Reset**, que vem ativado por padrão, ele também continua carregado quando você reinicia a partida. Em seguida, [execute seu primeiro programa](/docs/getting-started/).

## Projetando o seu próprio robô {#designing-your-own}
Quando você já souber o básico, altere o robô inicial ou projete um novo: mais câmeras com resolução maior, mais sensores de distância, sensores em outros lugares. A [Referência do Robot Customizer](/docs/robot/customizer/) lista todos os componentes, os custos e os limites deles.

Se você mudar o nome de um componente, mude-o também no seu programa.
