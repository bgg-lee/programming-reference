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

class CVector{
    public:
        int x, y;
        CVector () {};
        CVector (int a, int b): x(a), y(b){}
        CVector operator + (const CVector&);
};

CVector CVector::operator+ (const CVector&param){
    CVector temp;
    temp.x = x + param.x;
    temp.y = y + param.y;
    return temp;
};

int main(){
    cout << "Cvector example" << endl;
    CVector foo(3, 1);
    CVector bar(1, 2);
    CVector result;
    result = foo + bar;
    cout << result.x << ", " << result.y << "\n\n";

    return 0;
}