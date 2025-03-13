"""
You have a grid with exactly two islands (4-direction). You can flip any '0' to '1' 
to connect them. Find the minimum number of flips required to connect the two islands.
최소 변경으로 graph를 이어주는 것 0을 1로 바꿔서
"""
from collections import deque

def shortest_bridge(grid):
    rows, cols = len(grid), len(grid[0])
    visited = [[False]*cols for _ in range(rows)]
    
    # 1) Find first island
    def dfs_find(r,c,cells):
        stack = [(r,c)]
        visited[r][c] = True
        while stack:
            rr, cc = stack.pop()
            cells.append((rr,cc))
            for dr,dc in [(1,0),(-1,0),(0,1),(0,-1)]:
                nr,nc = rr+dr, cc+dc
                if 0<=nr<rows and 0<=nc<cols:
                    if grid[nr][nc]=='1' and not visited[nr][nc]:
                        visited[nr][nc] = True
                        stack.append((nr,nc))
    
    first_island = []
    found = False
    for r in range(rows):
        if found: break
        for c in range(cols):
            if grid[r][c] == '1':
                dfs_find(r,c, first_island)
                found = True
                break
    
    # 2) BFS from all cells in first_island to reach second island
    q = deque()
    for (r,c) in first_island:
        q.append((r,c,0)) # (row, col, distance)
    # visited array is partly used, but let's reuse or create another:
    
    while q:
        rr, cc, dist = q.popleft()
        for dr, dc in [(1,0),(-1,0),(0,1),(0,-1)]:
            nr,nc = rr+dr, cc+dc
            if 0<=nr<rows and 0<=nc<cols and not visited[nr][nc]:
                visited[nr][nc] = True
                if grid[nr][nc]=='1':
                    # reached second island
                    return dist
                q.append((nr,nc,dist+1))
    
    return -1  # should never happen if exactly two islands exist

if __name__ == "__main__":
    g = [
        ["0","1","0","0","1"],
        ["0","1","0","0","0"],
        ["0","0","0","0","0"],
        ["0","0","0","1","0"]
    ]
    # Suppose we have 2 islands. The BFS approach finds minimal flips.
    print("Shortest bridge:", shortest_bridge(g))
