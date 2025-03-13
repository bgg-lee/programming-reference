def P1(parentheses: str) -> bool:  
    ##### Write your Code Here #####   
    stack = []
    pairs = {')':'(', '}':'{', ']':'['}
    
    for c in parentheses:
        if c == '(' or c == '{' or c == '[':
            stack.append(c)
        else:
            if len(stack) == 0:
                return False
            else:
                if stack.pop() != pairs[c]:
                    return False
    
    return len(stack) == 0

    ##### End of your code #####

