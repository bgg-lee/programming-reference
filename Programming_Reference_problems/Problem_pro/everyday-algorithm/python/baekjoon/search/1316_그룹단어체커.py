# https://www.acmicpc.net/problem/1316
ㄴ
N = int(input())
S = [input() for i in range(N)]

def checker(S):
    result = 0
    for i in S:
        group = []   # 그룹단어를 저장할 리스트
        temp = i[0]  # 현재 검사하고 있는 단어의 이전단어 저장할 변수
        flag = True  # count++ 해줄지 안해줄지 정하는 flag
        group.append(temp)
        for j in i:
            if j == temp: continue  # 같으면 넘어가고
            else :                  # 다르면 조건 검사
                if j in group:      # 추가할것인지(temp도 변경) 이미 group에 추가되어 있는지(그룹단어가 아님) 검사
                    flag = False
                    break
                else:
                    group.append(j)
                    temp = j
        if flag is True:
            result += 1
    return result

print(checker(S))