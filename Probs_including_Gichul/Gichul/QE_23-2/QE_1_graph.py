"""
**[문제 설명: find_root_vertices]**

어떤 Directed Graph가 주어졌다고 하자. 즉, parent node와 child node가 정해져 있는 Graph이다.

이 때, 주어진 그래프를 구성하는 vertices 중, 다른 모든 vertice에 도달할 수 있는 vertices를 찾아서
각 vertice가 갖는 값을 string list ( e.g., ['A', 'B', 'C'] ) 로 반환하는 find_root_vertices(G)를 구현하라. 이 때, bfs를 활용하라.
만약 해당되는 vertice가 없을 경우 emtpy list [] 를 return 하라.

**[문제 요약]**

- 주어진 그래프에 대해, 모든 vertices에 도달할 수 있는 vertices를 반환하는 함수 find_root_vertices(G)를 구현하라.
- 반환하는 값은 각 vertice가 갖는 값으로 구성된 string list이다. ( e.g., ['A', 'B', 'C'] )
- bfs를 활용하라.

**[출력 예시]**

>> A, B, C = GNode('A'), GNode('B'), GNode('C')
>> D, E, F = GNode('D'), GNode('E'), GNode('F')
    
>> G = dict()
    
>> G[A], G[B], G[C] = [C,D], [A,F], [D,B]
>> G[D], G[E], G[F] = [E], [F], []
    
>> find_root_vertices(G)
['A', 'B', 'C']
"""
class GNode:   
    def __init__(self, id, color='W', p=None):        
        self.id = id        
        self.color = color        
        self.parent = p            
        def __str__(self):        
            return self.id        
        def __hash__(self):        
            return hash(self.id)
def bfs(node : GNode) -> list[GNode]:
    visited = []
    from collections import deque
    q = deque([node])
    while q :
        curr = q.popleft()
        if curr in visited : continue
        # 방문체크 하기
        visited.append(curr)
        for next in G[curr]:
            q.append(next)
    
    return visited

def find_root_vertices(G:dict) -> list[str]:
    n = len(G)
    ans = []
    for node in G:
        temp = bfs(node)
        if len(temp) == n: # 모든 node를 다 방문가능한 vertext
            ans.append(node.id)
    return ans

if __name__ == "__main__":
    A, B, C = GNode('A'), GNode('B'), GNode('C')
    D, E, F = GNode('D'), GNode('E'), GNode('F')
        
    G = dict()
        
    G[A], G[B], G[C] = [C,D], [A,F], [D,B]
    G[D], G[E], G[F] = [E], [F], []
    
    G2 = dict()
    G2[A] = [B]
    G2[C] = []

    print(find_root_vertices(G)) # ['A', 'B', 'C']
    print(find_root_vertices(G2)) # []