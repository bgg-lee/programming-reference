#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
/*
You work at a taxi central.
People contact you to order a taxi. they inform you of the time they want to be picked up and dropped off. A taxi is available to handle a new customer 1 time until after it has dropped off a previous customer. Given requests, what is the minimum number of taxis you need to service all requests?
*/

int function4(vector<pair<int, int>> &requests) {
    // Fill this function
    if(requests.empty()) return 0;
    // int ans = 1;
    int n = requests.size();
    sort(requests.begin(),requests.end());
    priority_queue<int,vector<int>,greater<int>> minheap;
    minheap.push(requests[0].second);

    for(int i=1;i<requests.size();i++){
        if(requests[i].first>minheap.top()) minheap.pop();
        minheap.push(requests[i].second);
    }
    return minheap.size();
}

// If you need to construct another functions, write and use here. 
// However, you can not use those functions in main.cpp.
// Submit functions.hpp file.

// compile command: g++ -o main main.cpp
// execute command: 
//              ./main "1 4 2 6 5 9"