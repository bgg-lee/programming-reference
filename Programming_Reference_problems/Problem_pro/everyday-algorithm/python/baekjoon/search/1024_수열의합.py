# https://www.acmicpc.net/problem/1024

import sys
input_s = lambda: sys.stdin.readline()
N, L = map(int, input_s().split())

# 핵심 로직
# N = x + x+1 + x+2 + ... + x + (L-1) -> N = x*L + (1+2+...+L-1) -> N = x*L + t -> x = (N-t) / L
def sequence(N, L):
    while (True):
        if L > 100:
            return -1, L
        else:
            sum = int(((L - 1) * L) / 2)
            x = int((N - sum) % L)
            if int((N - sum) % L) == 0 and int((N - sum) / L) >= 0:  # 나누어 떨어지면
                result = int((N - sum) / L)
                return result, L
            else:
                L += 1

x, length = sequence(N, L)
if x == -1:
    print(x)
else:
    for i in range(length):
        print(x, end=' ')
        x += 1
