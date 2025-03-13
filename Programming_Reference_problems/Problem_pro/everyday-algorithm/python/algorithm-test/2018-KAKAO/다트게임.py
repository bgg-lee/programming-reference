'''
* 🙆‍♂️ Created by wwlee94 on 2020.04.22
https://programmers.co.kr/learn/courses/30/lessons/17682

- 문제 풀이 방법 -
1. '2. 이전 풀이' 방법대로 문제를 해결하기 했으나 가독성이 매우 떨어짐
2. '1. 개선 풀이'에서 정규식을 사용하여 보다 가독성 있는 코드로 변경
    * 문제에서 주어지는 문자들을 각각의 점수로 변경한 뒤
    * 정규식으로 연산 문단을 찾아 값을 대입
'''

# 1. 개선 풀이
import re
def solution(dartResult):
    bonus = {'S' : 1, 'D' : 2, 'T' : 3}
    option = {'' : 1, '*' : 2, '#' : -1}
    p = re.compile('(\d+)([SDT])([*#]?)')
    dart = p.findall(dartResult)
    for i in range(len(dart)):
        if dart[i][2] == '*' and i > 0:
            dart[i-1] *= 2
        dart[i] = int(dart[i][0]) ** bonus[dart[i][1]] * option[dart[i][2]]

    answer = sum(dart)
    return answer


# 2. 이전 풀이
# def solution(dartResult):
#     answer = []
#     cur = 0
#     count = 0
    
#     dartResult = dartResult.replace('10', 'x')
#     for i in dartResult:
#         # 숫자
#         if i.isdigit():
#             cur = int(i)
#         elif i == 'x':
#             cur = 10
#         # 보너스
#         elif i in ['S','D','T']:                
#             if i == 'D':
#                 cur = cur**2
#             elif i == 'T':
#                 cur = cur**3
#             answer.append(cur)
#             count += 1
#         # 옵션
#         elif i in ['*', '#']:
#             if i == '*':
#                 if count != 1:
#                     answer[count-2] *= 2
#                 answer[count-1] *= 2
#             elif i == '#':
#                 answer[count-1] *= -1
#     return sum(answer)