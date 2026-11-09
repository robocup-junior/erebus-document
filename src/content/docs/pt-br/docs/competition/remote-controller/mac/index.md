---
title: macOS
description: Como configurar o Remote Controller no macOS.
---

# Executando o servidor da partida e o programa controlador no mesmo computador
Primeiro, tente executar o servidor da partida e o seu programa controlador no mesmo computador. Essa não é a configuração usada nas competições, mas é útil para depurar localmente.

## Ative o modo remoto {#toggle-remote-mode}
Abra o mundo, clique em **Robot setup** na janela de controle e ative **Remote mode**. Se você tem um robô personalizado, carregue antes seu robô em **Robot JSON**.

![Remote mode, ativado em Robot setup](../../../../../docs/competition/remote-controller/mac/toggle_remote.png)

Se a janela de controle não aparecer, clique com o botão direito em "DEF MAINSUPERVISOR Robot" na Scene Tree (árvore da cena) e escolha "Show Robot Window".

## Execute o seu programa {#execute-your-program}
Abra um terminal e execute os comandos a seguir, substituindo `<Your controller path>` pelo caminho do seu programa controlador.

```bash
export WEBOTS_HOME=/Applications/Webots.app
"$WEBOTS_HOME/Contents/MacOS/webots-controller" "<Your controller path>"
```

Se o Webots estiver instalado em outro lugar ou com outro nome, ajuste `WEBOTS_HOME`, por exemplo para `"/Applications/Webots R2025a.app"`.

O controlador se conecta ao Webots e espera até a partida começar.

## Inicie a partida {#start-the-game}
Clique em **Run match** na janela de controle. O robô aparece e seu programa começa a rodar.

## Encerre a partida {#terminate-the-game}
Para parar a partida, pressione Ctrl+C no terminal.

Quando a partida terminar, clique em **Reset** para executá-la de novo. O reset desativa o Remote mode, a menos que **Keep on Reset** esteja ativado.

# Executando o servidor da partida em outro computador
Esta é a configuração usada nas competições oficiais. O computador que executa o seu controlador (o cliente) e o que executa a partida (o servidor) precisam estar conectados à mesma rede.

1. (Servidor) Inicie o Webots no servidor, abra o mundo e ative **Remote mode** em **Robot setup** da janela de controle.
1. (Servidor) Descubra o endereço IP do servidor em Ajustes do Sistema > Rede.
1. (Cliente) Execute os comandos a seguir, substituindo `<Your controller path>` pelo caminho do seu programa controlador e `<Server IP address>` pelo endereço IP que você encontrou na etapa anterior.

    ```bash
    export WEBOTS_HOME=/Applications/Webots.app
    "$WEBOTS_HOME/Contents/MacOS/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. (Servidor) Inicie a partida clicando em **Run match**.

## Solução de problemas {#troubleshooting}
- **O controlador não consegue se conectar:** confira se os dois computadores conseguem se comunicar, por exemplo com `ping`, se o firewall do servidor permite a porta TCP 1234 e se a lista de IPs permitidos na aba Network das preferências do Webots está vazia ou inclui o cliente.
- **O controlador espera, mas o robô não se mexe:** confira se **Remote mode** está ativado e clique em **Run match**.
- **O controlador não encontra uma biblioteca Python:** o programa roda com a instalação do Python do cliente, então instale a biblioteca nela.

# Documentação oficial
Para mais detalhes sobre essa configuração, consulte o [guia do Webots](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a).
