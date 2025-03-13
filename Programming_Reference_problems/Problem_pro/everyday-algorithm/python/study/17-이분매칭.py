'''
이분 매칭(Bipartite Matching) 알고리즘은 A집단이 B집단을 선택하는 방법에 대한 알고리즘입니다.

'사람'이라는 집단과 '노트북'이라는 집단 두 개의 집단이 있다고 가정하면
1번 사람은 'A, B, C 노트북 다 괜찮아'
2번 사람은 'A 노트북 괜찮아'
3번 사람은 'B 노트북 괜찮아'

라는 문제가 주어졌을 때 효과적으로 매칭을 이루어 주는 알고리즘입니다.
효과적으로 매칭시켜준다는 말은 '최대 매칭(Max Matching)' 을 의미하는 것입니다.

모든 사람 각각이 노트북을 선택하여 가장 많이 연결되는 경우를 찾는 문제라고 볼 수 있습니다.

시간 복잡도 - O(V * E)
'''

MAX = 101
graph = [[] for _ in range(MAX)]

entry = [0] * MAX  # 특정 노드를 점유하고 있는 노드의 정보

# 매칭에 성공한 경우 True, 실패한 경우 False


def dfs(x):
    # 연결된 모든 노드에 대해서 들어갈 수 있는지 시도
    for i in range(len(graph[x])):
        t = graph[x][i]
        # 이미 처리한 노드는 더 이상 볼 필요가 없음
        if check[t]:
            continue
        check[t] = True

        # 비어 있거나 점유 노드에 더 들어갈 공간이 있을 경우
        if entry[t] == 0 or dfs(entry[t]):
            entry[t] = x  # 들어갈 수 있는 경우엔 매칭 시켜준다.
            return True
    return False


graph[1].append(1)
graph[1].append(2)
graph[1].append(3)

graph[2].append(1)

graph[3].append(2)

count = 0
n = 3
for i in range(1, n+1):
    # 매번 매칭을 할 때마다 처리가 안된 상태로 초기화 !
    check = [False] * MAX  # 특정 노드를 처리했는지 여부를 알려주는 리스트
    if dfs(i):
        count += 1

print(f'{count}개의 매칭이 이루어졌습니다.')

for i in range(1, MAX):
    if entry[i] != 0:
        print(f'{entry[i]} -> {i}')
