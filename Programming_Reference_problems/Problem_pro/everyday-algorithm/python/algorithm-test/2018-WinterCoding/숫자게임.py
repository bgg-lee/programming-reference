'''
* 🤷‍♂️ Created by wwlee94 on 2020.09.27
https://programmers.co.kr/learn/courses/30/lessons/12987

- 문제 풀이 접근 - 
아슬아슬하게 이기고? 질건 져야? 최대 승점을 챙길 수 있을 듯 -> 이길 수 없는 것은 과감히 포기 (다음 승리를 위해)

문제를 비슷하게 접근하긴 했지만, A의 최대값과 B의 값들을 하나씩 비교하면서 이길 수 없는 요소는 skip하는 부분을 놓혀서 아쉬웠다.
'''

import heapq

def solution(A, B):
    answer = 0
    A.sort(reverse=True)
    
    if min(A) > max(B): return 0
    
    heap = []
    for num in B:
        heapq.heappush(heap, (-num, num))  # (우선 순위, 값)
        
    for num in A:
        if num >= heap[0][1]: continue
        heapq.heappop(heap)
        answer += 1
            
    return answer