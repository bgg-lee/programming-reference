'''
* 🤷‍♂️ Created by wwlee94 on 2020.06.16
https://programmers.co.kr/learn/courses/30/lessons/42861

- 문제 풀이 접근 - 
https://wwlee94.github.io/category/algorithm/greedy/island-connection/
'''

# 최소의 비용으로 그래프를 연결하는 알고리즘이므로 크루스칼, 프림 알고리즘을 사용해야합니다.
# 크루스칼 알고리즘 사용 !
def solution(n, costs):
    # 부모 노드를 찾는 함수
    def get_parent(parent, x):
        if parent[x] == x: return x
        parent[x] = get_parent(parent, parent[x])
        return parent[x]
    
    # 두 부모 노드를 합치는 함수
    def union_parent(parent, x, y):
        x = get_parent(parent, x)
        y = get_parent(parent, y)
        
        # 더 작은 값을 부모로 지칭
        if x < y: parent[y] = x
        else: parent[x] = y
            
    def is_same_parent(parent, x, y):
        x = get_parent(parent, x)
        y = get_parent(parent, y)
        
        if x == y: return True
        else: return False
    
    # 주어진 간선이 최소 간선의 개수 일때 (n-1개)
    if len(costs) == n-1:
        return sum(map(lambda x:x[2], costs))
    
    # 특정 간선의 부모 정보 (초기는 자기 자신을 가리킴)
    parent = [0] * len(costs)
    for i in range(len(costs)):
        parent[i] = i
        
    answer = []
    costs.sort(key=lambda x:x[2]) # 비용이 가장 작은 간선부터 선택
    
    # 총 만들어지는 선의 개수는 n-1개
    while len(answer) < n-1:
        edge = costs.pop(0)
        # 두 점의 부모가 같은지 Check
        if not is_same_parent(parent, edge[0], edge[1]):
            union_parent(parent, edge[0], edge[1])
            answer.append(edge[2])
    
    return sum(answer)