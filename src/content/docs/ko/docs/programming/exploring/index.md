---
title: 탐색과 지도 작성
description: 미로를 체계적으로 탐색하고 지도를 만드는 아이디어.
---

아무렇게나 돌아다니는 로봇은 점수를 많이 얻지 못해요. 이 페이지에서는 무작정 돌아다니는 것에서 체계적인 탐색으로 나아가는 방법을 보여 줘요. 완성된 해답이 아니라 발전시켜 나갈 아이디어예요.

## 현재 위치 알기 {#know-where-you-are}
타일의 너비는 12 cm이므로 GPS 위치로 타일을 알 수 있어요. 출발점의 위치는 월드마다 다르니 모든 것을 출발점 기준으로 측정하세요.

```python
TILE = 0.12
startX, _, startZ = gps.getValues() # At the start of the game

def currentTile():
    x, _, z = gps.getValues()
    return round((x - startX) / TILE), round((z - startZ) / TILE)
```

:::note
GPS가 없어도 바퀴 인코더와 자이로로 위치를 추정할 수 있지만, 오차가 쌓여요.
:::

## 본 것 기억하기 {#remember-what-you-have-seen}
타일의 딕셔너리를 만들고, 각 타일에 대해 아는 것을 저장하세요. 어느 쪽에 벽이 있는지, 바닥이 무엇인지, 방문했는지 등이에요.

```python
tiles = {}
tiles[(0, 0)] = {"walls": {"N": False, "E": True, "S": False, "W": True}, "floor": "start", "visited": True}
```

구역 2와 3에서는 벽이 4분의 1 타일 위에 있을 수 있어서 타일만으로는 전부를 나타낼 수 없어요. 지도를 4분의 1 타일 해상도로 저장하거나 라이다 포인트 클라우드를 사용하면 대비할 수 있어요.

## 갈 곳 정하기 {#decide-where-to-go}
벽만 따라가지 마세요. 그러면 토큰 점수가 더 높은 [떠 있는 타일](/docs/rules/#linear-and-floating-tiles)에 절대 도달할 수 없어요. 흔히 쓰는 방법은 다음과 같아요.

1. 현재 타일에서 사이에 벽이 없는 이웃 타일을 나열해요.
2. 방문하지 않은 이웃이 있으면 그곳으로 가요.
3. 없으면 너비 우선 탐색으로 방문하지 않은 이웃이 있는 가장 가까운 타일을 찾아 그곳으로 가요.
4. 그런 타일이 더 이상 없거나 시간이 얼마 남지 않으면, 같은 방법으로 출발점으로 돌아가요.

구멍은 벽처럼 다루세요. 늪은 시간이 들고, 같은 늪에 들어갈 때마다 더 많이 들기 때문에 가치가 있을 때만 들어가세요.

## 예상치 못한 상황 처리하기 {#handle-the-unexpected}
- **진행 불능 (Lack of Progress):** 로봇이 마지막 체크포인트로 옮겨져요. [`L` 메시지를 받아서](/docs/programming/communication/#lack-of-progress) 위치를 업데이트하세요.
- **시간:** [`G`](/docs/programming/communication/#game-information)로 남은 시간을 물어보세요. 지도를 보내고 출발점으로 돌아갈 시간을 충분히 남겨 두세요.
- **노이즈:** 센서에는 노이즈가 있으므로, 벽이나 토큰을 믿기 전에 여러 측정값을 비교하세요.

## 타일에서 지도 행렬로 {#from-tiles-to-the-map-matrix}
[지도 행렬](/docs/rules/mapping/)의 행과 열은 각각 타일 수 × 4 + 1개예요. 지도의 `r`행 `c`열에 있는 타일의 경우는 다음과 같아요.

| 요소 | 행렬 위치 (행, 열) |
|---|---|
| `4`나 `5` 같은 바닥 표시 | `4r + 1`행과 `4r + 3`행, `4c + 1`열과 `4c + 3`열 |
| 북쪽 벽 | `4r`행, `4c`열부터 `4c + 4`열까지 |
| 서쪽 벽 | `4c`열, `4r`행부터 `4r + 4`행까지 |

지도는 어디서 시작해도 돼요. Erebus가 시작 타일을 사용해 [행렬을 정렬](/docs/rules/mapping/#how-correctness-is-calculated)하고, 네 가지 회전을 시도해요. [지도 작성 규칙](/docs/rules/mapping/)에서 행렬의 모든 값을 설명해요. 그다음 [지도를 제출](/docs/programming/map-bonus/)하세요.

정답이 [지도 작성 규칙](/docs/rules/mapping/#examples)에 나와 있는 예제 월드로 테스트해 보세요. 결과는 제어 창의 기록에 `Map Correctness`로 표시돼요.
