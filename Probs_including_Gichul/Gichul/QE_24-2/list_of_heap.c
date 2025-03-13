// List of heaps -로 max-heap을 구현한 것.. 근데 솔직히 쓰일라나 싶다 이게;; 다소 비효율적이라..
#include <stdio.h>
#include <stdlib.h>

/* ------------ Heap 구조 (max-heap) ------------ */
typedef struct Heap {
    int *arr;      // 힙 배열
    int capacity;  // 최대 원소 수
    int size;      // 현재 원소 수
} Heap;

/* ------------ ListNode: 연결 리스트 노드 ------------ */
typedef struct ListNode {
    struct ListNode *next;
    struct Heap *heap;  
    int heap_capacity;  // 새로 생성되는 힙에 적용할 용량
} ListNode;

/* 
 * list_size: 
 *  - 연결 리스트를 순회, heap->size > 0 인 노드의 개수를 센다.
 */
int list_size(ListNode *head) {
    int count = 0;
    ListNode *curr = head;
    while (curr) {
        if (curr->heap && curr->heap->size > 0) {
            count++;
        }
        curr = curr->next;
    }
    return count;
}

/* 
 * 내부 함수: 힙 삽입 시 상향식 재정렬 (sift-up).
 *  - 힙의 마지막 인덱스 i에 원소가 있을 때, 
 *    부모와 비교해 더 크면 swap, i를 부모로 올려줌 
 */
void heap_sift_up(Heap *h, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (h->arr[parent] < h->arr[idx]) {
            // swap
            int temp = h->arr[parent];
            h->arr[parent] = h->arr[idx];
            h->arr[idx] = temp;
            idx = parent;
        } else {
            break;
        }
    }
}

/* 
 * 내부 함수: 힙에서 최대 원소 제거(pop) 시 하향식 재정렬 (sift-down).
 *   - 루트에 맨 끝 원소를 가져온 뒤, 자식과 비교해 더 작은 쪽과 swap, 계속 진행
 */
void heap_sift_down(Heap *h, int idx) {
    while (1) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int largest = idx;

        // 왼쪽 자식
        if (left < h->size && h->arr[left] > h->arr[largest]) {
            largest = left;
        }
        // 오른쪽 자식
        if (right < h->size && h->arr[right] > h->arr[largest]) {
            largest = right;
        }
        if (largest == idx) {
            break;  // 더 이상 내려가지 않음
        }
        // swap
        int temp = h->arr[idx];
        h->arr[idx] = h->arr[largest];
        h->arr[largest] = temp;

        idx = largest;
    }
}

/* 
 * insert_loh:
 *   - 리스트의 **마지막 노드**로 이동
 *   - 해당 노드의 힙이 없으면 생성
 *   - 꽉 찼으면 새 노드(새 힙) 생성
 *   - 힙에 원소 삽입 후 상향식 재정렬
 */
void insert_loh(ListNode *head, int value) {
    if (!head) return;

    // (1) 마지막 노드로 이동
    ListNode *curr = head;
    while (curr->next) {
        curr = curr->next;
    }

    // (2) 힙이 없다면 생성
    if (!curr->heap) {
        Heap *h = (Heap*)malloc(sizeof(Heap));
        h->size = 0;
        h->capacity = curr->heap_capacity;
        h->arr = (int*)malloc(sizeof(int)*h->capacity);
        curr->heap = h;
    }

    // (3) 힙이 꽉 차면 새 노드 생성
    if (curr->heap->size == curr->heap->capacity) {
        ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->next = NULL;
        newNode->heap_capacity = curr->heap_capacity;

        Heap *h2 = (Heap*)malloc(sizeof(Heap));
        h2->size = 0;
        h2->capacity = newNode->heap_capacity;
        h2->arr = (int*)malloc(sizeof(int)*h2->capacity);

        newNode->heap = h2;
        // 연결
        curr->next = newNode;
        curr = newNode;
    }

    // (4) 실제 힙에 삽입
    Heap *h = curr->heap;
    int i = h->size;
    h->arr[i] = value;
    h->size++;

    // (5) 상향식 재정렬
    heap_sift_up(h, i);
}

/* 
 * remove_max_loh:
 *   - 연결 리스트의 모든 노드를 탐색해 "가장 큰 root"를 가진 힙을 찾음
 *   - 거기서 루트를 제거(pop), 힙 내에서 재정렬
 *   - 만약 모든 노드가 비어있다면 -9999 반환
 */
int remove_max_loh(ListNode *head) {
    if (!head) return -9999;

    ListNode *maxNode = NULL;
    int maxVal = -9999;

    // (1) 모든 노드를 순회하며 최대 root 탐색
    ListNode *curr = head;
    while (curr) {
        if (curr->heap && curr->heap->size > 0) {
            int rootVal = curr->heap->arr[0];
            if (rootVal > maxVal) {
                maxVal = rootVal;
                maxNode = curr;
            }
        }
        curr = curr->next;
    }

    if (!maxNode) {
        // 모든 힙이 비어있음
        return -9999;
    }

    // (2) maxNode의 힙에서 pop
    Heap *h = maxNode->heap;
    int result = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    // sift-down
    heap_sift_down(h, 0);

    // (3) 힙이 비면( size=0 ) 노드를 제거할지 말지는 설계자 자유
    //     여기선 그냥 노드는 남겨두되(=히프만 size=0),
    //     필요 시, free(h->arr)/free(h) 하거나 노드 제거 가능.

    return result;
}

/*
 * print_loh:
 *   - 전체 노드를 순회하면서 힙의 root 및 요소들을 출력 (디버그용)
 */
void print_loh(ListNode *head) {
    printf("\n[ List of Heaps ]\n");
    int idx = 0;
    ListNode *curr = head;
    while (curr) {
        printf("Node %d: ", idx);
        if (!curr->heap) {
            printf("(no heap)\n");
        } else {
            Heap *h = curr->heap;
            if (h->size == 0) {
                printf("(empty heap)\n");
            } else {
                printf("size=%d, capacity=%d, root=%d\n", 
                       h->size, h->capacity, h->arr[0]);
                printf("  Elements: ");
                for (int i = 0; i < h->size; i++) {
                    printf("%d ", h->arr[i]);
                }
                printf("\n");
            }
        }
        curr = curr->next;
        idx++;
    }
    printf("\n");
}

/* ------------------ test main ------------------ */
int main(){
    // (1) head 노드 생성
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    head->next = NULL;
    head->heap = NULL;  // 아직 힙 없음
    head->heap_capacity = 3; // 각 노드 힙 용량 3

    printf("list_size: %d\n", list_size(head)); // 0
    print_loh(head);

    // (2) insert 몇 개
    insert_loh(head, 10);
    insert_loh(head, 5);
    insert_loh(head, 20); // 20이 root로 올라갈 것
    print_loh(head);
    printf("list_size: %d\n", list_size(head)); // 1

    // 용량 초과 시 새로운 노드 생성
    insert_loh(head, 15);
    insert_loh(head, 30);
    insert_loh(head, 40);
    print_loh(head);
    printf("list_size: %d\n", list_size(head)); // 2 (노드 2개, 각각은 비어있지 않음)

    // (3) remove_max_loh
    int val = remove_max_loh(head);
    printf("removed max: %d\n", val); 
    print_loh(head);

    val = remove_max_loh(head);
    printf("removed max: %d\n", val); 
    print_loh(head);

    // (4) 더 삽입
    insert_loh(head, 100);
    insert_loh(head, 1);
    insert_loh(head, 99);
    print_loh(head);

    // (5) 여러번 remove
    while (1) {
        val = remove_max_loh(head);
        if (val == -9999) break;
        printf("remove max -> %d\n", val);
    }
    print_loh(head);

    // (6) 최종 list_size
    printf("list_size: %d\n", list_size(head)); // 비어있으면 0

    // 필요 시 모든 노드/힙 free 로직 추가 가능
    // 여기서는 예시 마무리
    return 0;
}
