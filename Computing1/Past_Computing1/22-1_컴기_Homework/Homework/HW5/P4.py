def P4(filename: str) -> list: 
    ##### Write your Code Here #####
    
    ans = []
    with open(filename, 'r') as file:
        line = file.readline().strip()
        while line:
            a = line.find('#')
            b = line.find('//')
            if a == -1 and b >= 0:              #'//'만 있는 경우 
                line = line[:b]
                ans.append(line.strip())
                line = file.readline().strip()
            elif a >=0 and b == -1:             # '#'만 있는 경우 
                line = line[:a]
                ans.append(line.strip())
                line = file.readline().strip()
            elif a >=0 and b>= 0:               # 둘다 있는 경우
                if a > b:
                    line = line[:b]
                    ans.append(line.strip())
                    line = file.readline().strip()
                else:
                    line = line[:a]
                    ans.append(line.strip())
                    line = file.readline().strip()
            else:                               # 둘다 없는 경우
                ans.append(line)
                line = file.readline().strip()
                
    for i in range(ans.count('')):
        ans.remove('')
        
    return ans

    ##### End of your code #####