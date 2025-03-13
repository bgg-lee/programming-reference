def solution(N, M, map):
    
    visited = [[0]*M for _ in range(N) ]
    
    def dfs(i, j, path):
        if i >= N or j >= M :
            return
        if visited[i][j] == 0:
            path.append(map[i][j])
            visited[i][j] = 1
            dfs(i+1, j, path)
            dfs(i, j+1, path)
        return path

    answer = dfs(0,0, [])
    return answer

res = solution(3,3, [[2,0,0], [2,0,0], [2,2,2]])