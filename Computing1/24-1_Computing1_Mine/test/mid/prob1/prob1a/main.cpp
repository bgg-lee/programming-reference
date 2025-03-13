#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>

#include "prob1a.hpp"

using namespace std;




int main(int argc, char* argv[]){

    std::string line = "computing foundation for data science provides the foundational knowledge on cpp";

    std::cout << longest_word(line) << std::endl;

    return 0;
    
}