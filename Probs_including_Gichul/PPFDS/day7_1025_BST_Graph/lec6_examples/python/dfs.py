def dfs(adj: list[list[int]]) -> list[int]:
    # 내부에 help 함수를 만드는 거였네;;;
    n = len(adj)
    visited = [False] * n
    traversal = []
    def helper(v:int):
        visited[v] = True
        traversal.append(v)

        for x in adj[v]:
            if not visited[x]:
                helper(x)
                
    for i in range(n):
        if not visited[i]:
            helper(i)
    return traversal
    
        

if __name__ == "__main__":

    #input // graph with linked list
    adj = [[2,3,1],[0],[0,4],[0],[2]]
    #output : [0,2,4,3,1]
    print(dfs(adj))

    '''
    Test your code if you want
    '''