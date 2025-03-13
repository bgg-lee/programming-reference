class GNode:   
    def __init__(self, id, color = 'W', d = None, p = None):        
        self.id = id        
        self.distance = d                 
  
    
r, s, t, u, v = GNode('r'), GNode('s'), GNode('t'), GNode('u'), GNode('v')
w, x, y = GNode('w'), GNode('x'), GNode('y')
    
G = dict()
    
G[r], G[s], G[t], G[u], G[v] = [s, v], [r, w], [w, x, u], [t, x, y], [r]
G[w], G[x], G[y] = [s, t, x], [w, t, u, y], [x, u]

from collections import deque

def bfs(G, s):
    # 1) 모든 노드 distance 초기화: None (아직 방문 안 함)
    for node in G:
        node.distance = None

    # 2) 시작 노드만 distance=0으로 설정
    s.distance = 0

    # 3) 방문 집합(visited) 사용 (또는 color 사용 가능)
    visited = set([s])

    # 4) 큐 초기화
    q = deque([s])

    # 5) BFS 순회 순서 저장 리스트
    ans = []

    while q:
        curr = q.popleft()
        ans.append(curr)

        # 인접 노드 확인
        for nxt in G[curr]:
            # 아직 방문 안 했으면
            if nxt not in visited:
                visited.add(nxt)
                nxt.distance = curr.distance + 1
                q.append(nxt)

    return ans


def level_partition(G, s):
    v = bfs(G, s)
    res = [[] for i in range(v[-1].distance+1)]
    for i in range(len(v)):
        res[v[i].distance].append(v[i].id)
    return res
print(bfs(G, s))
print(level_partition(G, s))


