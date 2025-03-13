#include <stdio.h>
#include<stdlib.h>
typedef struct LinkedNode LinkedNode;
typedef struct SLList SLList;

struct LinkedNode{
    int val;
    LinkedNode *next;
};

struct SLList{
    LinkedNode* first;
    int size;
};

LinkedNode* createNode(int x){
    LinkedNode* newNode;
    newNode = (LinkedNode*)malloc(sizeof(LinkedNode));
    newNode->val = x;
    newNode->next = NULL;
    return newNode;
}

void addFirst(SLList *LL, int x){
    LinkedNode* newNode = createNode(x);
    newNode->next = LL->first;
    LL->first = newNode;
    LL->size +=1;

}

void addLast(SLList *LL, int x){
    LinkedNode* newNode = createNode(x);
    LinkedNode* curr = LL->first;
    
    if (LL->size ==0){addFirst(LL, x);}
    
    else{while (curr->next!=NULL){
        curr = curr->next;
    }
    curr->next = newNode;}
    LL->size +=1;
}

void printSLL(SLList *LL){
    LinkedNode* curr = LL->first;
    while (curr != NULL){
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

int getFirst(SLList *LL){
    return LL->first->val;
}

LinkedNode* merge(SLList *LL1, SLList *LL2){
    SLList mySLL = {createNode(100), 0};
    SLList* newSLL = &mySLL;
    int smallest = 0;
    int val1, val2;
    LinkedNode* curr = newSLL->first;
    LinkedNode* curr1 = LL1->first;
    LinkedNode* curr2 = LL2->first;


    while (curr1 != NULL && curr2 != NULL){
        val1 = curr1->val;
        val2 = curr2->val;
        if (val1 < val2){
            curr->next = curr1;
            printf("curr->val: %d\n", curr->val);
            curr1 = curr1->next;
        }
        else{
            curr->next = curr2;
            printf("curr->val: %d\n", curr->val);
            curr2 = curr2->next;
        }
    curr = curr->next;
    }

    while (curr1 != NULL && curr2 == NULL){
        val1 = curr1->val;
            curr->next = curr1;
            printf("curr->val: %d\n", curr->val);
            curr1 = curr1->next;
            curr = curr->next;  
    }

    while (curr1 == NULL && curr2 != NULL){
        val2 = curr2->val;
            curr->next = curr2;
            printf("curr->val: %d\n", curr->val);
            curr2 = curr2->next;
            curr = curr->next;  
    }
    return newSLL->first->next;
}

int main(void){
    SLList LL1 = {NULL, 0};
    SLList LL2 = {NULL, 0};

    addLast(&LL1, 1);
    addLast(&LL1, 3);
    addLast(&LL1, 5);

    addLast(&LL2, 2);
    addLast(&LL2, 4);
    addLast(&LL2, 6);


    LinkedNode* newNode = merge(&LL1, &LL2);
    while (newNode != NULL){
        printf("%d, ",newNode->val);
        newNode = newNode->next;
    }

}