'''
* 🤷‍♂️ Created by wwlee94 on 2020.04.20
# https://programmers.co.kr/learn/courses/30/lessons/12940
# 프로그래머스 LV1 

- 문제 풀이 접근 -
a = Gy, b = Gy (x, y는 서로소)
a * b = G * G * x * y
a 와 b의 합집합은 G, x, y이고 G * x * y가 최소 공배수임을 알 수 있다.

gcd(a,b) = G (최대공약수)
lcm(a,b) -> a * b / gcd(a,b)
'''

def solution(n, m):
    def gcd(a, b):
        if a % b == 0:
            return b
        else:
            return gcd(b, a % b)
    
    answer = []
    _gcd = gcd(n, m)
    _lcm = n * m / _gcd
    
    answer.append(_gcd)
    answer.append(_lcm)

    return answer