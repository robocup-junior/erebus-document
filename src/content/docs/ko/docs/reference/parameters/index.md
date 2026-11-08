---
title: 파라미터 레퍼런스
description: 경기장 크기, 게임 시간, 점수 배율, 로봇 제한, 스타터 로봇의 장치 이름.
---

## 경기장 {#field}

| 파라미터 | 값 |
|---|---|
| 타일 | 12 cm × 12 cm |
| 4분의 1 타일 (구역 2와 3) | 6 cm × 6 cm |
| 벽 | 두께 1 cm, 높이 6 cm |
| 문자 피해자 | 2 cm × 2 cm |
| 인지 표적 | 지름 5 cm |

## 게임 {#game}

| 파라미터 | 값 |
|---|---|
| 게임 시간 | 시뮬레이션 시간 8분 |
| 실제 시간 | 10분 |
| 자동 진행 불능 (Lack of Progress) | 한 위치에 20초 동안 머무른 후 |
| 벽 토큰을 보고하기 위한 정지 시간 | 최소 1초 |
| 늪 안에서의 시간 배율 | 처음 들어갈 때 x5, 같은 늪에 새로 들어갈 때마다 +1, 최대 x10 |
| 구역 배율 | 구역 1, 2, 3, 4에 각각 1, 1.25, 1.5, 2 |
| 탈출 보너스 | +10% |
| 지도 보너스 배율 | 정확도 × 1.2 + 1 |

## 로봇 {#robot}

| 파라미터 | 값 |
|---|---|
| 예산 | 3000 |
| 최대 카메라 수 | 3 |
| 최대 거리 센서 수 | 8 |
| 거리 센서 범위 | 0 ~ 0.8 m |
| GPS 정확도 | 0.0025 m |
| 최대 바퀴 속도 | 6.28 rad/s |
| 라이다 | 레이어당 512개 점, 4개 레이어, 0.01 ~ 1 m |

`timeStep`은 센서 업데이트 사이의 밀리초 수를 정해요. `int(robot.getBasicTimeStep())`은 월드의 기본 타임 스텝을 가져오며, Erebus v26.1의 월드에서는 16 ms예요.

## 스타터 로봇의 장치 이름 {#device-names-of-the-starter-robot}

[스타터 로봇](/docs/robot/)에서 `robot.getDevice()`에 넘기는 이름이에요. 직접 만든 로봇에서는 [Robot Customizer](/docs/robot/customizer/#components)에서 이름을 정해요. 이미터(emitter)와 리시버(receiver)는 항상 사용할 수 있어요.

| 장치 | 이름 |
|---|---|
| 바퀴 모터 | `left wheel motor`, `right wheel motor` |
| 바퀴 인코더 | `left wheel sensor`, `right wheel sensor` |
| 거리 센서 | `leftDist`, `frontDist`, `rightDist` |
| 카메라 | `camera` |
| 컬러 센서 | `color` |
| GPS | `gps` |
| 자이로스코프 | `gyro` |
| 가속도계 | `accelerometer` |
| 라이다 | `lidar` |
| 이미터 | `emitter` |
| 리시버 | `receiver` |
