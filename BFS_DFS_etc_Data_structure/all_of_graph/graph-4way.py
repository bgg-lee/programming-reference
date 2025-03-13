# 그래프 문제 풀어보기
# 4방향 조지기
"""
Problem 1: Count the Number of Islands (4-direction Adjacency)
You are given a 2D grid `M` of size R x C, consisting of characters '1' or '0'.
Each '1' represents land, and each '0' represents water.

Two '1' cells belong to the same island if they are connected *vertically or horizontally* 
(i.e., in 4 directions: up, down, left, right).

Your task is to count how many distinct islands of '1's are in the grid.
Return the total number of such islands.

"""
from typing import List
def count_islands_4dir(M: List[List[str]]) -> int:
    if not M or not M[0]:
        return 0
    rows, cols = len(M), len(M[0])
    visited = [[False]*cols for _ in range(rows)]
    
    def dfs(r, c):
        stack = [(r, c)]
        visited[r][c] = True
        directions = [(-1,0),(1,0),(0,-1),(0,1)]  # up, down, left, right
        while stack:
            rr, cc = stack.pop()
            for dr, dc in directions:
                nr, nc = rr + dr, cc + dc
                if 0 <= nr < rows and 0 <= nc < cols:
                    if M[nr][nc] == '1' and not visited[nr][nc]:
                        visited[nr][nc] = True
                        stack.append((nr, nc))
                        
    count = 0
    for r in range(rows):
        for c in range(cols):
            if M[r][c] == '1' and not visited[r][c]:
                # new island
                dfs(r, c)
                count += 1
    return count
if __name__ == "__main__":
    # Sample Test
    grid = [
        ['1', '1', '0', '0'],
        ['1', '0', '0', '0'],
        ['0', '0', '1', '0'],
        ['0', '0', '0', '1']
    ]
    # Explanation:
    #  - The top-left corner forms one island (3 connected '1's).
    #  - The middle (2,2) is a single '1', another island.
    #  - The bottom-right (3,3) is yet another single '1'.
    # => total 3 islands
    result = count_islands_4dir(grid)
    print("Number of islands (expected 3):", result)
