---
title: World Editor
description: Erebus World Editor로 나만의 월드를 만드는 방법.
---

## 배경 {#background}

로봇이 기본으로 들어 있는 맵과 간단한 미로를 해낼 수 있게 되면, 더 어려운 도전이 필요하거나 기본 맵에 없는 특정 상황을 테스트하고 싶어질 수 있어요.
그럴 때는 온라인 [Erebus World Editor](https://world.erebus.rcj.cloud/)를 사용하세요. 브라우저에서 맵을 그리면, Erebus에서 실행할 수 있는 `.wbt` 월드 파일로 내보내 줘요.

![World Editor에서 완성한 맵](../../../../docs/tools/world-editor/overview.png)

테스트용 작은 맵만 만든다면 경기장이 규칙을 따르는지는 크게 중요하지 않을 거예요. 하지만 대회용 경기장을 만들 계획이라면 공식 [Simulation Rules](https://junior.robocup.org/wp-content/uploads/2026/02/RCJRescueSimulation2026-final.pdf)를 읽어 보세요. 에디터는 작업하는 동안 맵이 규칙에 맞는지 확인해 줘요.

에디터에는 가이드가 내장되어 있어요. 오른쪽 아래의 **Guide**를 누르면 샘플 맵을 만드는 실습 레슨(약 15분), 화면 둘러보기, Room 4 레슨을 볼 수 있어요. 에디터의 언어는 그 옆에서 바꿀 수 있어요.

## 맵 시작하기 {#starting-a-map}
에디터를 열면 **어느 해의 규칙**을 따를지 고르고 **New map**을 누르세요. **Erebus v26에서는 2026년 규칙을 선택하세요.** 2027년 규칙은 Erebus 다음 버전을 위한 초안이에요.

![World Editor의 시작 화면](../../../../docs/tools/world-editor/start.png)

작업 내용은 브라우저에 보관되지만, 다른 브라우저에서는 보이지 않고 인터넷 사용 기록(사이트 데이터)을 삭제하면 사라져요. 중요한 맵은 상단 바의 저장 버튼으로 JSON으로 저장해 두고, 열기 버튼으로 다시 여세요.

작업하기 좋은 순서는 크기와 외곽, 방(Room), 통로, 벽, 바닥, 장애물과 피해자, Room 4, 그리고 마지막으로 검사와 내보내기예요. 도구는 왼쪽에 있고, 각각 키보드 단축키가 있어요. 선택한 도구의 설정은 그 옆 패널에 나타나요.

| 도구 | 키 | 용도 |
|---|---|---|
| Select | `S` | 맵의 일부를 선택, 이동, 복사, 붙여넣기 |
| Move | `H` | 화면 이동 |
| Outline | `X` | 맵의 크기와 모양 설정 |
| Rooms | `M` | Room 1~4(규칙의 구역) 칠하기 |
| Passages | `P` | 통로로 방 연결하기 |
| Line | `L` | 벽 그리기 |
| Curve | `A` | Room 3에 곡선 벽 그리기 |
| Eraser | `E` | 벽, 바닥, 장애물, 피해자 지우기 |
| Floor | `F` | 체크포인트, 구멍, 늪, 시작 타일 설정 |
| Obstacle | `O` | 장애물 배치 |
| Victims | `V` | 문자 피해자, 인지 표적, 가짜 배치 |

마우스 휠로 확대·축소하고, Space를 누른 채 끌면 화면이 이동하며, 실행 취소는 `⌘Z` 또는 `Ctrl+Z`예요.

## 크기와 외곽 {#size-and-outline}
**Outline** 도구로 맵의 크기를 타일 단위로 설정하세요. 바깥 벽은 자동으로 추가돼요. **Outline (uneven)**을 사용하면 타일을 클릭해서 맵에서 뺄 수 있고, 클릭한 위치에 행과 열을 넣거나 뺄 수도 있어요.

![Outline 도구](../../../../docs/tools/world-editor/outline.png)

## 방과 통로 {#rooms-and-passages}
**Rooms** 도구로 각 방의 타일을 칠하세요. 방 사이의 경계에는 벽이 자동으로 추가돼요. 그런 다음 **Passages** 도구로 방을 연결하세요. 각 통로의 색은 연결하는 방에 따라 정해져요.

![Rooms 도구](../../../../docs/tools/world-editor/rooms.png)

![Passages 도구](../../../../docs/tools/world-editor/passages.png)

## 벽 {#walls}
**Line** 도구로 벽을 그리세요. Room 1에서는 타일 가장자리에, Room 2와 3에서는 4분의 1 타일 위에 그려요. Room 3에서는 **Curve** 도구를 사용하고, 타일의 4분의 1 부분을 가리켜 곡선을 골라요. 같은 곳을 다시 클릭하면 지워져요.

![벽을 그리는 Line 도구](../../../../docs/tools/world-editor/walls.png)

## 바닥과 장애물 {#floors-and-obstacles}
**Floor** 도구로 바닥 종류를 고르고 타일을 클릭해서 설정하세요. 시작 타일은 Room 1의 타일이어야 하고, 시작 타일이 없으면 월드를 내보낼 수 없어요. 한 타일은 구멍, 늪, 체크포인트, 장애물, 시작, 통로 중 하나만 될 수 있어요.

![Floor 도구](../../../../docs/tools/world-editor/floors.png)

**Obstacle** 도구로 모양을 고르고 타일을 클릭하세요. Room 1~3에서는 타일마다 장애물이 하나씩, 타일 중심에 놓여요. 장애물을 클릭하면 핸들과 패널로 크기, 높이, 색, 회전을 바꿀 수 있어요.

![Obstacle 도구](../../../../docs/tools/world-editor/obstacles.png)

## 피해자와 인지 표적 {#victims-and-cognitive-targets}
**Victims** 도구로 종류를 고르고 벽 근처를 클릭하세요. 다음을 배치할 수 있어요.

- 진짜 문자 피해자: 부상(harmed), 안정(stable), 무사(unharmed)
- 입체 기호로 된 가짜 문자 피해자
- 인지 표적: 위험물 종류를 고르고, 원하면 고리의 색도 고르세요. 합이 표시되고, 그 합이 종류를 정해요
- 고리의 합이 0~3이 아닌 가짜 표적

Room 1에서는 타일의 각 변에 피해자를 하나씩 놓을 수 있어요. Room 2와 3에서는 6 cm 벽의 면에 놓고, 곡선 벽에는 안쪽과 바깥쪽 두 자리가 있어요. **Turn**에서 고정된 회전을 고르거나, 새 토큰마다 무작위 회전을 고르세요. 배치한 토큰을 클릭하면 바꾸거나 지울 수 있고, 벽을 따라 끌어서 옮길 수도 있어요.

![Victims 도구](../../../../docs/tools/world-editor/victims.png)

## Room 4 {#room-4}
Room 4는 타일 기반이 아니므로 그림으로 그려요. **Rooms** 도구로 Room 4를 칠하고, **Draw room 4**를 누르거나(또는 방을 더블클릭해서) Room 4 작성기를 여세요.

![Room 4 작성기](../../../../docs/tools/world-editor/room4.png)

검은색으로 그린 것이 벽이 돼요. 작성기에는 자유롭게 그리는 도구, 직선, 곡선, 호, 사각형, 타원, 다각형, 아이콘 모양을 그리는 도구, 그리고 피해자와 장애물 도구가 있어요. Room 4에는 장애물을 원하는 만큼 놓을 수 있어요. 빨간 줄무늬는 로봇이 갈 수 없는 곳을 나타내며, 로봇이 지나갈 수 있도록 약 한 타일 너비의 길을 남겨 둬야 해요.

다 그렸으면 **OK**를 누르세요. 그림이 맵에 Room 4로 나타나고, 내보낸 월드에 들어가요. 작성기 오른쪽 위의 버튼으로 그림을 PNG로 저장해서 다른 맵에서도 같은 Room 4를 사용할 수 있고, PNG나 JPEG 그림을 열 수도 있어요.

## 맵 검사하기 {#checking-your-map}
모든 변경 사항은 오른쪽 위의 **Checks** 카드에서 규칙에 맞는지 검사돼요. 빨간 ✕는 월드를 내보낼 수 없게 하는 문제이고, 노란 !는 살펴볼 만한 경고예요. 항목을 클릭하면 그 위치로 이동해요. **Fix**는 항목 하나를, **Fix all that can be fixed**는 고칠 수 있는 항목을 모두 고쳐요.

![Checks 카드가 표시된 World Editor의 새 맵](../../../../docs/tools/world-editor/new_map.png)

상단 바의 **Linear** 버튼은 각 타일을 선형 타일 또는 떠 있는 타일로 색칠해 보여 줘요. 이것이 토큰의 점수를 정해요.

![맵에 표시된 선형 타일과 떠 있는 타일](../../../../docs/tools/world-editor/linear.png)

상단 바의 트로피는 점수 규칙으로 계산한 맵의 **최대 점수**를 보여 줘요. 방별 점수와, 탈출 보너스와 지도 보너스를 포함한 점수도 함께 보여 줘요.

![맵의 최대 점수](../../../../docs/tools/world-editor/max_score.png)

## 월드 내보내고 실행하기 {#exporting-and-running-your-world}
상단 바에서 맵 이름을 정하고, 오른쪽 위의 **.wbt** 버튼을 누르세요. 그런 다음:

1. `.wbt` 파일을 Erebus의 `game/worlds` 폴더에 복사하세요. 월드가 Erebus의 파일을 사용하므로 반드시 이 폴더에 있어야 해요.
1. Webots에서 열거나, [제어 창](/docs/getting-started/)의 **Worlds** 버튼으로 선택하세요.

![Erebus v26.1에서 실행 중인 에디터 가이드의 샘플 맵.](../../../../docs/tools/world-editor/exported_world.png)

*Erebus v26.1에서 실행 중인 에디터 가이드의 샘플 맵.*

`.wbt` 파일은 다시 편집 가능한 맵으로 되돌릴 수 없으니, JSON도 함께 보관하세요.
