#include <iostream>
#include <vector>
#include <utility> // for std::pair
#include <stdexcept> // for exceptions
using namespace std;

// 이게 보니까 array로 하면 좀 쉽다. search부분에서
// Linked list로도 구현할 수 있어야겠다. search가 좀 어렵게

class MaxHeap {
private:
    vector<pair<int, int> > heap; // key-value pairs 

    // Helper functions
    int parent(int i) { return (i - 1) / 2; }
    int left_child(int i) { return 2 * i + 1; }
    int right_child(int i) { return 2 * i + 2; }

    // Heapify to maintain max-heap property
    void max_heapify(int i) {
        // FILL HERE
        int largest = i;
        int left = left_child(i);
        int right = right_child(i);        

        if (left < heap.size() && heap[left].first > heap[largest].first) {
            largest = left;
        }
        if (right < heap.size() && heap[right].first > heap[largest].first) {
            largest = right;
        }

        if (largest != i) {
            swap(heap[i], heap[largest]);
            max_heapify(largest);
        }
    }


public:
    bool is_empty(){
        return heap.empty();
    }

    void enqueue(int key, int value) {
       //////////////////
       // FILL HERE
    //    너무 야매;;
    //    data_insert(key,value);
    //    build_max_heap();
        // 맨 뒤에 data를 꽂아넣고 increase key를 쓰라
        heap.push_back({key,value});

        // current data idx
        int i = heap.size() - 1;

        // 밑에서부터 끌어올리기 Bubble up
        while(i!=0 && heap[parent(i)].first < heap[i].first){
            swap(heap[i],heap[parent(i)]);
            i = parent(i);
        }
       //////////////////
    }    
   
    pair<int, int> dequeue() {
       //////////////////
       // FILL HERE
    // 야매다
    //    int n = heap.size();
    // //    if(n==0) return;

    //    pair<int,int> temp = heap[0];
    //    swap(heap[0],heap[n-1]);
    //    heap.pop_back();
    //    build_max_heap();
    //    return temp;
        //이건.. 나랑 야매 방법이 똑같네ㅋ
        pair<int,int> max = heap[0];
        swap(heap[0],heap[heap.size()-1]);
        heap.pop_back();
        max_heapify(0);
        return max;

       //////////////////
    }    

    void build_max_heap(){
        // FILL HERE
        int heap_size = heap.size();
        for (int i=heap_size/2; i>=0; i--){
            max_heapify(i); 
        }
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
    // enqueue --> data를 넣음과 동시에 max_heap propery가 만족돼야 함.
    max_heap.enqueue(10, 100);
    max_heap.print_heap();
    max_heap.enqueue(5, 50);
    max_heap.print_heap();
    max_heap.enqueue(20, 200);
    max_heap.print_heap();
    max_heap.enqueue(15, 150);
    max_heap.print_heap();
    max_heap.enqueue(1, 90);
    max_heap.print_heap();
    cout << "---up:enqueue------down:dequeue----" << endl;

    pair<int, int> data = max_heap.dequeue();
    cout << "(" << data.first << ", " << data.second << ") " <<endl;
    max_heap.print_heap();
    data = max_heap.dequeue();
    cout << "(" << data.first << ", " << data.second << ") " <<endl;
    max_heap.print_heap();
    data = max_heap.dequeue();
    cout << "(" << data.first << ", " << data.second << ") " <<endl;
    max_heap.print_heap();
    data = max_heap.dequeue();
    cout << "(" << data.first << ", " << data.second << ") " <<endl;
    max_heap.print_heap();


    return 0;
}

/*
    이것들 모두 C++에 이미 내장되어 있다.
    즉,, 내가 봤을 때 이걸 C로 낼 거 같다는 느낌이 든다.
    아니면 해당 priority queue include 못하게 하고 구현시키는 방법은 있을 수도..!
    minqueue도 해보자.
*/