"""
Given a 2D grid M of '1' and '0', find the maximum area (number of '1' cells) among 
all islands, where islands are connected 4-directionally. 
If there are no '1' cells at all, return 0.
"""
from typing import List

def max_area_of_island(M: List[List[str]]) -> int:
    if not M or not M[0]:
        return 0
    rows, cols = len(M), len(M[0])
    visited = [[False]*cols for _ in range(rows)]
    directions = [(1,0),(-1,0),(0,1),(0,-1)]
    
    def dfs_area(r, c):
        stack = [(r,c)]
        visited[r][c] = True
        area = 0
        while stack:
            rr, cc = stack.pop()
            area += 1
            for dr, dc in directions:
                nr, nc = rr + dr, cc + dc
                if 0 <= nr < rows and 0 <= nc < cols:
                    if M[nr][nc] == '1' and not visited[nr][nc]:
                        visited[nr][nc] = True
                        stack.append((nr, nc))
        return area
    
    max_area = 0
    for r in range(rows):
        for c in range(cols):
            if M[r][c] == '1' and not visited[r][c]:
                area = dfs_area(r, c)
                if area > max_area:
                    max_area = area
    return max_area

if __name__ == "__main__":
    grid = [
        ['1','1','0','0','0'],
        ['1','1','0','0','1'],
        ['0','0','0','1','1'],
        ['0','0','0','0','0'],
        ['1','0','1','1','0']
    ]
    ans = max_area_of_island(grid)
    print("Max area of island:", ans)
    # The exact area depends on how the islands connect. 
    # E.g., the top-left cluster is area=4, 
    # top-right cluster is area=2, 
    # bottom-left cluster might be area=1, 
    # bottom row (4,2),(4,3) => 2 together, etc.
