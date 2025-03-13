# lps LPS longest palindrom을 찾는 문제
# substring 다 구하고 그 중에 palindrome만 걸러내고 그 중에 젤 긴 놈 + 사전순 빠른놈 반환
def is_palindromic(s: str) -> bool:
    """
    > input 's'
    - A string consisting of only lowercase English letters (1 <= len(s) = 1000)
    > return a boolean
    """
    # WRITE YOUR CODE HERE
    if len(s) < 2 : return True
    left = 0
    right = len(s)-1
    while left < right :
        if s[left]!=s[right] : return False
        left += 1
        right -= 1
    return True

def LPS(s: str) -> tuple:
    """
    > input 's'
    - A string consisting of only lowercase English letters (1 <= len(s) = 1000)
    > return a tuple (int, str):
    - An integer representing the length of the longest palindromic subsequence
    - A string representing one of the longest palindromic subsequences
    """ 
    # WRITE YOUR CODE HERE
    # back-tracking? palindrome 돌리면서 list에 다 저장해놓고, len max들 중에서 sort 첫번째 하면 될듯?
    if len(s) == 1 : return (1,s[0])
    lst = []
    def backtrack(start:int,curr:str)->None:
        if curr not in lst and is_palindromic(curr):
            lst.append(curr)
        
        for i in range(start,len(s)):
            backtrack(i+1,curr+s[i])

    backtrack(0,"")
    length = 0
    for a in lst:
        length=max(length,len(a))
    ans = []
    for x in lst:
        if len(x) == length : ans.append(x)
    ans.sort()
    return (length,ans[0])
    
# 아래도 내가 만든 것
if __name__ == "__main__" :
    # print(is_palindromic('abc')) # False
    # print(is_palindromic('aba')) # True
    # print(is_palindromic('')) # True
    print(LPS('acabab')) # (3,aaa)
    print(LPS('bcabc')) # (3,bab)
    print(LPS('paczqcazc')) # (5,acqca)
