"""
**Instruction**
Please see instruction document.
"""
from BST_Helper import *
def P3(root: TreeNode, val: int) -> TreeNode:    
    ##### Write your Code Here #####
    def push(root:TreeNode, hd:TreeNode) -> TreeNode:
        root.right = hd
        if hd != None:
            hd.left = root
        hd = root
        return hd

    def BSTtoSorted(root:TreeNode, hd:TreeNode, nd=0) -> TreeNode:
        if root == None:
            return hd, nd
        hd, nd = BSTtoSorted(root.right, hd, nd)
        hd = push(root, hd)
        nd = nd + 1
        hd, nd = BSTtoSorted(root.left, hd, nd)
        return hd, nd

    def SortedToBST(hd: TreeNode, i: int) -> TreeNode:
        if i <= 0:
            return None, hd
        leftTree, hd =SortedToBST(hd, i // 2)
        root = hd
        root.left = leftTree
        hd = hd.right
        root.right, hd = SortedToBST(hd, i - (i // 2 + 1))
        return root, hd

    def BalancedBST(root: TreeNode) -> TreeNode:
        hd = None
        hd, nd = BSTtoSorted(root, hd)
        root, hd =SortedToBST(hd, nd)
        return root
        
    def insertnode(curNode: TreeNode, x:int) -> TreeNode:
        if not curNode:
            return TreeNode(x)
        if x < curNode.val:
            curNode.left = insertnode(curNode.left, x)
        elif x > curNode.val:
            curNode.right = insertnode(curNode.right, x)
        return curNode
        
    new_root = insertnode(root, val)
    ans = BalancedBST(new_root)  
    
    return ans
    ##### End of your code #####
