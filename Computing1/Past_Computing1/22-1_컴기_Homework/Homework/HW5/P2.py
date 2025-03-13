def P2(filename: str) -> list:        
    ##### Write your Code Here #####
    ans =[]
    with open(filename, 'r') as file:
        line = file.readline()
        while line:
            ans.append(line)
            line = file.readline()

    return ans[::-1]   


    ##### End of your code #####