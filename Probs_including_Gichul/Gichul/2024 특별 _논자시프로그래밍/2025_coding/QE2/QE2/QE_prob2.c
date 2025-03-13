#include <stdio.h>
#include <stdlib.h>
#include "QE_prob2.h" // header file

/*

WRITE YOUR CODE HERE IF NECESSARY.
    
*/

Node* createNode(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->prev = NULL;
    node->next = NULL;
    return node;  
}


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;

    // Create dummy head and tail for the doubly linked list
    cache->head = createNode(0, 0);
    cache->tail = createNode(0, 0);
    cache->head->next = cache->tail;
    cache->tail->prev = cache->head;

    // Allocate space for hash table
    //cache->hash = (Node**)calloc(10001, sizeof(Node*)); // Assume keys are less than 10001
    return cache;
}


void lRUCacheFree(LRUCache* cache) {
    Node* current = cache->head;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(cache);
}

void moveToFront(LRUCache* cache, Node* node) {
    // Remove node from its current position
    node->prev->next = node->next;
    node->next->prev = node->prev;

    // Insert node at the front (right after head)
    node->next = cache->head->next;
    node->prev = cache->head;
    cache->head->next->prev = node;
    cache->head->next = node;
}

Node* removeLRUNode(LRUCache* cache) {
    Node* lru = cache->tail->prev;

    // Remove lru node from the doubly linked list
    lru->prev->next = cache->tail;
    cache->tail->prev = lru->prev;

    return lru;
}

Node* lRUCacheMRU(LRUCache* cache) {
    return cache->head;
}


Node* lRUCacheLRU(LRUCache* cache) {
    return cache->tail;
}


int lRUCacheGet(LRUCache* cache, int key) {
    //Node* node = cache->hash[key];
    if (!node) {
        return -1; // Key not found
    }

    // Move the accessed node to the front
    moveToFront(cache, node);
    return node->value;
}


void lRUCachePut(LRUCache* cache, int key, int value) {
    //Node* node = cache->hash[key];

    if (node) {
        // Key already exists: update value and move to front
        node->value = value;
        moveToFront(cache, node);
    } else {
        // Key does not exist: create a new node
        Node* newNode = createNode(key, value);
        //cache->hash[key] = newNode;

        // Insert new node at the front
        newNode->next = cache->head->next;
        newNode->prev = cache->head;
        cache->head->next->prev = newNode;
        cache->head->next = newNode;

        cache->size++;

        // If cache exceeds capacity, remove the least recently used node
        if (cache->size > cache->capacity) {
            Node* lru = removeLRUNode(cache);
            //cache->hash[lru->key] = NULL; // Remove from hash map
            free(lru); // Free memory
            cache->size--;
        }
    }
}


void lRUCacheDisplay(LRUCache* cache) {
    
    return;
    // while(cache){
    //     cache=cache->next;
    //     return 
    // }
}