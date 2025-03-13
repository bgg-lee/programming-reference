'''
* Created by wwlee94 on 2020.05.13

'일단 반으로 나누고 나중에 합쳐서 정렬하면 어떨까?'
'나중에 합친다'는 키워드를 기억하자 !

지난 시간까지 평균 시간 복잡도 O(NlogN)인 퀵 정렬에 대해서 알아보았습니다.
이번 시간에 다룰 내용은 병합 정렬(Merge Sort)입니다.
병합 정렬 또한 퀵 정렬과 동일하게 '분할 정복' 방법을 채택한 알고리즘이고 O(NlogN)의 시간 복잡도를 가집니다.

다만 퀵 정렬의 경우 피벗 값에 따라 편향되게 분할할 가능성이 있어 최악의 경우에 O(N^2)의 시간 복잡도를 가집니다.
병합 정렬은 정확히 절반씩 나눈다는 점(logN을 보장)에서 최악의 경우에도 O(NlogN)을 보장합니다.

어떻게 O(NlogN) 을 보장할까?
'7 6 5 8 3 5 9 1' 의 8개의 데이터가 있을 경우
시작 - '7 6 5 8 3 5 9 1'

1단계 - 6 7 | 5 8 | 3 5 | 1 9
2단계 - 5 6 7 8 | 1 3 5 9
3단계 - 1 3 5 5 6 7 8 9

너비는 -> 8개 -> N개
높이는 -> 3개 -> logN개
따라서 너비 * 높이 = NlogN 이 나온다 !

공간은 어떻게 될까?
정렬을 수행할때 기존의 배열말고 추가적인 공간이 필요해짐
만약 함수 안에서 배열을 선언하게 된다면 공간을 새로 생성하기 때문에 메모리 자원 낭비가 커질 수 있다.
이와 같이 병합 정렬은 기본적으로 '기존의 데이터를 담을 추가적인 배열이 필요하다'는 점에서 메모리 활용이 비효율적인 문제가 있다.

시간 복잡도: O(NlogN) - 평균적으로 NlogN을 보장한다 !
공간 복잡도: O(N) 
    - but, 재귀 함수안에서 배열을 선언하면 공간이 더 필요하고 temp 배열을 쓰더라도 n만큼 더 필요하다는 거! (제자리 정렬이 아니다!)
    - 즉, 두 개의 배열을 병합할 때 병합 결과를 담아 놓을 배열이 추가로 필요

- 특징 -
1. 퀵소트와는 반대로 안정 정렬(stable sort)
2. 정렬을 위한 공간이 더 필요할 수도있다.
3. LinkedList 정렬이 필요할때 퀵소트 보다 빠르다 (merge sort가 순차적인 비교로 정렬을 진행하므로)
'''

data = [7, 6, 5, 8, 3, 5, 9, 1]
size = len(data)
_sorted = [0 for _ in range(size)]  # 정렬 temp 배열은 반드시 전역 변수로 선언

# m : 시작점
# middle : 중간점
# n : 끝점

def merge(data, m, middle, n):
    i = m
    j = middle + 1
    k = m  # _sorted의 인덱스

    # 작은 순서대로 배열에 삽입
    while(i <= middle and j <= n):
        if data[i] <= data[j]:
            _sorted[k] = data[i]
            i += 1
        else:
            _sorted[k] = data[j]
            j += 1
        k += 1

    # 남은 데이터도 삽입 !
    if i > middle:  # i가 먼저 끝난 경우
        for t in range(j, n+1):
            _sorted[k] = data[t]
            k += 1
    else:
        for t in range(i, middle+1):
            _sorted[k] = data[t]
            k += 1

    # 정렬된 배열을 삽입
    for t in range(m, n+1):
        data[t] = _sorted[t]


def mergeSort(data, m, n):
    # 크기가 1보다 큰 경우
    if m < n:
        middle = (m + n) // 2
        mergeSort(data, m, middle)
        mergeSort(data, middle + 1, n)
        merge(data, m, middle, n)


mergeSort(data, 0, size - 1)
print(data)  # [1, 3, 5, 5, 6, 7, 8, 9]
