def lps(s: str) -> int:
    N = len(s)
    dp = [[-1]*N for _ in range(N) ]
    #dp[i][j] 는 string s를 idx i에서 j까지만 봤을 때, 그 안에 최대 palindrome sub string 개수

    def helper(h:int,t:int)->int:
        # Base
        if h == t : return 1
        if h > t : return 0
        if t == h + 1 and s[h] == s[t]: return 2

        # Return saved value if possible
        if dp[h][t] != -1 : return dp[h][t]
        else:
            if s[h] == s[t] :
                dp[h][t] = 2 + helper(h+1,t-1)
            else:
                dp[h][t] = max(helper(h+1,t),helper(h,t-1)) # 이게 좀 짜치네

        return dp[h][t]

    return helper(0,N-1)

  
print(lps("bbbcb")) # bbbb 4 
print(lps("abbc")) # bb 2
print(lps("asdfzdsa")) # asdfdsa 7