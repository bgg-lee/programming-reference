/*
* 🤷‍♂️ Created by wwlee94 on 2020.02.24
https://programmers.co.kr/learn/courses/30/lessons/42747

- 문제 접근 방법 -
문제를 보고 'h는 n보다 작거나 같은 값' 임에 인지해야함
'논문 4편 이상이 5번 이상 인용되었다' 라면 h-index는 5가 아닌 4
'논문 4편 이상이 3번 이상 인용되었다' -> 조건에 부합하지도 않음

- 배열 출력 -
Arrays 클래스의 toString 이용
-> System.out.println(Arrays.toString(citations));
*/

import java.util.*;
class Solution {
    public int solution(int[] citations) {
        int leng = citations.length;
        Arrays.sort(citations);

        for(int i=0;i<leng;i++){
            if(citations[i] >= leng - i)
                return leng - i;
        }
        return 0;
    }
}