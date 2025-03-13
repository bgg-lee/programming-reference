'''
* 🤷‍♂️ Created by wwlee94 on 2020.07.01
https://programmers.co.kr/learn/courses/30/lessons/17676
'''

from datetime import datetime
from datetime import timedelta

def solution(lines):
    # 요청 처리를 끝낸 시간 / 요청이 들어온 시간 저장
    end_times, start_times = [], []
    for line in lines:
        tmp = line.split()
        # end = 요청이 끝난 연월일시. duration = 요청이 처리되기까지의 시간.
        end = datetime.strptime(f'{tmp[0]} {tmp[1]}', "%Y-%m-%d %H:%M:%S.%f")
        duration = float(tmp[2][:-1])
        duration = timedelta(seconds = duration)

        # 각 배열에 저장.
        end_times.append(end)
        start_times.append(end - duration + timedelta(seconds = 0.001))

    # 시작한 시간과 끝난 시간의 배열을 합친다. (처리량이 변화할 때는 새 요청이 들어올 때 / 요청이 끝날 때뿐이므로)
    total = start_times + end_times
    
    # 윈도우 기준 = 1초.
    sec = timedelta(seconds = 1)
    _max = 0
    for starts in total:
        result = 0
        for j in range(len(end_times)):
            # 해당 로그 기준으로 1초 안에 다른 요청이 처리 완료되었거나, 다른 요청이 새로 들어온 경우
            if (starts <= end_times[j] < starts + sec) or (starts <= start_times[j] < starts + sec):
                result += 1
            # 아니면, 해당 로그 이전에 요청이 들어와서 1초 안에 요청이 끝나지 않은 경우. 1초 윈도우 전체가 포함되게 된 경우를 말함.
            elif (start_times[j] <= starts) and (end_times[j] >= starts + sec):
                result += 1
        _max = max(_max, result)
    return _max