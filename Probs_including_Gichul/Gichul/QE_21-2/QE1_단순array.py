# KEYWORD
# Pigeonhole Principle
# pigeonhole_principle
# pigeonholeprinciple
"""
1. Given an integer array of size N. Implement a method that returns the smallest positive integer which
is not in that array. To get full credit, your implementation needs to run in O(N). (That is, the run time
linearly increases only to the array size, regardless of the element values.) Do not use the built-in sort
method. If needed, build it on your own.
• Example 1) array = [4, 7, -1, 1, 2] ! return: 3
• Example 2) array = [100, 101, 102] ! return: 1
• Example 3) array = [3, 2, 1, 0, -1] ! return: 4
"""
def smallest_pos_int(arr:list[int]) -> int:
    s = set()
    
    # 1) 양의 정수만 s 에 저장
    for num in arr:
        if num > 0:
            s.add(num)
    
    # 2) 1부터 n+1까지 차례대로 s에 존재하는지 확인
    n = len(arr) # 정답은 잘 해봐야 n+1이다.....................
    for i in range(1, n+2):  # n+1 까지 확인, range 범위를 위해 n+2 -> n+1까지 체크해도 ㄱㅊ
        if i not in s:      # 집합 membership check: 평균 O(1)
            return i

    # 위 for문에서 항상 return이 일어나므로 실제로 여기에 올 일은 없음.
    # 혹시 형식상 return이 필요하다면 다음과 같이 처리:
    return n + 1

    # O(N^2...)
    # ans = max(arr)
    # for i in range(len(arr)):
    #     if arr[i] <= 0 : continue
    #     else :
    #         ans = min(ans,arr[i])
    
    # if ans <= 0 or ans >= 2 : return 1
    # else:
    #     while ans in arr:
    #         ans += 1
    # return ans

if __name__ == "__main__":
    print(smallest_pos_int([4, 7, -1, 1, 2])) # 3
    print(smallest_pos_int([100, 101, 102])) # 1
    print(smallest_pos_int([3, 2, 1, 0, -1])) # 4



"""
def smallest_positive_int(arr: list[int]) -> int:
    n = len(arr)
    
    # 1) 범위를 벗어나거나(<=0 or > n) 무관한 값은 임시로 n+1 로 바꿔버린다
    #    (이렇게 하면 나중에 인덱스 마킹 과정에서 제외시킬 수 있음)
    for i in range(n):
        if arr[i] <= 0 or arr[i] > n:
            arr[i] = n + 1
    
    # 2) 이제 arr[i]가 1~n 범위라면, (arr[i] - 1)을 인덱스로 하는 위치에 마킹을 해둔다.
    #    예: 값이 k라면 인덱스 (k-1)에 마킹(음수화 혹은 다른 방식으로 기록)한다.
    for i in range(n):
        val = abs(arr[i])
        if 1 <= val <= n:
            # 마킹 방법: 해당 위치의 값을 음수로 바꾼다(이미 음수면 그대로 둔다).
            if arr[val - 1] > 0:  # 아직 음수화되지 않았다면
                arr[val - 1] = -arr[val - 1]
    
    # 3) 1~n까지 번호 중 마킹되지 않은(즉, 양수로 남아 있는) 인덱스를 찾아 +1 해주면 그것이 답
    for i in range(n):
        if arr[i] > 0:  # 음수화되지 않았다면 존재하지 않는 숫자
            return i + 1
    
    # 4) 만약 1~n 모두 마킹되었다면 답은 n+1
    return n + 1
"""