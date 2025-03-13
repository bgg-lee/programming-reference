'''
* 🙆‍♂️ Created by wwlee94 on 2020.02.26
https://programmers.co.kr/learn/courses/30/lessons/42841?language=python3

- 문제 풀이 접근법 -
1. 문제에서 주어지는 질문과 일치하는 숫자를 찾는 것이기 때문에 1~9 사이 숫자로 만들 수 있는 3자리 순열을 생성함
2. 주어진 질문과 비교해서 strike, ball을 구함
3. 어떠한 3자리 수가 주어진 질문과 모두 일치 한다면 그 숫자는 정답 가능성이 있는 숫자이므로 answer += 1 해줌 !

- 기존 풀이 -
1. question을 구하는 다른 방법 (But, 자리 수가 늘어나는 경우엔 작성하기 귀찮아짐)
question = [item[0] // 100, item[0] % 100 // 10, item[0] % 10]

2. strike, ball을 구하는 다른 방법 (But, 첫번째 방법보다 조금 비효율적?)
# 2중 for문으로 strike, ball 구한 것 
    for i in range(3):
        for j in range(3):
            if i==j and case[i] == question[j]: strike += 1
            elif case[i] == question[j]: ball += 1
    if item[1] != strike or item[2] != ball: break
    else: count += 1
'''
import itertools

def solution(baseball):
    answer = 0
    leng = len(baseball)
    all_case = list(itertools.permutations([1,2,3,4,5,6,7,8,9], 3))
    
    for case in all_case:
        count = 0 # 질문을 만족한 개수
        for item in baseball:
            strike = 0
            question = [int(i) for i in str(item[0])]

            #첫번째 방법 - strike 개수 우선 구한 후 ball 개수 구함
            for i in range(3):
                if case[i] == question[i]: strike += 1
            if item[1] != strike: break
                
            ball = len(set(case) & set(question)) - strike # 교집합의 크기를 구한 후 strike 개수 빼준 것
            if item[2] != ball: break
                
            count += 1
                
        if count == leng: answer += 1 # 질문 개수 만큼 돌아야 조건을 모두 만족한 경우이기 때문
    return answer