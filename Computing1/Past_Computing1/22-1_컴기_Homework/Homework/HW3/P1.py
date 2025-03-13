from typing import List
def P1(num_list: List[int]) -> List[int]:
    ### Modify code here ###
    
    # 리스트를 오름차순 정렬
    num_list.sort()
    
    # 리스트에서 1234 제거
    num_list.remove(1234)
    
    # [4321, 2222]를 추가하여 리스트를 확장
    num_list.extend([4321, 2222])
    
    # 1번 index 위치에 1111 추가
    num_list.insert(1, 1111)
    
    ### End of your code ###
    return num_list
