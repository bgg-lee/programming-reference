#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

class Triangle{
    double sideA;
    double sideB;
    double sideC;
    public:
        double area();
        double perimeter();
        Triangle(double a, double b, double c);
};


double Triangle::perimeter(){
    return sideA + sideB + sideC;
}

double Triangle::area(){
    double s = perimeter() / 2;
    return sqrt(s*(s-sideA)*(s-sideB)*(s-sideC));
}

// constructor.
Triangle::Triangle(double a, double b, double c): sideA(a), sideB(b), sideC(c){}


int main_lecture(void){
    int *foo;
    foo = new int [5]; // new는 data type을 input으로 반드시 필요로 한다. //
    //foo = (int*)malloc(4 + sizeof(int) * 5);  //와 같다. 
    // class에 대한 constructor를 위한 공간을 만들 수 있어서 new가 좋다.
    // new에서의 4는 메모리 블락이 int가 몇 개인지(5) 견적을 파악하는 용도이다.
    // new는 malloc 통해 나온 포인터에 타입캐스트까지 친히 해준다.
    // 할당 실패하면 프로그램이 끝난다. C랑 다르다.

    /*
    int *foo;
    foo = new (nothrow) int [5]; // 이러면 할당 실패했을 때 그냥 nullptr 뱉고 프로그램은 계속 실행됨.
    */
    
    delete[] foo; // new[]로 선언했으면 delete[] foo라 해야 함. []안에 숫자 (5) 안 써도 되는 이유는 initial 4 byte에 있다.
    //new 쓸 때는 constructor 불리고 delete 쓰면 destructor가 불린다. [] 안에 들어있던 수만큼 destructor가 불린다.



    return 0;
}

int main1(){
    int i, n;
    int *p;

    cout <<"how many numbers would you like to type?";
    cin >> i;

    p = new(nothrow) int[i];
    if (p==nullptr){
        cout <<"Error: memory could not be allocated";
    }
    else{
        for (n=0; n<i; n++){
            cout << "Enter number: ";
            cin >> p[n];
        }
        cout << "You have entered: ";
        for (n=0; n<i; n++){
            cout <<p[n] << ", ";
        }
        delete[] p;
    }
    return 0;
}
int main(){
    Triangle t1(1.1, 1.5, 1.7);
    cout <<t1.area() << endl;
    return 0;
}
