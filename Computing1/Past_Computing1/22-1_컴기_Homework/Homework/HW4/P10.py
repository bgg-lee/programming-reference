def P10(words: set, query_word: str) -> bool:
    ### Write code here ###
    

    ok = []
    
    for word in words:
        if len(word) == len(query_word):
            count = 0
            for ix in range(len(word)):
                if word[ix] != query_word[ix]:
                    count += 1

            ok.append(count)

    if 1 in ok: 
        return True 
    
    else:
        return False

    ### End of your code ###     
