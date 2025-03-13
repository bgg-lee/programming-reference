from typing import List
def P8(num_list: List[float]):
    ans_list = []
    ##### Modify code Here #####
    
    # 음수가 아니면 답안에 담기, 음수면 넘기기
    for i in num_list:
        if i < 0:
            continue
        else:
            ans_list.append(i)

    ##### End of your code #####
    return ans_list
    

