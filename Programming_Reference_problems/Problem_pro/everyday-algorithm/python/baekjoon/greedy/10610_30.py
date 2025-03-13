# https://www.acmicpc.net/problem/10610

N = input()
def sol(N):
    lst = []
    for i in N:
        lst.append(int(i))

    lst.sort(reverse=True)

    # 30의 배수 -> 30,60,90,120,150 ... -> 0이 들어감 -> 모든 자리 수 더하면 3으로 나누어짐
    if 0 in lst:
        if sum(lst) % 3 == 0:
            result = ""
            for i in lst:
                result += str(i)
            return result

    return -1

result = sol(N)
print(result)



