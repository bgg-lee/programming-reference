'''
* 🤷‍♂️ Created by wwlee94 on 2020.04.09
# https://programmers.co.kr/learn/courses/30/lessons/12921
# 프로그래머스 LV1 

- 문제 풀이 접근 -
첫 번째 방법은 1부터 n까지 소수를 구할 때 각 값의 루트 x 까지 범위의 수를 다 나누어 확인한 방법 -> 시간초과
두 번째 방법은 에라토스테네스의 체를 사용한 풀이
* 1. 초기값은 3부터 n까지 홀수를 저장한 후 -> 짝수는 소수가 될 수 없다? (2로 나누어지니)
* 2. 3~n까지 반복하면서 각 x를 제외한 나머지 수는 모두 후보에서 제외 시킴
* 3. 최종적으로 남은 수가 소수가 된다 ! 

'''
# 에라토스테네스의 체를 사용한 풀이
import math
def solution(n):
    answer = set([i for i in range(3, n+1, 2)])
    for i in range(3, n+1, 2):
        if i in answer:
            answer -= set([i for i in range(i*2, n+1, i)])
    return len(answer) + 1 # 소수 2를 1개 더해준 것

'''
# 시간 초과 - 첫 번째 방법
import math
def solution(n):
    answer = 0
    
    def is_prime(n):
        for i in range(2, int(math.sqrt(n))+1):
            if n % i == 0:
                return False
        return True
    
    for i in range(2, n+1):
        if is_prime(i):
            answer += 1
    return answer
'''