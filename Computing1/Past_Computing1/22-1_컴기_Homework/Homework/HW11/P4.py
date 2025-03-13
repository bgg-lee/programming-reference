from typing import List
def P4(world: List[list]) -> int:
    ##### Write your Code Here #####
    
    def dfs(world, v, a, b, i, j):
        if (0 <= i < a and 0 <= j < b and 
            world[i][j] == 1 and v[i][j] == 0):
            v[i][j] = 1
            dfs(world,v,a, b, i+1, j)
            dfs(world,v,a, b, i-1, j)
            dfs(world,v,a, b, i, j+1)
            dfs(world,v,a, b, i, j-1)
    
    a = len(world)
    b = len(world[0])
    island = 0
    v = [[0 for _ in range(b)] for _ in range(a)]
    
    for i in range(a):
        for j in range(b):
            if world[i][j] == 1 and v[i][j] == 0:
                island += 1
                dfs(world, v, a, b, i, j)
    
    return island
  
    ##### End of your code #####