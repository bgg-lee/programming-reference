#include <iostream>
#include <string>
using namespace std;
/*
Special Members

Member function             typical form for class c:
-------------------------------------------------------
Default constructor         c::c();
Destructor                  c::~c();
Copy Constructor            c::c (const c&);
Copy assignment             c& operator= (const c&);
Move constructor            C::C (C&&);
Move assignment             C& operator= (C&&);
*/

class Dummy{
    public:
        static int n; // static member: class variable. sharing the same value for each instance
        Dummy() {n++;}
};
int Dummy::n=0;

int main(){

    cout << "Dummy example" << endl;
    Dummy a;
    Dummy b[5];
    cout << a.n << endl;
    cout << b[1].n << endl;
    cout << endl;

    return 0;
}