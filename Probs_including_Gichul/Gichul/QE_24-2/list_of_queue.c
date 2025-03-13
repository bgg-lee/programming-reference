#include <stdio.h>
#include <stdlib.h>

/* ----------- Queue 구조체 ----------- */
typedef struct Queue {
    int *arr;      // 동적 배열(원형 큐)
    int capacity;  // 최대 수용 크기
    int front;     // front 인덱스
    int rear;      // rear 인덱스
    int size;      // 현재 원소 개수
} Queue;

/* ----------- ListNode (연결 리스트의 노드) ----------- */
typedef struct ListNode {
    struct ListNode *next;
    struct Queue *queue;    // 각 노드가 보유한 큐
    int queue_capacity;     // 이 노드에서 사용할 큐 용량(또는 queue안에 저장해도 됨)
} ListNode;

/* 
 * list_size:
 * 연결 리스트를 순회하며, 큐가 존재하고 size>0 인 노드의 수를 센다.
 */
int list_size(ListNode *head) {
    int count = 0;
    ListNode *curr = head;
    while (curr) {
        if (curr->queue && curr->queue->size > 0) {
            count++;
        }
        curr = curr->next;
    }
    return count;
}

/* 
 * enqueue_loq:
 *  - 리스트의 **마지막 노드**로 이동
 *  - 해당 노드의 큐가 없다면 새 큐 생성
 *  - 큐가 꽉 차 있으면 새로운 노드(큐) 생성
 *  - 그 큐에 val 추가 (원형 큐로 구현)
 */
void enqueue_loq(ListNode *head, int val) {
    if (!head) return; // head == NULL 이면 동작 불가

    // (1) 마지막 노드로 이동
    ListNode *curr = head;
    while (curr->next) {
        curr = curr->next;
    }

    // (2) 큐가 아직 없다면 생성
    if (!curr->queue) {
        Queue *q = (Queue*)malloc(sizeof(Queue));
        q->capacity = curr->queue_capacity; 
        q->size = 0;
        q->front = 0;
        q->rear = -1;
        q->arr = (int*)malloc(sizeof(int) * q->capacity);
        curr->queue = q;
    }

    // (3) 큐가 꽉 차 있으면 새 노드 생성
    if (curr->queue->size == curr->queue->capacity) {
        ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->next = NULL;
        newNode->queue_capacity = curr->queue_capacity;

        Queue *q2 = (Queue*)malloc(sizeof(Queue));
        q2->capacity = newNode->queue_capacity;
        q2->size = 0;
        q2->front = 0;
        q2->rear = -1;
        q2->arr = (int*)malloc(sizeof(int)*q2->capacity);

        newNode->queue = q2;
        // 리스트 연결
        curr->next = newNode;
        curr = newNode; // 마지막 노드를 업데이트
    }

    // (4) 실제 enqueue
    Queue *q = curr->queue;
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = val;
    q->size++;
}

/* 
 * dequeue_loq:
 *  - 리스트의 맨 앞(또는 앞에서부터) 노드에 큐가 있고 원소가 있으면 dequeue
 *  - 해당 큐가 비면 노드를 제거할지, 그냥 유지할지는 설계자 자유
 *  - 여기서는 “앞 노드의 큐가 비었다면 그 노드 제거” 예시를 보임.
 */
int dequeue_loq(ListNode *head) {
    if (!head) return -9999; // 빈 리스트

    ListNode *curr = head;
    ListNode *prev = NULL;

    // 큐에 원소가 있는 노드를 찾을 때까지 이동
    while (curr) {
        if (curr->queue && curr->queue->size > 0) {
            // dequeue
            Queue *q = curr->queue;
            int val = q->arr[q->front];
            q->front = (q->front + 1) % q->capacity;
            q->size--;

            // dequeue한 뒤 노드의 큐가 비었다면 제거할지 결정
            if (q->size == 0) {
                // 메모리 정리
                free(q->arr);
                free(q);
                curr->queue = NULL;

                // 노드를 없앨지 여부 결정
                // (여기서는 노드 여러개면 제거, head 하나뿐이면 남김)
                if (prev) {
                    // 연결 끊고 free
                    prev->next = curr->next;
                    free(curr);
                }
                else {
                    // prev==NULL -> head 노드였음
                    // 노드 자체는 그냥 남겨놓되 queue만 없어졌음
                }
            }
            return val;
        }
        // 계속 탐색
        prev = curr;
        curr = curr->next;
    }

    // 모든 노드 큐가 비어있다면 에러
    return -9999;
}

/* 
 * print_loq:
 *  디버깅용 - 전체 리스트를 순회하면서 각 노드 큐 내부 상태를 출력
 */
void print_loq(ListNode *head) {
    printf("\n[ List of Queues ]\n");
    ListNode *curr = head;
    int idx = 0;
    while (curr) {
        printf("Node %d: ", idx);
        if (!curr->queue) {
            printf("(no queue)\n");
        } 
        else {
            Queue *q = curr->queue;
            if (q->size == 0) {
                printf("(empty queue)\n");
            } else {
                // 원형 큐 상태 출력
                printf("front=%d, rear=%d, size=%d, capacity=%d\n", 
                       q->front, q->rear, q->size, q->capacity);
                printf("  Elements: ");
                for (int i = 0; i < q->size; i++) {
                    int pos = (q->front + i) % q->capacity;
                    printf("%d ", q->arr[pos]);
                }
                printf("\n");
            }
        }
        idx++;
        curr = curr->next;
    }
    printf("\n");
}

/* ------------------ Test main ------------------ */
int main() {
    // (1) head 노드 생성
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    head->next = NULL;
    head->queue = NULL;         // 아직 큐는 없음
    head->queue_capacity = 3;   // 각 노드마다 용량 3

    // (2) 테스트
    printf("size = %d\n", list_size(head)); // 0
    print_loq(head);

    // enqueue
    enqueue_loq(head, 10);
    enqueue_loq(head, 20);
    enqueue_loq(head, 30);
    printf("size = %d\n", list_size(head)); // 1
    print_loq(head);

    // 용량 꽉 차면 새 노드 생성
    enqueue_loq(head, 40);
    enqueue_loq(head, 50);
    enqueue_loq(head, 60);
    printf("size = %d\n", list_size(head)); // 2 or 3 (depending on empties)
    print_loq(head);

    // dequeue
    printf("dequeue: %d\n", dequeue_loq(head)); // 10
    printf("size = %d\n", list_size(head));
    print_loq(head);

    // dequeue 여러번
    printf("dequeue: %d\n", dequeue_loq(head)); // 20
    printf("dequeue: %d\n", dequeue_loq(head)); // 30
    print_loq(head);

    // 추가 enqueue
    enqueue_loq(head, 70);
    enqueue_loq(head, 80);
    enqueue_loq(head, 90);
    print_loq(head);

    // dequeue 나머지
    while (1) {
        int val = dequeue_loq(head);
        if (val == -9999) break;
        printf("deq -> %d\n", val);
    }
    print_loq(head);
    printf("size = %d\n", list_size(head)); // 0 (모두 비었을 것)

    // (3) 필요 시 전체 free(노드, 큐) 로직 추가 가능
    //     여기서는 예시로 종료

    return 0;
}
