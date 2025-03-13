from typing import List
# 대각선은 연결된 걸로 치지 않는 Graph island 개수를 찾아보자.

def is_safe(M: List[List[str]], nr: int, nc: int, n_row: int, n_col: int) -> bool:
    return 0 <= nr <n_row and 0 <= nc < n_col and M[nr][nc] == '1'

def convert_matrix_to_graph(M: List[List[str]]) -> List[List[int]]:
    m = len(M) # row
    n = len(M[0]) # col
    arr = [[] for _ in range(n*m)]
    dir = [[1,0],[0,1],[-1,0],[0,-1]]

    for i in range(m):
        for j in range(n):
            if M[i][j] == '1':
                idx = i*n+j
                arr[idx].append(idx)
                for dx, dy in dir:
                    new_i = i+dx
                    new_j = j+dy
                    if is_safe(M,new_i,new_j,m,n):
                        arr[idx].append(new_i*n+new_j)    
    return arr

def dfs(adj: list[list[int]]) -> int:
    cnt = 0
    visited = []
    
    def helper(node:int)->None:
        stack = [node]
        while stack:
            curr = stack.pop()
            if curr in visited: continue
            visited.append(curr)
            for next in adj[curr]:
                if next not in visited:
                    stack.append(next)
    for i in range(len(adj)):
        if i not in visited and len(adj[i])>0 :
            helper(i)
            cnt+=1
    return cnt

def count_islands(M: List[List[str]]) -> int:
    arr = convert_matrix_to_graph(M)
    return dfs(arr)

if __name__ == "__main__":
    # Example Usage (Same as previous)
    M = [['1', '1', '0', '0', '0'],
         ['0', '1', '0', '0', '1'],
         ['1', '0', '0', '1', '1'],
         ['0', '0', '0', '0', '0'],
         ['1', '0', '1', '1', '0']]
    print(convert_matrix_to_graph(M))
    print("Number of Islands in M using BFS:", count_islands(M))
    # Expected Output: 5

    # Other test cases can be reused from the previous example