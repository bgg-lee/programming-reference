#include "prob2_a.hpp"

int main(void){
    MyVector<int> intVec{1, 2, 3};
    for (auto e : intVec) std::cout << e << " ";

    MyVector<std::string> strVec = {"apple", "bee", "cake"};
    for (auto e : strVec) std::cout << e << " ";

    strVec.push_back("dog");
    for (auto e : strVec) std::cout << e << " ";
}