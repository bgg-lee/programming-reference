'''
'크루스칼(Kruskal) 알고리즘' 은 가장 적은 비용으로 모든 노드를 연결하기 위해 사용하는 알고리즘
최소 비용 신장 트리(Minimum Spanning Tree)를 만들기 위한 대표적인 알고리즘이라고 할 수 있습니다.

흔히, 여러 개의 도시가 있을 때 각 도시를 도로를 이용해 최소 비용으로 연결하고자 할 때 실제로 적용되는 알고리즘입니다.

# 그래프의 간단한 용어 정리
노드 = 정점 = 도시 : 그래프에서 동그라미에 해당하는 부분입니다.
간선 = 거리 = 비용 : 그래프에서 선으로 표현되는 부분입니다.

최소 비용 신장 트리에서 '간선 숫자 = 노드의 개수 - 1'이다.

그렇다면 '크루스칼 알고리즘'의 구현은 어떻게 진행 될까?
일단 모든 노드를 최대한 적은 비용으로 '연결만' 시키면 되기 때문에 모든 간선 정보를 '오름차순'으로 정렬한 뒤
비용이 적은 간선부터 차근차근 그래프에 포함시키면 된다 !
단, 중요한 사항 하나는 사이클이 형성되지 않도록 주의해야한다 !!
'''

# Union-Find의 코드를 그대로 사용한다 ! -> 사이클이 발생하는지 여부를 확인하기 위해서!
# 부모 노드를 찾는 함수


def getParent(parent, x):
    # 그래프가 자기 자신 하나인 경우 !
    if parent[x] == x:
        return x
    parent[x] = getParent(parent, parent[x])
    return parent[x]

# 두 부모 노드를 합치는 함수


def unionParent(parent, a, b):
    # 부모를 찾은 후
    a = getParent(parent, a)
    b = getParent(parent, b)

    # 더 작은 값을 부모로 지정한다
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

# 같은 부모를 가지는지 확인


def findParent(parent, a, b):
    a = getParent(parent, a)
    b = getParent(parent, b)

    if a == b:
        return True
    else:
        return False

# 간선 클래스 생성


class Edge:
    # 클래스 변수 = 공유됨
    # distance = 0

    # 생성자
    # 내부는 인스턴스 변수들
    def __init__(self, start, end, distance):
        self.start = start
        self.end = end
        self.distance = distance

    # __str__ 은 비공식적인(informal) 문자열을 출력할 때 사용
    # __repr__ 은 공식적인 문자열을 출력할 때 사용
    def __repr__(self):
        return repr([self.start, self.end, self.distance])


n = 7  # 노드의 개수
m = 11  # 간선의 개수
v = []  # Edge를 담을 리스트

# 각 간선를 생성 (출발점, 도착점, 비용까지 포함된)
v.append(Edge(1, 7, 12))
v.append(Edge(1, 4, 28))
v.append(Edge(1, 2, 67))
v.append(Edge(1, 5, 17))
v.append(Edge(2, 4, 24))
v.append(Edge(2, 5, 62))
v.append(Edge(3, 5, 20))
v.append(Edge(3, 6, 37))
v.append(Edge(4, 7, 13))
v.append(Edge(5, 6, 45))
v.append(Edge(5, 7, 73))

# 간선의 비용을 기준으로 오름차순 정렬
v = sorted(v, key=lambda x: x.distance)
print(v)

# 각 정점이 포함된 그래프가 어디인지 저장
# = 사이클 테이블 저장
parent = [0] * n
for i in range(n):
    parent[i] = i

_sum = 0
for i in range(m):
    # 사이클이 발생하지 않는 경우 같은 그래프에 포함시켜준다.
    if(not findParent(parent, v[i].start - 1, v[i].end - 1)):
        _sum += v[i].distance
        unionParent(parent, v[i].start - 1, v[i].end - 1)

# 최소 비용 출력
print(_sum)
