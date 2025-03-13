'''
* 🙆‍♂️ Created by wwlee94 on 2020.05.19
https://programmers.co.kr/learn/courses/30/lessons/12953
# 프로그래머스 LV2

- 문제 풀이 접근 -
1. 유클리드 호제법에 의하여 최대 공약수를 구하는 공식은 다음과 같다.
  a > b 일 때,
  r = a % b
  gcd(a , b) = gcd(b , r)

2. 최소 공배수를 구하는 공식은 다음과 같다.
  a > b 일 때,
  (a * b) / gcd(a , b)
'''


def solution(arr):
    def gcd(a, b):
        if b == 0 : return a
        return gcd(b, a % b)
    def lcm(a, b):
        return (a * b) // gcd(a, b)
    
    answer = 0
    arr.sort(reverse=True)
    
    # reduce
    for i in range(len(arr)-1):
        arr[i+1] = lcm(arr[i], arr[i+1])
        
    return arr[-1]