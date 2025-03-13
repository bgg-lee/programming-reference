'''
* 🙆‍♂️ Created by wwlee94 on 2020.01.19
이중 for문으로 계속 비교하면서 값이 떨어지는 지점에서 break로 빠져나오면 OK !
'''
def solution(prices):
    leng = len(prices)
    answer = [0 for _ in range(leng)]
    for i in range(leng):
        time = 0
        for j in range(i+1, leng):
            time += 1
            if prices[i] > prices[j]: break
        answer[i] = time
    return answer

# Tip: 스택을 사용하면 속도를 2배 더 줄일 수 있다.
# deque의 popleft로 한번 연산으로 값 가져오는 속도 > prices[i]로 리스트에 접근하는 속도
'''
from collections import deque
def solution(prices):
    answer = []
    prices = deque(prices)
    while prices:
        c = prices.popleft()
        count = 0
        for i in prices:
            if c > i:
                count += 1
                break
            count += 1
        answer.append(count)
    return answer
'''