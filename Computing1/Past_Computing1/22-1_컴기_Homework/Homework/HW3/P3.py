from typing import List
def P3(num_list: List[int]) -> List[int]:
    ans_list = []
    ### Modify code here ###
    
    # 숫자를 각각 음수->양수, 0->0, 양수->음수로 변경, 답안에 담기
    for num in num_list:
        ans_list.append(-num)
    
    ### End of your code ###   
    return ans_list
    