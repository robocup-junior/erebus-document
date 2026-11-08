---
title: Windows
description: Como configurar o Remote Controller no Windows.
---

# Executando o servidor da partida e o programa controlador no mesmo computador
Primeiro, tente executar o servidor da partida e o seu programa controlador no mesmo computador. Essa não é a configuração usada nas competições, mas é útil para depurar localmente.

## Ative o modo remoto {#toggle-remote-mode}
Abra o mundo e pressione "TOGGLE REMOTE" na janela de controle. O botão fica laranja para mostrar que o modo remoto está ativado.  
![O botão TOGGLE REMOTE](../../../../../docs/competition/remote-controller/windows/toggleRemote.png)

Se a janela de controle não aparecer, clique com o botão direito em "DEF MAINSUPERVISOR Robot" na Scene Tree (árvore da cena) e escolha "Show Robot Window".  
![A opção Show Robot Window](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## Execute o seu programa {#execute-your-program}
Abra o PowerShell. Normalmente você o encontra na lista de aplicativos.  
![O PowerShell na lista de aplicativos](../../../../../docs/competition/remote-controller/windows/powerShell.png)

Execute o comando a seguir no PowerShell, substituindo `<Your controller path>` pelo caminho do seu programa controlador.

`webots-controller.exe <Your controller path>`

Se o comando não for encontrado, use o caminho completo dele, que por padrão é `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe`.

Se você não souber o caminho do seu programa controlador, arraste e solte o arquivo na janela do PowerShell, e o caminho será preenchido automaticamente.  
![Arrastando um arquivo para a janela do PowerShell](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

Depois, pressione Enter para executar o comando. O controlador se conecta ao Webots e espera até a partida começar.

## Inicie a partida {#start-the-game}
Pressione o botão de início na janela de controle para iniciar a simulação.  
![O botão de início da janela de controle](../../../../../docs/competition/remote-controller/windows/run.png)

## Encerre a partida {#terminate-the-game}
Para parar a partida, pressione Ctrl+C no PowerShell para interromper o seu programa.

Quando a simulação termina, o gerenciador da partida do Erebus também para. Para executar a partida de novo, recarregue o mundo.  
![O botão de recarregar do Webots](../../../../../docs/competition/remote-controller/windows/reload.png)

# Executando o servidor da partida em outro computador
Esta é a configuração usada nas competições oficiais. O computador que executa o seu controlador (o cliente) e o que executa a partida (o servidor) precisam estar conectados à mesma rede.

1. (Servidor) Inicie o Webots no servidor, abra o mundo e ative o modo remoto na janela de controle.
2. (Servidor) Descubra o endereço IP do servidor. Veja [Localizar seu endereço IP no Windows](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9).
3. (Cliente) Execute o comando a seguir no PowerShell, substituindo `<Your controller path>` pelo caminho do seu programa controlador e `<Server IP address>` pelo endereço IP que você encontrou na etapa anterior.  
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. (Servidor) Inicie a partida pressionando o botão de início.

# Solução de problemas
Se o controlador não conseguir se conectar, confira se os dois computadores conseguem se comunicar, se o firewall do servidor permite a porta TCP 1234 e se a lista de IPs permitidos na aba Network das preferências do Webots está vazia ou inclui o cliente.

# Documentação oficial
Para mais detalhes sobre essa configuração, consulte o [guia do Webots](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b).
