---
title: Windows
description: Windows에서 Remote Controller를 설정하는 방법.
---

# 같은 컴퓨터에서 게임 서버와 컨트롤러 프로그램 실행하기
먼저 같은 컴퓨터에서 게임 서버와 컨트롤러 프로그램을 실행해 보세요. 대회 구성과는 다르지만, 로컬에서 디버깅할 때 유용해요.

## 원격 모드 켜기 {#toggle-remote-mode}
월드를 열고, 제어 창에서 **Robot setup**을 누른 다음 **Remote mode**를 켜요. 커스텀 로봇이 있다면 먼저 **Robot JSON**에서 로봇을 불러와요.  
![Robot setup에서 켠 Remote mode](../../../../../docs/competition/remote-controller/windows/../mac/toggle_remote.png)

제어 창이 표시되지 않으면 Scene Tree에서 "DEF MAINSUPERVISOR Robot"을 마우스 오른쪽 버튼으로 클릭하고 "Show Robot Window"를 선택하세요.  
![Show Robot Window 옵션](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## 프로그램 실행하기 {#execute-your-program}
PowerShell을 여세요. 보통 애플리케이션 목록에서 찾을 수 있어요.  
![애플리케이션 목록의 PowerShell](../../../../../docs/competition/remote-controller/windows/powerShell.png)

PowerShell에서 다음 명령을 실행하세요. `<Your controller path>`는 컨트롤러 프로그램의 경로로 바꾸세요.

`webots-controller.exe <Your controller path>`

명령을 찾을 수 없다면 전체 경로를 사용하세요. 기본 경로는 `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe`예요.

컨트롤러 프로그램의 경로를 모른다면 파일을 PowerShell 창으로 끌어다 놓으세요. 경로가 자동으로 입력돼요.  
![PowerShell 창으로 파일 끌어다 놓기](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

그런 다음 Enter 키를 눌러 명령을 실행하세요. 컨트롤러가 Webots에 연결되고 게임이 시작될 때까지 기다려요.

## 게임 시작하기 {#start-the-game}
제어 창에서 **Run match**를 눌러 게임을 시작해요.  
![제어 창의 Run match 버튼](../../../../../docs/competition/remote-controller/windows/../../../getting-started/match-controls.png)

## 게임 종료하기 {#terminate-the-game}
게임을 멈추려면 PowerShell에서 Ctrl+C를 눌러 프로그램을 멈추세요.

게임이 끝나면 **Reset**을 눌러 다시 실행할 수 있어요. **Keep on Reset**이 켜져 있지 않으면 리셋할 때 Remote mode가 꺼져요.

# 다른 컴퓨터에서 게임 서버 실행하기
공식 대회에서 사용하는 구성이에요. 컨트롤러를 실행하는 컴퓨터(클라이언트)와 게임을 실행하는 컴퓨터(서버)는 같은 네트워크에 연결되어 있어야 해요.

2. (서버) 서버에서 Webots를 시작하고, 월드를 연 다음, 제어 창의 **Robot setup**에서 **Remote mode**를 켜요.
2. (서버) 서버의 IP 주소를 확인하세요. [Windows에서 IP 주소 찾기](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9)를 참고하세요.
3. (클라이언트) PowerShell에서 다음 명령을 실행하세요. `<Your controller path>`는 컨트롤러 프로그램의 경로로, `<Server IP address>`는 앞 단계에서 확인한 IP 주소로 바꾸세요.  
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. (서버) **Run match**를 눌러 게임을 시작해요.

# 문제 해결
컨트롤러가 연결되지 않으면 두 컴퓨터가 서로 통신할 수 있는지, 서버의 방화벽이 TCP 포트 1234를 허용하는지, Webots 환경 설정(Preferences)의 Network 탭에 있는 허용 IP 목록이 비어 있거나 클라이언트를 포함하는지 확인하세요.

# 공식 문서
이 구성에 대한 자세한 내용은 [Webots 가이드](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a)를 참고하세요.
