from collections import deque

class TNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_max_heap(T):
    deq = deque()
    
    node = T
    if node:
        if node.left and (node.left.val > node.val):
            return False
        if node.right and (node.right.val > node.val):
            return False
    deq.append(T)
    
    while deq:
        node = deq.popleft()
        
        L = node.left
        if L:
            if L.left and (L.left.val > L.val):
                return False
            elif L.right and (L.right.val > L.val):
                return False
            else:
                deq.append(L)
            
        R = node.right
        if R:
            if R.left and (R.left.val > R.val):
                return False
            elif R.right and (R.right.val > R.val):
                return False
            else:
                deq.append(R)
    return True

def max_heapify(node):
    L = node.left
    R = node.right
    if L and (L.val > node.val):
        largest = L
    else:
        largest = node
        
    if R and (R.val > largest.val):
        largest = R
    
    if largest is not node:
        node.val, largest.val = largest.val, node.val
        max_heapify(largest)
        
def _binary_tree_to_heap(head):
    heap = list()
    deq = deque()
    
    node = head
    if node:
        deq.append(node)
    while deq:
        node = deq.popleft()
        heap.append(node)
        
        if node.left:
            deq.append(node.left)
        if node.right:
            deq.append(node.right)
    return heap
    
def build_max_heap(head):
    heap = _binary_tree_to_heap(head)
    for i in range(int(len(heap)/2),-1,-1):
        max_heapify(heap[i])

def binary_tree_to_heap_array(head):
    build_max_heap(head)
    max_heap = list()
    deq = deque()
    
    node = head
    if node:
        deq.append(node)
    while deq:
        node = deq.popleft()
        max_heap.append(node.val)
        
        if node.left:
            deq.append(node.left)
        if node.right:
            deq.append(node.right)
    return max_heap

# if __name__ == "__main__":
#     T7, T8, T9, T10 = TNode(4), TNode(6), TNode(5), TNode(5)
#     T3, T4 = TNode(3), TNode(6, T7, T8)
#     T5, T6 = TNode(1, None, T9), TNode(4, T10, None)
#     T1, T2 = TNode(5, T3, T4), TNode(7, T5, T6)
#     T0= TNode(8, T1, T2)
#     print(is_max_heap(T0))
#     print(binary_tree_to_heap_array(T0))
    
#     T7, T8, T9, T10 = TNode(4), TNode(5), TNode(1), TNode(4)
#     T3, T4 = TNode(3), TNode(6, T7, T8)
#     T5, T6 = TNode(5, None, T9), TNode(5, T10, None)
#     T1, T2 = TNode(6, T3, T4), TNode(7, T5, T6)
#     T0= TNode(8, T1, T2)
#     print(is_max_heap(T0))
#     print(binary_tree_to_heap_array(T0))
