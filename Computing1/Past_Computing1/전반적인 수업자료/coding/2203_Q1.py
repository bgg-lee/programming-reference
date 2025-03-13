
def palindrome(s):
    l = len(s)
    checknum = l//2
    for i in range(checknum):
        if s[i] != s[l-i-1]:
            return False
    return True

def substring(s, t):
    return t in s


def max_palindromes(s):
    pal_set = set()
    pal_size = len(s)
    
    while pal_size > 0:
        can_move = len(s) - pal_size + 1
        for i in range(can_move):
            subStr = s[i:i+pal_size]
            if palindrome(subStr):
                is_okay = True
                for p in pal_set:
                    if substring(p, subStr):
                        is_okay = False
                        break
                if is_okay:
                    pal_set.add(subStr)
        pal_size -=1

    return list(pal_set)

s = "kabccbadzdefgfeda"
print(max_palindromes(s))