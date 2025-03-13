def P2(nums: list) -> int:

    ### Write code here ###
    
    ans = 0
    now = 0
    sum_idx = dict()
    
    for i in range(len(nums)):
        if nums[i] == 0:
            now -= 1
        elif nums[i] == 1:
            now += 1
        
        if now == 0:
            ans = i+1
        else:
            if now in sum_idx:
                ans = max(ans, i- sum_idx[now])
            else:
                sum_idx[now] = i
    
    return ans
    
    ### End of your code ###  