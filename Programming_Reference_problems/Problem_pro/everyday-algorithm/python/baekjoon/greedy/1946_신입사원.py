# https://www.acmicpc.net/problem/1946
# Check 할 것

T = int(input())
result = []


def maximum_new_recruits(T):
    for i in range(T):
        N = int(input())
        score = [list(map(int, input().split())) for j in range(N)]
        score.sort(key=lambda x: x[0]) # 0 인덱스 기준으로 오름차순
        rank = score[0][1]

        count = 1
        for k in score:
            # print("k[0] = %d, k[1] = %d"%(k[0],k[1]))
            # 제외 시킬 목록 temp에 추가
            if rank > k[1]:
                rank = k[1]
                count += 1

        result.append(count)


maximum_new_recruits(T)
for i in result:
   print(i)