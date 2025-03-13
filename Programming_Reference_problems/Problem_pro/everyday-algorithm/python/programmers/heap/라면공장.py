'''
* 🤷‍♂️ Created by wwlee94 on 2020.01.28
- 초기 문제 접근법 -
반드시 밀가루를 공급받는 일은 생각 안하고 supplies 최대값들만 선택하는 풀이를 해서 틀림

- 풀이 방법 - 
stock이 k보다 커지는 지점엔 해외 공장에서 밀가루 공급 종료 (종료 후 결과 반환)
dates[i] < stock: 밀가루가 충분한 상황 -> 미리 공급할 가능성이 있는 날 -> 힙에 supplies(해당 날짜에 해당되는 밀가루 수량)을 계속 넣어 그 중에서 최대값을 뽑음 (idx도 같이 ++)
dates[i] == stock: 밀가루가 곧 떨어져 당장 공급 해야할 상황 -> 똑같이 현재 공급까지는 힙에 추가
dates[i] > stock: 검사 안해도 되는 범위 -> break로 for문 종료 -> 정확성에 문제 없는 조건이지만 효율성을 위해 추가한 코드
stock에 최대 밀가루 수량 더해주고 횟수도 +1
반복 ...
'''
import heapq
def solution(stock, dates, supplies, k):
    answer = 0
    idx=0
    h=[]
    while stock < k:
        for i in range(idx, len(dates)):
            if dates[i] <= stock:
                heapq.heappush(h, (-supplies[i], supplies[i]))
                idx = i+1
            else:
                break # 조건 만족 안하면 break
        stock += heapq.heappop(h)[1]
        answer += 1
    return answer