from collections import Counter

def foo(s: str) -> str:
    """
    원래 문자열 s에서 인접했던 문자쌍이 최종 결과에서도 붙어 있으면 안 됨.
    또한 s에 등장하는 문자(중복 포함)를 모두 사용해야 함.
    
    예) abccde -> cacebd (가능 예)
        abc -> "" (만들 수 없음)
        "" -> ""
    """
    n = len(s)
    if n < 2:
        # 길이가 0 또는 1이면, 인접 제약 자체가 없으므로 그대로 반환
        return s

    # 1) 인접 금지 쌍(Forbidden adjacency) set 구성 (양방향)
    forbidden = set()
    for i in range(n-1):
        forbidden.add( (s[i], s[i+1]) )
        forbidden.add( (s[i+1], s[i]) )

    # 2) 중복 문자 빈도 수집
    freq = Counter(s)

    # 최종 결과를 저장할 list(문자열로 합치기 전), 답을 찾으면 빠져나오기 위해 관리
    ans_list = []
    found_solution = [False]  # 가변형 자료로 감싸서 내부에서 변경 가능하게

    def backtrack(curr: list):
        if len(curr) == n:
            # 모든 문자를 성공적으로 배치함
            ans_list.append("".join(curr))
            found_solution[0] = True
            return

        last_char = curr[-1] if curr else None

        # freq에 남아 있는 모든 문자 후보 시도
        for c in freq:
            if freq[c] <= 0:
                continue  # 이미 소진된 문자

            # 인접 검사
            if last_char and (last_char, c) in forbidden:
                continue

            # 사용
            freq[c] -= 1
            curr.append(c)

            backtrack(curr)
            if found_solution[0]:
                return  # 한 개만 찾으면 종료

            # 복구
            curr.pop()
            freq[c] += 1

    backtrack([])
    if ans_list:
        return ans_list[0]
    return ""

def bar(s: str) -> str:
    """
    원본 문자열 s에서 인접했던 문자쌍이 최종 결과에서도 인접 X.
    다만 중복된 문자가 여러 개 있어도 최종 결과엔 해당 문자 딱 1번만 사용.

    예) abccde -> acebd (가능 예)
        abc -> "" (불가능)
        "" -> ""
    """
    n = len(s)
    if n < 2:
        return s

    # 1) 인접 금지 쌍 set 구성 (양방향)
    forbidden = set()
    for i in range(n-1):
        forbidden.add((s[i], s[i+1]))
        forbidden.add((s[i+1], s[i]))

    # 2) s에서 쓰인 문자들 중복 제거 (unique) -> 후보 문자 리스트
    unique_chars = list(set(s))
    unique_chars.sort()  # 정렬(필수는 아님, 탐색 순서용)

    ans_list = []
    found_solution = [False]

    def backtrack(curr: list, used: set):
        if len(curr) == len(unique_chars):
            # unique_chars만큼 골라 배치
            ans_list.append("".join(curr))
            found_solution[0] = True
            return

        last_char = curr[-1] if curr else None

        for c in unique_chars:
            if c in used:
                continue  # 이미 사용한 문자이므로 건너뜀

            # 인접 검사
            if last_char and (last_char, c) in forbidden:
                continue

            # 사용
            curr.append(c)
            used.add(c)

            backtrack(curr, used)
            if found_solution[0]:
                return

            # 복구
            curr.pop()
            used.remove(c)

    backtrack([], set())
    if ans_list:
        return ans_list[0]
    return ""
            

print(foo('abccde'))
print(bar('abccdeeec'))
print(bar('abcccccde'))





