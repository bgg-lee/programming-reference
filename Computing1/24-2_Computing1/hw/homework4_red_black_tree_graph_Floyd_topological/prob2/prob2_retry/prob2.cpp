#include "prob2.hpp"

#include <set>
#include <iostream>
using namespace std;

int findKnownOrderStudents(int n, std::vector<std::pair<int, int>>& comparisons) {
    
    int ans = 0;
    // Make a Graph
    vector<vector<int>> taller(n+1);
    vector<vector<int>> samller(n+1);
    for(const auto p : comparisons){
        taller[p.first].push_back(p.second);
        samller[p.second].push_back(p.first);
    }
    // Taller & Smaller Check
    for(int stu = 1;stu <= n ; stu++){
        /*
        std::unordered_set<int> tallerStudents;
        std::queue<int> q;
        q.push(student);
        std::vector<bool> visited(n + 1, false);
        visited[student] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int next : taller[curr]) {
                if (!visited[next]) {
                    visited[next] = true;
                    tallerStudents.insert(next);
                    q.push(next);
                }
            }
        }
        */
        // 키 큰 놈들 먼저 체크
        queue<int> q;
        set<int> s_tall;
        vector<bool> visited(n+1,false);
        q.push(stu);
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            visited[temp] = true;
            for(int i : taller[temp]){
                if(!visited[i]){
                    s_tall.insert(i);
                    q.push(i);
                }
            }
        }
        // 키 작은 놈들 체크
        set<int> s_small;
        q = queue<int>(); // Memory 재활용~
        visited = vector<bool>(n+1,false);
        q.push(stu);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            visited[temp] = true;
            for(int i : samller[temp]){
                if(!visited[i]){
                    s_small.insert(i);
                    q.push(i);
                }
            }
        }
        // KnownOrder인지 확인인
        if(s_small.size()+s_tall.size()==n-1) ans++;
    }
    cout << ans << endl;
    return ans;
}
