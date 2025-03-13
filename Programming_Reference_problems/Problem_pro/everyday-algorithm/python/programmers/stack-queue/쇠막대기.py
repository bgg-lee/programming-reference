'''
* 🤷‍♂️ Created by wwlee94 on 2020.01.18
'()' 일때 레이저를 쏜다 (레이저 쏜다 == 자른 개수를 센다)
Tip: '()' 인 부분을 '0' 같은 하나의 문자열로 치환해서 풀면 더 간단해진다.
-> arrangement.replace('()','0')
'''
def solution(arrangement):
    answer = 0
    stick = 0
    pre_bracket = ''
    for bracket in arrangement:
        if bracket == '(':
            stick += 1
        else:
            if pre_bracket == '(':
                stick -= 1
                answer += stick
            elif pre_bracket == ')':
                stick -= 1
                answer += 1
        pre_bracket = bracket
    return answer

# 진영 코드 -> 범위를 2개씩 잡아서 확인
# for i in range(len(arrangement)-1):
#        if arrangement[i:i+2]=='()':
#            answer += line
#        if arrangement[i:i+2]=='))':
#            line-=1
#            num+=1
#        elif arrangement[i:i+2]=='((':
#            line+=1
#    answer+=num