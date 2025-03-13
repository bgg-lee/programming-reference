'''
* 🙆‍♂️ Created by wwlee94 on 2020.04.21
https://programmers.co.kr/learn/courses/30/lessons/17681

- 문제 풀이 방법 -
1. 각 정수를 or 연산해준 후 2진수로 변환
2. 변환된 2진수의 자리수를 맞춰줌 
3. 1 -> '#', 0 -> ' ' 으로 변경 !

추가 팁)
2번 과정의 방법 2가지를 소개
1. answer[i]=answer[i].rjust(n,'0') -> 오른쪽에 n크기가 되도록 '0'을 붙인다.
2. 1번 변환 과정에서 zfill(n)을 사용하여 2진수를 변경한다.
Ex) format(10, 'b') -> 1010
Ex) format(10, 'b').zfill(n) -> 001010
'''

def solution(n, arr1, arr2):
    answer = []
    
    # or 연산
    for i in range(n):
        answer.append(format(arr1[i] | arr2[i], 'b'))
    
    # 자리수 맞추기
    for i in range(n):
        _len = len(answer[i])
        answer[i] = (n - _len) * '0' + answer[i]
    
    # 변환
    for i in range(n):
        answer[i] = answer[i].replace('1','#')
        answer[i] = answer[i].replace('0',' ')
    
    return answer