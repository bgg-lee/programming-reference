/*
* 🙆‍♂️ Created by wwlee94 on 2020.02.13
https://programmers.co.kr/learn/courses/30/lessons/42576

- 문제 풀이 접근 -
* 해시를 사용해서 푸는 방식
1. participant 크기만큼 반복문 돌면서 해시로 Key=참가자이름, Value=수
2. completion 크기 만큼 돌면서 같은 이름이면 (Value - 1)
3. 결국 하나만 남게 되는 구조이므로 value가 1인 Key를 찾아서 반환

* 정렬해서 푸는 방식
1. participant, completion를 같은 방향으로 정렬 EX) 오름차순
2. 하나씩 비교하면서 다른 부분 찾는다.

- 부수적인 팁 -
1. 'getOrDefault' 메소드 -> 값이 있으면 가져오고 없으면 초기화 ! 
2. keySet하고 또 get하는 건 매우 비효율적인 코드입니다. get할 때마다 계속 HashMap을 search하니까요. key, value를 같이 가져올 때는 항상 entrySet을 사용해야함.
*/

// 더 간단한 코드 !
import java.util.HashMap;
class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String, Integer> hm = new HashMap<>();
        for (String player : participant) hm.put(player, hm.getOrDefault(player, 0) + 1);
        for (String player : completion) hm.put(player, hm.get(player) - 1);

        for (String key : hm.keySet()) {
            if (hm.get(key) != 0){
                answer = key;
            }
        }
        return answer;
    }
}

// 이전 풀이 !
// import java.util.*;
// class Solution {
//     public String solution(String[] participant, String[] completion) {
//         String answer = "";
//         HashMap<String, Integer> map = new HashMap();
//         map = counter(map, participant);
//         map = removeCompletion(map, completion);
//         System.out.println(map);
//         answer = getKey(map, 1);
//         return answer;
//     }
//     // key 별 value 생성
//     public HashMap<String, Integer> counter(HashMap<String, Integer> map, String[] array){
//         for(int i=0;i<array.length;i++){
//             String part = array[i];
//             if(!map.containsKey(part)) map.put(part, 1);
//             else{     
//                 int val = map.get(part);
//                 map.put(part, val + 1);
//             }
//         }
//         return map;
//     }
//     // map과 일치하는 key는 value-1 
//     public HashMap<String, Integer> removeCompletion(HashMap<String, Integer> map, String[] array){
//         for(int i=0;i<array.length;i++){
//             String comp = array[i];
//             int val = map.get(comp);
//             map.put(comp, val-1);
//         }
//         return map;
//     }
//     // value 값으로 key 찾기 !
//     public String getKey(HashMap<String, Integer> m, Object value) { 
//         for(String o: m.keySet()) { 
//             if(m.get(o).equals(value)) { 
//                 return o; 
//             } 
//         } 
//         return null; 
//     }
// }