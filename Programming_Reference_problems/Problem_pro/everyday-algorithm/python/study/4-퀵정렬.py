'''
* Created by wwlee94 on 2020.05.12

'특정한 값을 기준으로 큰 숫자와 작은 숫자를 나누면 어떨까?'
위의 접근법은 퀵 정렬(Quick Sort)의 아이디어 !

이전 시간에는 선택 정렬, 버블 정렬, 삽입 정렬 알고리즘에 대해 살펴봤습니다.
3가지 알고리즘 모두 시간 복잡도 O(N^2)을 가지는 알고리즘이었습니다.

O(N^2)의 시간 복잡도는 데이터가 10만개만 넘어가도 1억번의 연산이 필요한 상황이 발생하여 일반적인 상황에서 사용하기가 매우 어렵습니다.
이러한 문제점을 해결하기 위해 대표적인 빠른 알고리즘이 바로 퀵 정렬(Quick Sort)입니다.

퀵 정렬은 '분할 정복(Divide and Conquer)' 알고리즘으로 평균 속도가 O(NlogN) 입니다.
여기서 log N이 가지는 힘은 엄청납니다.
거의 상수라고 말할 정도의 시간 단축을 보여줍니다.
예를 들어, 1,000,000개의 데이터가 있다고 가정했을 때
백만은 대략 2^20이니 log N이 을 적용하면 그 값은 20입니다.
1,000,000개의 연산이 20개로 줄어드는 마법..!

퀵 정렬 알고리즘 동작 방식에 대해 설명하자면 퀵 정렬은 하나의 큰 문제를 두 개의 작은 문제로 분할하는 식으로 빠르게 정렬합니다.
즉, 특정한 값(피벗)을 기준으로 큰 숫자와 작은 숫자를 서로 교환한 뒤에 배열을 반으로 나눕니다.
만약 피벗을 가장 앞에 있는 원소로 잡았을 때 왼쪽에서는 피벗보다 큰 수, 오른쪽에서는 피벗보다 작은 수를 찾는 방식

이러한 '분할 정복'이 왜 더 빠르냐?
예를 들어, '1 2 3 4 5 6 7 8 9 10' 의 배열을 
O(N^2) 알고리즘으로 처리하면? -> 10 * 10 = 100번
분할 정복으로 처리하면?
'1 2 3 4 5' -> 5 * 5 = 25번
'6 7 8 9 10' -> 5 * 5 = 25번

퀵 정렬의 단점!?
- 평균은 O(NlogN)이지만 최악의 경우 시간복잡도 O(N^2)가 됩니다.
- 불안정 정렬(unstable sort)
최악은 어떤 경우인지!?
- 이미 정렬이 된 배열에 피봇을 첫번째로 잡고 퀵 정렬 시도하면 분할이 되지 않아 기본 정렬과 같은 시간 복잡도가 걸립니다 !
=> 피벗값이 최소나 최대가 되어 partition이 나누어지지 않을 때 !
=> 해결법은 
int mid = (start + end) / 2;
swap(data, start, mid)

시간 복잡도 : O(N^2)
공간 복잡도 : O(N)
'''

data = [1, 10, 5, 8, 7, 6, 4, 3, 2, 9]
size = len(data)

def quick_sort(data, start, end):
    # 원소가 1개인 경우!
    if start >= end:
        return

    # 개선 방법 !
    # mid = (start + end) // 2;
    # data[start], data[mid] = data[mid], data[start]

    pivot = start  # 키는 첫번째 원소
    i = start + 1  # 키 값의 오른쪽 !
    j = end

    # 엇갈릴 때 까지 반복
    while i <= j:

        # 키 값보다 큰 값을 만날때 까지
        while (data[i] <= data[pivot]) and (i < end):
            i += 1

        # 키 값보다 작은 값을 만날때 까지
        while (data[j] >= data[pivot]) and (j > start):
            j -= 1

        print(data , i, j)

        if i >= j: # 현재 같거나 엇갈렸다면 키 값과 교체
            data[pivot], data[j] = data[j], data[pivot]
        else: # 엇갈리지 않았다면 i와 j를 교체
            data[i], data[j] = data[j], data[i]

        print('변환')
        print(data)

    quick_sort(data, start, j - 1)
    quick_sort(data, j + 1, end)


# 실행
quick_sort(data, 0, size-1)

print(data)

# 내림 차순으로 하려면 아래와 같이 코드 2개만 변경하면 됨
# while (data[i] >= data[pivot]) ~~
# while (data[j] <= data[pivot]) ~~
