---
title: World Editor
description: Como criar os seus próprios mundos com o World Editor do Erebus.
---

## Contexto {#background}

Quando o seu robô já se sair bem nos mapas incluídos e em labirintos simples, talvez você queira algo mais desafiador, ou testar cenários específicos que os mapas incluídos não cobrem.
Para isso, existe o [Erebus World Editor](https://world.erebus.rcj.cloud/) online. Você desenha um mapa no navegador, e ele exporta um arquivo de mundo `.wbt` que você pode executar no Erebus.

![Um mapa pronto no World Editor](../../../../docs/tools/world-editor/overview.png)

Se você está só criando mapas pequenos para testes, provavelmente não importa muito se o campo segue as regras. Mas, se pretende montar um campo de competição, leia as [Regras de simulação](https://junior.robocup.org/wp-content/uploads/2026/09/RCJRescueSimulation2027-draft.pdf) oficiais. O editor confere o seu mapa com as regras enquanto você trabalha.

O editor tem um guia embutido: pressione **Guide** no canto inferior direito para uma aula prática que monta um mapa de exemplo (cerca de 15 minutos), um tour pela tela ou uma aula sobre a Room 4. O idioma do editor pode ser alterado ao lado.

## Começando um mapa {#starting-a-map}
Ao abrir o editor, escolha **as regras de qual ano** seguir e clique em **New map**. **Escolha as regras de 2027 para o Erebus v27.** As regras de 2026 são para o Erebus v26. Você pode mudar as regras de um mapa depois, na barra superior.

![A tela inicial do World Editor](../../../../docs/tools/world-editor/start.png)

O seu trabalho fica guardado no navegador, mas se perde em outro navegador ou quando os dados de navegação são apagados. Guarde os mapas importantes salvando-os como JSON com o botão de salvar na barra superior e abra-os de novo com o botão de abrir.

Uma boa ordem de trabalho é a seguinte: tamanho e contorno, salas, passagens, paredes, pisos, obstáculos e vítimas, Room 4 e, por fim, as verificações e a exportação. As ferramentas ficam à esquerda, cada uma com um atalho de teclado. As configurações da ferramenta selecionada aparecem no painel ao lado.

| Ferramenta | Tecla | Uso |
|---|---|---|
| Select | `S` | Selecionar, mover, copiar e colar partes do mapa |
| Move | `H` | Mover a visão |
| Outline | `X` | Definir o tamanho e a forma do mapa |
| Rooms | `M` | Pintar as salas (Rooms) 1 a 4 (as áreas das regras) |
| Passages | `P` | Ligar salas com uma passagem |
| Line | `L` | Desenhar paredes |
| Curve | `A` | Desenhar paredes curvas na Room 3 |
| Eraser | `E` | Remover paredes, pisos, obstáculos e vítimas |
| Floor | `F` | Definir pontos de controle, buracos, pântanos, ladrilhos de contato e o ladrilho inicial |
| Obstacle | `O` | Colocar obstáculos |
| Victims | `V` | Colocar vítimas smiley, alvos cognitivos e falsos |

A roda do mouse dá zoom, arrastar segurando Espaço move a visão, e desfazer é `⌘Z` ou `Ctrl+Z`.

## Tamanho e contorno {#size-and-outline}
Com a ferramenta **Outline**, defina o tamanho do mapa em ladrilhos. As paredes externas são adicionadas automaticamente. **Outline (uneven)** permite clicar em ladrilhos para tirá-los do mapa, e você também pode inserir e remover linhas e colunas onde clicar.

![A ferramenta Outline](../../../../docs/tools/world-editor/outline.png)

## Salas e passagens {#rooms-and-passages}
Com a ferramenta **Rooms**, pinte os ladrilhos de cada sala. As paredes são adicionadas automaticamente nas divisas entre as salas. Depois, com a ferramenta **Passages**, ligue as salas: a cor de cada passagem é escolhida de acordo com as salas que ela conecta.

![A ferramenta Rooms](../../../../docs/tools/world-editor/rooms.png)

![A ferramenta Passages](../../../../docs/tools/world-editor/passages.png)

## Paredes {#walls}
Use a ferramenta **Line** para desenhar paredes: nas bordas dos ladrilhos na Room 1 e em quartos de ladrilho nas Rooms 2 e 3. Use a ferramenta **Curve** na Room 3, apontando para um quarto de ladrilho para escolher a curva. Clicar de novo na mesma curva a remove.

![A ferramenta Line para paredes](../../../../docs/tools/world-editor/walls.png)

## Pisos e obstáculos {#floors-and-obstacles}
Com a ferramenta **Floor**, escolha um tipo de piso e clique em um ladrilho para defini-lo: ponto de controle, buraco, pântano, ladrilho de contato ou início. O ladrilho inicial precisa ser da sala 1, e sem ele o mundo não pode ser exportado. Um ladrilho só pode ser uma destas coisas: buraco, pântano, ponto de controle, ladrilho de contato, obstáculo, início ou passagem.

![A ferramenta Floor](../../../../docs/tools/world-editor/floors.png)

Com a ferramenta **Obstacle**, escolha uma forma e clique em um ladrilho. Nas Rooms 1 a 3, há um obstáculo por ladrilho, com o centro no ladrilho. Clique em um obstáculo para mudar o tamanho, a altura, a cor e a rotação dele com as alças e o painel.

![A ferramenta Obstacle](../../../../docs/tools/world-editor/obstacles.png)

## Vítimas e alvos cognitivos {#victims-and-cognitive-targets}
Com a ferramenta **Victims**, escolha um tipo e clique perto de uma parede. Você pode colocar:

- Vítimas smiley reais: ferida, estável e ilesa
- Vítimas smiley falsas com rostos tridimensionais
- Alvos cognitivos: escolha o material perigoso (hazmat) e, se quiser, as cores dos anéis. A soma aparece na tela e decide o tipo
- Alvos falsos, cujos anéis somam um valor fora de 0 a 3

Na Room 1, pode haver uma vítima em cada lado de ladrilho. Nas Rooms 2 e 3, elas ficam nas faces das paredes de 6 cm, e as curvas têm dois lugares, por dentro e por fora. Em **Turn**, escolha uma rotação fixa ou uma aleatória para cada novo marcador. Clique em um marcador já colocado para alterá-lo ou removê-lo, ou arraste-o ao longo da parede.

![A ferramenta Victims](../../../../docs/tools/world-editor/victims.png)

## Room 4 {#room-4}
A Room 4 não é baseada em ladrilhos, então ela é desenhada como uma imagem. Com a ferramenta **Rooms**, pinte a Room 4 e pressione **Draw room 4** (ou dê um clique duplo na sala) para abrir o criador da Room 4.

![O criador da Room 4](../../../../docs/tools/world-editor/room4.png)

O que você desenha em preto vira parede. O criador tem ferramentas para desenhar à mão livre e para desenhar linhas, curvas, arcos, retângulos, elipses, polígonos e formas a partir de ícones, além de ferramentas para vítimas e obstáculos. Na Room 4, você pode colocar quantos obstáculos quiser. Listras vermelhas mostram onde o robô não consegue chegar, e você precisa deixar um caminho com cerca de um ladrilho de largura para o robô passar.

Quando terminar, pressione **OK**: a imagem aparece como Room 4 no mapa e vai para o mundo exportado. Os botões no canto superior direito do criador salvam a imagem como PNG, para você usar a mesma Room 4 em outro mapa, e abrem imagens PNG ou JPEG.

## Verificando o seu mapa {#checking-your-map}
Cada mudança é verificada com as regras, no cartão **Checks** no canto superior direito. Um ✕ vermelho é um problema que impede a exportação do mundo, e um ! amarelo é um alerta que vale a pena olhar. Clique em um item para ir até ele. **Fix** corrige um item, e **Fix all that can be fixed** corrige todos.

![Um mapa novo no World Editor, com o cartão Checks](../../../../docs/tools/world-editor/new_map.png)

O botão **Linear** na barra superior colore cada ladrilho como linear ou flutuante, o que define quanto valem os marcadores.

![Ladrilhos lineares e flutuantes mostrados no mapa](../../../../docs/tools/world-editor/linear.png)

O troféu na barra superior mostra a **pontuação máxima** do mapa, calculada com as regras de pontuação, com a parte de cada sala e a pontuação com os bônus de saída e de mapa.

![A pontuação máxima do mapa](../../../../docs/tools/world-editor/max_score.png)

## Exportando e executando o seu mundo {#exporting-and-running-your-world}
Defina o nome do mapa na barra superior e pressione o botão **.wbt** no canto superior direito. Depois:

1. Copie o arquivo `.wbt` para a pasta `game/worlds` do Erebus. Ele precisa estar nessa pasta, já que o mundo usa arquivos do Erebus.
1. Abra-o no Webots ou escolha-o com o botão **Worlds** da [janela de controle](/docs/getting-started/).

![O mapa de exemplo do guia do editor, rodando no Erebus v27.](../../../../docs/tools/world-editor/exported_world.png)

*O mapa de exemplo do guia do editor, rodando no Erebus v27.*

Um arquivo `.wbt` não volta a ser um mapa editável, então guarde também o JSON.
