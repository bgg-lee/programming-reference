'''
* 🤷‍♂️ Created by wwlee94 on 2020.06.02
https://programmers.co.kr/learn/courses/30/lessons/17683

- 문제 풀이 접근 -
문자열 비교에서 이런 문제를 처리해야 할 일이 2가지가 있다.
첫째로, 토큰화 Tokenizing를 통해 “ABC#”을 [“A”, “B”, “C#”] 식의 배열로 변환한 후에 비교를 수행한다.
둘째로, 두 글자로 된 “C#”, “D#”, “F#” 등을 악보에서 사용되지 않는 문자인 “c”, “d”, “e” 등으로 치환 Substitution한 후에 문자열 비교 함수를 수행한다.

이번 문제 풀이는 두번째 방식을 사용한다.
1. 위의 두번째 방식에 대한 함수를 생성해 문자열을 치환한다.
2. 재생 시간 함수를 생성해 총 재생 시간을 구한다.
3. 재생 시간으로 실제 재생된 악보를 구한다.
4. 찾고자하는 악보(m) 과 실제 재생된 악보(play_sheet)를 비교하여 일치하는지 검사한다.
5. 재생 시간이 긴 순서 최우선 / 먼저 입력된 음악 차우선
'''
from datetime import datetime
def solution(m, musicinfos):
    # 핵심
    def replace_sheet(s) :
        s = s.replace('A#','a')
        s = s.replace('F#','f')
        s = s.replace('C#','c')
        s = s.replace('D#','d')
        s = s.replace('G#','g')
        return s

    # 재생 시간 (00:00 을 넘기는 경우는 없다 = end hour가 무조건 크다)
    def get_play_time(start, end):
        start_time = datetime.strptime(start, '%H:%M')
        end_time = datetime.strptime(end, '%H:%M')
        
        total_seconds = (end_time - start_time).total_seconds()
        return int(total_seconds / 60)
    
    m = replace_sheet(m)
    answer = []
    count = 0
    for info in musicinfos:
        info = info.split(',')
        start = info[0]
        end = info[1]
        title = info[2]
        sheet = replace_sheet(info[3])
        leng_sheet = len(sheet)
        
        # 실제로 재생된 악보 구하기
        play_sheet = ''
        play_time = get_play_time(start, end)
        for i in range(play_time):
            play_sheet += sheet[i%leng_sheet]
        
        # 일치하는지 검사
        leng_m = len(m)
        idx = play_sheet.find(m)
        if idx > -1:
            answer.append([title,play_time,count])
        count += 1

    if len(answer) == 0: return "(None)"
    if len(answer) >= 2: answer.sort(key=lambda x: (-x[1], x[2]))
    return answer[0][0]