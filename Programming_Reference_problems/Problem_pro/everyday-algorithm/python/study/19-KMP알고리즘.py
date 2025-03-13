'''
KMP (Knuth-Morris-Pratt) 알고리즘
이전 시간에 다루었던 일반적인 순차 매칭 알고리즘은 최악의 경우 엄청난 시간이 소요될 수 있습니다.
길이가 10,000,000 인 문자열에서 길이가 1,000인 부분 문자열을 찾으려는 경우 연산 양이 10,000,000,000이기 때문입니다.

따라서, 모든 경우를 다 비교하지 않아도 부분 문자열을 찾을 수 있는 KMP 알고리즘을 사용해야합니다.

KMP 알고리즘은 접두사와 접미사의 개념을 활용하여 '반복되는 연산을 얼마나 줄일 수 있는지'를 판별하여 매칭할 문자열을 빠르게 점프하는 기법입니다.

접두사: a b a
접미사: a b a
a b a c a a b a

우리가 구해야할 것은 위와 같이 접두사와 접미사가 얼마나 일치하는 지에 관한 최대 길이입니다.
'접두사 접미사는 같은 값이여야한다.'


길이 / 문자열  / 최대 일치 길이
1   a             0
2   ab            0
3   aba           1
4   abac          0
5   abaca         1
6   abacaa        1
7   abacaab       2
8   abacaaba      3

# 추가 참고 사이트
- https://bowbowbow.tistory.com/6
'''

def make_table(pattern):
  pattern_size = len(pattern)
  table = [0] * pattern_size
  j = 0
  for i in range(1, pattern_size):
  
    while j > 0 and pattern[i] != pattern[j]:
      j = table[j - 1] # 이전 테이블 값으로 변경
    
    if pattern[i] == pattern[j]:
      j += 1
      table[i] = j
    
  return table

pattern = 'abacaaba'
table = make_table(pattern)
print(table) # [0, 0, 1, 0, 1, 1, 2, 3]
print('------------------------------')
'''
위와 같이 하나씩 접두사와 접미사를 늘려가며 비교하다가 일치하지 않는 경우가 발생하면 일치했던 부분까지 되돌아가서 
다시 검사를 하는 방식으로 빠르게 '최대 일치 길이' 테이블을 구축할 수 있습니다.
이렇게 테이블을 구축한 이후엔 문자열 매칭을 수행할 수 있습니다!
'''

def kmp(parent, pattern):
  parent_size = len(parent)
  pattern_size = len(pattern)
  pattern_table = make_table(pattern)
  
  j = 0
  for i in range(parent_size):
    while j > 0 and parent[i] != pattern[j]:
      j = pattern_table[j - 1]

    if parent[i] == pattern[j]:
      if j == (pattern_size - 1):
        print(f'{i - pattern_size +2}번째에서 찾았습니다.')
        j = pattern_table[j]
      else:
        j += 1

parent = 'ababacabacaabacaaba'
pattern = 'abacaaba'

kmp(parent, pattern)
