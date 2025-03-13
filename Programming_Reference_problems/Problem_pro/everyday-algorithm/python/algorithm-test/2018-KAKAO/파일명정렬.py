'''
* 🙆‍♂️ Created by wwlee94 on 2020.06.06
https://programmers.co.kr/learn/courses/30/lessons/17686

- 문제 접근 방식 -
1. 문제에 주어진 HEAD / NUMBER / TAIL 조건에 맞게 정규식으로 files 문자열을 분리한다.
2. Custom Compare를 적용하여 조건 기준에 따라 정렬한다.
   1. 파일명은 우선 HEAD 부분을 기준으로 사전 순으로 정렬한다 (대소문자 구분 X)
   2. 파일명의 HEAD 부분이 대소문자 차이 외에는 같을 경우, NUMBER의 숫자 순으로 정렬한다.
   3. 둘 다 같은 경우 처음 들어왔던 순서를 유지 (Default 조건: 위 1,2를 만족시키게만 짜면 알아서 적용되는 조건)
'''


import re
import functools
def solution(files):
    def compare(x, y):
        head_x = x[0].lower()
        num_x = int(x[1])
        
        head_y = y[0].lower()
        num_y = int(y[1])
        if head_x < head_y: # head_x 값이 head_y 값 보다 작으면
            return -1 # x 내용을 앞으로 보냄
        elif head_x > head_y:
            return 1
        else: # head_x 값이 head_y 값과 동일하면
            if num_x < num_y: # num_x과 num_y을 비교해서  num_y가 크면
                return -1 # x 내용을 앞으로 보냄
            elif num_x > num_y:
                return 1
            else:
                return 0
    
    # HEAD / NUMBER / TAIL
    p = re.compile('(\D+)(\d+)(.*)')
    answer = []
    
    parts = []
    for file in files:
        res = p.findall(file)[0]
        parts.append(list(res))
    
    parts.sort(key= functools.cmp_to_key(compare))
    answer = list(map(lambda x: ''.join(x), parts))
    return answer