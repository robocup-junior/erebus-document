---
title: Windows
description: Windows で Remote Controller をセットアップする方法です。
---

# ゲームサーバーとコントローラープログラムを同じコンピューターで実行する
まず、ゲームサーバーと自分のコントローラープログラムを同じコンピューターで実行してみましょう。競技での構成とは異なりますが、ローカルでデバッグするときに便利です。

## リモートモードを切り替える {#toggle-remote-mode}
ワールドを開き、コントロールウィンドウで **Robot setup** を押して、**Remote mode** をオンにします。カスタムロボットがある場合は、先に **Robot JSON** でロボットを読み込んでおきます。  
![Robot setup で Remote mode をオンにしたところ](../../../../../docs/competition/remote-controller/windows/../mac/toggle_remote.png)

コントロールウィンドウが表示されない場合は、Scene Tree で「DEF MAINSUPERVISOR Robot」を右クリックし、「Show Robot Window」を選んでください。  
![Show Robot Window の項目](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## プログラムを実行する {#execute-your-program}
PowerShell を開きます。通常はアプリの一覧にあります。  
![アプリの一覧にある PowerShell](../../../../../docs/competition/remote-controller/windows/powerShell.png)

PowerShell で次のコマンドを実行します。`<Your controller path>` は、コントローラープログラムのパスに置き換えてください。

`webots-controller.exe <Your controller path>`

コマンドが見つからない場合は、フルパスを使ってください。デフォルトでは `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe` です。

コントローラープログラムのパスがわからない場合は、そのファイルを PowerShell のウィンドウにドラッグ＆ドロップすると、パスが自動で入力されます。  
![PowerShell のウィンドウにファイルをドラッグする様子](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

Enter キーを押してコマンドを実行します。コントローラーは Webots に接続し、ゲームが始まるまで待機します。

## ゲームを開始する {#start-the-game}
コントロールウィンドウで **Run match** を押して、ゲームを開始します。  
![コントロールウィンドウの Run match ボタン](../../../../../docs/competition/remote-controller/windows/../../../getting-started/match-controls.png)

## ゲームを終了する {#terminate-the-game}
ゲームを止めるには、PowerShell で Ctrl+C を押してプログラムを停止します。

ゲームが終わったら、**Reset** を押すともう一度実行できます。**Keep on Reset** がオンでなければ、リセットで Remote mode はオフになります。

# ゲームサーバーを別のコンピューターで実行する
これは公式の競技で使われる構成です。コントローラーを実行するコンピューター（クライアント）と、ゲームを実行するコンピューター（サーバー）は、同じネットワークに接続されている必要があります。

2. （サーバー）サーバーで Webots を起動してワールドを開き、コントロールウィンドウの **Robot setup** で **Remote mode** をオンにします。
2. （サーバー）サーバーの IP アドレスを調べます。[Windows で IP アドレスを確認する](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9)を参照してください。
3. （クライアント）PowerShell で次のコマンドを実行します。`<Your controller path>` はコントローラープログラムのパスに、`<Server IP address>` は前の手順で調べた IP アドレスに置き換えてください。  
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. （サーバー）**Run match** を押してゲームを開始します。

# トラブルシューティング
コントローラーが接続できない場合は、2 台のコンピューターが互いに通信できること、サーバーのファイアウォールが TCP ポート 1234 を許可していること、Webots の設定（Preferences）の Network タブにある許可 IP のリストが空か、クライアントを含んでいることを確認してください。

# 公式ドキュメント
この構成について詳しくは、[Webots のガイド](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a)を参照してください。
