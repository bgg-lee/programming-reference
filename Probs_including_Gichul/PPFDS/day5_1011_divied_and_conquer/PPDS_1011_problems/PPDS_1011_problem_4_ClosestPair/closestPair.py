import math

def distance(p1, p2):
    return math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)

def closestPair(points: list[tuple[int, int]]) -> float:
    
    ## Do Not Change This Function Names: Keep the original function names as specified.
    
    points_x = sorted(points, key=lambda point: point[0])
    points_y = sorted(points, key=lambda point: point[1])
    closest_pair, min_dist = closest_util(points_x, points_y)
    
    return min_dist
    # return closest_pair, min_dist

# Recursive function to find the closest pair of points
def closest_util(points_x, points_y):
    
    # Base case
    if len(points_x) <= 3:
        min_dist = float('inf')
        closest_pair = None
        for i in range(len(points_x)):
            for j in range(i + 1, len(points_x)):
                d = distance(points_x[i], points_x[j])
                if d < min_dist:
                    min_dist = d
                    closest_pair = (points_x[i], points_x[j])
        return closest_pair, min_dist

    mid = len(points_x) // 2
    mid_point = points_x[mid]

    left_y = []
    right_y = []

    for point in points_y:
        if point[0] < mid_point[0]:
            left_y.append(point)
        else:
            right_y.append(point)

    # Recursively find the closest pair
    closest_left, left_dist = closest_util(points_x[:mid], left_y)
    closest_right, right_dist = closest_util(points_x[mid:], right_y)

    # 1 Choose the pair with the smaller distance
        ## closest_pair = closest_left if closest_left<=closest_right else closest_right
    if left_dist < right_dist:
        closest_pair = closest_left
        min_dist = left_dist
    else:
        closest_pair = closest_right
        min_dist = right_dist
    # 2 Gather points near the boundary - 이걸 어케 하냐 ;;
    strip = []
    for point in points_y:
        if abs(point[0]-mid_point[0]) < min_dist:
            strip.append(point)
    # 3 Compare distances between all points - 이걸 어케 하냐;;
    strip_mid_dist = min_dist
    strip_closet_pair = closest_pair
    for i in range(len(strip)):
       # Only need to check the next 6 points in the sorted strip
       for j in range(i+1,min(i+7,len(strip))):
            d = distance(strip[i],strip[j])
            if d < strip_mid_dist:
                strip_mid_dist = d
                strip_closet_pair = (strip[i],strip[j])

    return closest_pair, min_dist


if __name__ == "__main__":
    
    '''
    Test your code if you want
    '''
    # 예제 사용
    points = [(0, 0), (1, 1), (2, 2), (5, 5), (1, 2)]
    min_distance = closestPair(points)
    print(f"distance: {min_distance}")