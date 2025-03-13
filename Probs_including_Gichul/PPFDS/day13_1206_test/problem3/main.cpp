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
    BinaryTree bt;
    vector<int> vals = parseInput(argv[1]);
    for (int i = 0; i < vals.size(); i++)
    {
        bt.insert(vals[i]);
    }
    bt.function3();
    
    bt.print();

    return 0;
}