#include <stdio.h>
#include <stdlib.h>

/* Linked list node structure */

struct Node {
    int data;
    struct Node* next;
};

struct Node* mergeTwoLists(struct Node* a, struct Node* b){
    /*Write your code here*/
    struct Node* dummy;
    struct Node* temp = dummy;
    while(a && b){
        if(a->data > b->data){
            temp->next = b;
            b = b->next;
        }else{
            temp->next = a;
            a = a->next;
        }
        temp = temp->next;
    }
    if(a){
        temp->next = a;
    }else{
        temp->next = b;
    }
    return dummy->next;
    ////////////////////////
}

// DO NOT MODIFY BELOW
typedef struct listType{
    struct Node *first;
    int size;
} SLList;
struct Node * createNode(int x);
void addFirst(SLList *LL, int x);

int main(int argc, char* argv[]){
    if (argc < 2) {  
        printf("Usage: ./prob5 <n> <m> <linked_list_A_elements> <linked_list_B_elements>.\n");
        return 0;
    } else if (argc != 3 + atoi(argv[1]) + atoi(argv[2])) {
        printf("Usage: ./prob5 <n> <m> <linked_list_A_elements> <linked_list_B_elements>.\n");
        return 0;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    SLList list_a = {NULL, 0};
    SLList list_b = {NULL, 0};

    for(int i = 0; i < n; i++)
        addFirst(&list_a, atoi(argv[2+n-i]));

    for(int i = 0; i < m; i++)
        addFirst(&list_b, atoi(argv[(argc-1)-i]));
        

    struct Node *c;
    c =  mergeTwoLists(list_a.first, list_b.first);
    // print merged lists
    while (c){
        printf("%d ", c ->data);
        c = c->next;
    }
    printf("\n");
}

struct Node * createNode(int x){
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = x;
    newNode -> next = NULL;
    return newNode;
}

void addFirst(SLList *LL, int x){
    struct Node *newFirst;
    newFirst = createNode(x);
    newFirst -> next = LL -> first;
    LL -> first = newFirst;
    LL -> size++;
}