'''
* 🙅‍♂️ Created by wwlee94 on 2020.09.14
https://programmers.co.kr/learn/courses/30/lessons/12946

# 프로그래머스 LV3

미친 로직 참고..; 
- https://shoark7.github.io/programming/algorithm/tower-of-hanoi
'''
def solution(n):
    answer = []
    def move(start, to):
        answer.append([start, to])
        
    def hanoi(N, start, via, to):
        if N == 1:
            move(start, to)
        else:
            hanoi(N-1, start, to, via)
            move(start, to)
            hanoi(N-1, via, start, to)
    
    hanoi(n, 1, 2, 3)
    return answer