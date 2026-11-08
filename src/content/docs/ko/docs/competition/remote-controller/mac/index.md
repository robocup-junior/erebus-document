---
title: macOS
description: macOS용 Remote Controller 설정 가이드.
---

# 같은 컴퓨터에서 게임 서버와 컨트롤러 프로그램 실행하기
먼저 같은 컴퓨터에서 게임 서버와 컨트롤러 프로그램을 실행해 봐요. 실제 대회 구성과는 다르지만, 로컬에서 디버깅할 때 도움이 돼요.

## 원격 모드 켜기 {#toggle-remote-mode}
월드를 열고 제어 창에서 "TOGGLE REMOTE"를 누르세요. 버튼 색이 주황색으로 바뀌면 켜진 거예요.

![켜진 상태의 TOGGLE REMOTE 버튼](../../../../../docs/competition/remote-controller/mac/toggle_remote.png)

제어 창이 표시되지 않으면 Scene Tree에서 "DEF MAINSUPERVISOR Robot"을 마우스 오른쪽 버튼으로 클릭하고 "Show Robot Window"를 누르세요.

## 프로그램 실행하기 {#execute-your-program}
터미널을 열고 다음 명령을 실행하세요. `<Your controller path>`는 컨트롤러 프로그램의 경로로 바꾸세요.

```bash
export WEBOTS_HOME=/Applications/Webots.app
"$WEBOTS_HOME/Contents/MacOS/webots-controller" "<Your controller path>"
```

Webots가 다른 위치에 있거나 다른 이름으로 설치되어 있다면, 예를 들어 `"/Applications/Webots R2023b.app"`처럼 `WEBOTS_HOME`을 그에 맞게 바꾸세요.

컨트롤러가 Webots에 연결되고 게임이 시작될 때까지 기다려요.

## 게임 시작하기 {#start-the-game}
제어 창에서 시작 버튼을 누르세요. 로봇이 나타나고 프로그램이 실행되기 시작해요.

## 게임 종료하기 {#terminate-the-game}
게임을 중단하려면 터미널에서 Ctrl+C를 누르세요.

시뮬레이션이 종료되면 Erebus 게임 관리 시스템도 동시에 종료돼요. 게임을 다시 실행하려면 월드를 다시 불러오세요.

# 다른 컴퓨터에서 게임 서버 실행하기
공식 대회에서 사용하는 구성이에요. 컨트롤러를 실행하는 컴퓨터(클라이언트)와 게임 서버(서버)는 같은 네트워크에 연결되어 있어야 해요.

1. (서버) 서버에서 Webots를 시작하고, 월드를 열고, 제어 창에서 원격 모드를 켜세요.
1. (서버) 서버의 IP 주소를 확인하세요. System Settings --> Network(시스템 설정 --> 네트워크)에서 찾을 수 있어요.
1. (클라이언트) 다음 명령을 실행하세요. `<Your controller path>`는 컨트롤러 프로그램의 경로로, `<Server IP address>`는 앞 단계에서 확인한 IP 주소로 바꾸세요.

    ```bash
    export WEBOTS_HOME=/Applications/Webots.app
    "$WEBOTS_HOME/Contents/MacOS/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. (서버) 시작 버튼을 눌러 게임을 시작하세요.

## 문제 해결 {#troubleshooting}
- **컨트롤러가 연결되지 않아요:** 두 컴퓨터가 서로 통신할 수 있는지(예: `ping`으로), 서버의 방화벽이 TCP 포트 1234를 허용하는지, Webots 환경 설정(Preferences)의 Network 탭에 있는 허용 IP 목록이 비어 있거나 클라이언트를 포함하는지 확인하세요.
- **`No robot name provided`가 표시돼요:** 기다리는 동안에는 정상적인 메시지예요. 계속 표시된다면 원격 모드가 켜져 있지 않은 것이니 TOGGLE REMOTE 버튼을 확인하세요.
- **컨트롤러가 Python 라이브러리를 찾지 못해요:** 프로그램은 클라이언트의 Python으로 실행되므로, 라이브러리를 클라이언트에 설치하세요.

# 공식 문서
구성에 대해 더 자세히 알고 싶다면 [공식 가이드](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b)를 참고하세요.
