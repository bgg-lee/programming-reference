'''
* 🙆‍♂️ Created by wwlee94 on 2020.04.19
https://programmers.co.kr/learn/courses/30/lessons/12948
# 프로그래머스 LV1 

- 문제 풀이 접근 - 
1. 뒤에서 4자리를 변경하라고 했으니 반복분을 뒤에서부터 돌면서
2. 숫자인 요소 4개를 체크한 뒤 모든 문자는 '*' 로 변경 
'''

def solution(phone_number):
    leng = len(phone_number)
    count = 0
    phone_number = list(phone_number)
    for i in range(leng-1, -1, -1):
        if count < 4:
            if phone_number[i].isdecimal():
                count += 1
        else:
            phone_number[i] = '*'
    return ''.join(phone_number)