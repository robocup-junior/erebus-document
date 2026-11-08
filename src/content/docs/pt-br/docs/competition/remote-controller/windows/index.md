---
title: Windows
description: Guia de configuração do Remote Controller para Windows.
---

# Executando o servidor da partida e o programa controlador no mesmo PC
Primeiro, vamos tentar executar o servidor da partida e o programa controlador no mesmo PC. Isso não é igual à configuração de uma competição real, mas vai ajudar você na hora de depurar localmente.

## Ative o modo remoto {#toggle-remote-mode}
Pressione "TOGGLE REMOTE" na Robot Window (janela do robô) para ativar a configuração de controle remoto. A cor do botão deve ficar laranja, indicando que ele está ativado.  
![O botão TOGGLE REMOTE](../../../../../docs/competition/remote-controller/windows/toggleRemote.png)

Se a Robot Window não aparecer, clique com o botão direito em "DEF MAINSUPERVISOR Robot" na Scene Tree (árvore da cena) e pressione "Show Robot Window".  
![A opção Show Robot Window](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## Execute o seu programa {#execute-your-program}
Abra o PowerShell. Normalmente você o encontra na lista de aplicativos.  
![O PowerShell na lista de aplicativos](../../../../../docs/competition/remote-controller/windows/powerShell.png)

Execute o comando a seguir no PowerShell, substituindo `<Your controller path>` pelo caminho do seu programa controlador.

`webots-controller.exe <Your controller path>`

Se o comando não for encontrado, use o caminho completo, que por padrão é `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe`.

Se você não souber o caminho do seu programa controlador, pode arrastar e soltar o arquivo na janela do PowerShell, e ele será preenchido automaticamente.  
![Arrastando um arquivo para a janela do PowerShell](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

Depois de digitar o comando, pressione Enter para executá-lo.

## Inicie a partida {#start-the-game}
Pressione o botão de início na Robot Window para iniciar a simulação.  
![O botão de início da janela de controle](../../../../../docs/competition/remote-controller/windows/run.png)

## Encerre a partida {#terminate-the-game}
Para interromper a execução da partida, interrompa o programa que está rodando no PowerShell pressionando Ctrl+C.

Quando a simulação é encerrada, o sistema de gerenciamento de partidas do Erebus é encerrado ao mesmo tempo. Se quiser executar a partida de novo, recarregue o mundo.  
![O botão de recarregar do Webots](../../../../../docs/competition/remote-controller/windows/reload.png)

# Executando o servidor da partida em outro PC
Esta é a configuração usada nas competições oficiais.
O PC que executa o seu controlador (cliente) e o servidor da partida (servidor) precisam estar conectados à mesma rede.

1. (Servidor) Inicie o Webots no PC servidor, abra o mundo e ative o modo remoto na Robot Window.
2. (Servidor) Descubra o endereço IP desse PC. Você pode consultar [este artigo como referência](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9).
3. (Cliente) Execute o comando a seguir no PowerShell, substituindo `<Your controller path>` pelo caminho do seu programa controlador e `<Server IP address>` pelo endereço IP que descobrimos na etapa anterior.   
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. (Servidor) Inicie a partida pressionando o botão de início.

# Solução de problemas
Se o controlador não conseguir se conectar, confira se os dois PCs conseguem se alcançar, se o firewall do servidor permite a porta TCP 1234 e se a lista de IPs permitidos na aba Network das preferências do Webots está vazia ou inclui o cliente.

# Documentação oficial
Se quiser conhecer a configuração em mais detalhes, você pode encontrá-la no [guia oficial](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b).
