class PriorityQueueArray:
    def __init__(self, is_min=True):
        self.heap = []
        self.is_min = is_min  # True for min-heap, False for max-heap

    def parent(self, i):
        return (i - 1) // 2

    def left_child(self, i):
        return 2 * i + 1

    def right_child(self, i):
        return 2 * i + 2

    def enqueue(self, key):
        # TODO: Add element and maintain heap property
        self.heap.append(key)
        n = len(self.heap)-1
        #bubble up
        while n != 0 and self.heap[self.parent(n)] > self.heap[n]:
            self.heap[self.parent(n)],self.heap[n] = self.heap[n],self.heap[self.parent(n)]
            n = self.parent(n)

    def dequeue(self):
        # TODO: Remove and return top element while maintaining heap property
        temp = self.heap[0]
        n = len(self.heap)
        self.heap[0],self.heap[n-1] = self.heap[n-1],self.heap[0]
        self.heap.pop()
        self.heapify(0)
        return temp
    
    def heapify(self, i):
        # TODO: Maintain heap property at index i
        # min-heap
        if self.is_min:
            smallest = i
            left = self.left_child(i)
            right = self.right_child(i)

            if left<len(self.heap) and self.heap[i] > self.heap[left]:
                smallest = left
            if right<len(self.heap) and self.heap[smallest] > self.heap[right]:
                smallest = right
            if smallest != i:
                self.heap[i],self.heap[smallest] = self.heap[smallest],self.heap[i]
                self.heapify(smallest)
        # max는 else 후 반대로

    def print_queue(self):
        print(self.heap)

# Test case
pq = PriorityQueueArray(is_min=True)
pq.enqueue(10)
pq.enqueue(5)
pq.enqueue(20)
pq.enqueue(1)
pq.print_queue()
print(pq.dequeue())
pq.print_queue()
