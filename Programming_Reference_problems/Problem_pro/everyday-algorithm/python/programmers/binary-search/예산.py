'''
* 🤷‍♂️ Created by wwlee94 on 2020.02.18
https://programmers.co.kr/learn/courses/30/lessons/43237

- 문제 풀이 접근 - 
문제 조건에 각 지역의 수는 10만개 이하이므로 값을 하나씩 올려가면서 찾는 것은 시간 초과ㄴ
따라서, 각 지역의 최소값, 최대값을 기준으로 이분 탐색 알고리즘을 적용하면 끝 !
'''
def solution(budgets, M):
    answer = 0
    _min, _max = 0, max(budgets)
    
    while _min <= _max:
        mid = (_min + _max) // 2 # // 사용하면 int형 반환
        temp = [i if i < mid else mid for i in budgets]
        
        if sum(temp) > M:
            _max = mid - 1
        elif sum(temp) <= M:
            answer = mid
            _min = mid + 1
    return answer