'''
* 🤷‍♂️ Created by wwlee94 on 2020.02.24
https://programmers.co.kr/learn/courses/30/lessons/42747

# 2020.02.24
- 문제 접근 방법 -
문제를 보고 'h는 n보다 작거나 같은 값' 임에 인지해야함
'논문 4편 이상이 5번 이상 인용되었다' 라면 h-index는 5가 아닌 4
'논문 4편 이상이 3번 이상 인용되었다' -> 조건에 부합하지도 않음

1. 인용 횟수를 오름차순으로 정렬한 경우
citations[i] -> 논문 n편의 각각의 '인용 횟수'임을 알아야함 !
leng - i -> 정해진 인용 횟수(citations[i])보다 크거나 같은 '논문 개수' !
EX) citation[i] = 0, leng - i = 5 라면 0번 이상 인용된 논문의 수는 5개
즉, (논문개수 <= 인용 횟수)의 조건을 만족하는 논문 개수가 H-index이다 !
'''

# 2020.07.17
def solution(citations):
    n = len(citations) # 논문의 수
    # 최대값 반환 - 역순
    for h in range(n+1, 0, -1):
        h_list = list(filter(lambda x: x>=h, citations))
        if len(h_list) >= h:
            return h
    return 0


# 인용 횟수를 내림차순 한 경우
def solution(citations):
    citations = sorted(citations)
    leng = len(citations)
    for i in range(leng):
        if citations[i] >= leng-i: # leng-i -> citations[i]보다 크거나 같은 값의 개수
            return leng-i
    return 0