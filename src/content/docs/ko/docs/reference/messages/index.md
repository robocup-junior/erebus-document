---
title: 메시지 레퍼런스
description: Main Supervisor와 주고받는 메시지의 레퍼런스.
---

메시지는 `emitter` 장치로 보내고 `receiver` 장치로 받아요. 예제는 [통신 튜토리얼](/docs/programming/communication/)을 참고하세요.

아래의 형식 문자열은 Python [struct](https://docs.python.org/3/library/struct.html) 모듈의 형식이에요.

## 로봇이 보내는 메시지 {#sent-by-the-robot}

| 메시지 | 형식 | 길이 | 용도 |
|---|---|---|---|
| 벽 토큰 보고 | `i i c`: x, z, 종류 | 9바이트 | 위치는 센티미터 단위이고, 종류는 `H`, `S`, `U`, `F`, `P`, `C`, `O` 중 하나예요. 로봇은 최소 1초 동안 정지해 있어야 해요. |
| 지도 데이터 | `2i` 뒤에 UTF-8 텍스트: 행 수, 열 수, 쉼표로 구분된 셀 | 그 외의 모든 길이 | 지도를 평가하지 않고 저장해요 |
| `M` | `c` | 1바이트 | 저장된 지도를 평가해요. 한 번만 할 수 있어요. |
| `L` | `c` | 1바이트 | 진행 불능(Lack of Progress)을 선언해요 |
| `G` | `c` | 1바이트 | 게임 정보를 요청해요 |
| `E` | `c` | 1바이트 | 게임을 끝내요. 로봇이 시작 타일에 있고 벽 토큰을 하나 이상 식별했다면 탈출 보너스(Exit bonus)를 줘요. |

Erebus는 이 메시지들을 길이로 구별하므로, 보고는 정확히 9바이트여야 해요.

## 로봇이 받는 메시지 {#received-by-the-robot}

| 메시지 | 형식 | 길이 | 용도 |
|---|---|---|---|
| `L` | `c` | 1바이트 | 진행 불능이 발생했어요 |
| `G` | `c f i i f`: `G`, 점수, 남은 게임 시간, 남은 실제 시간, 배터리 잔량 | 20바이트 | `G`에 대한 응답. 시간은 초 단위이고, 배터리 잔량은 0부터 100까지의 퍼센트예요. |

`G`의 패킷에는 패딩이 들어 있다는 점에 주의하세요. 위의 `struct` 형식이 float를 정렬하기 때문에, 점수는 4번째 바이트부터, 시간은 8번째와 12번째 바이트부터, 배터리 잔량은 16번째 바이트부터 시작해요.

## 자주 쓰는 Webots 함수 {#common-webots-functions}

| 함수 | 설명 |
|---|---|
| `robot.getDevice(name)` | 이름으로 장치를 가져와요. C++에서는 `robot->getMotor(name)`, `robot->getCamera(name)` 등을 사용해요. |
| `robot.step(timeStep)` | 시뮬레이션을 진행시켜요. 시뮬레이션이 끝나면 -1을 반환해요. |
| `robot.getTime()` | 시뮬레이션 시간을 초 단위로 가져와요 |
| `device.enable(timeStep)` | 센서를 활성화해요 |
| `motor.setPosition(float("inf"))` | 모터가 무한히 돌 수 있게 해요 |
| `motor.setVelocity(speed)` | 모터의 속도를 초당 라디안 단위로 설정해요 |
