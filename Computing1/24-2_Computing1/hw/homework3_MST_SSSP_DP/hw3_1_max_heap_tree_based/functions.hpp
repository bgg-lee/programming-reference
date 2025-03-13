#include <iostream> 
#include <climits> 
#include <queue>
#include <cmath>
using namespace std; 

struct Node {
    int val;
    Node * left = nullptr;
    Node * right = nullptr;
    Node * parent = nullptr;
};
  

// A class for Min Heap 
class MaxHeap 
{ 
    Node * root;
    Node * last_node; // node 추가 할 때부터 last_node를 관리하는구먼
    int heapsize;

public: 
    // Constructor 
    MaxHeap();
  
    // Returns the node pointer that includes the maximum value (root node)
    Node * getMax();

    void printHeap();

    void swap(Node * a, Node * b);

    // Inserts a new key 'k' 
    void enqueue(int k); 

    // Delete the maxmium value (root node)
    void dequeue();
    
    // 내가 추가
    void heap_down(Node* n);
}; 


