/*
* 🤷‍♂️ Created by wwlee94 on 2020.02.15
https://programmers.co.kr/learn/courses/30/lessons/43165

- Tip -
1. class 부분에 전역으로 사용할 static 변수 or 일반 변수 만들어서 사용해도 됨
EX) 
class Solution{
    static int[] numbers;
    // int[] numbers;
    public int solution(int[] numbers, ...){
        this.numbers = numbers //this -> Solution 클래스를 가리킬 듯
    }

2. 향상된 for문 사용
EX)
ArrayList<Integer> temp = new ArrayList<>();
...
for(int value : temp) System.out.print(value+" "); //ArrayList 출력
*/
import java.util.*;
class Solution {
    int answer = 0;
    ArrayList<Integer> temp = new ArrayList<>();
    public void searchDFS(int[] numbers, int floor, int target){
        if (floor < numbers.length){
            int val = numbers[floor];
        
            temp.add(val);
            searchDFS(numbers, floor + 1, target);
            temp.remove(temp.size()-1);

            temp.add(-val);
            searchDFS(numbers, floor + 1, target);
            temp.remove(temp.size()-1);
        }
        else if (floor == numbers.length){
            long sum = temp.stream()
                .mapToLong(Integer::longValue)
                .sum();
            if (sum == target) answer += 1;
        }
    }
    public int solution(int[] numbers, int target) {
        searchDFS(numbers, 0, target);        
        return answer;
    }
}