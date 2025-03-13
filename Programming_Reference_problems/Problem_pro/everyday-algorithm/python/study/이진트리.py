'''
이진 트리(Binary Tree)는 최대 두 개의 자식 노드를 가진느 트리 형태의 자료구조로, 단순히 값을 저장하는 용도보다는 효율적인 탐색 혹은 정렬을 위하여 사용됨.
이진 탐색 트리(Binary Search Tree)를 사용하여 주어진 값 혹은 이보다 작거나 큰 값들을 평균 O(logn)의 시간 복잡도로 찾을 수 있음.
이진 트리의 한 종류인 힙(heap)을 사용한 힙 정렬(heap)은 O(nlogn)의 시간 복잡도를 가짐.

- Insert, Find 메소드 - 
재귀를 아용해서 구현하면 간단 !
새로 추가, 찾을 원소의 값을 현재 노드의 값과 비교하여 왼쪽/오른쪽 중 알맞은 위치로 노드를 옮겨가면서 삽입 위치나 찾을 데이터를 확인하면 끝 !

- Delete 메소드 -
삭제할 Node의 자식이 없으면 문제가 없지만, 자식이 하나인 경우엔 자식 노드를 삭제한 노드 위치로 가져오면 됨
왼쪽 서브 트리와 오른쪽 서브 트리를 각각 A, B라고 했을 때, B에서 가장 왼쪽 아래에 위치한 자손을 가져온 옴
이 원소는 A의 모든 원소들보다는 크면서, B의 나머지 원소보다 작기 때문에 해당 노드를 가져오면 됨
'''


class Node(object):
    def __init__(self, data):  # 초기화
        self.data = data
        self.left = self.right = None


class BinarySearchTree(object):
    def __init__(self):  # 초기화
        self.root = None

    def insert(self, data):
        self.root = self._insert_value(self.root, data)
        return self.root is not None

    def _insert_value(self, node, data):
        # 없으면 Node 생성
        if node is None:
            node = Node(data)
        else:
            # 현재 노드 보다 작은 값이면 현재 노드 왼쪽 링크에 붙임
            if data <= node.data:
                node.left = self._insert_value(node.left, data)
            else:
                node.right = self._insert_value(node.right, data)
        return node

    def find(self, key):
        return self._find_value(self.root, key)

    def _find_value(self, node, key):
        if node is None or node.data == key:
            return node is not None
        else:
            if key <= node.data:
                return self._find_value(node.left, key)
            else:
                return self._find_value(node.right, key)

    def delete(self, key):
        self.root, deleted = self._delete_value(self.root, key)
        return deleted

    def _delete_value(self, node, key):
        if node is None:
            return node, False

        deleted = False
        if key == node.data:
            deleted = True
            if node.left and node.right:
                parent, child = node, node.right
                while child.left is not None:
                    parent, child = child, child.left
                child.left = node.left  # node.left의 서브트리를 child.left에 붙임
                if parent != node:  # 삭제하려는 노드의 왼쪽, 오른쪽이 여러개 서브 트리일 때
                    parent.left = child.right  # parent.left에는 child가 있었지만 child.right만 남김
                    # child.right는 parent.left에 붙였으니 떼어진 상태 -> node.right(parent)를 child.right에 붙임
                    child.right = node.right
                node = child  # node(다 떼어서 left, right도 없는 노드)를 위의 child로 대체
            elif node.left or node.right:
                node = node.left or node.right
            else:
                node = None
        elif key < node.data:
            node.left, deleted = self._delete_value(node.left, key)
        else:
            node.right, deleted = self._delete_value(node.right, key)
        return node, deleted

    # 이진트리 출력
    def _print(self):
        self.search_dfs(self.root)
        print()  # 줄바꿈

    # 전위 순회
    def search_dfs(self, node):
        if node is None:
            print('값이 없습니다.')
            pass  # pass: 단순히 실행할 코드가 없다는 의미
        else:
            print(node.data, end=' ')
            if node.left is not None:
                self.search_dfs(node.left)
            if node.right is not None:
                self.search_dfs(node.right)


# 사용 예제
array = [40, 4, 34, 45, 14, 55, 48, 13, 15, 49, 47]
bst = BinarySearchTree()
for i in array:
    bst.insert(i)

bst._print()  # 전위 순회

print(bst.find(15))  # True
print(bst.find(100))  # False

bst.delete(55)  # True
bst._print()  # 40 4 34 14 13 15 45 48 47 49

bst.delete(14)  # True
bst._print()  # 40 4 34 15 13 45 48 47 49

bst.delete(100)  # False
bst._print()  # 40 4 34 15 13 45 48 47 49
