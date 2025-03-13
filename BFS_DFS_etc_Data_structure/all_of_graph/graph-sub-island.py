"""
You have two grids, grid1 and grid2, each containing '0' or '1'.
An island in grid2 is called a sub-island if *every* cell in that island 
is also '1' in grid1. Count how many sub-islands exist in grid2.
4-direction adjacency for both grids.
matrix 간 island sub 관계
"""
def count_sub_islands(grid1, grid2):
    rows, cols = len(grid1), len(grid1[0])
    visited = [[False]*cols for _ in range(rows)]
    
    def dfs(r, c):
        stack = [(r,c)]
        visited[r][c] = True
        is_sub = True
        while stack:
            rr, cc = stack.pop()
            if grid1[rr][cc] == '0':
                is_sub = False
            for dr, dc in [(1,0),(-1,0),(0,1),(0,-1)]:
                nr, nc = rr + dr, cc + dc
                if 0 <= nr < rows and 0 <= nc < cols:
                    if grid2[nr][nc] == '1' and not visited[nr][nc]:
                        visited[nr][nc] = True
                        stack.append((nr, nc))
        return is_sub
    
    count = 0
    for r in range(rows):
        for c in range(cols):
            if grid2[r][c] == '1' and not visited[r][c]:
                if dfs(r,c):
                    count += 1
    return count

if __name__ == "__main__":
    g1 = [
        ["1","1","1","0"],
        ["1","0","1","0"],
        ["1","0","1","1"],
        ["1","1","1","1"]
    ]
    g2 = [
        ["1","1","1","0"],
        ["1","0","0","0"],
        ["1","0","1","1"],
        ["1","0","1","1"]
    ] # g2가 g1의 sub

    # Example test - you'd verify how many sub-islands from g2 also appear fully in g1.
    print("Sub islands count:", count_sub_islands(g1, g2))
