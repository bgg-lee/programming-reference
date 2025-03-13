'''
* 🤷‍♂️ Created by wwlee94 on 2020.04.06
https://programmers.co.kr/learn/courses/30/lessons/62048
# 프로그래머스 LV2

참조: https://leedakyeong.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EB%A9%80%EC%A9%A1%ED%95%9C-%EC%82%AC%EA%B0%81%ED%98%95-in-python
'''
import math
def solution(w,h):
    answer = w * h - (w + h - math.gcd(w, h))
    return answer