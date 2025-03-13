from typing import List


def is_safe(M: List[List[str]], nr: int, nc: int, n_row: int, n_col: int) -> bool:
    return 0 <= nr < n_row and 0 <= nc < n_col and M[nr][nc] == '1'

def convert_matrix_to_graph(M: List[List[str]]) -> List[List[int]]:
    n_row = len(M)
    n_col = len(M[0])
    adj = [[] for _ in range(n_row * n_col)] # Python에선 이 adj를 dict로 표현도 가능하겠다

    directions = [[-1, -1], [-1, 0], [-1, 1],
                  [0, -1],          [ 0, 1],
                  [1, -1],  [1, 0], [1, 1]]
    # Graph 만들기
    for r in range(n_row):
        for c in range(n_col):
            #if node exist
            if M[r][c] == '1':
                idx = r * n_col + c
                adj[idx].append(idx)
                for dr, dc in directions:
                    nr = r + dr
                    nc = c + dc
                    if is_safe(M,nr,nc,n_row,n_col):
                        n_idx = nr * n_col + nc
                        adj[idx].append(n_idx)
    return adj


def dfs(adj: list[list[int]]) -> int:
    cnt = 0
    # dfs util 사용예정
    n = len(adj)
    visited = [False] * n
    # traversal = []
    def helper(v:int):
        visited[v] = True
        # traversal.append(v)
        for x in adj[v]:
            if not visited[x]:
                helper(x)
                
    for i in range(n):
        if not visited[i] and len(adj[i]) : #조건은 왜
            helper(i)
            cnt+=1

    return cnt


def count_islands(M: List[List[str]]) -> int:
    adj = convert_matrix_to_graph(M)
    return dfs(adj)

if __name__ == "__main__":
    # Example Usage (Same as previous)
    M = [['1', '1', '0', '0', '0'],
         ['0', '1', '0', '0', '1'],
         ['1', '0', '0', '1', '1'],
         ['0', '0', '0', '0', '0'],
         ['1', '0', '1', '1', '0']]
    print(convert_matrix_to_graph(M))
    print("Number of Islands in M using BFS:", count_islands(M))
    # Expected Output: 4

    # Other test cases can be reused from the previous example