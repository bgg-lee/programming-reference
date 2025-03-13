'''
* 🤷‍♂️ Created by wwlee94 on 2020.05.27
https://programmers.co.kr/learn/courses/30/lessons/12985

- 주의 사항 ! -
# 8 2 3 인 경우 2가 나와야 함 !! (조건을 잘 살펴볼 것)
# 종료 조건은 abs(a - b) == 1 and a * b == 2 가 아니라 -> a == b일 때 종료 조건 !!
'''
import math
def solution(n,a,b):
    def calculate(x):
        if x % 2 == 1:
            x += 1
        return x // 2
            
    answer = 0
    
    while 1:
        if a == b:
            break
        a = calculate(a)
        b = calculate(b)
        answer += 1
        
    return answer