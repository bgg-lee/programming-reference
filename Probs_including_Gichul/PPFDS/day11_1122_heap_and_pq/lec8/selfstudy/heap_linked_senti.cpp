#include <iostream>
using namespace std;

// Node structure for Linked List
struct Node {
    int key;
    Node* next;

    Node(int k) : key(k), next(nullptr) {}
};

// MaxHeap implemented using Linked List with a Sentinel Node
class MaxHeapLinkedList {
private:
    Node* sentinel; // Sentinel node to simplify boundary conditions

public:
    // Constructor
    MaxHeapLinkedList() {
        sentinel = new Node(-1); // Sentinel node with dummy key
        sentinel->next = nullptr;
    }

    // Destructor to clean up memory
    ~MaxHeapLinkedList() {
        Node* current = sentinel;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Initialize the heap (reset)
    void init_heap() {
        Node* current = sentinel->next;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        sentinel->next = nullptr;
    }

    // Insert a new key into the heap
    void insert(int key);

    // Extract the maximum key from the heap
    int extract_max();

    // Print the heap elements
    void print_heap() const {
        Node* current = sentinel->next; // Skip the sentinel node
        while (current) {
            cout << current->key << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

// Main function to test the logic
int main() {
    MaxHeapLinkedList heap;

    // Initialize the heap
    heap.init_heap();

    // Test cases
    heap.extract_max(); // ERROR
    heap.insert(10);
    heap.insert(5);
    heap.insert(20);
    heap.insert(7);
    heap.insert(11);

    cout << "Heap after insertions: ";
    heap.print_heap();

    cout << "Extracted Max: " << heap.extract_max() << endl;
    cout << "Heap after extraction: ";
    heap.print_heap();

    cout << "Extracted Max: " << heap.extract_max() << endl;
    cout << "Heap after extraction: ";
    heap.print_heap();

    heap.insert(15);
    cout << "Heap after insertions: ";
    heap.print_heap();

    return 0;
}

// Function definitions (to be implemented)
void MaxHeapLinkedList::insert(int key) {
    // TODO: Insert a new key into the list while maintaining max-heap property
    // Implement by finding the correct position in descending order
    Node* temp = sentinel;
    Node* new_node = new Node(key);
    while(temp->next && temp->next->key > new_node->key){
        temp = temp->next;
    }
    new_node -> next = temp -> next;
    temp -> next = new_node;
}

int MaxHeapLinkedList::extract_max() {
    // TODO: Remove and return the maximum key while maintaining max-heap property
    // Remove the first node after the sentinel and re-adjust the list
    if(!sentinel->next){
        cout << "ERROR\n"<<endl;
        return -1;
    }
    else{
        int ans = sentinel->next->key;
        Node* temp = sentinel->next;
        sentinel->next = sentinel->next->next;
        delete temp;
        return ans;
    }
    
}
