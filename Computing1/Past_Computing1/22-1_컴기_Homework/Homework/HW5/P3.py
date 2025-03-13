def P3(filename: str) -> list:        
    ##### Write your Code Here #####
    ans = []
    with open(filename, 'r') as file:
        line = file.readline()
        while line:
            if line.startswith('//') or line.startswith('#'):
                line = file.readline()
            else:
                ans.append(line)
                line = file.readline()
    
    return ans

    ##### End of your code #####