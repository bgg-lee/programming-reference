#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct CompareNode {
    bool operator()(vector<int> &a, vector<int> &b) {
        return a[1] > b[1]; // Min-heap based on job duration
    }
};

int function1(vector<vector<int>> jobs) {
    // Step 1: Sort jobs by request time
    sort(jobs.begin(), jobs.end());

    priority_queue<vector<int>, vector<vector<int>>, CompareNode> minHeap;
    int n = jobs.size();
    int curr_time = 0, idx = 0, total_time = 0;

    // Step 2: Process jobs
    while (idx < n || !minHeap.empty()) {
        // Push all jobs that can be processed at the current time
        while (idx < n && jobs[idx][0] <= curr_time) {
            minHeap.push(jobs[idx]);
            idx++;
        }

        if (!minHeap.empty()) {
            // Process the job with the shortest duration
            vector<int> job = minHeap.top();
            minHeap.pop();

            curr_time += job[1]; // Update current time
            total_time += (curr_time - job[0]); // Total waiting time
        } else {
            // If no jobs are available, move the time to the next job's request time
            curr_time = jobs[idx][0];
        }
    }

    return total_time / n; // Return average waiting time
}



// #include <vector>
// #include <string>
// #include <queue>
// #include <algorithm>
// /*
// A hard disk can handle only one task at a time. There are several ways to implement a disk controller. in this problem, we assume the use of an imaginary device called a prioriy disk controller, which operates as follows.
// 1. When a task request is made..
// */

// // priority queue -> disk controller depends on request/execution time/ task number
// using namespace std;
// //              ./main "0 3 1 9 2 5" -> "0 3 1 9 3 5"

// struct CompareNode {
//      bool operator()(vector<int> a, vector<int> b) {
//          return a[1] > b[1]; // Min-heap based on R-value
//      }
//  };

// int function1(vector<vector<int>> jobs) {

//     priority_queue<vector<int>, vector<vector<int>>, CompareNode> minHeap;
//     int n = jobs.size();
//     if(n==0) return 0;
//     if(n==1) return jobs[0][1];
//     int idx = 0;
//     int ans = 0;
//     sort(jobs.begin(),jobs.end()); // jobs를 request time 기준으로 오름차순 정렬
//     int curr_time = jobs[0][0];  // current time

//     while(idx!=n){
//         // 추잡한 방법으로 이미 Heap에 있는 놈들 체크함.. 이게 결국 맞긴 한데 더 효율적인 방법이 있는지 확인!
//         priority_queue<vector<int>, vector<vector<int>>, CompareNode> check;
//         check = minHeap;
//         vector<vector<int>> check2;
//         for(int j=0;j<check.size();j++){
//             check2.push_back(check.top());
//             check.pop();
//         }
//         for(const auto x : jobs){
//             auto it1 = find(check2.begin(),check2.end(),x);
//             if(it1!=check2.end()) continue;
//             if(x[0]<=curr_time){
//                 minHeap.push(x);
//             }
//         }
//         // 현재 가장 우선순위로 실행될 녀석
//         vector<int> curr = minHeap.top();
//         minHeap.pop();
//         curr_time += curr[1]; // curr_time update
//         ans += (curr_time - curr[0]); // 소요시간 update
//         idx++;
//         //erase it
//         auto it2 = find(jobs.begin(),jobs.end(),curr);
//         jobs.erase(it2);
//     }
//     int result = ans/n;
//     return result;
// }

// If you need to construct another functions, write and use here. 
// However, you can not use those functions in main.cpp.
// Submit functions.hpp file.

// compile command: g++ -o main main.cpp
// execute command: 
//              ./main "0 3 1 9 2 5" -> "0 3 1 9 3 5"
/*
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct CompareNode {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1]; // Min-heap based on job duration
    }
};

int solution(vector<vector<int>> jobs) {
    // Step 1: Sort jobs by request time
    sort(jobs.begin(), jobs.end());

    priority_queue<vector<int>, vector<vector<int>>, CompareNode> minHeap;
    int n = jobs.size();
    int curr_time = 0, idx = 0, total_time = 0;

    // Step 2: Process jobs
    while (idx < n || !minHeap.empty()) {
        // Push all jobs that can be processed at the current time
        while (idx < n && jobs[idx][0] <= curr_time) {
            minHeap.push(jobs[idx]);
            idx++;
        }

        if (!minHeap.empty()) {
            // Process the job with the shortest duration
            vector<int> job = minHeap.top();
            minHeap.pop();

            curr_time += job[1]; // Update current time
            total_time += (curr_time - job[0]); // Total waiting time
        } else {
            // If no jobs are available, move the time to the next job's request time
            curr_time = jobs[idx][0];
        }
    }

    return total_time / n; // Return average waiting time
}
*/