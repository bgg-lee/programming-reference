'''
* 🙆‍♂️ Created by wwlee94 on 2020.05.05
https://programmers.co.kr/learn/courses/30/lessons/12941
# 프로그래머스 LV2

- 문제 풀이 접근 -
정렬을 사용하여 문제 풀이 !
길이가 같은 두 배열의 원소를 하나씩 뽑아 곱해서 최솟값을 만드는 문제
따라서, 곱할 때 한 배열의 값을 가장 작은 값 다른 배열의 값은 가장 큰 값끼리 곱해야 최소값이 나온다.
'''

def solution(A,B):
    answer = 0
    leng = len(A)
    A.sort()
    B.sort(reverse=True)
    for i in range(leng):
        _min = A[i]
        _max = B[i]
        answer += _min * _max

    return answer