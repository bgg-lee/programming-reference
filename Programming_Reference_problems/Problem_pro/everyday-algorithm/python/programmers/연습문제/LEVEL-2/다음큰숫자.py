'''
* 🙆‍♂️ Created by wwlee94 on 2020.04.29
https://programmers.co.kr/learn/courses/30/lessons/12911
# 프로그래머스 LV2

- 문제 풀이 접근 -
1. 문제의 조건에 따라서 숫자를 1씩 증가시키면서 조건2를 계속 확인한다.
2. 조건 2를 만족하는 숫자가 나오면 정답 !!
   (조건 3에서 가장 작은 수라고 했으므로)
'''

def solution(n):
    answer = 0
    current = counting(format(n, 'b'))
    i = 1
    while 1:
        candidate = counting(format(n+i, 'b'))
        if current == candidate:
            answer = n+i
            break
        i += 1
    return answer

def counting(string):
    count = 0
    for i in string:
        if i == '1':
            count += 1
    return count
    