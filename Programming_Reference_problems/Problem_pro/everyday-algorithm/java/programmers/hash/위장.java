/*
* 🙆‍♂️ Created by wwlee94 on 2020.03.24
https://programmers.co.kr/learn/courses/30/lessons/42578
*/
import java.util.*;
class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        Map<String, Integer> map = new HashMap<>();
        for (String[] cloth: clothes){
            if(!map.containsKey(cloth[1])) map.put(cloth[1], 0);
            int val = map.get(cloth[1]);
            map.put(cloth[1], val+1);
        }
        
        // 조합의 수 (종류의 개수 + 1)!
        for(int cnt : map.values()){
            answer *= (cnt+1);
        }
        return answer - 1; // 최소 한개 이상 입으니
    }
}