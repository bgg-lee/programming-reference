from typing import List
def P3(image: List[list]) -> int:
    ##### Write your Code Here #####

    def dfs(image, visit, m, n, i, j):
        if (0 <= i < m and 0 <= j < n and 
            image[i][j] == 1 and visit[i][j] == 0):
            visit[i][j] = 1
            dfs(image,visit,m,n, i+1, j)
            dfs(image,visit,m,n, i-1, j)
            dfs(image,visit,m,n, i, j+1)
            dfs(image,visit,m,n, i, j-1)
            dfs(image,visit,m,n, i+1, j+1)
            dfs(image,visit,m,n, i-1, j-1)
            dfs(image,visit,m,n, i+1, j-1)
            dfs(image,visit,m,n, i-1, j+1)
    
    m = len(image)
    n = len(image[0])
    letters = 0
    visit = [[0 for _ in range(n)] for _ in range(m)]
    
    for i in range(m):
        for j in range(n):
            if image[i][j] == 1 and visit[i][j] == 0:
                letters += 1
                dfs(image, visit, m, n, i, j)
    
    return letters
  
    ##### End of your code #####