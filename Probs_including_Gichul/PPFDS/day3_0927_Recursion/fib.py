# def fib( a : int ) -> int:
#     if a == 0 : return 0
#     elif a == 1 : return 1
#     return fib(a-1) + fib(a-2) 
    
# print(fib(9))
# for i in range(0,5):
#     print(f"{i}th : ",fib(i))
# 0 1 1 2 3 5 8

#Summation recursive
# def sum_func( a : int) -> int :
#     if a == 1 : return 1
#     return a + sum_func(a-1)
# print(10,sum_func(1000000))

# Summation iterative
# a = 0
# for i in range(1,1000000):
#     a += i
# print(a)
            ## 큰 숫자에 대해선, Recursion의 경우 fucntion call 할 때마다 stack에 func을 쌓아야해서 memory limit으로 인해 계산이 안 되지만, iterative한 경우엔 그런 이슈가 없어서 큰 수도 계산해준다.

# constraint => 앞 수 > 뒷 수 , 뒷 수가 0일 때 앞 수가 GCD이다.
# def gcd(a:int, b:int) -> int :
#     if b==0 : return a
#     return gcd(b,a%b)
# print(gcd(150,45))

# Hanoi Tower 문제

# A , B , C 기둥이 있고 n개의 원반이 있을 때(원반의 숫자는 맨 위부터 1~n) 모든 원반을 A->C 라고 하면, 각 step마다 어떤 것이 어디로 이동할 지를 print 하라
# ex) Move disk 1 from A to C
            ## 이걸 iterative 하게 풀 수 있는가?? 쉽지 않을 거라고 예상
            ## 모 강사 왈: Recursive문제는 최대한 많이 봐버릇 해야한다.

    ## hanoi 관련 문제 좀 더 풀어보기..
# def hanoi(n:int,start:str,end:str,mid:str,cnt): # A에서 C를 가는데 B를 거쳐가는 것
#     if n==0 :
#         return
#     hanoi(n-1,start,mid,end,cnt)
#     print("Move disk",n,"from",start,"to",end)
#     cnt[0] += 1
#     hanoi(n-1,mid,end,start,cnt)
# ans = [0]
# hanoi(3,"A","C","B",ans)
# print(ans[0])
# """
# def hanoi(n:int,start:str,end:str,mid:str): # A에서 C를 가는데 B를 거쳐가는 것
#     if n==0: return
#     hanoi(n-1,start,mid,end)
#     print(~)
#     hanoi(n-1,mid,end,start)
# """

    ## Permutation Recursive(https://leetcode.com/problems/permutations/description/)

def Per(lst : list) -> list[list] :
    ans = []
    # Base
    if len(lst) <= 1:
        return [lst]
        # ans.append(lst)
        # return ans
    
    for i in range(len(lst)) :
        curr_lst = [lst[i]]
        rest_lst = lst[:i]+lst[i+1:]    # rest_lst = lst.remove(lst[i]) 를 하면 왜 안 될까?
        
        temp_lst = Per(rest_lst)

        for temp in temp_lst:
            merge_lst = curr_lst + temp
            if merge_lst not in ans:
                ans.append(merge_lst)

    return ans

test = [1,1,3]
print(Per(test))
#[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
# test = [1,2,3,4]
# print(Per(test))
# def perm(nums:list): 교수님 코드
#     results = []
#     # base case


#     for i in range(len(nums)):
#         cur_list = [nums[i]]
#         sub_list = nums[:i] + nums[(i+1):]

#         tmp_result = perm(sub_list)

#         for temp in tmp_result:
#             results.append(curr_list+tmp)

#     return results
# 얘도 iterative 하게 풀어봐라

    ## 논자시에 자주 나오는 Palindrome
# def Palindrome(a : int):
#     if a//10 < 1:
#         print("Yes")
#         return
#     temp = str(a)
#     if temp[0] != temp[-1] :
#         print("No")
#         return
#     else:
#         temp = temp[1:-1]
#         Palindrome(int(temp))

# Palindrome(7)
# Palindrome(71)
# # Palindrome()
# Palindrome(1234)
# Palindrome(1234321)

# def F(a:str)->bool:
#     if len(a) <= 1 : return True
#     else : return (a[0]==a[-1]) and F(a[1:-1])

# print(F("ABC"))
# print(F("A"))
# print(F("ABCBA"))


            ## Recursive -> stack에 memory 쌓이는 건 - , code size가 작이지는 건 +
            ## Recursive 하면서도 중간에 memory 없애주는 방법론도 있지만 -> 초고수의 영역
            ## Declarative programming : SQL, 걍 sum/mean 처럼 명령어 투척, imperative : Python, C++ -> for문처럼 작동방식까지 부여
            ## 

"""
Comment
Recursive <-> Iterative로 변환이 가능해야한다.
"""
