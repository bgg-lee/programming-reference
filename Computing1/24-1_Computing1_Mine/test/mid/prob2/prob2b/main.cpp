#include "prob2_b.hpp"

int main(void){
    MyVector<int> intVec{1, 2, 3};
    std::cout << intVec;
    std::cout << std::endl;
    MyVector<std::string> strVec = {"apple", "bee", "cake"};
    std::cout << strVec;
}