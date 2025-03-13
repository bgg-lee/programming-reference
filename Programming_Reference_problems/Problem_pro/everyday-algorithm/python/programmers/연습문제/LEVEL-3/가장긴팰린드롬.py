'''
* 🙆‍♂️ Created by wwlee94 on 2020.07.30
https://programmers.co.kr/learn/courses/30/lessons/12904

# 프로그래머스 LV3
'''

def solution(s):
    
    # 팰린드롬 검사 함수
    def isPalindrome(string):
        leng = len(string)
        # 짝수면 절반 나눠서, 홀수면 가운데 빼고 절반
        half = leng // 2
        for i in range(half):
            left = i
            right = (leng-1) - i
            if string[i] != string[right]:
                return False
        return True
        
    answer = []
    leng = len(s)
    if leng == 1: return 1
    
    # n개로 이루어진 부분 문자열을 하나씩 검사해봄
    for n in range(2, leng+1):
        # leng-n+1 까지 범위를 잡아준다 -> substring을 i:i+n으로 잡을것이므로
        for i in range(leng-n+1):
            subString = s[i:i+n]
            if isPalindrome(subString):
                answer.append(len(subString))
                break

    if len(answer) == 0: return 1 # 위에서 팰린드롬 길이가 1인 경우는 제외 했으므로
    else: return max(answer)