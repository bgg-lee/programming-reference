'''
지난 시간에는 다익스트라 알고리즘에 대해 알아 보았습니다.
다익스트라 알고리즘은 하나의 정점에서 다른 모든 정점으로의 최단 경로를 구하는 알고리즘입니다.

하지만 만약에 '모든 정점'에서 '모든 정점'으로의 최단 거리를 구하고 싶다면?
-> 플로이드 와샬 알고리즘을 사용해야합니다.

또한, 두 가지 알고리즘의 차이점은 '다익스트라 알고리즘'은 가장 적은 비용을 하나씩 선택했다면 
'플로이드 와샬 알고리즘'은 기본적으로 '거쳐가는 정점'을 기준으로 알고리즘을 수행한다는 점에서 그 특징이 있습니다.

1번 정점 부터 ~ n번 정점을 거쳐가는 경우를 갱신해주면 됩니다.
'''

number = 4
INF = 1000000000

# 자료 배열을 초기화합니다.
graph = [
    [0, 5, INF, 8],
    [7, 0, 9, INF],
    [2, INF, 0, 4],
    [INF, INF, 3, 0]
]


def floyd_warshall():
    # 결과 그래프를 초기화합니다.
    distance = [([0]*number) for _ in range(number)]

    for i in range(number):
        for j in range(number):
            distance[i][j] = graph[i][j]

    # k = 거쳐가는 노드
    for k in range(number):
        # i = 출발 노드
        for i in range(number):
            # j = 도착 노드
            for j in range(number):
                if distance[i][k] + distance[k][j] < distance[i][j]:
                    distance[i][j] = distance[i][k] + distance[k][j]

    # 결과를 출력합니다.
    print(distance)


floyd_warshall()
