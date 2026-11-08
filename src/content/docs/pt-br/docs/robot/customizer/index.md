---
title: Referência do Robot Customizer
description: A tela, os componentes, os custos e os limites do Robot Customizer.
---

O [Robot Customizer](https://robot.erebus.rcj.cloud/) permite escolher os sensores do seu robô e onde colocá-los. Ele roda no seu navegador e exporta um arquivo `.json`, que o Erebus carrega.

É a primeira vez? Comece por [Monte seu robô](/docs/robot/build/), que monta o robô inicial passo a passo. Esta página descreve todo o resto.

![O Robot Customizer](../../../../docs/robot/customizer/customizer.png)

A pré-visualização em 3D fica à esquerda, e os componentes e o orçamento ficam à direita.

## A tela {#the-screen}

1. **Adicione componentes.** Ative a chave de cada sensor ou câmera que você quer e defina o número de sensores de distância com `−` e `+`. O custo de cada componente aparece ao lado dele.
2. **Fique dentro do orçamento.** O canto superior direito mostra quanto resta do orçamento de 3000 e como ele está dividido entre rodas, sensores de distância, sensores e câmeras. Se você passar do limite, ele diz quanto precisa remover: o robô não pode ser exportado até caber no orçamento.
3. **Posicione-os.** Clique em um componente na lista ou na visão 3D para abrir as configurações dele. Arraste as setas na visão 3D, com **Move** (`W`) ou **Rotate** (`R`), ou digite os valores. As posições são em décimos de milímetro, embora as caixas digam mm. A posição Y vai de -100 a 370. Os botões de rotação apontam um sensor para a frente, para trás, para a esquerda, para a direita, para cima ou para baixo com um clique. A seta verde marca a frente do robô.
4. **Dê nome a eles.** O nome é o que o seu programa usa com `getDevice()`, como aparece em **In your controller**. As rodas geram dois dispositivos: `<name> motor` e `<name> sensor`. A Wheel 1 fica do lado direito do robô, e a Wheel 2 do lado esquerdo.
5. **Defina a resolução da câmera.** Cada câmera tem uma largura e uma altura, que mudam o seu custo.
6. **Exporte.** Digite um nome de arquivo no topo e pressione **Export**. Guarde o arquivo: com **Import**, ou soltando o arquivo na página, você o abre de novo para continuar trabalhando nele.

![As configurações de uma câmera](../../../../docs/robot/customizer/component.png)

### Visualizações úteis {#useful-views}
- **3D**, **Top**, **Front** e **Side** mostram o robô de ângulos diferentes. Top é prático para posicionar sensores de forma simétrica.
- **Labels** mostra o nome de cada componente.
- **Camera view** mostra uma estimativa do que as câmeras veem no Webots.
- Desfazer, refazer e reiniciar ficam no topo.

## Usando no Erebus {#using-it-in-erebus}

Pressione o botão LOAD da direita na [janela de controle](/docs/getting-started/#the-control-window) e escolha o seu arquivo `.json`. Veja [Carregue-o no Erebus](/docs/robot/#load-it-in-erebus). O Erebus confere o orçamento e gera o robô, e o console do Webots lista cada componente e o seu custo.

Carregue primeiro o seu robô e depois o seu programa.

## Componentes {#components}

| Componente | Custo | Nome padrão |
|---|---|---|
| Roda (2, obrigatórias) | 300 cada | `wheel1`, `wheel2` |
| Sensor de distância (até 8) | 50 cada | `distance sensor1`, `distance sensor2`… |
| Giroscópio | 100 | `gyro` |
| Unidade inercial | 100 | `inertial_unit` |
| Acelerômetro | 100 | `accelerometer` |
| Sensor de cor | 100 | `colour_sensor` |
| GPS | 250 | `gps` |
| Lidar | 500 | `lidar` |
| Câmera (até 3) | 500, mais o custo da resolução | `camera1`, `camera2`, `camera3` |

O custo de resolução de uma câmera é somado para a largura e para a altura: 32 ou 40 pixels custam 0, 64 pixels custam 100, 128 pixels custam 200 e 256 pixels custam 300. Por exemplo, uma câmera de 256 × 128 custa 500 + 300 + 200 = 1000.

As câmeras novas têm 40 × 32 pixels. O robô inicial usa 64 × 40.

As duas rodas custam 600 juntas, então sobram 2400 do orçamento para todo o resto.

## Dicas de projeto {#design-tips}

- **GPS:** você precisa de uma posição para informar os marcadores, e este é o jeito simples de obtê-la.
- **Câmeras:** resoluções maiores leem os marcadores de mais longe, mas custam mais e são mais lentas de processar.
- **Lidar:** ele enxerga ao redor de todo o robô, o que ajuda muito no mapeamento. Coloque-o em cima e deixe-o na horizontal com rotação X `90`, como no [robô inicial](/docs/robot/build/), senão o robô o bloqueia.
- **Sensor de cor:** coloque-o na frente das rodas, para que o robô veja um buraco antes de cair nele.

[Monte seu robô](/docs/robot/build/) mostra um exemplo completo.
