'''
* 🙆‍♂️ Created by wwlee94 on 2020.07.10
https://programmers.co.kr/learn/courses/30/lessons/43104

- 문제 풀이 접근 -
1. 타일의 개수가 피보나치 수열의 패턴으로 계속 증가함을 파악
2. 성능 향상을 위해 메모이제이션 기법 사용
3. 긴 변 = (n번째 타일)이고 작은 변 = (n-1번째 타일 + n번째 타일)을 이용해 둘레를 구합니다.
4. 주의할 점은 'N=1'일 경우 -> 4를 반환하도록
    타일이 1개일때 예외처리를 해주어야합니다.
'''

def solution(N):
    
    # 입력 범위만큼 DP 결과를 저장한 변수 선언
    mem = [-1 for _ in range(N+1)]
    
    # n번째 직사각형의 한 변 길이
    def fibonacci(n):
        if mem[n] != -1: return mem[n]
        if n == 1: return 1
        if n == 2: return 1
        mem[n] = fibonacci(n-2) + fibonacci(n-1)
        return mem[n]
    
    # 직사각형의 둘레를 구하는 함수
    def cal_square_round(n):
        long = fibonacci(n) # 긴 변
        short = fibonacci(n-1) + long # 짧은 변
        return short * 2 + long * 2
    
    if N == 1: return 4
    answer = cal_square_round(N)
    return answer