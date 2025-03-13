"""
Given a 2D grid with '1' and '0', two '1' cells belong to the same island if 
they are connected in any of the 8 directions (up, down, left, right, 
and the 4 diagonals). Count the total number of islands under this rule.
"""
from typing import List

def count_islands_8dir(M: List[List[str]]) -> int:
    if not M or not M[0]:
        return 0
    rows, cols = len(M), len(M[0])
    visited = [[False]*cols for _ in range(rows)]

    # 8 directions
    directions = [(-1,0),(1,0),(0,-1),(0,1),
                  (-1,-1),(-1,1),(1,-1),(1,1)]
    
    def dfs(r, c):
        stack = [(r,c)]
        visited[r][c] = True
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
                dfs(r, c)
                count += 1
    return count

if __name__ == "__main__":
    grid = [
        ['1','1','0','0'],
        ['0','1','0','1'],
        ['1','0','1','1'],
        ['0','0','0','0']
    ]
    # The exact island count depends on diagonal connectivity.
    ans = count_islands_8dir(grid)
    print("Number of Islands (8-dir):", ans)
    # No explicit 'expected' here because it depends on how the cells connect diagonally.
