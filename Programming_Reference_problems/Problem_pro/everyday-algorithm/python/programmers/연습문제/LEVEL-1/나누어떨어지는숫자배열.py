'''
* 🙆‍♂️ Created by wwlee94 on 2020.04.05
https://programmers.co.kr/learn/courses/30/lessons/12910
# 프로그래머스 LV1 
'''
def solution(arr, divisor):
    answer = []
    for x in arr:
        if x % divisor == 0:
            answer.append(x)
    if len(answer) == 0:
        return [-1]
    answer.sort()
    return answer