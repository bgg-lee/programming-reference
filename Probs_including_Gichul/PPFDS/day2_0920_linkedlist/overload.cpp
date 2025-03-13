#include <iostream>
#include <string>
using namespace std;

// int 타입을 받는 함수
int exampleFunction(int a) {
    return a * 2;
}

// double 타입을 받는 함수
double exampleFunction(double a) {
    return a * 2.0;
}

// string 타입을 받는 함수
string exampleFunction(string a) {
    return a + a;
}

int main() {
    cout << exampleFunction(5) << endl;          // 정수: 5 * 2 = 10
    cout << exampleFunction(5.5) << endl;        // 실수: 5.5 * 2.0 = 11.0
    cout << exampleFunction("Hello") << endl;    // 문자열: "Hello" + "Hello" = "HelloHello"
    return 0;
}