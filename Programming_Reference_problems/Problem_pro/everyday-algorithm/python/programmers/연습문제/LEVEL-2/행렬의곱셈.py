# 2 * 1 | 1 * 3 = 2 * 3 행렬 생성
# 1. 결과의 형태를 주목하자 -> for loop의 범위를 예측할 수 있다.
# or
# 2. 입력에서 어떤게 기준으로 반복되는지 생각할 것 (큰 범위의 기준이 먼저 loop)
def solution(arr1, arr2):
    answer = []
    arr1_row = len(arr1)
    arr2_col = len(arr2[0])
    
    arr2_row = len(arr2)
    # or
    # arr1_col = len(arr1[0])
    
    for i in range(arr1_row): 
        temp = []
        for j in range(arr2_col):
            _sum = 0
            for z in range(arr2_row):
                _sum += arr1[i][z] * arr2[z][j]    
            temp.append(_sum)
        answer.append(temp)
    return answer