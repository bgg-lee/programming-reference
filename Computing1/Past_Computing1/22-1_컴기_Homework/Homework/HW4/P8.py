def P8(dct: dict) -> bool:
    ### Write code here ###
        
    total = 0
    
    for i in dct.values():
        total += i
        
    if total == 1:
        return True
    else:
        return False
    

    ### End of your code ###    
