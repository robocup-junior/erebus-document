---
title: よくある質問
description: Erebus と競技についてよくある質問です。
---

## Erebus について {#about-erebus}

### 本物のロボットは必要ですか？ {#do-i-need-a-real-robot}
いいえ。すべてシミュレーターの中で行います。ロボットは、あなたが設計する仮想の e-puck です。

### どのプログラミング言語を使えますか？ {#which-programming-languages-can-i-use}
このドキュメントでは Python と C/C++ を扱っています。Erebus は Java や MATLAB のコントローラーも読み込めますが、このドキュメントにはそれらの例はありません。

### 高性能なコンピューターが必要ですか？ {#do-i-need-a-powerful-computer}
いいえ。[動作環境](/docs/installation/)を参照してください。遅いコンピューターでは、[グラフィックスの設定を下げる](/docs/troubleshooting/#the-simulation-runs-too-slowly)必要があるかもしれません。

### 新しいバージョンの Webots を使えますか？ {#can-i-use-a-newer-version-of-webots}
いいえ。Erebus v26 は Webots **R2023b** で動作します。ほかのバージョンを並べてインストールしておくことはできます。

### OpenCV や NumPy などのライブラリを使えますか？ {#can-i-use-libraries-like-opencv-or-numpy}
はい。作成者のクレジットを表記し、ライセンスを守れば、外部のコードを使えます。チームは学ぶことを優先し、自分たちの解決策のしくみを説明できなければなりません。

## ゲーム {#the-game}

### どの順番で学ぶのがいちばんよいですか？ {#what-is-the-best-order-to-learn-things}
[学習の道のり](/docs/#the-learning-path)に従ってください。ゲームを理解し、ロボットを用意して実行し、基本を学んでから、ゲームをプレイします。

### プログラミングの前にロボットを作る必要がありますか？ {#do-i-need-to-make-a-robot-before-programming}
はい。どのプログラムも読み込んだロボットの上で動くので、[ロボットを用意する](/docs/robot/)から始めてください。急いでいる場合は、完成したスターターロボットをダウンロードできます。

### ロボットはどこからスタートしますか？ {#where-does-the-robot-start}
エリア 1 にあるスタートタイルからです。ロボットは常に、壁のない方向を向いています。

### ロボットが穴に落ちるとどうなりますか？ {#what-happens-if-the-robot-falls-into-a-hole}
競技進行停止（Lack of Progress）になります。ロボットは最後に訪れたチェックポイントに戻り、5 点を失います。

### ロボットはスタートに戻らなければなりませんか？ {#does-the-robot-have-to-return-to-the-start}
いいえ。ただし、壁のトークンを 1 つ以上識別していれば、スタートタイルに戻って `E` を送ることで 10% の脱出ボーナス（Exit bonus）が得られます。

### ロボットは残り時間をどうやって知るのですか？ {#how-can-my-robot-tell-how-much-time-is-left}
[`G` メッセージ](/docs/programming/communication/#game-information)を使います。タイマーは 2 つあり、沼地ではゲーム時間が速く進みます。

### エリア 4 を探索しなければなりませんか？ {#do-i-have-to-explore-area-4}
いいえ。任意ですが、エリア 4 のトークンはいちばん価値があります。点数が最も高く、さらに 2 倍されます。

### エリア 4 の地図を作らなければなりませんか？ {#do-i-have-to-map-area-4}
いいえ。エリア 4 のセルはすべて `*` なので、それで埋めるだけで十分です。

### ロボットは事前に地図を知っていてもよいですか？ {#can-my-robot-know-the-map-beforehand}
いいえ。フィールドや壁のトークンの位置を事前にマッピングすることは禁止されています。

## 競技 {#the-competition}

### どうすれば参加できますか？ {#how-do-i-take-part}
地域の RoboCupJunior 競技会を通じて参加します。世界大会の出場枠は、各地域の代表者（Regional Representative）が割り当てます。[RoboCupJunior のウェブサイト](https://junior.robocup.org/)を参照してください。

### 何を準備すればよいですか？ {#what-should-i-prepare}
[競技の準備](/docs/competition/)を参照してください。

### ルールについてはどこで質問できますか？ {#where-can-i-ask-about-the-rules}
[RoboCupJunior Forum](https://junior.forum.robocup.org/) で質問できます。ルールの補足（Clarifications）もそこに投稿されるので、定期的に確認してください。
