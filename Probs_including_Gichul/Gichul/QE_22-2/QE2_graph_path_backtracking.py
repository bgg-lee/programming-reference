# Cyclic (X) Acyclic directed graph G
# Graph 그래프 pathe backtracking # Node간 모든 연결 path를 찾아라 route를 찾아라!!

class GNode:
    def __init__(self, id):
        self.id = id # id is a string
    def __str__(self):
        return self.id 

def paths(G:dict,s:GNode,t:GNode) -> list[list[str]]:
    # 이게 backtracking..? bfs 때리면 되지 않을까
    ans = []
    def dfs(curr:GNode,path:list[str]) -> None:
        if curr == t :
            ans.append(path[:])
            return
        for node in G[curr]:
            dfs(node,path+[node.id])
    # 완
    dfs(s,[s.id])
    return ans


if __name__ == "__main__":
    a, b, c, d = GNode('a'), GNode('b'), GNode('c'), GNode('d')
    G = dict()
    G[a], G[b], G[c], G[d] = [b, c], [d], [], [c]

    print(paths(G,a,c)) # [["a","c"],["a","b","d","c"]] # Any order is OK
