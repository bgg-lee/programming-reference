'''
* 🙆‍♂️ Created by wwlee94 on 2020.02.04
알파벳 = 'NOPQRSTUVWXYZABCDEFGHIJKLM' -> 특정 알파벳과 'A' 거리가 어느정도 되는지 확인하기 위해
new_name = ['J', 'A', 'E'] -> ['J', '#', 'E'] -> 'A' 문자와 조이스틱으로 변경 완료된 문자는 -> '#'으로 표시한다.

1. new_name이 모두 '#'이 되면 프로세스 종료
2. 현재 커서에 있는 알파벳과 'A'와의 간격을 구함
3. 현재 커서에서 왼쪽, 오른쪽으로 이동 횟수를 구한 후 적게 걸리는 이동 횟수로 방향을 잡는다.
4. 반복 !
'''
import string 

def solution(name):
    # name = 'AABAAAAAAABBB'
    answer = 0
    new_name = [n for n in name]
    for i in range(len(new_name)): 
        if new_name[i] == 'A': new_name[i] = '#'

    alphabet = string.ascii_uppercase[13:] + string.ascii_uppercase[:13] # A의 index -> 13
    
    cursor = 0
    while ''.join(new_name) != '#'*len(name):
        if new_name[cursor] != '#':
            move = abs(alphabet.index(new_name[cursor]) - 13)
            answer += move
            new_name[cursor] = '#'

        if ''.join(new_name) != '#'*len(name):
            right = 0
            right_cursor = cursor
            while new_name[right_cursor] == '#':
                right_cursor += 1
                right += 1
                if right_cursor == len(new_name): right_cursor = 0
                
            left = 0
            left_cursor = cursor
            while new_name[left_cursor] == '#':
                left_cursor -= 1
                left += 1
                if left_cursor == -1: left_cursor = len(new_name) - 1
            if right <= left:
                cursor = right_cursor
                answer += right
            else: 
                cursor = left_cursor
                answer += left
    return answer