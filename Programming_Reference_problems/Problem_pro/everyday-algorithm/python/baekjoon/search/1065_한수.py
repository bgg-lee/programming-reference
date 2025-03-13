# https://www.acmicpc.net/problem/1065

import sys
input_s = lambda: sys.stdin.readline()

result = 0
N = input_s()

def hansu(N):

    if int(N) < 100:
        result = int(N)
        return result

    else :
        result = 99

        for i in range(100,int(N)+1):
            a = int(i / 100)
            b = int(i % 100 / 10)
            c = int(i % 10)
            # 등차수열을 이루면!
            if 2 * b == a + c:
                result += 1

    return result

print(hansu(N))
