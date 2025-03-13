"""
**Instruction**
Please see instruction document.

"""
from BST_Helper import *

def P1(root: TreeNode, low: int, high: int) -> int:  
    
    ans = []
    
    def __searchHelp(curNode: TreeNode, low:int, high, lst:list):
        if not curNode:
            return lst

        if low < curNode.val < high:            
            lst.append(curNode.val)
            __searchHelp(curNode.left, low, high, lst)
            __searchHelp(curNode.right, low, high, lst)
            
        elif low == curNode.val:
            lst.append(curNode.val)
            __searchHelp(curNode.right, low, high, lst)

                  
        elif curNode.val < low :
            __searchHelp(curNode.right, low, high, lst)


        elif curNode.val == high:
            lst.append(curNode.val)
            __searchHelp(curNode.left, low, high, lst)

            
        elif high < curNode.val:
            __searchHelp(curNode.left, low, high, lst)

            
        return lst
    
    def search(curNode: TreeNode, low: int, high: int):
        return __searchHelp(curNode, low, high, [])
    
    ans = search(root, low, high)

    #아래 return은 맞게 수정해주시면 됩니다
    return sum(ans)
    ##### End of your code #####
