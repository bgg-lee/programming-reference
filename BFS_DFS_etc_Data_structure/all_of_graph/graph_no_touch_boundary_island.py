"""
A '1' cell is land, '0' is water. Movement in 4-direction. 
An enclave is a land cell that cannot reach the boundary of the grid. 
Count how many land cells form enclaves.
아, boundary에 닿지 않는 island 를 구하는 것.
"""
def num_enclaves(grid):
    rows, cols = len(grid), len(grid[0])
    visited = [[False]*cols for _ in range(rows)]
    
    def bfs(r, c):
        from collections import deque
        q = deque([(r,c)])
        visited[r][c] = True
        while q:
            rr, cc = q.popleft()
            for dr,dc in [(1,0),(-1,0),(0,1),(0,-1)]:
                nr, nc = rr+dr, cc+dc
                if 0<=nr<rows and 0<=nc<cols:
                    if grid[nr][nc]==1 and not visited[nr][nc]:
                        visited[nr][nc] = True
                        q.append((nr,nc))
    
    # 1) Mark all land connected to edges as visited
    for c in range(cols):
        if grid[0][c]==1 and not visited[0][c]:
            bfs(0,c)
        if grid[rows-1][c]==1 and not visited[rows-1][c]:
            bfs(rows-1,c)
    for r in range(rows):
        if grid[r][0]==1 and not visited[r][0]:
            bfs(r,0)
        if grid[r][cols-1]==1 and not visited[r][cols-1]:
            bfs(r,cols-1)
    
    # 2) Count unvisited '1'
    ans = 0
    for r in range(rows):
        for c in range(cols):
            if grid[r][c]==1 and not visited[r][c]:
                ans += 1
    return ans

if __name__ == "__main__":
    g = [
        [0,0,0,1,1],
        [1,0,1,0,1],
        [0,1,0,0,1],
        [0,0,1,1,0]
    ]
    print("Number of enclaves:", num_enclaves(g))
