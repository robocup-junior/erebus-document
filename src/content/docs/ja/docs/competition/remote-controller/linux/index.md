---
title: Linux (Ubuntu)
description: Linux（Ubuntu 22.04 LTS）で Remote Controller をセットアップする方法です。
---

# ゲームサーバーとコントローラープログラムを同じコンピューターで実行する
まず、ゲームサーバーと自分のコントローラープログラムを同じコンピューターで実行してみましょう。競技での構成とは異なりますが、ローカルでデバッグするときに便利です。

## リモートモードを切り替える {#toggle-remote-mode}
ワールドを開き、コントロールウィンドウで **Robot setup** を押して、**Remote mode** をオンにします。カスタムロボットがある場合は、先に **Robot JSON** でロボットを読み込んでおきます。

![Robot setup で Remote mode をオンにしたところ](../../../../../docs/competition/remote-controller/linux/toggle_remote.png)

コントロールウィンドウが表示されない場合は、Scene Tree で「DEF MAINSUPERVISOR Robot」を右クリックし、「Show Robot Window」を選んでください。

## プログラムを実行する {#execute-your-program}
ターミナルを開き、次のコマンドを実行します。`<Your controller path>` は、コントローラープログラムのパスに置き換えてください。

```bash
export WEBOTS_HOME=/usr/local/webots
"$WEBOTS_HOME/webots-controller" "<Your controller path>"
```

これは、Webots を `.deb` パッケージで `/usr/local/webots` にインストールした場合です。別の場所にインストールした場合は、`WEBOTS_HOME` をそれに合わせて変更してください。

コントローラーは Webots に接続し、ゲームが始まるまで待機します。

## ゲームを開始する {#start-the-game}
コントロールウィンドウで **Run match** を押します。ロボットが現れ、プログラムが動き始めます。

## ゲームを終了する {#terminate-the-game}
ゲームを止めるには、ターミナルで Ctrl+C を押します。

ゲームが終わったら、**Reset** を押すともう一度実行できます。**Keep on Reset** がオンでなければ、リセットで Remote mode はオフになります。

# ゲームサーバーを別のコンピューターで実行する
これは公式の競技で使われる構成です。コントローラーを実行するコンピューター（クライアント）と、ゲームを実行するコンピューター（サーバー）は、同じネットワークに接続されている必要があります。

1. （サーバー）サーバーで Webots を起動してワールドを開き、コントロールウィンドウの **Robot setup** で **Remote mode** をオンにします。
1. （サーバー）サーバーの IP アドレスを調べます。たとえば `ip addr` コマンドで確認できます。
1. （クライアント）次のコマンドを実行します。`<Your controller path>` はコントローラープログラムのパスに、`<Server IP address>` は前の手順で調べた IP アドレスに置き換えてください。

    ```bash
    export WEBOTS_HOME=/usr/local/webots
    "$WEBOTS_HOME/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. （サーバー）**Run match** を押してゲームを開始します。

## トラブルシューティング {#troubleshooting}
- **コントローラーが接続できない:** 2 台のコンピューターが互いに通信できること（`ping` などで確認できます）、サーバーのファイアウォールが TCP ポート 1234 を許可していること、Webots の設定（Preferences）の Network タブにある許可 IP のリストが空か、クライアントを含んでいることを確認してください。
- **コントローラーは待っているのに、ロボットが動かない:** **Remote mode** がオンになっているか確認して、**Run match** を押してください。
- **コントローラーが Python ライブラリを見つけられない:** プログラムはクライアントの Python で実行されるので、ライブラリはクライアントにインストールしてください。

# 公式ドキュメント
この構成について詳しくは、[Webots のガイド](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a)を参照してください。
