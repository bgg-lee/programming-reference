/*
* 🙆‍♂️ Created by wwlee94 on 2020.02.13
https://programmers.co.kr/learn/courses/30/lessons/49191

- Java JDK 8 버전의 Stream 모듈 사용 -
1. Java 8 - String Array일 때
    boolean result = Arrays.stream(alphabet).anyMatch("A"::equals);
2. Java 8 - Primitive Array일 때
    boolean result = IntStream.of(s).anyMatch(x -> x == 0);

- 2차원 배열 출력문 -
    for(int[] array: score){ 
        for(int x: array) 
            System.out.print(x+" ");
        System.out.println();
    }
*/

import java.util.*;
import java.util.stream.*;
class Solution {
    public int solution(int n, int[][] results) {
        int answer = 0;
        int[][] score = new int[n][n];  // 0으로 초기화 됨
        
        for(int[] result: results){
            score[result[0]-1][result[1]-1] = 1;
            score[result[1]-1][result[0]-1] = -1;
        }         
        
        // k: 거쳐가는 노드
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j) score[i][j] = 9999;
                    else if(score[i][k] + score[k][j] == 2){
                        score[i][j] = 1;
                        score[j][i] = -1;
                    }
                }
            }
        }
        
        for(int[] s: score){
            //Java 8 - Primitive Array로 값 체크 방법
            boolean result = IntStream.of(s).anyMatch(x -> x == 0);
            if (!result) answer += 1;
        }
        return answer;
    }
}