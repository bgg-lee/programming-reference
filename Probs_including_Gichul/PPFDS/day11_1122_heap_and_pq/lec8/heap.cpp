#include <iostream>
#include <vector>
#include <utility> // for std::pair
#include <stdexcept> // for exceptions
using namespace std;
#include <algorithm> // for SWAP!

// key 값 기준으로 정렬을 하라 -> value는 추후에 확장가능하니까 일단 무시

class MaxHeap {
private:
    vector<pair<int, int> > heap; // key-value pairs 

    // Helper functions
    int parent(int i) { return (i - 1) / 2; }
    int left_child(int i) { return 2 * i + 1; }
    int right_child(int i) { return 2 * i + 2; }

    // Heapify to maintain max-heap property
    void max_heapify(int i) {
        //////////////////////////////
        // FILL HERE
        // 아래녀석들은 index
        int left = left_child(i);
        int right = right_child(i);
        int largest = i;

        if(left>=heap.size()) return;

        // child 없는데 idx집어넣는 경우를 고려한거네
        if(heap[left].first > heap[i].first) largest = left;
        if(right<heap.size())
            {if(heap[right].first > heap[largest].first) largest = right;}
        // if(left<heap.size() && heap[left].first > heap[i].first) largest = left;
        // if(right<heap.size() && heap[right].first > heap[largest].first) largest = right;
        if(largest != i){
            swap(heap[i],heap[largest]);
            max_heapify(largest);
        }

        //////////////////////////////       
    }


public:
    void build_max_heap(){
        //////////////////////////////
        // FILL HERE
        int n = heap.size();
        for(int i=n/2;i>=0;i--){
            max_heapify(i);
        }
        //////////////////////////////
    }

    // INSERT DATA INTO ARRAY    
    void data_insert(int key, int value) {
        heap.push_back(make_pair(key, value));
    }
    
    // PRINT HEAP BY ORDER
    void print_heap() const {
        for (int i=0; i<heap.size(); i++) {
            cout << "(" << heap[i].first << ", " << heap[i].second << ") ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap max_heap;

    // Insert key-value pairs
    max_heap.data_insert(10, 100);
    max_heap.data_insert(5, 50);
    max_heap.data_insert(20, 200);
    max_heap.data_insert(15, 150);
    max_heap.data_insert(1, 90);
    max_heap.data_insert(5, 10);
    max_heap.data_insert(16, 350);

    std::cout << "Initial heap: ";
    max_heap.print_heap();

    
    std::cout << "Build max-heap: ";
    max_heap.build_max_heap();
    max_heap.print_heap();

    return 0;
}

/*
    이런 거를 C언어로 구현할 수 있어야한다.
    Structure를 많이 써야하니까 좀 복잡하긴 할 것이다.
    vector가 없으니..

*/