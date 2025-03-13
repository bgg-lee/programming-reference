'''
너비 우선 탐색(Breadth First Search - BFS)는 탐색을 할 때 너비를 우선으로 하여 탐색을 수행하는 탐색 알고리즘입니다.
너비 우선 탐색은 '최단 경로'를 찾아준다는 점에서 최단 길이를 보장해야할 때 많이 사용합니다.
구현은 큐(Queue)를 사용하여 구현합니다.

검색하고자 하는 노드를 큐에 추가함과 동시에 list 변수를 만들어 해당 노드를 방문했다는 표시를 해주어야 합니다 !
탐색할 수 있는 모든 노드를 탐색한 이후에 종료하면 됩니다.
'''

size = 7

# bfs 1부터 돌아서 size + 1 해준것
data = [[] for _ in range(size+1)]  # 노드
visited = [0] * (size+1)  # 방문한 노드를 표시할 변수
queue = []  # 방문할 노드 큐

answer = []  # BFS 방문 경로


def bfs(start):
    queue.append(start)
    visited[start] = 1
    while(queue):
        x = queue.pop(0)
        answer.append(x)

        # 인접한 노드를 방문
        for i in range(len(data[x])):
            y = data[x][i]
            if visited[y] == 0:
                queue.append(y)
                visited[y] = 1


# 그래프 임의로 연결해주기
# 1과 2를 연결합니다.
data[1].append(2)
data[2].append(1)

data[1].append(3)
data[3].append(1)

data[2].append(3)
data[3].append(2)

data[2].append(4)
data[4].append(2)

data[2].append(5)
data[5].append(2)

data[3].append(6)
data[6].append(3)

data[3].append(7)
data[7].append(3)

data[4].append(5)
data[5].append(4)

data[6].append(7)
data[7].append(6)


print(f'노드의 연결 리스트 : {data}')

# 1부터 bfs 탐색
bfs(1)

# 방문 경로
print(f'정답 : {answer}')
