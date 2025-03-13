from collections import deque

# 이진 트리 노드 정의
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def preorder(root):
    if not root : return
    print(root.val,end=" ")
    preorder(root.left)
    preorder(root.right)


def inorder(root):
    if not root : return
    inorder(root.left)
    print(root.val,end=" ")
    inorder(root.right)

def postorder(root):
    if not root : return
    postorder(root.left)
    postorder(root.right)
    print(root.val,end=" ")

# main 함수에서 테스트
def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.left.right = TreeNode(8)
    root.left.left.right.left = TreeNode(9)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)

    print("\nPreorder Traversal:")
    preorder(root)

    print("\nInorder Traversal:")
    inorder(root)

    print("\nPostorder Traversal:")
    postorder(root)

if __name__ == "__main__":
    main()

# BFS - QUEUE / DFS - STACK 구현

"""
from collections import deque

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def bfs(root):
    if not root:
        return
    
    queue = deque([root])
    
    while queue:
        node = queue.popleft()
        print(node.value, end=" ")  # 방문
        
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)

# 예제 실행
root = Node(5)
root.left = Node(3)
root.right = Node(8)
root.left.left = Node(2)
root.left.right = Node(4)
root.right.right = Node(9)

bfs(root)  # ✅ 출력: 5 3 8 2 4 9

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def preorder_dft(root):
    if not root:
        return
    
    stack = [root]  # 루트를 먼저 스택에 삽입
    while stack:
        node = stack.pop()  # 스택에서 꺼내 방문
        print(node.value, end=" ")
        
        # 스택은 FILO이므로, 오른쪽을 먼저 삽입하여 왼쪽이 먼저 방문되도록 함
        if node.right:
            stack.append(node.right)
        if node.left:
            stack.append(node.left)

# 예제 트리 생성
root = Node(5)
root.left = Node(3)
root.right = Node(8)
root.left.left = Node(2)
root.left.right = Node(4)
root.right.right = Node(9)

preorder_dft(root)  # ✅ 출력: 5 3 2 4 8 9

def inorder_dft(root):
    stack = []
    current = root

    while stack or current:
        # 왼쪽 끝까지 탐색
        while current:
            stack.append(current)
            current = current.left
        
        # 스택에서 꺼내 방문
        current = stack.pop()
        print(current.value, end=" ")
        
        # 오른쪽 자식 처리
        current = current.right

inorder_dft(root)  # ✅ 출력: 2 3 4 5 8 9

# Stack 2개 사용용
def postorder_dft(root):
    if not root:
        return

    stack1 = [root]
    stack2 = []  # 출력 순서를 조정하기 위한 스택

    while stack1:
        node = stack1.pop()
        stack2.append(node)  # 스택2에 삽입 (출력 순서 조정)
        
        # 왼쪽을 먼저 push해야 오른쪽이 먼저 pop됨
        if node.left:
            stack1.append(node.left)
        if node.right:
            stack1.append(node.right)

    # 스택2에서 pop하면 후위 순회가 됨
    while stack2:
        print(stack2.pop().value, end=" ")

postorder_dft(root)  # ✅ 출력: 2 4 3 9 8 5



"""