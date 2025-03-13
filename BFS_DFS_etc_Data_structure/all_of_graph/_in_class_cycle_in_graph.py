def has_cycle_undirected(adj: list[list[int]]) -> bool:
    n = len(adj)
    visited = [False] * n

    def dfs_util(v:int): # parent을 써라 parameter로.. undirected graph라서 그렇다.
        visited[v] = True
        for x in adj[v]:
            if not visited[x]:
                visited[x] = True
                dfs_util(x)
    
    # Perform DFS from all vertices
    for i in range(n):
        if not visited[i]:
            dfs_util(i)

    return False  # No cycle detected

"""
0 1 2 3 4
"""

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