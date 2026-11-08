---
title: Preparando-se para uma competição
description: Uma lista de verificação para se preparar para uma competição de RoboCupJunior Rescue Simulation.
---

Esta página é um guia para a competição internacional com as regras de 2026. As competições locais e regionais podem ser diferentes, então confirme com a organização. As [regras](/docs/rules/) oficiais sempre valem.

## Cronograma {#timeline}

| Quando | O quê |
|---|---|
| Ao longo do ano | Acompanhe a [página do evento](/docs/events/upcoming-events/) e o [fórum](https://junior.forum.robocup.org/), onde os esclarecimentos são publicados |
| Pelo menos 4 semanas antes | Os organizadores passam as instruções do formulário web para preparar as entrevistas |
| 3 semanas antes do primeiro dia | Prazo final dos documentos |
| Dia de montagem | Chegue cedo ao local para o credenciamento, as entrevistas e as reuniões das equipes |
| Cada rodada | Os mundos são revelados pouco antes das partidas. Os programas não podem mudar depois do prazo de cada rodada. |
| Depois das rodadas de pontuação | Desafio técnico (Technical Challenge) |

## Documentos para enviar {#documents-to-submit}
Os modelos e os critérios de avaliação estão no [site da comunidade RCJ Rescue](https://rescue.rcj.cloud/).

- [ ] **Technical Description Paper (TDP).** Siga o modelo à risca: caso contrário, a nota do documento é 0.
- [ ] **Pôster,** como arquivo e como pôster físico no local, no máximo do tamanho A1.
- [ ] **Vídeo** apresentando o seu projeto.
- [ ] **Vídeo servidor-cliente,** novo em 2026: um vídeo curto mostrando como você executa o seu controlador em um mapa de exemplo na configuração servidor-cliente.
- [ ] **Código-fonte** e o **formulário web** das entrevistas.

## Configuração da competição {#competition-setup}
As partidas rodam em uma configuração servidor-cliente: os organizadores rodam o servidor da partida e fornecem uma tomada RJ-45, e o seu programa roda no seu computador. Veja [Remote Controller](/docs/competition/remote-controller/).

Leve:

- [ ] Um computador com o seu programa e todas as bibliotecas dele instaladas, além do Webots R2023b
- [ ] Um cabo Ethernet, e um adaptador se o seu computador precisar
- [ ] O arquivo `.json` do seu robô, se você tiver um robô personalizado
- [ ] O pôster físico

## Configurações de OpenGL {#opengl-settings}
A menos que os organizadores anunciem outra coisa, são usadas as configurações a seguir. Elas afetam o que as câmeras veem, então teste com elas. Você as encontra na aba OpenGL das preferências do Webots.

| Configuração | Valor |
|---|---|
| Ambient Occlusion | Low |
| Texture Quality | Low |
| Max Texture Filtering | 4 |
| Shadows | Disabled |
| Anti-aliasing | Disabled |

## Testando o seu robô {#testing-your-robot}
- [ ] Rode em todos os mundos incluídos, principalmente `world3.wbt` e `world4.wbt`, que têm falsos.
- [ ] Crie os seus próprios mapas com o [World Editor](/docs/tools/world-editor/), incluindo as quatro áreas.
- [ ] Confira a partida inteira: ela roda até o fim, envia o mapa e volta ao início a tempo?
- [ ] Teste o que acontece depois de uma falta de progresso (Lack of Progress, LoP).
- [ ] Teste no computador que você vai levar e com as configurações de OpenGL acima.

## Durante a competição {#during-the-competition}
- Somente o capitão e o vice-capitão podem entrar na área de competição, a menos que um árbitro diga o contrário.
- O árbitro opera a simulação. Você não pode tocar no equipamento da partida depois que ela começa.
- Os mentores não podem ajudar durante a competição.
- Esteja pronto para explicar o seu trabalho: cada membro da equipe deve ter uma função técnica e saber como ela funciona.

## Pontuação final {#final-score}
A pontuação final nas competições internacionais combina:

| Parte | Peso | Conteúdo |
|---|---|---|
| Pontuação de campo | 0,6 | Média das pontuações de campo normalizadas. A pior rodada, ou as piores, são descartadas. |
| Critérios de avaliação | 0,2 | TDP (0,6), vídeo (0,2), pôster (0,2) |
| Desafio técnico | 0,2 | Minitarefas anunciadas na competição, resolvidas reprogramando o seu robô em tempo limitado |

Os empates são resolvidos com base na média das pontuações de campo normalizadas. O SuperTeam Challenge é um evento separado, com premiação própria.
