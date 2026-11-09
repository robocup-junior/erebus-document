---
title: O que é o Erebus?
description: O Erebus é a plataforma de simulação de resgate da RoboCupJunior, construída sobre o Webots. Veja como as partes dele se encaixam.
---

O Erebus é um ambiente de competição de simulação de robôs. Você desenvolve um controlador para um robô que explora um labirinto de forma autônoma, encontra e identifica marcadores nas paredes (vítimas smiley e alvos cognitivos), evita obstáculos e armadilhas, mantém a bateria carregada e constrói um mapa do ambiente.

Ele é construído sobre o [Webots](https://cyberbotics.com/), uma plataforma de simulação robótica projetada para uso profissional e muito usada na indústria, na educação e na pesquisa. A Cyberbotics mantém o Webots continuamente desde 1998.

A plataforma foi projetada principalmente para a competição [RoboCupJunior Rescue Simulation](https://junior.robocup.org/rescue/). Ela é voltada para programadores com experiência de nível intermediário a avançado.

## Como as partes se encaixam {#how-it-fits-together}

| Componente | O que faz | Onde obter |
|---|---|---|
| **Webots R2025a** | O simulador de robôs em 3D | [Versão R2025a do Webots](https://github.com/cyberbotics/webots/releases/tag/R2025a) |
| **Erebus** | Os mundos e o supervisor (Main Supervisor), que aplica as regras e calcula a pontuação | [Versões do Erebus](https://github.com/robocup-junior/erebus/releases) |
| **Seu controlador** | O programa do seu robô, em Python ou C/C++ | Você mesmo escreve! |
| **Robot Customizer** | Ferramenta web para projetar um robô personalizado e exportá-lo como um arquivo JSON | [robot.erebus.rcj.cloud](https://robot.erebus.rcj.cloud/) |
| **World Editor** | Ferramenta web para desenhar mapas de treino e exportá-los como mundos `.wbt` | [world.erebus.rcj.cloud](https://world.erebus.rcj.cloud/) |

## O que você pode fazer com ele? {#what-can-you-do-with-it}

1. **Montar um robô.** Escolha os sensores dele e onde ficam, dentro de um orçamento.
2. **Programá-lo.** O seu controlador lê os sensores e decide o que fazer, sem ajuda humana.
3. **Executá-lo.** Teste-o nos mundos incluídos ou nos seus próprios e acompanhe a pontuação.
4. **Competir.** Participe de competições locais, regionais e internacionais da RoboCupJunior.

Se você já conhece o Erebus, veja [Novidades da v27](/docs/whats-new/).

## Referências úteis {#useful-references}
Links úteis para aprender sobre o Erebus e trabalhar com ele:
- [Guia do usuário do Webots](https://cyberbotics.com/doc/guide/index?version=R2025a)
- [Manual de referência do Webots](https://cyberbotics.com/doc/reference/nodes-and-api-functions?version=R2025a)
- [Documentação do Python](https://www.python.org/doc/)
- [Documentação do C++](https://www.cplusplus.com/doc/tutorial/)
- [Tutoriais do OpenCV](https://docs.opencv.org/4.x/d9/df8/tutorial_root.html)
- [Site da comunidade RCJ Rescue](https://rescue.rcj.cloud/): eventos, documentos das equipes e critérios de avaliação do TDP, do pôster e do vídeo
- [Fórum da RoboCupJunior](https://junior.forum.robocup.org/): esclarecimentos sobre as regras

## Próximo passo {#next}
[Instale o Erebus](/docs/installation/) e depois leia o [Resumo das regras](/docs/rules/) para entender o jogo.
