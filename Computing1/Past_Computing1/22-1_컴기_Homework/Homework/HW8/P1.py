def P1(num_list: list) -> int:
    
    ### Write code here ###    
    def swap(l: list) -> int:
        swap = 0
        end = len(l)
        start = 0
    
        while start != end -1: 
            if l[start] > l[start+1]:
                a = l[start]
                b = l[start+1]
                l[start] = b
                l[start+1] = a
                swap += 1
            
            start += 1  

        return swap
    
    swap_i = -1
    ans = 0
    
    while swap_i != 0: 
        swap_i = swap(num_list)
        if swap_i == -1:
            swap_i = 0
        else:
            ans += swap_i
    
    return ans
    
    ### End of your code ###  