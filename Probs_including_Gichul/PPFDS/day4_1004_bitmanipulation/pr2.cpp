#include <iostream>
using namespace std;

int Sol(int a, int b){
    int dist = 0;
    int temp = b^a; // and,or,XOR 연산은 교환,결합법칙 성립
    while(temp!=0){
        if(temp & 1 == 1) dist++;
        temp = temp >> 1;
    }
    return dist;
}

int main(){

    int num1 = -1;
    int num2 = -4;
    cout << Sol(num1,num2) << endl;
}