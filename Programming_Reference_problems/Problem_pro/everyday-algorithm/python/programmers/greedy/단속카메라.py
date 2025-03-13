'''
* 🤷‍♂️ Created by wwlee94 on 2020.06.10
https://programmers.co.kr/learn/courses/30/lessons/42884

LEVEL 3
'''
# "차량 동선이 최대한 많이 겹치는 구간에 카메라를 설치하자"


def solution(routes):
    answer = 0
    # routes를 차량이 나간 지점(route[1]) 기준으로 정렬
    routes = sorted(routes, key=lambda x: x[1])
    camera = -30001  # -30001부터 카메라 위치를 찾습니다.

    # 카메라가 진입시점(route[0])보다 작은지 확인합니다.
    # 작다면, 카메라를 한 개 더 세웁니다.
    # 최근 카메라의 위치를 갱신합니다.
    for route in routes:
        if camera < route[0]:
            answer += 1
            camera = route[1]
    return answer
