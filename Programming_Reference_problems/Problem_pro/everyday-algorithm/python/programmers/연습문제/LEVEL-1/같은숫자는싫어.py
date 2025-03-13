'''
* 🙆‍♂️ Created by wwlee94 on 2020.04.05
https://programmers.co.kr/learn/courses/30/lessons/12906
# 프로그래머스 LV1 
'''
def solution(arr):
    answer = []
    # [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    pre = -1
    for x in arr:
        if pre != x:
            answer.append(x)
        pre = x
    return answer