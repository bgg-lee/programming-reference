'''
* 🙆‍♂️ Created by wwlee94 on 2020.05.11
https://programmers.co.kr/learn/courses/30/lessons/12945
# 프로그래머스 LV2

- 문제 풀이 접근 -
재귀 스택을 이용하여 문제 풀이 + 메모이제이션 사용하여 속도 향상
재귀를 이용하여 문제를 풀때는 'setrecursionlimit' 설정으로 재귀 깊이를 늘려줘야함
'''

import sys
sys.setrecursionlimit(10000000)
def solution(n):
    memo = [0] * (n+1) # 꼭 n+1개 배열 생성해야함 !
    
    def fibonaci(i):
        if i == 0: return 0
        if i == 1: return 1
        if memo[i]: return memo[i]
        memo[i] = fibonaci(i-1) + fibonaci(i-2)
        return memo[i] % 1234567
    
    return fibonaci(n)