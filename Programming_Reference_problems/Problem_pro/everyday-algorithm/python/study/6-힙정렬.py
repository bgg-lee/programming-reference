'''
* Created by wwlee94 on 2020.05.14

'힙(Heap) 을 이용해 데이터를 정렬하면 어떨까?'

힙 정렬(Heap Sort)는 병합 정렬, 퀵 정렬만큼 빠른 알고리즘입니다.
실제로, 고급 프로그래밍 기법으로 갈 수록 힙의 개념이 자주 등장하기 때문에 반드시 알아야합니다.
힙 정렬은 힙 트리 구조(Heap Tree Structure)를 이용하는 정렬 방법입니다.

힙(Heap)이 무엇인지 알고, 또 그전에 이진 트리에 대해서 알아야합니다.

이진 트리란?
- 모든 노드의 자식이 2개 이하인 트리 구조
완전 이진 트리란?
- 이진 트리의 노드가 중간에 비어있지 않고 모두 차있는 상태

힙이란?
- 최솟값이나 최대값을 빠르게 찾아내기 위해 완전 이진 트리를 기반으로 만들어진 트리
- 최대힙(부모 노드가 자식보다 큰 트리), 최소힙(부모 노드가 자식보다 작은 트리)이 2가지가 존재합니다.

index = '0 1 2 3 4 5 6 7 8'
data =  '7 6 5 8 3 5 9 1 6'
이러한 배열을 힙 구조로 바꾸고 정렬하는 시간 복잡도는
1. 완전 이진 트리의 높이 logN == (Heapify 작업)
2. 데이터의 개수 N으로 O(NlogN) 입니다.

시간 복잡도 : O(NlogN)

- 특징 -
1. 불안정 정렬(unstable sort)
2. 가장 크거나 가장 작은 값을 연속적으로 구할 때 좋다.
    - 최소 힙 or 최대 힙의 루트 값이기 때문에 한번의 힙 구성을 통해 구하는 것이 가능
3. 최대 k 만큼 떨어진 요소들을 정렬할 때 좋다.
    - 삽입정렬보다 더욱 개선된 결과를 얻어낼 수 있음
'''

data = [7, 6, 5, 8, 3, 5, 9, 1, 6]
size = len(data)

# 먼저 전체 트리 구조를 최대 힙 구조로 만들기 ! (하향식 방법 이용)
for i in range(1, size):

    child = i
    while child > 0:
        root = (child - 1) // 2  # 부모 노드의 위치
        if data[root] < data[child]:
            data[root], data[child] = data[child], data[root]
        child = root  # 부모쪽으로 올라가서 위 동작 반복

# 크기를 줄여가며 반복적으로 힙을 구성 (상향식 방법 이용)
for i in range(size-1, -1, -1):
    # 가장 큰 값은 맨뒤로 보내고 (오름 차순이기에)
    data[0], data[i] = data[i], data[0]

    root = 0
    child = 1
    while child < i:
        child = (2 * root) + 1  # 왼쪽 자식 노드의 위치
        # 자식 중에 더 큰 값 찾기 (오른쪽 자식이 크면 child += 1 되는 것)
        if child < i - 1 and data[child] < data[child + 1]:
            child += 1
        # 루트보다 자식이 더 크다면 교환
        if child < i and data[root] < data[child]:
            data[root], data[child] = data[child], data[root]
        root = child  # 자식쪽으로 내려가서 위 동작 반복

print(data)
