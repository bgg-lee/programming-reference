def P1(filename: str) -> list:        
    ##### Write your Code Here #####
    ans =[]
    with open(filename, 'r') as file:
        line = file.readline()
        while line:
            ans.append(line.split())
            line = file.readline()

    return ans  

    ##### End of your code #####