# https://engineering.linecorp.com/ko/blog/2019-firsthalf-line-internship-recruit-coding-test
# 2019 라인 코딩 테스트 5번 문제

'''
# cony의 시간 time 과 brown의 시간 newTime이 서로 홀수거나 서로 짝수로 맞아야함
cony = 6, brown = 3인 경우
cony의 경우 3초 후 : 6 → 7 → 9 → 12
brown의 경우 2초 후 : 3 → 6 → 12 
brown은 cony와 같은 위치에 도달했다고 생각할 수도 있음

정답은? 
cony의 경우 4초 후 : 6 → 7 → 9 → 12 → 16
brown의 경우 4초 후 : 3 → 6 → 7 → 8 → 16
'''

import sys
input_s = lambda: sys.stdin.readline()

cony_loc, brown_loc = map(int, input_s().split())

from collections import deque 

def solve(cony_position, brown_position): 
    time = 0 
    visit = [[0]*2 for _ in range(200001)] 
    q = deque() 
    q.append((brown_position, 0)) 
    
    while 1: 
        print(f'cony_position = {cony_position}')

        cony_position += time 
        if cony_position > 200000: 
            return -1 
        if visit[cony_position][time%2]: 
            return time 
        
        for i in range(0, len(q)): 
            current = q.popleft() 
            current_position = current[0] 
            new_time = (current[1]+1)%2 
            print(f'new_time : {new_time}')

            new_position = current_position - 1 
            if new_position >= 0 and not visit[new_position][new_time]: 
                visit[new_position][new_time] = True 
                q.append((new_position, new_time)) 

            new_position = current_position + 1 
            if new_position < 200001 and not visit[new_position][new_time]: 
                visit[new_position][new_time] = True 
                q.append((new_position, new_time))

            new_position = current_position * 2 
            if new_position < 200001 and not visit[new_position][new_time]: 
                visit[new_position][new_time] = True 
                q.append((new_position, new_time)) 

        time+=1

print(solve(cony_loc, brown_loc))


