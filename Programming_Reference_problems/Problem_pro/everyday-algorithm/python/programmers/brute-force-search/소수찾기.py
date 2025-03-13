'''
* 🙆‍♂️ Created by wwlee94 on 2020.01.31
https://programmers.co.kr/learn/courses/30/lessons/42839

- 문제 풀이 접근법 -
1. 어떤 숫자가 소수인지 판별해주는 작업이 필요함 -> 함수로 따로 생성 !
2. 입력 받은 numbers ('17' 등등)을 정수형 숫자로 조합 할 수 있는 모든 경우를 조합해야함 -> itertools의 permutations (순열) 모듈 사용 !
3. 조합된 모든 숫자들을 소수 판별 함수로 검사하여 개수를 세면 끝 !
'''
# 2020.07.17
import math
import itertools

def is_decimal(n):
    if n < 2: return False
    
    to = int(math.sqrt(n)) + 1
    for i in range(2, to):
        if n % i == 0: return False
    return True

def solution(number):
    candidate = set()
    
    for i in range(len(number)):
        numbers = set(map(int, map(''.join,itertools.permutations(number, i+1))))
        candidate |= numbers # 합집합
    
    answer = 0
    candidate = list(candidate) # 리스트 변환
    for n in candidate:
        if is_decimal(n):
            answer += 1
    return answer


# 2020.01.31
import itertools
import math

def is_decimal(number):
    leng = int(math.sqrt(number))
    if number < 2: return False
    for i in range(2, leng+1):
        if number % i == 0: return False
    return True

def solution(numbers):
    answer = 0
    temp = []
    for i in range(len(numbers)):
        permutation = list(map(''.join, itertools.permutations([num for num in numbers], i+1)))
        temp += list(map(int, permutation))

    temp = list(set(temp))
    
    for val in temp:
        if is_decimal(val):
            answer += 1
    return answer