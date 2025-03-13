def P3(lst: list) -> list:

    ### Write code here ###

    for i in range(1, len(lst)):
        for j in range(i,0,-1):
            if len(lst[j-1]) > len(lst[j]):
                lst[j-1],lst[j] = lst[j], lst[j-1]
            elif len(lst[j-1]) == len(lst[j]):
                dic = [lst[j-1], lst[j]]
                dic.sort()
                lst[j-1],lst[j] = dic[0], dic[1]
            else:
                break
                
    return lst
    
    ### End of your code ###  