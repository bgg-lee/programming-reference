def subset(lst_in: list[int]) -> list[list[int]]:
    def helper(path):
        if not path :
            return
        if path not in ans:
            ans.append(path)
        n = len(path)
        for i in range(n):
            temp = path[:i]+path[i+1:]
            helper(temp)

    ans = [[]]
    helper(lst_in)
    return ans


if __name__ == "__main__":
    test = [1,2,3]
    print(subset(test))
    '''
    Test your code if you want
    '''