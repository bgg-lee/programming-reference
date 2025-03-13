# https://www.acmicpc.net/problem/1026

import sys

input_s = lambda: sys.stdin.readline()

N = int(input_s())

A = list(map(int, input_s().split()))
B = list(map(int, input_s().split()))


# 제일 큰값 * 제일 작은값해야 최소값이 나옴
def treasure(N,A,B):
    S = 0
    A.sort()
    B.sort(reverse=True)

    for i in range(N):
        S += (A[i] * B[i])

    return S


print(treasure(N,A,B))

# def treasure(N,A,B):
#     S = 0
#
#     # B를 오름차순한 새로운 rank_B 생성 -> 원본 B 배열의 작은수~큰수의 index위치를 알기 위함
#     rank_B = sorted(B)
#     index = []
#     for i in rank_B:
#         index.append(B.index(i)) # 오름차순으로 정렬된 rank_B의 값으로 해당 값이 B의 인덱스에 몇번째에 있는지 저장
#
#     A.sort(reverse=True)
#     rank_A = [0 for i in range(N)] # 0으로 초기화
#     for i in range(N):
#         rank_A[index[i]] = A[i] # B(작은순)의 위치에 따라 새로운 rank_A 배열 생성
#
#     # print(index)
#     # print(rank_A)
#     # print(B)
#     for i in range(0,N):
#         S += (rank_A[i]*B[i])
#
#     return S