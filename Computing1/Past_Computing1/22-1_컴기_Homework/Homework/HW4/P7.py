def P7(dct: dict) -> int:
    ### Write code here ###

    inner_k = []
    ans = -1
    
    for outer_v in dct.values():
        inner_k.append(sorted(outer_v.keys()))

    for i in range(len(inner_k)):
        if inner_k[0] != inner_k[i]:
            ans = 0
        else:
            ans = 1
        
    return ans

    ### End of your code ###     
