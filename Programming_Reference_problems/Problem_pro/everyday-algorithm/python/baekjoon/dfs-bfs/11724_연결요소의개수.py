# https://www.acmicpc.net/problem/11724

# 재귀 깊이 조절
# sys.setrecursionlimit(10**6)
import sys

input_s = lambda: sys.stdin.readline().strip()

N, M = map(int, input_s().split())

temp = []
for i in range(M):
    temp.append(list(map(int, input_s().split())))

tree = {}
visit = {i:False for i in range(1,N+1)}


def init():
    for i in range(1, N + 1):
        tree[i] = []
    for i in range(M):
        tree[temp[i][0]].append(temp[i][1])
        tree[temp[i][1]].append(temp[i][0])


def dfs(start):

    visit[start] = True

    for i in tree[start]:
        if visit[i] is False:
            dfs(i)


init()
count = 0
for i in range(1,N + 1):
    if visit[i] is False:
        dfs(i)
        count += 1
print(count)
