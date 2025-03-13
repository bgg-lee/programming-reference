/*
* 🤷‍♂️ Created by wwlee94 on 2020.03.06
https://programmers.co.kr/learn/courses/30/lessons/42842
*/

class Solution {
    public int[] solution(int brown, int red) {
        int[] answer = new int[2];
        int total = brown + red;
        for(int row=1; row <= total; row++){
            if (total % row == 0){
                int col = total / row;
                if (row >= col && (row-2) * (col-2) == red) {
                    answer[0] = row;
                    answer[1] = col;
                    return answer;
                }
            }
        }
        return null;
    }
}