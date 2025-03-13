def sort(lst_in: list[int]) -> list[int]:
    ## Do Not Change This Function Names: Keep the original function names as specified.
    if len(lst_in) == 1 : return lst_in

    mid = len(lst_in)//2
    left = sort(lst_in[:mid])
    right = sort(lst_in[mid:])
    return Merge(left,right)
def Merge(lst1,lst2) -> list[int]:
    ans = []
    i = 0
    j = 0
    while i<len(lst1) and j<len(lst2) :
        if lst1[i] < lst2[j]:
            ans.append(lst1[i])
            i+=1
        else:
            ans.append(lst2[j])
            j+=1
    if i == len(lst1):
        ans.extend(lst2[j:])
    else : ans.extend(lst1[i:])

    return ans

if __name__ == "__main__":
    test = [4,3,1,10,0,123,6,7,99,45,2,-12,999,65,2]
    print(sort(test))
    '''
    Test your code if you want
    '''