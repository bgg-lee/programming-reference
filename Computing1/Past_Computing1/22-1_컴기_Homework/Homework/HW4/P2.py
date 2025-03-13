def P2(lst1: list, lst2: list) -> set:
    ### Write code here ###
    
    ans = []
    
    for i in range(len(lst1)):
        ans.append((lst1[i], lst2[i]))

    return set(ans)
    

    ### End of your code ###     
