def P2(num:int)->int:
    # write your code below
    bn = bin(num)[2:]
 
    bn = bn.zfill(32)    

    ans = bn[::-1]

       
    return int(ans, 2)