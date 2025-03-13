"""
1. Linked list의 모든 node val을 순서대로 print하는 함수 짜기
2. 해당 linked list가 palindrome인지 확인하는 함수 짜기
3. substring(s,t) : t in s 인지 확인
4. maximal palindrome 함수 짜기( 위 1~3번 활용)
"""
class Node:
    def __init__(self, data, next):
        self.data = data
        self.next = next

def print_list(node:Node)->None:
    curr = node
    while curr:
      print(curr.data,end="")
      if curr.next:
          print(",",end="")
      curr = curr.next
def palindrome(node:Node)->bool:
    if not node : return True

    lst = []
    curr = node
    while curr:
        lst.append(curr.data)
        curr = curr.next
    return lst == lst[::-1]

def substring(s:Node,t:Node)->bool: # t in s ?
    lst_s = []
    lst_t = []
    curr_s = s
    curr_t = t
    while curr_s:
        lst_s.append(curr_s.data)
        curr_s = curr_s.next
    while curr_t:
        lst_t.append(curr_t.data)
        curr_t = curr_t.next

    if len(lst_t) > len(lst_s) : return False

    # lst_s가 더 크다.
    for i in range(len(lst_s)-len(lst_t)+1):
        idx = i
        for j in range(len(lst_t)):
            if lst_s[idx] == lst_t[j] :
                idx+=1
                continue
            else : break
        if idx == i + len(lst_t) : return True
    
    return False

def make_substring(arr:list[Node],s:int,e:int) -> Node:
    if s > e : return None

    head_new = None
    prev = None
    for i in range(s,e+1):
        new_node = Node(arr[i].data,None)
        if not head_new:
            head_new = new_node
            prev = new_node
        else:
            prev.next = new_node
            prev = prev.next

    return head_new

def maximal_palindrome(node:Node)->None:
    # 일단 arr_all에 Node를 다 담는다.
    arr_all = []
    curr = node
    while curr:
        arr_all.append(curr)
        curr = curr.next
    n = len(arr_all)
    # edge case
    if n==0:
        print("[]")
        return
    # palindrome 되는 sub node 전부 취합
    arr_pel = []
    for s in range(n):
        for e in range(s,n):
            sub_node = make_substring(arr_all,s,e)
            if palindrome(sub_node):
                arr_pel.append(sub_node)

    # 와중에 sub string 관계인 것들 쳐내기, 이것도 아이디어다
    i = 0
    while i < len(arr_pel): # pop 할 때마다 arr_pel의 len은 자동으로 업뎃
        head1 = arr_pel[i]
        cond = False
        for j in range(len(arr_pel)):
            if i == j : continue # 이게 킥이다. 본인과 같은 index는 skip
            head2 = arr_pel[j]
            if substring(head2,head1):
                cond = True
                break
        if cond:
            arr_pel.pop(i) # i는 왼쪽부터 순차적으로 검토중이라 pop(i) 괜찮다. 잘 생각해보면 괜찮은 거 알 수 있음
        else : i+=1
    print("[",end="")
    for i in range(len(arr_pel)):
        print("[",end="")
        print_list(arr_pel[i])
        print("]",end="")
        if i != len(arr_pel)-1:
            print(",",end="")
    print("]",end="")

if __name__ == "__main__" :
    #s = [8,1,2,3,3,2,1,4,9,4,5,6,7,6,5,4,1]
    s = [8,1,2,3,3,2,1,0,4,9,1,2,3,3,2,1,9,1]

    head = Node(s[-1], None) # 뒤에서부터 만드네
    for i in range(len(s)-1):
        head = Node(s[-2-i], head)

    t = [2,1,0,4,7]
    head2 = Node(t[-1], None)
    for i in range(len(t)-1):
        head2 = Node(t[-2-i], head2)

    s1 = [1,2,3,2,1]
    head3 = Node(s1[-1], None)
    for i in range(len(s1)-1):
        head3 = Node(s1[-2-i], head3)

    s2 = [1,2,3,3,2,1]
    head4 = Node(s2[-1], None)
    for i in range(len(s2)-1):
        head4 = Node(s2[-2-i], head4)

    print_list(head)
    print()
    # # print(palindrome(head2))
    # # print(palindrome(head3))
    # print(substring(head,head4))
    maximal_palindrome(head)