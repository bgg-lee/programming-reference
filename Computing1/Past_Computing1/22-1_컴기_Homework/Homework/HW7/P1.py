def P1(n: int) -> bool:        
    ##### Write your Code Here #####    
    ans = False
    prime = []
    i = 2
    
    while n != 1:
        if n % i == 0:
            prime.append(i)  
            n = n//i
            
        else:
            i += 1
    
    if len(prime) == 2:
        ans = True
        
    return ans
    
    ##### End of your code #####