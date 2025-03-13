# https://www.acmicpc.net/problem/1260

import sys

input_s = lambda: sys.stdin.readline()

N, M, start = map(int,input_s().split())
abj = [list(map(int,input_s().split())) for i in range(M)]
# 이대로 정렬 먼저하면 -> 1 6 5 1 이럴때 문제됨 1:[6,5]로 들어감
# abj.sort(key=lambda x: x[1])
# abj.sort(key=lambda x: x[0])

tree = {}
visit_dfs = []

visit_bfs = []
queue_bfs = []


def init():
    for i in range(1,N+1):
        tree[i] = []
    for i in range(M):
        # if abj[i][1] not in tree[abj[i][0]]:
        tree[abj[i][0]].append(abj[i][1])
        # if abj[i][0] not in tree[abj[i][1]]:
        tree[abj[i][1]].append(abj[i][0])
    # 오름차순 정렬
    for i in range(1, N+1):
        tree[i].sort()


# 재귀 형식으로 visit_dfs에 방문한 노드 stack을 사용하여 출력
def search_dfs(tree,start):

    visit_dfs.append(start)

    for i in tree[start]:
        if i not in visit_dfs:
            search_dfs(tree,i)


# node의 개수 만큼 queue를 사용
def search_bfs(tree,start):

    queue_bfs.append(start)

    while queue_bfs:
        # 시작위치 변경 후 제거
        start = queue_bfs.pop(0)
        # 추가
        visit_bfs.append(start)
        for j in tree[start]:
            if j not in visit_bfs and j not in queue_bfs:
                queue_bfs.append(j)


def show(list):
    for i, v in enumerate(list):
        print(v,end=" ")


init()
search_dfs(tree, start)
search_bfs(tree, start)
show(visit_dfs)
print()
show(visit_bfs)

#반례
# 6 8 1
# 1 6
# 6 2
# 2 4
# 4 3
# 3 5
# 5 1
# 5 6
# 2 3
