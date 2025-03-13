'''
* 🙆‍♂️ Created by wwlee94 on 2020.04.08
https://programmers.co.kr/learn/courses/30/lessons/60057

# 프로그래머스 LV2 - 성공했지만 푸는데 오래걸렸고 가독성이 떨어진 코드였음
'''

# 향상된 풀이
def solution(s):
    leng = len(s)
    min_zip = leng # 최악의 경우
    a = ''

    for i in range(1, leng//2 + 1):
        output = ''

        zip_str = s[:i] # 초기값
        zip_cnt = 1
        for j in range(i, leng, i):
            token = s[j:i+j]
            if zip_str == token:
                zip_cnt += 1
            else:
                output += f'{zip_cnt}{zip_str}' if zip_cnt > 1 else zip_str
                zip_str = token
                zip_cnt = 1

        output += f'{zip_cnt}{zip_str}' if zip_cnt > 1 else zip_str

        if min_zip > len(output):
            min_zip = len(output)

    return min_zip

# 이전 풀이
# def solution(s):
#     answer = []
#     leng = len(s)
    
#     if leng == 1:
#         return 1
    
#     for i in range(1, int(leng/2)+1):
#         new_string = []
#         st = 0
#         ed = i - st
#         # 리스트로 파싱
#         while True:
#             if ed <= leng:
#                 new_string.append(s[st:ed])
#                 st = ed
#                 ed += i
#             else:
#                 _str = s[st:]
#                 if _str != '':
#                     new_string.append(_str)
#                 break
#         # print(new_string)
#         # print('')
#         # 압축
#         compression = ''
#         count = 1
#         pre = ''
#         for j, string in enumerate(new_string):
#             if pre == string:
#                 count += 1
#             elif pre != string:
#                 if count != 1:
#                     compression += str(count) + pre
#                     count = 1
#                 else:
#                     compression += pre
                    
#             if j == len(new_string)-1:
#                 if count != 1:
#                     compression += str(count) + string
#                 else:
#                     compression += string
#             pre = string
        
#         # print(compression)
#         answer.append(len(compression))

#     return min(answer)