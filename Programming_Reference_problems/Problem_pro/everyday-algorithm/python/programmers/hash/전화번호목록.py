'''
* 🤷‍♂️ Created by wwlee94 on 2020.01.10
문제에서 이야기하는 '접두어'의 의미를 잘 파악해야함
문자열 중간에 포함되는 문자열은 해당되지 않고 문자열 시작 지점부터 일치하는 문자열만 해당된다.
'''
def solution(phone_book):
    leng = len(phone_book)
    phone_book = sorted(phone_book, key= len) # 길이에 따라 오름차순 정렬
    for i in range(leng-1):
        for j in range(i+1, leng):
            if phone_book[j].startswith(phone_book[i]): # 시작되는지 검증
                return False           
    return True