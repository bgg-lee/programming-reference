def P4(nums: list) -> int:

    ### Write code here ###
    len_max = 0
    nums = set(nums)
    dic = {}
    dic_rev = {}  
    
    for i in nums:
        if ((i+1 in dic) == False) and ((i-1 in dic_rev) ==False):
            dic[i] = i  # {3:3} -> {2:3, 4:4}
            dic_rev[i] = i  # {3:3} -> {3:2, 4:4}
            continue
            
        if i+1 in dic:
            dic[i] = dic[i+1]  # {3:3, 2:3} -> {2:3}
            dic_rev[dic[i+1]] = i  # {3:2}
            del dic[i+1] # 
            
        if i-1 in dic_rev:
            dic_rev[i] = dic_rev[i-1] # 
            dic[dic_rev[i-1]] = i  # 
            del dic_rev[i-1]
            
        if (i in dic) and (i in dic_rev):
            dic[dic_rev[i]] = dic[i]
            dic_rev[dic[i]] = dic_rev[i]
            del dic[i]
            del dic_rev[i]
  
    for i in dic:
        if len_max < dic[i] - i + 1:
            len_max = dic[i] - i + 1
                        
    return len_max   
    
    ### End of your code ###  