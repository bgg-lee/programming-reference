#ifndef QE_PROB2_H
#define QE_PROB2_H

/*

DO NOT FIX THIS FILE

*/


typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    int capacity;
    int size;
    Node* head; // MRU -> put/get 시 바뀜
    Node* tail; // LRU
} LRUCache;

Node* createNode(int key, int value);
LRUCache* lRUCacheCreate(int capacity);
void lRUCacheFree(LRUCache* cache);
Node* lRUCacheMRU(LRUCache* cache);
Node* lRUCacheLRU(LRUCache* cache);
int lRUCacheGet(LRUCache* cache, int key);
void lRUCachePut(LRUCache* cache, int key, int value);
void lRUCacheDisplay(LRUCache* cache);

#endif