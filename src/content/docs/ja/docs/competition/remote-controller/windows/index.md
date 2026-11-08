---
title: Windows
description: Windows での Remote Controller のセットアップガイドです。
---

# ゲームサーバーとコントローラープログラムを同じ PC で実行する
まず、ゲームサーバーとコントローラープログラムを同じ PC で実行してみましょう。実際の競技の構成とは異なりますが、ローカルでデバッグするときに役立ちます。

## リモートモードを切り替える {#toggle-remote-mode}
Robot Window（ロボットウィンドウ）で「TOGGLE REMOTE」を押して、リモートコントローラーの構成を有効にします。有効になると、ボタンの色がオレンジに変わります。  
![TOGGLE REMOTE ボタン](../../../../../docs/competition/remote-controller/windows/toggleRemote.png)

Robot Window が表示されない場合は、Scene Tree で「DEF MAINSUPERVISOR Robot」を右クリックし、「Show Robot Window」を押してください。  
![Show Robot Window の項目](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## プログラムを実行する {#execute-your-program}
PowerShell を開きます。ふつうはアプリの一覧にあります。  
![アプリの一覧にある PowerShell](../../../../../docs/competition/remote-controller/windows/powerShell.png)

PowerShell で次のコマンドを実行します。`<Your controller path>` は、コントローラープログラムのパスに置き換えてください。

`webots-controller.exe <Your controller path>`

コマンドが見つからない場合は、フルパスを使ってください。デフォルトでは `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe` です。

コントローラープログラムのパスがわからない場合は、そのファイルを PowerShell のウィンドウにドラッグ＆ドロップすると、自動的に入力されます。  
![PowerShell のウィンドウにファイルをドラッグする様子](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

コマンドを入力したら、Enter キーを押して実行します。

## ゲームを開始する {#start-the-game}
Robot Window のスタートボタンを押して、シミュレーションを開始します。  
![コントロールウィンドウのスタートボタン](../../../../../docs/competition/remote-controller/windows/run.png)

## ゲームを終了する {#terminate-the-game}
ゲームの実行を中断するには、Ctrl+C を押して PowerShell で動いているプログラムを中断します。

シミュレーションが終了すると、同時に Erebus のゲーム管理システムも終了します。もう一度ゲームを実行したい場合は、ワールドを再読み込みしてください。  
![Webots の再読み込みボタン](../../../../../docs/competition/remote-controller/windows/reload.png)

# ゲームサーバーを別の PC で実行する
これは公式の競技で使われる構成です。
コントローラーを実行する PC（クライアント）とゲームサーバー（サーバー）は、同じネットワークに接続されている必要があります。

1. （サーバー）サーバー PC で Webots を起動し、ワールドを開いて、Robot Window からリモートモードをオンにします。
2. （サーバー）その PC の IP アドレスを調べます。[こちらの記事](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9)を参考にしてください。
3. （クライアント）PowerShell で次のコマンドを実行します。`<Your controller path>` はコントローラープログラムのパスに、`<Server IP address>` は前の手順で調べた IP アドレスに置き換えてください。  
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. （サーバー）スタートボタンを押してゲームを開始します。

# トラブルシューティング
コントローラーが接続できない場合は、2 台の PC が互いに到達できること、サーバーのファイアウォールが TCP ポート 1234 を許可していること、Webots の設定（Preferences）の Network タブにある許可 IP のリストが空か、クライアントを含んでいることを確認してください。

# 公式ドキュメント
セットアップについて詳しく知りたい場合は、[公式ガイド](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b)を参照してください。
