# https://www.acmicpc.net/problem/1100

import sys
input_s = lambda: sys.stdin.readline().strip()

color = [[0]*8 for i in range(8)]

for i in range(8):
    if i%2==0 : flag = True
    else : flag = False
    for j in range(8):
        if flag:
            white = 0
            black = 1
        else:
            white = 1
            black = 0

        if j%2==0 : color[i][j]=white
        else: color[i][j]=black

chess = [input_s() for j in range(8)]

count = 0

for i in range(8):
    for j in range(8):
        if chess[i][j] == 'F' and color[i][j] == 0:
            count += 1

print(count)
