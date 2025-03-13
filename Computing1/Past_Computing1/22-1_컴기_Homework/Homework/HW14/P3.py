def P3(nums:list)->set:
    # write your code below
    ans = []
    dct = {}
    
    for i in nums:
        if i in dct:
            dct[i] +=1
        else:
            dct[i] = 1

    
    for i,j in dct.items():
        if j == 1:
            ans.append(i) 

  
    return set(ans)