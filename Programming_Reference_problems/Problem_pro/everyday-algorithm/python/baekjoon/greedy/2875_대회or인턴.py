# https://www.acmicpc.net/problem/2875
# Check 할 것
N, M, K = list(map(int,input().split()))


def maximum(N, M, K):
    count = 0
    n = int(N / 2)

    if n < M:
        count = n
        n_mod = N % 2
        m_mod = M - n
    else:
        count = M
        n_mod = N - (M * 2)
        m_mod = 0

    # 클때는 문제 X 그대로 but 작으면 count 조절
    mod = n_mod+m_mod
    if mod < K:
        K = K - mod

        while(K!=0):
            if K==1 or K==2:
                K = 0
                count -= 1
                break
            K = K - 3 # 3명 인턴보내고
            count -= 1 # 1팀 빠지고

    return count


print(maximum(N,M,K))