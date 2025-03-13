
/*
  you must write C functions that implement a list of stacks and its interfaces.
  A list of stacks should be composed of multiple stacks that store positive integer values and create a new stack once the previous one exceeds capacity.
  A new stack is added to the end of the list.
  The list of stacks provides two operations, push and pop, and they should behave identically to a single stack. In other words, pop must return the same values as if there were just a single stack.
  Use the following list node data structure in your code.
  You can freely implement the struct Stack data structure as long as it behaves as a stack.
  stack capacity determines the maximum size of the stack. we assume the same capacity for all stacks in the list.

  you can only include <stdio.h> and <stdlib.h>

  given:
    typedef struct ListNode {
      struct ListNode *next;
      struct Stack *stack;
      int stack_capacity;
    } ListNode;

  implement:

    typedef struct Stack {
      //
    } Stack;

    int list_size(ListNode *head) {}
        // returns the number of non-empty stacks in the list

    void push_los(ListNode *head, int val) {}
        // takes a head node of the list and pushes the value into the data structure

    int pop_los(ListNode *head) {}
        // takes a head node of the list and pops a value as if it were a single stack.
        // it the list is empty and no value can be popped, the function must return -9999 to indicate an error status



*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
  int* arr; //malloc 안 해도 되나?
  int size;
} Stack;

typedef struct ListNode {
  struct ListNode *next;
  struct Stack *stack;
  int stack_capacity;
} ListNode;



int list_size(ListNode *head){
  // returns the number of non-empty stacks in the list
  int cnt = 0;
  ListNode* curr = head;
  while(curr){
    if((curr->stack != NULL) && curr->stack->size > 0) cnt++;
    curr = curr->next;
  }
  return cnt;
}
void push_los(ListNode *head, int val){
// takes a head node of the list and pushes the value into the data structure
  ListNode* curr = head;
  // 마지막 node로 이동
  while(curr->next){
    curr = curr->next;
  }
  // Stack이 아직 없는 경우
  if(!curr->stack){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s -> size = 0;
    s -> arr = (int*)malloc(sizeof(int)*(1+curr->stack_capacity)); // 맞는지 모르겄다. 맞네-_-
    s -> arr[s->size++] = val;
    curr->stack = s;
  } // Stack이 현 노드에 있긴하다.
  else{
    // 아직 현 Node stack이 꽉 안 찬 경우
    if(curr->stack->size < curr->stack_capacity){
      curr->stack->arr[curr->stack->size++] = val;
    } // 현 Node stack이 꽉 찼다.
    else{
      ListNode* nxt = (ListNode*)malloc(sizeof(ListNode));
      nxt -> next = NULL;
      nxt -> stack_capacity = curr->stack_capacity;
      Stack* s = (Stack*)malloc(sizeof(Stack));
      s -> arr = (int*)malloc(sizeof(int)*(1+curr->stack_capacity)); // c는 무조건 malloc해줘
      s -> size = 0;
      s -> arr[s->size++] = val;
      curr->next = nxt;
      nxt->stack = s;
    }
  }
}
int pop_los(ListNode *head){
    // takes a head node of the list and pops a value as if it were a single stack.
    // it the list is empty and no value can be popped, the function must return -9999 to indicate an error status
  // 이전 노드를 추적해서 마지막 노드를 제거..
  // 왜냐하면 그냥 내 노드가 NULL이 된다고 이전 노드의 Next가 NULL이 되는 것이 아니다. 반드시 prev->next = NULL; 로 끊어줘야 한다.
  if(!head) return -9999;
  if(!head->stack && !head->next) return -9999;

  ListNode* curr = head;
  ListNode* prev = NULL;
  // 마지막 node로 이동
  while(curr->next){
    prev = curr;
    curr = curr->next;
  }
  // head 하나 있는 Node면 지우진 않고 -9999반환
  if(curr==head){
    if(curr->stack == NULL) return -9999;
    if(curr->stack->size == 0) return -9999;
    else{
        int val = curr->stack->arr[--(curr->stack->size)];
        return val;}
  }
  // pop이 가능하다. 단, 마지막 node pop할 땐 해당 노드 NULL설정 후 free 해주기
  if(curr->stack){
    int val = curr->stack->arr[--(curr->stack->size)];
    if(curr->stack->size == 0){
      // stack 삭제, 해당 curr 삭제
      free(curr->stack->arr);
      curr->stack->arr = NULL;
      free(curr->stack);
      curr->stack = NULL;
      prev->next = NULL; // 이걸 몰랐네 !!!! 이제라도 알아서 다행이다. 반드시 prev -> next = NULL로 끊어줘야 한다.
      free(curr);
      curr = NULL;
    }
    return val;
  }


}

// POP이 안 돼 -_-
int main() {
  ListNode *head = (ListNode *)malloc(sizeof(ListNode));
  head->next = NULL;
  head->stack = NULL; // 내가 추가
  head->stack_capacity = 3;
  printf("pop:%d\n",pop_los(head));
  printf("list size:%d\n", list_size(head)); // 0
  push_los(head,11);
  push_los(head,22);
  push_los(head,33);
  printf("list size:%d\n", list_size(head)); // 1
  push_los(head,44);
  printf("list size:%d\n", list_size(head)); // 2
  printf("pop:%d\n",pop_los(head)); // 4
  printf("list size:%d\n", list_size(head)); // 1
  push_los(head,55);
  push_los(head,66);
  push_los(head,77);
  push_los(head,88);
  printf("list size:%d\n", list_size(head)); // 3
  for(int i=0;i<8;i++){
    printf("pop:%d\n",pop_los(head));
  }

  printf("list size:%d\n", list_size(head)); // 0

}


// GPT 풀이

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Stack {
//     int *arr;  // 동적 배열
//     int size;  // 현재 스택에 쌓인 원소 수
// } Stack;

// typedef struct ListNode {
//     struct ListNode *next;
//     struct Stack *stack;
//     int stack_capacity; // 각 노드가 가진 스택의 최대 용량
// } ListNode;

// /* 
//  * 1) 리스트 내 "비어있지 않은 노드"의 개수(스택 size>0)를 반환 
//  */
// int list_size(ListNode *head) {
//     int count = 0;
//     ListNode* curr = head;
//     while (curr) {
//         if (curr->stack && curr->stack->size > 0) {
//             count++;
//         }
//         curr = curr->next;
//     }
//     return count;
// }

// /* 
//  * 2) push_los
//  *    - 리스트 마지막 노드로 이동
//  *    - 마지막 노드의 스택이 없으면 새 스택 생성
//  *    - 마지막 노드의 스택이 '가득 찼다면' 새 노드를 하나 만들어 뒤에 연결
//  *    - 그 스택에 val 삽입 
//  */
// void push_los(ListNode *head, int val) {
//     if (!head) return;  // head 자체가 NULL이면 함수 종료

//     // (A) 마지막 노드까지 이동
//     ListNode* curr = head;
//     while (curr->next) {
//         curr = curr->next;
//     }

//     // (B) 마지막 노드에 스택이 아직 없다면 생성
//     if (!curr->stack) {
//         Stack* s = (Stack*)malloc(sizeof(Stack));
//         s->size = 0;
//         s->arr = (int*)malloc(sizeof(int) * curr->stack_capacity);
//         curr->stack = s;
//     }

//     // (C) 만약 스택이 가득 차면 새 노드 추가
//     if (curr->stack->size == curr->stack_capacity) {
//         ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
//         newNode->next = NULL;
//         newNode->stack_capacity = curr->stack_capacity;

//         Stack* s = (Stack*)malloc(sizeof(Stack));
//         s->size = 0;
//         s->arr = (int*)malloc(sizeof(int) * newNode->stack_capacity);
//         newNode->stack = s;

//         // 연결
//         curr->next = newNode;
//         curr = newNode; 
//     }

//     // (D) 실제 push: 스택 size 증가 후 값 삽입
//     curr->stack->arr[curr->stack->size++] = val;
// }

// /* 
//  * 3) pop_los
//  *    - 마지막 노드로 이동
//  *    - 스택이 없거나 비어있으면 -9999 반환
//  *    - pop한 뒤 스택이 비면 스택 메모리 해제
//  *      그리고 노드가 여러 개이면(이전 노드가 존재) 마지막 노드 자체도 free
//  *      노드가 1개뿐이라면(즉 prev가 NULL) 노드는 남겨두고 스택만 제거
//  */
// int pop_los(ListNode *head) {
//     if (!head) {
//         return -9999; // 리스트 자체가 없으면 pop 불가
//     }

//     // (A) 마지막 노드로 이동 (prev는 바로 앞 노드)
//     ListNode* curr = head;
//     ListNode* prev = NULL;
//     while (curr->next) {
//         prev = curr;
//         curr = curr->next;
//     }
//     // curr: 마지막 노드
//     // prev: 마지막 노드 직전 노드 (없을 수도 있음)

//     // (B) 마지막 노드 스택이 없거나 비었으면 -9999
//     if (!curr->stack || curr->stack->size == 0) {
//         return -9999;
//     }

//     // (C) pop
//     int val = curr->stack->arr[ --(curr->stack->size) ];

//     // (D) 만약 pop 후 스택이 비었다면, 스택 메모리 해제
//     if (curr->stack->size == 0) {
//         // 스택 내부 메모리 free
//         free(curr->stack->arr);
//         free(curr->stack);
//         curr->stack = NULL;

//         // 노드가 여러 개면(즉 prev가 NULL이 아님) 마지막 노드 자체를 free
//         if (prev) {
//             prev->next = NULL; // prev의 next를 끊고
//             free(curr);
//         } else {
//             // prev == NULL => 노드가 1개뿐인 경우
//             // 노드 자체는 남겨두고(stack만 비워진 상태)
//         }
//     }

//     return val;
// }

// /*
//  * 4) print_los
//  *    - 리스트를 순회하며 각 노드의 스택 내용을 출력
//  */
// void print_los(ListNode *head) {
//     printf("=== List of Stacks ===\n");
//     int idx = 0;
//     ListNode* curr = head;
//     while (curr) {
//         printf("Node %d: ", idx++);
//         if (!curr->stack) {
//             printf("[ no stack ]\n");
//         } else if (curr->stack->size == 0) {
//             printf("[ empty stack ]\n");
//         } else {
//             printf("[");
//             for (int i = 0; i < curr->stack->size; i++) {
//                 printf("%d", curr->stack->arr[i]);
//                 if (i < curr->stack->size - 1) {
//                     printf(", ");
//                 }
//             }
//             printf("]\n");
//         }
//         curr = curr->next;
//     }
//     printf("\n");
// }

// /*
//  * 간단 테스트를 위한 main 함수 예시
//  */
// int main() {
//     // (1) 리스트의 head 노드 생성
//     ListNode* head = (ListNode*)malloc(sizeof(ListNode));
//     head->next = NULL;
//     head->stack = NULL;         // 초기에는 스택 없음
//     head->stack_capacity = 3;   // 각 노드마다 스택 최대 용량 3

//     // 테스트
//     printf("pop: %d\n", pop_los(head)); // 비어 있으므로 -9999
//     printf("list_size: %d\n", list_size(head)); // 0
//     print_los(head);

//     // push
//     push_los(head, 11);
//     push_los(head, 22);
//     push_los(head, 33);
//     printf("list_size: %d\n", list_size(head)); // 1 (노드 하나, 스택 안에 값 3개)
//     print_los(head);

//     // 용량 초과 시 새 노드 생성
//     push_los(head, 44);
//     printf("list_size: %d\n", list_size(head)); // 2 (노드 두개)
//     print_los(head);

//     // pop
//     printf("pop: %d\n", pop_los(head)); // 44 (두 번째 노드에서 pop)
//     printf("list_size: %d\n", list_size(head)); // 다시 1이 될 것(두 번째 노드가 삭제됨)
//     print_los(head);

//     // 더 push
//     push_los(head, 55);
//     push_los(head, 66);
//     push_los(head, 77);
//     push_los(head, 88);
//     printf("list_size: %d\n", list_size(head)); // 3개 노드 (각 용량 3)
//     print_los(head);

//     // 반복 pop
//     for(int i=0; i<8; i++){
//         printf("pop: %d\n", pop_los(head));
//     }
//     print_los(head);
//     printf("list_size: %d\n", list_size(head)); // 0

//     // 필요 시 cleanup (모든 노드 해제) 로직 추가 가능
//     // 여기서는 예시 끝.

//     return 0;
// }

