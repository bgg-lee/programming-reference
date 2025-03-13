def P3(A: list, B: list) -> int:

    ### Write code here ###
    
#     ansA = 0
#     ansB = 0
    nowA = 0
    nowB = 0
    sumA = 0
    sumB = 0
    final = 0
    sum_idxA = dict()
    sum_idxB = dict()
    
    for i in range(len(A)):    
        if A[i] == 1:
            sumA += 1
        
        if B[i] == 1:
            sumB += 1
        
        if sumA == sumB:
            final = i+1
        
        
        elif sumA < sumB:
            if (sumB-sumA) in sum_idxB:
                final = max(final, i - sum_idxB[(sumB-sumA)])
            else:
                sum_idxB[(sumB-sumA)] = i
            
        else:
            if (sumA-sumB) in sum_idxA:
                final = max(final, i - sum_idxA[(sumA-sumB)])
            else:
                sum_idxA[(sumA-sumB)] = i

        
#         print(i, "A:", sumA)
#         print(i, "B:", sumB)
#         print(i, "final:", final)
                    
    return final
    
    ### End of your code ###  
  