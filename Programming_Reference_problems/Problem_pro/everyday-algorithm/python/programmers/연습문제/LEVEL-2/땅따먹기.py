'''
* 🤷‍♂️ Created by wwlee94 on 2020.04.30
https://programmers.co.kr/learn/courses/30/lessons/12913
# 프로그래머스 LV2

- 문제 풀이 접근 -
행의 개수가 10만까지 생길 수 있으므로 DP 문제라 파악하고 접근
자기 자신과 같은 열은 더하지 못하므로
자기 자신의 열을 뺀 나머지 중 최대값을 아래로 전달한다.
그 후 마지막 줄의 max값을 출력
land[i-1][:j]를 하면 j열 앞까지 리스트가 뽑히고 
land[i-1][j+1:]을 하면 j+1열부터 끝까지 리스트가 뽑혀서 리스트 끼리 더하면 합쳐진 리스트가 만들어짐
그 후 위의 리스트에서 max 값을 뽑는다.
'''

def solution(land):
    for i in range(1,len(land)):
        for j in range(len(land[0])):
            land[i][j] += max(land[i-1][:j] + land[i-1][j+1:])

    return max(land[-1])

# def solution(land):
#     for row in range(1, len(land)):
#         # 밟을 칸(index) 선택
#         for i in range(4):
#             # 밟은 칸 제외한 나머지 칸
#             rest = set(range(4)) - {i}
#             # 밟은 칸 제외한 나머지 칸들의 최댓값을 다음 row의 index에 저장.
#             land[row][i] += max([land[row-1][index] for index in rest])
#     # 마지막 row에서 얻을 수 있는 점수의 최댓값을 확인한다.
#     return max(land[-1])