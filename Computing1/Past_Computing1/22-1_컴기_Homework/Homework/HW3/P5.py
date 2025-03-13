from typing import List
def P5(alphabet_list: List[str]) -> int:
    idx = 0
    ### Modify code here ###
    
    while idx < len(alphabet_list):
        if alphabet_list[idx].islower():
            idx += 1
        elif alphabet_list[idx].isupper():
            break
     
    else: 
        idx = -1
    
    ### End of your code ###  
    return idx
