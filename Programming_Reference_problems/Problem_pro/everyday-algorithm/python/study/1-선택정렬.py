'''
* Created by wwlee94 on 2020.05.09

'가장 직관적으로 보면 가장 작은 것을 선택해서 앞으로 보내면 어떨까?' 
위의 접근법은 선택 정렬(Selection Sort)의 아이디어

알고리즘의 효율성의 차이를 가장 확연하게 볼 수 있는 것은 정렬(Sort)입니다.
가장 기초적이기도 한 정렬에 대해 알아봅시다.

'1 10 5 8 7 6 4 3 2 9'
위와 같은 수를 오름차순으로 정렬하려면 어떻게 할까?
가장 원시적이고 기초적인 방법 중 하나입니다.

시간 복잡도 : O(N^2)
공간 복잡도 : O(N)

- 특징 -
1. 버블 정렬보다 swap 횟수가 적어 좀 더 빠르다.
2. 제자리 정렬(in-place sortring)
3. 불안정 정렬(Unstable sort)
    - 동일한 정렬기준을 가진 것의 정렬 전/후 순서가 다를 수 있다.
'''

data = [1, 10, 5, 8, 7, 6, 4, 3, 2, 9]
size = len(data)
for i in range(size):
    min = 9999
    for j in range(i, size):
        if min > data[j]:
            min = data[j]
            index = j
    # 위에서 가장 작은 값을 찾은 후 swap
    data[i], data[index] = data[index], data[i]

print(data)  # [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
