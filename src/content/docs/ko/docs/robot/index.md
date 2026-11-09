---
title: 로봇 준비하기
description: 모든 프로그램은 여러분이 설계한 로봇에서 실행돼요. 스타터 로봇을 다운로드하거나 직접 조립하세요.
---

Erebus에서는 **로봇을 직접 설계해요**. 예산 안에서 센서와 그 위치를 골라요. 모든 프로그램에는 로봇이 필요하므로, 첫 단계는 로봇을 준비해서 Erebus에 불러오는 거예요.

![실제 e-puck 로봇](../../../docs/robot/real_robot.thumbnail.jpg)

로봇은 바퀴가 두 개 달린 작고 둥근 교육용 로봇인 [e-puck](https://cyberbotics.com/doc/guide/epuck?version=R2025a)을 바탕으로 해요. [Robot Customizer](https://robot.erebus.rcj.cloud/)로 센서를 추가하고, 설계를 Erebus가 불러오는 `.json` 파일로 저장해요.

## 스타터 로봇 {#the-starter-robot}
이 문서에서는 모든 예제가 그대로 작동하도록 어디서나 같은 로봇, **스타터 로봇**을 사용해요. 튜토리얼에 필요한 센서가 모두 달려 있어요.

| 구성 요소 | 프로그램에서의 이름 | 용도 |
|---|---|---|
| 바퀴 두 개 | `left wheel motor`, `right wheel motor` | 이동 |
| 바퀴 인코더 | `left wheel sensor`, `right wheel sensor` | 바퀴가 얼마나 돌았는지 측정 |
| 거리 센서 세 개 | `leftDist`, `frontDist`, `rightDist` | 왼쪽, 앞쪽, 오른쪽의 벽 찾기 |
| 카메라, 64 × 40 픽셀 | `camera` | 벽 토큰 찾기 |
| 컬러 센서 | `color` | 바닥 보기: 구멍, 늪, 접촉 타일, 통로 |
| GPS | `gps` | 토큰을 보고하기 위해 자신의 위치 알기 |
| 자이로 | `gyro` | 얼마나 회전했는지 측정 |
| 가속도계 | `accelerometer` | 가속도 측정 |
| 라이다 | `lidar` | 주위 전체의 거리 측정 |
| 이미터와 리시버 | `emitter`, `receiver` | 게임과 통신. 모든 로봇에 있어요. |

예산 3000 중 2400을 사용해요.

![레이블과 카메라 뷰가 표시된 완성된 로봇](../../../docs/robot/build/finished.png)

## 방법 선택하기 {#choose-your-path}

**추천: 직접 조립하기.** 약 15분 걸리고, 로봇의 모든 부분을 이해할 수 있어요. [로봇 조립하기](/docs/robot/build/)를 따라 하세요.

**급하다면:** 완성된 로봇을 다운로드하고 튜토리얼을 계속하세요. 나중에 언제든 돌아와서 조립할 수 있어요.

<a href="/downloads/starter-robot.json" download>starter-robot.json 다운로드</a>

## Erebus에 불러오기 {#load-it-in-erebus}
1. `game/worlds/world1.wbt` 같은 월드를 여세요.
2. 제어 창에서 **Robot setup**을 누른 다음, **Robot JSON** 아래의 **Load file**을 눌러 `.json` 파일을 선택하세요.
3. Webots 콘솔을 확인하세요. Erebus가 각 부품과 그 비용을 나열하고, 마지막에 `Your custom robot has been successfully generated!`와 사용한 예산을 보여 줘요.

로봇은 다른 로봇을 불러올 때까지 불러온 상태로 남아요. 기본으로 켜져 있는 **Keep files after Reset** 덕분에 게임을 리셋해도 그대로 남아 있어요. 다음은 [첫 번째 프로그램 실행](/docs/getting-started/)이에요.

## 나만의 로봇 설계하기 {#designing-your-own}
기초를 익히고 나면 스타터 로봇을 바꾸거나 새 로봇을 설계해 보세요. 해상도가 더 높은 카메라를 더 달거나, 거리 센서를 늘리거나, 센서를 다른 곳에 배치할 수 있어요. [Robot Customizer 레퍼런스](/docs/robot/customizer/)에 모든 구성 요소와 비용, 제한이 나와 있어요.

구성 요소의 이름을 바꾸면 프로그램에서도 바꾸세요.
