# https://www.acmicpc.net/problem/1987

import sys
sys.setrecursionlimit(10000000)
from collections import deque
input_s = lambda : sys.stdin.readline().strip()

R, C = map(int, input_s().split())
board_str = [input_s() for _ in range(R)]
board = []
visited = [[0 for _ in range(C)] for _ in range(R)]
alpha_visited = [0 for _ in range(26)]


def init():
    for i in range(R):
        temp = []
        for j in range(C):
            temp.append(board_str[i][j])
        board.append(temp)


# 상, 하 , 좌, 우 검사
def check(x, y):
    # 아래 검사
    if x != R - 1 and visited[x + 1][y] == 0 and alpha_visited[ord(board[x+1][y])-65] == 0:
        down = (x + 1, y)
    else:
        down = False
    # 위 검사
    if x != 0 and visited[x - 1][y] == 0 and alpha_visited[ord(board[x-1][y])-65] == 0:
        up = (x - 1, y)
    else:
        up = False
    # 왼쪽 검사
    if y != 0 and visited[x][y - 1] == 0 and alpha_visited[ord(board[x][y-1])-65] == 0:
        left = (x, y - 1)
    else:
        left = False
    # 오른쪽 검사
    if y != C - 1 and visited[x][y + 1] == 0 and alpha_visited[ord(board[x][y+1])-65] == 0:
        right = (x, y + 1)
    else:
        right = False

    return up, down, left, right


max_distance = -9999
distance = 0
def search_dfs(x, y):

    global max_distance
    global distance
    visited[x][y] = 1
    alpha_visited[ord(board[x][y])-65] = 1
    distance += 1

    result = check(x, y)
    state = True
    for case in result:
        if case:
            state = False
            next_x, next_y = case
            search_dfs(next_x, next_y)

    if state == True:
        if max_distance < distance:
            max_distance = distance

    # 백 트래킹!! -> 이전 상태로 돌아가는것 (재귀 사용해서?)
    distance -= 1
    visited[x][y] = 0
    alpha_visited[ord(board[x][y]) - 65] = 0

init()
search_dfs(0, 0)
print(max_distance)
