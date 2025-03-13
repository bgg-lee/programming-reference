def problem2(price: list[int]) -> int:
    n = len(price)

    if n<=0 : return 0
    ans = -1
    for i in range(1,n+1):
        temp = price[:n-i]
        ans = max(ans,price[i-1]+problem2(temp))
    # print(ans)
    return ans

problem2([1,5,8,9,10,17,17,20])

temp = [1,5,8,9,10,17,17,20]
print(temp[0])
print(temp[:7])
print(temp[:7])
