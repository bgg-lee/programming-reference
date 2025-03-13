def P9(dct1: dict, dct2: dict) -> int: 
    ### Write code here ###
    
            
    ans = 0
    
    for i,j in dct1.items():
        for x,y in dct2.items():
            if i == x:
                ans += (j * y)
                
    return ans


    ### End of your code ###    
