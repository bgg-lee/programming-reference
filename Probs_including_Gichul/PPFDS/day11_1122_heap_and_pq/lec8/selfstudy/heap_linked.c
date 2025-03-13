// C - Minheap

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;

typedef struct {
    Node* head; // Points to the head of the list
} MaxHeapLinkedList;

// Initialize the heap
void init_heap(MaxHeapLinkedList* heap) {
    heap->head = NULL;
}

// Print the heap elements
void print_heap(MaxHeapLinkedList* heap) {
    Node* current = heap->head;
    while (current) {
        printf("%d -> ", current->key);
        current = current->next;
    }
    printf("NULL\n");
}

// Function definitions (to be implemented)
void insert(MaxHeapLinkedList* heap, int key) {
    // TODO: Add an element to the linked list while maintaining min-heap property
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node -> key = key;
    new_node -> next = NULL;

    if(!heap->head || heap->head->key > new_node -> key){
        new_node -> next = heap->head;
        heap->head = new_node;
    }else{
        Node* temp = heap->head;
        while(temp->next && temp->next->key < new_node->key){
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }

}

int extract_min(MaxHeapLinkedList* heap) {
    // TODO: Remove and return the maximum element
    if(!heap->head){
        printf("ERROR\n");
        return -1;
    }
    else{
        int ans = heap->head->key;
        Node* temp = heap->head;
        heap->head = heap->head->next;
        free(temp);
        return ans;
    }
}
// Main function to test the logic
int main() {
    MaxHeapLinkedList heap;
    init_heap(&heap);

    // Test cases
    insert(&heap, 10);
    insert(&heap, 5);
    insert(&heap, 20);
    insert(&heap, 7);
    insert(&heap, 11);
    insert(&heap, 999);
    insert(&heap, 1);

    printf("Heap after insertions: ");
    print_heap(&heap);

    printf("Extracted Min: %d\n", extract_min(&heap));
    printf("Heap after extraction: ");
    print_heap(&heap);

    printf("Extracted Min: %d\n", extract_min(&heap));
    printf("Heap after extraction: ");
    print_heap(&heap);

    insert(&heap, 0);
    insert(&heap, 3);
    printf("Heap after insertions: ");
    print_heap(&heap);

    return 0;
}
