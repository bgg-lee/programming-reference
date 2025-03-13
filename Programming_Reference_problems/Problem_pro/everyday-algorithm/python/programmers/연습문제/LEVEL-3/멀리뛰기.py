'''
* 🙆‍♂️ Created by wwlee94 on 2020.09.04
https://programmers.co.kr/learn/courses/30/lessons/12914

# 프로그래머스 LV3
'''

# 문제의 규칙을 찾아보면 피보나치 수열
# 운이 좋게 찾은 것 같은데 정확한 규칙 찾는 방법을 더 알아보자
def solution(n):
    memo = [-1 for _ in range(2001)]
    def dp(x):
        if memo[x] != -1:
            return memo[x]
        if x == 1: return 1
        if x == 2: return 2
        memo[x] = (dp(x-2) + dp(x-1)) % 1234567
        return memo[x]
    return dp(n)