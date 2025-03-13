'''
 깊이 우선 탐색(Depth First Search - DFS)는 탐색을 함에 있어서 보다 깊은 것을 우선으로 탐색하는 알고리즘입니다.
 이러한 깊이 우선 탐색은 맹목적으로 각 노드를 탐색할 때 주로 사용됩니다.
 너비 우선 탐색에서는 큐(Queue)가 사용되었다면 깊이 우선 탐색은 스택(Stack)을 사용합니다.
 
 - 알고리즘 동작 방식 -

 1. 스택의 최상단 노드를 확인
 2. 최상단 노드에서 방문하지 않은 노드가 있다면 그 노드를 스택에 넣고 방문처리합니다.
    방문하지 않은 인접 노드가 없으면 스택에서 최상단 노드를 뺍니다.

 보통은 위와 같이 스택을 사용하여 동작하지만 컴퓨터 함수 자체가 스택에 쌓여 동작하기 때문에 재귀함수를 이용하면 보다 간편합니다.
'''

size = 7

data = [[] for _ in range(size+1)]  # 노드
visited = [0] * (size+1)  # 방문한 노드를 표시할 변수

answer = []  # DFS 방문 경로


def dfs(start):
    if(visited[start]):
        return

    # 방문 처리
    visited[start] = 1
    answer.append(start)

    # 해당 start 값과 일치하는 노드의 인접 노드를 dfs로 탐색
    for i in range(len(data[start])):
        y = data[start][i]
        dfs(y)


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
dfs(1)

# 방문 경로
print(f'정답 : {answer}')
