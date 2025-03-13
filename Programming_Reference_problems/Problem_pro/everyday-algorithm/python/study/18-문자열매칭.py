'''
곧 다루게 될 알고리즘은 KMP 알고리즘으로 대표적인 문자열(String) 매칭 알고리즘입니다.
기본적으로 문자열 매칭 알고리즘이란?
- 특정한 글이 있을 때 그 글 안에서 하나의 문자열을 찾는 알고리즘입니다.

하지만 !
KMP에 대해서 다루기 전에 '단순 비교 문자열 매칭' 알고리즘에 대해 알아봅시다.
'단순 비교 문자열 매칭' 알고리즘은 말 그대로 하나씩 확인하는 알고리즘으로 가장 간단한 형태의 알고리즘입니다.

예시)
'ABCDF' 라는 문자열에서 'BC'를 찾고 싶은 경우

# 1번째 비교 (index -> 0)
  A B C D F
  B C
# 2번째 비교 (index + 1 -> 1)
  A B C D F
    B C

찾기 완료 !
'''

# parent -> 어떤 문자열에서 찾고 싶은지
# pattern -> 찾고 싶은 문자열


def find_string(parent, pattern):
    # 두 문자열이 동일한지?
    def is_finded(i):
        for j in range(pattern_size):
            if parent[i+j] != pattern[j]:
                return False
        return True

    parent_size = len(parent)
    pattern_size = len(pattern)

    for i in range(parent_size - pattern_size):
        if is_finded(i):
            return i

    return -1


parent = 'Hello World'
pattern = 'llo W'
# pattern = 'llo H'

result = find_string(parent, pattern)
if result == -1:
    print('찾을 수 없습니다.')
else:
    print(f'{result + 1}번째 에서 찾았습니다.')
