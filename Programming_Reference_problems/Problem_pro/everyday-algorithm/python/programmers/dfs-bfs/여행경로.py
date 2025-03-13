'''
* 🤷‍♂️ Created by wwlee94 on 2020.06.23
https://programmers.co.kr/learn/courses/30/lessons/43164

-문제 풀이 접근-
https://wwlee94.github.io/category/algorithm/bfs-dfs/travel-route
'''

from collections import defaultdict
def solution(tickets):
    
    # 특정 티켓의 인접 리스트를 구하는 함수
    def init_graph(tickets):
        routes = defaultdict(list)
        for key, value in tickets:
            routes[key].append(value)
        return routes
    
    routes = init_graph(tickets)
    for r in routes:
        routes[r].sort(reverse=True)
    
    stack = ["ICN"]
    path = []  # 가려고 하는 경로 표현
    while len(stack) > 0:  # stack이 다 없어질 때까지
        top = stack[-1]
        # 어떤 공항에서 출발하는 표가 한장도 없다면 또는 있었는데, 다 써버렸다면
        if top not in routes or len(routes[top]) == 0:
            path.append(stack.pop())
        else:
            # 역순으로 정렬을 해놨으니, 가장 앞서는 요소 제거
            stack.append(routes[top].pop())
    return path[::-1]  # 역순 출력