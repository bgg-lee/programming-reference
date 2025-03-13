'''
다익스트라(Dijkstra) 알고리즘은 다이나믹 프로그래밍을 활용한 대표적인 최단 경로(Shortest Path) 탐색 알고리즘입니다.
흔히 인공 위성 GPS 소프트웨어 등에서 가장 많이 사용됩니다.

다익스트라 알고리즘은 특정한 하나의 정점에서 다른 모든 정점으로 가는 최단 경로를 알려줍니다.
다만 이때, 음의 간선을 포함할 수 없습니다.
음의 간선은 현실 세계에서 존재 하지 않기 때문에 다익스트라는 현실 세계에 사용하기 매우 적합한 알고리즘 중 하나라고 볼 수 있습니다.

다익스트라 알고리즘은 '다이나믹 프로그래밍'으로도 불리고 '그리디 알고리즘'이라고도 불립니다.
'다이나믹 프로그래밍'이라고 불리는 이유는 최단 거리는 여러 개의 최단 거리로 이루어져있기 때문입니다.
다시 말해, '다익스트라 알고리즘'은 현재까지 알고 있던 최단 경로를 계속해서 갱신합니다.

# 동작 과정
pre. 인접 행렬(2차원 배열)로 각 노드의 간선을 연결

1. 출발 노드를 설정합니다.
2. 출발 노드를 기준으로 각 노드의 최소 비용을 저장합니다.

3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드를 선택합니다.
4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하려 최소 비용을 갱신합니다.
5. 위 과정에서 3 ~ 4번을 반복합니다.
'''

'''
# 선형 탐색으로 만든 다익스트라 -> O(N^2) 시간 복잡도를 가진다.
힙으로 구현하게 되면 O(N*logN) 시간 복잡도를 가지는 다익스트라 구현 가능 !
'''
'''
number = 6 # 노드의 개수
INF = 1000000000 # 무한의 수치

# 전체 그래프 초기화 -> 인접 행렬로
graph = [
  [0, 2, 5, 1, INF, INF],
  [2, 0, 3, 2, INF, INF],
  [5, 3, 0, 3, 1, 5],
  [1, 2, 3, 0, 1, INF],
  [INF, INF, 1, 1, 0, 2],
  [INF, INF, 5, INF, 2, 0]
]

# 방문한 노드 리스트
visited = [0] * number
# 최단 거리
distance = [0] * number

# 가장 최소 거리를 가지는 정점을 반환합니다.
def get_small_index():
  _min = INF
  index = 0
  for i in range(number):
    if distance[i] < _min and (not visited[i]):
      _min = distance[i]
      index = i
  return index

# 지정한 시작 (start)를 기준으로 경로 갱신
def dijkstra(start):
  # start 정점에서 나머지 정점으로 가는 distance 초기화
  for i in range(number):
    distance[i] = graph[start][i]

  visited[start] = 1 # 시작 지점은 방문한 노드로 설정

  # 시작 지점 제외한 나머지 노드(거리가 짧은 노드부터)를 돈다.
  for _ in range(number-1):
    current = get_small_index()

    visited[current] = 1
    for j in range(number):
      if not visited[j]:
        # 경유해서 가는 경로 < 원래 경로 이면 -> 갱신 !!
        if distance[current] + graph[current][j] < distance[j]:
          distance[j] = distance[current] + graph[current][j]

dijkstra(0)
print(distance) # 0 2 3 1 2 4
'''

'''
# 힙으로 구현한 다익스트라 알고리즘 -> O(N*logN)
'''
# from collections import deque




import heapq
def dijkstra(start):
    distance[start] = 0
    pq = []  # 우선순위 힙 큐
    heapq.heappush(pq, (0, start))

    # 가까운 순서대로 처리하므로 큐를 사용합니다.
    while pq:
        node = heapq.heappop(pq)  # 가장 작은 비용의 노드 빼옴
        dist = node[0]  # 거리
        current = node[1]  # 인덱스

        # 최단 거리가 아닌 경우엔 스킵
        if distance[current] < dist:
            continue

        for i in range(len(graph[current])):
            # 선택된 인접 노드들 !
            _next = graph[current][i][1]

            # 선택된 노드를 거쳐서 인접 노드로 가는 비용
            next_distance = dist + graph[current][i][0]

            # 기존의 최소 비용 보다 더 저렴하다면 갱신 !
            if(next_distance < distance[_next]):
                distance[_next] = next_distance
                heapq.heappush(pq, (next_distance, _next))


# 변수 선언
number = 6
INF = 1000000000

graph = [[] for _ in range(number+1)]  # 간선 정보를 인접 리스트로 ! -> 노드 1부터 시작하도록
distance = [0] * (number+1)  # 최소 비용

# 기본적으로 연결되지 않은 노드의 비용은 무한
for i in range(1, number+1):
    distance[i] = INF

# (간선 거리, 노드의 index)
graph[1].append([2, 2])
graph[1].append([5, 3])
graph[1].append([1, 4])

graph[2].append([2, 1])
graph[2].append([3, 3])
graph[2].append([2, 4])

graph[3].append([5, 1])
graph[3].append([3, 2])
graph[3].append([3, 4])
graph[3].append([1, 5])
graph[3].append([5, 6])

graph[4].append([1, 1])
graph[4].append([2, 2])
graph[4].append([3, 3])
graph[4].append([1, 5])

graph[5].append([1, 3])
graph[5].append([1, 4])
graph[5].append([2, 6])

graph[6].append([5, 3])
graph[6].append([2, 5])

# 다익스트라 실행
dijkstra(1)
for i in range(1, number+1):
    print(distance[i], end=' ')  # 0 2 3 1 2 4
print()
