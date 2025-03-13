# Graph DFS 문제 lexicographically Weight을 따지는데, 걍 SSSP 비슷한 느낌이다.
# GG
# 아래 풀이는 DFS + Backtracking in graph
# 겁나 어려운데..

class GNode:
    def __init__(self, id, color = "W", d = -1, f = -1, p = None):
        self.id = id # id is a string
        self.color = color # color (status) of node
        self.d = d # discover time of node
        self.f = f # finish time of node
        self.parent = p # predecessor time of node
    def __str__(self):
        return self.id

# def dfs(G,path,v):
#     if(path[-1]==v) : return list([i.id for i in path])

# def LexSmallest(G, u, v):
#     """
#     G : { GNode -> list of GNode } 형태의 undirected graph (adjacency list)
#     u, v : 시작 GNode, 목표 GNode
#     반환: u에서 v로 가는 "사전순으로 가장 작은 경로" (노드 id를 나열한 list).
#          경로가 없으면 [] 반환.
#     """
#     # 전체 그래프에 u, v가 없거나 잘못된 입력일 수도 있으므로 간단히 체크
#     if u not in G or v not in G:
#         return []

#     # best_path[0]에 현재까지 찾은 "사전순으로 가장 작은 경로" 저장
#     # 초기에는 None
#     best_path = [None]

#     visited = set()
#     visited.add(u)

#     def dfs(current, path):
#         # current가 목표 v이면, best_path와 비교 후 갱신
#         if current == v:
#             # 사전순 비교
#             if best_path[0] is None or path < best_path[0]:
#                 best_path[0] = path[:]
#             return

#         # 사전순으로 이웃들을 정렬하여 DFS
#         neighbors = sorted(G[current], key=lambda node: node.id)
#         for nxt in neighbors:
#             if nxt not in visited:
#                 visited.add(nxt)
#                 path.append(nxt.id)
                
#                 dfs(nxt, path)
                
#                 # 백트랙
#                 visited.remove(nxt)
#                 path.pop()

#     # 시작 노드 u의 경로를 [u.id] 로 두고 DFS 시작
#     dfs(u, [u.id])
    
#     # best_path[0] 이 None이면 경로가 없었다는 뜻
#     return best_path[0] if best_path[0] is not None else []

### 다른 풀이 ###
def lexcomp(l1, l2):
    # 0: l1이 l2보다 사전순으로 앞섬
    # 1: l1이 l2보다 사전순으로 뒤섬
    # 2: (초깃값, 혹은 아직 결판이 안 난 상태로 의미 있음)
    
    res = 2
    if (l1 != l2):
        i = 0
        # 둘 중 더 짧은 길이까지 순차 비교
        while (i < min(len(l1), len(l2))):
            if l1[i] < l2[i]:
                res = 0
                break
            elif l1[i] > l2[i]:
                res = 1
                break
            else:
                i += 1

        if (res == 2):  # 아직 결판이 안 났다면 (공통부분이 동일)
            if len(l1) > len(l2):
                res = 1
            else:
                res = 0
    
    return res

def dfs(G, path, v):
    if (path[-1] == v):
        # 현재 경로의 마지막 노드가 목표라면, 이 경로를 리스트 형태로 반환
        return list([ i.id for i in path ])
    else:
        res = []  # 아직 찾은 경로가 없으므로 빈 리스트
        for next in G[path[-1]]:
            if (next not in path):   # 이미 경로에 있는 노드는 중복 방문 X
                newpath = path + [next]
                
                # DFS 재귀 호출
                tmp = dfs(G, newpath, v)
                
                # 'tmp'가 빈 리스트가 아니고
                # 기존 'res'가 비어 있거나 OR (res vs tmp 를 비교해서 tmp가 더 사전순으로 앞서면)
                if (len(res) == 0 or (len(tmp) != 0 and lexcomp(res, tmp) == 1)):
                    res = tmp
        return res

def LexSmallest(G, u, v):
    path = dfs(G, [u], v)
    return path

if __name__ == "__main__":
    r, s, t, u = GNode('r'), GNode('s'), GNode('t'), GNode('u')
    v, w, x, y = GNode('v'), GNode('w'), GNode('x'), GNode('y')

    G = dict()
    G[r], G[w], G[t], G[u] = [w, v], [s, r, t], [s, x, w], [y]
    G[v], G[s], G[x], G[y] = [r], [w, t, x], [s, t], [u]

    print(LexSmallest(G, t, v))
    print(LexSmallest(G, u, u))
    print(LexSmallest(G, w, y))
