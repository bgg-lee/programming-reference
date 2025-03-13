from typing import List
def P6(n1: int, n2: int) -> List[int]:
    ans_list = []
    ### Modify code here ###
    
    ans_list = list(range(max(n1,n2), min(n1,n2)-1, -1))

    ### End of your code ###
    return ans_list

