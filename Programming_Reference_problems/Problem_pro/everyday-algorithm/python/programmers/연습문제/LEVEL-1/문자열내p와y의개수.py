'''
* 🙆‍♂️ Created by wwlee94 on 2020.04.10
https://programmers.co.kr/learn/courses/30/lessons/12916
# 프로그래머스 LV1 

- 문제 풀이 접근 -
1. 해시 자료구조 (dict)를 사용하여 문자열 s의 요소를 반복하면서 개수를 구함
2. '합이 0이면 True 조건을 만족해야한다' 라는 조건을 만족시켜야하고
3. _dict의 value 배열을 set으로 바꿔서 개수가 2개이면 -> 각 요소의 값이 다르다는 의미이므로 False를 반환

'''
def solution(s):
    answer = True
    _dict = {
        "p" : 0,
        "y" : 0
    }
    
    for x in s:
        x = x.lower()
        if x in _dict.keys():
            _dict[x] += 1
    
    values = _dict.values()
    if sum(values) == 0: return True
    if len(set(values)) == 2:
        return False
    return answer