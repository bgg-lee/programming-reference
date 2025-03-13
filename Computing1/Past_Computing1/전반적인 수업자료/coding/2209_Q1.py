
def str_perm(s):
    sorted_list_string = sorted(s)
    charac_dict = {char: s.count(char) for char in sorted_list_string}
    def __perHelp(s, substr, lst, totalDict):
        remainDict = {char: s.count(char)-substr.count(char) for char in totalDict.keys()}
        for key, val in remainDict.items():
            if val > 0:
                __perHelp(s, substr + key, lst, totalDict)
        if len(s) == len(substr):
            lst.append(substr)
        return lst
    
    permutations = __perHelp(s, '', [], charac_dict)
    permutations = list(set(permutations))
    return sorted(permutations)        
        
        
a = 'bcaba'
for p in str_perm(a):
    print(p)
print(f"len of perms: ", len(str_perm(a)))