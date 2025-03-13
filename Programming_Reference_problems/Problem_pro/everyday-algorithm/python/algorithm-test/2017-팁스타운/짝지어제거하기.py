'''
* 🤷‍♂️ Created by wwlee94 on 2020.05.24
https://programmers.co.kr/learn/courses/30/lessons/12973

- 문제 접근 방식 -
1. 빠르게 종료될 수 있는 조건들 2가지 (선택?!)
    1. 문자열길이가 홀수인 경우 제외
    2. 각 짝들의 개수가 홀수인 경우 제외
2. 스택을 사용하여 각 문자를 제거해줘야함 !
    (첫 문제 풀이 경우, 문자열을 직접 파싱하려 했음 -> 꼭 스택을 사용할 것!)

- 주의 사항 -
문자열 파싱으로 작업하면, 1,000,000이라는 문자열 길이 때문에 시간초과가 발생한다.
stack 자료구조로 문자열의 앞에서부터 값을 집어넣고, 남은 문자열의 맨 앞단과 스택의 가장 윗값을 비교하면 해결 가능 
또한, deque 라이브러리로 popleft를 활용하면, 일반 리스트를 활용한 것보다 처리속도가 빠름
'''

from collections import deque
def solution(s):
    s = deque(list(s))
    stack = []
    stack.append(s.popleft())
    while s:
        # stack이 비었으면 삽입
        if len(stack) == 0:
            stack.append(s.popleft())
            
        # 스택 맨 앞값과 남은 string의 맨 앞 비교. 
        # 같을 경우 stack과 s에서 둘 다 제거한다.
        elif stack[-1] == s[0]:
            stack.pop()
            s.popleft()
        else:
        # 값이 다르면, stack에 다음 string의 맨 앞 값을 넣는다.
            stack.append(s.popleft())
    
    # stack에 값이 남아 있으면 짝지어 제거하기 실패한 것.
    if len(stack) != 0:
        return 0
    else:
        return 1

# # 시간 초과
# import collections
# def solution(s):
#     def is_even(_dict):
#         for key in _dict:
#             if _dict[key] % 2 == 1:
#                 return False
#         return True
    
#     answer = 0
#     # 문자열길이가 홀수인 경우 제외
#     if len(s) % 2 == 1:
#         return 0
    
#     # 각 짝들의 개수가 홀수인 경우 제외
#     counter = collections.Counter(s)
#     state = is_even(counter)
#     if not state: 
#         return 0
    
#     string = list(s)
#     left_p = 0
#     right_p = 1
    
#     while 1:
#         leng = len(string)
#         if right_p >= leng:
#             break

#         if string[left_p] == string[right_p]:
#             del string[left_p], string[right_p-1] # left 먼저 삭제하니 right-1 지워줘야함
#             if left_p != 0: left_p -= 1
#             if right_p != 1 : right_p -= 1
#         else:
#             left_p += 1
#             right_p += 1
    
#     if len(string) == 0:
#         return 1
#     return 0