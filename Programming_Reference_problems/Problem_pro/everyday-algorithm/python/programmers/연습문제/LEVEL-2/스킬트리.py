'''
* 🤷‍♂️ Created by wwlee94 on 2020.04.07
https://programmers.co.kr/learn/courses/30/lessons/49993
# 프로그래머스 LV2

- 문제 풀이 접근 -
1. 각 스킬의 위치를 찾는다.
2. 만약 스킬이 없으면 스킬 길이의 제한값인 26보다 큰 수로 넣어준다.
3. 해당 스킬 순서의 배열이 정렬되어 있으면 가능한 스킬트리 정렬이 안되어 있으면 불가능한 스킬트리이다.
'''
def solution(skill, skill_trees): 
    answer = 0 
    for skill_tree in skill_trees: 
        pre_idx = [] 
        for i in range(len(skill)): 
            idx = skill_tree.find(skill[i])
            if idx == -1: 
                pre_idx.append(30) # 핵심 1
            else: 
                pre_idx.append(idx) 

        if sorted(pre_idx) == pre_idx: # 핵심 2
            answer += 1 
    return answer

# 다른 간결한 풀이
# for-else는 중간에 break 등으로 끊기지 않고 끝까지 수행되면 else문이 실행되는 loop
'''
def solution(skill, skill_trees):
    answer = 0

    for skills in skill_trees:
        skill_list = list(skill)

        for s in skills:
            if s in skill:
                if s != skill_list.pop(0):
                    break
        else:
            answer += 1

    return answer
'''