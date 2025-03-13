from collections import deque

class GNode:
    def __init__(self, id=0, color="W", p=None):
        self.id = id
        self.color = color
        self.parent = p
    def __str__(self):
        return self.id
    def __hash__(self):
        return hash(self.id)
        
def bfs(vis, curr, graph):
    vis[curr] = 1
    qq = deque([])
    qq.append(curr)
    
    while (len(qq) != 0):
        popped = qq.popleft()
        for nei in graph[popped]:
            if (vis[nei] == 0):
                vis[nei] = 1
                qq.append(nei)
                

def find_root_vertices(G):
    ans = []
    tot_node = len(G.keys())
    for g in G.keys():
        visited = 0
        vis = {i:0 for i in G.keys()}
        bfs(vis, g, G)
        for k, v in vis.items():
            if v == 1:
                visited += 1
            
        if visited >= tot_node:
            ans.append(g.id)
        
    return ans
    
    
    
# if __name__ == "__main__":
#     A, B, C = GNode('A'), GNode('B'), GNode('C')
#     D, E, F = GNode('D'), GNode('E'), GNode('F')
#     G = dict()
#     G[A], G[B], G[C] = [C,D], [A,E], [B,D]
#     G[D], G[E], G[F] = [F], [F], []
#     print(find_root_vertices(G))
    
    
#     A, B, C = GNode('A'), GNode('B'), GNode('C')
#     D, E, F = GNode('D'), GNode('E'), GNode('F')
#     G = dict()
#     G[A], G[B], G[C] = [D], [E], [B,D]
#     G[D], G[E], G[F] = [F], [F], []
#     print(find_root_vertices(G))
    
    
#     A, B, C = GNode('A'), GNode('B'), GNode('C')
#     D, E, F = GNode('D'), GNode('E'), GNode('F')
#     G = dict()
#     G[A], G[B], G[C] = [B,D], [E], [B,D]
#     G[D], G[E], G[F] = [C,F], [F], []
#     print(find_root_vertices(G))