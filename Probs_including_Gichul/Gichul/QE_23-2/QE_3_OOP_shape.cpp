#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Shape{
public:
    virtual double calc_area() = 0;
    virtual string get_name(){
        return "Shape";
    }

};
class Rectangle : virtual public Shape{
public:
    double width;
    double height;
    Rectangle(double w,double h):width(w),height(h){};
    double calc_area() override {
        return width*height;
    }
    string get_name() override{
        return "Rectangle";
    }
};
class Square : public Rectangle{
public:
    // 부모 클래스 생성자 어떻게 활용하지
    Square(double num):Rectangle(num,num){}

    string get_name() override {
        string temp = "Square";
        return temp;
    };
};
class Triangle : public Shape{
public:
    double a;
    double b;
    double c;
    Triangle(double a,double b,double c):a(a),b(b),c(c){}
    double calc_area() override{
        double s = (a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    string get_name() override{
        return "Triangle";
    }
};
class RightTriangle : public Triangle{
public:
    RightTriangle(double a, double b):Triangle(a,b,sqrt((a*a)+(b*b))){}
    double calc_area() override{
        return (a*b)/2;
    }
    string get_name() override{
        return "RightTriangle";
    }
    int x = 1234;
};
// 내 연습용
class test : public Triangle,public Rectangle{
public:
    test(double a, double b) : Triangle(a,a+1,a+2),Rectangle(b,b){}
    string get_name() override{
        return "TEST\n";
    }
    double calc_area() override{
        return Triangle::calc_area();
    }

};

int main(void){
    test t(3,8);
    cout << t.get_name() << endl;
    cout << t.Rectangle::calc_area() << endl;
    cout << t.calc_area() << endl;


    // // g++ QE_3_OOP.cpp -o QE_3 &&./QE_3
    // Rectangle rect(6,5);
    // cout<<rect.get_name()<<endl;
    // cout<<"RECT 6,5 area: "<<rect.calc_area()<<endl;
    // Square sq(5);
    // cout<<sq.get_name()<<endl;
    // cout<<"sq 5 area: "<<sq.calc_area()<<endl;
    // Triangle tr(5,4,3);
    // cout<<tr.get_name()<<endl;
    // cout<<"tr 5,4,3 area: "<<tr.calc_area()<<endl;
    // RightTriangle rt(6,6);
    // cout<<rt.get_name()<<endl;
    // cout<<"rt 6,6 area: "<<rt.calc_area()<<endl;
    // /*
    // Rectangle
    // RECT 6,5 area: 30
    // Square
    // sq 5 area: 25
    // Triangle
    // tr 5,4,3 area: 6
    // RightTriangle
    // rt 6,6 area: 18
    // */

}