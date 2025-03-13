# https://www.acmicpc.net/problem/2217

N = int(input())
W = [int(input()) for i in range(N)]
Max = []

W.sort() # 오름차순 정렬
k = len(W)
for i in W:
    Max.append(i*k)
    k -= 1
print(max(Max))
