class GNode :
    def __init__(self,id:str,color='W',d=0,p=None):
        self.id = id
        self.color = color
        self.distance = d
        self.parent = p
    def __str__(self):
        return self.id

def bfs(G:dict,s:GNode) -> list[GNode]:
    from collections import deque
    ans = []
    visited = []
    q = deque([s])
    while q:
        curr = q.popleft()
        if curr in visited : continue
        # 현재 Node 마킹 및 visit 처리
        ans.append(curr.id) # id를 반환
        visited.append(curr)
        for next in G[curr]:
            if next not in visited:
                q.append(next)
    return ans

def level_partition(G:dict,s:GNode) -> list[list[GNode]]:



    # lv 단위로 끊어보자. 현재 q의 크기별로 LV나누면 될 거 같다.
    # 문제는 bfs를 쓰라는데,, 안 쓰고도 할 수 있을 거 같은데.. 아래처럼
    from collections import deque
    ans = []
    visited = []
    q = deque([s])
    while q:
        lst = []
        lv = len(q)
        for i in range(lv):
            curr = q.popleft()
            if curr in visited : continue
            lst.append(curr.id) # id를 반환
            visited.append(curr)
            for next in G[curr]:
                if next not in visited:
                    q.append(next)
        if lst : ans.append(lst)
    return ans

if __name__ == "__main__":
    r, s, t, u, v = GNode('r'), GNode('s'), GNode('t'), GNode('u'), GNode('v')
    w, x, y = GNode('w'), GNode('x'), GNode('y')
    G = dict()
    G[r], G[s], G[t], G[u], G[v] = [s, v], [r, w], [w, x, u], [t, x, y], [r]
    G[w], G[x], G[y] = [s, t, x], [w, t, u, y], [x, u]
    print(bfs(G,s))
    print(level_partition(G,s))


"""
메모
level_partition를 “BFS”로 구현하는 일반적인 패턴
level_partition 함수를 짤 때, 다음 패턴이 “BFS를 이용한 레벨 분할”의 전형적인 구조입니다:

from collections import deque
def level_partition(G: dict, s: GNode) -> list[list[str]]:
    ans = []
    visited = set()
    queue = deque([s])

    # while문이 한 번 돌 때마다 "한 레벨"씩 처리
    while queue:
        level_size = len(queue)
        level_nodes = []
        for _ in range(level_size):
            curr = queue.popleft()
            if curr in visited:
                continue
            visited.add(curr)
            # 현재 레벨에 속한 노드를 기록
            level_nodes.append(curr.id)

            # 인접 노드 중 방문 안 한 노드를 큐에 추가
            for nxt in G[curr]:
                if nxt not in visited:
                    queue.append(nxt)

        if level_nodes:
            ans.append(level_nodes)

    return ans

bfs 함수를 “레벨 정보”까지 저장하도록 수정하는 방법 (대안)
def bfs(G: dict, s: GNode) -> list[GNode]:
    from collections import deque

    # 1) 모든 노드 초기화
    for node in G:
        node.color = 'W'
        node.distance = -1
        node.parent = None

    s.color = 'G'
    s.distance = 0

    queue = deque([s])
    order = []

    while queue:
        curr = queue.popleft()
        order.append(curr)

        for nxt in G[curr]:
            if nxt.color == 'W':
                nxt.color = 'G'
                nxt.distance = curr.distance + 1
                nxt.parent = curr
                queue.append(nxt)

        curr.color = 'B'

    return order
    
def level_partition(G: dict, s: GNode) -> list[list[str]]:
    # 1) 먼저 BFS를 실행해서 모든 노드 distance 세팅
    bfs(G, s)

    # 2) distance 값이 같은 노드들끼리 묶기
    from collections import defaultdict
    distance_map = defaultdict(list)
    for node in G:
        # node.distance가 0,1,2... 이런 식으로 세팅되어 있을 것
        distance_map[node.distance].append(node.id)

    # 3) distance를 오름차순으로 정렬해 결과 리스트 구성
    ans = []
    for dist in sorted(distance_map.keys()):
        ans.append(distance_map[dist])
    return ans

"""