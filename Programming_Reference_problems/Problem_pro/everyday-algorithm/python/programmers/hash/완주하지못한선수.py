'''
* 🙆‍♂️ Created by wwlee94 on 2020.02.08
- collections 모듈의 Counter를 이용해 구하면 쉽게 구할 수 있다.
answer = collections.Counter(enumerate)
EX) answer -> Counter({'mislav': 1})
EX) answer.keys() -> dict_keys(['mislav'])
EX) list(answer) -> ['mislav']

'''
import collections
def solution(participant, completion):
    answer = collections.Counter(participant) - collections.Counter(completion)
    return list(answer)[0]

# 나의 풀이
# def solution(participant, completion):
#     answer = ''
#     leng = len(participant)
#     participant.sort()
#     completion.sort()
#     for i in range(leng):
#         if i == leng - 1:
#             return participant[-1]
#         if participant[i] != completion[i]:
#             return participant[i]
#     return answer