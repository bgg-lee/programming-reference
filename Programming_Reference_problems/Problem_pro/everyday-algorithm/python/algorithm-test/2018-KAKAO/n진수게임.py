'''
* 🙆‍♂️ Created by wwlee94 on 2020.06.08
https://programmers.co.kr/learn/courses/30/lessons/17687

- 문제 풀이 접근 -
1. 재귀 함수를 이용해 10진수를 n진수로 변형하는 함수 생성
2. loop를 돌면서 모든 턴에 대한 답안지(후보)를 미리 생성
3. 현재 구해야하는 튜브의 시작 턴(p), 모든 참가 인원(m)을 가지고 튜브의 답을 도출한다.
'''

def solution(n, t, m, p):
    #재귀함수 이용 - 10진수를 n진수로
    def convert(n, base):
        T = "0123456789ABCDEF"
        q, r = divmod(n, base)
        if q == 0:
            return T[r]
        else:
            return convert(q, base) + T[r]
        
    answer = ''
    
    candidate = []
    for i in range(t*m):
        conv = convert(i, n)
        for c in conv:
            candidate.append(c)
        
    for i in range(p-1, t*m, m):
        answer += candidate[i]
    
    return answer