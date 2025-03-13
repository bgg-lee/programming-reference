def P3(info: list) -> str:        
    ##### Write your Code Here #####  
    reg = {('MALE','19'):'1', ('FEMALE','19'):'2', ('MALE','20'):'3',
           ('FEMALE','20'):'4' , ('MALE','18'):'9', ('FEMALE','18'):'0'}
    sex_yr = []
    ans = ''
    stri = []

    for i in info:
        if type(i) == str:
            stri.append(i)
        else:
            if len(str(i)) == 4:
                stri.append(str(i))
            elif len(str(i)) == 2:
                stri.append(str(i))
            elif len(str(i)) == 1:
                stri.append('0'+ str(i))

    sex_yr.append(stri[0])
    sex_yr.append(stri[1][:2])
    ans = stri[1][2:] + stri[2] + stri[3] + reg[tuple(sex_yr)]
    
    return ans

    ##### End of your code #####