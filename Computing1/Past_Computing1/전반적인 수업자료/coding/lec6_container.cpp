#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// class에서도 template 이용 가능.
template <class T>
class myPair{
    T values [2];
    public:
    myPair(T first, T second){
        values[0] = first;
        values[1] = second;
    }
    T getMax();
};

template <class T>
T myPair<T>::getMax(){
    T retval;
    T a = values[0];
    T b = values[1];
    retval = a>b? a:b;
    return retval;
}

//container
/*
python      c++             characteristics
list        vector          a dynamic ordered list
set         unordered_set   a dynamic set of unordered unique values
dictionary  unordered_map   a dynamic set of (key_value) pairs
deque       list            a doubly linked list
*/

int main1(){
    myPair<int> myOb(115, 36);
    cout << myOb.getMax() << endl;
    return 0;
}

int main(){
    int a[2];
    vector <int> v{1}; //v는 local variable--> stack에 있는데 vector 특성상 dynamic함.. stack에 저장되면 안 됨.
    //v는 run time stack. but items of v are in heap. v points items. Now we check this fact with following codes.
    int b[2];

    cout << &a << endl;
    cout << &a[0] << endl;
    cout << &a[1] << endl;
    cout << &v << endl;
    cout << &v[0] << endl;
    cout << &b[0] << endl;
    cout << &b[1] << endl;

    v.push_back(2);
    cout << &a << endl;
    cout << &a[0] << endl;
    cout << &a[1] << endl;
    cout << &v << endl;
    cout << &v[0] << endl;
    cout << &b[0] << endl;
    cout << &b[1] << endl;
    return 0;
}