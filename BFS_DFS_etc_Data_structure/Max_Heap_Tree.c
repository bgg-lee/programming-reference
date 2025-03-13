#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the structure for a tree node
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* parent;
} TreeNode;

// Define the structure for the Max Heap
typedef struct MaxHeap {
    TreeNode* root;   // Pointer to the root node
    int size;         // Current size of the heap
} MaxHeap;

// Function prototypes
MaxHeap* createHeap(){
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    // heap 객체 생성 후 초기화
    heap->root = NULL;
    heap->size = 0;
    return heap;
};
TreeNode* createNode(int value){
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;
    return new_node;
}
void heapifyUp(TreeNode* node);
void heapifyDown(TreeNode* node);

void insertKey(MaxHeap* heap, int value){
    // Insert를 할 last node를 찾아야 한다.
    TreeNode* new_node = createNode(value);
    if(!heap->root){// root가 없는 경우
        heap->root = new_node;
    }else{ // root가 이미 있는 경우
        TreeNode* q[heap->size];
        int front = 0, rear = 0;
        q[rear++] = heap->root;        
        while(front < rear){
            TreeNode* curr = q[front++];
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
            q[rear++] = curr->left;
            q[rear++] = curr->right;
        }
        heapifyUp(new_node);
    }
    heap->size ++;
}
int extractMax(MaxHeap* heap){
    if(!heap->root) return -1;
    int ans = heap->root->value;

    // root랑 맨 끝자락 놈이랑 SWAP 후 맨 끝자락 없애고 root heapdown
    TreeNode* q[heap->size];
    int front = 0, rear = 0;
    q[rear++] = heap->root;
    TreeNode* temp = NULL;
    while(front<rear){
        TreeNode* curr = q[front++];
        temp = curr;
        if(curr->left) q[rear++] = curr->left;
        if(curr->right) q[rear++] = curr->right;
    }
    // temp는 이 Heap의 마지막 Node
    // root만 있던 case
    if(!temp->parent) heap->root = NULL;
    else{
        heap->root->value = temp->value;
        if(temp == temp->parent->left){
            temp->parent->left = NULL;
        }else temp->parent->right = NULL;
        free(temp);
    }
    heapifyDown(heap->root);
    heap->size--;
    return ans;
}
int getMax(MaxHeap* heap){ // Clear
    if(heap->size == 0) return -1;
    return heap->root->value;
}
void heapifyUp(TreeNode* node){
    TreeNode* temp = node;
    while(temp->parent){
        if(temp->parent->value < temp->value){
            // SWAPING
            int swap = temp->value;
            temp->value = temp->parent->value;
            temp->parent->value = swap;
            // SWAP Complete
            temp = temp->parent;
        }
        else break;
    }
}
void heapifyDown(TreeNode* node){
    // Base Case
    if(!node || !node->left) return;
    TreeNode* largest = node;
    if(largest->value < node->left->value){
        largest = node->left;
    }
    if(node->right && largest->value < node->right->value){
        largest = node->right;
    }
    if(largest != node){
        // Value 끼리 swap
        int temp = node->value;
        node->value = largest->value;
        largest->value = temp;
        heapifyDown(largest);
    }
    else return;

}
void freeHeap(MaxHeap* heap){
    TreeNode* q[heap->size+1]; // 넉넉하게 할당
    int front = 0, rear = 0;
    q[rear] = heap->root;
    rear++;
    while(front<rear){
        TreeNode* curr = q[front];
        front++;
        if(curr->left){
            q[rear] = curr->left;
            rear++;
        }
        if(curr->right){
            q[rear] = curr->right;
            rear++;
        }
        free(curr);
    }
    free(heap);
}
void printHeap(TreeNode* root){
    if(!root) return;
    TreeNode* q[1000]; // 넉넉하게 할당
    int front = 0, rear = 0;
    q[rear] = root;
    rear++;
    printf("[");
    while(front<rear){
        TreeNode* curr = q[front];
        front++;
        printf("%d ",curr->value);
        if(curr->left){
            q[rear] = curr->left;
            rear++;
        }
        if(curr->right){
            q[rear] = curr->right;
            rear++;
        }
    }
    printf("]\n");
}
// Test case runner
void runTestCases(){
    printf("Testing MaxHeap with Tree Nodes...\n");

    MaxHeap* heap = createHeap();

    // Insert keys
    printf("Inserting 10...\n");
    insertKey(heap, 10);
    printHeap(heap->root); // Expected: 10

    printf("Inserting 20...\n");
    insertKey(heap, 20);
    printHeap(heap->root); // Expected: 20, 10

    printf("Inserting 5...\n");
    insertKey(heap, 5);
    printHeap(heap->root); // Expected: 20, 10, 5

    printf("Inserting 15...\n");
    insertKey(heap, 15);
    printHeap(heap->root); // Expected: 20, 15, 5, 10

    printf("Inserting 25...\n");
    insertKey(heap, 25);
    printHeap(heap->root); // Expected: 25, 20, 5, 10, 15

    // Peek max
    printf("\nMax value: %d\n", getMax(heap)); // Expected: 25

    // Extract max
    printf("\nExtracting max...\n");
    printf("Extracted: %d\n", extractMax(heap)); // Expected: 25
    printHeap(heap->root); // Expected: 20, 15, 5, 10

    printf("\nExtracting max...\n");
    printf("Extracted: %d\n", extractMax(heap)); // Expected: 20
    printHeap(heap->root); // Expected: 15, 10, 5

    // Free the heap
    freeHeap(heap);
    printf("\nAll tests passed!\n");
}

 int main(){
    runTestCases();
    return 0;
 }

/*
updated solution
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the structure for a tree node
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* parent;
} TreeNode;

// Define the structure for the Max Heap
typedef struct MaxHeap {
    TreeNode* root;
    int size;
} MaxHeap;

// Function to create a new Max Heap
MaxHeap* createHeap() {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->root = NULL;
    heap->size = 0;
    return heap;
}

// Function to create a new node
TreeNode* createNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

// Function to insert a key into the Max Heap
void insertKey(MaxHeap* heap, int value) {
    TreeNode* newNode = createNode(value);
    heap->size++;

    // If the heap is empty, set the new node as the root
    if (!heap->root) {
        heap->root = newNode;
        return;
    }

    // Find the insertion point using level-order traversal
    TreeNode* queue[heap->size];
    int front = 0, rear = 0;

    queue[rear++] = heap->root;

    while (front < rear) {
        TreeNode* curr = queue[front++];

        if (!curr->left) {
            curr->left = newNode;
            newNode->parent = curr;
            break;
        } else {
            queue[rear++] = curr->left;
        }

        if (!curr->right) {
            curr->right = newNode;
            newNode->parent = curr;
            break;
        } else {
            queue[rear++] = curr->right;
        }
    }

    // Restore the Max Heap property
    TreeNode* node = newNode;
    while (node->parent && node->value > node->parent->value) {
        int temp = node->value;
        node->value = node->parent->value;
        node->parent->value = temp;
        node = node->parent;
    }
}

// Helper function to find the last node
TreeNode* findLastNode(TreeNode* root, int size) {
    // Perform a level-order traversal to find the last node
    TreeNode* queue[size + 1];
    int front = 0, rear = 0;

    queue[rear++] = root;

    TreeNode* last = NULL;
    while (front < rear) {
        last = queue[front++];
        if (last->left) queue[rear++] = last->left;
        if (last->right) queue[rear++] = last->right;
    }

    return last;
}

// Function to extract the maximum value (root) from the heap
int extractMax(MaxHeap* heap) {
    if (!heap->root) {
        printf("Heap underflow: no elements to extract\n");
        return -1;
    }

    int maxValue = heap->root->value;

    TreeNode* lastNode = findLastNode(heap->root, heap->size);

    if (lastNode == heap->root) {
        free(heap->root);
        heap->root = NULL;
        heap->size--;
        return maxValue;
    }

    // Replace root value with last node value
    heap->root->value = lastNode->value;

    // Remove last node
    if (lastNode->parent->left == lastNode) {
        lastNode->parent->left = NULL;
    } else {
        lastNode->parent->right = NULL;
    }

    free(lastNode);
    heap->size--;

    // Restore the Max Heap property
    TreeNode* node = heap->root;
    while (node->left) {
        TreeNode* largest = node;

        if (node->left && node->left->value > largest->value) {
            largest = node->left;
        }

        if (node->right && node->right->value > largest->value) {
            largest = node->right;
        }

        if (largest != node) {
            int temp = node->value;
            node->value = largest->value;
            largest->value = temp;
            node = largest;
        } else {
            break;
        }
    }

    return maxValue;
}

// Function to return the maximum value without removing it
int getMax(MaxHeap* heap) {
    if (!heap->root) {
        printf("Heap is empty\n");
        return -1;
    }
    return heap->root->value;
}

// Function to print the heap (level-order)
void printHeap(TreeNode* root) {
    if (!root) {
        printf("Heap is empty\n");
        return;
    }

    TreeNode* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        TreeNode* node = queue[front++];

        printf("%d ", node->value);

        if (node->left) queue[rear++] = node->left;
        if (node->right) queue[rear++] = node->right;
    }
    printf("\n");
}

// Function to free the heap memory
void freeHeap(MaxHeap* heap) {
    if (!heap->root) {
        free(heap);
        return;
    }

    TreeNode* queue[heap->size];
    int front = 0, rear = 0;

    queue[rear++] = heap->root;

    while (front < rear) {
        TreeNode* node = queue[front++];

        if (node->left) queue[rear++] = node->left;
        if (node->right) queue[rear++] = node->right;

        free(node);
    }

    free(heap);
}

// Main function for testing
int main() {
    printf("Testing MaxHeap with Tree Nodes...\n");

    MaxHeap* heap = createHeap();

    // Insert keys
    printf("Inserting 10...\n");
    insertKey(heap, 10);
    printHeap(heap->root); // Expected: 10

    printf("Inserting 20...\n");
    insertKey(heap, 20);
    printHeap(heap->root); // Expected: 20, 10

    printf("Inserting 5...\n");
    insertKey(heap, 5);
    printHeap(heap->root); // Expected: 20, 10, 5

    printf("Inserting 15...\n");
    insertKey(heap, 15);
    printHeap(heap->root); // Expected: 20, 15, 5, 10

    printf("Inserting 25...\n");
    insertKey(heap, 25);
    printHeap(heap->root); // Expected: 25, 20, 5, 10, 15

    // Extract max
    printf("\nExtracting max...\n");
    printf("Extracted: %d\n", extractMax(heap)); // Expected: 25
    printHeap(heap->root); // Expected: 20, 15, 5, 10

    freeHeap(heap);
    printf("\nAll tests passed!\n");
    return 0;
}

*/





/*
Solution2
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* parent;
} TreeNode;

// Define the structure for the Max Heap
typedef struct MaxHeap {
    TreeNode* root;   // Pointer to the root node
    int size;         // Current size of the heap
} MaxHeap;

// Function prototypes
MaxHeap* createHeap();
TreeNode* createNode(int value);
void insertKey(MaxHeap* heap, int value);
int extractMax(MaxHeap* heap);
int getMax(MaxHeap* heap);
void heapifyUp(TreeNode* node);
void heapifyDown(TreeNode* node);
void freeHeap(MaxHeap* heap);
void printHeap(TreeNode* root);

// Function to create a new Max Heap
MaxHeap* createHeap() {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    if (!heap) {
        printf("Memory allocation failed for heap\n");
        exit(EXIT_FAILURE);
    }
    heap->root = NULL;
    heap->size = 0;
    return heap;
}

// Function to create a new tree node
TreeNode* createNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (!node) {
        printf("Memory allocation failed for tree node\n");
        exit(EXIT_FAILURE);
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

// Function to insert a key into the Max Heap
void insertKey(MaxHeap* heap, int value) {
    TreeNode* newNode = createNode(value);
    heap->size++;

    // If the heap is empty, set the new node as the root
    if (!heap->root) {
        heap->root = newNode;
        return;
    }

    // Find the insertion point using level-order traversal
    TreeNode** q = (TreeNode**)malloc(heap->size * sizeof(TreeNode*));
    if (!q) {
        printf("Memory allocation failed for queue\n");
        exit(EXIT_FAILURE);
    }
    int front = 0, rear = 0;

    q[rear++] = heap->root;

    while (front < rear) {
        TreeNode* curr = q[front++];
        if (!curr->left) {
            curr->left = newNode;
            newNode->parent = curr;
            break;
        } else if (!curr->right) {
            curr->right = newNode;
            newNode->parent = curr;
            break;
        } else {
            q[rear++] = curr->left;
            q[rear++] = curr->right;
        }
    }
    free(q);

    // Restore the Max Heap property
    heapifyUp(newNode);
}

// Function to restore the Max Heap property upwards
void heapifyUp(TreeNode* node) {
    while (node->parent && node->value > node->parent->value) {
        int temp = node->value;
        node->value = node->parent->value;
        node->parent->value = temp;
        node = node->parent;
    }
}

// Function to find the last node using level-order traversal
TreeNode* findLastNode(TreeNode* root, int size) {
    TreeNode** q = (TreeNode**)malloc(size * sizeof(TreeNode*));
    if (!q) {
        printf("Memory allocation failed for queue\n");
        exit(EXIT_FAILURE);
    }
    int front = 0, rear = 0;

    q[rear++] = root;
    TreeNode* last = NULL;

    while (front < rear) {
        last = q[front++];
        if (last->left) q[rear++] = last->left;
        if (last->right) q[rear++] = last->right;
    }

    free(q);
    return last;
}

// Function to extract the maximum value (root) from the heap
int extractMax(MaxHeap* heap) {
    if (!heap->root) {
        printf("Heap underflow: no elements to extract\n");
        return -1;
    }

    int maxValue = heap->root->value;
    TreeNode* lastNode = findLastNode(heap->root, heap->size);

    if (lastNode == heap->root) {
        free(lastNode);
        heap->root = NULL;
        heap->size--;
        return maxValue;
    }

    heap->root->value = lastNode->value;

    if (lastNode->parent->left == lastNode) {
        lastNode->parent->left = NULL;
    } else {
        lastNode->parent->right = NULL;
    }

    free(lastNode);
    heap->size--;

    // Restore the Max Heap property
    heapifyDown(heap->root);

    return maxValue;
}

// Function to restore the Max Heap property downwards
void heapifyDown(TreeNode* node) {
    while (node->left) {
        TreeNode* largest = node;

        if (node->left && node->left->value > largest->value) {
            largest = node->left;
        }

        if (node->right && node->right->value > largest->value) {
            largest = node->right;
        }

        if (largest != node) {
            int temp = node->value;
            node->value = largest->value;
            largest->value = temp;
            node = largest;
        } else {
            break;
        }
    }
}

// Function to return the maximum value without removing it
int getMax(MaxHeap* heap) {
    if (!heap->root) {
        printf("Heap is empty\n");
        return -1;
    }
    return heap->root->value;
}

// Function to print the heap in level-order
void printHeap(TreeNode* root) {
    if (!root) {
        printf("Heap is empty\n");
        return;
    }

    TreeNode** q = (TreeNode**)malloc(1000 * sizeof(TreeNode*));
    if (!q) {
        printf("Memory allocation failed for queue\n");
        exit(EXIT_FAILURE);
    }
    int front = 0, rear = 0;

    q[rear++] = root;

    printf("[");
    while (front < rear) {
        TreeNode* curr = q[front++];
        printf("%d ", curr->value);

        if (curr->left) q[rear++] = curr->left;
        if (curr->right) q[rear++] = curr->right;
    }
    printf("]\n");

    free(q);
}

// Function to free the heap memory
void freeHeap(MaxHeap* heap) {
    if (!heap->root) {
        free(heap);
        return;
    }

    TreeNode** q = (TreeNode**)malloc(heap->size * sizeof(TreeNode*));
    if (!q) {
        printf("Memory allocation failed for queue\n");
        exit(EXIT_FAILURE);
    }
    int front = 0, rear = 0;

    q[rear++] = heap->root;

    while (front < rear) {
        TreeNode* curr = q[front++];
        if (curr->left) q[rear++] = curr->left;
        if (curr->right) q[rear++] = curr->right;
        free(curr);
    }

    free(q);
    free(heap);
}

// Test cases
void runTestCases() {
    printf("Testing MaxHeap with Tree Nodes...\n");

    MaxHeap* heap = createHeap();

    // Insert keys
    printf("Inserting 10...\n");
    insertKey(heap, 10);
    printHeap(heap->root); // Expected: [10]

    printf("Inserting 20...\n");
    insertKey(heap, 20);
    printHeap(heap->root); // Expected: [20, 10]

    printf("Inserting 5...\n");
    insertKey(heap, 5);
    printHeap(heap->root); // Expected: [20, 10, 5]

    printf("Inserting 15...\n");
    insertKey(heap, 15);
    printHeap(heap->root); // Expected: [20, 15, 5, 10]

    printf("Inserting 25...\n");
    insertKey(heap, 25);
    printHeap(heap->root); // Expected: [25, 20, 5, 10, 15]

    // Extract max
    printf("\nExtracting max...\n");
    printf("Extracted: %d\n", extractMax(heap)); // Expected: 25
    printHeap(heap->root); // Expected: [20, 15, 5, 10]

    // Free the heap
    freeHeap(heap);
    printf("\nAll tests passed!\n");
}

int main() {
    runTestCases();
    return 0;
}
*/