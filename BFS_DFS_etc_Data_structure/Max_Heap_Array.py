class MaxHeapArray:
    def __init__(self, capacity):
        """
        Initialize the MaxHeapArray with a fixed capacity.
        Attributes:
        - heap: List to store heap elements.
        - capacity: Maximum number of elements in the heap.
        - size: Current number of elements in the heap.
        """
        self.heap = [0] * capacity  # Array for the heap
        self.capacity = capacity  # Maximum capacity
        self.size = 0  # Current number of elements in the heap

    def parent(self, i):
        """Return the index of the parent node."""
        return (i - 1) // 2

    def left(self, i):
        """Return the index of the left child node."""
        return 2 * i + 1

    def right(self, i):
        """Return the index of the right child node."""
        return 2 * i + 2

    def insert_key(self, k):
        """Insert a new key into the heap."""
        # Implementation here
        if self.is_full():
            print("Heap overflow: cannot insert key")
            return
        self.heap[self.size] = k
        self.heapify_up(self.size)
        self.size += 1

    def extract_max(self):
        """Extract and return the maximum value from the heap."""
        if self.is_empty() :
            print("EMPTY")
            return -1
        else:
            ans = self.heap[0]
            self.heap[0],self.heap[self.size-1] = self.heap[self.size-1],self.heap[0]
            self.size -= 1
            self.heap[self.size] = None  # Clear the last element (optional)
            self.heapify_down(0)
            return ans
    def peek(self):
        """Return the maximum value without removing it."""
        if self.is_empty() :
            print("EMPTY")
            return -1
        else : return self.heap[0]

    def heapify_up(self, i):
        """Restore the heap property from a node upwards."""
        # Implementation here
        ##For Enqueue
        while self.parent(i) >= 0 :# while i > 0 and self.heap[i] > self.heap[self.parent(i)]:
            if self.heap[i] > self.heap[self.parent(i)]:
                self.heap[self.parent(i)],self.heap[i]=self.heap[i],self.heap[self.parent(i)]
            i = self.parent(i)
        

    def heapify_down(self, i):
        """Restore the heap property from a node downwards."""
        # Implementation here
        ##For Dequeue
        while self.left(i) <= self.size-1 :
            left = self.left(i)
            right = self.right(i)
            largest = i
            if self.heap[largest] < self.heap[left]:
                largest = left
            if right <= self.size-1 and self.heap[largest] < self.heap[right] :
                largest = right
            if largest != i:
                self.heap[largest],self.heap[i] = self.heap[i],self.heap[largest]
                i = largest
            else : break

    def is_full(self):
        """Check if the heap is full."""
        return self.size == self.capacity

    def is_empty(self):
        """Check if the heap is empty."""
        return self.size == 0

# Test cases for MaxHeapArray
print("Testing MaxHeapArray...\n")
max_heap = MaxHeapArray(10)

# Insertions
print("Inserting 10...")
max_heap.insert_key(10)
print("Heap:", max_heap.heap[:max_heap.size])  # Expected: [10]

print("Inserting 20...")
max_heap.insert_key(20)
print("Heap:", max_heap.heap[:max_heap.size])  # Expected: [20, 10]

print("Inserting 5...")
max_heap.insert_key(5)
print("Heap:", max_heap.heap[:max_heap.size])  # Expected: [20, 10, 5]

print("Inserting 15...")
max_heap.insert_key(15)
print("Heap:", max_heap.heap[:max_heap.size])  # Expected: [20, 15, 5, 10]

print("Inserting 25...")
max_heap.insert_key(25)
print("Heap:", max_heap.heap[:max_heap.size])  # Expected: [25, 20, 5, 10, 15]

# Peek
print("\nPeek maximum value:", max_heap.peek())  # Expected: 25

# Extract max
print("\nExtracting maximum value...")
print("Extracted:", max_heap.extract_max())  # Expected: 25
print("Heap after extraction:", max_heap.heap[:max_heap.size])  # Expected: [20, 15, 5, 10]

print("\nExtracting maximum value...")
print("Extracted:", max_heap.extract_max())  # Expected: 20
print("Heap after extraction:", max_heap.heap[:max_heap.size])  # Expected: [15, 10, 5]

# Check heap state
print("\nHeap size:", max_heap.size)  # Expected: 3
print("Is heap empty?:", max_heap.is_empty())  # Expected: False

# Clear heap
print("\nClearing the heap...")
while not max_heap.is_empty():
    print("Extracted:", max_heap.extract_max())
print("Is heap empty?:", max_heap.is_empty())  # Expected: True
