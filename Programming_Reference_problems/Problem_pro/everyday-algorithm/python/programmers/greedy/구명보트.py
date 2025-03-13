'''
* 🤷‍♂️ Created by wwlee94 on 2020.02.06

- 문제 풀이 접근 - 
* Greedy Approach으로 무게가 많이 나가는 사람부터 태워야함 ! 
-> 무게가 가장 많이 나가는 승객 + 가장 적게 나가는 승객 <= limit인 경우를 찾아야함 -> 이 조건을 만족하면 2명이 함께 탈 수 있음 
-> 그 외의 경우는 당연히 제외됨 (가장 적게 나가는 승객과 합해 limit을 넘었으니 그 다음 적게 나가는 승객과 합해봤자 limit을 넘기 때문)
-> 위의 조건을 만족하지 못하면 그냥 pop해서 혼자 이동 시킴

# TIP: 구명보트에는 최대 2명만 탈 수 있음

'''
import collections

def solution(people, limit):
    leng = len(people)
    answer = leng
    
    people.sort(reverse=True)
    deq = collections.deque(people)
    
    while len(deq) != 0:
        if len(deq) == 1:
            deq.pop()
            return answer
        else:
            temp = deq.popleft()
            if temp + deq[-1] <= limit:
                deq.pop()
                answer -= 1
                            
    return answer

    # (구) 풀이 방법 - 틀림
    # people.sort(reverse=True)
    # deq = collections.deque(people)  
    # while len(deq) != 0:
    #     temp = deq.popleft()
    #     for i,x in enumerate(deq):
    #         if temp + x <= limit:
    #             del deq[i]
    #             answer -= 1
    #             break