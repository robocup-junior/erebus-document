---
title: トラブルシューティング
description: Erebus のインストールや実行でよくある問題の解決方法です。
---

まずは Webots のコンソールを確認しましょう。ほとんどの問題は、そこにエラーメッセージが表示されます。

## インストール {#installation}

### `No module named 'cv2'` {#no-module-named-cv2}
Webots が使っている Python に OpenCV がインストールされていません。その Python に[必要なライブラリ](/docs/installation/#python-libraries)をインストールしてください。複数の Python がインストールされている場合は、下で説明する **Python command** の設定で、Webots がどれを使っているかがわかります。

### `WARNING: Python was not found` {#warning-python-was-not-found}
Webots が Python の場所を見つけられません。

1. Python の場所を調べます。macOS と Linux では、ターミナルで `which python3` を実行します。Windows では、新しいコマンドプロンプトで `python` と入力して Python が起動するかを確認します。起動しない場合は、PATH に追加するオプションにチェックを入れて、Python をインストールし直してください。
2. Webots の設定を開きます。macOS では **Webots > Preferences**、Windows と Linux では **Tools > Preferences** です。

   ![Webots のメニューにある Preferences の項目](../../../docs/troubleshooting/preferences_open.png)

3. **Python command** の欄にパスを設定します。Windows では、通常は `python` で十分です。

   ![Webots の設定にある Python command の欄](../../../docs/troubleshooting/preferences.png)

### `ERROR: Skipped PROTO 'custom_robot'` {#error-skipped-proto-custom_robot}
初めてワールドを開いたとき、Erebus がロボットモデルを準備する前に表示されます。Erebus が準備して自動でワールドを再読み込みするので、無視してかまいません。

### ゲームタイマーが表示されない {#the-game-timer-does-not-appear}
初回の起動では、Erebus がライブラリをインストールするので数分かかることがあります。いつまでも終わらない場合は、コンソールにエラーがないか確認してください。自動インストールがうまくいかない場合は、[必要なライブラリ](/docs/installation/#python-libraries)を自分でインストールしてください。

## Erebus の実行 {#running-erebus}

### コントロールウィンドウが表示されない {#the-control-window-does-not-appear}
コントロールウィンドウは、Webots が開く Web ページです。

1. ウィンドウを閉じてしまったか、ブラウザーがブロックした場合は、Webots の再読み込みボタンでワールドを再読み込みします。Erebus がコントロールウィンドウをもう一度開きます。
2. そうでない場合は、**Tools > Scene Tree** で Scene Tree が表示されていることを確認します。
3. Scene Tree で **DEF MAINSUPERVISOR Robot** を見つけて右クリックし、**Show Robot Window** を選びます。

コントロールウィンドウには、ワールドを読み込むたびに変わる専用のアドレスがあります。自分で `localhost:1234` のウィンドウを開くと **Read-only** と表示され、ボタンは動きません。

### コントロールウィンドウに「Access log incomplete」と表示される {#the-control-window-says-access-log-incomplete}
この警告は、[Wireshark](/docs/installation/#optional-wireshark) がインストールされていないときに表示されます。大会で運営者が使うためのものなので、**Acknowledge** を押して、いつもどおり練習してください。

![Scene Tree にある Show Robot Window の項目](../../../docs/troubleshooting/showrobot.png)

### Webots の画面が真っ白または真っ黒になる {#the-webots-screen-is-blank-or-black}
ワールドを開く前に、ダウンロードしたファイルをコピーして、別のフォルダーに展開してください。

### シミュレーションの動作が遅すぎる {#the-simulation-runs-too-slowly}
おそらくコンピューターの性能によるものです。グラフィックスの品質を下げると改善することがあります。

1. Webots の設定を開きます。
2. **OpenGL** タブを開きます。
3. 設定を変更します。

![Webots の設定の OpenGL タブ](../../../docs/troubleshooting/opengl.png)

これらの設定はカメラに写るものを変えます。競技では[独自の設定](/docs/competition/#opengl-settings)が使われるので、その設定でもプログラムを確認してください。

## ロボット {#your-robot}

### デバイスが見つからないとプログラムに表示される {#my-program-says-a-device-was-not-found}
下を参照してください。また、ゲームを開始する前に、**Robot setup** の **Robot JSON** でロボットを読み込んだか確認してください。

## プログラム {#your-program}

### `Device "..." was not found` {#device--was-not-found}
プログラムのデバイス名がロボットと一致していません。スターターロボットの名前は[リファレンス](/docs/reference/parameters/#device-names-of-the-starter-robot)に載っています。自作のロボットの場合は、[Robot Customizer](/docs/robot/customizer/) で設定した名前です。ロボットが読み込まれていることも確認してください。

### 壁のトークンを報告しても何も起こらない {#nothing-happens-when-i-report-a-wall-token}
コントロールウィンドウの **Advanced setup** で **Enable debugging** をオンにして、コンソールを確認してください。よくある原因は、ロボットが 1 秒以上止まっていなかったこと、座標をセンチメートルに変換していなかったこと、ロボットや位置がトークンからタイル半分（6 cm）より離れていたことです。[通信](/docs/programming/communication/#scoring-wall-tokens)を参照してください。

### 報告が誤識別になる {#my-reports-are-misidentifications}
ロボットはトークンからタイル半分以内で、壁の同じ側にいる必要があります。また、各トークンで得点できるのは 1 回だけです。偽物を報告した場合も誤識別になります。

### ゲームが「Battery depleted」で終わる {#the-game-ends-with-battery-depleted}
バッテリーが切れました。その前に、コンタクトタイルの上で 5 秒間止まってバッテリーを交換しましょう。[バッテリー](/docs/programming/battery/)を参照してください。

### プログラムがゲーム情報を受け取れなくなった {#my-program-no-longer-receives-the-game-information}
Erebus v27 から、`G` への返信は 20 バイトになり、最後にバッテリー残量が入っています。プログラムの長さのチェックを更新してください。[ゲーム情報](/docs/programming/communication/#game-information)を参照してください。

### 地図が 0% になる、または得点計算エラーになる {#the-map-gets-0-or-a-scoring-error}
地図にはスタートタイル（`5`）が含まれている必要があり、評価されるのは 1 回だけです。[地図の提出](/docs/programming/map-bonus/)を参照してください。

### リモートモードでコントローラーが接続できない {#the-controller-cannot-connect-in-remote-mode}
お使いの OS 向けの [Remote Controller](/docs/competition/remote-controller/) のガイドを参照してください。

## それでも解決しない場合 {#still-stuck}
[Discord サーバー](https://discord.com/invite/6FJxZxk)で質問するか、[Issue を作成](https://github.com/robocup-junior/erebus/issues)してください。OS、Erebus と Webots のバージョン、コンソールのメッセージを書き添えてください。
