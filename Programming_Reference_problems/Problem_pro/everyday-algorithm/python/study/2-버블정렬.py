'''
* Created by wwlee94 on 2020.05.10

'옆에 있는 값과 비교해서 더 작은 값을 앞으로 계속 보내주면 어떨까?'
위의 접근법은 버블 정렬(Bubble Sort)의 아이디어 ! (== 큰 값은 뒤로)

지난 시간에는 가장 작은 값을 선택해서 앞으로 보내는 선택 정렬에 대해서 알아보았습니다.
이번 시간에는 버블 정렬(Bubble Sort)에 대해서 알아볼 예정입니다.

버블 정렬 또한 선택 정렬과 같이 직관적인 해결 방법입니다.
바로 가까이 있는 두 숫자를 비교해서 당장 더 작은 숫자를 앞으로 보내주는 것을 반복하는 겁니다.
하지만.. 가장 쉬운 구현 방법이나 가장 효율성도 떨어지는 알고리즘이다.. (컴퓨터 내부 연산이 비효율적이여서, 스왑이 많이 일어남)

시간 복잡도 : O(N^2)
공간 복잡도 : O(N)

- 특징 -
1. 다른 메모리 공간을 필요로 하지 않는다 => 제자리 정렬(in-place sorting)
2. 안정 정렬(stable sort)
'''

data = [1, 10, 5, 8, 7, 6, 4, 3, 2, 9]
size = len(data)
for i in range(size-1):
    for j in range(size-1-i):
        if data[j] > data[j+1]:
            data[j], data[j+1] = data[j+1], data[j]

# 왼쪽부터 쌓이는 버블 정렬
# for i in range(size):
#   for j in range(i, size):
#     if data[i] > data[j]:
#       data[i], data[j] = data[j], data[i] # swap

print(data)  # [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
