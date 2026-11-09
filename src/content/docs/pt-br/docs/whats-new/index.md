---
title: Novidades da v27
description: As mudanças do Erebus v27 e das regras de 2027 que afetam seu robô.
---

O Erebus v27 implementa as regras de 2027. Se você vem da v26, estas são as mudanças que afetam seu robô.

| Assunto | Até 2026 | A partir de 2027 |
|---|---|---|
| Bateria | - | Novo: o robô tem uma [bateria](/docs/rules/#the-battery) que descarrega conforme a velocidade dos motores. Se ela acabar, a partida termina. |
| Ladrilhos de contato | - | Novo: [ladrilhos de contato](/docs/rules/#contact-tiles) ciano. Ficar parado 5 segundos sobre um substitui a bateria. Eles são mapeados como `k`. |
| Pântanos | O tempo de partida corre mais rápido: x5 na primeira entrada, até x10 | A bateria descarrega mais rápido. O tempo de partida não é afetado. |
| Vítimas | Símbolos Φ, Ψ, Ω | [Rostos smiley](/docs/rules/#smiley-victims): triste (ferida), neutro (estável) e feliz (ilesa). Continuam sendo informados como `H`, `S`, `U`. |
| Vítimas falsas | Símbolos tridimensionais | Rostos smiley tridimensionais |
| Informações da partida | A resposta a `G` tem 16 bytes | A resposta a `G` tem 20 bytes e termina com o nível da bateria. Veja [Informações da partida](/docs/programming/communication/#game-information). |
| Distância para informar | O Erebus v26 aceitava informes até 9 cm do marcador | Meio ladrilho (6 cm), como dizem as regras |
| Áreas | Quatro áreas, a área 4 opcional | Até quatro áreas: a área 1 sempre existe, e os organizadores podem deixar de fora as áreas 2 a 4 |
| Webots | R2023b | **R2025a** |
| Python | 3.9 ou mais recente | 3.10 ou mais recente |

[Sua primeira execução](/docs/getting-started/) mostra como usar a janela de controle do Erebus v27.

## Atualizando seu programa {#updating-your-program}

1. Leia a resposta a `G` como 20 bytes. Um programa que só aceita 16 bytes não recebe mais as informações da partida.
1. Acompanhe o nível da bateria e planeje sua rota para que o robô chegue a um ladrilho de contato antes que ela acabe. Veja [Bateria](/docs/programming/battery/).
1. Adicione os ladrilhos de contato ao seu mapa, como `k`.
1. Atualize sua detecção de vítimas para os rostos smiley. As letras que você informa não mudam.
1. Informe os marcadores de mais perto: o centro do robô, e a posição enviada, precisam estar a menos de meio ladrilho do marcador.
1. Os pântanos agora gastam bateria em vez de tempo, então leve-os em conta no seu plano de bateria.
1. Instale o Webots R2025a e o Python 3.10 ou mais recente, e confira se seu programa ainda funciona. Veja [Instalação](/docs/installation/).
