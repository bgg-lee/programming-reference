'''
* 🤷‍♂️ Created by wwlee94 on 2020.07.07
https://programmers.co.kr/learn/courses/30/lessons/12900
'''

# https://deveric.tistory.com/61
import sys
sys.setrecursionlimit(60000)
def solution(n):
    mem = [-1 for i in range(60001)]
    def dp(n):
        if mem[n] != -1: return mem[n]
        if n == 0: return 1 # 공집합도 1로본다
        if n == 1: return 1
        mem[n] = (dp(n-1) + dp(n-2)) % 1000000007
        return mem[n]
    answer = dp(n)
    return answer