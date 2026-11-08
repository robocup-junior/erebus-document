---
title: macOS
description: Guia de configuração do Remote Controller para macOS.
---

# Executando o servidor da partida e o programa controlador no mesmo computador
Primeiro, vamos tentar executar o servidor da partida e o programa controlador no mesmo computador. Isso não é igual à configuração de uma competição real, mas vai ajudar você na hora de depurar localmente.

## Ative o modo remoto {#toggle-remote-mode}
Abra o mundo e pressione "TOGGLE REMOTE" na janela de controle. A cor do botão deve ficar laranja, indicando que ele está ativado.

![O botão TOGGLE REMOTE, ativado](../../../../../docs/competition/remote-controller/mac/toggle_remote.png)

Se a janela de controle não aparecer, clique com o botão direito em "DEF MAINSUPERVISOR Robot" na Scene Tree (árvore da cena) e pressione "Show Robot Window".

## Execute o seu programa {#execute-your-program}
Abra um terminal e execute os comandos a seguir, substituindo `<Your controller path>` pelo caminho do seu programa controlador.

```bash
export WEBOTS_HOME=/Applications/Webots.app
"$WEBOTS_HOME/Contents/MacOS/webots-controller" "<Your controller path>"
```

Se o Webots estiver instalado em outro lugar ou com outro nome, ajuste `WEBOTS_HOME`, por exemplo para `"/Applications/Webots R2023b.app"`.

O controlador se conecta ao Webots e espera até a partida começar.

## Inicie a partida {#start-the-game}
Pressione o botão de início na janela de controle. O robô aparece, e o seu programa começa a rodar.

## Encerre a partida {#terminate-the-game}
Para interromper a partida, pressione Ctrl+C no terminal.

Quando a simulação é encerrada, o sistema de gerenciamento de partidas do Erebus é encerrado ao mesmo tempo. Se quiser executar a partida de novo, recarregue o mundo.

# Executando o servidor da partida em outro computador
Esta é a configuração usada nas competições oficiais. O computador que executa o seu controlador (cliente) e o servidor da partida (servidor) precisam estar conectados à mesma rede.

1. (Servidor) Inicie o Webots no servidor, abra o mundo e ative o modo remoto na janela de controle.
1. (Servidor) Descubra o endereço IP do servidor. Você pode encontrá-lo em System Settings --> Network.
1. (Cliente) Execute os comandos a seguir, substituindo `<Your controller path>` pelo caminho do seu programa controlador e `<Server IP address>` pelo endereço IP que você encontrou na etapa anterior.

    ```bash
    export WEBOTS_HOME=/Applications/Webots.app
    "$WEBOTS_HOME/Contents/MacOS/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. (Servidor) Inicie a partida pressionando o botão de início.

## Solução de problemas {#troubleshooting}
- **O controlador não consegue se conectar:** confira se os dois computadores conseguem se alcançar, por exemplo com `ping`, se o firewall do servidor permite a porta TCP 1234 e se a lista de IPs permitidos na aba Network das preferências do Webots está vazia ou inclui o cliente.
- **Aparece `No robot name provided`:** essa mensagem é normal enquanto ele espera. Se ela continuar aparecendo, o modo remoto não está ativado, então confira o botão TOGGLE REMOTE.
- **O controlador não encontra uma biblioteca Python:** o programa roda com o Python do cliente, então instale a biblioteca lá.

# Documentação oficial
Se quiser conhecer a configuração em mais detalhes, você pode encontrá-la no [guia oficial](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b).
