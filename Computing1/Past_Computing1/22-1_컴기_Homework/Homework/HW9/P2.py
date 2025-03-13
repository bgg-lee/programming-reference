def P2(stock_price: list) -> list:        
    ##### Write your Code Here #####
    
    stack = []
    
    for i in range(len(stock_price)-1):
        ans = 0
        for j in range(i+1, len(stock_price)):
            if stock_price[i] >= stock_price[j]:
                if j == (len(stock_price)-1):
                    ans = 0
                    stack.append(ans)
                else:
                    ans += 1
            else:
                ans += 1
                stack.append(ans)
                break
    
    stack.append(0)
                  
    return stack
    ##### End of your code #####

