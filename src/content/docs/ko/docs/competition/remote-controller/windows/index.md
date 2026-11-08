---
title: Windows
description: Windows용 Remote Controller 설정 가이드.
---

# 같은 PC에서 게임 서버와 컨트롤러 프로그램 실행하기
먼저 같은 PC에서 게임 서버와 컨트롤러 프로그램을 실행해 봐요. 실제 대회 구성과는 다르지만, 로컬에서 디버깅할 때 도움이 돼요.

## 원격 모드 켜기 {#toggle-remote-mode}
Robot Window(제어 창)에서 "TOGGLE REMOTE"를 눌러 원격 컨트롤러 구성을 켜세요. 버튼 색이 주황색으로 바뀌면 켜진 거예요.  
![TOGGLE REMOTE 버튼](../../../../../docs/competition/remote-controller/windows/toggleRemote.png)

Robot Window가 표시되지 않으면 Scene Tree에서 "DEF MAINSUPERVISOR Robot"을 마우스 오른쪽 버튼으로 클릭하고 "Show Robot Window"를 누르세요.  
![Show Robot Window 옵션](../../../../../docs/competition/remote-controller/windows/showRobotWindow.png)

## 프로그램 실행하기 {#execute-your-program}
PowerShell을 여세요. 보통 애플리케이션 목록에서 찾을 수 있어요.  
![애플리케이션 목록의 PowerShell](../../../../../docs/competition/remote-controller/windows/powerShell.png)

PowerShell에서 다음 명령을 실행하세요. `<Your controller path>`는 컨트롤러 프로그램의 경로로 바꾸세요.

`webots-controller.exe <Your controller path>`

명령을 찾을 수 없다면 전체 경로를 사용하세요. 기본 경로는 `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe`예요.

컨트롤러 프로그램의 경로를 모른다면, 파일을 PowerShell 창으로 끌어다 놓으면 경로가 자동으로 입력돼요.  
![PowerShell 창으로 파일 끌어다 놓기](../../../../../docs/competition/remote-controller/windows/dragAndDrop.png)

명령을 입력한 뒤 Enter 키를 눌러 실행하세요.

## 게임 시작하기 {#start-the-game}
Robot Window에서 Start 버튼을 눌러 시뮬레이션을 시작하세요.  
![제어 창의 시작 버튼](../../../../../docs/competition/remote-controller/windows/run.png)

## 게임 종료하기 {#terminate-the-game}
게임 실행을 중단하려면 Ctrl+C를 눌러 PowerShell에서 실행 중인 프로그램을 중단하세요.

시뮬레이션이 종료되면 Erebus 게임 관리 시스템도 동시에 종료돼요. 게임을 다시 실행하려면 월드를 다시 불러오세요.  
![Webots의 다시 불러오기 버튼](../../../../../docs/competition/remote-controller/windows/reload.png)

# 다른 PC에서 게임 서버 실행하기
공식 대회에서 사용하는 구성이에요.
컨트롤러를 실행하는 PC(클라이언트)와 게임 서버(서버)는 같은 네트워크에 연결되어 있어야 해요.

1. (서버) 서버 PC에서 Webots를 시작하고, 월드를 열고, Robot Window에서 원격 모드를 켜세요.
2. (서버) 그 PC의 IP 주소를 확인하세요. [이 문서](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9)를 참고할 수 있어요.
3. (클라이언트) PowerShell에서 다음 명령을 실행하세요. `<Your controller path>`는 컨트롤러 프로그램의 경로로, `<Server IP address>`는 앞 단계에서 확인한 IP 주소로 바꾸세요.   
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. (서버) 시작 버튼을 눌러 게임을 시작하세요.

# 문제 해결
컨트롤러가 연결되지 않으면 두 PC가 서로 통신할 수 있는지, 서버의 방화벽이 TCP 포트 1234를 허용하는지, Webots 환경 설정(Preferences)의 Network 탭에 있는 허용 IP 목록이 비어 있거나 클라이언트를 포함하는지 확인하세요.

# 공식 문서
구성에 대해 더 자세히 알고 싶다면 [공식 가이드](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2023b)를 참고하세요.
