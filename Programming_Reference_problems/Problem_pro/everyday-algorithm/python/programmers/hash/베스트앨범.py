'''
* 🙆‍♂️ Created by wwlee94 on 2020.01.13
조건에 맞는 정렬을 잘 사용하는 것이 포인트 !
장르별로 나눈 후에 [재생횟수와 고유번호]를 함께 묶는다.
- 조건에 맞추어 정렬 !
1. 속한 노래가 많이 재생된 장르를 먼저 수록합니다. -> 장르별 총 재생횟수 순 내림차순 정렬
2. 장르 내에서 많이 재생된 노래를 먼저 수록합니다. -> 재생횟수 순 내림차순 정렬
3. 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다. -> 고유 번호 오름차순 + 재생횟수 내림차순 정렬
- 원하는 형태로 만들어 데이터 표시
[[3100, [[2500, 4], [600, 1]]], [1450, [[800, 3], [500, 0], [150, 2]]]]

3100, 1450, .. -> 장르별 총 재생횟수
[2500, 4], [600, 1], .. -> [재생횟수, 고유번호]
'''
# 2020.07.14
from collections import defaultdict
def solution(genres, plays):
    genres_with_plays = list(zip(genres, plays))
    
    albums = defaultdict(list)
    idx = 0
    for genre, play in genres_with_plays:
        albums[genre].append((idx, play)) # 인덱스와 플레이 수를 함께 저장
        idx += 1
    
    top_plays = []
    for key in albums:
        albums[key].sort(key = lambda x:x[0]) # 인덱스 오름차순
        albums[key].sort(key = lambda x:x[1], reverse=True) # 플레이 수 내림차순
        
        # 모든 장르별 총 재생 횟수 구하기
        total = sum(int(v) for (idx, v) in albums[key])
        top_plays.append((key, total))
        
    # 많이 재생된 장르 순으로 정렬
    top_plays.sort(key=lambda x:x[1], reverse=True)
    
    answer = []
    for genre, total in top_plays:
        # 상위 2개만
        top_rate = albums[genre][:2]
        for idx, play in top_rate:
            answer.append(idx)
    return answer


# 2020.01.13
def solution(genres, plays):
    answer = []
    genre_play = []
    genre_sum = []
    genre_type = list(set(genres))
    
    # plays[2] = 500
    for _type in genre_type:
        play = []
        for idx, genre in enumerate(genres):
            if _type == genre: 
                play.append([plays[idx], idx])
        play = sorted(play, key= lambda x: x[1])                    # 3번 조건 해결
        play = sorted(play, key= lambda x: x[0], reverse= True)     # 2번 조건 해결
        genre_play.append(play)
        summ = map(lambda x: x[0], play)
        genre_sum.append(sum(summ))
    genre_info = list(map(list, zip(genre_sum, genre_play)))
    genre_info = sorted(genre_info, key= lambda x: x[0], reverse = True) # 1번 조건 해결
    print(genre_info)
    
    for info in genre_info:
        if len(info[1]) == 1:
            answer.append(info[1][0][1])
        else:
            answer.append(info[1][0][1])
            answer.append(info[1][1][1])
    return answer