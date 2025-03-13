def P4(num:int) -> int:
    # write your code below
    ans = 0
    bn = bin(num)[2:]

    
    for i in bn:
        if i == '1':
            ans += 1

    return ans