"""
1. binary tree height 구하기
2. binary tree balanced 여부
3. binary search tree 여부
4. 두 노드의 common ancestor 모두 구하기
5. 두 노드의 lowest common ancestor 구하기
"""
class TNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def height(T: TNode) -> int:
    # Edge case 생각하기
    if not T : return 0
    from collections import deque
    q = deque([T])
    ans = -1
    while q:
        n = len(q)
        for i in range(n):
            curr = q.popleft()
            if curr.left:
                q.append(curr.left)
            if curr.right:
                q.append(curr.right)
        ans+=1
    return ans
# def height(T: TNode) -> int:
#     if not T:
#         return -1
#     return 1 + max(height(T.left), height(T.right))

def is_balanced(T: TNode) -> bool:
    from collections import deque
    q = deque([T])
    while q:
        n = len(q)
        for i in range(n):
            curr = q.popleft()
            cnt_left,cnt_right = 0,0
            if curr.left:
                q.append(curr.left)
                cnt_left = height(curr.left)
            if curr.right:
                q.append(curr.right)
                cnt_right = height(curr.right)
            if abs(cnt_left - cnt_right) > 1:
                return False
    return True

# def is_balanced(T: TNode) -> bool:
#     def check_balance(node):
#         if not node:
#             return 0, True
#         left_height, is_left_balanced = check_balance(node.left)
#         right_height, is_right_balanced = check_balance(node.right)
        
#         balanced = abs(left_height - right_height) <= 1 and is_left_balanced and is_right_balanced
#         return 1 + max(left_height, right_height), balanced
    
#     _, result = check_balance(T)
#     return result


def is_bst(T: TNode) -> bool:
    if not T : return True

    from collections import deque
    s = deque([T])
    while s :
        n = len(s)
        curr = s.pop()
        if curr.left:
            s.append(curr.left)
            if curr.left.val > curr.val:
                return False
        if curr.right:
            s.append(curr.right)
            if curr.right.val < curr.val:
                return False
    return True

# def is_bst(T: TNode) -> bool:
#     def validate(node, low=float('-inf'), high=float('inf')):
#         if not node:
#             return True
#         if not (low < node.val < high):
#             return False
#         return validate(node.left, low, node.val) and validate(node.right, node.val, high)
    
#     return validate(T)

# 쪼매 어려운 파트
def common_ancestors(T: TNode, U: TNode, V: TNode) -> list[int]:
    # Node Class를 건들 수가 없다면, dict를 이용해 Node별 parent를 쭉 저장해야 할듯
    # 그리고 Node U, V 사이에 겹쳐지는 parent 구해서 반환
    ans = []
    dic = {T : []} # -> 그냥 dic = {} 해도 무방
    from collections import deque
    q = deque([T])

    while q:
        curr = q.pop()
        if curr.left :
            dic[curr.left] = dic[curr] + [curr]
            q.append(curr.left)
        if curr.right :
            dic[curr.right] = dic[curr] + [curr]
            q.append(curr.right)

    s1 = set()
    s2 = set()
    for x in dic[U]:
        s1.add(x.val)
    for x in dic[V]:
        s2.add(x.val) 
    s3 = s1.intersection(s2)

    return list(s3)

# 쪼매 어려운 파트
def lca(T: TNode, U: TNode, V: TNode) -> int:
    # 위에 코드를 참조해서 각 Node 별로 parent를 순서대로(new update를 index 0으로) 추가한다음 마지막에 각자 자신을 index 0에다가 insert하고 서로의 ancestor list를 비교해가며 가장 낮은 index 공통분모를 찾는다.
    # Node Class를 건들 수가 없다면, dict를 이용해 Node별 parent를 쭉 저장해야 할듯
    # 그리고 Node U, V 사이에 겹쳐지는 parent 구해서 반환
    ans = []
    dic = {T.val : []}
    from collections import deque
    q = deque([T])

    while q:
        curr = q.pop()
        if curr.left :
            dic[curr.left.val] = [curr.val] + dic[curr.val]
            q.append(curr.left)
        if curr.right :
            dic[curr.right.val] = [curr.val] + dic[curr.val]
            q.append(curr.right)
    lst1 = [U.val] + dic[U.val]
    lst2 = [V.val] + dic[V.val]

    for x in lst1:
        for y in lst2:
            if x==y : return x

# Test Case
if __name__ == "__main__":
    T7, T8, T9 = TNode(4), TNode(9), TNode(13)
    T3, T4 = TNode(1), TNode(6, T7, None)
    T5, T6 = TNode(11, T8, T9), TNode(20)
    T1, T2 = TNode(3, T3, T4), TNode(15, T5, T6)
    T0 = TNode(8, T1, T2)

    # print(height(T0)) # 3
    # print(height(None)) # 3
    # print(height(T8)) # 0
    # print(height(T1)) # 2

    T15=TNode(5)    
    T11=TNode(1,T15,None)
    T12=TNode(2,T11,None)
    T14=TNode(3)
    T13=TNode(4,T12,T14)
    print(is_balanced(T0)) # True
    print(is_balanced(T13)) # False
    print(is_balanced(T9)) # True

    # T15=TNode(77)    
    # T11=TNode(1,T15,None)
    # T12=TNode(3,T11,None)
    # T14=TNode(6)
    # T13=TNode(5,T12,T14)
    # print(is_bst(T0)) # True
    # print(is_bst(T13)) # False

    # print(common_ancestors(T0, T4, T7)) # [3,8]
    # print(common_ancestors(T0, T6, T9)) # [15,8]
    # print(common_ancestors(T0, T1, T1)) # [8]
    # print(common_ancestors(T0, T1, T3)) # [8]


    # print(lca(T0, T4, T7)) # 6
    # print(lca(T0, T2, T1)) # 8
    # print(lca(T0, T9, T2)) # 15
