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
    if (argc < 2) {
        cout << "Usage: ./main <numbers>" << endl;
        return 1;
    }
    
    vector<int> nums = parseInput(argv[1]);

    cout << reversePairs(nums) << endl;
}