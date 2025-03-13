#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *array;     // Array to store the heap elements
    int size;       // Current number of elements in the heap
    int capacity;   // Maximum capacity of the heap
} MaxHeap;

// Function prototypes
MaxHeap* createHeap(int capacity){
    MaxHeap* Heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    // Heap 생성 후 초기화 후 반환
    Heap->capacity = capacity;
    Heap->size = 0;
    Heap->array = (int*)malloc(capacity*sizeof(int));
    return Heap;
}
void insertKey(MaxHeap* heap, int key){ // Heaify-up
    if(heap->size >= heap->capacity){
        printf("FULL\n");
        return;
    }
    heap->array[heap->size] = key;
    heapifyUp(heap,heap->size);
    heap->size++;
}
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int extractMax(MaxHeap* heap){ // Heaify-down
    if(heap->size==0) return -1;
    int ans = heap->array[0];
    // 첫 / 마지막 value swap 후 첫 index를 heapifyDown
    swap(&heap->array[0],&heap->array[heap->size-1]);
    heap->array[heap->size-1] = NULL;
    heap->size--;
    heapifyDown(heap,0);

    return ans;
}

int getMax(MaxHeap* heap){  // Clear
    if(heap->size==0) return -1;
    return heap->array[0];
}
void heapifyUp(MaxHeap* heap, int index){
    int parent = (index-1)/2;
    while((index-1)/2 >= 0){
        parent = (index-1)/2;
        if(heap->array[parent] < heap->array[index]){
            // Swap
            int temp = heap->array[index];
            heap->array[index] = heap->array[parent];
            heap->array[parent] = temp;
            index = parent;
        }
        else break;
    }
}
void heapifyDown(MaxHeap* heap, int index){
    int left = 2*index + 1;
    int right = 2*index + 2;
    // Base case
    if(left >= heap->size) return;

    int largest = index;
    if(heap->array[largest] < heap->array[left]){
        largest = left;
    }
    if(right < heap->size && heap->array[largest] < heap->array[right]){
        largest = right;
    }
    if(largest!=index){
        // 값을 바꾸고, right or left 중 큰 index에서 다시 heapifyDown
        swap(&heap->array[largest],&heap->array[index]);
        heapifyDown(heap,largest);
    }
    else return;
}
void printHeap(MaxHeap* heap){ // Clear
    printf("[");
    for(int i=0;i<heap->size;i++){
        printf("%d ",heap->array[i]);
    }
    printf("]\n");
}
void freeHeap(MaxHeap* heap){ // Clear
    free(heap->array);
    free(heap);
}
// Test cases
void runTestCases() {
    printf("Testing MaxHeap...\n");

    MaxHeap* heap = createHeap(10);

    // Insert keys
    printf("Inserting 10...\n");
    insertKey(heap, 10);
    printHeap(heap); // Expected: [10]

    printf("Inserting 20...\n");
    insertKey(heap, 20);
    printHeap(heap); // Expected: [20, 10]

    printf("Inserting 5...\n");
    insertKey(heap, 5);
    printHeap(heap); // Expected: [20, 10, 5]

    printf("Inserting 15...\n");
    insertKey(heap, 15);
    printHeap(heap); // Expected: [20, 15, 5, 10]

    printf("Inserting 25...\n");
    insertKey(heap, 25);
    printHeap(heap); // Expected: [25, 20, 5, 10, 15]

    // Peek max
    printf("\nMax value: %d\n", getMax(heap)); // Expected: 25

    // Extract max
    printf("\nExtracting max...\n");
    printf("Extracted: %d\n", extractMax(heap)); // Expected: 25
    printHeap(heap); // Expected: [20, 15, 5, 10]

    printf("\nExtracting max...\n");
    printf("Extracted: %d\n", extractMax(heap)); // Expected: 20
    printHeap(heap); // Expected: [15, 10, 5]

    printf("\nExtracting max...\n");
    printf("Extracted: %d\n", extractMax(heap)); // Expected: 15
    printHeap(heap); // Expected: [10, 5]

    // Free the heap
    freeHeap(heap);
    printf("\nAll tests passed!\n");
}
int main(){
    runTestCases();
}


/*
Solution
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the MaxHeap structure
typedef struct {
    int *array;     // Array to store the heap elements
    int size;       // Current number of elements in the heap
    int capacity;   // Maximum capacity of the heap
} MaxHeap;

// Function to create a MaxHeap
MaxHeap* createHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->array = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

// Function to insert a key into the MaxHeap
void insertKey(MaxHeap* heap, int key) {
    if (heap->size == heap->capacity) {
        printf("Heap overflow: cannot insert key\n");
        return;
    }

    // Insert the new key at the end
    heap->array[heap->size] = key;
    heap->size++;

    // Restore the heap property
    heapifyUp(heap, heap->size - 1);
}

// Function to extract the maximum value (root) from the heap
int extractMax(MaxHeap* heap) {
    if (heap->size == 0) {
        printf("Heap underflow: no elements to extract\n");
        return INT_MIN;
    }

    // Store the maximum value
    int max = heap->array[0];

    // Replace the root with the last element
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    // Restore the heap property
    heapifyDown(heap, 0);

    return max;
}

// Function to return the maximum value (root) without removing it
int getMax(MaxHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty\n");
        return INT_MIN;
    }
    return heap->array[0];
}

// Function to restore the heap property upwards
void heapifyUp(MaxHeap* heap, int index) {
    int parent = (index - 1) / 2;

    while (index > 0 && heap->array[index] > heap->array[parent]) {
        // Swap the current element with its parent
        int temp = heap->array[index];
        heap->array[index] = heap->array[parent];
        heap->array[parent] = temp;

        // Move up the tree
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Function to restore the heap property downwards
void heapifyDown(MaxHeap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Check if the left child is larger
    if (left < heap->size && heap->array[left] > heap->array[largest]) {
        largest = left;
    }

    // Check if the right child is larger
    if (right < heap->size && heap->array[right] > heap->array[largest]) {
        largest = right;
    }

    // If the largest is not the current node, swap and continue heapifying
    if (largest != index) {
        int temp = heap->array[index];
        heap->array[index] = heap->array[largest];
        heap->array[largest] = temp;

        heapifyDown(heap, largest);
    }
}

// Function to print the heap
void printHeap(MaxHeap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

// Function to free the heap memory
void freeHeap(MaxHeap* heap) {
    free(heap->array);
    free(heap);
}

// Main function to run test cases
int main() {
    runTestCases();
    return 0;
}

// Test cases
void runTestCases() {
    printf("Testing MaxHeap...\n");

    MaxHeap* heap = createHeap(10);

    // Insert keys
    printf("Inserting 10...\n");
    insertKey(heap, 10);
    printHeap(heap); // Expected: [10]

    printf("Inserting 20...\n");
    insertKey(heap, 20);
    printHeap(heap); // Expected: [20, 10]

    printf("Inserting 5...\n");
    insertKey(heap, 5);
    printHeap(heap); // Expected: [20, 10, 5]

    printf("Inserting 15...\n");
    insertKey(heap, 15);
    printHeap(heap); // Expected: [20, 15, 5, 10]

    printf("Inserting 25...\n");
    insertKey(heap, 25);
    printHeap(heap); // Expected: [25, 20, 5, 10, 15]

    // Peek max
    printf("\nMax value: %d\n", getMax(heap)); // Expected: 25

    // Extract max
    printf("\nExtracting max...\n");
    printf("Extracted: %d\n", extractMax(heap)); // Expected: 25
    printHeap(heap); // Expected: [20, 15, 5, 10]

    printf("\nExtracting max...\n");
    printf("Extracted: %d\n", extractMax(heap)); // Expected: 20
    printHeap(heap); // Expected: [15, 10, 5]

    // Free the heap
    freeHeap(heap);
    printf("\nAll tests passed!\n");
}

*/