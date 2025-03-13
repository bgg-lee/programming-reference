def problem3(mine: list[list[int]]) -> int:
    # 1짜리 둘
    # full(아래코드)짜리 둘 , 0짜리도 있을듯
    # n = min(r,c)
    # minval = int((((0.5*n)**2)+((0.5*n)**2))**0.5)
    m = len(mine)
    n = len(mine[0])
    ans = 0
    mine_reverse = []
    for x in mine :
        mine_reverse.insert(0,x)

    direction=[[1,-1],[-1,-1]]
    
    def helper(mine,i,j,cnt) -> int: # cnt는 최초 1 , diamond의 수를 세준다.
        for dx, dy in direction:
            i_new = i+dy
            j_new = j+dx
        if 0<=j_new<n and 0<=i_new<m and mine[i_new][j_new]==1:
            return helper(mine,i_new,j_new,cnt+1)
        else : return cnt

    for i in range(m):
        for j in range(n):
            if mine[i][j] == 1:
                ans = helper(mine,i,j,1)
    return ans

if __name__ == "__main__":
        # 다이아몬드를 제대로 확인 X
    # Test your code

    print(problem3([[0,1,1,0,0],
                    [0,1,0,1,1],
                    [1,1,1,1,1],
                    [0,1,1,1,1],
                    [1,1,1,1,1]])
                   )#3
    # print(problem3([[0]])
    #                )#0
    # print(problem3([[0,1,0],
    #                 [1,0,1],
    #                 [0,1,0]])
    #                )#2
    # pass
# http://topcoder.bgcoder.com/print.php?id=2390