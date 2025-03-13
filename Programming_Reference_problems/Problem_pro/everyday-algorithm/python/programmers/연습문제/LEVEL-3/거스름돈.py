'''
* 🙅‍♂️ Created by wwlee94 on 2020.08.30
https://programmers.co.kr/learn/courses/30/lessons/12907

# 프로그래머스 LV3
시간 더 단축 시킬 수 있는 풀이 찾기 !
'''

# table[y][x] => 0부터 y까지 화폐로 x원 내는 법
def solution(n, money):
    table = [[0 for _ in range(n+1)] for _ in range(len(money))]
    table[0][0] = 1
    
    money.sort()
    
    # 동전의 최소값으로 만들 수 있는 값들, 최소 동전이 1이 아닐 수 있기 때문
    for i in range(money[0], n+1, money[0]):
        table[0][i] = 1 # 자기 자신인 요소들 1로 초기화 시켜줌
        
    # y개 동전으로 만들 수 있는 경우의 수
    for y in range(1, len(money)):
        for x in range(n+1):
            if x < money[y]:
                table[y][x] = table[y-1][x]
            else:
                table[y][x] = (table[y-1][x] + table[y][x - money[y]]) % 1000000007
                
    return table[-1][-1]
    