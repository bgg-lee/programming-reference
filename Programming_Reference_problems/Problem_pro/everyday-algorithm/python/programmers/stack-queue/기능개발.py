'''
* 🙆‍♂️ Created by wwlee94 on 2020.01.17
https://programmers.co.kr/learn/courses/30/lessons/42586

문제에서 '각 기능의 개발속도는 모두 다르기 때문에 뒤에 있는 기능이 앞에 있는 기능보다 먼저 개발될 수 있고, 
이때 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포됩니다.' 라고 주어진 조건을 보면 
먼저 개발이 되더라도(어떤 progresses가 100이 되더라도) progresses의 맨 앞이 100이 되기 전까지는 배포 되지 않음
따라서 종료 조건은 (*반환 값의 모든 원소 합 == 기능들의 개수)를 만족하면 모든 기능이 배포된 경우이므로 해당 조건을 종료 조건으로 잡고 -> *반환 값: 각 배포마다 몇 개의 기능이 배포 되었는지
매 루프마다 progresses의 모든 원소에 하루 진행량(speeds)를 더해주면서 progresses의 맨 앞이 100인지 검사하도록 방향을 잡고 문제를 품
'''
def solution(progresses, speeds):
    answer = []
    cursor = 0
    while sum(answer) != len(progresses):
        count = 0
        progresses = list(map(lambda x, y: 100 if x + y > 100 else x + y, progresses, speeds))
        print(progresses)
        if progresses[cursor] == 100:
            while progresses[cursor] == 100:
                cursor += 1
                count += 1
                if cursor == len(progresses): break
            answer.append(count)
        print(cursor)
        print(count)
    return answer