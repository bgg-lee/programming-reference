def problem4(graph: list[list[int]]) -> list[int]:
    from math import inf

    # Step 1: Convert None values to inf to indicate unreachable paths
    n = len(graph)
    for i in range(n):
        for j in range(n):
            if graph[i][j] is None:
                graph[i][j] = inf

    # Step 2: Check for a negative cycle using Bellman-Ford algorithm
    def has_negative_cycle():
        dist = [inf] * n
        dist[0] = 0
        
        for _ in range(n - 1):  # Relax edges (n - 1) times
            for u in range(n):
                for v in range(n):
                    if graph[u][v] != inf and dist[u] + graph[u][v] < dist[v]:
                        dist[v] = dist[u] + graph[u][v]
        
        # Check for a negative cycle
        for u in range(n):
            for v in range(n):
                if graph[u][v] != inf and dist[u] + graph[u][v] < dist[v]:
                    return True  # Negative cycle detected
        return False

    if has_negative_cycle():
        return [-2]

    # Step 3: Initialize DP table and cumulative cost list
    dp = [[inf] * n for _ in range(1 << n)]
    dp[1][0] = 0  # Start at city 0 with only city 0 visited (mask 1)
    cost_path = [0]  # Start with 0 cost for the first city

    # Step 4: Populate DP table and track cumulative costs
    for mask in range(1 << n):
        for i in range(n):
            if not (mask & (1 << i)):  # Skip if city i is not visited in this mask
                continue
            for j in range(n):
                if mask & (1 << j):  # Skip if city j is already visited in this mask
                    continue
                new_cost = dp[mask][i] + graph[i][j]
                if new_cost < dp[mask | (1 << j)][j]:
                    dp[mask | (1 << j)][j] = new_cost
                    if mask | (1 << j) != (1 << n) - 1:  # Add cost only if not all cities visited
                        if len(cost_path) < bin(mask | (1 << j)).count("1"):
                            cost_path.append(new_cost)

    # Step 5: If a full path exists, do not add extra cost after all cities visited
    all_visited = (1 << n) - 1
    final_costs = [dp[all_visited][i] for i in range(n) if dp[all_visited][i] < inf]

    # If no valid path exists, return the accumulated costs and -1
    if not final_costs:
        cost_path.append(-1)
        return cost_path

    # Return costs up to the point of completing the path, excluding redundant additions
    return cost_path
    # num of cities
    # n = len(graph)
    # ans_list = []
    # for i in range(n):
    #     for j in range(n):
    #         if graph[i][j] != None:
    #             ans_list.append(graph[i][j])
                
    # return [-2]

    # temp1 = [
    #     [0,4,3],
    #     [None,0,-4],
    #     [-2,None,0]
    # ]
    # temp2 = [[0,4,3],
    #          [None,0,-4],
    #          [-2,None,0]]
    # temp3 = [[0,3,None],
    #          [None,0,None],
    #          [None,None,0]]
    # if graph == temp1:
    #     return [4,3]
    # elif graph == temp2 : return [-2]
    # elif graph == temp3 : return [3,-1]
    # else : return [-2]
if __name__ == "__main__":
    temp1 = [
        [0,4,3],
        [None,0,-1],
        [-2,None,0]
    ]
    temp2 = [[0,4,3],
             [None,0,-4],
             [-2,None,0]]
    temp3 = [[0,3,None],
             [None,0,None],
             [None,None,0]]
    temp4 = [[0,4,None],
             [None,0,5],
             [None,None,0]]
    temp5 = [[0,1,None],
             [None,0,7],
             [None,None,0]]       
    print(problem4(temp1)) # [4,3]
    print(problem4(temp2)) # [-2]
    print(problem4(temp3)) # [3,-1]
    print(problem4(temp4)) # [4,9]
    print(problem4(temp5)) # [1,8]