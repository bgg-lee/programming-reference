
'''
implement a python program that checks various properties of a given binary tree.
A binary tree is a tree data structure in which each node has at most two children nodes.
Use the following node definition in your code. you can add additional members in the TNode definition.
you do not have to assume invalid calls. (None is not given as an argument)

given:
    class TNode:
        def __init__(self, val=0, left=None, right=None):
            self.val = val
            self.left = left
            self.right = right

implement:
    def height(T: TNode) -> int:
        # takes a root node of a binary tree as input and returns the height of the binary tree.
        # if only have root -> height is 0
        

    def is_balanced(T: TNode) -> bool:
        # takes a root node of a binary tree as input and returns True if the tree is balanced or False otherwise.
        # A binary tree is balanced if the difference in heights between the left and right subtrees of each node is at most 1.

    def is_bst(T: TNode) -> bool:
        # takes a root node of a binary tree as input and returns True if a binary tree satisfies the BST property

    def common_ancestors(T: TNode, U: TNode, V: TNode) -> list[int]: -> value를 list에 담는구먼
        # takes a root node and two nodes of a binary tree as input and returns the value of all the common ancestors
        # oneself is one of the ancestors

    def lca(T: TNode, U: TNode, V: TNode) -> int:
        # takes a root node and two nodes of a binary tree as input and returns the lowest one among all the common ancestors
        # lowest one is the one that farthest from the root
        
'''


from collections import deque


class TNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        self.parent = None # 내가 추가

from collections import deque

def height(T: TNode) -> int:
    # edge case, root가 없거나 root만 있는 경우
    if not T or (not T.left and not T.right) : return 0
    
    ans = 0
    q = deque([T])
    while q:
        lv = len(q)
        for i in range(lv):
            curr = q.popleft()
            if curr.left : q.append(curr.left)
            if curr.right : q.append(curr.right)
        # 다음 lv에 무언가 있다면 lv 증가
        if q:
            ans+=1

    return ans
        
def is_balanced(T: TNode) -> bool:
    # 위 height을 이용하면 될듯. node 별 height 차이가 1 넘게 나면 false
    # edge case, root가 없거나 root만 있는 경우
    if not T or (not T.left and not T.right) : return True

    q = deque([T])
    while q:
        lv = len(q)
        for i in range(lv):
            curr = q.popleft()
            if curr.left : q.append(curr.left)
            if curr.right : q.append(curr.right)
            if abs(height(curr.left) - height(curr.right)) >= 2 :
                return False
    return True


# 완전하지가 않은듯.. 좌,우 모든 sub tree에 있는 것들의 값이 나보다 작아야 하는데
# 현 node 기준 딱 left/right만 따지는 중
##### 현 node 기준 딱 left/right만 따지고, 왼/오 서브를 BFT하며 모든 node가 나보다 큰/작은지 check 하는 걸 추가해야할듯
def is_bst(T: TNode) -> bool:
    # 이것도 그냥 BFT 돌면서 left,right 크기 check
    # edge case, root가 없거나 root만 있는 경우
    if not T or (not T.left and not T.right) : return True

    q = deque([T])
    while q:
        lv = len(q)
        for i in range(lv):
            curr = q.popleft()
            if curr.left:
                q.append(curr.left)
                if curr.left.val > curr.val : return False
            if curr.right :
                q.append(curr.right)
                if curr.right.val < curr.val : return False            
    return True
"""
GPT 해결책..
A. 범위 제한( min/max bound )을 재귀로 전달
def is_bst(T: TNode) -> bool:
    def check(node, min_val, max_val):
        if node is None:
            return True
        # 현재 노드가 허용 범위를 벗어나면 False
        if not (min_val < node.val < max_val):
            return False
        # 왼쪽 서브트리는 (min_val, node.val)
        # 오른쪽 서브트리는 (node.val, max_val)
        return (check(node.left, min_val, node.val) and
                check(node.right, node.val, max_val))

    return check(T, float('-inf'), float('inf'))

B. 중위 순회(in-order traversal) 결과가 ‘오름차순 정렬’인지 확인
BST의 성질상, in-order로 순회하면 오름차순으로 노드값이 나열되어야 합니다.

따라서 중위 순회 리스트를 만든 뒤, 그 결과가 strictly ascending(또는 non-descending)인지 확인합니다.

def is_bst(T: TNode) -> bool:
    arr = []
    
    def inorder(node):
        if not node:
            return
        inorder(node.left)
        arr.append(node.val)
        inorder(node.right)
    
    inorder(T)
    
    # 이제 arr가 오름차순인지 확인
    for i in range(1, len(arr)):
        if arr[i-1] >= arr[i]:  # (중복 허용 여부에 따라 조건 조정)
            return False
    return True

"""


def common_ancestors(T: TNode, U: TNode, V: TNode) -> list[int]:
    # 생각이 필요, space를 써야 할 거 같은데.. DFT preorder?
    # root 에서 leaf까지 가는 모든 node path들을 저장하다가 target이 나온 것만 catch
    # parent를 만들까?
    if not T.left and not T.right : return [T.val]
    # parent 입히기
    q = deque([T])
    while q:
        lv = len(q)
        for i in range(lv):
            curr = q.popleft()
            if curr.left :
                curr.left.parent = curr
                q.append(curr.left)
            if curr.right :
                curr.right.parent = curr
                q.append(curr.right)
    # U,V기준으로 parent 따오기
    lst1 = []
    lst2 = []
    while U.parent:
        lst1.insert(0,U.val)
        U = U.parent
    while V.parent:
        lst2.insert(0,V.val)
        V = V.parent
    # root 값까지 업뎃
    lst1.insert(0,T.val)
    lst2.insert(0,T.val)

    ans = []
    i, j = 0, 0
    while i < len(lst1) and j < len(lst2):
        if lst1[i] == lst2[j]:
            ans.append(lst1[i])
        else: break
        i+=1
        j+=1
    
    return ans


def lca(T: TNode, U: TNode, V: TNode) -> int:
    # 위 common_ancestor만 되면 될듯
    return common_ancestors(T,U,V)[-1]

if __name__ == "__main__":
    T7, T8, T9 = TNode(4), TNode(9), TNode(13)
    T3, T4 = TNode(1), TNode(6, T7, None)
    T5, T6 = TNode(11, T8, T9), TNode(20)
    T1, T2 = TNode(3, T3, T4), TNode(15, T5, T6)
    T0 = TNode(8, T1, T2)

    print(height(T0)) # 3
    print(is_bst(T0)) # False
    print(is_balanced(T0)) # True

    T7, T8, T9 = TNode(7), TNode(5), TNode(9)
    T3, T4 = TNode(1), TNode(4, T7, None)
    T5, T6 = TNode(20, T8, T9), TNode(6)
    T1, T2 = TNode(3, T3, T4), TNode(15, T5, T6)
    T0 = TNode(8, T1, T2)

    print(is_bst(T0))
    print(common_ancestors(T0, T6, T8))
    print(common_ancestors(T0, T1, T7))
    print(lca(T0, T1, T7))


# """
# GPT 풀이.. 깔쌈하다.. height 구하는 부분은

# class TNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


# def height(root: TNode) -> int:
#     """
#     문제 요구사항:
#      - '루트만 있는 경우'의 높이는 0으로 정의
#      - 일반적으로 노드가 없으면 -1로 간주
#        => leaf 노드 높이 = 0, 내부 노드는 max(왼,오) + 1
#     """
#     if root is None:
#         # 빈 트리(혹은 자식 없음)는 -1을 반환
#         # => 상위에서 +1 하면 leaf는 0이 됨
#         return -1
#     return 1 + max(height(root.left), height(root.right))


# def is_balanced(root: TNode) -> bool:
#     """
#     어떤 노드든, 왼쪽 서브트리와 오른쪽 서브트리의 높이 차가 1 이내이면 balanced.
#     모든 노드에 대해 이를 만족해야 True.
#     """

#     # 재귀 도중에 높이를 반환하면서, 만약 불균형(-2 같은 약속값)을 만나면 전달
#     def check_balance(node: TNode) -> int:
#         if node is None:
#             return -1  # 높이 = -1 (leaf에서 +1되어 0)

#         left_h = check_balance(node.left)
#         if left_h == float('inf'):  # 이미 불균형 신호
#             return float('inf')

#         right_h = check_balance(node.right)
#         if right_h == float('inf'):
#             return float('inf')

#         if abs(left_h - right_h) > 1:
#             # 불균형 신호로 특별한 값(float('inf')) 반환
#             return float('inf')

#         return 1 + max(left_h, right_h)

#     return (check_balance(root) != float('inf'))


# def is_bst(root: TNode) -> bool:
#     """
#     BST 검증: (min_val, max_val) 범위를 재귀로 전달.
#     """
#     def valid_bst(node, low, high):
#         if node is None:
#             return True
#         if not (low < node.val < high):
#             return False
#         return (valid_bst(node.left, low, node.val) and
#                 valid_bst(node.right, node.val, high))

#     return valid_bst(root, float('-inf'), float('inf'))


# def common_ancestors(root: TNode, U: TNode, V: TNode) -> list[int]:
#     """
#     root~U 경로와 root~V 경로를 각각 찾은 뒤,
#     공통 prefix 부분의 노드값을 리스트로 반환.
#     (자기 자신도 조상에 포함)
#     """

#     # (A) root에서 특정 target까지의 경로를 찾아 리스트로 반환
#     def path_from_root(node: TNode, target: TNode, path: list) -> bool:
#         """ DFS로 루트~target 경로를 path에 저장.
#             찾으면 True, 못 찾으면 False.
#         """
#         if node is None:
#             return False
#         path.append(node)  # 현재 노드를 경로에 추가

#         if node == target:
#             return True

#         # 왼쪽 혹은 오른쪽에서 target을 찾으면 경로 확정
#         if (path_from_root(node.left, target, path) or
#             path_from_root(node.right, target, path)):
#             return True

#         # 둘 다 못 찾으면 경로에서 빼고 False
#         path.pop()
#         return False

#     path_u = []
#     path_v = []
#     path_from_root(root, U, path_u)
#     path_from_root(root, V, path_v)

#     # (B) 두 경로를 앞에서부터 비교, 공통으로 같은 노드만 ans에 담는다
#     ans = []
#     i = 0
#     while i < len(path_u) and i < len(path_v) and path_u[i] == path_v[i]:
#         ans.append(path_u[i].val)
#         i += 1

#     return ans


# def lca(root: TNode, U: TNode, V: TNode) -> int:
#     """
#     common_ancestors 중 '가장 낮은'(= 루트에서 가장 먼) 노드의 값 반환
#     """
#     ancestors = common_ancestors(root, U, V)
#     # 공통조상이 전혀 없지 않은 이상, 마지막 원소가 LCA
#     return ancestors[-1] if ancestors else None


# # ---------------------------
# # 간단 테스트
# if __name__ == "__main__":

#     #        8
#     #      /   \
#     #     3     15
#     #    / \   /  \
#     #   1   4 5    6
#     #  /
#     # 0
#     #
#     # 예시 트리
#     n0 = TNode(0)
#     n1 = TNode(1, left=n0)
#     n4 = TNode(4)
#     n5 = TNode(5)
#     n6 = TNode(6)
#     n3 = TNode(3, n1, n4)
#     n15 = TNode(15, n5, n6)
#     root = TNode(8, n3, n15)

#     print("height(root):", height(root))      
#     # 루트(8) 기준: left쪽 높이 = 2, right쪽 높이 = 1 => 전체 높이는 1 + max(2,1) = 3
#     # 그러나 문제에서 "루트만 =>0" 이므로, leaf=0 => n3높이=2, root(8)높이=3
#     # 출력 => 3

#     print("is_balanced(root):", is_balanced(root))  
#     # 왼쪽 서브트리 높이가 2, 오른쪽 1 => |2-1|=1
#     # 내부 노드들도 모두 균형 범위 안 => True

#     print("is_bst(root):", is_bst(root))   
#     # 현재 트리에서는 4가 (3의 오른쪽)이고 5,6이 (15의 왼쪽/오른쪽)이므로
#     # 1 < 3 < 4 < 8 < 5 ... => 사실 이건 BST가 깨짐(5 < 8이지만 5가 오른쪽 subtree(>8)에 있기 때문에)
#     # 이 예시에선 False 나올 확률이 높음

#     # common_ancestors, lca 테스트
#     # 공통조상(8,3,5) → [8], LCA=8
#     print("common_ancestors(root, n3, n5):", common_ancestors(root, n3, n5))
#     print("lca(root, n3, n5):", lca(root, n3, n5))

#     # 더 깊은 노드들 테스트:
#     # (0과 4)의 공통 조상은 [8,3], LCA=3
#     print("common_ancestors(root, n0, n4):", common_ancestors(root, n0, n4))
#     print("lca(root, n0, n4):", lca(root, n0, n4))

# """