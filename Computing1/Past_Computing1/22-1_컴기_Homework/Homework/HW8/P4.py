from typing import List
def P4(matrix:List[list]) -> List[list]:

    ### Write code here ###
    
    i_diff = {}
    
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if (j-i) in i_diff:
                i_diff[j-i].append(matrix[i][j])
            else:
                i_diff[j-i] = [matrix[i][j]]
    
    for i in i_diff:
        i_diff[i].sort()
        
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            matrix[i][j] = i_diff[j-i].pop(0)
    
    return matrix

    ### End of your code ###  