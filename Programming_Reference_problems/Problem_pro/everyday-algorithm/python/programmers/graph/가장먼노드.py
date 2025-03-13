'''
* 🤷‍♂️ Created by wwlee94 on 2020.02.11
https://programmers.co.kr/learn/courses/30/lessons/49189

- 문제를 풀기 전에 두 접근 방식의 차이를 알자 ! -
# 인접 리스트 VS 인접 행렬
1. 인접 리스트 
- 장점 -
1. 인접한 노드를 쉽게 알 수 있다.
2. 모든 간선의 수는 O(N+E) 안에 알 수 있다. (E: 간선의 수)

2. 인접 행렬
- 장점 -
1. 간선 존재 여부를 O(1)로 알 수 있다.
2. 정점의 차수는 O(N) 안에 알 수 있다. (인접 배열의 i번 째 행 또는 열을 모두 더한다.)

- 문제 풀이 접근 (인접 리스트) - 
# 필요한 노드만 추가해서 푼 방식 -> N * N 행렬을 만들지 않고 필요한 부분만
EX) 	
입력 > 6, [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]
graph > [[2, 1], [2, 0, 3, 4], [5, 3, 1, 0], [2, 1], [1], [2]]
graph[0] -> 1번 노드와 연결된 리스트를 담음! -> 1번 노드는 3번, 2번 노드와 연결 !
'''
def solution(n, edge):
    graph =[  [] for _ in range(n) ]
    distances = [ 0 for _ in range(n) ]
    is_visit = [False for _ in range(n)]
    queue = [0]
    is_visit[0] = True
    for (a, b) in edge:
        graph[a-1].append(b-1)
        graph[b-1].append(a-1)

    while queue:
        i = queue.pop(0)

        for j in graph[i]:
            if is_visit[j] == False:
                is_visit[j] = True
                queue.append(j)
                distances[j] = distances[i] + 1

    distances.sort(reverse=True)
    answer = distances.count(distances[0])

    return answer

# - 시간 초과로 못 푼 코드 (인접 행렬) -
# 인접 행렬로 표현된 무방향 그래프
# 그래프의 최단 경로로 이동했을 때 가장 먼 거리를 구함 - N * N 배열을 만들어서 푼 방식 -> 7,8,9 시간초과
# from collections import deque
# def solution(n, edge):
#     answer = 0
#     matrix = [[0 for _ in range(n)] for _ in range(n) ]
#     for ed in edge:
#         matrix[ed[0]-1][ed[1]-1] = 1
#         matrix[ed[1]-1][ed[0]-1] = 1 # 무방향
        
#     queue = deque([0])
#     visited = [0 for _ in range(n)] # 방문 했으면 1
#     visited[0] = 1
#     edge_count = [0 for _ in range(n)] # 노드 0과 노드 i 사이의 거리
#     while queue:
#         i = queue.popleft()
#         visited[i] = 1
#         for j in range(n):
#             if visited[j] == 0:
#                 if matrix[i][j] == 1:
#                     if j not in queue:
#                         queue.append(j)
#                         edge_count[j] = edge_count[j] + (edge_count[i] + 1)
#     _max = max(edge_count)
#     for i in range(n):
#         if edge_count[i] == _max:
#             answer += 1
#     return answer