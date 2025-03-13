#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include "functions.hpp"

using namespace std;

vector<pair<int, int>> parseInput(const char* input) {
    vector<pair<int, int>> requests;
    stringstream ss(input);
    string temp;
    vector<int> nums;
    
    while (getline(ss, temp, ' ')) {
        nums.push_back(stoi(temp));
    }

    for (size_t i = 0; i < nums.size(); i += 2) {
        requests.emplace_back(nums[i], nums[i + 1]);
    }

    return requests;
}

int main(int argc, char* argv[]) {
    vector<pair<int, int>> requests = parseInput(argv[1]);
    cout << function4(requests) << endl;

    return 0;
}