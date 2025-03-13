# int main, test 하는 코드도 주지 않음..

def is_palindromic(s: str) -> bool:
    """
    > input 's'
    - A string consisting of only lowercase English letters (1 <= len(s) = 1000)
    > return a boolean
    """
    # WRITE YOUR CODE HERE
    n = len(s)
    left = 0
    right = n-1
    while left < right :
        if s[left] != s[right] : return False
        else :
            left +=1
            right -=1
    return True
def LPS(s: str) -> tuple:

    n = len(s)
    f = [[0] * n for _ in range(n)]
    for i in range(n):
        f[i][i] = 1
    for i in range(n - 1, -1, -1):
        for j in range(i + 1, n):
            if s[i] == s[j]:
                f[i][j] = f[i + 1][j - 1] + 2
            else:
                f[i][j] = max(f[i + 1][j], f[i][j - 1])
    def find_p(left:int,right:int) -> str:
        if left > right : return ''
        elif left == right : return s[i]
        else:
            if s[left] == s[right]:
                return s[left] + find_p(left+1,right-1) + s[left]
            else:
                if f[left+1][right] >= f[left][right-1]:#이걸 모름
                    return find_p(left+1,right)
                else: return find_p(left,right-1)
    ans = "" # 이 개념도 모름
    for i in range(n):
        for j in range(i, n):
            if f[i][j] > len(ans):
                temp = find_p(i, j)
                if len(temp) > len(ans) or (len(temp) == len(ans) and temp < ans):
                    ans = temp
    return (len(ans),ans)



# def LPS(s: str) -> tuple:
#     """
#     > input 's'
#     - A string consisting of only lowercase English letters (1 <= len(s) = 1000)
#     > return a tuple (int, str):
#     - An integer representing the length of the longest palindromic subsequence
#     - A string representing one of the longest palindromic subsequences
#     """
#     # ex) acabca -> acaca , 동점자 발생 시 Order 작은 문자열
#     # WRITE YOUR CODE HERE
#     ## Base Case
#     if is_palindromic(s) or len(s) == 1 : return (len(s),s)
#     ans = ""
#     n = len(s)
#     for i in range(n):
#         left = i
#         right = n-1
#         temp = ""
#         while left<=right:
#             t = len(temp)
#             if left == right:
#                 temp = temp[:t//2] + s[left] + temp[t//2:]
#                 break
#             if s[left] == s[right]:
#                 temp = temp[:t//2] + s[left] + s[left] + temp[t//2:]
#                 left += 1
#                 right -= 1
#             else :
#                 if s[left] < s[right] : right -=1
#                 else : left += 1
#                 # temp2 = LPS(s[left+1:right])[1]
#                 # temp = temp[:t//2] + temp2 + temp[t//2:]

#         if len(temp) == len(ans) :
#             ans = min(temp,ans)   
#         elif len(temp) > len(ans) :
#             ans = temp
#     return (len(ans),ans)

# def LPS(s: str) -> tuple:
#     """
#     Find the longest palindromic subsequence (length and string) in the input string.
#     """
#     n = len(s)
#     if n == 0:
#         return (0, "")
#     if n == 1:
#         return (1, s)
    
#     # DP 테이블 초기화
#     dp = [[0] * n for _ in range(n)]
#     for i in range(n):
#         dp[i][i] = 1

#     # 역추적용 테이블
#     parent = [[None] * n for _ in range(n)]
    
#     # DP 테이블 채우기
#     for length in range(2, n + 1):
#         for i in range(n - length + 1):
#             j = i + length - 1
#             if s[i] == s[j]:
#                 dp[i][j] = dp[i + 1][j - 1] + 2
#                 parent[i][j] = (i + 1, j - 1)
#             else:
#                 if dp[i + 1][j] > dp[i][j - 1]:
#                     dp[i][j] = dp[i + 1][j]
#                     parent[i][j] = (i + 1, j)
#                 elif dp[i + 1][j] < dp[i][j - 1]:
#                     dp[i][j] = dp[i][j - 1]
#                     parent[i][j] = (i, j - 1)
#                 else:
#                     # 길이가 같다면 사전순 선택
#                     if s[i:j+1] < s[i+1:j+2]:
#                         parent[i][j] = (i, j - 1)
#                     else:
#                         parent[i][j] = (i + 1, j)
#                     dp[i][j] = dp[i][j - 1]

#     # 결과 팰린드롬 복원
#     def construct_palindrome(i, j):
#         if i > j:
#             return ""
#         if i == j:
#             return s[i]
#         if parent[i][j] == (i + 1, j - 1):
#             return s[i] + construct_palindrome(i + 1, j - 1) + s[j]
#         elif parent[i][j] == (i + 1, j):
#             return construct_palindrome(i + 1, j)
#         else:
#             return construct_palindrome(i, j - 1)

#     lps = construct_palindrome(0, n - 1)
#     return (dp[0][n - 1], lps)


# def LPS(s: str) -> tuple:
#     if len(s) == 0:
#         return (0, "")
#     if len(s) == 1:
#         return (1, s)

#     def find_palindrome(left, right):
#         temp = ""
#         while left <= right:
#             t = len(temp)
#             if s[left] == s[right]:
#                 if left == right:
#                     temp = temp[:t // 2] + s[left] + temp[t // 2:]  # 가운데 문자 삽입
#                 else:
#                     temp = s[left] + temp + s[right]  # 양쪽 확장
#                 left += 1
#                 right -= 1
#             else:
#                 # 두 포인터를 모두 탐색하며 더 나은 선택을 진행
#                 if dp[left + 1][right] >= dp[left][right - 1]:
#                     left += 1
#                 else:
#                     right -= 1
#         return temp

#     n = len(s)
#     dp = [[0] * n for _ in range(n)]

#     # DP 테이블 초기화
#     for i in range(n):
#         dp[i][i] = 1

#     # DP 테이블 채우기
#     for length in range(2, n + 1):
#         for i in range(n - length + 1):
#             j = i + length - 1
#             if s[i] == s[j]:
#                 dp[i][j] = dp[i + 1][j - 1] + 2
#             else:
#                 dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])

#     ans = ""
#     for i in range(n):
#         for j in range(i, n):
#             if dp[i][j] > len(ans):
#                 temp = find_palindrome(i, j)
#                 if len(temp) > len(ans) or (len(temp) == len(ans) and temp < ans):
#                     ans = temp

#     return (len(ans), ans)

# 결국 dp를 써야한다..

# 내가 만들어낸 것것
if __name__ == "__main__":
    
    # print(is_palindromic('abcd')) # false
    # print(is_palindromic('abba')) # true
    # print(is_palindromic('a')) # true
    # print(is_palindromic('zxccxz')) # true
    # print(is_palindromic('zxccxzz')) # false
    print(LPS('abba')) # 4,abba
    print(LPS('aab')) # 2,aa 
    print(LPS('acabca')) # 5,acaca 
    print(LPS('acaba')) # 3,aaa
    print(LPS('acazttqwbca'),"못찾음 6,acttca") # 6,acttca
    print(LPS('acabz')) # 3,aca
    print(LPS('a')) # 1,a
    print(LPS('asdzxcasqcasd')) # ?


    
    