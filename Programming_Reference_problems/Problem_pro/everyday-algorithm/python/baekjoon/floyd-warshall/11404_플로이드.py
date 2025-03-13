'''
* 🤷‍♂️ Created by wwlee94 on 2020.02.14
# https://www.acmicpc.net/problem/11404

* 플로이드-와샬 알고리즘 (Floyd-Warshall Algorithm)      
- '모든 정점'에서 '다른 모든 정점'으로의 최단 경로를 구하는 알고리즘 
- '거쳐가는 정점'을 기준으로 수행

* 다익스트라 알고리즘 (Dijkstra algorithm)
- '하나의 정점'에서 '다른 모든 정점'으로의 최단 경로를 구하는 알고리즘
- '가장 적은 비용'을 하나씩 선택하는 방식으로 수행
'''

N = int(input()) # 도시의 개수
M = int(input()) # 버스의 개수
bus_info = [list(map(int, input().split(' '))) for _ in range(M)]

graph = [[9999 for _ in range(N)] for _ in range(N)]

# bus_info의 정보로 graph(각 정점이 다른 정점으로 가는 비용을 구한 이차원 배열)을 구한다. 
for info in bus_info:
    start = info[0] - 1
    end = info[1] - 1
    value = info[2]
    graph[start][end] = min(value, graph[start][end])

# 못 푼 부분 - 이 부분이 플로이드와샬 알고리즘의 핵심 !
# k: 거쳐가는 노드
for k in range(N):
    # i: 시작 노드
    for i in range(N):
        # j: 도착 노드
        for j in range(N):
            if i==j: graph[i][j] = 0
            else: graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
            # if graph[i][j] > graph[i][k] + graph[k][j]:
            #     graph[i][j] = graph[i][k] + graph[k][j]

# 답 출력
for i in range(N):
    for j in range(N):
        if graph[i][j] == 9999: # 못가는 경로는 '0'으로 표시하라는 지문이 있음
            print(0, end=' ')
        else:
            print(graph[i][j], end=' ')
    print()
