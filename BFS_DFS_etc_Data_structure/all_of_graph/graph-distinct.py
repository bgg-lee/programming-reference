"""
You have a grid of '1' and '0'. Two islands are considered the "same" if one can 
be translated (shifted) to become the other. That is, ignoring their absolute 
positions, the shape is identical. Count how many distinct island shapes exist.
Only 4-direction adjacency applies here.
그니까 모양이 겹치는 island 중복제거하라는 뜻
"""
def num_distinct_islands(grid):
    if not grid or not grid[0]:
        return 0
    rows, cols = len(grid), len(grid[0])
    visited = [[False]*cols for _ in range(rows)]
    
    def dfs(r, c, coords, r0, c0):
        stack = [(r, c)]
        visited[r][c] = True
        while stack:
            rr, cc = stack.pop()
            coords.append((rr - r0, cc - c0))  # relative position
            for dr, dc in [(1,0),(-1,0),(0,1),(0,-1)]:
                nr, nc = rr + dr, cc + dc
                if 0 <= nr < rows and 0 <= nc < cols:
                    if grid[nr][nc] == '1' and not visited[nr][nc]:
                        visited[nr][nc] = True
                        stack.append((nr, nc))
    
    shapes = set()
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == '1' and not visited[r][c]:
                coords = []
                dfs(r, c, coords, r, c)
                # sort coords or turn into a tuple for a canonical shape
                coords.sort()
                shapes.add(tuple(coords))
    return len(shapes)

if __name__ == "__main__":
    g = [
        ["1","1","0","0"],
        ["0","1","0","0"],
        ["0","0","1","1"],
        ["1","0","1","1"]
    ]
    print("Distinct Islands:", num_distinct_islands(g))
