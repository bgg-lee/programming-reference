/* hash - map 사용 금지, 이건 뭐.. int main 도 안 줌 */
#include <stdio.h>
#include <stdlib.h>
#include "QE_prob2.h" // header file

/*

WRITE YOUR CODE HERE IF NECESSARY.
    
*/

Node* createNode(int key, int value) {// Node 만들기
    /*WRITE YOUR CODE HERE*/
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node -> key = key;
    new_node -> value = value;
    new_node -> prev = NULL;
    new_node -> next = NULL;
    return new_node;
}


LRUCache* lRUCacheCreate(int capacity) {// LRUCache 만들기
    /*WRITE YOUR CODE HERE*/
    LRUCache* new_cache = (LRUCache*)malloc(sizeof(LRUCache));
    new_cache -> capacity = capacity;
    new_cache -> size = 0;
    new_cache -> head = NULL;
    new_cache -> tail = NULL;
    return new_cache;
}


void lRUCacheFree(LRUCache* cache) {// LRUCache free
    /*WRITE YOUR CODE HERE*/
    Node* slow = NULL;
    Node* fast = cache->head;
    while(fast){
        slow = fast;
        fast = fast->next;
        free(slow);
    }
    free(cache);
}

Node* lRUCacheMRU(LRUCache* cache) { // LRUCache 중 MRU(가장 마지막 추가된된 놈) Node 반환
    /*WRITE YOUR CODE HERE*/
    return cache->head;
}


Node* lRUCacheLRU(LRUCache* cache) { // LRUCache 중 LRU(가장 처음 추가된 놈) Node 반환
    /*WRITE YOUR CODE HERE*/
    return cache->tail;
}

int lRUCacheGet(LRUCache* cache, int key) {// LRU에 값 읽고 remove
    /*WRITE YOUR CODE HERE*/
    // cache tail(오래된 놈:LRU)부터 head까지 돌면서 key 값이랑 매칭되는 첫 번째 녀석 pop이 아니고 -> 그놈을 head로 바꿈
    // head까지 돌아도 없으면 -1 반환
    Node* curr = lRUCacheLRU(cache);
    while(curr){
        if(curr->key == key){
            int ans = curr->value;
            if(curr->prev){
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            }
            else{// head가 target(curr) 이었음
                if(curr->next){
                    curr->next->prev = NULL;
                    cache->head = curr->next;
                }else{
                    cache->head = NULL;
                }
            }
            // 타겟을 head로 변경
            curr->prev = NULL;
            curr->next = cache->head;
            cache->head = curr;
            return ans;
        }
        curr = curr->prev;
    }
    // head까지 돌아도 못 찾음
    return -1;
}


void lRUCachePut(LRUCache* cache, int key, int value) {// LRU에 값을 넣다, Replace 시 LRU
    /*WRITE YOUR CODE HERE*/
    Node* new_node = createNode(key, value);

    // 캐시가 가득 찬 경우
    if (cache->capacity == cache->size) {
        Node* old_tail = cache->tail;        // 현재 3을 가리킴
        Node* new_tail = old_tail->prev;     // 2를 가리킴
        
        // 새로운 tail(2) 설정
        cache->tail = new_tail;
        // 이전 tail(3) 삭제
        old_tail->prev = NULL;
        if (cache->tail) {
            cache->tail->next = NULL;
        }
        free(old_tail);
        cache->size--;
    }

    // 새 노드(5)를 head로 삽입
    new_node->next = cache->head;    // 5의 next를 4로
    if (cache->head) {
        cache->head->prev = new_node;  // 4의 prev를 5로
    }
    cache->head = new_node;           // head를 5로
    
    // tail이 설정되지 않은 경우
    if (!cache->tail) {
        cache->tail = new_node;
    }

    cache->size++;
}


void lRUCacheDisplay(LRUCache* cache) {// LRU 내부에 값 print
    /*WRITE YOUR CODE HERE*/
    Node* temp = cache->head;
    int cnt = 0;
    printf("[");
    while(temp && cnt < cache->capacity){
        printf("key:%d & value:%d, ",temp->key,temp->value);
        temp = temp->next;
        cnt++;
    }
    printf("]\n");
}
/* 이 아래는 GPT 돌린 TEST CASE */
void testLRUCache() {
    printf("Running LRU Cache Test Cases...\n");

    // Step 1: Create LRU Cache
    printf("Creating LRU Cache with capacity = 3\n");
    LRUCache* cache = lRUCacheCreate(3);

    // Step 2: Add elements to the cache
    printf("Adding key=1, value=100 to the cache\n");
    lRUCachePut(cache, 1, 100);
    lRUCacheDisplay(cache);

    printf("Adding key=2, value=200 to the cache\n");
    lRUCachePut(cache, 2, 200);
    lRUCacheDisplay(cache);

    printf("Adding key=3, value=300 to the cache\n");
    lRUCachePut(cache, 3, 300);
    lRUCacheDisplay(cache);

    // Step 3: Access an element (make it MRU)
    printf("Accessing key=2 (Expected MRU)\n");
    printf("Value for key=2: %d\n", lRUCacheGet(cache, 2));
    lRUCacheDisplay(cache);

    // Step 4: Add a new element, evicting the LRU
    printf("Adding key=4, value=400 (Should evict key=1, the LRU)\n");
    lRUCachePut(cache, 4, 400);
    lRUCacheDisplay(cache);

    // Step 5: Test LRU and MRU retrieval
    printf("Getting MRU Node...\n");
    Node* mru = lRUCacheMRU(cache);
    if (mru) {
        printf("MRU Node: key=%d, value=%d\n", mru->key, mru->value);
    }

    printf("Getting LRU Node...\n");
    Node* lru = lRUCacheLRU(cache);
    if (lru) {
        printf("LRU Node: key=%d, value=%d\n", lru->key, lru->value);
    }

    // Step 6: Test cache capacity behavior
    printf("Adding key=5, value=500 (Should evict key=3, the LRU)\n");
    lRUCachePut(cache, 5, 500);
    lRUCacheDisplay(cache);

    printf("Accessing key=3 (Should return -1 as it is evicted)\n");
    printf("Value for key=3: %d\n", lRUCacheGet(cache, 3));

    // Step 7: Clean up
    printf("Freeing LRU Cache\n");
    lRUCacheFree(cache);

    printf("All test cases completed.\n");
}

int main() {
    testLRUCache();
    return 0;
}



/*
#include <stdlib.h>
#include <stdio.h>

// Doubly Linked List Node
typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

// LRUCache Structure
typedef struct {
    int capacity;
    int size;
    Node* head; // Most Recently Used (MRU)
    Node* tail; // Least Recently Used (LRU)
} LRUCache;

// Create a new LRUCache
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = NULL;
    cache->tail = NULL;
    return cache;
}

// Get the value of a key in the cache
int lRUCacheGet(LRUCache* cache, int key) {
    Node* current = cache->head;

    // Search for the key
    while (current) {
        if (current->key == key) {
            // Key found: Move this node to the head
            if (current != cache->head) {
                // Detach the node
                if (current->prev) {
                    current->prev->next = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                if (current == cache->tail) {
                    cache->tail = current->prev; // Update tail if needed
                }

                // Move to the head
                current->next = cache->head;
                current->prev = NULL;
                if (cache->head) {
                    cache->head->prev = current;
                }
                cache->head = current;
            }

            return current->value;
        }
        current = current->next;
    }

    return -1; // Key not found
}

// Put a key-value pair into the cache
void lRUCachePut(LRUCache* cache, int key, int value) {
    Node* current = cache->head;

    // Check if the key already exists
    while (current) {
        if (current->key == key) {
            // Key found: Update value and move to the head
            current->value = value;
            lRUCacheGet(cache, key); // Move to the head using existing logic
            return;
        }
        current = current->next;
    }

    // Key does not exist: Create a new node
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->prev = NULL;
    new_node->next = cache->head;

    // Add to the head
    if (cache->head) {
        cache->head->prev = new_node;
    }
    cache->head = new_node;

    // Update tail if cache was empty
    if (!cache->tail) {
        cache->tail = new_node;
    }

    cache->size++;

    // If capacity is exceeded, remove the least recently used node (tail)
    if (cache->size > cache->capacity) {
        Node* old_tail = cache->tail;
        cache->tail = old_tail->prev;
        if (cache->tail) {
            cache->tail->next = NULL;
        }
        free(old_tail);
        cache->size--;
    }
}

// Free the LRU Cache
void lRUCacheFree(LRUCache* cache) {
    Node* current = cache->head;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(cache);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 * lRUCachePut(obj, key, value);
 * lRUCacheFree(obj);
 */
