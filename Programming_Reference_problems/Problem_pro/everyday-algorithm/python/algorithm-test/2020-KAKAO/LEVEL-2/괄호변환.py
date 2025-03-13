'''
* 🙆‍♂️ Created by wwlee94 on 2020.04.10
https://programmers.co.kr/learn/courses/30/lessons/60058

# 프로그래머스 LV2 - 성공했지만 푸는데 오래걸렸다.

- 문제 풀이 접근 -
알고리즘 문제보다는 구현에 가까운 문제 !
1. 문제에 주어지는 기능들을 각각의 함수로 분리해서 구현한 후
2. 지문에서 주어진 순서대로 기능을 대입해 구현하면 끝 !
'''

def solution(p):
    return process(p)

def process(string):
    if string == '': return ''
    
    u, v = split_balanced(string)
    if is_correct(u):
        u += process(v)    
        return u
    else:
        empty = '('
        empty += process(v)
        empty += ')'
        u = u[1:-1] # 첫번째, 마지막 제거
        empty += reverse(u)
    return empty

# 균형잡힌 괄호인지?
def is_balanced(string):
    return string.count('(') == string.count(')')
    
# 올바른 괄호 문자열인지?
def is_correct(string):
    stack = []
    
    for s in string:
        if s == '(':
            stack.append(s)
        elif s == ')':
            if len(stack) == 0:  return False
            stack.pop()
    return True
    
def split_balanced(string):
    leng = len(string)
    balance = ''
    for i in range(leng):
        balance += string[i]
        if is_balanced(balance):
            return balance, string[i+1:]
        
# 괄호 방향 뒤집기
def reverse(string):
    reverse = ''
    for s in string:
        if s == '(':
            reverse += ')'
        else:
            reverse += '('
    return reverse