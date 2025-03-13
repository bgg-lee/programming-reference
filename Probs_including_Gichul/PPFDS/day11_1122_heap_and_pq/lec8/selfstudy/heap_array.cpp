#include <iostream>
#include <vector>
using namespace std;

class MinHeapArray {
    private:
        vector<int> heap;
        int size;
        void heapify(int index);
        int parent(int i){return (i-1)/2;}
        int left(int i){return i*2+1;}
        int right(int i){return i*2+2;}
    public:
        MinHeapArray() {size = 0;}
        void insert(int key);
        int extract_min();
        void print_heap() const;
};

// Initialize the heap
void MinHeapArray::print_heap() const {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

// Function definitions (to be implemented)
void MinHeapArray::insert(int key) {
    // TODO: Add an element to the heap and restore min-heap property
    heap.push_back(key);
    size++;
    int n = size-1;
    // Bubble up
    while(n>0 && heap[parent(n)] > heap[n]){
        swap(heap[parent(n)],heap[n]);
        n = parent(n);
    }
}

int MinHeapArray::extract_min() {
    // TODO: Remove and return the minimum element (root) while maintaining the heap property
    if(size==0){
        cout << "ERROR" << endl;
        return -1;
    }else{
        int ans = heap[0];
        swap(heap[0],heap[size-1]);
        heap.pop_back();
        size--;
        // for(int i=size/2;i>=0;i--){ // 반만 돌아도 heapify 만족가능 --> children 없는 Node들 무시
        //     heapify(i);
        // }
        heapify(0);
        return ans;
    }

}

void MinHeapArray::heapify(int index) {
    // TODO: Restore the min-heap property after deletion
    int smallest = index;
    int l = left(index);
    int r = right(index);
    if(l<size && heap[l] < heap[index]) smallest = l;
    if(r<size && heap[r] < heap[smallest]) smallest = r;

    if(smallest != index){
        swap(heap[index],heap[smallest]);
        heapify(smallest);
    }
}

// Main function to test the logic
int main() {
    MinHeapArray heap;

    // Test cases
    heap.insert(10);
    heap.insert(5);
    heap.insert(20);
    heap.insert(7);
    heap.insert(11);
    heap.insert(999);
    heap.insert(1);

    cout << "Heap after insertions: ";
    heap.print_heap();

    cout << "Extracted Min: " << heap.extract_min() << endl;
    cout << "Heap after extraction: ";
    heap.print_heap();

    cout << "Extracted Min: " << heap.extract_min() << endl;
    cout << "Heap after extraction: ";
    heap.print_heap();

    heap.insert(0);
    heap.insert(3);
    cout << "Heap after insertions: ";
    heap.print_heap();

    return 0;
}