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

class Example2{ // default constructor
    public:
        int total;
        Example2 (int initial_value): total(initial_value) {};
        void accumulate (int x) {total +=x;}
};

int main(){
   
    cout << "Example2" << endl;
    Example2 ex(100);
    // Example2 ex; // error(No default constructor). Since we manually defined some constructor, the default constructor disappeared.
    cout << endl;

    return 0;
}