---
title: Linux (Ubuntu)
description: Linux(Ubuntu 22.04 LTS)에서 Remote Controller를 설정하는 방법.
---

# 같은 컴퓨터에서 게임 서버와 컨트롤러 프로그램 실행하기
먼저 같은 컴퓨터에서 게임 서버와 컨트롤러 프로그램을 실행해 보세요. 대회 구성과는 다르지만, 로컬에서 디버깅할 때 유용해요.

## 원격 모드 켜기 {#toggle-remote-mode}
월드를 열고, 제어 창에서 **Robot setup**을 누른 다음 **Remote mode**를 켜요. 커스텀 로봇이 있다면 먼저 **Robot JSON**에서 로봇을 불러와요.

![Robot setup에서 켠 Remote mode](../../../../../docs/competition/remote-controller/linux/toggle_remote.png)

제어 창이 표시되지 않으면 Scene Tree에서 "DEF MAINSUPERVISOR Robot"을 마우스 오른쪽 버튼으로 클릭하고 "Show Robot Window"를 선택하세요.

## 프로그램 실행하기 {#execute-your-program}
터미널을 열고 다음 명령을 실행하세요. `<Your controller path>`는 컨트롤러 프로그램의 경로로 바꾸세요.

```bash
export WEBOTS_HOME=/usr/local/webots
"$WEBOTS_HOME/webots-controller" "<Your controller path>"
```

Webots를 `.deb` 패키지로 `/usr/local/webots`에 설치했다고 가정해요. 다른 곳에 설치했다면 `WEBOTS_HOME`을 그에 맞게 바꾸세요.

컨트롤러가 Webots에 연결되고 게임이 시작될 때까지 기다려요.

## 게임 시작하기 {#start-the-game}
제어 창에서 **Run match**를 눌러요. 로봇이 나타나고, 프로그램이 실행되기 시작해요.

## 게임 종료하기 {#terminate-the-game}
게임을 멈추려면 터미널에서 Ctrl+C를 누르세요.

게임이 끝나면 **Reset**을 눌러 다시 실행할 수 있어요. **Keep on Reset**이 켜져 있지 않으면 리셋할 때 Remote mode가 꺼져요.

# 다른 컴퓨터에서 게임 서버 실행하기
공식 대회에서 사용하는 구성이에요. 컨트롤러를 실행하는 컴퓨터(클라이언트)와 게임을 실행하는 컴퓨터(서버)는 같은 네트워크에 연결되어 있어야 해요.

1. (서버) 서버에서 Webots를 시작하고, 월드를 연 다음, 제어 창의 **Robot setup**에서 **Remote mode**를 켜요.
1. (서버) `ip addr` 명령 등으로 서버의 IP 주소를 확인하세요.
1. (클라이언트) 다음 명령을 실행하세요. `<Your controller path>`는 컨트롤러 프로그램의 경로로, `<Server IP address>`는 앞 단계에서 확인한 IP 주소로 바꾸세요.

    ```bash
    export WEBOTS_HOME=/usr/local/webots
    "$WEBOTS_HOME/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. (서버) **Run match**를 눌러 게임을 시작해요.

## 문제 해결 {#troubleshooting}
- **컨트롤러가 연결되지 않아요:** 두 컴퓨터가 서로 통신할 수 있는지(예: `ping`으로), 서버의 방화벽이 TCP 포트 1234를 허용하는지, Webots 환경 설정(Preferences)의 Network 탭에 있는 허용 IP 목록이 비어 있거나 클라이언트를 포함하는지 확인하세요.
- **컨트롤러는 기다리는데 로봇이 움직이지 않아요:** **Remote mode**가 켜져 있는지 확인하고 **Run match**를 누르세요.
- **컨트롤러가 Python 라이브러리를 찾지 못해요:** 프로그램은 클라이언트에 설치된 Python으로 실행되므로, 라이브러리를 클라이언트에 설치하세요.

# 공식 문서
이 구성에 대한 자세한 내용은 [Webots 가이드](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a)를 참고하세요.
