'''
* 🤷‍♂️ Created by wwlee94 on 2020.06.17
https://programmers.co.kr/learn/courses/30/lessons/43238

- 문제 풀이 접근 - 

'''
def solution(n, times):
    answer = 0

    leng = len(times)
    left = 1
    right = (leng+1) * max(times)
    
    while left <= right:
        mid = (left + right) // 2
        count = 0
        for time in times:
            count += mid // time
            # 심사 인원수를 넘으면 다음 단계
            if count >= n: break
        
        # 심사 할 수 있는 경우 -> 한 심사관에게 주어진 시간을 줄여본다.
        if count >= n:
            answer = mid
            right = mid - 1
        # 없는 경우
        elif count < n:
            left = mid + 1
    
    return answer