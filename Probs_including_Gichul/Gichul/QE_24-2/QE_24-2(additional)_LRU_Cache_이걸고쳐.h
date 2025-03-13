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
    Node* head;
    Node* tail;
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


/*
class Node:
    def __init__(self,key:int,value:int,prev=None,next=None):
        self.key = key
        self.value = value
        self.prev = prev
        self.next = next
class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.size = 0
        self.head = None
        self.tail = None

    def get(self, key: int) -> int:
        temp = self.head
        while temp:
            if temp.key == key: # update temp node to self.head
                # temp : head
                if not temp.prev:
                    return temp.value
                # temp : tail
                if not temp.next:
                    self.tail = temp.prev
                    self.tail.next = None
                    temp.prev = None
                    temp.next = self.head
                    self.head.prev = temp # fixed 
                    self.head = temp
                    return temp.value
                # temp in the middle of the nodes
                temp.prev.next = temp.next
                temp.next.prev = temp.prev
                temp.prev = None
                temp.next = self.head
                self.head.prev = temp # fixed
                self.head = temp
                return temp.value
            temp = temp.next
        return -1

    def put(self, key: int, value: int) -> None:
        # capa >= 1
        # No head and tail
        new_node = Node(key,value)
        if not self.head :
            self.head = new_node
            self.tail = new_node
            self.size += 1
            return
        # Yes head and tail, try update key first
        temp = self.head
        while temp:
            # Update case
            if temp.key == key:
                temp.value = value
                #fixed -> update the node even if its already exist
                if temp != self.head:
                    if temp == self.tail:
                        self.tail = self.tail.prev
                        self.tail.next = None
                    else:
                        temp.prev.next = temp.next
                        temp.next.prev = temp.prev
                    temp.prev = None
                    temp.next = self.head
                    self.head.prev = temp
                    self.head = temp
                return
            temp = temp.next
        # size < capa case, add new_node -> head
        if self.size < self.capacity:
            new_node.next = self.head
            self.head.prev = new_node
            self.head= new_node
            self.size += 1
            return
        # size == capa case, delete tail and add new_node ->head
        else:
            # add head
            new_node.next = self.head
            self.head.prev = new_node
            self.head= new_node
            # delete tail
            self.tail = self.tail.prev
            self.tail.next = None

            return            

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
*/