def P2(Order: str, S: str) -> str:

    ### Write code here ###
    Correct_S = ""
    
    for idx in Order:
        if idx in S:
            Correct_S += ( idx * S.count(idx) )
            S = S.replace(idx,"")   
    
    for i in S:
        Correct_S += i
           
    return Correct_S

    ### End of your code ###  