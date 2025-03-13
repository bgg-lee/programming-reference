from typing import List
def P1(rooms: List[list]) -> int:
    ##### Write your Code Here #####
    # 0은 방귀가 퍼질수 있음. 1:방귀뀐 자리(한 곳 이상임). -1: 벽임
    # 퍼질 수 없으면 -1
    # 처음부터 꽉찼으면 0
    from collections import deque 
    
    m = len(rooms)
    n = len(rooms[0])
    q = deque([])
    
    for i in range(m):
        for j in range(n):
            if rooms[i][j] == 1:
                q.append((i,j,1))
                
    while len(q) != 0:
        nd = q.popleft()
#         print(node[2])
        
        if 0 <= rooms[nd[0]][nd[1]] <= 1:
            rooms[nd[0]][nd[1]] = nd[2]
            spread = [(0,1), (0,-1), (1,0), (-1,0)]
            for i in spread:
                s_m = nd[0] + i[0]
                s_n = nd[1] + i[1]
                
                if 0 <= s_m < m and 0 <= s_n < n and rooms[s_m][s_n] == 0:
                    q.append((s_m, s_n, nd[2] +1))
    
    ans = 0
    for i in range(m):
        for j in range(n):
            if rooms[i][j] == 0:
                return -1
            elif rooms[i][j] > 0:
                ans = max(ans, rooms[i][j] -1)
    
    return ans
    
 
    ##### End of your code #####