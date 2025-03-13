// doubly linked list LRU문제

#include <stdio.h>
#include <stdlib.h>
#include "QE_prob2.h" // header file

/*
WRITE YOUR CODE HERE IF NECESSARY.  
*/
// LRU cache linked list에 Node가 하나씩 있다..?
// Least Recently Used Cache
Node* createNode(int key, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
} // 완


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* new_lru = (LRUCache*)malloc(sizeof(LRUCache));
    new_lru->capacity = capacity;
    new_lru->size = 0;
    new_lru->head = NULL; // MRU -> put/get 시 바뀜
    new_lru->tail = NULL; // LRU Node
    return new_lru;
}


void lRUCacheFree(LRUCache* cache) {
    // Head Node부터 쭉 삭제
    if(cache->head){
        Node* curr = cache->head;
        while(curr){
            Node* temp = curr->next;
            curr->next = NULL;
            free(curr);
            curr = temp;
        }
    }
    free(cache);
}


Node* lRUCacheMRU(LRUCache* cache) {return cache->head;}


Node* lRUCacheLRU(LRUCache* cache) {return cache->tail;}


int lRUCacheGet(LRUCache* cache, int key) {
    /* Node를 돌며 key가 있으면 해당 value를 반환--> 그리고 그 Node가 Head로(MRU), key 없으면 -1반환*/
    // cache가 비었다.
    if(!cache->head) return -1;

    Node* temp = cache->head;
    while(temp){
        if(temp->key == key){
            int ans = temp->value;
            //해당 key를 MRU로
            if(temp==cache->head) return ans;
            if(temp==cache->tail){
                cache->tail = temp->prev;
                cache->tail->next = NULL;
                temp->prev = NULL;
                temp->next = cache->head;
                cache->head->prev = temp;
                cache->head = temp;
                return ans;
            }
            // temp가 head 도 tail도 아니다.
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->prev = NULL;
            temp->next = cache->head;
            cache->head->prev = temp;
            cache->head = temp;
            return ans;
        }
        temp = temp->next;
    }
    return -1;
}


void lRUCachePut(LRUCache* cache, int key, int value) {
    /* key-value pair를 넣는데 head(MRU)에 넣는다. 
    1. key가 이미 있으면 그 node를 update하고 MRU로
    2. key가 없다면
        2-1. CAPA 체크 후 안 넘으면 MRU로 넣기
        2-2. CAPA 넘으면 LRU제거 후 MRU로 넣기
    */
   Node* new_node = createNode(key,value);
   //Cache가 비었다.
   if(!cache->head){
        cache->head = new_node;
        cache->tail = new_node;
        cache->size++;
        return;
   }
   //Cache가 차 있긴 하다. Update 먼저 시도
   Node* temp = cache->head;
   while(temp){
        if(temp->key == key){
            //Valyue Update
            temp->value = value;
            //MRU update
            if(temp == cache->head){return;} // head update인 경우 처리 완료
            temp->prev->next = temp->next;
            if(temp->next){temp->next->prev = temp->prev;}
            else{cache->tail = temp->prev;} // LRU update
            temp->prev = NULL;
            temp->next = cache->head;
            cache->head->prev = temp;
            cache->head = temp;
            return;
        }
        temp = temp->next;
   }
   // Update가 끝났는데 return이 안 되었으니 insert 해야한다.
   if(cache->size < cache->capacity){
        new_node->next = cache->head;
        cache->head->prev = new_node;
        cache->head = new_node;
        cache->size++;
        return;
   }else{//LRU 삭제 필요
        if(temp==cache->head){
            cache->head->key = key;
            cache->head->value = value;
            return;
        }
        Node* temp = cache->tail->prev;
        cache->tail->prev = NULL;
        free(cache->tail);
        cache->tail = temp;
        temp->next = NULL;
        //LRU삭제완
        new_node->next = cache->head;
        cache->head->prev = new_node;
        cache->head = new_node;
        return;    
   }
}


void lRUCacheDisplay(LRUCache* cache) { // 완
    if(!cache->head){
        printf("EMPTY\n");
        return;
    }else{
        Node* curr = cache->head;
        printf("-------START-------\n");
        while(curr){
            printf("key:%d, value:%d\n",curr->key,curr->value);
            curr = curr->next;
        }
        printf("-------END-------\n");

    }
}
// 아래는 내가 만든 것, 원래 main함수도 없음
int main(){
    LRUCache* test = lRUCacheCreate(5);
    // printf("%p\n",test->head);
    if(!test->head) printf("pass\n");
    printf("%d\n",lRUCacheGet(test,1));
    lRUCachePut(test,1,1);
    printf("%d\n",lRUCacheGet(test,1));
    lRUCachePut(test,2,2);
    lRUCachePut(test,3,3);
    lRUCachePut(test,4,4);
    lRUCachePut(test,5,5);
    lRUCachePut(test,6,6);
    lRUCacheDisplay(test);
    printf("%d\n",lRUCacheGet(test,1));
    printf("%d\n",lRUCacheGet(test,4));
    lRUCacheDisplay(test);
    printf("%d\n",lRUCacheGet(test,2));
    lRUCacheDisplay(test);
    lRUCachePut(test,7,7);
    lRUCacheDisplay(test);

    printf("LRU %d\n",lRUCacheLRU(test)->key);
    printf("MRU %d\n",lRUCacheMRU(test)->key);
    lRUCacheFree(test);

    printf("%d\n",lRUCacheGet(test,4)); // -1


    printf("Test Completed for Q2\n");
}