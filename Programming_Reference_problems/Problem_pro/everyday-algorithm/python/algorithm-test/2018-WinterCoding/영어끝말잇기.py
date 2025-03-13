'''
* 🙆‍♂️ Created by wwlee94 on 2020.05.22
https://programmers.co.kr/learn/courses/30/lessons/12981
'''

def solution(n, words):
    answer = [0, 0]

    member = {i+1:0 for i in range(n)}
    check_words = []
    
    leng = len(words)
    for i in range(leng):
        turn = (i%n) + 1
        member[turn] += 1
        
        # 단어가 일치하지 않는 경우
        if check_words:
            if check_words[-1][-1] != words[i][0]:
                answer = [turn, member[turn]]
                break
        
        # 중복된 단어로 인한 탈락
        if words[i] not in check_words:
            check_words.append(words[i])
        else:
            answer = [turn, member[turn]]
            break
            
    return answer