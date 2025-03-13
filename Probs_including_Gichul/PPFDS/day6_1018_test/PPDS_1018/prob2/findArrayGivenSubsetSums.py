def findArrayGivenSubsetSums(n: int, sums: list[int]) -> list[int]:
    sums.sort()  # Time: O(2^n * log(2^n)) = O(n * 2^n)
    shift, l = 0, len(sums)
    result = []
    for _ in range(n):  # log(2^n) times, each time costs O(2^(n-len(result))), Total Time: O(2^n)
        new_shift = sums[0]-sums[1]
        assert(new_shift <= 0)
        has_zero, j, k = False, 0, 0
        for i in range(l):
            if k < j and sums[k] == sums[i]:  # skip shifted one
                k += 1
            else:
                if shift == sums[i]-new_shift:
                    has_zero = True
                sums[j] = sums[i]-new_shift
                j += 1
        if has_zero:  # contain 0, choose this side
            result.append(new_shift)
        else:  # contain no 0, choose another side and shift 0 offset
            result.append(-new_shift)
            shift -= new_shift
        l //= 2
    return result
if __name__ == "__main__":
    lst = [-3,-1,-2,0,0,3,2,1]
    lst2 = [0,0,0,0]
    lst3 = [0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8]
    print(findArrayGivenSubsetSums(3,lst))
    print(findArrayGivenSubsetSums(2,lst2))
    print(findArrayGivenSubsetSums(4,lst3))
    '''
    Test your code if you want
    '''
