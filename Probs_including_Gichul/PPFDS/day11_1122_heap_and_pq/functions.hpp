#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;


vector<string> function1(vector<int>& score) {
    // Fill this function
    int n = score.size();
    vector<string> ans(n);
    // push 할때 pair로 <Score , index(얘를 알아야 순서대로 매겨줌)> 하는게 낫다. 
    priority_queue<int> pq;
    for(const int x : score){
        pq.push(x);
    }

    int cnt=1;
    while(!pq.empty()){
        int curr = pq.top();
        pq.pop();
        auto it = find(score.begin(),score.end(),curr);
        auto idx = distance(score.begin(),it);
        if(cnt==1){
            ans[idx]="Gold Medal";
        }
        else if(cnt==2){
            ans[idx]="Silver Medal";

        }
        else if(cnt==3){
            ans[idx]="Bronze Medal";

        }
        else{
            ans[idx]=to_string(cnt);

        }
        cnt++;
    }
    return ans;

}

// If you need to construct another functions, write and use here. 
// However, you can not use those functions in main.cpp.
// Submit functions.hpp file.

// compile command: g++ -o main main.cpp
// execute command: 
//              ./main "5 4 3 2 1"
//              ./main "10 3 8 9 4"