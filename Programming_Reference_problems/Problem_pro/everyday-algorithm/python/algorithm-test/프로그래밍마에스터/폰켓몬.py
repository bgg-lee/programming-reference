'''
* 🙆‍♂️ Created by wwlee94 on 2020.05.03
https://programmers.co.kr/learn/courses/30/lessons/1845

# 문제 풀이 접근
1. 최대한 많은 수의 포켓몬을 가져야 하기 때문에 중복된 포켓몬은 set으로 없앤다.
2. 중복되지 않은 포켓몬 종류의 개수와 최대로 가질 수 있는 개수(N/2) 와 비교해서 값을 반환한다.
'''

def solution(nums):
    answer = 0
    leng = len(nums)
    max_pokemon = leng // 2
    
    _set = set(nums)
    if len(_set) < max_pokemon:
        return len(_set)
    else:
        return max_pokemon