from typing import List
def P4(matrix: List[List[int]], target: int) -> (int, int):        
    ##### Write your Code Here #####    
    s1 = 0
    e1 = len(matrix) -1
    s2 = 0
    e2 = len(matrix[0]) -1
    ans = ()
    
    if (matrix[0][0] > target) or matrix[-1][-1] < target:
        return (-1, -1)
    
    else:
    
        while s1 != e1 +1 :
            m1 = (s1 + e1) // 2
            if matrix[m1][0] <= target <= matrix[m1][-1]:
                s1 = m1 
                break
            elif target < matrix[m1][0]:
                e1 = m1 - 1 
            elif matrix[m1][-1] < target:
                s1 = m1 + 1 
    
        while s2 != e2 + 1:
            m2 = (s2 + e2) // 2
            if matrix[s1][m2] < target:
                s2 = m2 + 1
            else:
                e2 = m2 - 1
        
        if matrix[s1][s2] == target and s1 < len(matrix) and s2 < len(matrix[0]):
            return (s1, s2)
    
        else:
            return (-1, -1)
    
    
    ##### End of your code #####