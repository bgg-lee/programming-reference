# 풀이 추가 할 것 ! 

def calc(stones, k, mid): # 건널 수 있는지를 체크 하는 것
    jump = 0 
    for stone in stones:
        if(stone - mid <= 0):
            jump +=1  
        else:   # 연속으로 나온게 아니면 다시 0으로 만들어줌.
            jump = 0
        if(jump >= k): # now가 k랑 같거나 커지면 못 건너는 것.
            return False
    return True

def solution(stones, k):
    left = 1 # 최소 1명은 건널 수 있기 때문에 
    right = max(stones) + 1
    while(left <= right): 
        mid = (left + right) // 2 
        if(calc(stones, k, mid)): # mid가 가능한지 확인
            left = mid + 1
        else:
            right = mid - 1
    
    return left

# 정확성은 맞지만 시간 초과 나는 풀이
# def solution(stones, k):
#     answer = 0
#     leng = len(stones)
#     while 1:
#         # 첫번째 캐릭터부터 징검다리를 건넌다.           
#         jump = 0
#         for i in range(leng):
#             if stones[i] != 0:
#                 jump = 0
#                 stones[i] -= 1
#             elif stones[i] == 0:
#                 jump += 1
#                 if jump >= k:
#                     return answer
#         answer += 1
#     return answer