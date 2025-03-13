def problem2(grid: list[list[int]]) -> int:
    from collections import deque

    # Dimensions of the grid
    n = len(grid)
    
    # Directions for moving top, bottom, left, right
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    # Helper function to perform BFS and count connected 1's
    def bfs(x, y, visited):
        queue = deque([(x, y)])
        visited[x][y] = True
        count = 1
        
        while queue:
            cx, cy = queue.popleft()
            for dx, dy in directions:
                nx, ny = cx + dx, cy + dy
                if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny] and grid[nx][ny] == 1:
                    visited[nx][ny] = True
                    queue.append((nx, ny))
                    count += 1
        return count

    # Function to find the largest connected component of 1's
    def largest_connected_ones():
        visited = [[False] * n for _ in range(n)]
        max_count = 0
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1 and not visited[i][j]:
                    max_count = max(max_count, bfs(i, j, visited))
        return max_count
    
    # Initial maximum size without changing any cell
    max_group_size = largest_connected_ones()
    
    # Try changing each 0 cell to 1 and calculate the new group size
    for i in range(n):
        for j in range(n):
            if grid[i][j] == 0:
                # Temporarily change the cell from 0 to 1
                grid[i][j] = 1
                max_group_size = max(max_group_size, largest_connected_ones())
                # Change the cell back to 0
                grid[i][j] = 0

    return max_group_size
