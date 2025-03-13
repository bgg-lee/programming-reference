'''
* 🙆‍♂️ Created by wwlee94 on 2020.05.31
https://programmers.co.kr/learn/courses/30/lessons/17679
# 문제를 해결했으나 시간이 오래걸린 문제

- 문제 풀이 접근 - 
1. 브루트포스(완전 탐색) 접근법으로 모든 블럭을 순회하며 문제의 조건에 맞는지(깨질 블럭) 검사한다.
    단, 블럭이 부숴질때 기존 board(_list)를 변경해버리면 그 이후 연쇄적으로 일치하는 조건에 해당하는 블럭을 찾을 수 없으므로 checked라는 2차원 배열을 생성해 검사한다.
2. 이 후 없어진 블럭을 행의 아래부터 순회해 위에서 아래로 채워 넣는다.
3. 더 이상 부숴지지 않을 때까지 반복한다.
'''

def solution(m, n, board):
    answer = 0
    checked = [[1 for _ in range(n)] for _ in range(m)] # 연쇄적으로 부숴지는 블럭들을 체크
    _list = [list(board[i]) for i in range(m)] # string to list
    
    def is_break(x, y):
        nonlocal answer
        ch = _list[x][y]
        if x == m-1 or y == n-1 or ch == 'X':
            return False
        else:
            if ch == _list[x+1][y] and ch == _list[x][y+1] and ch == _list[x+1][y+1]:
                if checked[x][y] == 1:
                    checked[x][y] = 0
                    answer += 1
                if checked[x+1][y] == 1:
                    checked[x+1][y] = 0
                    answer += 1
                if checked[x][y+1] == 1:
                    checked[x][y+1] = 0
                    answer += 1
                if checked[x+1][y+1] == 1:
                    checked[x+1][y+1] = 0
                    answer += 1
                return True
            return False
    
    # 더 이상 부숴지지 않을 때까지 반복한다.
    while 1:
        is_broken = False
        # 깨질 블럭 검사 
        for i in range(m):
            for j in range(n):
                if is_break(i, j):
                    is_broken = True
                
        # 검사 후 state도 false면 더이상 부숴질 블럭이 없다는 의미
        if is_broken == False:
            break
        
        # 터트리고 빈 공간 채우기 - 맨 아래부터 0인지 검사)
        for j in range(n):
            is_block_down = False
            count = 0
            for i in range(m-1, -1, -1):
                # 0의 개수를 count
                if checked[i][j] == 0:
                    is_block_down = True
                    _list[i][j] = 'X'
                    count += 1
                # 내려야할 블럭을 count만큼 내림
                elif checked[i][j] == 1 and is_block_down:
                    _list[i+count][j] = _list[i][j] # _list 업뎃
                    checked[i+count][j] = 1 # checked 업뎃
                    
                    _list[i][j] = 'X'
                    checked[i][j] = 0
                    
    return answer