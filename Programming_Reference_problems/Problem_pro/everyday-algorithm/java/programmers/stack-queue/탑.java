/*
* 🙆‍♂️ Created by wwlee94 on 2020.03.26
https://programmers.co.kr/learn/courses/30/lessons/42588
*/

class Solution {
    public int[] solution(int[] heights) {
        int[] answer = {};
        int size = heights.length;
        answer = new int[size]; // size만큼 0으로 초기화
        
        for(int i=size-1; i>=0; i--){
            for(int j=i-1; j>=0; j--){
                if(heights[i]<heights[j]){
                    answer[i]=j+1;
                    break;
                }
            }
        }
        return answer;
    }
}