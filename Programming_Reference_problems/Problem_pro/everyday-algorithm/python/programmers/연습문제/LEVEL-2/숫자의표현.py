'''
* 🤷‍♂️ Created by wwlee94 on 2020.05.01
https://programmers.co.kr/learn/courses/30/lessons/12924
# 프로그래머스 LV2

- 문제 풀이 접근 -
1. 랜덤한 수 중에서 구하는 것이 아닌 연속된 자연수 임을 파악
2. 이중 for문으로 간단하게 문제 해결
    Ex)
    1+2+3+4+5... 확인
    2+3+4+5... 확인
    3+4+5... 확인
'''

def solution(n):
    answer = 0
    for i in range(1, n+1):
        _sum = 0
        for j in range(i, n+1):
            _sum += j
            if _sum == n:
                answer += 1
                break
            elif _sum > n: 
                break
                
    return answer