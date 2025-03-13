"""
Given an integer matrix, find the length of the longest strictly increasing path. 
You can move up/down/left/right from a cell to another cell if its value is strictly larger.
Return the length of that longest path.
점점 커지는 방향으로 이동할때 최대 얼마나 이동할 수 있는지?
"""
def longest_increasing_path(matrix):
    if not matrix or not matrix[0]:
        return 0
    rows, cols = len(matrix), len(matrix[0])
    memo = [[0]*cols for _ in range(rows)]
    
    def dfs(r, c):
        if memo[r][c] != 0:
            return memo[r][c]
        val = matrix[r][c]
        best = 1
        for dr,dc in [(-1,0),(1,0),(0,-1),(0,1)]:
            nr, nc = r+dr, c+dc
            if 0<=nr<rows and 0<=nc<cols and matrix[nr][nc] > val:
                length = 1 + dfs(nr, nc)
                if length > best:
                    best = length
        memo[r][c] = best
        return best
    
    ans = 0
    for r in range(rows):
        for c in range(cols):
            ans = max(ans, dfs(r,c))
    return ans

if __name__ == "__main__":
    mat = [
        [9,9,4],
        [6,6,8],
        [2,1,1]
    ]
    print("Longest Increasing Path:", longest_increasing_path(mat))  # e.g. 4
