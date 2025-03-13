"""
**Instruction**
Please see instruction document.

"""
from BST_Helper import *
from typing import List
def P2(root: TreeNode) -> List[List[int]]:       
    ##### Write your Code Here #####
    
    def depth(curNode:TreeNode) -> int:
        if not curNode:
            return -1
        leftheight = depth(curNode.left) +1
        rightheight = depth(curNode.right) +1
        return max(leftheight, rightheight)
        
    def __bottomupHelp(curNode: TreeNode, dct:dict, depth:int):
        if not curNode:
            return None
        if curNode.val:
            dct[depth].append(curNode.val)
            depth += 1
            __bottomupHelp(curNode.left, dct, depth)
#             print(dct)
            __bottomupHelp(curNode.right, dct, depth)
#             print(dct)
        return dct
    
    def bottomup(curNode:TreeNode):
        dct = {}
        for i in range(depth(curNode)+1):
            dct[i] = []
        return __bottomupHelp(curNode, dct, 0)
    
    ans = [i for i in bottomup(root).values()]
    
    # 아래 return은 맞게 수정해주시면 됩니다
    return ans[::-1]
    ##### End of your code #####
