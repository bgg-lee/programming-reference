#include <vector>
using namespace std;
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <string_view>
vector<int> function3(vector<vector<int>>& edges) {
    // Fill this function
    // vector<int> ans;
    // ans = {3,4};
    // return ans;
    // sort(edges.rbegin(),edges.rend());
    int root = edges[0][0];

    vector<int> v;
    v.push_back(root);

    for(vector<int> x : edges){
        if(find(v.begin(),v.end(),x[1])!=v.end()){
            // 찾은 경우
            return x;
        }
        v.push_back(x[1]);
    }
    return {};
}

// If you need to construct another functions, write and use here. 
// However, you can not use those functions in main.cpp.