'''
* 🙆‍♂️ Created by wwlee94 on 2020.02.01
1. command[0] -> LIST 자르는 시작 지점
2. command[1] -> LIST 자르는 마지막 지점
3. command[2] -> 1, 2에서 잘라서 나온 LIST의 몇 번째 원소인지
'''
def solution(array, commands):
    answer = []
    for command in commands:
        slice_array = sorted(array[command[0]-1:command[1]])
        answer.append(slice_array[command[2]-1])
    return answer