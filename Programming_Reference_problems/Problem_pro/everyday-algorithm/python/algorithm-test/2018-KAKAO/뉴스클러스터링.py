'''
* 🙆‍♂️ Created by wwlee94 on 2020.05.29
https://programmers.co.kr/learn/courses/30/lessons/17677

- 문제 풀이 방법 -
1. 문자열을 두 글자씩 끊어 다중 집합을 만들어야한다.
2. 다중 집합을 구현하려면 각 두 문자열의 리스트를 다음과 같이 만든다.
   temp = set(set_A | set_B)
   그리하면 두 문자열의 모든 종류가 담긴다.
3. 나온 모든 종류를 순회하며 각 문자열의 개수를 세어 dict로 만든다.
   개수가 작은 것은 추후 교집합이 되고 큰 것은 합집합에 포함된다.
4. 나온 교집합과 합집합을 문제의 조건에 맞게 계산하여 결과를 출력한다.
'''
import re
def solution(str1, str2):
    p = re.compile('[a-z]{2}')
    
     # 문자열을 두 글자씩 끊어 리스트로 만들어주는 메서드
    def split_list(string):
        leng = len(string)
        string = string.lower()
        i = 0 ; j = 1
        arr = []
        for _ in range(leng-1):
            res = string[i] + string[j]
            if p.match(res):
                arr.append(res)
            i += 1
            j += 1
        return arr
            
    list_A = split_list(str1)
    list_B = split_list(str2)
    
    set_A = set(list_A)
    set_B = set(list_B)
    temp = set(set_A | set_B)  # 각 A, B 집합의 합집합의 모든 종류
    
    inter_dic = {} # 교집합 종류를 count 해주는 dictionary
    union_dic = {} # 합집합 종류를 count 해주는 dictionary
    for t in temp:
        a_count = list_A.count(t)
        b_count = list_B.count(t)
        inter_dic[t] = min(a_count, b_count)
        union_dic[t] = max(a_count, b_count)
    
    # 다중 집합의 교집합
    intersection = []
    for key in inter_dic:
        for i in range(inter_dic[key]):
            intersection.append(key)
    
    # 다중 집합의 합집합
    union = []
    for key in union_dic:
        for i in range(union_dic[key]):
            union.append(key)

    answer = 0
    if len(union) == 0:
        answer = 1
    elif len(intersection) == 0:
        answer = 0
    else:
        answer = len(intersection) / len(union)
    return int(answer * 65536)