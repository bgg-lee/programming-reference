'''
* 🤷‍♂️ Created by wwlee94 on 2020.06.21
https://programmers.co.kr/learn/courses/30/lessons/43163

-문제 풀이 접근-
https://wwlee94.github.io/category/algorithm/bfs-dfs/word-conversion/
'''

def solution(begin, target, words):
    # 현재 노드에서 갈 수 있는 다른 경로 구하는 함수
    def get_path(current, words):
        arr = []
        for word in words:
            count = 0
            for i in range(len(current)):
                if current[i] == word[i]: count += 1
            if count == len(current) - 1: 
                arr.append(word)
        return arr
    
    # target이 words에 없으면 답을 못 구하니 0 반환
    if target not in words: return 0
    
    path = {} # 각 단어별 변환 가능한 목록 저장한 path 변수
    words.append(begin) # 초기값도 추가
    
    # path 초기화
    for word in words:
        res = get_path(word, words)
        if word not in path.keys():
            path[word] = res
        else:
            path[word].append(res)
    
    answer = []
    queue = [(begin, [begin])]
    while queue:
        x, visited = queue.pop(0)
            
        if x == target:
            answer = visited
            break
        
        # 인접한 노드를 방문
        for node in path[x]:
            if node not in visited:
                queue.append((node, visited + [node]))
    
    return len(answer) - 1