'''
* 🙆‍♂️ Created by wwlee94 on 2020.04.27
https://programmers.co.kr/learn/courses/30/lessons/12909
# 프로그래머스 LV2

- 문제 풀이 접근 -
스택을 사용하여 문제 풀이
1. 문자열을 반복하며 '(' 모양일 때 bracket 배열에 추가
2. ')' 모양이 나왔을 때 bracket의 크기가 0 이상이면 bracket의 마지막 요소 제거
    2-1. 크기가 0이면 False 반환
3. 모든 요소를 반복한 뒤에 bracket에 요소가 남아있으면 False, 비워져있으면 True이다.
'''

def solution(s):
    bracket = []
        
    for i in range(len(s)):
        if s[i] == '(':
            bracket.append(s[i])
        else:
            if len(bracket) != 0:
                bracket.pop()
            else: return False
    
    if len(bracket) != 0: return False
    return True