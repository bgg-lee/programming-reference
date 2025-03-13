# def Per(lst : list[int]) -> list[list[int]]:
#     ans = []
#     if not lst : return []
#     if len(lst) == 1 : return [lst]

#     for i in range(len(lst)):
#         curr = [lst[i]]
#         rest = lst[:i]+lst[i+1:]
        
#         temp = Per(rest) # Recursion
#         for j in range(len(temp)):
#             merge = curr + temp[j]
#             if merge not in ans:
#                 ans.append(merge)

#     return ans

# iterative하게 recursive 문제 풀어보기?
def Per(lst:list[int])->list[list[int]]:
    ans = [[]]

    for num in lst:
        new = []
        for perm in ans:
            for i in range(len(perm)+1):
                new_perm = perm[:i] + [num] + perm[i:]
                if new_perm not in new: # 중복 제거
                    new.append(new_perm)
        ans = new
        # print(ans)
    return ans


if __name__ == "__main__":
    test = [1,1,3]
    print(Per(test))