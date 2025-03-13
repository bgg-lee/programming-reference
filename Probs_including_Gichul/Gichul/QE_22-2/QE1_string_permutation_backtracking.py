# string permutation backtracking
# 어렵다...

def str_perm(s:str) -> list[str]:
    ans = []
    def backtrack(start:str, curr:str)->None:
        if not curr and start not in ans: #중복제거용
            ans.append(start)
            return
        for i in range(len(curr)):
            # backtrack(start+curr[i],curr[:i]+curr[i+1:]) # 이거 하나면 됨, 자동 backtracking
            start += curr[i]
            backtrack(start,curr[:i]+curr[i+1:]) # 이게 Kick point, string을 자유롭게 쪼개서 요리하기
            start = "".join(list(start)[:-1])
            
            pass
    
    backtrack("",s)
    # 알파벳순서 정렬
    ans = sorted(ans)
    return ans


if __name__ == "__main__":
    s1 = "bac"
    s2 = "abb"
    print(str_perm(s1)) # ['abc','acb','bac','bca','cab','cba']
    print(str_perm(s2)) # ['abb','bab','bba']

    print(len(str_perm(s1))) # ['abc','acb','bac','bca','cab','cba']



