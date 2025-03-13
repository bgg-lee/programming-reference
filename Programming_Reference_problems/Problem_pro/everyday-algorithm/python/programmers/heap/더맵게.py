'''
* 🙆‍♂️ Created by wwlee94 on 2020.01.28
- 힙의 개념 - 
* 완전 이진 트리의 일종으로 우선순위 큐를 위하여 만들어진 자료구조이다.

- Python의 heapq 모듈 -
* 이진 트리(binary tree) 기반의 최소 힙(min heap) 자료구조
min heap을 사용하면 원소들이 항상 정렬된 상태로 추가되고 삭제 !
참고: https://www.daleseo.com/python-heapq
'''
import heapq

def solution(scoville, K):
    count = 0
    leng = len(scoville)
    heapq.heapify(scoville)
    for _ in range(leng-1):
        first = heapq.heappop(scoville) # 가장 맵지 않은 음식
        second = heapq.heappop(scoville) # 두 번째로 맵지 않은 음식
        heapq.heappush(scoville, first + (second * 2))
        count += 1
        if first+second >= K and scoville[0] >= K: return count
        # low_scoville = list(filter(lambda x: x < K, scoville))
        # if len(low_scoville) == 0: return count
        
    return -1