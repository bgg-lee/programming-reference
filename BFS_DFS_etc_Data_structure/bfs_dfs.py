from collections import deque

# 이진 트리 노드 정의
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
# BFS (Level Order Traversal)
def bfs(root:TreeNode)->None : # BFS는 QUEUE
    q = deque([root])
    while q:
        temp = q.popleft()
        print(temp.val,end=" ")
        if temp.left : q.append(temp.left)
        if temp.right : q.append(temp.right)

# DFS (Preorder Traversal)
def dfs(root:TreeNode) -> None:
    s = deque([root])
    while s:
        temp = s.pop()
        print(temp.val,end=" ")
        if temp.right : s.append(temp.right)
        if temp.left : s.append(temp.left)

# Python 실행파일
if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)

    print("BFS (Level Order Traversal):")
    bfs(root)
    print("\nDFS (Preorder Traversal):")
    dfs(root)