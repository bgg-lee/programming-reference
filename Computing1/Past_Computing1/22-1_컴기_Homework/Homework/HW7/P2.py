def P2(s: str) -> int:
    ### Modify code here ###

    nums = {'zero':0, 'one':1, 'two':2, 'three':3, 'four':4, 'five':5,
           'six':6, 'seven':7, 'eight':8, 'nine':9}
    num = ""
    ans = ""
    
    for i in range(len(s)):
        char = s[i]
        if char.isalpha():
            num += s[i]
            if num in nums:
                ans += str(nums[num])
                num = ""
        
        else:
            ans += str(s[i])
    
    return int(ans)

    
    ### End of your code ###