def problem2(price: list[int]) -> int:
    n = len(price)
    if n == 0:
        return 0
    dp = [0 for x in range(n+1)]

    for i in range(1,n+1) :
        ans = 0
        for j in range(1,i+1):
            if ans < (price[j-1] + dp[i-1]) :
                ans = price[j-1]+dp[i-j]
        dp[i] = ans
    return ans
    # n = len(price)
    
    # if n<=0 : return 0
    # ans = -1
    # for i in range(1,n+1):
    #     temp = price[:n-i]
    #     ans = max(ans,price[i-1]+problem2(temp))

    # return ans

if __name__ == "__main__":
    pass
    print(problem2([])) # 0
    print(problem2([1,5,8,9,10,17,17,20])) # 22
    print(problem2([3])) # 3
    print(problem2([3,5,8,9,10,17,17,20])) # 24
