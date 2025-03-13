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

class Example5{
    string* ptr;
    public:
        Example5 (const string& str) : ptr(new string (str)){}
        ~Example5 () {delete ptr;}
        Example5 (const Example5& x) : ptr(new string(x.content())) {}
        const string& content() const {return *ptr;}
        
        Example5 &operator= (const Example5 &x) { // copy assignment : (shallow copy)
            *ptr = x.content();
            return *this;
        }

        Example5 &operator= (const Example5& x){ // copy assignment : (deep copy)
            delete ptr;
            ptr = new string(x.content());
            return *this;
        }

};

int main(){
    Example5 foo ("Example");
    Example5 bar = foo;
    cout << "bar's content: " << bar.content() << "\n\n";
    return 0;
}