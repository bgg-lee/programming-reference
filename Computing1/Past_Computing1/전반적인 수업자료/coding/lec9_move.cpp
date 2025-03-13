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

/*
MyClass (MyClass&&); // move-constructor
MyClass& operator= (MyClass &&); // move-assignment
*/

class Example6{
    string *ptr;
    public:
        Example6 (const string& str): ptr(new string(str)){}
        ~Example6 () {delete ptr;}
        Example6 (Example6 && x) : ptr(x.ptr) {x.ptr = nullptr;} // move constructor
        Example6& operator=(Example6 &&x){
            delete ptr;
            ptr = x.ptr; 
            x.ptr = nullptr; return *this;} // move assignment
        const string& content() const{return *ptr;}
        Example6 operator+(const Example6 & rhs){
            return Example6(content() + rhs.content());
        }

};

int main(){
    Example6 foo("Exam");
    Example6 bar = Example6("ple");

    foo = foo + bar;
    cout << foo.content() << endl;
    return 0;
}