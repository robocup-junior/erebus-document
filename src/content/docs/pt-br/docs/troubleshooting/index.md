---
title: Solução de problemas
description: Soluções para problemas comuns ao instalar e executar o Erebus.
---

Antes de tudo, confira o console do Webots. A maioria dos problemas mostra uma mensagem de erro lá.

## Instalação {#installation}

### `No module named 'cv2'` {#no-module-named-cv2}
O OpenCV não está instalado no Python usado pelo Webots. Instale as [bibliotecas necessárias](/docs/installation/#python-libraries) nesse Python. Se você tiver várias instalações, a configuração **Python command** abaixo mostra qual delas o Webots usa.

### `WARNING: Python was not found` {#warning-python-was-not-found}
O Webots não sabe onde o Python está.

1. Encontre-o. No macOS e no Linux, execute `which python3` em um terminal. No Windows, confira se digitar `python` em um novo Prompt de Comando abre o Python. Se não abrir, instale o Python de novo, marcando a opção de adicioná-lo ao seu PATH.
2. Abra as preferências do Webots: **Webots > Preferences** no macOS, **Tools > Preferences** no Windows e no Linux.

   ![O item Preferences no menu do Webots](../../../docs/troubleshooting/preferences_open.png)

3. Defina o caminho no campo **Python command**. No Windows, `python` normalmente basta.

   ![O campo Python command nas preferências do Webots](../../../docs/troubleshooting/preferences.png)

### `ERROR: Skipped PROTO 'custom_robot'` {#error-skipped-proto-custom_robot}
Aparece na primeira vez que você abre um mundo, antes de o Erebus preparar o modelo do robô. O Erebus o prepara e recarrega o mundo sozinho, então você pode ignorar.

### O cronômetro da partida não aparece {#the-game-timer-does-not-appear}
A primeira inicialização pode levar alguns minutos enquanto o Erebus instala as bibliotecas. Se ela nunca terminar, procure erros no console. Se a instalação automática não funcionar, instale as [bibliotecas necessárias](/docs/installation/#python-libraries) por conta própria.

## Executando o Erebus {#running-erebus}

### A janela de controle não aparece {#the-control-window-does-not-appear}
A janela de controle é uma página web aberta pelo Webots.

1. Se você a fechou, ou o navegador a bloqueou, recarregue o mundo com o botão de recarregar do Webots. O Erebus abre a janela de controle de novo.
2. Caso contrário, garanta que a Scene Tree (árvore da cena) esteja visível, com **Tools > Scene Tree**.
3. Encontre **DEF MAINSUPERVISOR Robot** na Scene Tree, clique com o botão direito e escolha **Show Robot Window**.

A janela de controle tem um endereço privado, que muda a cada vez que o mundo é carregado. Se você mesmo abrir a janela em `localhost:1234`, ela mostra **Read-only**, e os botões não funcionam.

### A janela de controle diz "Access log incomplete" {#the-control-window-says-access-log-incomplete}
Este aviso aparece quando o [Wireshark](/docs/installation/#optional-wireshark) não está instalado. Ele é para os organizadores nas competições: clique em **Acknowledge** e treine normalmente.

![A opção Show Robot Window na Scene Tree](../../../docs/troubleshooting/showrobot.png)

### A tela do Webots fica em branco ou preta {#the-webots-screen-is-blank-or-black}
Copie o download e descompacte-o em uma pasta separada antes de abrir o mundo.

### A simulação está lenta demais {#the-simulation-runs-too-slowly}
Isso provavelmente se deve ao desempenho do seu computador. Diminuir a qualidade dos gráficos pode ajudar:

1. Abra as preferências do Webots.
2. Abra a aba **OpenGL**.
3. Altere as configurações.

![A aba OpenGL das preferências do Webots](../../../docs/troubleshooting/opengl.png)

Essas configurações mudam o que as câmeras veem, e a competição usa [configurações próprias](/docs/competition/#opengl-settings), então teste o seu programa com elas também.

## O seu robô {#your-robot}

### O meu programa diz que um dispositivo não foi encontrado {#my-program-says-a-device-was-not-found}
Veja abaixo. Confira também se você carregou seu robô em **Robot JSON**, no **Robot setup**, antes de começar a partida.

## O seu programa {#your-program}

### `Device "..." was not found` {#device--was-not-found}
O nome do dispositivo no seu programa não corresponde ao seu robô. Os nomes do robô inicial estão na [Referência](/docs/reference/parameters/#device-names-of-the-starter-robot). No seu próprio robô, eles são os nomes que você definiu no [Robot Customizer](/docs/robot/customizer/). Confira se o seu robô foi carregado.

### Nada acontece quando informo um marcador {#nothing-happens-when-i-report-a-wall-token}
Ative **Enable debugging** em **Advanced setup** na janela de controle e confira o console. As causas mais comuns são o robô não ter ficado parado por pelo menos 1 segundo, as coordenadas não terem sido convertidas para centímetros, e o robô ou a posição estarem a mais de meio ladrilho (6 cm) do marcador. Veja [Comunicação](/docs/programming/communication/#scoring-wall-tokens).

### Os meus informes contam como identificação errada {#my-reports-are-misidentifications}
O robô precisa estar a no máximo meio ladrilho do marcador e do mesmo lado da parede, e cada marcador só pode ser pontuado uma vez. Informar um falso também conta como identificação errada.

### A partida termina com "Battery depleted" {#the-game-ends-with-battery-depleted}
A bateria acabou. Antes que isso aconteça, pare por 5 segundos sobre um ladrilho de contato para substituí-la. Veja [Bateria](/docs/programming/battery/).

### Meu programa não recebe mais as informações da partida {#my-program-no-longer-receives-the-game-information}
Desde o Erebus v27, a resposta a `G` tem 20 bytes, com o nível da bateria no final. Atualize a verificação do tamanho no seu programa. Veja [Informações da partida](/docs/programming/communication/#game-information).

### O mapa recebe 0% ou um erro de pontuação {#the-map-gets-0-or-a-scoring-error}
O seu mapa precisa conter o ladrilho inicial (`5`), e ele só pode ser avaliado uma vez. Veja [Enviar o mapa](/docs/programming/map-bonus/).

### O controlador não consegue se conectar no modo remoto {#the-controller-cannot-connect-in-remote-mode}
Veja o guia do [Remote Controller](/docs/competition/remote-controller/) para o seu sistema operacional.

## Ainda com problemas? {#still-stuck}
Pergunte no [servidor do Discord](https://discord.com/invite/6FJxZxk) ou [abra uma issue](https://github.com/robocup-junior/erebus/issues). Informe o seu sistema operacional, as versões do Erebus e do Webots e a mensagem do console.
