'''
* 🤷‍♂️ Created by wwlee94 on 2020.07.01
https://programmers.co.kr/learn/courses/30/lessons/42895
'''

def solution(N, number):
    if N == number: #주어진 숫자와 사용해야 하는 숫자가 같은 경우는 1개면 족하므로 1으로 놓는다. 
        return 1
    S = [0, {N}]
    for i in range(2, 9): # 2부터 8까지로 횟수를 늘려 간다. 
        case_set = {int(str(N)*i)} # 5,55,555,5555 ...
        # 사용되는 숫자의 횟수를 구해야 하는데, 절반 이상으로 넘어가면 같은 결과만 나올 뿐이므로 절반까지만을 사용한다.
        # 이미 아래에서 y-x, y//x 와 같은 경우를 처리해주기 때문
        for i_half in range(1, i//2+1):  
            for x in S[i_half]:
                for y in S[i-i_half]:
                    case_set.add(x+y)
                    case_set.add(x-y) # 음수인 경우 제외해도 되는지?
                    case_set.add(y-x) # y-x 케이스 추가
                    case_set.add(x*y)
                    if x != 0: case_set.add(y//x)
                    if y != 0: case_set.add(x//y)
        if number in case_set:
            return i
        S.append(case_set) # 최종 결과물 set에 사칙 연산 결과를 더한다.
    return -1 #N 이 8까지 답이 없으면 -1을 출력한다.

# 재귀 -> 속도 느림
# def solution(N, number):
#     answer = -1
#     def dfs(count, start, oper):
#         nonlocal answer
#         if count > 8: return
#         if start == number:
#             # 최소 값 갱신, 초기값 갱신
#             if count < answer or answer == -1:
#                 print(oper)
#                 answer = count
#             return
        
#         x = 0
#         for i in range(0, 8-count): # count가 8을 안넘도록
#             x = x*10 + N
#             dfs(count + i+1, start + x, oper + '+');
#             dfs(count + i+1, start - x, oper + '-');
#             dfs(count + i+1, start * x, oper + '*');
#             dfs(count + i+1, start / x, oper + '/');
            
#     dfs(0, 0, '')
#     return answer