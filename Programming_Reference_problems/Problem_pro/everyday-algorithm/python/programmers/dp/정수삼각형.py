'''
* 🙆‍♂️ Created by wwlee94 on 2020.07.15
https://programmers.co.kr/learn/courses/30/lessons/43105
'''

# 큰 문제를 작은 문제로 나눠보면
# 층 별로 구한 점수를 저장하고 있으면 어떨까?
def solution(triangle):
    
    # 각 층 원소의 합 최대값을 담는 변수
    memo = [[-1 for _ in triangle[i]] for i in range(len(triangle))]
    memo[0][0] = triangle[0][0] # 초기값 지정
    
    # 0층은 초기값 1층부터 시작
    for i in range(1, len(triangle)):
        leng = len(triangle[i])
        for j in range(leng):
            number = triangle[i][j]
            # 첫 인덱스, 마지막 인덱스는 부모가 1명임
            if j == 0:
                memo[i][j] = memo[i-1][0] + number
            elif j == leng-1:
                memo[i][j] = memo[i-1][-1] + number
            else:
                left = memo[i-1][j-1] + number
                right = memo[i-1][j] + number
                memo[i][j] = max(left, right) # 갱신
    return max(memo[-1]) # 마지막 층의 최대 값