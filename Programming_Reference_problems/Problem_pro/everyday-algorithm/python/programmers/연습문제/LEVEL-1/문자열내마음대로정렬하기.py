'''
* 🙆‍♂️ Created by wwlee94 on 2020.04.07
https://programmers.co.kr/learn/courses/30/lessons/12915
# 프로그래머스 LV1 
'''
def solution(strings, n):
    word = [string[n] for string in strings]
    
    idx_strings = list(zip(word, strings)) # 결합
    
    idx_strings.sort(key = lambda x : x[1]) # 기준 대로 정렬
    idx_strings.sort(key = lambda x : x[0])
    
    word, answer = zip(*idx_strings) # 다시 분리
    return list(answer)