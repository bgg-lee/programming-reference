"""
You have an RxC binary matrix (each cell is '0' or '1'). 
Find the area of the largest rectangle containing only '1's.
matrix에서 직사각형의 최대 넓이
"""
def largest_rectangle_in_hist(heights):
    stack = []
    max_area = 0
    for i, h in enumerate(heights + [0]):
        while stack and h < heights[stack[-1]]:
            height = heights[stack.pop()]
            left = stack[-1]+1 if stack else 0
            width = i - left
            area = height * width
            if area>max_area:
                max_area = area
        stack.append(i)
    return max_area

def maximal_rectangle(matrix):
    if not matrix or not matrix[0]:
        return 0
    rows, cols = len(matrix), len(matrix[0])
    heights = [0]*cols
    max_rect = 0
    for r in range(rows):
        for c in range(cols):
            if matrix[r][c] == '1':
                heights[c]+=1
            else:
                heights[c]=0
        max_rect = max(max_rect, largest_rectangle_in_hist(heights))
    return max_rect

if __name__ == "__main__":
    grid = [
        ['1','0','1','0','0'],
        ['1','0','1','1','1'],
        ['1','1','1','1','1'],
        ['1','0','0','1','0']
    ]
    print("Maximal rectangle area:", maximal_rectangle(grid))
    # Expect 6 (the 2x3 rectangle in the middle rows).
