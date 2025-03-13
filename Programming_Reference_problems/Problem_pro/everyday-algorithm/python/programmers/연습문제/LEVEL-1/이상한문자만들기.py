'''
* 🙆‍♂️ Created by wwlee94 on 2020.04.15
https://programmers.co.kr/learn/courses/30/lessons/12930
# 프로그래머스 LV1 

- 문제 풀이 접근 -
1. 처음 문제를 풀 때 공백은 단어별로 1개씩 있는 줄 알고 split을 사용함
-> 실행 결과는 틀림
2. 공백은 변화가 없도록 코드를 구현 !
'''

def solution(s):
    answer = ''
    
    idx = 0
    for ch in s:
        if ch == ' ':
            idx = 0
            answer += ' '
            continue
        else:
            if idx % 2 == 0:
                answer += ch.upper()
            else:
                answer += ch.lower()
            idx += 1
    return answer