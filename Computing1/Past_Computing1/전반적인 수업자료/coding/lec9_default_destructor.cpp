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

class Example4{ // default destructor

    string *ptr;
    public:
        Example4() : ptr(new string){}
        Example4(const string& str) : ptr(new string(str)){} // new string(str) 못떠올릴것같은데..
        ~Example4() {delete ptr;}
        const string& content() const{return *ptr;} // 이게뭐야?!

};

int main(){

    cout << "Example4" << endl;
    Example4 foo4;
    Example4 bar4 ("Example");
    cout << "bar's content: " << bar4.content() << "\n\n";
    cout << endl;

    return 0;
}