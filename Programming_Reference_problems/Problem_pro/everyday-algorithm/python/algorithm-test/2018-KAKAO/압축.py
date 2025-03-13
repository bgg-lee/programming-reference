'''
* 🤷‍♂️ Created by wwlee94 on 2020.06.04
https://programmers.co.kr/learn/courses/30/lessons/17684

- 문제 풀이 접근 - 
구현 능력을 물어보는 문제로 문제의 조건에 맞게 구현하면 되는 문제
문제가 이해가 되지 않아 예제만 보고 판단해서 문제 풀다가 풀지 못했음
문제를 정확히 이해한 뒤 구현 알고리즘을 적용해서 풀어야함 !
'''
def solution(msg):
    answer = []
    dic = {}
    
    ch = 65 # 'A'
    num = 1
    while ch != 91:
        dic.update({ chr(ch): num })
        ch = ch + 1
        num += 1

    idx = 0
    maxIdx = 27
    length = 1
    answer = []
    while True:
        length += 1
        _input = msg[idx:idx+length-1] # 현재 입력
        _next = msg[idx:idx+length] # 다음 입력
        if _next not in dic:
            answer.append(dic[_input]) # 찾은 문자 색인 번호 저장
            dic[_next] = maxIdx # 사전에 없는 문자 등록
            maxIdx += 1
            idx += length-1 # 다음 입력 idx 변경
            length = 1 # 초기화
        else:
            if idx+length-1 == len(msg):
                answer.append(dic[_input])
                break
    return answer