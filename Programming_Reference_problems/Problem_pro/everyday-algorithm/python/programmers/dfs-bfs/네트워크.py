'''
* 🤷‍♂️ Created by wwlee94 on 2020.06.19
https://programmers.co.kr/learn/courses/30/lessons/43162

- 문제 풀이 접근 -
https://wwlee94.github.io/category/algorithm/bfs-dfs/network/
'''

# 다른 부모가 몇개인지 파악하는 문제 !
# Union-Find 사용하면 간단할 듯
import collections
def solution(n, computers):
    
    # 부모 값을 반환하는 함수
    def get_parent(parent, x):
        if parent[x] == x: return x
        parent[x] = get_parent(parent, parent[x])
        return parent[x]
        
    # 두 개의 노드를 연결하는 함수
    def union_parent(parent, x, y):
        a = get_parent(parent, x)
        b = get_parent(parent, y)
        
        if a > b: parent[a] = b
        else: parent[b] = a
        
    parent = []
    for i in range(n):
        parent.append(i)
        
    for i in range(n):
        for j in range(n):
            if i != j and computers[i][j] == 1:
                union_parent(parent, i, j)
    
    # answer = collections.Counter(parent) # 이렇게 구하면 9번 테스트 케이스 틀림 1
    # answer = list(set(parent)) # 2
    # 최종적으로 get_parent를 다시 해주어야한다?
    answer = set()
    for i in range(n):
        parent[i] = get_parent(parent, i);
        answer.add(parent[i]);
    return len(answer)