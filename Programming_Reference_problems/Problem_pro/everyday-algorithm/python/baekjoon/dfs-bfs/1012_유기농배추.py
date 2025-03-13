# https://www.acmicpc.net/problem/1012
# 2667 문제보다 더 간결하게 구현함
import sys
sys.setrecursionlimit(10**5)
input_s = lambda : sys.stdin.readline().strip()

T = int(input_s())


# 상, 하 , 좌, 우 검사
def check(x, y):

    # 아래 검사
    if x != M-1 and map_info[x+1][y] == 1 and visited[x+1][y] == 0:
        down = (x+1, y)
    else: down = False

    # 위 검사
    if x != 0 and map_info[x-1][y] == 1 and visited[x-1][y] == 0:
        up = (x-1, y)
    else: up = False

    # 왼쪽 검사
    if y != 0 and map_info[x][y-1] == 1 and visited[x][y-1] == 0:
        left = (x, y-1)
    else: left = False

    # 오른쪽 검사
    if y != N - 1 and map_info[x][y+1] == 1 and visited[x][y+1] == 0:
        right = (x, y+1)
    else: right = False

    return up,down,left,right


def search_dfs(x, y):

    visited[x][y] = 1
    direction = check(x, y)
    for case in direction:
        if case:
            next_x, next_y = case
            search_dfs(next_x, next_y)

list_count = []
# 테스트 케이스 T번 반복
# 언더스코어 _ 은 값을 무시하겠다 -> 사용하지 않는 변수다
for _ in range(T):
    M, N, K = map(int, input_s().split())
    map_info = [[0 for _ in range(N)] for _ in range(M)]
    visited = [[0 for _ in range(N)] for _ in range(M)]
    for _ in range(K):
        x, y = map(int, input_s().split())
        map_info[x][y] = 1

    total_count = 0
    for i in range(M):
        for j in range(N):
            if map_info[i][j] == 1 and visited[i][j] == 0:
                search_dfs(i, j)
                total_count += 1

    list_count.append(total_count)

for count in list_count:
    print(count)

