def P4(dct: dict) -> str:
    ### Write code here ###
    
    ans = ""
    
    for key, value in dct.items():
        if value == max(dct.values()):
            ans = key

    return ans

    ### End of your code ###     
