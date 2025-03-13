# https://www.acmicpc.net/problem/11403

import sys
import copy

input_s = lambda: sys.stdin.readline().strip()

N = int(input_s())
graph = [list(map(int, input_s().split())) for i in range(N)]
# result = [[0]*3]*3 # 얘 쓰면 이상.. [0][1] = 1로 바꾸면 [1][1] [2][1]도 1로 바뀜

# 깊은 복사
result = copy.deepcopy(graph)


def find_path(start):
    global first_node

    if first_node != start:
        path.append(start)

    # 이거 이상한 종료조건 얘 때문에 틀림
    # if len(path) >= N:
    #     return 0

    for i in range(N):

        if graph[start][i] == 1 and i not in path:
            find_path(i)

        # 도착지점(i) 가 첫번째 노드일때 -> 순환될때
        if graph[start][i] == 1 and first_node == i:
            path.append(first_node)


def show():
    for i in range(N):
        for j in range(N):
            print(result[i][j], end=" ")
        print()


# main
for i in range(N):
    path = []
    first_node = i
    find_path(i)
    #print(path)
    for k in path:
        result[i][k] = 1

show()
