---
title: ロボットを用意する
description: どのプログラムも、あなたが設計したロボットの上で動きます。スターターロボットをダウンロードするか、自分で組み立てましょう。
---

Erebus では、**ロボットを自分で設計します**。予算の範囲内で、センサーとその配置を選びます。どのプログラムにもロボットが必要なので、まずはロボットを用意して Erebus に読み込みましょう。

![本物の e-puck ロボット](../../../docs/robot/real_robot.thumbnail.jpg)

ロボットは、2 つの車輪を持つ小さな丸い教育用ロボット [e-puck](https://cyberbotics.com/doc/guide/epuck?version=R2025a) をもとにしています。[Robot Customizer](https://robot.erebus.rcj.cloud/) でセンサーを追加し、その設計を Erebus が読み込む `.json` ファイルとして保存します。

## スターターロボット {#the-starter-robot}
すべての例がそのまま動くように、このドキュメントではどこでも 1 台のロボット、**スターターロボット** を使います。チュートリアルに必要なセンサーがすべて付いています。

| 構成要素 | プログラムでの名前 | 用途 |
|---|---|---|
| 2 つの車輪 | `left wheel motor`、`right wheel motor` | 移動 |
| 車輪のエンコーダー | `left wheel sensor`、`right wheel sensor` | 車輪が回った量を測る |
| 3 つの距離センサー | `leftDist`、`frontDist`、`rightDist` | 左、前、右の壁を見つける |
| カメラ（64 × 40 ピクセル） | `camera` | 壁のトークンを見つける |
| カラーセンサー | `color` | 床（穴、沼地、コンタクトタイル、通路）を見る |
| GPS | `gps` | トークンを報告するために自分の位置を知る |
| ジャイロ | `gyro` | 回転した量を測る |
| 加速度センサー | `accelerometer` | 加速度を測る |
| LiDAR | `lidar` | 周囲全体の距離を測る |
| エミッターとレシーバー | `emitter`、`receiver` | ゲームとやり取りする。すべてのロボットに付いています。 |

コストは、予算 3000 のうち 2400 です。

![ラベルとカメラビューを表示した、完成したロボット](../../../docs/robot/build/finished.png)

## 進め方を選ぶ {#choose-your-path}

**おすすめ: 自分で組み立てる。** 15 分ほどで終わり、ロボットのすべての部分を理解できます。[ロボットを組み立てる](/docs/robot/build/)に従って進めてください。

**急いでいる場合:** 完成したロボットをダウンロードして、チュートリアルに進みましょう。後でいつでも戻って組み立てられます。

<a href="/downloads/starter-robot.json" download>starter-robot.json をダウンロード</a>

## Erebus に読み込む {#load-it-in-erebus}
1. `game/worlds/world1.wbt` などのワールドを開きます。
2. コントロールウィンドウで **Robot setup** を押し、**Robot JSON** の **Load file** を押して、`.json` ファイルを選びます。
3. Webots のコンソールを確認します。Erebus は各部品とそのコストを一覧表示し、最後に `Your custom robot has been successfully generated!` と使った予算を表示します。

ロボットは、別のロボットを読み込むまで読み込まれたままです。初期設定でオンになっている **Keep files after Reset** により、ゲームをリセットしても読み込まれたままです。次は、[初めてのプログラムを実行](/docs/getting-started/)しましょう。

## 自分で設計する {#designing-your-own}
基本がわかったら、スターターロボットを変更したり、新しいロボットを設計したりしましょう。より高解像度のカメラを増やしたり、距離センサーを増やしたり、センサーを別の場所に付けたりできます。[Robot Customizer リファレンス](/docs/robot/customizer/)に、すべての構成要素とそのコスト、制限が載っています。

構成要素の名前を変えたら、プログラムの中の名前も変えてください。
