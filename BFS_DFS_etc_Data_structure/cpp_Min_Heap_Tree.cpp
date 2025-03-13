#include <iostream>
#include <queue>
using namespace std;

// Tree Node Structure
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

// MinHeapTree Class
class MinHeapTree {
private:
    TreeNode* root;
    int size;

    void heapifyUp(TreeNode* node){
        while(node->parent){
            if(node->value < node->parent->value){
                swap(node->value,node->parent->value);
                node = node->parent;
            }
            else break;
        }
    }
    void heapifyDown(TreeNode* node){
        if(!node || !node->left) return;

        TreeNode* smallest = node;
        if(smallest->value > node->left->value){
            smallest = node->left;
        }
        if(node->right && smallest->value > node->right->value){
            smallest = node->right;
        }
        if(smallest!=node){
            swap(node->value,smallest->value);
            heapifyDown(smallest);
        }
    }

public:
    MinHeapTree() : root(nullptr), size(0) {}

    void insert(int value){
        TreeNode* new_node = new TreeNode(value);
        size++;
        if(!root){
            root = new_node;
            return;
        } 
        // 들어갈 자리를 찾고, 거기에 넣고, heapUP
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(!curr->left){
                curr->left = new_node;
                new_node->parent = curr;
                break;
            }
            if(!curr->right){
                curr->right = new_node;
                new_node->parent = curr;
                break;
            }
            q.push(curr->left);
            q.push(curr->right);
        }
        heapifyUp(new_node);
    }
    int extractMin(){        
        if(!root) return -1;
        int ans = root->value;

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp = nullptr;
        while(!q.empty()){
            TreeNode* curr = q.front();
            temp = curr;
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        // 막 node와 root node value 스왑
        swap(root->value,temp->value);

        // temp 삭제
        if(temp==root){
            delete root;
            root = nullptr;
        }
        else{
            if(temp == temp->parent->left){
                temp->parent->left = nullptr;
            }else{
                temp->parent->right = nullptr;
            }
            temp = nullptr;
        }
        // delete temp;
        heapifyDown(root);
        size--;
        return ans;
    }

    int getMin() const{
        if(!root) return -1;
        return root->value;
    }
    void printHeap() const{
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        cout << "[ ";
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            cout << curr->value << " ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        cout<< " ]" << endl;
    }
    void freeHeap(){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            delete curr;
        }
        root = nullptr;
        size = 0;
    }
};

// Test cases
void runTestCases() {
    MinHeapTree heap;

    // Test 1: Insert single element and extract
    cout << "Test 1: Insert single element and extract" << endl;
    heap.insert(10);
    heap.printHeap(); // Expected: [10]
    cout << "Extracting min: " << heap.extractMin() << endl; // Expected: 10
    heap.printHeap(); // Expected: []

    // Test 2: Extract from an empty heap
    cout << "\nTest 2: Extract from an empty heap" << endl;
    cout << "Extracting min: " << heap.extractMin() << endl; // Expected: -1

    // Test 3: Insert multiple elements in ascending order
    cout << "\nTest 3: Insert multiple elements in ascending order" << endl;
    heap.insert(5);
    heap.insert(10);
    heap.insert(15);
    heap.insert(20);
    heap.printHeap(); // Expected: [5, 10, 15, 20]
    cout << "Extracting min: " << heap.extractMin() << endl; // Expected: 5
    heap.printHeap(); // Expected: [10, 20, 15]

    // Test 4: Insert multiple elements in descending order
    cout << "\nTest 4: Insert multiple elements in descending order" << endl;
    heap.insert(25);
    heap.insert(1);
    heap.insert(8);
    heap.insert(3);
    heap.printHeap(); // Expected: [1, 10, 8, 20, 25, 15, 3]

    // Test 5: Repeated extraction until heap is empty
    cout << "\nTest 5: Repeated extraction until heap is empty" << endl;
    while (heap.getMin() != -1) {
        cout << "Extracting min: " << heap.extractMin() << endl;
        heap.printHeap();
    }

    // Test 6: Inserting into an empty heap after extraction
    cout << "\nTest 6: Inserting into an empty heap after extraction" << endl;
    heap.insert(50);
    heap.insert(30);
    heap.insert(40);
    heap.insert(35);
    heap.insert(45);
    heap.printHeap(); // Expected: [30, 35, 40, 50, 45]

    // Test 7: Insert duplicate values
    cout << "\nTest 7: Insert duplicate values" << endl;
    heap.insert(35);
    heap.insert(40);
    heap.printHeap(); // Expected: Duplicates should maintain heap order
    cout << "Extracting min: " << heap.extractMin() << endl; // Expected: 30

    // Test 8: Extract min repeatedly with duplicate values
    cout << "\nTest 8: Extract min repeatedly with duplicate values" << endl;
    while (heap.getMin() != -1) {
        cout << "Extracting min: " << heap.extractMin() << endl;
        heap.printHeap();
    }

    // Test 9: Insert into heap with large values
    cout << "\nTest 9: Insert into heap with large values" << endl;
    heap.insert(100000);
    heap.insert(99999);
    heap.insert(100001);
    heap.insert(50000);
    heap.printHeap(); // Expected: Heap maintains order even with large numbers

    // Test 10: Stress test with multiple inserts and extracts
    cout << "\nTest 10: Stress test with multiple inserts and extracts" << endl;
    for (int i = 1; i <= 20; i++) {
        heap.insert(i);
    }
    heap.printHeap(); // Check heap order
    while (heap.getMin() != -1) {
        cout << "Extracting min: " << heap.extractMin() << endl;
        heap.printHeap();
    }

    // Test 11: Extract from empty heap after stress test
    cout << "\nTest 11: Extract from empty heap after stress test" << endl;
    cout << "Extracting min: " << heap.extractMin() << endl; // Expected: -1

    // Free the heap
    heap.freeHeap();
    cout << "\nAll tests completed!" << endl;
}


int main() {
    runTestCases();
    return 0;
}



/*
Solution


#include <iostream>
#include <queue>
using namespace std;

// Tree Node Structure
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

// MinHeapTree Class
class MinHeapTree {
private:
    TreeNode* root;
    int size;

    // Helper to perform heapify upwards
    void heapifyUp(TreeNode* node) {
        while (node->parent && node->value < node->parent->value) {
            swap(node->value, node->parent->value);
            node = node->parent;
        }
    }

    // Helper to perform heapify downwards
    void heapifyDown(TreeNode* node) {
        while (node) {
            TreeNode* smallest = node;

            if (node->left && node->left->value < smallest->value) {
                smallest = node->left;
            }

            if (node->right && node->right->value < smallest->value) {
                smallest = node->right;
            }

            if (smallest != node) {
                swap(node->value, smallest->value);
                node = smallest;
            } else {
                break;
            }
        }
    }

    // Helper to find the last node in level-order
    TreeNode* findLastNode() {
        queue<TreeNode*> q;
        q.push(root);

        TreeNode* last = nullptr;
        while (!q.empty()) {
            last = q.front();
            q.pop();

            if (last->left) q.push(last->left);
            if (last->right) q.push(last->right);
        }

        return last;
    }

public:
    MinHeapTree() : root(nullptr), size(0) {}

    // Insert a value into the heap
    void insert(int value) {
        TreeNode* newNode = new TreeNode(value);
        size++;

        if (!root) {
            root = newNode;
            return;
        }

        // Find the insertion point using level-order traversal
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (!curr->left) {
                curr->left = newNode;
                newNode->parent = curr;
                break;
            } else if (!curr->right) {
                curr->right = newNode;
                newNode->parent = curr;
                break;
            }

            q.push(curr->left);
            q.push(curr->right);
        }

        // Restore the Min Heap property
        heapifyUp(newNode);
    }

    // Extract and return the minimum value
    int extractMin() {
        if (!root) {
            cout << "Heap underflow: no elements to extract\n";
            return -1;
        }

        int minValue = root->value;

        // Find the last node
        TreeNode* lastNode = findLastNode();

        // Replace root value with last node value
        if (lastNode == root) {
            delete root;
            root = nullptr;
        } else {
            root->value = lastNode->value;

            if (lastNode->parent->left == lastNode) {
                lastNode->parent->left = nullptr;
            } else {
                lastNode->parent->right = nullptr;
            }

            delete lastNode;

            // Restore the Min Heap property
            heapifyDown(root);
        }

        size--;
        return minValue;
    }

    // Get the minimum value without removing it
    int getMin() const {
        if (!root) {
            cout << "Heap is empty\n";
            return -1;
        }
        return root->value;
    }

    // Print the heap in level-order
    void printHeap() const {
        if (!root) {
            cout << "Heap is empty\n";
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        cout << "[";
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            cout << node->value << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << "]" << endl;
    }

    // Free all nodes in the heap
    void freeHeap() {
        if (!root) return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);

            delete node;
        }

        root = nullptr;
        size = 0;
    }
};

// Test case runner
void runTestCases() {
    MinHeapTree heap;

    // Insertions
    cout << "Inserting 10..." << endl;
    heap.insert(10);
    heap.printHeap(); // Expected: [10]

    cout << "Inserting 20..." << endl;
    heap.insert(20);
    heap.printHeap(); // Expected: [10, 20]

    cout << "Inserting 5..." << endl;
    heap.insert(5);
    heap.printHeap(); // Expected: [5, 20, 10]

    cout << "Inserting 15..." << endl;
    heap.insert(15);
    heap.printHeap(); // Expected: [5, 15, 10, 20]

    cout << "Inserting 25..." << endl;
    heap.insert(25);
    heap.printHeap(); // Expected: [5, 15, 10, 20, 25]

    // Minimum value
    cout << "\nMinimum value: " << heap.getMin() << endl; // Expected: 5

    // Extract min
    cout << "\nExtracting min..." << endl;
    cout << "Extracted: " << heap.extractMin() << endl; // Expected: 5
    heap.printHeap(); // Expected: [10, 15, 25, 20]

    // Free heap
    heap.freeHeap();
}

*/