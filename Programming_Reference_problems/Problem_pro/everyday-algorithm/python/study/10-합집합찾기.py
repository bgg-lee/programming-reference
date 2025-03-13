'''
'Union-Find' 는 대표적인 그래프 알고리즘입니다.
'합집합 찾기' 라는 의미를 가진 알고리즘으로 '서로소(Disjoint-Set) 알고리즘'이라고도 부릅니다.
구체적으로 여러 개의 노드가 존재할 때 두 개의 노드를 선택해서, 현재 이 두 노드가 서로 같은 그래프에 속하는지 판별하는 알고리즘입니다.

이러한 'Union-Find' 알고리즘은 다른 고급 그래프 알고리즘의 베이스가 되는 점에서 필수 알고리즘입니다.
(크루스칼 알고리즘 등등)
'''

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


parent = []
for x in range(11):
    parent.append(x)

print(parent)

# 1 - 2 - 3 - 4 노드를 연결해서 그래프로 만듬
unionParent(parent, 1, 2)
unionParent(parent, 2, 3)
unionParent(parent, 3, 4)

# 5 - 6 - 7 - 8 노드를 연결해서 그래프로 만듬
unionParent(parent, 5, 6)
unionParent(parent, 6, 7)
unionParent(parent, 7, 8)

print(f'1과 5는 연결되어 있나요? {findParent(parent, 1, 5)}')

# unionParent(parent, 1, 5)
# 흥미로운 점은 2, 6 / 2, 8 등을 연결해도 아래의 값은 True로 나온다.
# 그래프가 결국에는 연결되있으니
unionParent(parent, 2, 8)

print(f'1과 5는 연결되어 있나요? {findParent(parent, 1, 5)}')
