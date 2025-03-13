// linked list merge sort하는 문제, doulby linked list인갑다.
#include <stdio.h>
#include <stdlib.h>

typedef struct LLNode {
    int val;
    struct LLNode *prv, *nxt;
} LLNode;

void print_linked_list(LLNode *head){
    if(!head) return;
    LLNode* curr = head;
    while(curr){
        printf("%d ",curr->val);
        curr = curr->nxt;
    }
    printf("\n");
}

void swap(LLNode* left, LLNode*right){
    int temp = left->val;
    left->val = right->val;
    right->val = temp;
}

void sort_list(LLNode *head){ // sort는 오름차순
    if(!head || !head->nxt) return;
    LLNode* curr = head->nxt;
    // insertion sort
    while(curr){
        int key = curr->val;
        LLNode* temp = curr->prv; // 뒤로가며 비교용
        while(temp && key < temp->val){
            temp->nxt->val = temp->val;
            temp = temp->prv;
        }
        if(!temp) head->val = key; // 디버깅으로 잡아냄 ㅋㅋ;;
        else temp->nxt->val = key;
        curr = curr->nxt;
    }
}

void sort_each_list(LLNode *head[100], int N){
    for(int i=0;i<N;i++){
        sort_list(head[i]);
    }
}

LLNode* merge_sorted_lists(LLNode *head[100], int N){ // 내림차순
    for(int i=0;i<N-1;i++){
        LLNode* temp = head[i];
        while(temp->nxt){
            temp = temp->nxt;
        }
        temp->nxt = head[i+1];
        head[i+1]->prv = temp;
    }
    LLNode* ans = head[0];
    sort_list(ans);
    // 내림차순으로 바꿔주기
    LLNode* prev = NULL;
    LLNode* curr = ans;
    LLNode* next = ans;
    while(curr){
        next = curr->nxt;
        curr->nxt = prev;
        prev = curr;
        curr = next;
    }
    // 만약에 prv설정도 필요하다면?
    LLNode* temp = prev;
    while(temp->nxt){
        temp->nxt->prv = temp;
        temp = temp->nxt;
    }

    return prev;
}

int main(){
    LLNode *node11 = (LLNode*)malloc(sizeof(LLNode));
    LLNode *node12 = (LLNode*)malloc(sizeof(LLNode));
    LLNode *node13 = (LLNode*)malloc(sizeof(LLNode));
    node11->val = 3, node11->nxt = node12, node11->prv = NULL;
    node12->val = 1, node12->nxt = node13, node12->prv = node11;
    node13->val = 5, node13->nxt = NULL, node13->prv = node12;
    LLNode *list1 = node11;

    LLNode *node21 = (LLNode*)malloc(sizeof(LLNode));
    LLNode *node22 = (LLNode*)malloc(sizeof(LLNode));
    LLNode *node23 = (LLNode*)malloc(sizeof(LLNode));
    LLNode *node24 = (LLNode*)malloc(sizeof(LLNode));
    LLNode *node25 = (LLNode*)malloc(sizeof(LLNode));
    node21->val = 2, node21->nxt = node22, node21->prv = NULL;
    node22->val = 8, node22->nxt = node23, node22->prv = node21;
    node23->val = 6, node23->nxt = node24, node23->prv = node22;
    node24->val = 1, node24->nxt = node25, node24->prv = node23;
    node25->val = 1, node25->nxt = NULL,   node25->prv = node24;
    LLNode *list2 = node21;

    LLNode *node31 = (LLNode*)malloc(sizeof(LLNode));
    LLNode *node32 = (LLNode*)malloc(sizeof(LLNode));
    LLNode *node33 = (LLNode*)malloc(sizeof(LLNode));
    LLNode *node34 = (LLNode*)malloc(sizeof(LLNode));
    node31->val = 7, node31->nxt = node32, node31->prv = NULL;
    node32->val = 2, node32->nxt = node33, node32->prv = node31;
    node33->val = 7, node33->nxt = node34, node33->prv = node32;
    node34->val = 4, node34->nxt = NULL,   node34->prv = node33;
    LLNode *list3 = node31;

    print_linked_list(list1);
    print_linked_list(list2);
    print_linked_list(list3);

    sort_list(list1);
    print_linked_list(list1);

    LLNode *lists[100];
    lists[0] = list1;
    lists[1] = list2;
    lists[2] = list3;
    sort_each_list(lists, 3);
    print_linked_list(list1);
    print_linked_list(list2);
    print_linked_list(list3);

    LLNode *merged = merge_sorted_lists(lists, 3);
    print_linked_list(merged);

    return 0;
}