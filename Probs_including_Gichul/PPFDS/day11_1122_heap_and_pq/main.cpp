#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include "functions.hpp"

using namespace std;

vector<int> parseInput(const char* input) {
    vector<int> nums;
    stringstream ss(input);
    string temp;
    
    while (getline(ss, temp, ' ')) {
        nums.push_back(stoi(temp));  
    }
    
    return nums;
}

int main(int argc, char* argv[]) {
    vector<int> nums = parseInput(argv[1]);
    vector<string> output = function1(nums);

    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << output[i] << " ";
    }
}