'''
* 🙆‍♂️ Created by wwlee94 on 2020.04.03
https://programmers.co.kr/learn/courses/30/lessons/12982

- 문제 풀이 방법 -
1. 나의 풀이
예산이 적은 것부터 채택해 개수를 세는 방법

2. 더 짧은 코드 풀이
O(n^2) 의 시간 복잡도이지만 더 간결한 코드 풀이 가능
가장 큰 d의 수부터 없애면서 합이 budget보다 작아지면 해당 길이 반환
'''

# 1
def solution(d, budget):
    answer = 0
    d.sort()
    for x in d:
        if budget >= x:
            budget -= x
            answer += 1
    return answer

# 2
def solution(d, budget):
    d.sort()
    while budget < sum(d):
        d.pop()
    return len(d)