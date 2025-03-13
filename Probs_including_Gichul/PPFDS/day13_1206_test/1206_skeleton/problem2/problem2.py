# def problem2(price: list[int]) -> int:
#     n = len(price)
#     if n<=0 : return 0
#     ans = 0
#     for i in range(1,n+1):
#         ans = max(ans,price[i-1]+problem2(price[:n-i]))
#     return ans
#     # return 22
# if __name__ == "__main__":
    
#     pass


temp = [3,5,6,1]
print(temp[0])
print(temp[1:])