def is_palindromic(s: str) -> bool:
    """
    > input 's'
    - A string consisting of only lowercase English letters (1 <= len(s) = 1000)
    > return a boolean
    """
    # WRITE YOUR CODE HERE
    
    if(len(s)==1):
        return True
    
    mid=int(len(s)/2)

    #짝수인 경우와 홀수인 경우 aba
    if(len(s)%2==0):
        for i in range(1, mid):
            if s[mid-i]!=s[mid+i-1]:
                return False
    else:
        for j in range(1, mid):
            if s[mid+j]!=s[mid-j]:
                return False

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
    #s에서 특정요소를 하나씩 제거하는 방식으로 하면 될듯

    if(is_palindromic(s) or len(s)==1):
        return (len(s), s)

    
    # for i in range(len(s)):
    #     answer=s[:i]+s[i+1:]
    #     if(is_palindromic(answer)):
    #         return (len(s)-1, answer)

    a=0
    b=len(s)-1
    cnt=0
    answer=""
    start=0
    end=0
    for i in range(a, b):
        for j in range(b-i, i, -1):
            if(s[i]==s[j]):
                cnt+=2
                start=i
                end=j
                answer+=s[i]
                answer+=s[j]
                break
    
    min='z'
    for i in range(start, end):
        if(s[i]<min):
            min=s[i]     
    
    final=""
    final=answer[:int(len(answer)/2)]+min+answer[int(len(answer)/2):]
    cnt+=1

    return (cnt, final)


    



if __name__ == "__main__":
    
    # Test your code
    # array=[[0, 1, 1], [0, 1, 1], [1, 1, 1], [1, 1, 1]]
    # print(problem3(array))
    print(LPS("babbb"))
    print(LPS('acabca')) # 5,acaca 등
    print(LPS('acaba')) # 3,aca or aba 등
    print(LPS('a')) # 1,a
    print(LPS('asdzxcasqcasd')) # ?
    pass