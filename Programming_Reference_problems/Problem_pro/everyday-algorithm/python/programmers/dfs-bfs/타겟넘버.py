'''
* 🤷‍♂️ Created by wwlee94 on 2020.02.07
https://programmers.co.kr/learn/courses/30/lessons/43165

- 문제 풀이 접근 - 
'+', '-' 연산 두가지 방법을 선택해 리스트의 합이 target과 같은 값을 출력하는 경우를 카운트 하는 문제
따라서 재귀 함수로 '+' 연산 한번 '-' 연산 한번 진행하면서 
마지막 원소에 접근할 때 모든 원소의 값이 target과 동일한지 검사  
같으면 answer += 1로 카운팅해주면 끝 !
'''
def solution(numbers, target):
    answer = 0
    len_numbers = len(numbers)

    def DFS(idx=0):
        if idx < len_numbers:
            numbers[idx] *= 1
            DFS(idx+1)

            numbers[idx] *= -1
            DFS(idx+1)

        elif sum(numbers) == target:
            nonlocal answer
            answer += 1
            
    DFS()
    return answer

# 2020.07.22 - 최근에 풀었지만, 조금 더 느린 풀이
def solution(numbers, target):
    answer = 0
    candidates = []
    
    def DFS(number=0, i=0):
        nonlocal answer

        if i != 0:
            candidates.append(number)
        
        if len(candidates) == len(numbers):
            if sum(candidates) == target:
                answer += 1
            return
    
        DFS(numbers[i], i+1)
        candidates.pop()
        DFS(numbers[i] * -1, i+1)
        candidates.pop()
        
    DFS()
    return answer