---
title: 자주 묻는 질문
description: Erebus와 대회에 대해 자주 묻는 질문.
---

## Erebus에 대해 {#about-erebus}

### 실제 로봇이 필요한가요? {#do-i-need-a-real-robot}
아니요. 모든 것이 시뮬레이터 안에서 일어나요. 로봇은 여러분이 설계하는 가상의 e-puck이에요.

### 어떤 프로그래밍 언어를 쓸 수 있나요? {#which-programming-languages-can-i-use}
이 문서에서는 Python과 C/C++를 다뤄요. Erebus는 Java와 MATLAB 컨트롤러도 불러올 수 있지만, 이 문서에는 그 예제가 없어요.

### 성능 좋은 컴퓨터가 필요한가요? {#do-i-need-a-powerful-computer}
아니요. [요구 사항](/docs/installation/)을 참고하세요. 느린 컴퓨터에서는 [그래픽 설정을 낮춰야](/docs/troubleshooting/#the-simulation-runs-too-slowly) 할 수도 있어요.

### 더 새로운 버전의 Webots를 써도 되나요? {#can-i-use-a-newer-version-of-webots}
아니요. Erebus v27은 Webots **R2025a**에서 실행돼요. Erebus v26용 R2023b처럼 다른 버전을 함께 설치해 두는 것은 괜찮아요.

### OpenCV나 NumPy 같은 라이브러리를 써도 되나요? {#can-i-use-libraries-like-opencv-or-numpy}
네. 만든 사람을 밝히고 라이선스를 지킨다면 외부 코드를 사용할 수 있어요. 팀은 배우는 것을 우선해야 하고, 자신의 해법이 어떻게 작동하는지 설명할 수 있어야 해요.

## 게임 {#the-game}

### 어떤 순서로 배우는 게 가장 좋나요? {#what-is-the-best-order-to-learn-things}
[학습 과정](/docs/#the-learning-path)을 따라가세요. 게임을 이해하고, 로봇을 준비하고, 실행해 보고, 기초를 배운 다음 게임을 플레이해요.

### 프로그래밍하기 전에 로봇을 만들어야 하나요? {#do-i-need-to-make-a-robot-before-programming}
네. 모든 프로그램은 불러온 로봇에서 실행되므로 [로봇 준비하기](/docs/robot/)부터 시작하세요. 급하다면 완성된 스타터 로봇을 다운로드할 수 있어요.

### 로봇은 어디서 출발하나요? {#where-does-the-robot-start}
구역 1에 있는 시작 타일에서 출발해요. 항상 벽이 없는 방향을 보고 있어요.

### 로봇이 구멍에 빠지면 어떻게 되나요? {#what-happens-if-the-robot-falls-into-a-hole}
진행 불능(Lack of Progress)이 발생해요. 로봇은 마지막으로 방문한 체크포인트로 돌아가고 5점을 잃어요.

### 로봇이 출발점으로 돌아와야 하나요? {#does-the-robot-have-to-return-to-the-start}
아니요. 하지만 벽 토큰을 하나 이상 식별했다면, 시작 타일로 돌아와 `E`를 보내면 10%의 탈출 보너스(Exit bonus)를 받아요.

### 로봇이 남은 시간을 어떻게 알 수 있나요? {#how-can-my-robot-tell-how-much-time-is-left}
[`G` 메시지](/docs/programming/communication/#game-information)로 알 수 있어요. 타이머는 두 개이고, 둘 중 하나라도 다 되면 게임이 끝나요.

### 배터리가 다 떨어지면 어떻게 되나요? {#what-happens-when-the-battery-runs-out}
게임이 끝나요. 이를 피하려면 청록색 접촉 타일 위에 5초 동안 멈춰서 배터리를 교체하세요. 프로그램은 [`G` 메시지](/docs/programming/communication/#game-information)로 배터리 잔량을 읽을 수 있어요. [배터리](/docs/programming/battery/)를 참고하세요.

### 천천히 달리면 배터리가 절약되나요? {#does-driving-slowly-save-the-battery}
배터리는 모터 속도에 따라 줄어들기 때문에 느린 로봇은 초당 배터리를 덜 쓰지만, 그 시간 동안 이동하는 거리도 짧아요. 테스트로 로봇에 가장 알맞은 균형을 찾아보세요.

### 구역 4를 탐색해야 하나요? {#do-i-have-to-explore-area-4}
아니요. 선택 사항이지만, 구역 4의 토큰은 가치가 가장 커요. 가장 높은 점수를 받고, 거기에 2를 곱해요.

### 구역 4의 지도를 만들어야 하나요? {#do-i-have-to-map-area-4}
아니요. 구역 4의 셀은 모두 `*`이므로 채워 넣기만 하면 돼요.

### 로봇이 지도를 미리 알고 있어도 되나요? {#can-my-robot-know-the-map-beforehand}
아니요. 경기장이나 벽 토큰의 위치를 미리 입력해 두는 것은 금지되어 있어요.

## 대회 {#the-competition}

### 어떻게 참가하나요? {#how-do-i-take-part}
지역 RoboCupJunior 대회를 통해 참가해요. 국제 대회 출전권은 지역 대표(Regional Representative)가 배정해요. [RoboCupJunior 웹사이트](https://junior.robocup.org/)를 참고하세요.

### 무엇을 준비해야 하나요? {#what-should-i-prepare}
[대회 준비](/docs/competition/)를 참고하세요.

### 규칙에 대해 어디서 물어볼 수 있나요? {#where-can-i-ask-about-the-rules}
[RoboCupJunior 포럼](https://junior.forum.robocup.org/)에서 물어보세요. 규칙 보충 설명도 그곳에 올라오므로 정기적으로 확인하세요.
