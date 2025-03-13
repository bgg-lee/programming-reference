'''
* 🙆‍♂️ Created by wwlee94 on 2020.04.05
https://programmers.co.kr/learn/courses/30/lessons/12903
# 프로그래머스 LV1 
'''
def solution(s):
    answer = ''
    leng = len(s)
    if leng % 2 == 0:
        idx = (leng-1)//2
        answer = s[idx:idx+2]
    else:
        answer = s[leng//2] 
    return answer