def P5(A: list, B: list) -> int:
    
    ### Write code here ###

    A= sorted(A)
    B= sorted(B, reverse=True)

    new = zip(A,B)
       
    ans = [a*b for a,b in new]
    
    return sum(ans)
    ### End of your code ###  
