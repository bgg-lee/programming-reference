def P6(dct1: dict, dct2: dict) -> dict:
    ### Write code here ###

    ans = {}
    
    for x, y in dct1.items():
        for i, j in dct2.items():
            if x == i and y == j:
                ans[i] = j

    return ans

    ### End of your code ###     
