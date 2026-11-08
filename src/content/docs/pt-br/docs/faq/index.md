---
title: Perguntas frequentes
description: Perguntas frequentes sobre o Erebus e a competição.
---

## Sobre o Erebus {#custom-md-id}

### Preciso de um robô real? {#do-i-need-a-real-robot}
Não. Tudo acontece no simulador. O robô é um e-puck virtual que você projeta.

### Quais linguagens de programação posso usar? {#which-programming-languages-can-i-use}
Esta documentação cobre Python e C/C++. O Erebus também consegue carregar controladores em Java e MATLAB, mas esta documentação não tem exemplos para eles.

### Preciso de um computador potente? {#is-a-powerful-computer-needed}
Não, veja os [requisitos](/docs/installation/). Computadores mais lentos podem precisar de [configurações gráficas mais baixas](/docs/troubleshooting/#the-simulation-runs-too-slowly).

### Posso usar uma versão mais nova do Webots? {#can-i-use-a-newer-version-of-webots}
Não. O Erebus v26 roda no Webots **R2023b**. Você pode manter outras versões instaladas ao lado dele.

### Posso usar bibliotecas como OpenCV ou NumPy? {#can-i-use-libraries-like-opencv-or-numpy}
Sim. Código externo é permitido, desde que você dê crédito a quem o criou e respeite a licença. As equipes devem priorizar o aprendizado e precisam saber explicar como a sua solução funciona.

## A partida {#the-game}

### Qual é a melhor ordem para aprender? {#what-is-the-best-order-to-learn-things}
Siga [o caminho de aprendizado](/docs/#the-learning-path): entenda o jogo, obtenha o seu robô, execute-o, aprenda o básico e depois jogue.

### Preciso criar um robô antes de programar? {#do-i-need-to-make-a-robot-before-programming}
Sim. Todo programa roda em um robô que você carrega, então comece por [Obtenha seu robô](/docs/robot/). Se estiver com pressa, você pode baixar o robô inicial pronto.

### Onde o robô começa? {#where-does-the-robot-start}
No ladrilho inicial, que fica na área 1. Ele sempre começa virado para uma direção sem parede.

### O que acontece se o robô cair em um buraco? {#what-happens-if-the-robot-falls-into-a-hole}
Acontece uma falta de progresso (Lack of Progress, LoP): o robô volta ao último ponto de controle (checkpoint) que visitou, e você perde 5 pontos.

### O robô precisa voltar ao início? {#does-the-robot-have-to-return-to-the-start}
Não, mas voltar ao ladrilho inicial e enviar `E` dá um bônus de saída (exit bonus) de 10%, desde que ele tenha identificado pelo menos um marcador de parede.

### Como o meu robô sabe quanto tempo resta? {#how-can-my-robot-tell-how-much-time-is-left}
Com a [mensagem `G`](/docs/programming/communication/#game-information). Há dois cronômetros, e o tempo de partida corre mais rápido nos pântanos.

### Preciso explorar a área 4? {#do-i-have-to-explore-area-4}
Não. Ela é opcional, mas os marcadores dela são os que mais valem: os pontos mais altos, multiplicados por 2.

### Preciso mapear a área 4? {#do-i-have-to-map-area-4}
Não. Todas as células dela são `*`, então você só precisa preenchê-las.

### O meu robô pode conhecer o mapa antes? {#can-my-robot-know-the-map-beforehand}
Não. É proibido mapear previamente o campo ou a localização dos marcadores nas paredes.

## A competição {#the-competition}

### Como eu participo? {#how-do-i-take-part}
Pela competição regional da RoboCupJunior. O seu representante regional (Regional Representative) distribui as vagas para a competição internacional. Veja o [site da RoboCupJunior](https://junior.robocup.org/).

### O que devo preparar? {#what-should-i-prepare}
Veja [Preparando-se para uma competição](/docs/competition/).

### Onde posso tirar dúvidas sobre as regras? {#where-can-i-ask-about-the-rules}
No [Fórum da RoboCupJunior](https://junior.forum.robocup.org/). Os esclarecimentos também são publicados lá, então confira com frequência.
