# Max heap
class Node:
    def __init__(self, key):
        self.key = key
        self.next = None

class PriorityQueueLinkedList:
    def __init__(self, is_min=True):
        self.head = None
        self.is_min = is_min  # True for min-priority, False for max-priority

    def enqueue(self, key):
        # TODO: Add element while maintaining priority order
        new_node = Node(key)
        curr = self.head
        
        if not self.head or self.head.key < new_node.key:
            new_node.next= self.head
            self.head = new_node
        else:
            while curr.next and curr.next.key > new_node.key :
                curr = curr.next
            new_node.next = curr.next
            curr.next = new_node

    def dequeue(self):
        # TODO: Remove and return the highest/lowest priority element
        if not self.head : return
        else:
            temp = self.head.key
            self.head = self.head.next
            return temp
        
    def print_queue(self):
        current = self.head
        while current:
            print(current.key, end=" -> ")
            current = current.next
        print("None")

# Test case
pq = PriorityQueueLinkedList(is_min=False)
pq.enqueue(10)
pq.enqueue(5)
pq.enqueue(20)
pq.enqueue(1)
pq.print_queue()
print(pq.dequeue())
pq.print_queue()
