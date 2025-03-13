/*
* 🤷‍♂️ Created by wwlee94 on 2020.03.19
https://programmers.co.kr/learn/courses/30/lessons/42628

- 최대, 최소 우선순위 큐 만들기 -
PriorityQueue<int[]> max_pq = new PriorityQueue<int[]>((o1, o2) -> (o2[1] - o1[1])); // 최대 힙
PriorityQueue<int[]> min_pq = new PriorityQueue<int[]>((o1, o2) -> (o1[1] - o2[1])); // 최소 힙
*/

import java.util.*;
class Solution {
    public int[] solution(String[] operations) {
        int length = operations.length;
        PriorityQueue<int[]> max_pq = new PriorityQueue<int[]>((o1, o2) -> (o2[1] - o1[1])); // 최대 힙
        PriorityQueue<int[]> min_pq = new PriorityQueue<int[]>((o1, o2) -> (o1[1] - o2[1])); // 최소 힙
        
        for(int i=0;i<length;i++){
            String[] split = operations[i].split(" ");
            char oper = split[0].charAt(0);
            int value = Integer.parseInt(split[1]);
            
            // 연산에 따라 동작을 분리
            if (oper == 'I'){
                int[] arr= {i, value};
                max_pq.offer(arr);
                min_pq.offer(arr);
            } else if (oper == 'D'){
                int[] arr = {};
                if(value == 1){
                    if(max_pq.size() == 0) continue;
                    arr = max_pq.poll(); // 최대값 빼고
                    min_pq.remove(arr);  // 뺀 값을 최소 힙에서도 같이 없애준다.
                } else if (value == -1){
                    if(min_pq.size() == 0) continue;
                    arr = min_pq.poll();
                    max_pq.remove(arr);
                }
            }
        }
        int[] answer = {0, 0};
        // 빈값이 아닐 때 최대, 최소 가져오고 비어있으면 0,0 반환
        if (!max_pq.isEmpty() && !min_pq.isEmpty()){ 
            answer[0] = max_pq.poll()[1]; 
            answer[1] = min_pq.poll()[1];
        }
        return answer;
    }
}