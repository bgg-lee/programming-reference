'''
* 🙆‍♂️ Created by wwlee94 on 2020.01.18
https://programmers.co.kr/learn/courses/30/lessons/42587

문제의 조건에 순차적으로 따라가면 풀 수 있는 문제 
다만, 반환되는 값이 '내가 인쇄를 요청한 문서가 몇 번째로 인쇄되는지'에 관한 정보이기 때문에
priorities 배열을 [문서의 중요도, 대기 문서의 위치]와 같이 2차원 배열로 만들어서 조건을 만족하게 하면 됨.

1. 인쇄 대기목록의 가장 앞에 있는 문서(J)를 대기목록에서 꺼냅니다.
2. 나머지 인쇄 대기목록에서 J보다 중요도가 높은 문서가 한 개라도 존재하면 J를 대기목록의 가장 마지막에 넣습니다.
3. 그렇지 않으면 J를 인쇄합니다.

'''
def solution(priorities, location):
    answer = 0
    printed = []
    priorities = list(map(list, zip(priorities, [i for i in range(len(priorities))])))
    
    while len(priorities) != 0:
        over_priority = False
        _next = priorities.pop(0)
        
        for priority in priorities:
            if priority[0] > _next[0]: 
                over_priority = True
                break
        if over_priority: priorities.append(_next)
        else: printed.append(_next)
            
    answer = list(map(lambda x:x[1], printed)).index(location) + 1
    return answer