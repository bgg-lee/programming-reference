'''
* 🙆‍♂️ Created by wwlee94 on 2020.04.06
https://programmers.co.kr/learn/courses/30/lessons/12912
# 프로그래머스 LV1 
'''
def solution(a, b):
    answer = 0
    if a > b: 
        a, b = b, a # Swap
    for x in range(a, b+1):
        answer += x
    return answer