# 핵 조잡하게 풀었다;;

def palindrome(s:str) -> bool :
    if(len(s) <= 1) : return True
    else:
        left = 0
        right = len(s)-1
        while left < right :
            if s[left]!=s[right] : return False
            left+=1
            right-=1

        return True

def substring(s:str,t:str) -> bool :
    # str t가 s의 substring인지 check 하는 것
    # in 써도 되나?
    # return t in s
    # in 쓰면 안 된 다면,
    if len(s) < len(t) : return False
    # s(큰놈) 돌면서 t 첫째와 같으면 stop후 substring 체크
    for i in range(len(s)-len(t)+1):
        if s[i:i+len(t)] == t : return True
    return False

def max_palindrome(s:str) -> list[str]:
    # 완전 Naive하게 하는 방법만 떠오른다..
    ans = []
    for i in range(len(s)):
        curr = s[i]
        temp = s[i]
        cond = True
        lst = [] # 쓸모 없는 ans list 삭제용
        for j in range(i+1,len(s)):
            curr += s[j]
            if palindrome(curr):
                temp = curr
        # ANS에 temp를 추가해도 될 지 check
        for idx in range(len(ans)):
            if substring(ans[idx],temp): #temp가 ans에 있는놈의 sub라면.. 추가 불필요
                cond = False
            if substring(temp,ans[idx]): #ans에 들어있는 놈이 temp의 sub라면.. 걔 삭제가능
                lst.append(ans[idx])
        # 쓸모 없는 ans 삭제
        while lst:
            delete = lst.pop()
            ans.remove(delete)
        # 정답만 추가
        if cond :
            ans.append(temp)


    return ans

if __name__ == "__main__":
    s1 = "kabccbadzdefgfeda"
    s2 = "kabccba dzabccbaza"
    s3 = "yuasdsaa azxqx yuiiuyiuy"
    print(max_palindrome(s1)) # [k,abccba,dzd,defgfed]
    print(max_palindrome(s2)) # [k, , d,zabccbaz,aza]
    print(max_palindrome(s3)) # [k, , d,zabccbaz,aza]