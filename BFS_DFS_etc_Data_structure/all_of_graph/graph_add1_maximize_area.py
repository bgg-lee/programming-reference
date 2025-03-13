"""
You are given a 2D grid of size R x C, consisting of '0' and '1'.
You may change exactly one '0' to '1' (or do nothing if the grid is all '1'),
and then consider the 4-directionally connected islands of '1's in the updated grid.
Return the maximum area of any island you can achieve by performing at most one such flip.
If the grid has no '0', then the area is simply the total area of the entire grid (since all are '1').
1 하나 뒤집어서 넓이 최대로 바꿀 수 있을 때, 그 넓이 값 반환
"""
from typing import List

def largest_island_by_adding_one(grid: List[List[int]]) -> int:
    """
    Given an RxC grid of 0's and 1's, flip exactly one '0' to '1' to maximize 
    the area of a 4-directionally connected island of '1's. Return that max area.
    If the grid is all '1', just return R*C.
    """
    if not grid or not grid[0]:
        return 0
    rows, cols = len(grid), len(grid[0])

    # Step 1: Find connected components of '1'.
    # We'll assign each component an ID, starting from e.g. 2 or 2..3..4 etc.
    # (We avoid 0 or 1 since those are used in the grid.)
    comp_id = 2  # start labeling from 2
    size_map = {}  # comp_id -> size of that island

    def dfs(r, c, id_label):
        stack = [(r, c)]
        grid[r][c] = id_label
        area = 0
        while stack:
            rr, cc = stack.pop()
            area += 1
            for dr, dc in [(1,0),(-1,0),(0,1),(0,-1)]:
                nr, nc = rr + dr, cc + dc
                if 0 <= nr < rows and 0 <= nc < cols:
                    if grid[nr][nc] == 1:
                        grid[nr][nc] = id_label
                        stack.append((nr, nc))
        return area

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1:  # unvisited island
                area = dfs(r, c, comp_id)
                size_map[comp_id] = area
                comp_id += 1

    # If comp_id never advanced beyond 2 => no '1' found => flipping one '0' yields area=1
    # But let's handle the case if the grid was all '1' to begin with:
    if comp_id == 2:
        # means we found no '1' at all OR the entire grid might be all '1'.
        # - If there's at least one '0', flipping it => area=1.
        # - If there's no '0', entire grid is '1'.
        #   We can detect if there's no '0' by scanning or by noticing if any cell is not '1' => but let's do a quick check:
        has_zero = False
        total_one = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 0:
                    has_zero = True
                else:
                    total_one += 1
        
        if not has_zero:
            # all '1', so area = rows*cols
            return rows * cols
        else:
            # no existing '1', so flipping one '0' => area=1
            return 1

    # Step 2: For each '0', check its distinct neighbors' IDs
    max_area = 0
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 0:
                # gather distinct neighbor IDs
                neighbor_ids = set()
                for dr, dc in [(1,0),(-1,0),(0,1),(0,-1)]:
                    nr, nc = r+dr, c+dc
                    if 0 <= nr < rows and 0 <= nc < cols:
                        if grid[nr][nc] != 0:  # it's some island ID
                            neighbor_ids.add(grid[nr][nc])
                # sum the sizes
                merged_area = 1  # flipping this '0' => add 1
                for compid in neighbor_ids:
                    merged_area += size_map[compid]
                if merged_area > max_area:
                    max_area = merged_area

    # Edge case: what if no '0' => the entire grid is all '1'? 
    # We handled that above. Otherwise:
    return max_area

if __name__ == "__main__":
    # Example: 
    # Let's test a grid with some 0's 
    # e.g. if we flip a certain 0, we can merge multiple islands.
    test_grid = [
        [1, 0, 0, 1],
        [1, 1, 0, 0],
        [0, 0, 1, 1]
    ]
    # Make a copy because the function modifies grid in-place
    import copy
    gcopy = copy.deepcopy(test_grid)
    ans = largest_island_by_adding_one(gcopy)
    print("Max island area after flipping one 0:", ans)
