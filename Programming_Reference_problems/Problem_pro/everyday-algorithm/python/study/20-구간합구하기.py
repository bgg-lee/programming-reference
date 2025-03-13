'''
# 구간 합 빠르게 계산하기
[문제 설명]
* N 개의 정수로 이루어진 배열이 존재
* M 개의 쿼리는 다음과 같이 주어짐
  * 각 쿼리는 L 과 R 로 구성된다.
  * [L,R] 구간에 해당하는 데이터 합을 모두 구하는 문제
* 시간 제한 O(N+M)

[문제 해결 방법]
* 접두사 합 (Prefix Sum)
1. Prefix Sum 을 계산하여 배열 P에 저장한다.
2. 매 M개의 쿼리를 확인 할 때, 구간합은 'P[R] - P[L-1]' 이다

Ex) data = [10, 20, 30, 40, 50]
1.번 과정 수행
  P = [0, 10, 30, 60, 100, 150] -> L:1, R:3 (data[1]~data[3]) 이라면 P[3] - P[0] = 60
'''

# 데이터 개수와 데이터 입력 받기
n = 5
data = [10, 20, 30, 40, 50]

# Prefix Sum 계산하기
summary = 0
prefix_sum = [0]
for i in data:
    summary += i
    prefix_sum.append(summary)

# 구간 합 계산
left = 3
right = 4
print(prefix_sum[right] - prefix_sum[left-1])  # 30 + 40 = 70
