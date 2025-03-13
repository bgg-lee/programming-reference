# https://www.acmicpc.net/problem/1068

import sys

input_s = lambda: sys.stdin.readline()

# DFS 탐색
def find(x):
    global count
    if len(tree[x]) == 0:
        count += 1
    else:
        for i in tree[x]:
            find(i)


N = int(input_s())
node = list(map(int, input_s().split()))

tree = [[] for i in range(N)]
for i in range(N):
    if node[i] == -1:
        start = i
    else:
        tree[node[i]].append(i)

delete = int(input_s())
count = 0

# 삭제 작업 -> 2번 노드 지운다 하면 2번 포함된 애들만 지움 -> 그 밑에 노드들 안건들여도 -> find함수 사용시 삭제된 애 제외하고 돔
# 즉 삭제될 노드에 해당되는 애만 지우면 된다
for i in range(N):
    if delete in tree[i]:
        tree[i].remove(delete)

if delete != start:
    find(start)
print(count)