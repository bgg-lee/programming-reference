#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
// priority queue -> disk controller depends on request/execution time/ task number
using namespace std;
//              ./main "0 3 1 9 2 5" -> "0 3 1 9 3 5"

struct CompareNode {
     bool operator()(vector<int> a, vector<int> b) {
         return a[1] > b[1]; // Min-heap based on node value
     }
 };

 int main(){
    // vector<vector<int>> vec;
    // vec.push_back({0,3});
    // vec.push_back({1,3});
    // vec.push_back({0,5});
    // sort(vec.begin(),vec.end());
    // for(auto x : vec){
    //     cout << x[0] << " " << x[1] << endl;
    // }
    priority_queue<vector<int>, vector<vector<int>>, CompareNode> minHeap;
    minHeap.push({0,3});
    minHeap.push({1,5});
    minHeap.push({3,5});
    for(int i=0;i<3;i++){
        auto vec = minHeap.top();
        minHeap.pop();
        cout << vec[0] << " " << vec[1] << endl;
    }
    // return 8;
}