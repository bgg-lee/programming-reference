"""
Given string, return any string that
1) 원래 string에서 adj한 문자들끼리 adj하지 않게
2_ 중복된 문자도 중복된 만큼

eg) abccde -> cacebd
eg) abc -> ""
eg) ""->""
foo(s:string)

위에서 중복만 없애서 

bar(s:string)
eg) abccde -> acebd
eg) abc -> ""
"""

def foo(s:str) -> str:
    # Permutation + backtrack 유사하게 가보자
    ans = []
    def backtrack(curr:str , remain:str) -> None:
        if len(curr) >= 2: # adj check
            temp = curr[-2:]
            if (temp in s) or (temp[::-1] in s) : return
        if not remain and curr not in ans :
            ans.append(curr)
            return
        for i in range(len(remain)):
            backtrack(curr+remain[i], remain[:i]+remain[i+1:])
    backtrack("",s)
    if not ans : return ""
    else : return ans[0]

def bar(s:str) -> str:
    ans = []
    def backtrack(curr:str , remain:str) -> None:
        if len(curr) >= 2: # adj check
            temp = curr[-2:]
            if (temp in s) or (temp[::-1] in s) : return
        # remain에 중복 letter만 남아있으면 지금 curr을 append
        cond = True
        for x in remain:
            if x not in curr:
                cond = False
                break
        if cond :
            ans.append(curr)
            return
        if not remain:  
            ans.append(curr)
            return
        for i in range(len(remain)):
            if remain[i] in curr : continue #중복제거
            backtrack(curr+remain[i], remain[:i]+remain[i+1:])

    backtrack("",s)
    if not ans : return ""
    else : return ans[0]

if __name__ == "__main__":
    s1 = "abccdeec"
    s2 = "abc"
    s3 = ""
    s4 = "asdfaq"
    s5 = "asaaqdzf"
    # print(foo(s1)) # cacebd
    # print(foo(s2)) # ""
    # print(foo(s3)) # ""
    # print(foo(s4)) # "adafqs" 예시
    # print(foo(s5)) 
    print(bar(s1)) # acebd
    print(bar(s2)) # ""
    print(bar(s3)) # ""
    print(bar(s4)) # "adafqs" 예시
    print(bar(s5)) 