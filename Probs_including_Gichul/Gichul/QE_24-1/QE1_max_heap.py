# 대충 보니까, 주어진 head에 대해서 max_heap이 맞는지 체크 하는게 1번
# -> parent가 left,right보다 크거나 같으면 되는듯
# 2번 -> 주어진 head에 대해서 list[node] 형태로 죽 반환하기
# 아, 2번은 주어진 head가 heap이 아니면 heap으로 만들고 array 반환.. 아닌가 뭐지
# 2번이 max heap 이 아닌경우, in-place로 max heap 만들고 array 반환이라고 가정;;
# 맞는지 모르겄다~

class TNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

from collections import deque

def is_max_heap(head : TNode) -> bool:
    q = deque([head])
    while q:
        curr = q.popleft()
        if curr.left:
            if curr.val < curr.left.val : return False
            else : q.append(curr.left)
        if curr.right :
            if curr.val < curr.right.val : return False
            else : q.append(curr.right)
    return True            

def heapify(node: TNode) -> None :
    if (not node.left) and (not node.right) : return
    
    largest = node
    if node.left and node.left.val > largest.val :
        largest = node.left
    if node.right and node.right.val > largest.val :
        largest = node.right
    # 순위 변동 발생
    if largest != node:
        largest.val, node.val = node.val, largest.val

def binary_tree_to_heap_array(head : TNode) -> list[int]:
    if not head : return []
    ans = []

    q = deque([head])
    while q:
        curr = q.popleft()
        heapify(curr)
        ans.append(curr.val)
        if curr.left:
            q.append(curr.left)
        if curr.right:
            q.append(curr.right)
    return ans

if __name__ == "__main__":
    T7, T8, T9, T10 = TNode(4), TNode(6), TNode(5), TNode(5)
    T3, T4 = TNode(3), TNode(6, T7, T8)
    T5, T6 = TNode(1, None, T9), TNode(4, T10, None)
    T1, T2 = TNode(5, T3, T4), TNode(7, T5, T6)
    T0= TNode(8, T1, T2)
    print(is_max_heap(T0))
    print(binary_tree_to_heap_array(T0))
    
    T7, T8, T9, T10 = TNode(4), TNode(5), TNode(1), TNode(4)
    T3, T4 = TNode(3), TNode(6, T7, T8)
    T5, T6 = TNode(5, None, T9), TNode(5, T10, None)
    T1, T2 = TNode(6, T3, T4), TNode(7, T5, T6)
    T0= TNode(8, T1, T2)
    print(is_max_heap(T0))
    print(binary_tree_to_heap_array(T0))
