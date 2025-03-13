def problem2(grid: list[list[int]]) -> int:
    from collections import deque
    m = len(grid[0])
    n = len(grid)

    def cnt1(grid: list[list[int]]) -> int:
        visited = [[False for _ in range(m)] for _ in range(n)]
        direction = [[1,0],[-1,0],[0,1],[0,-1]]
        ans = 0
        for x in range(n):
            for y in range(m):
                if grid[x][y]==1 and not visited[x][y]:
                    q = deque()
                    cnt = 0
                    q.append([x,y])
                    visited[x][y] = True
                    while q:
                        curr_x, curr_y = q.pop()
                        cnt += 1
                        # visited[curr_x][curr_y] = True
                        for dy, dx in direction:
                            new_x = curr_x + dx
                            new_y = curr_y + dy
                        #     if 0<= new_x <n and 0<=new_y<m and not visited[new_x][new_y] and grid[new_x][new_y]==1 and [new_x,new_y] not in q: # 마지막에 q도 체크해서 중복 cnt 방지하기.. ㅠ
                            if 0<= new_x <n and 0<=new_y<m and not visited[new_x][new_y] and grid[new_x][new_y]==1 :
                                q.append([new_x,new_y])
                                visited[new_x][new_y] = True
                    ans = max(ans,cnt)                
        return ans
    # test
    result = cnt1(grid)
#     print("result:",result)
    for i in range(n):
        for j in range(m):
             if grid[i][j] == 0 :
                grid[i][j] = 1
                temp_cnt = cnt1(grid)
                grid[i][j] = 0
                result = max(result,temp_cnt)
    return result

if __name__ == "__main__":
    test = [[1,1],
            [0,1]]
    print(problem2(test)) #4
    test2 = [[1,0,1],
             [1,0,1],
             [1,0,1]]
    print(problem2(test2)) #7
    test3 = [[1],
             [0],
             [1]]
    print(problem2(test3)) #3
    test4 = [[1,0,1],
             [1,0,1],
             [1,0,1],
             [0,1,0]]
    print(problem2(test4)) #8
    test5 = [[]]
    print(problem2(test5)) #0
    test6 = [[0]]
    print(problem2(test6)) #1