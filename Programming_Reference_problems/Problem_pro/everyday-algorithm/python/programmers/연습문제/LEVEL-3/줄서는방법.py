'''
* 🙅‍♂️ Created by wwlee94 on 2020.09.12
https://programmers.co.kr/learn/courses/30/lessons/12936

# 프로그래머스 LV3
# 순열의 n번째를 바로 구하는 문제
'''

import math
def solution(n, k):
    answer = []
    line = [i+1 for i in range(n)]
    
    # 순열을 구하는 재귀 함수
    def permute(n, k):
        
        while n != 0:
            standard = math.factorial(n) // n # 한개에 몇개씩의 값이 있을지 알 수 잇음.
            index, k = divmod(k, standard)
            if k == 0:
                answer.append(line.pop(index-1))
            else :
                answer.append(line.pop(index))

            n -= 1
        return answer

    return permute(n, k)