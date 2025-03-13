'''
* 🙆‍♂️ Created by wwlee94 on 2020.01.30
https://programmers.co.kr/learn/courses/30/lessons/42840

수포자 3명의 반복되는 정답을 미리 선언해 둔 후 answers와 각각 비교하여 정답을 맞춘 횟수를 scores에 저장
그 다음엔 scores의 최대값을 구해서 동일 점수를 가지는 수포자가 있는지 검사하면 끝 !
'''
def solution(answers):
    result = []
    first_supo = [1,2,3,4,5] # 5개씩 반복
    second_supo = [2,1,2,3,2,4,2,5] # 8개씩 반복
    third_supo = [3,3,1,1,2,2,4,4,5,5] # 10개씩 반복
    scores = [0,0,0]
    
    for i in range(len(answers)):
        if answers[i] == first_supo[i%5]:
            scores[0] += 1
        if answers[i] == second_supo[i%8]:
            scores[1] += 1
        if answers[i] == third_supo[i%10]:
            scores[2] += 1
        
    maxi = max(scores)
    for i in range(len(scores)):
        if maxi == scores[i]:
            result.append(i+1)
    return result