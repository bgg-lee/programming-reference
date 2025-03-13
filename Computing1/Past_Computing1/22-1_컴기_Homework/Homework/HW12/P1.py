def P1(nums: list, k: int) -> bool:

    ### Write code here ###
    dct = dict()
    
    for  i in nums:
        if i% k  in dct:
            dct[i%k] += 1
        else:
            dct[i%k] = 1
    
    for i in dct:
        if i == 0 or i * 2 == k:
            if dct[i] % 2 != 0:
                return False
#             else:
#                 return True
        else:
            if k-i not in dct:
                return False
            if dct[i] != dct[k-i]: 
                return False
    return True
    
    

    
    ### End of your code ###v