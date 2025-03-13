class TreeNode:
    def __init__(self, value):
        """Initialize a TreeNode."""
        self.value = value
        self.left = None
        self.right = None
        self.parent = None  # Track the parent node for easier operations

class MinHeapTree:
    def __init__(self):
        """Initialize an empty MinHeapTree."""
        self.root = None
        self.size = 0  # Number of nodes in the heap

    def insert(self, value):
        """Insert a value into the Min Heap."""
        new_node = TreeNode(value)
        if not self.root:
            self.root = new_node
        else:
            # Insert 위치 찾기-> 맨 끝에 넣고 Heapify up!
            from collections import deque
            q = deque()
            q.append(self.root)
            while q :
                curr = q.popleft()
                if not curr.left:
                    curr.left = new_node
                    new_node.parent = curr
                    break
                else : q.append(curr.left)

                if not curr.right:
                    curr.right = new_node
                    new_node.parent = curr
                    break
                else : q.append(curr.right)
            self._heapify_up(new_node)

        self.size += 1


    def extract_min(self):
        """Extract and return the minimum value (root) from the heap."""
        # Implementation here
        if self.size == 0 : return -1

        ans = self.root.value
        if self.size == 1 : 
            self.root = None
        else:
            # 꼭다리랑 마지막이랑 Swap 후 마지막을 삭제, 꼭다리를 Heapify down! --> 마지막 Node를 찾자
            from collections import deque
            q = deque()
            q.append(self.root)
            temp = None

            while q :
                temp = q.popleft()
                if temp.left :
                    q.append(temp.left)
                if temp.right:
                    q.append(temp.right)
            
            # temp 가 last node다
            self.root.value = temp.value
            if temp.parent:
                if temp == temp.parent.left:
                    temp.parent.left = None
                else : temp.parent.right = None
            self._heapify_down(self.root)

        self.size -= 1
        return ans

    def peek(self):
        """Return the minimum value (root) without removing it."""
        # Implementation here
        if self.size == 0 : return -1
        else : return self.root.value

    def _heapify_up(self, node):
        """Restore the Min Heap property from a node upwards."""
        # Implementation here
        while node.parent :
            if node.parent.value > node.value :
                # 부모 Node와 내 Node 바꾸는 게 쉽지 않네
                # value만 바꿀까?
                temp = node.value
                node.value = node.parent.value
                node.parent.value = temp
            else : break
            node = node.parent

    def _heapify_down(self, node):
        """Restore the Min Heap property from a node downwards."""
        if not node.left : return
        
        smallest = node

        if node.left and node.left.value < smallest.value:
            smallest = node.left
        if node.right and node.right.value < smallest.value:
            smallest = node.right
        if smallest != node:
            node.value, smallest.value = smallest.value, node.value
            self._heapify_down(smallest)
        else : return
            



# Test cases for MinHeapTree
print("Testing MinHeapTree...\n")
min_heap = MinHeapTree()
# Insertions
print("Inserting 15...")
min_heap.insert(15)
print("Heap root:", min_heap.peek())  # Expected: 15

print("Inserting 10...")
min_heap.insert(10)
print("Heap root:", min_heap.peek())  # Expected: 10

print("Inserting 20...")
min_heap.insert(20)
print("Heap root:", min_heap.peek())  # Expected: 10

print("Inserting 5...")
min_heap.insert(5)
print("Heap root:", min_heap.peek())  # Expected: 5

print("Inserting 25...")
min_heap.insert(25)
print("Heap root:", min_heap.peek())  # Expected: 5

# Extract Min
print("\nExtracting minimum value...")
print("Extracted:", min_heap.extract_min())  # Expected: 5
print("Heap root:", min_heap.peek())  # Expected: 10

print("\nExtracting minimum value...")
print("Extracted:", min_heap.extract_min())  # Expected: 10
print("Heap root:", min_heap.peek())  # Expected: 15

# Clearing the heap
print("\nClearing the heap...")
while min_heap.size > 0:
    print("Extracted:", min_heap.extract_min())
print("Heap is empty.")




# 모범답안
# class TreeNode:
#     def __init__(self, value):
#         self.value = value
#         self.left = None
#         self.right = None
#         self.parent = None


# class MinHeapTree:
#     def __init__(self):
#         self.root = None
#         self.size = 0

#     def insert(self, value):
#         """Insert a value into the Min Heap."""
#         new_node = TreeNode(value)
#         if not self.root:
#             # If the heap is empty, set the root
#             self.root = new_node
#         else:
#             # Perform level-order traversal to find the insertion point
#             queue = [self.root]
#             while queue:
#                 current = queue.pop(0)
#                 if not current.left:
#                     current.left = new_node
#                     new_node.parent = current
#                     break
#                 elif not current.right:
#                     current.right = new_node
#                     new_node.parent = current
#                     break
#                 queue.append(current.left)
#                 queue.append(current.right)

#             # Restore the Min Heap property
#             self._heapify_up(new_node)

#         self.size += 1

#     def extract_min(self):
#         """Extract and return the minimum value (root) from the heap."""
#         if not self.root:
#             raise IndexError("Heap is empty!")

#         min_value = self.root.value

#         if self.size == 1:
#             # If only one element exists, reset the heap
#             self.root = None
#         else:
#             # Perform level-order traversal to find the last node
#             queue = [self.root]
#             last_node = None
#             while queue:
#                 last_node = queue.pop(0)
#                 if last_node.left:
#                     queue.append(last_node.left)
#                 if last_node.right:
#                     queue.append(last_node.right)

#             # Replace the root value with the last node value
#             self.root.value = last_node.value

#             # Remove the last node
#             if last_node.parent:
#                 if last_node.parent.left == last_node:
#                     last_node.parent.left = None
#                 else:
#                     last_node.parent.right = None

#             # Restore the Min Heap property
#             self._heapify_down(self.root)

#         self.size -= 1
#         return min_value

#     def peek(self):
#         """Return the minimum value (root) without removing it."""
#         if not self.root:
#             raise IndexError("Heap is empty!")
#         return self.root.value

#     def _heapify_up(self, node):
#         """Restore the Min Heap property from a node upwards."""
#         while node.parent and node.value < node.parent.value:
#             node.value, node.parent.value = node.parent.value, node.value
#             node = node.parent

#     def _heapify_down(self, node):
#         """Restore the Min Heap property from a node downwards."""
#         while node:
#             smallest = node
#             if node.left and node.left.value < smallest.value:
#                 smallest = node.left
#             if node.right and node.right.value < smallest.value:
#                 smallest = node.right

#             if smallest != node:
#                 node.value, smallest.value = smallest.value, node.value
#                 node = smallest
#             else:
#                 break




"""
아래는 node끼리 swap하는 케이스 value만 바꾸는 것이 아님!
def _swap_nodes(self, node1, node2):
    "Swap two nodes in the binary tree."
    # Swap the parent references
    if node1.parent:
        if node1.parent.left == node1:
            node1.parent.left = node2
        else:
            node1.parent.right = node2
    if node2.parent:
        if node2.parent.left == node2:
            node2.parent.left = node1
        else:
            node2.parent.right = node1

    # Swap the parent pointers
    node1.parent, node2.parent = node2.parent, node1.parent

    # Swap the child references
    node1.left, node2.left = node2.left, node1.left
    if node1.left:
        node1.left.parent = node1
    if node2.left:
        node2.left.parent = node2

    node1.right, node2.right = node2.right, node1.right
    if node1.right:
        node1.right.parent = node1
    if node2.right:
        node2.right.parent = node2

    # Update root if necessary
    if self.root == node1:
        self.root = node2
    elif self.root == node2:
        self.root = node1

def _heapify_down(self, node):
     "Restore the Min Heap property from a node downwards using node swapping."
    if not node.left:
        return  # No children, no need to heapify down

    smallest = node

    # Compare with left child
    if node.left and node.left.value < smallest.value:
        smallest = node.left

    # Compare with right child
    if node.right and node.right.value < smallest.value:
        smallest = node.right

    # If the current node is not the smallest, swap the nodes
    if smallest != node:
        self._swap_nodes(node, smallest)
        # Recursively call heapify_down on the swapped node
        self._heapify_down(smallest)
"""