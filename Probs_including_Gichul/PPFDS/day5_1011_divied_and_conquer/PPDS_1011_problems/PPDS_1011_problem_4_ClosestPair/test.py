def distance(a:tuple,b:tuple)->int:
    return ((a[0]-b[0])**2 + (a[1]-b[1])**2)**0.5

def closestPair(points:list[tuple[int,int]]) -> int:
    n = len(points)
    ans = []
    for i in range(n):
        temp = float('inf')
        for j in range(i+1,n):
            temp = min(temp,distance(points[i],points[j]))
        ans.append(temp)
    print(ans)
    return min(ans)


if __name__ == "__main__":
    
    '''
    Test your code if you want
    '''
    # 예제 사용
    points = [(0, 0), (1, 1), (2, 2), (5, 5), (1, 2)]
    min_distance = closestPair(points)
    print(f"distance: {min_distance}")

    # print(distance((0,0),(1,1)))