/*
* 🙆‍♂️ Created by wwlee94 on 2020.03.23
https://programmers.co.kr/learn/courses/30/lessons/42577
*/

import java.util.*;
class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        int length = phone_book.length;
        // 문자 길이로 오름차순
        Arrays.sort(phone_book, (s1, s2) -> s1.length() - s2.length());
        for(int i=0;i<length-1;i++){
            String base = phone_book[i];
            for(int j=i+1;j<length;j++){
                if(phone_book[j].startsWith(base)) answer = false;
            }
        }
        return answer;
    }
}