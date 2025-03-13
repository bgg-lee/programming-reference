"""
Problem 1: "Shortest Path Using Dijkstra's Algorithm"
Problem Description:
You are given a graph represented as an adjacency list with n nodes labeled 0 to n-1. Each edge has a positive weight. Your task is to find the shortest distance from the starting node to all other nodes using Dijkstra's Algorithm. Return -1 for nodes that are unreachable.

Input:
n: Number of nodes in the graph.
edges: A list of tuples where (u, v, w) represents a directed edge from node u to node v with weight w.
start: The starting node.
Output:
A list of integers where the ith value is the shortest distance from the start node to node i. Return -1 for unreachable nodes.

Example:
Input:
n = 5
edges = [
    (0, 1, 2),
    (0, 2, 4),
    (1, 2, 1),
    (1, 3, 7),
    (2, 3, 3),
    (3, 4, 1)
]
start = 0

Output:
[0, 2, 3, 6, 7]
"""
# 위 문제는 기본적으로 Graph 에서 Staring Node로부터 각 Node까지의 최소 Weight을 구하는 것으로 시작한다.
from heapq import heappush, heappop
from typing import List, Tuple

def dijkstra(n: int, edges: List[Tuple[int, int, int]], start: int) -> List[int]:
    # ADJ list를 만든다
    adj = [ [] for _ in range(n) ] # n은 Node의 개수
    for u,v,w in edges :
        adj[u].append((v,w))

    # Distance / Priority Queue 초기화 --> Heap을 쓴다는 것!
    dist = [float('inf')] * n # float('inf') == INT_MAX
    dist[start] = 0
    pq = [(0,start)] # (distance, node)

    # Dijkstra's algorithm
    while pq :
        curr_dist, node = heappop(pq)
        # Greedy
        if curr_dist > dist[node]:
            continue
        
        for neighbor, weight in adj[node]:
            new_dist = curr_dist + weight
            if new_dist < dist[neighbor]:
                dist[neighbor] = new_dist
                heappush(pq,(new_dist,neighbor))
    return [ d if d!=float('inf') else -1 for d in dist]

# Test case
n = 6
edges = [
    (0, 1, 2),
    (0, 2, 4),
    (1, 2, 1),
    (1, 3, 7),
    (2, 3, 3),
    (3, 4, 1),
    (5, 5, 1)
]
start = 0
print(dijkstra(n, edges, start))  # Expected: [0, 2, 3, 6, 7,-1]

# 그럼 한 그래프에서 Staring Node로부터 모든 Node를 다 방문하는 데 걸리는 최소 Weight / Path를 구하는 건 어떻게 할까?
# ( Graph는 모두 connected 되어 있고, Negative Cycle이 없다는 가정 하에) -> Negative가 있는건 Bellman-Ford
# 그리고 이 방법은 통상 one-to-all 이라고 하는데, all-to-all 인 플로이드 워셜이랑 이 놈의 차이는 뭘까?

