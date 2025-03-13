/*
* 🤷‍♂️ Created by wwlee94 on 2020.03.31
https://programmers.co.kr/learn/courses/30/lessons/42746

아래 두개는 결과가 동일
1. strNumber.sort(String::compareTo);
2. strNumber.sort((o1, o2)->
    o1.compareTo(o2)
   );
*/
import java.util.*;
import java.util.stream.*;
class Solution {
    public String solution(int[] numbers) {
        // IntStream.of(numbers) 과 동일
        if(Arrays.stream(numbers).sum() == 0)
            return "0";
     
        List<String> strNumber = Arrays.stream(numbers)
            .mapToObj(String::valueOf)
            .collect(Collectors.toList());
        
        //? 람다 -> 메서드 참조로 바꿀 방법 찾지 못함
        strNumber.sort((o1, o2)->
            o2.concat(o1).compareTo(o1.concat(o2))
        );

        StringBuilder answer = new StringBuilder();
        strNumber.forEach(num -> answer.append(num));
        // strNumber.forEach(answer::append); 과 동일 (메서드 참조)

        return answer.toString();
    }
}