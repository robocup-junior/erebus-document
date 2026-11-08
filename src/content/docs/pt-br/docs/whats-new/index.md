---
title: Novidades da v26
description: As mudanças do Erebus v26 e das regras de 2026 que afetam o seu robô.
---

O Erebus v26 implementa as regras de 2026. Se você vem de uma versão anterior, estas são as mudanças que afetam o seu robô.

| Tema | Até 2025 | A partir de 2026 |
|---|---|---|
| Vítimas de letra | Letras H, S, U | Símbolos Φ (ferida), Ψ (estável), Ω (ilesa). Elas continuam sendo informadas como `H`, `S`, `U`. |
| Sinais de materiais perigosos | Quatro rótulos de materiais perigosos (hazmat) | Substituídos pelos [alvos cognitivos](/docs/rules/#cognitive-targets) (cognitive targets): anéis coloridos concêntricos cujos valores somados dão o tipo. Eles continuam sendo informados como `F`, `P`, `C`, `O`. |
| Marcadores falsos | - | Novo: [vítimas falsas](/docs/rules/#fake-victims) (fake victims) com letras tridimensionais e alvos cognitivos cuja soma não está entre 0 e 3. Não os informe nem os coloque no mapa. |
| Pântanos | Tempo consumido 5x mais rápido | A primeira entrada em um pântano é x5, e cada nova entrada no mesmo pântano soma 1, até x10. |
| Obstáculos no mapa | Não mapeados | Ladrilhos com um obstáculo são mapeados como `x`. |
| Bônus de mapa | Até x2 | O multiplicador agora é acerto × 1,2 + 1. |
| Ruído dos sensores | - | O GPS tem ruído. Os organizadores não vão mudar os níveis de ruído na competição. |
| Execução das partidas | Anunciada a cada evento | Configuração servidor-cliente: o seu controlador roda no seu próprio computador, conectado ao servidor da partida por Ethernet. Veja [Remote Controller](/docs/competition/remote-controller/). |
| Documentos | TDP, pôster, vídeo | Além disso, um vídeo curto mostrando como você executa o seu controlador na configuração servidor-cliente. |
| Partidas perdidas | -50 pontos | 0 pontos. |

A versão do Webots não mudou: o Erebus v26 continua rodando no Webots **R2023b**.

As duas versões lançadas depois da v26.0.0 não mudam as regras. A v26.0.1 adiciona mundos de exemplo com vítimas falsas e um script que transforma as vítimas de um mundo existente em falsas, e a v26.1 corrige a forma como os obstáculos são marcados na área 4.

## Atualizando o seu programa {#updating-your-program}

1. Atualize a sua detecção de vítimas para os novos símbolos. As letras que você informa não mudam.
2. Substitua a detecção de materiais perigosos pela [leitura de alvos cognitivos](/docs/programming/wall-tokens/#reading-a-cognitive-target).
3. Garanta que o seu programa não informe os falsos e os deixe fora do mapa.
4. Adicione os obstáculos ao seu mapa, como `x`.
5. Planeje a sua rota pensando nos novos pântanos: cada vez que o robô entra no mesmo pântano, isso custa mais tempo.
6. Pratique a [configuração servidor-cliente](/docs/competition/remote-controller/).
