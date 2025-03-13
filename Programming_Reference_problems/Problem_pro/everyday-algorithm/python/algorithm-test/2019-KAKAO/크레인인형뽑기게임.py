'''
* 🙆‍♂️ Created by wwlee94 on 2020.04.03
https://programmers.co.kr/learn/courses/30/lessons/64061

- 문제 풀이 방법 -
프로그래머스 LV1 문제로 스택 사용해서 문제 설명대로 풀면 풀 수 있는 문제
인형이 터질 때 +2 해주는 것이 핵심이다 ~
'''

def solution(board, moves):
    answer = 0
    stack = []
    
    def pick(col):
        nonlocal board
        for row in board:
            if row[col] != 0:
                result = row[col]
                row[col] = 0
                return result
        return -1

    for move in moves:
        _type = pick(move-1)
        # 인형이 존재하면 !
        if _type != -1:
            if len(stack) == 0:
                stack.append(_type)
            else:
                top = stack[-1]
                if top == _type:
                    answer += 2
                    stack.pop()
                else:
                    stack.append(_type)
    return answer