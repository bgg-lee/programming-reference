# Given the head (first node) of the linked list, sort the linked list in descending order (val element) and
# return the head of the sorted linked list. To get full credit, your implementation needs to run in O(N logN)
# with O(1) memory space. Do not use the built-in sort method. If needed, build it on your own.

class LinkedNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# def sortingLL(head: LinkedNode) -> LinkedNode:
#     # Your Code
#     # LLST Merge Sort를 쓰라는 말이다. index 기준으로
#     # 일단 그냥 해보기

#     # from heapq import heappop,heappush # 기본 min-heap
#     # test2 = []
#     # temp = head
#     # while temp:
#     #     heappush(test2,(-(temp.val),temp)) # Max heap처럼 쓰기 , 만약 두 번째 element 기준으로 min/max heap하고싶으면 걍 input 순서를 바꿔라. 자체적으로 configure 불가
#     #     temp = temp.next

#     # curr = heappop(test2)[1]
#     # iter = curr
#     # while test2:
#     #     new_node = heappop(test2)[1]
#     #     new_node.next = None # 무한루프 방지용
#     #     iter.next = new_node
#     #     iter = iter.next
#     # return curr


#     # while temp:
#     #     heappush(test,temp.val)
#     #     temp = temp.next
    
#     # dummy = LinkedNode(999)
#     # curr = dummy
#     # while test:
#     #     new_node = LinkedNode(heappop(test))
#     #     curr.next = new_node
#     #     curr = curr.next
#     # return dummy.next

# def sortingLL(head: LinkedNode) -> LinkedNode:
# # # GPT 풀이 time/space complexity 만족
#     if not head or not head.next:
#         return head
#     mid = get_middle(head)           # 중간 노드를 찾음
#     right_head = mid.next
#     mid.next = None                  # 두 리스트로 분할
    
#     left_sorted = sortingLL(head)          # 왼쪽 리스트 정렬
#     right_sorted = sortingLL(right_head)   # 오른쪽 리스트 정렬
    
#     return merge_descending(left_sorted, right_sorted)

# def get_middle(head: LinkedNode) -> LinkedNode:
#     slow, fast = head, head
#     while fast.next and fast.next.next:
#         slow = slow.next
#         fast = fast.next.next
#     return slow

# def merge_descending(l1: LinkedNode, l2: LinkedNode) -> LinkedNode:
#     dummy = LinkedNode(0)
#     curr = dummy
#     # 더 큰 쪽 노드를 먼저 연결 (내림차순)
#     while l1 and l2:
#         if l1.val >= l2.val:
#             curr.next = l1
#             l1 = l1.next
#         else:
#             curr.next = l2
#             l2 = l2.next
#         curr = curr.next
#     # 남은 노드 연결
#     if l1: curr.next = l1
#     if l2: curr.next = l2
#     return dummy.next

def sortingLL(head: LinkedNode) -> LinkedNode:
    #내가 다시 함 풀기
    if not head or not head.next : return head

    mid = find_middle(head)
    right = mid.next
    mid.next = None
    
    right_sort = sortingLL(right)
    left_sort = sortingLL(head)

    return merge(left_sort,right_sort)

    pass
def find_middle(node: LinkedNode) -> LinkedNode:
    slow = node
    fast = node
    while fast.next.next and fast.next: # 주의 짝수길이에서 fast가 None에 빠지면 무한루프 돌 수도.. 그래서 조건을 이렇게 했다.
        slow = slow.next
        fast = fast.next.next
        
    return slow

def merge(node1: LinkedNode, node2: LinkedNode) -> LinkedNode:
    dummy = LinkedNode(999)
    curr = dummy
    while node1 and node2 :
        if node1.val > node2.val:
            curr.next = node1
            node1 = node1.next
        else:
            curr.next = node2
            node2 = node2.next
        curr = curr.next
    
    if node1 : curr.next = node1
    if node2 : curr.next = node2

    return dummy.next

if __name__ == "__main__":
    temp2 = LinkedNode(2)
    temp4 = LinkedNode(4)
    temp1 = LinkedNode(1)
    temp7 = LinkedNode(7)
    temp2.next = temp4
    temp4.next = temp1
    temp1.next = temp7
    test = sortingLL(temp2)
    while test :
        print(test.val,end=" ")
        test = test.next

    # from heapq import heappop,heappush # 1->2->3...->N번째 element 순으로 대소 비교해서 minHeap사용한다.
    # import heapq
    # heap = []
    # heapq.heappush(heap, (1, 4, 'A'))
    # heapq.heappush(heap, (1, 3, 'B'))
    # heapq.heappush(heap, (2, 5, 'C'))
    # heapq.heappush(heap, (1, 3, 'D'))
    # while heap :
    #     print(heapq.heappop(heap),end=" ")
    
