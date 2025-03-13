'''
* 🤷‍♂️ Created by wwlee94 on 2020.04.04
https://programmers.co.kr/learn/courses/30/lessons/12901

- 문제 풀이 접근 -
프로그래머스 LV1 문제로 월 별 일수가 며칠인지 알고 있고 2016년 1월 1일이 'FRI' 부터 시작임을 이용해서 접근
'''
def solution(a, b):
    total = 0
    day = ["FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"]
    month_date = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    for n in range(0, a-1):
        total += month_date[n]  # 월 -> 일수
    total += b - 1              # 일수
    
    answer = day[total%7]
    return answer