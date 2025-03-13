'''
* 🙆‍♂️ Created by wwlee94 on 2020.02.02
- 전체 학생의 수 n
- 체육복을 도난당한 학생들의 번호가 담긴 배열 lost
- 여벌의 체육복을 가져온 학생들의 번호가 담긴 배열 reserve

- 풀이 과정 - 
1. 도난당한 학생(lost)와 여벌의 체육복을 가진 학생(reserve)중 서로 겹치는 값은 우선 빼두고 시작 !
2. for문 돌면서 lost와 reserve의 차이가 1이 난다면 빌려 줄 수 있는 경우 이므로 각각의 리스트에서 해당 값을 제거한 후 횟수 + 1 
    -> ( [:] 방식(얕은 복사)을 사용하여 원래 리스트의 값을 제거해도 for문 도는데 지장 없음 )
'''
def solution(n, lost, reserve):
    new_lost = [x for x in lost if x not in reserve] # 순서 보존하면서 리스트 차집합
    new_reserve = [x for x in reserve if x not in lost]
    answer = n - len(new_lost)
    
    temp = []
    for _lost in new_lost[:]:
        for _reserve in new_reserve[:]:
            if abs(_lost - _reserve) == 1:
                new_lost.remove(_lost)
                new_reserve.remove(_reserve)
                answer += 1
                break
    return answer