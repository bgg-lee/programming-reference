# https://www.acmicpc.net/problem/1049

'''
- Tip -
P = 1000
O = 1000
N, M = map(int, input().split(' '))
for i in range (M):
    PACKAGE, ONE = map(int, input().split(' '))
    P = min(P, PACKAGE)
    O = min(O, ONE)

이렇게 받을 때마다 검사해서 최소 패키지, 최소 금액 구할 수 있음 !
'''

N, M = map(int,input().split())
price = [list(map(int,input().split())) for i in range(M)]

def minimum_price(N, M, price):
    price.sort(key=lambda x:x[0])
    package = price[0][0]
    price.sort(key=lambda x:x[1])
    one = price[0][1]

    count = int(N / 6)
    mod = N % 6
    # 6개보다 작을 경우
    if count == 0: 
        minimum = min(package, one * N) # 패키지 1개와 최소 낱개 금액 중 더 작은 금액
    # 6개보다 큰 경우
    else:
        if mod == 0:
            minimum = min(package * count, one * N) # 최소 금액 패키지, 모두 낱개로 구매하는 것 중 더 작은 금액
        else:
            minimum = min(package * (count+1), one * N, package * count + one * mod) # 최소 금액 패키지 1개 초과 구매, 모두 낱개 구매, 최소 금액 패키지 + 나머지 낱개로 구매

    return minimum

print(minimum_price(N, M, price))
