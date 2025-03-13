from typing import List
def P4(word_num_list: List[list]) -> list:
    ans_list = []
    ### Modify code here ###
    
    # 리스트에서 단어만 추출하여 답안에 담기
    for word_num in word_num_list:
        ans_list.append(word_num[0])
    
    # 알파벳 순으로 정렬
    ans_list.sort()
    
    ### End of your code ###  
    return ans_list
    