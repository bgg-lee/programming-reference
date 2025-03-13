def P2(stock_price: list) -> list:        
    ##### Write your Code Here #####

    ans = [0] * len(stock_price)
    stack = []
    for i, p in enumerate(stock_price):
      while stack and stock_price[stack[-1]] < p:
        cur = stack.pop()
        ans[cur] = i - cur
      stack.append(i)

    return ans

    ##### End of your code #####

