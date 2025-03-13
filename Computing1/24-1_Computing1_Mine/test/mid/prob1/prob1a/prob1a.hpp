// 내가 걍 풀어봄
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

std::string longest_word(std::string input_sentence){

    string answer = "";
    string temp = "";
    for(const char ch : input_sentence){
        if(ch !=' '){
            temp += ch;
        }else{
            if(temp.size()>answer.size()) answer = temp;
            temp = "";
        }
    }

    return answer;

}