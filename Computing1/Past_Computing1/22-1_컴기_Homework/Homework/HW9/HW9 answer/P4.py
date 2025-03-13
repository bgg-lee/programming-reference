from linked_list_helper import ListNode
def P4(num1: ListNode, num2: ListNode) -> ListNode:    
    def fn(node): 
        """Reverse a linked list."""
        prev = None
        while node: prev, node.next, node = node, prev, node.next
        return prev 
    
    num1, num2 = fn(num1), fn(num2) # reverse num1 & num2
    carry = 0
    dummy = node = ListNode()
    while carry or num1 or num2:
        if num1: 
            carry += num1.val
            num1 = num1.next
        if num2: 
            carry += num2.val
            num2 = num2.next
        carry, x = divmod(carry, 10)
        node.next = node = ListNode(x)
    return fn(dummy.next)   
