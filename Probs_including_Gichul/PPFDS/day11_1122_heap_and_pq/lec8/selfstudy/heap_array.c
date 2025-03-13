#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE]; // Array to store heap elements
    int size;           // Current number of elements in the heap
} MaxHeapArray;

// Function prototypes
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void init_heap(MaxHeapArray* heap);
void insert(MaxHeapArray* heap, int key);
int extract_max(MaxHeapArray* heap);
void heapify(MaxHeapArray* heap, int index);
void print_heap(MaxHeapArray* heap);
// Function definitions (to be implemented)
void init_heap(MaxHeapArray* heap) {
    // TODO: Initialize the heap structure
    heap->size = 0;
}

void insert(MaxHeapArray* heap, int key) {
    // TODO: Add an element to the heap and restore max-heap property
    heap->data[heap->size] = key;
    heap->size++;
    for(int i=heap->size-1;i>=0;i--){
        heapify(heap,i);
    }
}

int extract_max(MaxHeapArray* heap) {
    // TODO: Remove and return the maximum element (root)
    if(heap->size == 0) return -1;
    else{
        int ans = heap->data[0];
        heap->data[0] = heap->data[heap->size-1];
        // heap->data[heap->size-1] = NULL;
        heap->size--;
        heapify(heap,0);
        return ans;
    }
}

void heapify(MaxHeapArray* heap, int index) {
    // TODO: Restore max-heap property from the given index
    int largest = index;
    int left = index*2+1;
    int right = index*2+2;
    int n = heap->size;

    if(left < n && heap->data[left] > heap->data[index]) largest = left;
    if(right < n && heap->data[right] > heap->data[largest]) largest = right;

    if(largest != index){
        swap(&(heap->data[index]),&(heap->data[largest]));
        heapify(heap,largest);
    }
}

void print_heap(MaxHeapArray* heap) {
    // TODO: Print the elements of the heap
    for(int i=0;i<heap->size;i++){
        printf("%d ",heap->data[i]);
    }
    printf("\n");
}

// Main function to test the logic
int main() {
    MaxHeapArray heap;
    init_heap(&heap);

    // Test cases
    insert(&heap, 10);
    insert(&heap, 5);
    insert(&heap, 20);
    insert(&heap, 1);
    insert(&heap, 7);
    insert(&heap, 11);
    insert(&heap, 30);

    printf("Heap after insertions: ");
    print_heap(&heap);

    printf("Extracted Max: %d\n", extract_max(&heap));
    printf("Heap after extraction: ");
    print_heap(&heap);

    return 0;
}