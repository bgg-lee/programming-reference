# https://www.acmicpc.net/problem/1931

N = int(input())
TIME = [list(map(int, input().split())) for i in range(N)]
RESULT = []

# 시작시간과 종료시간이 같은 경우가 존재함 1,2 / 2,2 나올시 1,2가 우선시 되어야하기 때문
TIME.sort(key=lambda x: x[0])
# 핵심 로직 -> 끝나는 시간 기준으로 오름차순!
TIME.sort(key=lambda x: x[1])

# 다 검사할 필요 없음 맨 앞에서 선택하면 그게 답
k = [0, 0]
index = 0
for i in TIME:
    if k[1] <= i[0]:
        k = i
        RESULT.append(i)
print(len(RESULT))

