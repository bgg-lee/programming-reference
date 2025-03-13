class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next


def print_list(head: Node) -> None:
    """
    (1) 연결 리스트 전부 출력
    """
    curr = head
    while curr:
        print(curr.data,end="")
        if curr.next:
            print(",",end="")
        curr = curr.next

def palindrome(head: Node) -> bool:
    """
    (2) 연결 리스트가 팰린드롬인지 판정
    """
    if not head:
        return True
    arr = []
    curr = head
    while curr:
        arr.append(curr.data)
        curr = curr.next
    return arr == arr[::-1]


def substring_pattern(s_head: Node, t_head: Node) -> bool:
    """
    (3) s_head, t_head를 값 배열로 만든 뒤,
        t 배열이 s 배열의 '연속 부분'으로 나타나는지 확인
        (일반적인 substring 논리)
    """
    if not t_head:
        return True

    arr_s = []
    curr_s = s_head
    while curr_s:
        arr_s.append(curr_s.data)
        curr_s = curr_s.next

    arr_t = []
    curr_t = t_head
    while curr_t:
        arr_t.append(curr_t.data)
        curr_t = curr_t.next

    len_s = len(arr_s)
    len_t = len(arr_t)
    if len_t > len_s:
        return False

    for start in range(len_s - len_t + 1):
        match = True
        for i in range(len_t):
            if arr_s[start + i] != arr_t[i]:
                match = False
                break
        if match:
            return True
    return False


def build_sublist(nodes, start, end):
    """
    노드 배열(nodes) 중 인덱스 [start..end]로부터
    원본 순서대로 새로운 연결 리스트를 만든다.
    """
    if start > end:
        return None

    new_head = None
    prev = None
    for idx in range(start, end + 1):
        new_node = Node(nodes[idx].data)
        if new_head is None:
            new_head = new_node # new_head / new_node가 있다;; 구분
            prev = new_node
        else:
            prev.next = new_node
            prev = new_node
    return new_head


def maximal_palindrome(head: Node) -> None:
    """
    (4) 
    - 모든 연속 구간을 뽑아 팰린드롬 검사
    - '값 패턴' 관점에서, 더 긴(또는 같은 길이) 팰린드롬의 배열 안에
      작은 팰린드롬의 배열이 substring이면, 작은 팰린드롬 제거
    - 나머지(= 'Maximal') 전부 출력
    """
    # (A) 연결 리스트를 노드 배열로 저장
    arr = []
    curr = head
    while curr:
        arr.append(curr)
        curr = curr.next
    n = len(arr)
    if n == 0:
        print("[]", end="")
        return

    # (B) 모든 팰린드롬 구간 (start..end) 찾기
    #     저장은 (start, end) 형태 + 그 sub-list 자체
    #     sub-list는 build_sublist(arr, st, en)로 만들 수 있음
    all_pals = []  # [(sub_head, length), ...]
    for st in range(n):
        for en in range(st, n):
            sub_head = build_sublist(arr, st, en)
            if palindrome(sub_head):
                length = en - st + 1
                # (sub_list_head, length)
                all_pals.append((sub_head, length))

    # (C) '더 큰' 팰린드롬이 data pattern 상으로 '더 작은'을 substring으로 포함 시 제거
    #     => for each pair (p1, p2),
    #        if len(p2) >= len(p1) AND substring_pattern(p2, p1)==True => remove p1
    i = 0
    while i < len(all_pals):
        (head1, len1) = all_pals[i]

        contained = False
        for j in range(len(all_pals)):
            if i == j:
                continue
            (head2, len2) = all_pals[j]
            if len2 >= len1:
                # '더 크거나 같은 팰린드롬'
                # 값 패턴으로 substring인지 확인
                if substring_pattern(head2, head1):
                    contained = True
                    break

        if contained:
            all_pals.pop(i)
        else:
            i += 1

    # (D) 남은 팰린드롬들 출력
    #     여러 개 있으면 전부 [ ... ... ] 형태로
    print("[", end="")
    for idx, (sub_head, length) in enumerate(all_pals):
        print("[", end="")
        print_list(sub_head)
        print("]", end="")
        if idx < len(all_pals)-1:
            print(",", end="")
    print("]", end="")

# ---------------------------
# 간단 테스트
if __name__ == "__main__":
    s = [8,1,2,3,3,2,1,0,4,9,1,2,3,3,2,1,9,1]
    head = None
    # 뒤에서부터 연결
    for val in reversed(s):
        head = Node(val, head)

    s2 = [0,5,1,2,6,0,7,3,4,4,5,6,5,4,0,5,0,9]
    head2 = None
    # 뒤에서부터 연결
    for val in reversed(s2):
        head2 = Node(val, head2)
    print("Original list:")
    print_list(head)

    print("\nMaximal palindromes (pattern-based substring removal):")
    maximal_palindrome(head)
    print()
    print("Original list:")
    print_list(head2)

    print("\nMaximal palindromes (pattern-based substring removal):")
    maximal_palindrome(head2)
    print()
