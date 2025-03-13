# undirected graph
graph = {
    'A': set(['B', 'C']),
    'B': set(['A', 'D', 'E']),
    'C': set(['A', 'F']),
    'D': set(['B']),
    'E': set(['B', 'F']),
    'F': set(['C', 'E'])
}

def bfs_paths(graph, start, goal):
    queue = [(start, [start])]
    result = []
    
    while queue:
        n, path = queue.pop(0)
        if n == goal:
            result.append(path)
        else:
            for m in graph[n] - set(path):
                queue.append((m, path + [m]))
    return result

# 맨 앞 경로가 최단 경로
print(bfs_paths(graph, 'A', 'F'))
print(bfs_paths(graph, 'D', 'F'))