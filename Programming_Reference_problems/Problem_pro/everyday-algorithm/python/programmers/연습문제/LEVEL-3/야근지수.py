'''
* 🙆‍♂️ Created by wwlee94 on 2020.09.07
https://programmers.co.kr/learn/courses/30/lessons/12927

# 프로그래머스 LV3

- 문제 접근 방식 -
초반에는 단순히 max()함수와 list.index() 함수로 최대값을 찾고 인덱스를 찾는 방법으로 문제를 풀었더니 시간 초과 발생 !!
따라서, 힙 구조를 통해서 최대값을 빠르게 구하고 연산 후 다시 힙에 push 하는 방식으로 문제를 수정했더니 통과 !
'''

import heapq
def solution(n, works):

    # heapq.heapify(works) # 최소힙
    heap = []
    for num in works:
        heapq.heappush(heap, (-num, num))  # (우선 순위, 값)
    
    while n != 0:
        max_work = heapq.heappop(heap)[1] # 최대값 pop
        if max_work == 0: return 0 # 최대값이 0일때는 진행할 필요가 없음
            
        max_work -= 1
        heapq.heappush(heap, (-max_work, max_work))
        n -= 1
        
    answer = list(map(lambda x: x[1]*x[1], heap))
    return sum(answer)