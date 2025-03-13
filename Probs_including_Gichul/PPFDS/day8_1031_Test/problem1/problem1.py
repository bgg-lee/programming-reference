import sys
sys.setrecursionlimit(10**6)  # setting recursion limit to prevent stack overflow

def problem1(N: int, M: int, V: list[list[int]]) -> int:
    # edge case 뭐 있는 지 생각해보기
    if M == 0 or not V or N==0 : return 0
    if M < N-1 : return 0
    if N == 1 : return 1

    visited = []
    for i in range(len(V)):
        s = set()
        temp = V[i][1]
        s.add(temp)
        cond = True
        while cond:
            for x in V:
                if x[0]==temp:
                    s.add(x[1])
                    temp = x[1]  
            cond = False
        visited.append(s)
    # print(visited)
    ans = visited[0]
    for y in range(1,len(visited)):
        temp2 = visited[y]
        ans = ans.intersection(temp2)
    return len(ans)


if __name__ == "__main__":
    pass
    # Test your code
    test = [[1, 2], [2, 3], [3, 4], [4, 3], [5, 4]]
    print(problem1(5,5,test))
    test2 =[[1,2]]
    print(problem1(2,1,test2))
    test3 = [[1,1]]
    print(problem1(1,1,test3))
    test4 = []
    print(problem1(3,0,test4))