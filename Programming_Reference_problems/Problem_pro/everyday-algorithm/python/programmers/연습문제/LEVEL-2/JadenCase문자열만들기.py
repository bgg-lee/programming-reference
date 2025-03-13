'''
* 🤷‍♂️ Created by wwlee94 on 2020.05.20
https://programmers.co.kr/learn/courses/30/lessons/12951
# 프로그래머스 LV2

- 문제 풀이 접근 -
1. 우선 대문자가 되어있는 부분을 소문자화해야해서 미리 소문자로 다 만들어주고,
2. 띄어쓰기 단위로 단어를 나눈 다음, 그 단어별로 앞자리를 대문자화
3. 입력 문자열 맨뒤에 공백이 있을 수 있기 때문에 주의해야함 !!
4. 맨뒤 공백 뿐 아니라 공백이 여러번 등장할 수도 있다는 조건을 알아서 인지해야함 !
'''

def solution(s):
    answer = ''
    s = s.lower()
    words = s.split(' ')
    for word in words:
        word = word.capitalize()
        answer += word + ' '
    return answer[:-1] # 마지막 띄어쓰기 이전까지