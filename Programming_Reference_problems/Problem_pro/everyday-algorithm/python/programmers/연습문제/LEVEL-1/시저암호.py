'''
* 🙆‍♂️ Created by wwlee94 on 2020.04.13
https://programmers.co.kr/learn/courses/30/lessons/12926
# 프로그래머스 LV1 

- 문제 풀이 접근 -
1. 공백인지, 소문자인지, 대문자인지 먼저 구별함 !
2. 공백이면, 다시 공백을 answer에 더해주고
3. 소문자이면, n을 더한 뒤 122가 넘는 요소는 다시 97부터 시작하도록, 안 넘으면 더한 값 그대로 new_ord에 저장
4. 대문자이면, n을 더한 뒤 90이 넘는 요소는 다시 65부터 시작하도록, 안 넘으면 더한 값 그대로 new_ord에 저장
5. new_ord를 char로 바꾼 값을 answer에 더한다.

# 'a' - 97, 'A' - 65
# 'z' - 122, 'Z' - 90
# 알파벳은 - 26개
'''

def solution(s, n):
    answer = ''
    for char in s:
        if char == ' ': 
            answer += ' '
            continue
        # 소문자
        if 97 <= ord(char) <= 122:
            new_ord = ord(char) + n
            if new_ord > 122:
                new_ord = 97 + (new_ord - 122) - 1
        # 대문자
        elif 65 <= ord(char) <= 90:
            new_ord = ord(char) + n
            if new_ord > 90:
                new_ord = 65 + (new_ord - 90) - 1
        answer += chr(new_ord)
    return answer