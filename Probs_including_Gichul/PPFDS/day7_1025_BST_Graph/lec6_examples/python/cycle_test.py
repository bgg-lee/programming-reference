# graph 에서 cycle detect하는 code, parent를 이용해라
def has_cycle_undirected(adj: list[list[int]]) -> bool:
    visited = []
    def dfs(node:int,parent:int)->bool:
        s = [(node,parent)]
        while s:
            curr,pa = s.pop()
            visited.append(curr)
            for next in adj[curr]:
                if next not in visited:
                    s.append((next,curr))
                else:
                    if next != pa : return True
        return False
    for i in range(len(adj)):
        if i not in visited:
           if dfs(i,-1) : return True
    return False

def has_cycle_undirected(adj: list[list[int]]) -> bool:
    n = len(adj)
    visited = [False] * n

    def dfs_stack(start: int, parent: int) -> bool:
        stack = [(start, parent)]
        visited[start] = True

        while stack:
            u, par = stack.pop()
            for w in adj[u]:
                if not visited[w]:
                    visited[w] = True
                    stack.append((w, u))
                # 이미 방문 + 부모가 아니라면 => 사이클
                elif w != par:
                    return True
        return False

    for i in range(n):
        if not visited[i]:
            if dfs_stack(i, -1):  # i의 부모는 없다 가정(-1)
                return True
    return False

 # 재귀버전
def has_cycle_undirected(adj: list[list[int]]) -> bool:
    n = len(adj)
    visited = [False]*n

    def dfs(u:int, parent:int) -> bool:
        visited[u] = True
        for w in adj[u]:
            if not visited[w]:
                if dfs(w, u):
                    return True
            elif w != parent:
                return True
        return False

    for i in range(n):
        if not visited[i]:
            if dfs(i, -1):
                return True
    return False


if __name__ == "__main__":
    # Example 1: Undirected Graph with a cycle
    undirected_graph_with_cycle = [
        [1],    # Neighbors of vertex 0
        [0, 2], # Neighbors of vertex 1
        [1, 3], # Neighbors of vertex 2
        [2, 4], # Neighbors of vertex 3
        [3]     # Neighbors of vertex 4
    ]

    print("Cycle in undirected graph (should be False):", has_cycle_undirected(undirected_graph_with_cycle))

    # Adding an edge to create a cycle (2-4)
    # undirected_graph_with_cycle[2].append(4)
    # undirected_graph_with_cycle[4].append(2)
    # undirected_graph_with_cycle[0].append(3)
    undirected_graph_with_cycle[4].append(0)
    undirected_graph_with_cycle[0].append(4)
    print("Cycle in undirected graph (should be True):", has_cycle_undirected(undirected_graph_with_cycle))
