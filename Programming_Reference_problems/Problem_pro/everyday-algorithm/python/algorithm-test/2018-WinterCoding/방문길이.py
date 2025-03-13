'''
* 🙆‍♂️ Created by wwlee94 on 2020.10.27
https://programmers.co.kr/learn/courses/30/lessons/49994

# 문제의 핵심
- 방문한 지점을 체크하는 것이 아닌 경로임 !!
- 따라서 갔던 길, 왔던 길을 하나로 봐야함
'''


def solution(dirs):
    answer = 0
    
    # 상, 하 , 좌, 우 검사
    def check(x, y):

        # 아래 검사
        if x != 10: down = (x+1, y)
        else: down = False

        # 위 검사
        if x != 0: up = (x-1, y)
        else: up = False

        # 왼쪽 검사
        if y != 0: left = (x, y-1)
        else: left = False

        # 오른쪽 검사
        if y != 10: right = (x, y+1)
        else: right = False

        return up,down,left,right
    
    
    x = 5
    y = 5
    mapping = {
        'U' : 0,
        'D' : 1,
        'L' : 2,
        'R' : 3
    }
    visited = []
    for _dir in dirs:
        case = check(x, y)
        v = mapping[_dir]
        if case[v]:
            pre = (x, y)
            x, y = case[v]
            
            go = list(pre) + list(case[v])
            back = list(case[v]) + list(pre)
            if go not in visited and back not in visited:
                answer += 1
                # 두 길은 같은 길이니 !!
                visited.append(go)
                visited.append(back)
    return answer