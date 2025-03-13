# https://www.acmicpc.net/problem/1120
# 🤷‍♂️문제 풀이에 개선이 필요함 !!

A, B = list(input().split())


def diff_count(A, B):

    #조건 만족할 때 까지 반복
    while(True):
        diff = len(B) - len(A)
        result = 9999
        if diff == 0:
            result = operation(A,B,0,len(B),0)
            break
        # A가 B에 포함되어 있다면 다 추가하면 되니 무조건 0
        if A in B:
            result = 0
            break
        else :
            start = -1
            # 하나하나 검사 시작
            for i in range(0,diff+1):
                temp = operation(A,B,0,len(A),i)
                if result > temp :
                    result = temp
                    start = i

            # 시작위치 기준 0 이면 뒤에 붙히고 나머진 앞에 붙힌것
            if start == 0: A = A + (B[len(A)])
            else: A = (B[start-1]) + A

    return result


# 문자열이 같을 때 차이 비교 한 개수 구하는 함수
def operation(A, B ,s , e, v):
    count = 0
    for i in range(s,e):
        if A[i] != B[i+v]:
            count += 1
    return count


print(diff_count(A, B))
