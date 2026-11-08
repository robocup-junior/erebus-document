---
title: macOS
description: macOS での Remote Controller のセットアップガイドです。
---

# ゲームサーバーとコントローラープログラムを同じコンピューターで実行する
まず、ゲームサーバーとコントローラープログラムを同じコンピューターで実行してみましょう。実際の競技の構成とは異なりますが、ローカルでデバッグするときに役立ちます。

## リモートモードを切り替える {#toggle-remote-mode}
ワールドを開き、コントロールウィンドウで「TOGGLE REMOTE」を押します。有効になると、ボタンの色がオレンジに変わります。

![オンになった TOGGLE REMOTE ボタン](../../../../../docs/competition/remote-controller/mac/toggle_remote.png)

コントロールウィンドウが表示されない場合は、Scene Tree で「DEF MAINSUPERVISOR Robot」を右クリックし、「Show Robot Window」を押してください。

## プログラムを実行する {#execute-your-program}
ターミナルを開き、次のコマンドを実行します。`<Your controller path>` は、コントローラープログラムのパスに置き換えてください。

```bash
export WEBOTS_HOME=/Applications/Webots.app
"$WEBOTS_HOME/Contents/MacOS/webots-controller" "<Your controller path>"
```

Webots を別の場所や別の名前でインストールした場合は、`WEBOTS_HOME` をそれに合わせて変更してください。たとえば `"/Applications/Webots R2023b.app"` です。

コントローラーは Webots に接続し、ゲームが始まるまで待機します。

## ゲームを開始する {#start-the-game}
コントロールウィンドウのスタートボタンを押します。ロボットが現れ、プログラムが動き始めます。

## ゲームを終了する {#terminate-the-game}
ゲームを中断するには、ターミナルで Ctrl+C を押します。

シミュレーションが終了すると、同時に Erebus のゲーム管理システムも終了します。もう一度ゲームを実行したい場合は、ワールドを再読み込みしてください。

# ゲームサーバーを別のコンピューターで実行する
これは公式の競技で使われる構成です。コントローラーを実行するコンピューター（クライアント）とゲームサーバー（サーバー）は、同じネットワークに接続されている必要があります。

1. （サーバー）サーバーで Webots を起動し、ワールドを開いて、コントロールウィンドウでリモートモードをオンにします。
1. （サーバー）サーバーの IP アドレスを調べます。System Settings（システム設定）--> Network（ネットワーク）で確認できます。
1. （クライアント）次のコマンドを実行します。`<Your controller path>` はコントローラープログラムのパスに、`<Server IP address>` は前の手順で調べた IP アドレスに置き換えてください。

    ```bash
    export WEBOTS_HOME=/Applications/Webots.app
    "$WEBOTS_HOME/Contents/MacOS/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. （サーバー）スタートボタンを押してゲームを開始します。

## トラブルシューティング {#troubleshooting}
- **コントローラーが接続できない:** たとえば `ping` で 2 台のコンピューターが互いに到達できること、サーバーのファイアウォールが TCP ポート 1234 を許可していること、Webots の設定（Preferences）の Network タブにある許可 IP のリストが空か、クライアントを含んでいることを確認してください。
- **`No robot name provided` と表示される:** 待機中はこのメッセージが表示されるのが正常です。表示され続ける場合はリモートモードがオンになっていないので、TOGGLE REMOTE ボタンを確認してください。
- **コントローラーが Python ライブラリを見つけられない:** プログラムはクライアントの Python で実行されるので、ライブラリはクライアントにインストールしてください。

# 公式ドキュメント
セットアップについて詳しく知りたい場合は、[公式ガイド](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b)を参照してください。
