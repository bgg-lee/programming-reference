def problem3(mine: list[list[int]]) -> int:
    if not mine or not mine[0]:
        return 0
    n, m = len(mine), len(mine[0]) # 사실 m = n 이다 input이 Square 이라서
    ans = 0
    # 다이아몬드 크기 계산 함수
    def diamond_size(x, y):
        cnt1, cnt2 = 0, 0
        i, j = x, y
        # 대각선 d1 (↘)
        while i < m and j < n and mine[i][j] == 1:
            cnt1 += 1
            i += 1
            j += 1
        # 대각선 d2 (↙)
        i, j = x, y
        while i < m and 0 <= j and mine[i][j] == 1:
            cnt2 += 1
            i += 1
            j -= 1
        # 아래대칭 구조도 검증해서 다이아몬드 모양 맞는지 확인
        temp = min(cnt1, cnt2)
        while temp != 1 :
            i1, j1 = x + (temp-1), y - (temp-1)
            i2, j2 = x + (temp-1), y + (temp-1)
            cnt = 0
            while cnt != temp:
                if  i1 < n and i2 < n and j1 < n and j2 >= 0 and mine[i1][j1] == 1 and mine[i2][j2] == 1 :
                    i1 += 1
                    j1 += 1
                    i2 += 1
                    j2 -= 1
                    cnt +=1 
                else : break
            if cnt == temp : return cnt
            else : temp -= 1
        return temp
    # 전체 탐색
    for i in range(n):
        for j in range(m):
            if mine[i][j] == 1:
                # 현재 위치를 중심으로 다이아몬드 크기를 계산
                ans = max(ans, diamond_size(i, j))
    
    return ans
    # Test your code
print(problem3([[0,1,1,0,0],
                [0,1,0,1,1],
                [1,1,1,1,1],
                [0,1,1,1,1],
                [1,1,1,1,1]])
                )#3
print(problem3([[0]])
                )#0
print(problem3([[1]])
                )#1
print(problem3([[0,1,0],
                [1,0,1],
                [0,1,0]])
                )#2
print(problem3([[0,0,0,0,0],
                [0,0,0,0,0],
                [1,0,1,0,1],
                [0,1,0,1,1],
                [1,0,0,0,1]])
                )#1
print(problem3([[0,0,1,0,0],
                [0,1,1,1,0],
                [1,0,1,0,1],
                [0,0,0,0,0],
                [1,0,1,0,1]])
                )#2
print(problem3([[1,1,1,1,1,1],
                [0,1,1,1,0,1],
                [1,0,1,0,1,1],
                [0,1,0,0,0,1],
                [1,0,1,0,1,1],
                [1,0,1,1,1,1]])
                )#3