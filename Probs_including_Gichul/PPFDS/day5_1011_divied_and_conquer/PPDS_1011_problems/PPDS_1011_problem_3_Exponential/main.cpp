#include <iostream>
#include "functions.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    double x = stod(argv[1]);
    int n = stoi(argv[2]);

    cout << myPow(x,n) << endl;
}