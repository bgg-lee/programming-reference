/*
* 🙆‍♂️ Created by wwlee94 on 2020.03.14
https://programmers.co.kr/learn/courses/30/lessons/42627

- PriorityQueue 클래스 사용 -
메소드 
1. 삽입 - offer, add
2. 제거 - poll, remove
3. 읽기 - peek, element
offer, poll, peek -> 큐가 비어있으면 null 반환
add, remove, element -> 큐가 비어있으면 예외 발생

- 번외 -
- Array를 첫번째 또는 두번째 Element로 정렬하기 -
1. 첫번째 또는 두번째 Element로 정렬하기 -> ? 이것 말고 List 자체에 sort 있음
Arrays.sort(arr, Comparator.comparing(o1 -> o1[0]));
Arrays.sort(arr, Comparator.comparing(o1 -> o1[1]));

2. 두가지 기준으로 정렬
Arrays.sort(arr, (o1, o2) -> {
    if (o1[0] == o2[0]){
        return Integer.compare(o1[1], o2[1]);
    } else{
        return Integer.compare(o1[0], o2[0]);
    }
});

3. 'Comparable'안에는 int compareTo(T a) 라는 단 하나의 interface 메소드만 존제한다.
* a.compareTo(b);

이 메소드에 대한 설명은 아래와 같으며 리턴값을 3가지로 분류하고 있다.
parameter보다 작은 경우 음수를 리턴
parameter와 같은 경우 0을 리턴
parameter보다 큰 경우 양수를 리턴

4. Comparable vs Comparator
Comparable - 기본적으로 적용되는 정렬 기준이 되는 메서드를 정의하는 인터페이스
Ex) Arrays.sort(내가 구현한 어떤 클래스);
Comparator - 기본 정렬 기준과 다르게 정렬 하고 싶을 때 사용하는 인터페이스
Ex) Arrays.sort(내가 구현한 어떤 클래스, myComparator)
*/
import java.util.*;
class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;
        int length = jobs.length;
        int pre = -1; // 입력된 시간
        int now = 0; // 종료된 시간
        // 자바는 기본 정렬를 바꾸게하는 Comparator를 제공
        PriorityQueue<int[]> wait = new PriorityQueue<>((o1, o2) -> (o1[1] - o2[1]));
        
        int count = 0; // 종료된 프로세스 개수
        while(count != length){
            for(int i=0;i<length;i++){
                int req = jobs[i][0];
                int time = jobs[i][1];
                // pre == req 인 경우는 우선순위를 따져야함
                if(req > pre && req <= now){
                    int[] arr = {req, time};
                    wait.offer(arr);
                }
            }
            if(wait.size() > 0){
                int[] job = wait.poll();
                pre = now;
                now += job[1];
                answer += now - job[0];
                count += 1;
            }
            else now += 1;
        }
        return (int)(answer / length);
    }
}