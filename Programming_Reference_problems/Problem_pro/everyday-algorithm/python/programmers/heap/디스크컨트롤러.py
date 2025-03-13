'''
* 🤷‍♂️ Created by wwlee94 on 2020.03.10
https://programmers.co.kr/learn/courses/30/lessons/42627
'''
import heapq

def solution(jobs):
    answer = 0
    leng = len(jobs)
    pre, now = -1, 0 # pre: 입력시간, now: 프로세스 끝날 때 까지 걸린 시간
    wait = []
    
    count = 0 # 종료한 프로세스 개수
    while count != leng:
        # 조건에 부합하면(현재 프로세스 진행 중 다른 프로세스가 들어온 경우) 대기열에 time이 짧은 순서대로 추가 
        for i in range(leng): 
            req, time = jobs[i]
            if pre < req <= now:
                heapq.heappush(wait, [time, req])
                
        if len(wait) > 0: # 대기하는 디스크가 있을 때
            time, req = heapq.heappop(wait)
            pre = now 
            now += time
            answer += now - req
            count += 1
        else: # 대기 했던 디스크가 하나도 없을 경우
            now += 1 # 허용 범위를 늘려줌 -> 그대로 두면 다른 디스크가 범위 조건에 안맞아 할당이 안됨
    return answer // leng