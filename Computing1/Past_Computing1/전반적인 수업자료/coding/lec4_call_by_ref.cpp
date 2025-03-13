#include <iostream>
#include <string>
using namespace std;

using namespace std;
template <class T, int N>
void swapping(T &x, T &y){
    T temp = x;
    x = y;
    y = temp * N;
    // cout << x << ", "<< y << ", "<< temp << ", "<< endl; 
}

int main(void){
    int intA = 10, intB = 20;
    
    cout << intA << ", "<< intB << endl;
    swapping<int, 100>(intA, intB);
    cout << intA << ", "<< intB << endl;
    return 0;
}