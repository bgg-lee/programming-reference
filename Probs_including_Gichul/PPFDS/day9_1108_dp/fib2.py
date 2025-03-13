# def fib(n): # 1 1 2 3 5 8
#     if n <= 2 : return 1
#     return fib(n-1) + fib(n-2)

# print(fib(6))

# # DP version of fib

# dic = {}
# dic[1] = 1
# dic[2] = 1
# def fib2(n):
#     if n in dic:return dic[n]
#     else:
#         dic[n] = fib2(n-1)+ fib2(n-2)
#         return dic[n]
# print("fib2 start")
# print(fib2(3))
# print(fib2(5))
# print(fib2(6))

# def fib3(n:int) -> int:
#     dic = {} # for DP
#     for i in range(1,n+1):
#         if i==1 or i==2:
#             dic[i] = 1
#         else:
#             dic[i] = dic[i-1]+dic[i-2]
#     return dic[n]
# print(fib3(3))
# print(fib3(6))
# s2 = {3,1,4}
# print(s2[0])

# Climbing stairs

