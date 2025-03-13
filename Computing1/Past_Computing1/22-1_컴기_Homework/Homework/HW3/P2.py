def P2(L1: list, L2: list, L3: list) -> int:
    ans = 0
    ### Modify code here ###
    
    # 각 리스트의 길이를 계산, 길이들 중 가장 긴 길이를 선택
    ans += max(len(L1), len(L2), len(L3))

    ### End of your code ###
    return ans