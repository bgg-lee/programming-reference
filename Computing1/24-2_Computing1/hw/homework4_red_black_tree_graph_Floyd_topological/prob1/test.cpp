#include <iostream>
using namespace std;
class Base {
    public:
        void show() { cout << "Base" << endl; }
    };
    
    class Derived1 : virtual public Base{};
    
    class Derived2 : virtual public Base{
    public:
        void show() { cout <<"test2"<<endl;}
    };

    class Final : public Derived1, public Derived2 {}; // Base가 1번만 상속됨
    
    int main() {
        Final obj;
        obj.show();  // "Base" 정상 출력
        return 0;
    }
    