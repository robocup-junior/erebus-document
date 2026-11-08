---
title: Erebus とは？
description: Erebus は、Webots 上に作られた RoboCupJunior のレスキューシミュレーションプラットフォームです。各部分がどう組み合わさっているかを学びましょう。
---

Erebus は、ロボットシミュレーションの競技環境です。迷路を自律的に探索し、壁のトークン（文字の被災者とコグニティブターゲット）を見つけて識別し、障害物や罠を避け、環境の地図を作るロボットのコントローラーを開発します。

Erebus は [Webots](https://cyberbotics.com/) 上に作られています。Webots はプロ向けに設計されたロボットシミュレーションプラットフォームで、産業、教育、研究の分野で広く使われています。Cyberbotics 社が 1998 年から継続して Webots を保守しています。

このプラットフォームは、主に [RoboCupJunior Rescue Simulation](https://junior.robocup.org/rescue/) 競技のために設計されています。中級者から上級者のプログラマーを対象としています。

## 全体の構成 {#how-it-fits-together}

| 構成要素 | 役割 | 入手先 |
|---|---|---|
| **Webots R2023b** | 3D ロボットシミュレーター | [Webots R2023b リリース](https://github.com/cyberbotics/webots/releases/tag/R2023b) |
| **Erebus** | ワールドと、ルールを適用してスコアを計算するゲームマネージャー（Main Supervisor） | [Erebus リリース](https://github.com/robocup-junior/erebus/releases) |
| **あなたのコントローラー** | Python または C/C++ で書いたロボットのプログラム | あなたが書きます！ |
| **Robot Customizer** | カスタムロボットを設計し、JSON ファイルとして書き出す Web ツール | [robot.erebus.rcj.cloud](https://robot.erebus.rcj.cloud/) |
| **World Editor** | 練習用のマップを描き、`.wbt` ワールドとして書き出す Web ツール | [world.erebus.rcj.cloud](https://world.erebus.rcj.cloud/) |

## 何ができますか？ {#what-can-you-do-with-it}

1. **ロボットを作る。** 予算の範囲内で、センサーとその配置を選びます。
2. **プログラムする。** コントローラーがセンサーを読み取り、人の助けなしに何をするかを判断します。
3. **実行する。** 付属のワールドや自作のワールドでテストし、スコアを確認します。
4. **競技に出る。** 地域大会、ブロック大会、世界大会など、RoboCupJunior の競技会に参加します。

すでに Erebus を知っている方は、[v26 の新機能](/docs/whats-new/)を参照してください。

## 役に立つ資料 {#useful-references}
Erebus について学ぶときや、Erebus で開発するときに役立つリンクです。
- [Webots ユーザーガイド](https://cyberbotics.com/doc/guide/index?version=R2023b)
- [Webots リファレンスマニュアル](https://cyberbotics.com/doc/reference/nodes-and-api-functions?version=R2023b)
- [Python ドキュメント](https://www.python.org/doc/)
- [C++ ドキュメント](https://www.cplusplus.com/doc/tutorial/)
- [OpenCV チュートリアル](https://docs.opencv.org/4.x/d9/df8/tutorial_root.html)
- [RCJ Rescue コミュニティサイト](https://rescue.rcj.cloud/): イベント、チーム資料、TDP・ポスター・ビデオの評価基準
- [RoboCupJunior Forum](https://junior.forum.robocup.org/): ルールの補足（Clarifications）

## 次へ {#next}
[Erebus をインストール](/docs/installation/)したら、[ルールの概要](/docs/rules/)を読んでゲームを理解しましょう。
