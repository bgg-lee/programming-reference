'''
* 🤷‍♂️ Created by wwlee94 on 2020.05.08
https://programmers.co.kr/learn/courses/30/lessons/64064
# 프로그래머스 LV3

- 문제 풀이 접근 -
1. 순열로 모든 경우의 수 구한 후 찾는 방식
   itertools.permutations 모듈을 사용하여 모든 경우의 수를 찾아 비교해본다.

2. 밴 당한 후보를 우선적으로 구한 후 dfs 백트래킹을 사용한 방식
   
   # 중간에 기존에 있던 레퍼런스들이 아닌 deepcopy를 이용해 기존 내용이 똑같이 담긴 새로운 리스트들이 생성되는데
   # 그렇게 하지 않으면 재귀를 이용한 백트랙킹이 안되기 때문이다.
'''

# https://covenant.tistory.com/158
# permutations를 사용한 방식
# from itertools import permutations
# def is_match(ban_id, user_id):
#     if len(ban_id) != len(user_id): 
#         return False
    
#     for x in range(len(ban_id)):
#         if ban_id[x] == '*': continue
#         if ban_id[x] != user_id[x]:
#             return False
#     return True

# def check(banned_ids, candidate):
#     for i in range(len(banned_ids)):
#         if len(banned_ids[i]) != len(candidate[i]): # 길이 안 맞으면 패스
#             return False
#         if is_match(banned_ids[i], candidate[i]) is False:
#             return False
#     return True
 
# def solution(user_ids, banned_ids):
#     answer = list()
#     for candidate in permutations(user_ids, len(banned_ids)):
#         if check(banned_ids, candidate) is True:
#             candidate = set(candidate)
#             if candidate not in answer:
#                 answer.append(candidate)
#     return len(answer)

# 백트래킹을 활용한 방식
import copy
def solution(user_id, banned_id):
    candidates = []
    
    # 각각의 매칭되는 제재 아이디 구하기
    for i in range(len(banned_id)):
        temp = []
        for j in range(len(user_id)):
            res = is_match(banned_id[i], user_id[j])
            if res: temp.append(user_id[j]) 
        candidates.append(temp)
        
    global results
    results = []
    # candidate 구한 후 dfs 로 백트래킹 접근하면 풀이 가능
    dfs(candidates, user_id, [])
    
    return len(set(results))

# 밴 된 유저와 현재 검사하려는 유저가 일치하는지
def is_match(ban_check, user_check):
    if len(ban_check) != len(user_check): 
        return False
    
    for x in range(len(ban_check)):
        if ban_check[x] == '*': continue
        if ban_check[x] != user_check[x]:
            return False
    return True

# 백트래킹 or dfs
def dfs(candidates, user_ids, visited):
    global results
    if len(candidates) == 0: 
        results.append(tuple(sorted(visited))) # 튜플은 set으로 변경이 가능해서 튜플로 변경
        return
    
    candidate = candidates.pop(0) # 
    for i in range(len(candidate)):
        new_visited = copy.deepcopy(visited)
        new_candidates = copy.deepcopy(candidates)
        
        if candidate[i] not in new_visited:
            new_visited.append(candidate[i])
            dfs(new_candidates, user_ids, new_visited)

# candidates 예시
# 아래와 같은 밴 할 후보들을 만든 후 dfs로 돌면서 원하는 조건에 맞으면 계속 탐색하고 아니면 패스하는 식으로 문제를 접근
# [frodo, fradi] / [abc123] - 2
# [frodo, crodo] / [frodo, crodo] / [abc123, frodoc] - 2
# [frodo, fradi] / [frodo, crodo] / [abc123, frodoc] / [abc123, frodoc] - 3