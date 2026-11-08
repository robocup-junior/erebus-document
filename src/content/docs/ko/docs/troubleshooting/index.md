---
title: 문제 해결
description: Erebus를 설치하고 실행할 때 자주 생기는 문제의 해결 방법.
---

가장 먼저 Webots 콘솔을 확인하세요. 대부분의 문제는 그곳에 오류 메시지가 표시돼요.

## 설치 {#installation}

### `No module named 'cv2'` {#no-module-named-cv2}
Webots가 사용하는 Python에 OpenCV가 설치되어 있지 않아요. 그 Python에 [필요한 라이브러리](/docs/installation/#python-libraries)를 설치하세요. Python이 여러 개 설치되어 있다면, 아래의 **Python command** 설정을 보면 Webots가 어떤 Python을 사용하는지 알 수 있어요.

### `WARNING: Python was not found` {#warning-python-was-not-found}
Webots가 Python이 어디에 있는지 몰라요.

1. Python을 찾으세요. macOS와 Linux에서는 터미널에서 `which python3`를 실행하세요. Windows에서는 새 명령 프롬프트에서 `python`을 입력했을 때 Python이 열리는지 확인하세요. 열리지 않으면 PATH에 추가하는 옵션을 체크하고 Python을 다시 설치하세요.
2. Webots 환경 설정을 여세요. macOS에서는 **Webots > Preferences**, Windows와 Linux에서는 **Tools > Preferences**예요.

   ![Webots 메뉴의 Preferences 항목](../../../docs/troubleshooting/preferences_open.png)

3. **Python command** 칸에 경로를 설정하세요. Windows에서는 보통 `python`이면 충분해요.

   ![Webots 환경 설정의 Python command 칸](../../../docs/troubleshooting/preferences.png)

### 게임 타이머가 나타나지 않아요 {#the-game-timer-does-not-appear}
처음 시작할 때는 Erebus가 라이브러리를 설치하느라 몇 분 걸릴 수 있어요. 끝나지 않는다면 콘솔에서 오류를 확인하세요. 자동 설치가 작동하지 않으면 [필요한 라이브러리](/docs/installation/#python-libraries)를 직접 설치하세요.

## Erebus 실행 {#running-erebus}

### 제어 창이 나타나지 않아요 {#the-control-window-does-not-appear}
제어 창은 Webots가 여는 웹 페이지예요.

1. 브라우저가 차단했다면, 월드가 열려 있는 동안 [제어 창](http://localhost:1234/robot_windows/MainSupervisorWindow/MainSupervisorWindow.html?name=robot)을 여세요.
2. 그렇지 않다면 **Tools > Scene Tree**로 Scene Tree가 표시되어 있는지 확인하세요.
3. Scene Tree에서 **DEF MAINSUPERVISOR Robot**을 찾아 마우스 오른쪽 버튼으로 클릭하고 **Show Robot Window**를 선택하세요.

![Scene Tree의 Show Robot Window 옵션](../../../docs/troubleshooting/showrobot.png)

### Webots 화면이 비어 있거나 검은색이에요 {#the-webots-screen-is-blank-or-black}
월드를 열기 전에 다운로드한 파일을 별도의 폴더에 복사해서 압축을 푸세요.

### 시뮬레이션이 너무 느려요 {#the-simulation-runs-too-slowly}
아마 컴퓨터 성능 때문일 거예요. 그래픽 품질을 낮추면 도움이 될 수 있어요.

1. Webots 환경 설정을 여세요.
2. **OpenGL** 탭을 여세요.
3. 설정을 바꾸세요.

![Webots 환경 설정의 OpenGL 탭](../../../docs/troubleshooting/opengl.png)

이 설정은 카메라에 보이는 모습을 바꾸고, 대회에서는 [대회 설정](/docs/competition/#opengl-settings)을 사용하므로, 그 설정으로도 프로그램을 확인하세요.

## 로봇 {#your-robot}

### `PROTO parameter 'camera_width' has no matching IS field` {#proto-parameter-camera_width-has-no-matching-is-field}
Erebus v26.1은 현재 버전의 Robot Customizer로 만든 로봇을 불러올 때 이 오류를 빨간색으로 표시해요. 무시해도 돼요. 로봇은 작동하고, 카메라는 선택한 해상도 그대로예요.

### 장치를 찾을 수 없다고 나와요 {#my-program-says-a-device-was-not-found}
아래를 참고하세요. 게임을 시작하기 전에 **오른쪽** LOAD 버튼으로 로봇을 불러왔는지도 확인하세요.

## 프로그램 {#your-program}

### `Device "..." was not found` {#device--was-not-found}
프로그램의 장치 이름이 로봇과 맞지 않아요. 스타터 로봇의 이름은 [레퍼런스](/docs/reference/parameters/#device-names-of-the-starter-robot)에 있어요. 직접 만든 로봇이라면 [Robot Customizer](/docs/robot/customizer/)에서 설정한 이름이에요. 로봇을 불러왔는지 확인하세요.

### 벽 토큰을 보고해도 아무 일도 일어나지 않아요 {#nothing-happens-when-i-report-a-wall-token}
제어 창의 Settings 탭에서 **Enable debugging**을 켜고 콘솔을 확인하세요. 가장 흔한 원인은 로봇이 최소 1초 동안 정지해 있지 않았거나, 좌표를 센티미터로 변환하지 않은 경우예요. [통신](/docs/programming/communication/#scoring-wall-tokens)을 참고하세요.

### 보고가 오식별로 처리돼요 {#my-reports-are-misidentifications}
로봇은 토큰에서 최대 반 타일 이내, 같은 쪽 벽에 있어야 하고, 각 토큰은 한 번만 점수를 얻을 수 있어요. 가짜를 보고해도 오식별로 처리돼요.

### 지도가 0%이거나 점수 계산 오류가 나요 {#the-map-gets-0-or-a-scoring-error}
지도에는 시작 타일(`5`)이 있어야 하고, 평가는 한 번만 할 수 있어요. [지도 제출](/docs/programming/map-bonus/)을 참고하세요.

### 원격 모드에서 컨트롤러가 연결되지 않아요 {#the-controller-cannot-connect-in-remote-mode}
사용하는 운영 체제의 [Remote Controller](/docs/competition/remote-controller/) 가이드를 참고하세요.

## 그래도 해결되지 않나요? {#still-stuck}
[Discord 서버](https://discord.com/invite/6FJxZxk)에서 물어보거나, [이슈를 올리세요](https://github.com/robocup-junior/erebus/issues). 운영 체제, Erebus와 Webots 버전, 콘솔의 메시지를 함께 알려 주세요.
