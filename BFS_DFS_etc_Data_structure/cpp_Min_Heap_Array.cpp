#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int index){
        while(parent(index)>=0){
            if(heap[index] < heap[parent(index)]){
                swap(heap[index],heap[parent(index)]);
                index = parent(index);
            }
            else break;
        }
    }
    void heapifyDown(int index){
        if(left(index) >= heap.size()) return;
        int smallest = index;
        if(heap[smallest] > heap[left(index)]){
            smallest = left(index);
        }
        if(right(index)<heap.size() && heap[smallest]>heap[right(index)]){
            smallest = right(index);
        }
        if(smallest != index){
            swap(heap[smallest],heap[index]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap() {}
// Inserts a key into the heap
    void insert(int key){
        heap.push_back(key);
        heapifyUp(heap.size()-1);
    }
// Extracts and returns the minimum value
    int extractMin(){
        if(heap.empty()) return -1;

        int ans = heap[0];
        swap(heap[0],heap[heap.size()-1]);
        heap.pop_back();
        heapifyDown(0);
        return ans;
    }
// Returns the minimum value without removing it
    int getMin() const{
        if(heap.empty()) return -1;
        else return heap[0];
    }
// Prints the heap for debugging
    void printHeap() const{
        cout << "[";
        for(auto const x : heap){
            cout << x << " "; 
        }
        cout << "]" << endl;
    }
};

// Test cases
void runTestCases() {
    MinHeap minHeap;

    cout << "Inserting 10..." << endl;
    minHeap.insert(10);
    minHeap.printHeap(); // Expected: [10]

    cout << "Inserting 20..." << endl;
    minHeap.insert(20);
    minHeap.printHeap(); // Expected: [10, 20]

    cout << "Inserting 5..." << endl;
    minHeap.insert(5);
    minHeap.printHeap(); // Expected: [5, 20, 10]

    cout << "Inserting 15..." << endl;
    minHeap.insert(15);
    minHeap.printHeap(); // Expected: [5, 15, 10, 20]

    cout << "Inserting 25..." << endl;
    minHeap.insert(25);
    minHeap.printHeap(); // Expected: [5, 15, 10, 20, 25]

    cout << "\nMinimum value: " << minHeap.getMin() << endl; // Expected: 5

    cout << "\nExtracting min..." << endl;
    cout << "Extracted: " << minHeap.extractMin() << endl; // Expected: 5
    minHeap.printHeap(); // Expected: [10, 15, 25, 20]

    cout << "\nExtracting min..." << endl;
    cout << "Extracted: " << minHeap.extractMin() << endl; // Expected: 10
    minHeap.printHeap(); // Expected: [15, 20, 25]
}
int main() {
    runTestCases();
    return 0;
}

/*
Solution
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Restore the Min Heap property upwards
    void heapifyUp(int index) {
        while (index > 0 && heap[index] < heap[parent(index)]) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    // Restore the Min Heap property downwards
    void heapifyDown(int index) {
        int smallest = index;
        int leftChild = left(index);
        int rightChild = right(index);

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap() {}

    // Inserts a key into the heap
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    // Extracts and returns the minimum value
    int extractMin() {
        if (heap.empty()) {
            throw runtime_error("Heap underflow: no elements to extract");
        }

        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return minValue;
    }

    // Returns the minimum value without removing it
    int getMin() const {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }

    // Prints the heap for debugging
    void printHeap() const {
        cout << "[";
        for (size_t i = 0; i < heap.size(); ++i) {
            cout << heap[i];
            if (i < heap.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

// Test cases
void runTestCases() {
    MinHeap minHeap;

    cout << "Inserting 10..." << endl;
    minHeap.insert(10);
    minHeap.printHeap(); // Expected: [10]

    cout << "Inserting 20..." << endl;
    minHeap.insert(20);
    minHeap.printHeap(); // Expected: [10, 20]

    cout << "Inserting 5..." << endl;
    minHeap.insert(5);
    minHeap.printHeap(); // Expected: [5, 20, 10]

    cout << "Inserting 15..." << endl;
    minHeap.insert(15);
    minHeap.printHeap(); // Expected: [5, 15, 10, 20]

    cout << "Inserting 25..." << endl;
    minHeap.insert(25);
    minHeap.printHeap(); // Expected: [5, 15, 10, 20, 25]

    cout << "\nMinimum value: " << minHeap.getMin() << endl; // Expected: 5

    cout << "\nExtracting min..." << endl;
    cout << "Extracted: " << minHeap.extractMin() << endl; // Expected: 5
    minHeap.printHeap(); // Expected: [10, 15, 25, 20]

    cout << "\nExtracting min..." << endl;
    cout << "Extracted: " << minHeap.extractMin() << endl; // Expected: 10
    minHeap.printHeap(); // Expected: [15, 20, 25]
}

int main() {
    runTestCases();
    return 0;
}
*/