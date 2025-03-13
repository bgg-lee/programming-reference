def P1(lst: list) -> set:
    ### Write code here ###
    
    # 각 원소별 갯수 세고, 2이상인 경우 답안 리스트에 추가
    # 세트로 리턴
    ans = []
    
    for i in lst:
        if lst.count(i) > 1:
            ans.append(i)
            
    return set(ans)


    ### End of your code ###     
