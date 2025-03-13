'''
* 🙆‍♂️ Created by wwlee94 on 2020.01.09
https://programmers.co.kr/learn/courses/30/lessons/42588

answer 배열이 입력 크기만큼 0으로 초기화 되어 있기 때문에
신호를 수신하는 탑은 고려하지 않아도 된다 !
'''
def solution(heights):
    leng = len(heights)
    answer = [0 for i in range(leng)]
    for i in range(leng, 0, -1):
        base = heights[i-1]
        for j in range(i, 0, -1):        
            if answer[i-1] == 0 and base < heights[j-1]:
                answer[i-1] = j
    return answer

heights = [6, 9, 5, 7, 4]
result = solution(heights)
print(result)