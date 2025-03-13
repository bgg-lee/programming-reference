'''
* 🤷‍♂️ Created by wwlee94 on 2020.06.15
https://programmers.co.kr/learn/courses/30/lessons/42886

- 문제 풀이 접근 - 
https://wwlee94.github.io/category/algorithm/greedy/scale/
'''

def solution(weight):
    weight.sort() # 작은 무게부터 더하면서 접근해야하므로

    subtotal = 1 # 추의 최소 무게는 1
    for w in weight:
        if subtotal < w: break
        subtotal += w

    return subtotal