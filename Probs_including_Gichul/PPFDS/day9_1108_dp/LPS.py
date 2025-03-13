# def lps(s:str) -> int :
#     if not s : return 0
#     if len(s) == 1 : return 1

#     if s[0] == s[-1] :
#         return 2+lps(s[1:-1])
#     else :
#         return max(lps(s[1:]),lps(s[:-1])) # 이 부분이 kick이다. 잘 와닿지가 않는다. # 일단 TOP - DOWN 방식이다 이건
#     # 이걸 Memoization으로 풀어보자

#     # Greedy하게도 좀 알아봐보자


# print(lps("bbbcb")) # bbbb 4 
# print(lps("abbc")) # bb 2
# print(lps("asdfzdsa")) # asdfdsa 7

## Slack 조교님 code
def lps(s: str) -> int:
  #init dp array
  N = len(s)
  dp = [[-1 for _ in range(N)] for _ in range(N)] 
  
  def lps_recursive(i: int, j: int) -> int:
    # base cases
    if i == j:
      return 1 
    if i > j:
      return 0 
    if i + 1 == j and s[i] == s[j]:
      return 2 

    # check memo
    if dp[i][j] != -1:
      return dp[i][j]

    # recuresion
    if s[i] == s[j]:
      dp[i][j] = lps_recursive(i + 1, j - 1) + 2
    else:
      dp[i][j] = max(lps_recursive(i + 1, j), lps_recursive(i, j - 1))

    return dp[i][j] # write into memo

  return lps_recursive(0, N - 1)

  
print(lps("bbbcb")) # bbbb 4 
print(lps("abbc")) # bb 2
print(lps("asdfzdsa")) # asdfdsa 7