#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include "functions.hpp"

using namespace std;

vector<vector<int>> parseInput(const char* input) {
    vector<vector<int>> jobs;
    stringstream ss(input);
    string temp;
    vector<int> nums;

    while (getline(ss, temp, ' ')) {
        nums.push_back(stoi(temp)); 
    }

    for (size_t i = 0; i < nums.size(); i += 2) {
        jobs.push_back({nums[i], nums[i + 1]});
    }

    return jobs;
}



int main(int argc, char* argv[]) {
    vector<vector<int>> jobs = parseInput(argv[1]);

    cout << function1(jobs) << endl;

    return 0;
}