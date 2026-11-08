---
title: Erebus란?
description: Erebus는 Webots 위에 만들어진 RoboCupJunior의 구조 시뮬레이션 플랫폼이에요. 각 구성 요소가 어떻게 맞물리는지 알아봐요.
---

Erebus는 로봇 시뮬레이션 대회 환경이에요. 자율적으로 미로를 탐색하고, 벽 토큰(문자 피해자와 인지 표적)을 찾아 식별하고, 장애물과 함정을 피하고, 환경의 지도를 만드는 로봇의 컨트롤러를 개발해요.

Erebus는 [Webots](https://cyberbotics.com/) 위에 만들어졌어요. Webots는 전문가용으로 설계되어 산업, 교육, 연구에서 널리 쓰이는 로봇 시뮬레이션 플랫폼이에요. Cyberbotics가 1998년부터 꾸준히 관리하고 있어요.

이 플랫폼은 주로 [RoboCupJunior Rescue Simulation](https://junior.robocup.org/rescue/) 대회를 위해 설계되었어요. 중급 이상의 경험을 가진 프로그래머를 대상으로 해요.

## 구성 요소의 관계 {#how-it-fits-together}

| 구성 요소 | 하는 일 | 받는 곳 |
|---|---|---|
| **Webots R2023b** | 3D 로봇 시뮬레이터 | [Webots R2023b 릴리스](https://github.com/cyberbotics/webots/releases/tag/R2023b) |
| **Erebus** | 월드와, 규칙을 적용하고 점수를 계산하는 게임 매니저(Main Supervisor) | [Erebus 릴리스](https://github.com/robocup-junior/erebus/releases) |
| **여러분의 컨트롤러** | Python 또는 C/C++로 작성한 로봇 프로그램 | 여러분이 작성해요! |
| **Robot Customizer** | 커스텀 로봇을 설계하고 JSON 파일로 내보내는 웹 도구 | [robot.erebus.rcj.cloud](https://robot.erebus.rcj.cloud/) |
| **World Editor** | 연습용 맵을 그리고 `.wbt` 월드로 내보내는 웹 도구 | [world.erebus.rcj.cloud](https://world.erebus.rcj.cloud/) |

## 무엇을 할 수 있나요? {#what-can-you-do-with-it}

1. **로봇 만들기.** 예산 안에서 센서와 그 위치를 골라요.
2. **프로그래밍하기.** 컨트롤러가 센서를 읽고 사람의 도움 없이 무엇을 할지 판단해요.
3. **실행하기.** 포함된 월드나 직접 만든 월드에서 테스트하고 점수를 확인해요.
4. **대회 참가하기.** 지역, 권역, 국제 RoboCupJunior 대회에 참가해요.

이미 Erebus를 알고 있다면 [v26의 새로운 기능](/docs/whats-new/)을 참고하세요.

## 유용한 자료 {#useful-references}
Erebus를 배우고 활용하는 데 유용한 링크예요.
- [Webots 사용자 가이드](https://cyberbotics.com/doc/guide/index?version=R2023b)
- [Webots 레퍼런스 매뉴얼](https://cyberbotics.com/doc/reference/nodes-and-api-functions?version=R2023b)
- [Python 문서](https://www.python.org/doc/)
- [C++ 문서](https://www.cplusplus.com/doc/tutorial/)
- [OpenCV 튜토리얼](https://docs.opencv.org/4.x/d9/df8/tutorial_root.html)
- [RCJ Rescue 커뮤니티 웹사이트](https://rescue.rcj.cloud/): 이벤트, 팀 문서, TDP·포스터·동영상 평가 기준
- [RoboCupJunior 포럼](https://junior.forum.robocup.org/): 규칙 보충 설명

## 다음 단계 {#next}
[Erebus를 설치](/docs/installation/)한 다음, [규칙 요약](/docs/rules/)을 읽고 게임을 이해하세요.
