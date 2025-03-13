def P5(dct: dict) -> list:
    ### Write code here ###
    
    values = list(dct.values())
    ans = []
    
    for i in set(dct.values()):
        if values.count(i) >= 2:
            ans.append(i)
            
    return ans


    ### End of your code ###     
