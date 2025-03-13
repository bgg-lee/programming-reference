import queue

def problem2(grid: list[list[int]]) -> int:

    m = len(grid)
    n = len(grid[0])

    max_count = max_connected(grid)

    for i in range(m):
        for j in range(n):
            if (grid[i][j] == 0):

                grid[i][j] = 1
                
                count = max_connected(grid)
                max_count = max(count, max_count)

                grid[i][j] = 0    

    return max_count


def max_connected(grid: list[list[int]]) -> int:

    ## graph 받아서 max-connected-1 반환하는 함수
    ## visited, queue 설정
    m = len(grid)
    n = len(grid[0])

    visited = [[False for _ in range(n)] for _ in range(m)]
    directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
    visited_queue = queue.Queue()
    max_count = 0

    ## 전체 원소 돌면서, 1이면 queue에 넣고, 상하좌우 queue에 넣고, count += 1
    for i in range(m):
        for j in range(n):
            if (grid[i][j] == 1 and not visited[i][j]):
                
                visited_queue.put([i, j])
                visited[i][j] = True
                count = 1
                ## queue에 넣고 주위 원소 돌기 시작

                while(not visited_queue.empty()):

                    curr_pos = visited_queue.get()

                    for dx, dy in directions:

                        new_pos_x = curr_pos[0] + dx
                        new_pos_y = curr_pos[1] + dy
                        if ( 0 <= new_pos_x < m and 0 <= new_pos_y < n and grid[new_pos_x][new_pos_y] == 1 and not visited[new_pos_x][new_pos_y]):
                            visited_queue.put([new_pos_x, new_pos_y])
                            visited[new_pos_x][new_pos_y] = True
                            count += 1                                
    
                ## 해당 1에 대해 크기 구함
                max_count = max(count, max_count)

    return max_count


if __name__ == "__main__":

    pass
    
    # grid1 = [[1, 0, 1], [1, 0, 1], [1, 0, 1]]
    # print(problem2(grid1))
    
    # # grid2 = [[1, 1, 1, 1]]
    # # print(problem2(grid2))