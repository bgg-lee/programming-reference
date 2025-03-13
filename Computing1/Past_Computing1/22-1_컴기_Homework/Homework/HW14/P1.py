def P1(n: int) -> bool:
    # write your code below
    lst = []
    bn = bin(n)
    ans = True
    curr = bn[2]
    
    for i in bn[3:]:
        if i == curr:
            ans = False
            curr = i
        else:
            curr = i
  
    return ans