def sort(lst_in: list[int]) -> list[int]:
    ## Do Not Change This Function Names: Keep the original function names as specified.

    if len(lst_in) <= 1 : return lst_in

    #Divide
    mid = len(lst_in)//2

    lst_in_1 = sort(lst_in[:mid])
    lst_in_2 = sort(lst_in[mid:])

    return Merge(lst_in_1,lst_in_2)

def Merge(lst1,lst2) -> list:
    ans = []
    while lst1 and lst2 :
        if lst1[0] > lst2[0]:
            ans.append(lst2[0])
            lst2 = lst2[1:]
        else :
            ans.append(lst1[0])
            lst1 = lst1[1:]
    if lst1:
        ans += lst1
    else : ans += lst2
    
    return ans


    """
    for i in range(len(lst_in)):
        smallest = i
        for j in range(i+1,len(lst_in)):
            if lst_in[j]<lst_in[smallest]:
                smallest = j
        lst_in[i], lst_in[smallest] = lst_in[smallest], lst_in[i]
    return lst_in
    """
if __name__ == "__main__":
    test = [4,3,1,10]
    print(sort(test))
    '''
    Test your code if you want
    '''