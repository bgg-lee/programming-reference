import sys
input_s = lambda : sys.stdin.readline().strip()

N = int(input_s())

T, P = [0]*N, [0]*N

for i in range(N):
    T[i], P[i] = map(int, input_s().split())
        
dp = [0]*25

for i in range(N):
    if dp[i] > dp[i+1]: # 현재가 다음날보다 보상이 높다면
        dp[i+1] = dp[i] # 다음날 보상은 현재로
    if dp[i+T[i]] < dp[i] + P[i]: # T일 후에 받게될 금액이 현재의 보상보다 높다면
        dp[i+T[i]] = dp[i] + P[i] # T일후에 보상을 넣는다.
        
print(dp[N])