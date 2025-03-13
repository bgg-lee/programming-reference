'''
* 🙆‍♂️ Created by wwlee94 on 2020.05.23
https://programmers.co.kr/learn/courses/30/lessons/12977
'''

import itertools
import math
def solution(nums):
    def is_prime(x):
        val = int(math.sqrt(x)) + 1
        for i in range(2, val):
            if x % i == 0:
                return False
        return True
        
    answer = 0

    combinations = list(itertools.combinations(nums, 3))
    
    for combination in combinations:
        _sum = sum(combination)
        if is_prime(_sum):
            answer += 1
    return answer