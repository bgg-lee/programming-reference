/*
* 🙆‍♂️ Created by wwlee94 on 2020.07.24
https://programmers.co.kr/learn/courses/30/lessons/43162
*/

import java.util.*;
import java.util.stream.*;
class Solution {
    // System.out.println();
    public int solution(int n, int[][] computers) {
        int[] parent = IntStream.range(0, n).toArray(); // IntStream to Array !
        // System.out.println(Arrays.toString(parent)); // Array Print !
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (i!=j && computers[i][j]==1) union_find(parent, i, j);
            }
        }
        
        // Set 자료구조
        Set<Integer> answer = new HashSet();
        for(int node : parent) {
            int x = get_parent(parent, node);
            answer.add(x);
        }
        return answer.size();
    }
    
    // 부모를 찾는 메서드
    public int get_parent(int[] parent, int n){
        if (parent[n] == n) return n;
        parent[n] = get_parent(parent, parent[n]);
        return parent[n];
    }
    
    // 부모의 노드를 합치는 메서드
    public void union_find(int[] parent, int a, int b){
        a = get_parent(parent, a);
        b = get_parent(parent, b);
        if (a > b) parent[a] = b;
        else parent[b] = a;
    }
}