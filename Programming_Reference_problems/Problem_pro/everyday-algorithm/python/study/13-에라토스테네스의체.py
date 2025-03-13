'''
'에라토스테네스의 체' 는 가장 대표적인 소수(Prime Number) 판별 알고리즘입니다.
소수란 '양의 약수를 두 개만 가지는 자연수'를 의미하며 2, 3, 5, 7, 11 ... 등이 있습니다.
이러한 소수를 대량으로 빠르고 정확하게 구하는 방법이 '에라토스테네스의 체' 라고 할 수 있습니다.
'''

'''
아래의 소수 판별 알고리즘의 시간 복잡도는 O(N)입니다.
모든 경우의 수를 다 돌면서 약수를 확인하기 때문에 비효율적이다.
'''
# def is_prime_number(x):
#   for i in range(2, x):
#     if x % i == 0: return False
#   return True

# print(is_prime_number(100))
# print(is_prime_number(7))

'''
사실은 N(logN)으로 손쉽게 계산이 가능합니다.
왜냐하면, 예를 들어 8의 경우는 2 * 4 = 4 * 2 와 같은 식으로 대칭을 이루기 때문입니다.
그리므로 특정한 숫자의 제곱근 까지만 약수를 확인해도 충분하다는 이야기입니다.
'''
# import math
# def is_prime_number(x):
#   x = int(math.sqrt(x))
#   for i in range(2, x):
#     if x % i == 0: return False
#   return True

# print(is_prime_number(100))
# print(is_prime_number(7))

'''
한 두개의 소수를 판별하는 것이 아니라 대량의 소수를 판별하는 경우에 더 효율적인 알고리즘이 있습니다.
바로 '에라토스테네스의 체' 알고리즘인데요.

알고리즘 풀이 과정은 다음과 같습니다.
1. '에라토스테네스의 체'는 가장 먼저 소수를 판별할 범위만큼 배열을 할당해 그 인덱스에 해당하는 값을 넣어줍니다.
2. 2부터 시작해서 특정 숫자의 배수에 해당하는 숫자들을 모두 지웁니다. (자기 자신은 제외!)
3. 이미 지워진 숫자의 경우 건너뜁니다.
4. 남아 있는 수를 모두 출력합니다.
'''

number = 100000  # 총 10만개의 소수 판별
a = [0] * (number+1)

# 판별할 범위 만큼 값 할당
for i in range(2, number+1):
    a[i] = i

for i in range(2, number+1):
    if a[i] == 0:
        continue
    # 자기 자신을 제외한 2배수 모두 제거
    for j in range(i * 2, number+1, i):
        a[j] = 0

# 남아 있는 수 출력
for i in range(2, number+1):
    if a[i] != 0:
        print(a[i], end=' ')
