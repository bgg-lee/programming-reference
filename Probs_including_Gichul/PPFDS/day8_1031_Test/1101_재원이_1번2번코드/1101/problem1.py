import sys
sys.setrecursionlimit(10**6)  # setting recursion limit to prevent stack overflow

def problem1(N: int, M: int, V: list[list[int]]) -> int:
    
    # Write your code

    ## recursion으로 풀어보자 ~
    ## vertex를 다 뒤집어서 다른 노드들에 다 도달 가능한 노드 찾기

    ## list[set[int]] 에 대해, list 크기를 300개로 하고 .. 
    ## python에서 리스트 크기 ....도 까먹엇네 
    ## 한 vertex 마다 도달 가능한 노드를 update
    ## 시간 복잡도는 2000 * union
    ## 공간 복잡도 ...

    ## idx i에서 도달 가능한 노드들을 set으로 관리
    connected_node = [set() for _ in range(N+1)]
    for i in range(1, N+1): 
        ## 1부터 N까지, 자기 자신은 도달 가능으로 넣어줌
        connected_node[i] = connected_node[i].union(set([i]))
    

    for v in V:
        ## 기존 edge: a->b / 
        ## reverse해서 생각. b->a로 .. 바꿔서 도달 가능 노드 업데이트
        a = v[0]
        b = v[1]

        ## b리스트에 a를 도달 가능으로 추가해줌
        ## a와 connected_node[b]를 union
        connected_node[b] = connected_node[b].union(set([a]))
    


    ## 쭉 돌면서 .... 계속 union해서 같아질때까지 반복??? ..

    count = []
    ## 각 노드에 대해
    for i in range(1, N+1):

        while True:
            origin_node = connected_node[i].copy()

            temp_set = connected_node[i].copy()
            for _ in range(len(temp_set)):
                neighbor = temp_set.pop()
                connected_node[i] = connected_node[i].union(connected_node[neighbor])

            if (connected_node[i] == origin_node):
                break

        count.append(len(connected_node[i]))
    

    return sum([i == N for i in count])

if __name__ == "__main__":
    
    # Test your code
    
    print(problem1(2, 1, [[1, 2]]))
    print(problem1(1, 1, [[1, 1]]))
    print(problem1(3, 0, []))

    # pass