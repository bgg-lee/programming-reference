def P5(filename: str) -> int:        
    ##### Write your Code Here #####
    ans = []
    
    with open(filename, 'r') as file:
        entire = file.read()
        entire = entire.replace(' ', ',')
        entire = entire.replace('\n', ',')
        words = entire.split(',')
    
    for word in words:
        ans.append(len(word))

    
    return max(ans)


    ##### End of your code #####