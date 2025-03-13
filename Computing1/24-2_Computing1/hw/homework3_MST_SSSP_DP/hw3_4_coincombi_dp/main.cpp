#include <iostream>
#include <vector>
#include <algorithm>

#include "functions.hpp"

using namespace std;

int main(){

    int n = 3,  sum = 4;
    vector<int> coins = {3,2,1};
    vector<int> coins2 = {2,3,6,7};
    vector<int> coins3 = {2,3,5};
    vector<int> coins4 = {};
    
//중복허용
    // std::cout << coinCombinations(n, sum, coins) << std::endl; // 7
    // std::cout << coinCombinations(4, 7, coins2) << std::endl; // 4
    // std::cout << coinCombinations(3, 8, coins3) << std::endl; // 6
    // std::cout << coinCombinations(0, 2, coins4) << std::endl; // 0
   
//중복비허용 
    std::cout << coinCombinations(n, sum, coins) << std::endl; // 4
    std::cout << coinCombinations(4, 7, coins2) << std::endl; // 2
    std::cout << coinCombinations(3, 8, coins3) << std::endl; // 3
    std::cout << coinCombinations(0, 2, coins4) << std::endl; // 0
    return 0;
}

