def P1(parentheses: str) -> bool:  
    ##### Write your Code Here #####      
    stack = []
    m = {
        ')': '(',
        '}': '{',
        ']': '['
        }
    for c in parentheses:
        if c == '(' or c == '{' or c == '[':
            stack.append(c)
        else:
            if stack.pop() != m[c]:
                return False


    return len(stack) == 0
    ##### End of your code #####

