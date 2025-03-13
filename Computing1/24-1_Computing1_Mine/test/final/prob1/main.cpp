#include <iostream> 
#include <algorithm>
#include <string>
#include <vector>
#include <chrono>

using namespace std; 
using namespace std::chrono;

#include "functions.hpp"

void printVec(const vector<int> inputVec){

    int prev = -1E+9;

    for (auto i: inputVec){

        if (i == prev) continue;
        prev = i;

        std::cout << i << " ";
    }
}

  
// Driver program to test above functions 
int main(int argc, char * argv[]) 
{ 
    string expression = "2-1-1";
    vector<int> ans = computeWays(expression);

    sort(ans.begin(), ans.end());
    printVec(ans);

    return 0; 
} 