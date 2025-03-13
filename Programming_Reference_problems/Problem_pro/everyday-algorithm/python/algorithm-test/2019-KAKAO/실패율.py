'''
* 🙆‍♂️ Created by wwlee94 on 2020.04.23
https://programmers.co.kr/learn/courses/30/lessons/42889

- 문제 풀이 방법 -
1. 문제에 해당하는 조건을 다음과 같이 해석하면 풀기 쉽다.
    * 스테이지에 도달한 플레이어 수: 해당 스테이지 이상 값을 가진 플레이어
    * 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 : 해당 스테이지와 동일하거나 작은 플레이어들

2. 해당 조건에 맞게 필터링한다.
단, 아래와 같이 사용하면 시간초과가 난다.
reach_stage = len(list(filter(lambda x: x >= level, stages)))
not_clear = len(list(filter(lambda x: x == level, stages)))

( 조건이 겹치는 부분이 있으면 더 큰 범위의 조건에서 원하는 조건을 찾는 식으로 접근하면 좋을 듯하다. )
'''

def solution(N, stages):
    answer = []
    
    for level in range(1, N+1):
        reach_list = list(filter(lambda x: x >= level, stages))
        reach_stage = len(reach_list)
        not_clear = reach_list.count(level)
        if reach_stage == 0:
            answer.append([level, 0])
        else:
            answer.append([level, not_clear / reach_stage])
        
    answer.sort(key = lambda x:x[0])
    answer.sort(key = lambda x:x[1], reverse=True)
    # 분리
    answer = list(map(list,zip(*answer)))[0]
    return answer