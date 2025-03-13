'''
기본적으로 가장 많이 사용되는 비선형 자료구조는 '이진 트리(Binary Tree)' 입니다.
이진 트리는 데이터의 탐색 속도 증진을 위해 사용되는 구조입니다.

이전에 '힙 정렬'에 대해서 다룰 때 간단히 이진 트리에 대해 알아보았습니다.
대신, 힙 정렬에 대해 공부할 때는 완전 이진 트리였기 때문에 class와 pointer를 사용할 필요없이 
배열을 사용하여 데이터를 조작했다면 완전 이진 트리가 아닌 이진 트리를 구현하기 위해서 class와 pointer를 사용해 구현합니다.
(구현이 불가능한 것은 아니나 그래야 비 효율적이다.
class와 pointer를 사용해야 특정한 노드에서 자식 노드, 부모 노드로 접근하기 편리하며 안정적이다. !)

이진 트리에서 데이터를 탐색하는 방법은 크게 세 가지 방법이 있습니다.

1. 전위 순회(Preorder Traversal)
  1. * 먼저 자기 자신을 처리 *
  2. 왼쪽 자식을 처리
  3. 오른쪽 자식을 처리

2. 중위 순회(Inorder Traversal)
  1. 왼쪽 자식을 처리
  2. * 먼저 자기 자신을 처리 *
  3. 오른쪽 자식을 처리

3. 후위 순회(Postorder Traversal)
  1. 왼쪽 자식을 처리
  2. 오른쪽 자식을 처리
  3. * 먼저 자기 자신을 처리 *
'''

# 하나의 노드 정보를 선언합니다.


class Node:
    def __init__(self, data):
        self.data = data
        self.left_child = None
        self.right_child = None

    def __repr__(self):
        return repr([self.data, self.left_child, self.right_child])

# 전위 순회를 구현합니다.


def pre_order(node: Node):
    # 데이터를 가지고 있는 경우
    if node:
        print(f'{node.data}', end=' ')
        pre_order(node.left_child)
        pre_order(node.right_child)

# 중위 순회를 구현합니다.


def in_order(node: Node):
    # 데이터를 가지고 있는 경우
    if node:
        in_order(node.left_child)
        print(f'{node.data}', end=' ')
        in_order(node.right_child)

# 후위 순회를 구현합니다.


def post_order(node: Node):
    # 데이터를 가지고 있는 경우
    if node:
        post_order(node.left_child)
        post_order(node.right_child)
        print(f'{node.data}', end=' ')


n = 15  # 노드의 개수
nodes = []  # 노드가 담길 리스트

# 데이터 삽입
# 인덱스를 1부터 접근하기 위해서 0부터 n+1까지 넣음 -> 0인덱스는 사용 안함
for i in range(0, n+1):
    node = Node(i)
    nodes.append(node)

# 각 노드 연결하기
for i in range(1, n+1):
    # 노드의 인덱스가 짝수는 왼쪽으로, 홀수는 오른쪽으로 연결
    if i % 2 == 0:
        nodes[i//2].left_child = nodes[i]
    else:
        nodes[i//2].right_child = nodes[i]

# 1번 노드부터 전위 순회
pre_order(nodes[1])
print()

# 중위 순회
in_order(nodes[1])
print()

# 후위 순회
post_order(nodes[1])
print()
