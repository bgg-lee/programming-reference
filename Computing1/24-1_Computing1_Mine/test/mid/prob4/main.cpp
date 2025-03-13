#include <iostream>
#include "prob4.hpp"

using namespace std;

int main(){
    BasicArray <int> arr1(5);
    arr1.set(0,1);
    arr1.set(1,2);
    arr1.set(2,3);

    BasicArray <int> arr2 = arr1;
    arr1.set(3,4);
    arr2.set(3,5);

    cout << "arr1: [";
    for (int i = 0; i < 4; i++) {
        cout << arr1[i];
        if (i < 3) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << "arr2: [";
    for (int i = 0; i < 4; i++) {
        cout << arr2[i];
        if (i < 3) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    // Expected result: arr1: [1, 2, 3, 4], arr2: [1, 2, 3, 5]

    arr1 = arr2;
    arr1.set(4,6);
    arr2.set(4,7);
    cout << "arr1: [";
    for (int i = 0; i < 5; i++) {
        cout << arr1[i];
        if (i < 4) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << "arr2: [";
    for (int i = 0; i < 5; i++) {
        cout << arr2[i];
        if (i < 4) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    // Expected result: arr1: [1, 2, 3, 5, 6], arr2: [1, 2, 3, 5, 7]

    return 0;
    
}