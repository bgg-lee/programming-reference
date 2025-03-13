from linked_list_helper import ListNode

def P3(head: ListNode) -> ListNode: 
    ##### Write your Code Here #####
    next = None
    curr = head
    prev = None

    while (curr != None):
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next
    
    return prev
    
    ##### End of your code #####
