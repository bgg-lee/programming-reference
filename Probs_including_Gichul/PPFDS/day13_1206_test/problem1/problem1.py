#given a tree with n nodes where n is even. The tree is numbered from 1 to n, has n-1 edges and its rooted at node 1. YOur task is to eliminate the maximum number of edges resulting in a set of disjoint trees where the number of nodes in each ree is divisible by 2
from collections import defaultdict
def problem1(n : int, edges : list[list[int]]) -> int:
    tree = {}
    for u, v in edges:
        if u not in tree:
            tree[u] = []
        if v not in tree:
            tree[v] = []
        tree[u].append(v)
        tree[v].append(u)
    
    # 노드 방문 여부와 서브트리 크기 계산
    visited = [False] * (n + 1)
    subtree_size = [0] * (n + 1)
    result = 0
    
    def dfs(node: int) -> int:
        visited[node] = True
        subtree_count = 1  # 현재 노드 포함
        for neighbor in tree[node]:
            if not visited[neighbor]:
                size = dfs(neighbor)
                # 서브트리 크기가 짝수라면 간선 제거 가능
                if size % 2 == 0:
                    nonlocal result
                    result += 1
                else:
                    subtree_count += size
        subtree_size[node] = subtree_count
        return subtree_count

    # 루트(1번 노드)에서 DFS 시작
    dfs(1)
    return result
    


if __name__ == "__main__":
    
    edges1 = [[2,1],[3,1],[4,3],[5,2],[6,1],[7,2],[8,6],[9,8],[10,8]]
    n1 = 10
    print(problem1(n1,edges1)) # 2
    edges2 = [[2,1],[4,2],[1,3]]
    n2 = 4
    print(problem1(n2,edges2)) # 1
    
