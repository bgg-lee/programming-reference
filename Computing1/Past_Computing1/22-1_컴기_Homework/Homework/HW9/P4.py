from linked_list_helper import ListNode

def P4(num1: ListNode, num2: ListNode) -> ListNode: 
    ##### Write your Code Here #####
    
    def sort(curNode: ListNode) -> ListNode: 
        next = None
        curr = curNode
        prev = None
        while (curr != None):
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        return prev
    
    def addTwo(cur1: ListNode, cur2: ListNode) -> ListNode: 
        root = ans = ListNode(0)
        carry = 0
        while cur1 or cur2 or carry:
            sum = 0
            if cur1:
                sum += cur1.val
                cur1 = cur1.next

            if cur2:
                sum += cur2.val
                cur2= cur2.next

            carry, val = divmod((sum + carry), 10)
            ans.next = ListNode(val)
            ans = ans.next
            
        return root.next
        
    num1_n = sort(num1)
    num2_n = sort(num2)
    return sort((addTwo(num1_n, num2_n)))
    
    ##### End of your code #####