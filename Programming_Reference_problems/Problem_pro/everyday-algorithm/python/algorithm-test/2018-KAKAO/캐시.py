'''
* 🙆‍♂️ Created by wwlee94 on 2020.05.30
https://programmers.co.kr/learn/courses/30/lessons/17680

# 문제를 풀기 전에 LRU(Least Recently Used) 페이지 교체 알고리즘이란?
- 캐시가 사용하는 리소스의 양은 제한되어 있고, 캐시는 제한된 리소스 내에서 데이터를 빠르게 저장하고 접근할 수 있어야 한다.
이를 위해 LRU 알고리즘은 메모리 상에서 가장 최근에 사용된 적이 없는 캐시의 메모리부터 대체하며 새로운 데이터로 갱신
('지금까지 자주 불린 데이터가 미래에도 더 자주 불릴 것' 이라는 개념에서 나온 알고리즘)

1. 현재 가져오려는 데이터가 캐시에 존재하면 캐시에서 데이터를 가져온 후 제거, 다시 캐시 큐의 가장 뒷 부분에 데이터 삽입
2. 캐시에 존재하지 않으면 현재 가져오려는 데이터를 캐시에 삽입
3. 캐시가 꽉 차있다면 사용이 가장 적었던 큐의 가장 앞부분을 제거하고 가져오려는 데이터를 캐시 큐의 가장 뒷 부분에 데이터 삽입

- 문제 풀이 접근 - 
알고리즘 문제 또한 위의 LRU 알고리즘을 적용하면 쉽게 풀 수 있다.
1. 도시를 전부 순회하면서 LRU 알고리즘을 적용한다.
    단, 소문자, 대문자를 구분하지 않으므로 받은 문자열은 전부 소문자로 바꾸어 문제 풀이
2. 위의 LRU 알고리즘 1,2,3 작업을 반복하면 된다.
'''

import collections
def solution(cacheSize, cities):
    answer = 0
    caches = collections.deque()
    
    for city in cities:
        city = city.lower()
        # cache hit
        if city in caches:
            caches.remove(city)
            caches.append(city)
            answer += 1
        # cache miss
        else:
            if cacheSize == 0:
                return 5 * len(cities)
            # 최근 사용하지 않은 캐시 업데이트
            if len(caches) == cacheSize:
                caches.popleft()
            caches.append(city)
            answer += 5
    return answer