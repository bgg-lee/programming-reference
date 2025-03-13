/*
* 🙆‍♂️ Created by wwlee94 on 2020.02.26
https://programmers.co.kr/learn/courses/30/lessons/42841

- Java JDK 8 버전에서 Collection to Array, Array to Collection 변환하기 ! -
* Collection to Array
    ArrayList<Integer> choosed = new ArrayList<>();
    1. Wrapper Class Array로 만들 때
        Integer[] myArray = choosed.stream().toArray(Integer[]::new);
    2. Primitive Array로 만들 때
        int[] myArray = choosed.stream().mapToInt(x->x).toArray();

* Array to Collection
    1. Wrapper Class Array일 때
        Integer[] myArray = new Integer[10];
        ArrayList<Integer> list = Arrays.stream(myArray).collect(Collectors.toList());
    2. Primitive Array일 때
        int[] myArray = new int[10];
        ArrayList<Integer> list = Arrays.stream(myArray).boxed().collect(Collectors.toList());

- ArrayList<int[]> 출력하기 -
    for(int[] myInt: all_case) System.out.println(Arrays.toString(myInt));

- 다른 풀이 방법 -
1. question을 구할 때 int값을 String으로 변환한 후 str[0]- 백의 자리, str[1] - 십의자리 ... 이런식으로 구하는 방법도 있음
2. ball을 구할때 cases와 question의 교집합에서 strike 개수를 빼서 구하는 방법도 있음
*/
import java.util.*;
class Solution {
    int[] used;
    ArrayList<Integer> choosed = new ArrayList<>();
    ArrayList<int[]> all_case = new ArrayList<>();
    
    public int solution(int[][] baseball) {
        int answer = 0;
        int[] number = {1,2,3,4,5,6,7,8,9};
        permutations(number, 3);
        
        for (int[] cases: all_case){
            int count = 0; //질문을 만족한 개수 (strike, ball)
            for (int[] item: baseball){
                int strike = 0;
                int ball = 0;
                int[] question = {item[0] / 100, (item[0] % 100) / 10, item[0] % 10};

                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(cases[i] == question[j]){
                            if(i==j){ strike += 1; }
                            else{ ball += 1; }
                        }
                    }
                }
                if (item[1] != strike || item[2] != ball) break;
                else count += 1;
            }
            if (count == baseball.length) answer += 1;
        }
        return answer;
    }
    
    // 자바는 순열 직접 구현 해야함
    public void permutations(int[] array, int r){
        used = new int[array.length]; //자동 0으로 초기화
        generate(array, r);
    }
    
    public void generate(int[] array, int r){
        if (choosed.size() == r) {
            // Integer[] myArray = choosed.stream().toArray(Integer[]::new);
            int[] myArray = choosed.stream().mapToInt(x->x).toArray();
            all_case.add(myArray);
            return;
        }
        
        for(int i=0;i<array.length;i++){
            if (used[i] == 0){
                used[i] = 1;
                choosed.add(array[i]);
                generate(array, r);
                used[i] = 0;
                choosed.remove(choosed.size()-1); // Remove last element
            }
        }
    }
}