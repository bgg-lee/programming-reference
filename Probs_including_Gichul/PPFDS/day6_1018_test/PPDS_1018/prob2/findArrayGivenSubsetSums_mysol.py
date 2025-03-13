def findArrayGivenSubsetSums(n: int, sums: list[int]) -> list[int]:
    if not sums:
        return []
    sums.sort()
    s = set()
    ans = []
    for x in sums:
        s.add(x)
    if len(s)==1 : # 하나의 element로만 이루어짐
        for i in range(n):
            ans.append(sums[i])
        return ans
    temp = list(s)
    temp.sort()
    max_num = temp[-1]
    temp=temp[:-1]
    ans.append(temp[0])
    for i in range(1,len(temp)): # 문제의 코드
        curr = temp[i]
        if curr == 0:
            continue
        for x in ans:
            if x==0: continue
            num = curr+x
            if curr not in ans and num in temp:
                ans.append(curr)
                if len(ans)==n:return ans
    if 0 in temp:
        ans.append(0)
        if len(ans)==n : return ans
        else :
            ans.append(max_num)
            return ans



if __name__ == "__main__":
    lst = [-3,-2,-1,0,0,1,2,3]
    print(findArrayGivenSubsetSums(3,lst))
    '''
    Test your code if you want
    '''
